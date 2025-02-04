/*
 * Copyright (c) 2024 Bang & Olufsen A/S, Denmark
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT ti_mspm0_spi

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/pinctrl.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/mspm0_clock_control.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/logging/log.h>
#include <soc.h>

/* DriverLib includes */
#include <driverlib/dl_spi.h>

LOG_MODULE_REGISTER(spi_mspm0, CONFIG_SPI_LOG_LEVEL);

/* must be included after log module registration */
#include "spi_context.h"

#define SPI_MODE(operation) (operation & BIT(0) ? DL_SPI_MODE_PERIPHERAL : DL_SPI_MODE_CONTROLLER)
#define BIT_ORDER_MODE(operation)                                                                  \
	(operation & BIT(4) ? DL_SPI_BIT_ORDER_LSB_FIRST : DL_SPI_BIT_ORDER_MSB_FIRST)
#define DATA_SIZE_MODE(operation) (SPI_WORD_SIZE_GET(operation) - 1)

#define POLARITY_MODE(operation)                                                                   \
	(SPI_MODE_GET(operation) & SPI_MODE_CPOL ? SPI_CTL0_SPO_HIGH : SPI_CTL0_SPO_LOW)
#define PHASE_MODE(operation)                                                                      \
	(SPI_MODE_GET(operation) & SPI_MODE_CPHA ? SPI_CTL0_SPH_SECOND : SPI_CTL0_SPH_FIRST)
#define DUPLEX_MODE(operation)                                                                     \
	(operation & BIT(11) ? SPI_CTL0_FRF_MOTOROLA_3WIRE : SPI_CTL0_FRF_MOTOROLA_4WIRE)

/* Only motorola format requires config - TI format is a single value */
#define FRAME_FORMAT_MODE(operation)                                                               \
	(operation & SPI_FRAME_FORMAT_TI                                                           \
		 ? SPI_CTL0_FRF_TI_SYNC                                                            \
		 : DUPLEX_MODE(operation) | POLARITY_MODE(operation) | PHASE_MODE(operation))

/* 0x38 represents the bits 8, 16 and 32. Knowing that 24 is bits 8 and 16
 * These are the bits were when you divide by 8, you keep the result as it is.
 * For all the other ones, 4 to 7, 9 to 15, etc... you need a +1,
 * since on such division it takes only the result above 0
 */
#define BYTES_PER_FRAME(word_size)                                                                 \
	(((word_size) & ~0x38) ? (((word_size) / 8) + 1) : ((word_size) / 8))

struct spi_mspm0_config {
	SPI_Regs *base;
	const struct mspm0_clockSys *clock_subsys;
	const struct pinctrl_dev_config *pinctrl;
	const DL_SPI_ClockConfig clock_config;
	void (*irq_config_func)(const struct device *dev);
};

struct spi_mspm0_data {
	struct spi_context ctx;
	//uint8_t dfs;
};

static int spi_mspm0_configure(const struct device *dev, const struct spi_config *spi_cfg)
{
	struct spi_mspm0_data *const data = dev->data;
	const struct spi_mspm0_config *const cfg = dev->config;
	const struct device *const clk_dev = DEVICE_DT_GET(DT_NODELABEL(clkmux));
	struct spi_context *ctx = &data->ctx;
	int ret;

	uint32_t clock_rate;


	if (spi_context_configured(ctx, spi_cfg)) {
		/* this configuration is already in use */
		return 0;
	}

	ret = clock_control_get_rate(clk_dev, (clock_control_subsys_t)cfg->clock_subsys,
				     &clock_rate);

	if(ret < 0){
		return ret;
	}

	if (SPI_MODE(spi_cfg->operation) == DL_SPI_MODE_PERIPHERAL) {
		/* todo: not yet tested so don't add support yet */
		return -ENOTSUP;
	}

	if (spi_cfg->frequency > (clock_rate / 2)) {
		return -EINVAL;
	}

	/* see DL_SPI_setBitRateSerialClockDivider for details */
	uint16_t clock_scr = (clock_rate / (spi_cfg->frequency * 2)) - 1;

	if (!IN_RANGE(clock_scr, 0, 1023)) {
		return -EINVAL;
	}

	const DL_SPI_Config dl_cfg = {
		.mode = SPI_MODE(spi_cfg->operation),
		.frameFormat = FRAME_FORMAT_MODE(spi_cfg->operation),
		.chipSelectPin = DL_SPI_CHIP_SELECT_NONE, /* spi_context controls the CS pin */
		.parity = DL_SPI_PARITY_NONE,             /* currently unused in zephyr */
		.bitOrder = BIT_ORDER_MODE(spi_cfg->operation),
		.dataSize = DATA_SIZE_MODE(spi_cfg->operation),
	};

	/* peripheral should always be disabled prior to applying a new configuration */
	DL_SPI_disable(cfg->base);
	DL_SPI_init(cfg->base, (DL_SPI_Config *)&dl_cfg);
	DL_SPI_setBitRateSerialClockDivider(cfg->base, (uint32_t)clock_scr);

	/* Packing temporarily disabled */
	// 1 = BYTES_PER_FRAME(SPI_WORD_SIZE_GET(spi_cfg->operation));
	// if (1 > 2) {
	// 	DL_SPI_enablePacking(cfg->base);
	// } else {
	//}
	DL_SPI_disablePacking(cfg->base);

	if (SPI_MODE_GET(spi_cfg->operation) & SPI_MODE_LOOP) {
		DL_SPI_enableLoopbackMode(cfg->base);
	} else {
		DL_SPI_disableLoopbackMode(cfg->base);
	}

	DL_SPI_enable(cfg->base);

	/* save config so it can be reused.
	 * also it's required for the lock owner to work
	 */
	ctx->config = spi_cfg;

	return 0;
}

