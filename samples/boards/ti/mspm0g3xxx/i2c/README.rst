.. _ti-mspm0g3xxx-i2c-sample:

MSPM0G3XXX I2C Controller Demo
##############################

Overview
********

This sample can be used to demonstrate basic I2C controller function. This
demo does the following:

    1. Sets up I2C for the controller and toggles led0 high
    2. Send out values 0-15
    3. Receives the values put out (should be 0-15)
    4. Toggles led0

Requirements
************

This application uses the MSPM0G3507 LaunchPad for the demo.

Building, Flashing and Running
******************************

.. zephyr-app-commands::
   :zephyr-app: samples/boards/mspm0g3xxx/i2c
   :board: lp_mspm0g3xxx
   :goals: build
   :compact:

After flashing the device, do the following:

    1. Run the i2c_target_rw_multibyte_fifo_interrupts_XXX_nortos test
    on another MSPM0 launchpad, whether XXX be a G or L device
    2. Connect the launchpad to the other board, from PB3/2 (Data/Clock) to
    the other board's SDA and SCL pins
    3. Start this code
