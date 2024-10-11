# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_MSPM0L2228)
    zephyr_compile_definitions(-D__MSPM0L2228__)
endif()
if(CONFIG_SOC_MSPM0L2227)
    zephyr_compile_definitions(-D__MSPM0L2227__)
endif()
if(CONFIG_SOC_MSPM0L1228)
    zephyr_compile_definitions(-D__MSPM0L1228__)
endif()
if(CONFIG_SOC_MSPM0L1227)
    zephyr_compile_definitions(-D__MSPM0L1227__)
endif()
zephyr_sources(soc.c)
zephyr_include_directories(.)

set(SOC_LINKER_SCRIPT ${ZEPHYR_BASE}/include/zephyr/arch/arm/cortex_m/scripts/linker.ld CACHE INTERNAL "")
