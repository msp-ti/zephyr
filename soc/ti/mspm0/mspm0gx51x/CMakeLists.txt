# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_MSPM0G1518)
	zephyr_compile_definitions(-D__MSPM0G1518__)
elseif(CONFIG_SOC_MSPM0G1519)
	zephyr_compile_definitions(-D__MSPM0G1519__)
elseif(CONFIG_SOC_MSPM0G3518)
	zephyr_compile_definitions(-D__MSPM0G3518__)
elseif(CONFIG_SOC_MSPM0G3519)
    zephyr_compile_definitions(-D__MSPM0G3519__)
endif()

zephyr_sources(soc.c)
zephyr_include_directories(.)
