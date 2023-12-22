# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_MSPM0G3507)
    zephyr_compile_definitions(-D__MSPM0G3507__)
endif()
zephyr_sources(soc.c)
