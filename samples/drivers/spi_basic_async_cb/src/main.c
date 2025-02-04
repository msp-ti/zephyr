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

uint8_t rxBuffer[64];
uint32_t rxBufferPtr = 0;
uint8_t buff[3] = { 0x11, 0x22, 0x33};
uint8_t rxdata[3];
int transactionFlag = 0;


void spi_callback(const struct device * dev, int status, void * userdata)
{
	for(int i = 0; i < 3; i++){
		rxBuffer[rxBufferPtr] = rxdata[i];
		rxBufferPtr++;
	}

	transactionFlag = 1;
}

void test_8bit_xfer(const struct device *dev, struct spi_cs_control *cs)
{
	struct spi_config config;

	config.frequency = 100000;
	config.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8);
	config.slave = 0;
	config.cs = *cs;

	int datacount = 3;
	// uint8_t buff[datacount] = { 0x11, 0x22, 0x33};
	// uint8_t rxdata[datacount];

	struct spi_buf tx_buf[1] = {
		{.buf = buff, .len = datacount},
	};
	struct spi_buf rx_buf[1] = {
		{.buf = rxdata, .len = datacount},
	};

	struct spi_buf_set tx_set = { .buffers = tx_buf, .count = 1 };
	struct spi_buf_set rx_set = { .buffers = rx_buf, .count = 1 };

	int ret = spi_transceive_cb(dev, &config, &tx_set, &rx_set, spi_callback, NULL);

	printf("8bit_partial; ret: %d\n", ret);
	printf(" tx (i)  : %02x %02x %02x\n",
	       buff[0], buff[1], buff[2]);

	while(transactionFlag == 0){
		k_usleep(20);
	}

	printf("8bit finished\n");
	printf(" rx (i)  : %02x %02x %02x\n",
	    	rxBuffer[0], rxBuffer[1], rxBuffer[2]);
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
	while (1)
	{
		// test_basic_write_9bit_words(dev, &cs_ctrl);
		// k_sleep(K_MSEC(200));

		k_sleep(K_MSEC(1000));
		test_8bit_xfer(dev, &cs_ctrl);
	}
	return 0;
}
