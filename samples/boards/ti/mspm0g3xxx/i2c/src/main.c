/* SPDX-License-Identifier: Apache-2.0 */

#include <zephyr/devicetree.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>

/* I2C Target address */
#define I2C_TARGET_ADDRESS (0x48)

/* Maximum size of TX packet */
#define I2C_TX_MAX_PACKET_SIZE (16)

/* Number of bytes to send to target device */
#define I2C_TX_PACKET_SIZE (16)

/* Maximum size of RX packet */
#define I2C_RX_MAX_PACKET_SIZE (16)

/* Number of bytes to received from target */
#define I2C_RX_PACKET_SIZE (16)

/* Data sent to the Target */
uint8_t gTxPacket[I2C_TX_MAX_PACKET_SIZE] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
					     0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

/* Data received from Target */
uint8_t gRxPacket[I2C_RX_MAX_PACKET_SIZE];

const struct i2c_dt_spec i2c = {.bus = DEVICE_DT_GET(DT_NODELABEL(i2c1)),
				.addr = I2C_TARGET_ADDRESS};

static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});

int main(void)
{
	printk("Starting I2C controller test\n");

	/* Setup LED */
	if (led.port) {
		int ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT);

		if (ret != 0) {
			printk("Error %d: failed to configure LED device %s pin %d\n", ret,
			       led.port->name, led.pin);
			led.port = NULL;
		} else {
			printk("Set up LED at %s pin %d\n", led.port->name, led.pin);
		}
	}

	/* Set LED to indicate start of transfer */
	gpio_pin_set_dt(&led, 1);

	/* Start writing */
	printk("Starting write\n");

	struct i2c_msg msg = {
		.buf = gTxPacket, .len = I2C_TX_MAX_PACKET_SIZE, .flags = I2C_MSG_WRITE};

	if (i2c_transfer_dt(&i2c, &msg, 1)) {
		printk("Write failed\n");
		return 0;
	}

	printk("Finished write\n");

	/* Add delay between transfers */
	k_busy_wait(1000);

	/* Start read */
	printk("Starting read\n");

	msg = (struct i2c_msg){
		.buf = gRxPacket, .len = I2C_RX_MAX_PACKET_SIZE, .flags = I2C_MSG_READ};

	if (i2c_transfer_dt(&i2c, &msg, 1)) {
		printk("Read failed\n");
		return 0;
	}

	printk("Success!\n");

	/* If write and read were successful, toggle LED */
	while (true) {
		gpio_pin_toggle_dt(&led);
		k_busy_wait(1000000);
	}
}
