/*
 * Copyright (c) 2024 Texas Instruments
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT ti_mspm0_smbus

/* Zephyr Includes */
#include <zephyr/kernel.h>
#include <zephyr/drivers/smbus.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/pinctrl.h>
#include <soc.h>

struct smbus_mspm0_config {
    I2C_Regs * base;
};

struct smbus_mspm0_data {
    uint32_t value;
    uint32_t isTarget;
    uint32_t dev_config;
};

static void smbus_mspm0_init(const struct device *dev) {
    i2c_mspm0_init(dev);
}

static int smbus_mspm0_configure(const struct device *dev, uint32_t dev_config){
    const struct smbus_mspm0_config *config = dev->config;
	struct smbus_mspm0_data *data = dev->data;

    data->dev_config = dev_config;
	/* Set the I2C speed to standard for now*/
	DL_I2C_setTimerPeriod(config->base, (uint32_t) 7);
}

static int smbus_mspm0_get_config(const struct device *dev, uint32_t * dev_config){
    struct smbus_mspm0_data *data = dev->data;

    return data->dev_config;
}

static int smbus_mspm0_quick(const struct device *dev, uint16_t addr, enum smbus_direction direction){
	// here's the quick command

}

static int smbus_mspm0_byte_write(const struct device *dev, uint16_t addr, uint8_t byte){

}

static int smbus_mspm0_byte_read(const struct device *dev, uint16_t addr, uint8_t byte){

}

static int smbus_mspm0_byte_data_write(const struct device *dev, uint16_t addr,
									uint8_t cmd, uint8_t byte){
	// data write
}

static int smbus_mspm0_byte_data_read(const struct device *dev, uint16_t addr,
									uint8_t cmd, uint8_t byte){
	// data read
}

static const struct smbus_driver_api smbus_mspm0_driver_api = {
    .xfer_stats = //
	.configure = smbus_mspm0_configure,
	.get_config = smbus_mspm0_get_config,
    .smbalert_set_cb = //
    .smbalert_remove_cb = //
    .host_notify_set = //
    .host_notify_remove_cb = //
    .quick = smbus_mspm0_quick,
    .byte_write = smbus_mspm0_byte_write,
    .byte_read = smbus_mspm0_byte_read,
    .byte_data_write = smbus_mspm0_byte_data_write,
    .byte_data_read = smbus_mspm0_byte_data_read,
    .word_data_write = //
    .word_data_read = //
    .pcall = //
    .block_write = //
    .block_read = //
    .block_pcall = //
	// add target stuff next
};


#define MSP_SMBUS_INIT_FN(index)		\
	\
	PINCTRL_DT_INST_DEFINE(index);		\
	\
	\
	static const struct i2c_mspm0_config i2c_mspm0_cfg_##index = {	\
		.base = DT_INST_REG_ADDR(index),							\
		.clock_frequency = DT_INST_PROP(index, clock_frequency),	\
		.pinctrl = PINCTRL_DT_INST_DEV_CONFIG_GET(index),			\
		.interrupt_init_function = i2c_mspm0_interrupt_init_##index,\
		.gI2CClockConfig = {.clockSel = DL_I2C_CLOCK_BUSCLK,		\
				    .divideRatio = DL_I2C_CLOCK_DIVIDE_1}};			\
	\
	static struct i2c_mspm0_data i2c_mspm0_data_##index;			\
	\
	I2C_DEVICE_DT_INST_DEFINE(index, i2c_mspm0_init, NULL,			\
				&i2c_mspm0_data_##index, &i2c_mspm0_cfg_##index,	\
				POST_KERNEL, CONFIG_I2C_INIT_PRIORITY,	\
				&i2c_mspm0_driver_api);					\
	\
	INTERRUPT_INIT_FUNCTION(index)

DT_INST_FOREACH_STATUS_OKAY(MSP_SMBUS_INIT_FN)