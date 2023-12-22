/* SPDX-License-Identifier: Apache-2.0 */

#include <zephyr/init.h>
#include <ti/driverlib/m0p/dl_core.h>
#include <soc.h>

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
	SYSCFG_DL_initPower();
	SYSCFG_DL_SYSCTL_init();
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
	DL_GPIO_reset(GPIOA);
	DL_GPIO_reset(GPIOB);

	DL_GPIO_enablePower(GPIOA);
	DL_GPIO_enablePower(GPIOB);
	delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{
	/* Low Power Mode is configured to be SLEEP0 */
	DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

	/* Set default configuration:
	 *	SYSOSC = 32MHz
	 *	CPUCLK = SYSOSC/1
	 *	MCLK = SYSOSC/1
	 *	ULPCLK = SYSOSC/1
	 *	LFOSC = 32.768kHz
	 *	LFXT = N/A
	 *	LFCLK = LFOSC
	 *	HFXT = 40MHz crystal
	 *	HFCLK = HFXT/1
	 *	Note: Clock Control driver is not available yet for MSPM0.
	 *		More advanced clock configuration will be added to this driver.
	 */
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
	DL_SYSCTL_setHFCLKSourceHFXTParams(DL_SYSCTL_HFXT_RANGE_32_48_MHZ, 10, true);

}

static int ti_mspm0g3xxx_init(void)
{
	SYSCFG_DL_init();

	return 0;
}

SYS_INIT(ti_mspm0g3xxx_init, PRE_KERNEL_1, 0);
