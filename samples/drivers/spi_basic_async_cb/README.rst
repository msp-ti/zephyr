.. zephyr:code-sample:: spi-basic
   :name: SPI basic
   :relevant-api: spi_interface

   Use the SPI driver for communicating with a slave.

Overview
********

This sample demonstrates using the SPI driver. This example would transmit 
a non multiple of 8 word size, for example some
LCDs which have an extra cmd/data bit.

This sample loops through a spi transfer configuration.


Building and Running
********************

The application will build only for a target that has a :ref:`devicetree
<dt-guide>` entry with :dtcompatible:`zephyr,spi-basic` as a compatible.

You can connect the MISO and MOSI pins with a wire to provide a basic loopback
test for receive data.

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/spi_basic
   :board: lp_mspm0g3507
   :goals: build flash
   :compact:

Sample Output
=============

.. code-block:: console

*** Booting Zephyr OS build b952ca451e51 ***
8bit_loopback_partial; ret: 0
 tx (i)  : 01 02 03 04 05
 rx (i)  : 01 01 00 ff 00
basic_write_9bit_words; ret: 0
 wrote 0101 00ff 00a5 0000 0102
8bit_loopback_partial; ret: 0
 tx (i)  : 01 02 03 04 05
 rx (i)  : 01 01 00 ff 00
basic_write_9bit_words; ret: 0
 wrote 0101 00ff 00a5 0000 0102
 ...
 ...