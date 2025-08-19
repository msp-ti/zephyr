#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/rtc.h>
#include <ti/driverlib/m0p/dl_sysctl.h>
#include <ti/driverlib/dl_gpio.h>

static const struct device *uart = DEVICE_DT_GET(DT_NODELABEL(uart0));
static const struct device *gpio_dev = DEVICE_DT_GET(DT_GPIO_CTLR(DT_NODELABEL(btn1), gpios));
static const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET(DT_NODELABEL(btn1), gpios);
static struct gpio_callback button_cb_data;
static const struct device *rtc = DEVICE_DT_GET(DT_NODELABEL(rtc));
static struct rtc_time alarm_time;
static uint8_t alarm_triggers;

#define BUFFER_SIZE 16
char buffer[BUFFER_SIZE];
uint8_t buffer_idx;
K_SEM_DEFINE(uart_sem, 1, 1);

/* This callback is fired when a UART RX interrupt occurs. A character
 * will be read from the FIFO and placed inside of the ring buffer.
 */
void uart_callback(const struct device *dev, void *user_data)
{
	uart_irq_update(dev);

	if(uart_irq_rx_ready(dev)) {		
		k_sem_take(&uart_sem, K_FOREVER);
		uart_fifo_read(dev, &buffer[buffer_idx++], 1);
		if(buffer_idx == BUFFER_SIZE) {
			buffer_idx = 0;
		}
		k_sem_give(&uart_sem);
	}
}

/* This callback is fired when a GPIO button is pressed. The contents of
 * the ring buffer will sent over the UART TX line.
 */
static void button_callback(const struct device *dev, struct gpio_callback *cb, gpio_port_pins_t pins)
{
	int bytes_sent = 0;

	k_sem_take(&uart_sem, K_FOREVER);
	uart_irq_tx_enable(uart);
	while(bytes_sent < BUFFER_SIZE) {
		bytes_sent += uart_fifo_fill(uart, buffer+bytes_sent, BUFFER_SIZE - bytes_sent);
	}
	while(!uart_irq_tx_complete(uart));
	uart_irq_tx_disable(uart);
	k_sem_give(&uart_sem);
}

/* This callback is fired when the RTC alarm generates an interrupt. The message
 * "Alarm Triggered!" will be sent over the UART TX line. The RTC minute alarm will
 * advanced forward by 1 minute so that it will trigger again.
 */
static void alarm_callback(const struct device *dev, uint16_t id, void *user_data)
{
	char msg[] = "Alarm Triggered!";
	int bytes_sent = 0;
	alarm_triggers++;

	k_sem_take(&uart_sem, K_FOREVER);
	uart_irq_tx_enable(uart);
	while(bytes_sent < strlen(msg)) {
		bytes_sent += uart_fifo_fill(uart, msg+bytes_sent, strlen(msg)-bytes_sent);
	}
	while(!uart_irq_tx_complete(uart));
	uart_irq_tx_disable(uart);

	if(rtc_get_time(dev, &alarm_time) == 0) {
		alarm_time.tm_min++;
		rtc_alarm_set_time(rtc, 0, RTC_ALARM_TIME_MASK_MINUTE, &alarm_time);
	}
} 

int main(void)
{
	/* Enable external clock for frequency reading of ULPCLK if desired */
	DL_SYSCTL_enableExternalClock(DL_SYSCTL_CLK_OUT_SOURCE_ULPCLK, DL_SYSCTL_CLK_OUT_DIVIDE_16);
	/* Set the low power policy to be STANDBY0 */
	DL_SYSCTL_setPowerPolicySTANDBY0();

	/* Configure S2 button (PB21) as input with interrupt triggering on falling edge. 
	 * Attaches a callback that will called when the interrupt triggers.
	 */
	gpio_pin_configure_dt(&button0, GPIO_INPUT);
	gpio_pin_interrupt_configure_dt(&button0, GPIO_INT_TRIG_LOW | GPIO_INT_MODE_EDGE);
	gpio_init_callback(&button_cb_data, button_callback, BIT(button0.pin));
	gpio_add_callback(gpio_dev, &button_cb_data);
	
	/* Attach a callback when a UART interrupt occurs. Also enables the RX interrupts on the UART
	 * so that it can wake from low power mode.
	 */
	uart_irq_callback_set(uart, uart_callback);
	uart_irq_rx_enable(uart);

	/* Configures an RTC alarm enables with the minutes mask. Sets the first alarm to
	 * trigger one minute from now. Also attaches the callback that will fired when the interrupt
	 * wakes the CPU.
	 */
	alarm_triggers = 0;
	alarm_time.tm_min = 0;
	rtc_set_time(rtc, &alarm_time);
	rtc_alarm_set_callback(rtc, 0, alarm_callback, NULL);
	alarm_time.tm_min++;
	rtc_alarm_set_time(rtc, 0, RTC_ALARM_TIME_MASK_MINUTE, &alarm_time);

	/* Put the CPU to sleep */
	while(1) {
		k_cpu_idle();
	}
}