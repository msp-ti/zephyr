.. zephyr:code-sample:: low_power
   :name: MSPM0 Low Power Demonstration
   :relevant-api: uart_interface

   Demonstrate the use of UART, GPIO, and RTC peripherals while
   operting under low power mode. 

Overview
********
This example demonstrates putting the device into STANDBY0 while allowing the CPU to wake
on a UART, GPIO, or RTC interrupt. In STANDBY0, the BUSCLK frequency will lower to 32 KHz
while the MFCLK stops. Acitvity on UART RX, a GPIO interrupt, or an RTC interrupt will assert
the wake logic, bringing SYSOSC up and providing ULPCLK or MFCLK to the necessary peripherals for
the duration of the request.
