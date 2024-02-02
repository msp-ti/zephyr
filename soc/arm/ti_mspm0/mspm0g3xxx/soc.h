/* SPDX-License-Identifier: Apache-2.0 */

#ifndef soc_h
#define soc_h

#define SYSCONFIG_WEAK __attribute__((weak))

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

#define POWER_STARTUP_DELAY (16)

/* 
 *  Note: Clock Control driver is not available yet for MSPM0. 
 *	More advanced clock configuration will be available once the driver is 
 *   implemented. 
 */
/*!
 * @brief If true, enables HFXT to be used for CAN, otherwise enables PLL using SYSOSC
 */
#define SOC_MSPM0_CAN_USE_HFXT      (false) 
/*!
 * @brief CPU frequency in Hz
 */
#define SOC_MSPM0_CPUCLK_FREQ_HZ    MHZ(32)
/*!
 * @brief HFCLK frequency in Hz (if enabled)
 */
#if (SOC_MSPM0_CAN_USE_HFXT == true)
#define SOC_MSPM0_HFCLK_FREQ_HZ     MHZ(40)
#else 
#define SOC_MSPM0_HFCLK_FREQ_HZ     (0)
#endif
/*!
 * @brief SYSPLL frequency in Hz (if enabled)
 */
#if (SOC_MSPM0_CAN_USE_HFXT == true)
#define SOC_MSPM0_SYSPLL_FREQ_HZ    (0)
#else 
#define SOC_MSPM0_SYSPLL_FREQ_HZ    MHZ(40)
#endif

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_SYSCTL_init(void);

#ifdef __cplusplus
}
#endif

#endif /* soc_h */