// static bool spi_mspm0_transfer_ongoing(struct spi_context *ctx)
// {
// 	return spi_context_tx_on(ctx) || spi_context_rx_on(ctx);
// }

static void spi_mspm0_frame_tx(const struct device *dev)
{
	struct spi_mspm0_data *data = dev->data;
	const struct spi_mspm0_config *cfg = dev->config;
	struct spi_context *ctx = &data->ctx;

	/* nop tx if no data is expected */
	uint32_t tx_bytes_transmitted = 0;

	//if (spi_context_tx_buf_on(ctx)) {
	tx_bytes_transmitted = DL_SPI_fillTXFIFO8(cfg->base, ctx->tx_buf, ctx->tx_len);
	//}
	spi_context_update_tx(ctx, 1, tx_bytes_transmitted);
	DL_SPI_clearInterruptStatus(cfg->base, DL_SPI_INTERRUPT_IDLE);
	DL_SPI_enableInterrupt(cfg->base, DL_SPI_INTERRUPT_IDLE);
}

static void spi_mspm0_frame_rx(const struct device *dev)
{
	struct spi_mspm0_data *data = dev->data;
	const struct spi_mspm0_config *cfg = dev->config;
	struct spi_context *ctx = &data->ctx;

	uint8_t fifoOutput[8];
	uint8_t rx_cnt;

	rx_cnt = DL_SPI_drainRXFIFO8(cfg->base, fifoOutput, ctx->rx_len);

	/* only update rx buffer if the context is configured to do so
	 * could be eg. if a write is triggered without a read - here the peripheral would not
	 * respond why stale POCI would result in 0 being read out (full duplex mode)
	 */
	if (!spi_context_rx_buf_on(ctx)) {
		return;
	}

	for(int i = 0; i < rx_cnt; i++)
	{
		*((uint8_t *)ctx->rx_buf + i) = fifoOutput[i];
	}

	spi_context_update_rx(ctx, 1, rx_cnt);
}

static void spi_mspm0_start_transfer(const struct device *dev)
{
	struct spi_mspm0_data *data = dev->data;
	struct spi_context *ctx = &data->ctx;

	spi_context_cs_control(ctx, true);

	// if(ctx->tx_len != 0){
	spi_mspm0_frame_tx(dev);
	// } else {
	// 	// spi_context_cs_control(ctx, false);
	// 	// spi_context_complete(ctx, dev, 0);
	// }
}

static int mspm0_transceive(const struct device * dev,
	const struct spi_config * spi_cfg,
	bool async,
	const struct spi_buf_set *tx_bufs,
	const struct spi_buf_set *rx_bufs,
	spi_callback_t cb,
	void *userdata)
{
	struct spi_mspm0_data *data = dev->data;
	struct spi_context *ctx = &data->ctx;

	spi_context_lock(ctx, async, cb, userdata, spi_cfg);

	int ret = spi_mspm0_configure(dev, spi_cfg);

	if (ret != 0) {
		spi_context_release(ctx, ret);
		return ret;
	}

	spi_context_buffers_setup(ctx, tx_bufs, rx_bufs, 1);

	spi_mspm0_start_transfer(dev);

	ret = spi_context_wait_for_completion(ctx);
	spi_context_release(ctx, ret);

	return ret;
}

static void spi_mspm0_isr(const struct device * dev)
{
	struct spi_mspm0_data *data = dev->data;
	const struct spi_mspm0_config *cfg = dev->config;
	struct spi_context *ctx = &data->ctx;

	spi_mspm0_frame_rx(dev);

	if(ctx->tx_len == 0){
		spi_context_cs_control(ctx, false);
		spi_context_complete(ctx, dev, 0);
	}

	DL_SPI_disableInterrupt(cfg->base, DL_SPI_INTERRUPT_IDLE);

	DL_SPI_clearInterruptStatus(cfg->base, DL_SPI_INTERRUPT_IDLE);
}

