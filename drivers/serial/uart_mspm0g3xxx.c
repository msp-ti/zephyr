/* SPDX-License-Identifier: Apache-2.0 */

#define DT_DRV_COMPAT ti_mspm0g3xxx_uart

#include <soc.h>

/* Defines for UART0 */
#define UART_0_IBRD_33_kHZ_9600_BAUD (1)
#define UART_0_FBRD_33_kHZ_9600_BAUD (9)
#define GPIO_UART_0_IOMUX_RX         (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX         (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC    IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC    IOMUX_PINCM21_PF_UART0_TX

/* Zephyr includes */
#include <zephyr/drivers/uart.h>
#include <zephyr/irq.h>

/* Driverlib includes */
#include <ti/driverlib/dl_uart_main.h>

struct uart_mspm0g3xxx_config {
	UART_Regs *regs;
};

struct uart_mspm0g3xxx_dev_data_t {
	/* UART clock structure */
	DL_UART_Main_ClockConfig gUART_0ClockConfig;
	/* UART config structure */
	DL_UART_Main_Config gUART_0Config;
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	uart_irq_callback_user_data_t cb; /* Callback function pointer */
	void *cb_data;                    /* Callback function arg */
#endif                                    /* CONFIG_UART_INTERRUPT_DRIVEN */
};

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
static void uart_mspm0g3xxx_isr(const struct device *dev);
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */

static const struct uart_mspm0g3xxx_config uart_mspm0g3xxx_dev_cfg_0 = {
	.regs = (UART_Regs *)DT_INST_REG_ADDR(0)};

static struct uart_mspm0g3xxx_dev_data_t uart_mspm0g3xxx_dev_data_0 = {
	/* UART clock structure */
	.gUART_0ClockConfig = {.clockSel = DL_UART_MAIN_CLOCK_LFCLK,
			       .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1},
	/* UART config structure */
	.gUART_0Config = {.mode = DL_UART_MAIN_MODE_NORMAL,
			  .direction = DL_UART_MAIN_DIRECTION_TX_RX,
			  .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
			  .parity = DL_UART_MAIN_PARITY_NONE,
			  .wordLength = DL_UART_MAIN_WORD_LENGTH_8_BITS,
			  .stopBits = DL_UART_MAIN_STOP_BITS_ONE},
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	.cb = NULL,
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */
};

static int uart_mspm0g3xxx_init(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	/* Reset power */
	DL_UART_Main_reset(config->regs);
	DL_UART_Main_enablePower(config->regs);
	delay_cycles(POWER_STARTUP_DELAY);

	/* Init UART pins */
	DL_GPIO_initPeripheralOutputFunction(GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
	DL_GPIO_initPeripheralInputFunction(GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);

	/* Set UART configs */
	DL_UART_Main_setClockConfig(
		config->regs,
		(DL_UART_Main_ClockConfig *)&uart_mspm0g3xxx_dev_data_0.gUART_0ClockConfig);
	DL_UART_Main_init(config->regs,
			  (DL_UART_Main_Config *)&uart_mspm0g3xxx_dev_data_0.gUART_0Config);

	/*
	 * Configure baud rate by setting oversampling and baud rate divisors.
	 *  Target baud rate: 9600
	 *  Actual baud rate: 9576.04
	 */
	DL_UART_Main_setOversampling(config->regs, DL_UART_MAIN_OVERSAMPLING_RATE_3X);
	DL_UART_Main_setBaudRateDivisor(config->regs, UART_0_IBRD_33_kHZ_9600_BAUD,
					UART_0_FBRD_33_kHZ_9600_BAUD);

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	IRQ_CONNECT(DT_INST_IRQN(0), DT_INST_IRQ(0, priority), uart_mspm0g3xxx_isr,
		    DEVICE_DT_INST_GET(0), 0);
	irq_enable(DT_INST_IRQN(0));
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */

	/* Enable UART */
	DL_UART_Main_enable(config->regs);

	return 0;
}

static int uart_mspm0g3xxx_poll_in(const struct device *dev, unsigned char *c)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (DL_UART_receiveDataCheck(config->regs, c)) ? 0 : -1;
}

static void uart_mspm0g3xxx_poll_out(const struct device *dev, unsigned char c)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	DL_UART_Main_transmitDataBlocking(config->regs, c);
}

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
static int uart_mspm0g3xxx_fifo_fill(const struct device *dev, const uint8_t *tx_data, int size)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (int)DL_UART_Main_fillTXFIFO(config->regs, (uint8_t *)tx_data, size);
}

static int uart_mspm0g3xxx_fifo_read(const struct device *dev, uint8_t *rx_data, const int size)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (int)DL_UART_Main_drainRXFIFO(config->regs, rx_data, size);
}

