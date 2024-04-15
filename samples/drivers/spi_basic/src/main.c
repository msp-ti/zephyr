/*
 * Copyright (c) 2021 Marc Reilly, Creative Product Design
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/drivers/spi.h>

#define SPI_1_NODE	DT_NODELABEL(spi1)

/*
 * writes 5 9bit words, you can check the output with a logic analyzer
 */
void test_basic_write_9bit_words(const struct device *dev,
				 struct spi_cs_control *cs)
{
	struct spi_config config;

	config.frequency = 125000;
	config.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(9);
	config.slave = 0;
	config.cs = *cs;

	uint16_t buff[5] = { 0x0101, 0x00ff, 0x00a5, 0x0000, 0x0102};
	int len = 5 * sizeof(buff[0]);

	struct spi_buf tx_buf = { .buf = buff, .len = len };
	struct spi_buf_set tx_bufs = { .buffers = &tx_buf, .count = 1 };

	int ret = spi_write(dev, &config, &tx_bufs);

	printf("basic_write_9bit_words; ret: %d\n", ret);
	printf(" wrote %04x %04x %04x %04x %04x\n",
		buff[0], buff[1], buff[2], buff[3], buff[4]);
}

int main(void)
{
	const struct device *const dev = DEVICE_DT_GET(SPI_1_NODE);

	if (!device_is_ready(dev)) {
		printk("%s: device not ready.\n", dev->name);
		return 0;
	}

	struct spi_cs_control cs_ctrl = (struct spi_cs_control){
		.gpio = GPIO_DT_SPEC_GET(SPI_1_NODE, cs_gpios),
		.delay = 0u,
	};

	/*
	 * Loop through the various demo functions, the delays make it easier to
	 * locate on a scope/analyzer, the longer delay at the end helps discern
	 * where the pattern repeats.
	 */
	while (1) {
		test_basic_write_9bit_words(dev, &cs_ctrl);
		k_sleep(K_MSEC(200));
	}
	return 0;
}