static int spi_mspm0_transceive(const struct device *dev, const struct spi_config *spi_cfg,
				const struct spi_buf_set *tx_bufs,
				const struct spi_buf_set *rx_bufs)
{
	return mspm0_transceive(dev, spi_cfg, false, tx_bufs, rx_bufs, NULL, NULL);
}

#ifdef CONFIG_SPI_ASYNC
static int spi_mspm0_transceive_async(const struct device *dev, const struct spi_config *spi_cfg,
				const struct spi_buf_set *tx_bufs,
				const struct spi_buf_set *rx_bufs,
				spi_callback_t cb,
				void *userdata)
{
	return mspm0_transceive(dev, spi_cfg, true, tx_bufs, rx_bufs, cb, userdata);
}
#endif /* CONFIG_SPI_ASYNC */

static int spi_mspm0_release(const struct device *dev, const struct spi_config *config)
{
	struct spi_mspm0_data *data = dev->data;
	const struct spi_mspm0_config *cfg = dev->config;
	struct spi_context *ctx = &data->ctx;

	if (!spi_context_configured(ctx, config)) {
		return -EINVAL;
	}

	if (DL_SPI_isBusy(cfg->base)) {
		return -EBUSY;
	}

	spi_context_unlock_unconditionally(ctx);
	return 0;
}

static const struct spi_driver_api spi_mspm0_api = {
	.transceive = spi_mspm0_transceive,
#ifdef CONFIG_SPI_ASYNC
	.transceive_async = spi_mspm0_transceive_async,
#endif
	.release = spi_mspm0_release,
};

static int spi_mspm0_init(const struct device *dev)
{
	struct spi_mspm0_data *data = dev->data;
	const struct spi_mspm0_config *cfg = dev->config;
	struct spi_context *ctx = &data->ctx;

	DL_SPI_reset(cfg->base);
	DL_SPI_enablePower(cfg->base);
	delay_cycles(POWER_STARTUP_DELAY);

	int ret = pinctrl_apply_state(cfg->pinctrl, PINCTRL_STATE_DEFAULT);

	if (ret < 0) {
		LOG_ERR("Failed to apply pinctrl, err: %d", ret);
		return ret;
	}

	ret = spi_context_cs_configure_all(ctx);
	if (ret < 0) {
		return ret;
	}

	cfg->irq_config_func(dev);

	DL_SPI_setClockConfig(cfg->base, (DL_SPI_ClockConfig *)&cfg->clock_config);
	DL_SPI_enable(cfg->base);

	spi_context_unlock_unconditionally(ctx);

	return ret;
}


#define MSPM0_SPI_INIT(inst)                                                                       \
	static void irq_config_##inst(const struct device *dev) \
	{ \
		IRQ_CONNECT(DT_INST_IRQN(inst), DT_INST_IRQ(inst, priority), \
					spi_mspm0_isr, DEVICE_DT_INST_GET(inst), 0); \
		irq_enable(DT_INST_IRQN(inst)); \
	} \
	\
	static const struct mspm0_clockSys mspm0_spi_clockSys##inst = MSPM0_CLOCK_SUBSYS_FN(inst); \
	\
	PINCTRL_DT_INST_DEFINE(inst);                                                              \
                                                                                                   \
	static struct spi_mspm0_config spi_mspm0_##inst##_cfg = {                                  \
		.base = (SPI_Regs *)DT_INST_REG_ADDR(inst),                                        \
		.clock_subsys = &mspm0_spi_clockSys##inst,                                       \
		.pinctrl = PINCTRL_DT_INST_DEV_CONFIG_GET(inst),                                   \
		.clock_config = {.clockSel = (DT_INST_CLOCKS_CELL(inst, bus) & MSPM0_CLOCK_SEL_MASK), \
				 .divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1},                      \
		.irq_config_func = irq_config_##inst\
	};                                                                                         \
                                                                                                   \
	static struct spi_mspm0_data spi_mspm0_##inst##_data = {                                   \
		SPI_CONTEXT_INIT_LOCK(spi_mspm0_##inst##_data, ctx),                               \
		SPI_CONTEXT_INIT_SYNC(spi_mspm0_##inst##_data, ctx),                               \
		SPI_CONTEXT_CS_GPIOS_INITIALIZE(DT_DRV_INST(inst), ctx)};                          \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(inst, spi_mspm0_init, NULL, &spi_mspm0_##inst##_data,                \
			      &spi_mspm0_##inst##_cfg, POST_KERNEL, CONFIG_SPI_INIT_PRIORITY,      \
			      &spi_mspm0_api);

DT_INST_FOREACH_STATUS_OKAY(MSPM0_SPI_INIT)