static void uart_mspm0g3xxx_irq_tx_enable(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	DL_UART_Main_enableInterrupt(config->regs, DL_UART_MAIN_INTERRUPT_TX);
}

static void uart_mspm0g3xxx_irq_tx_disable(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	DL_UART_Main_disableInterrupt(config->regs, DL_UART_MAIN_INTERRUPT_TX);
}

static int uart_mspm0g3xxx_irq_tx_ready(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (DL_UART_getEnabledInterruptStatus(config->regs, DL_UART_MAIN_INTERRUPT_TX)) ? 0 : 1;
}

static void uart_mspm0g3xxx_irq_rx_enable(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	DL_UART_Main_enableInterrupt(config->regs, DL_UART_MAIN_INTERRUPT_RX);
}

static void uart_mspm0g3xxx_irq_rx_disable(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	DL_UART_Main_disableInterrupt(config->regs, DL_UART_MAIN_INTERRUPT_RX);
}

static int uart_mspm0g3xxx_irq_tx_complete(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (DL_UART_Main_isTXFIFOEmpty(config->regs)) ? 1 : 0;
}

static int uart_mspm0g3xxx_irq_rx_ready(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (DL_UART_getEnabledInterruptStatus(config->regs, DL_UART_MAIN_INTERRUPT_RX)) ? 1 : 0;
}

static int uart_mspm0g3xxx_irq_is_pending(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;

	return (DL_UART_getEnabledInterruptStatus(config->regs,
	DL_UART_MAIN_INTERRUPT_RX | DL_UART_MAIN_INTERRUPT_TX))
		       ? 1
		       : 0;
}

static int uart_mspm0g3xxx_irq_update(const struct device *dev)
{
	ARG_UNUSED(dev);
	return 1;
}

static void uart_mspm0g3xxx_irq_callback_set(const struct device *dev,
					     uart_irq_callback_user_data_t cb, void *cb_data)
{
	struct uart_mspm0g3xxx_dev_data_t *const dev_data = dev->data;

	/* Set callback function and data */
	dev_data->cb = cb;
	dev_data->cb_data = cb_data;
}

/**
 * @brief Interrupt service routine.
 *
 * This simply calls the callback function, if one exists.
 *
 * @param arg Argument to ISR.
 */
static void uart_mspm0g3xxx_isr(const struct device *dev)
{
	const struct uart_mspm0g3xxx_config *config = dev->config;
	struct uart_mspm0g3xxx_dev_data_t *const dev_data = dev->data;

	/* Get the pending interrupt */
	int int_status = DL_UART_getEnabledInterruptStatus(config->regs,
	DL_UART_MAIN_INTERRUPT_RX | DL_UART_MAIN_INTERRUPT_TX);

	/* Perform callback if defined */
	if (dev_data->cb) {
		dev_data->cb(dev, dev_data->cb_data);
	}

	/*
	 * Clear interrupts only after cb called, as Zephyr UART clients expect
	 * to check interrupt status during the callback.
	 */
	DL_UART_Main_clearInterruptStatus(config->regs, int_status);
}
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */

static const struct uart_driver_api uart_mspm0g3xxx_driver_api = {
	.poll_in = uart_mspm0g3xxx_poll_in,
	.poll_out = uart_mspm0g3xxx_poll_out,
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	.fifo_fill = uart_mspm0g3xxx_fifo_fill,
	.fifo_read = uart_mspm0g3xxx_fifo_read,
	.irq_tx_enable = uart_mspm0g3xxx_irq_tx_enable,
	.irq_tx_disable = uart_mspm0g3xxx_irq_tx_disable,
	.irq_tx_ready = uart_mspm0g3xxx_irq_tx_ready,
	.irq_rx_enable = uart_mspm0g3xxx_irq_rx_enable,
	.irq_rx_disable = uart_mspm0g3xxx_irq_rx_disable,
	.irq_tx_complete = uart_mspm0g3xxx_irq_tx_complete,
	.irq_rx_ready = uart_mspm0g3xxx_irq_rx_ready,
	.irq_is_pending = uart_mspm0g3xxx_irq_is_pending,
	.irq_update = uart_mspm0g3xxx_irq_update,
	.irq_callback_set = uart_mspm0g3xxx_irq_callback_set,
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */
};

DEVICE_DT_INST_DEFINE(0, uart_mspm0g3xxx_init, DT_INST_REG_ADDR(0), &uart_mspm0g3xxx_dev_data_0,
		      &uart_mspm0g3xxx_dev_cfg_0, PRE_KERNEL_1, CONFIG_SERIAL_INIT_PRIORITY,
		      (void *)&uart_mspm0g3xxx_driver_api);
