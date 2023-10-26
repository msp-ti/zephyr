#ifndef _MSPM0_DT_BINDINGS_PINCTRL_H_
#define _MSPM0_DT_BINDINGS_PINCTRL_H_


/* MSP_IOMUX_PINCM1[PF] Bits */
#define MSP_IOMUX_PINCM1_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM1_PF_GPIOA_DIO00                             (0X00000001)
#define MSP_IOMUX_PINCM1_PF_UART0_TX                                (0X00000002)
#define MSP_IOMUX_PINCM1_PF_I2C0_SDA                                (0X00000003)
#define MSP_IOMUX_PINCM1_PF_TIMA0_CCP0                              (0X00000004)
#define MSP_IOMUX_PINCM1_PF_TIMA_FAULT1                             (0X00000005)
#define MSP_IOMUX_PINCM1_PF_TIMG8_CCP1                              (0X00000006)
#define MSP_IOMUX_PINCM1_PF_SYSCTL_FCC_IN                           (0X00000007)

/* MSP_IOMUX_PINCM2[PF] Bits */
#define MSP_IOMUX_PINCM2_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM2_PF_GPIOA_DIO01                             (0X00000001)
#define MSP_IOMUX_PINCM2_PF_UART0_RX                                (0X00000002)
#define MSP_IOMUX_PINCM2_PF_I2C0_SCL                                (0X00000003)
#define MSP_IOMUX_PINCM2_PF_TIMA0_CCP1                              (0X00000004)
#define MSP_IOMUX_PINCM2_PF_TIMA_FAULT2                             (0X00000005)
#define MSP_IOMUX_PINCM2_PF_TIMG8_IDX                               (0X00000006)
#define MSP_IOMUX_PINCM2_PF_TIMG8_CCP0                              (0X00000007)

/* MSP_IOMUX_PINCM3[PF] Bits */
#define MSP_IOMUX_PINCM3_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM3_PF_GPIOA_DIO28                             (0X00000001)
#define MSP_IOMUX_PINCM3_PF_UART0_TX                                (0X00000002)
#define MSP_IOMUX_PINCM3_PF_I2C0_SDA                                (0X00000003)
#define MSP_IOMUX_PINCM3_PF_TIMA0_CCP3                              (0X00000004)
#define MSP_IOMUX_PINCM3_PF_TIMA_FAULT0                             (0X00000005)
#define MSP_IOMUX_PINCM3_PF_TIMG7_CCP0                              (0X00000006)
#define MSP_IOMUX_PINCM3_PF_TIMA1_CCP0                              (0X00000007)

/* MSP_IOMUX_PINCM4[PF] Bits */
#define MSP_IOMUX_PINCM4_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM4_PF_GPIOA_DIO29                             (0X00000001)
#define MSP_IOMUX_PINCM4_PF_I2C1_SCL                                (0X00000002)
#define MSP_IOMUX_PINCM4_PF_UART2_RTS                               (0X00000003)
#define MSP_IOMUX_PINCM4_PF_TIMG8_CCP0                              (0X00000004)
#define MSP_IOMUX_PINCM4_PF_TIMG6_CCP0                              (0X00000005)

/* MSP_IOMUX_PINCM5[PF] Bits */
#define MSP_IOMUX_PINCM5_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM5_PF_GPIOA_DIO30                             (0X00000001)
#define MSP_IOMUX_PINCM5_PF_I2C1_SDA                                (0X00000002)
#define MSP_IOMUX_PINCM5_PF_UART2_CTS                               (0X00000003)
#define MSP_IOMUX_PINCM5_PF_TIMG8_CCP1                              (0X00000004)
#define MSP_IOMUX_PINCM5_PF_TIMG6_CCP1                              (0X00000005)

/* MSP_IOMUX_PINCM6[PF] Bits */
#define MSP_IOMUX_PINCM6_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM6_PF_GPIOA_DIO31                             (0X00000001)
#define MSP_IOMUX_PINCM6_PF_UART0_RX                                (0X00000002)
#define MSP_IOMUX_PINCM6_PF_I2C0_SCL                                (0X00000003)
#define MSP_IOMUX_PINCM6_PF_TIMA0_CCP3_CMPL                         (0X00000004)
#define MSP_IOMUX_PINCM6_PF_TIMG12_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM6_PF_SYSCTL_CLK_OUT                          (0X00000006)
#define MSP_IOMUX_PINCM6_PF_TIMG7_CCP1                              (0X00000007)
#define MSP_IOMUX_PINCM6_PF_TIMA1_CCP1                              (0X00000008)

/* MSP_IOMUX_PINCM7[PF] Bits */
#define MSP_IOMUX_PINCM7_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM7_PF_GPIOA_DIO02                             (0X00000001)
#define MSP_IOMUX_PINCM7_PF_TIMG8_CCP1                              (0X00000002)
#define MSP_IOMUX_PINCM7_PF_SPI0_CS0                                (0X00000003)
#define MSP_IOMUX_PINCM7_PF_TIMG7_CCP1                              (0X00000004)
#define MSP_IOMUX_PINCM7_PF_SPI1_CS0                                (0X00000005)

/* MSP_IOMUX_PINCM8[PF] Bits */
#define MSP_IOMUX_PINCM8_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM8_PF_GPIOA_DIO03                             (0X00000001)
#define MSP_IOMUX_PINCM8_PF_TIMG8_CCP0                              (0X00000002)
#define MSP_IOMUX_PINCM8_PF_SPI0_CS1_POCI1                          (0X00000003)
#define MSP_IOMUX_PINCM8_PF_UART2_CTS                               (0X00000004)
#define MSP_IOMUX_PINCM8_PF_TIMA0_CCP2                              (0X00000005)
#define MSP_IOMUX_PINCM8_PF_COMP1_OUT                               (0X00000006)
#define MSP_IOMUX_PINCM8_PF_TIMG7_CCP0                              (0X00000007)
#define MSP_IOMUX_PINCM8_PF_TIMA0_CCP1                              (0X00000008)
#define MSP_IOMUX_PINCM8_PF_I2C1_SDA                                (0X00000009)

/* MSP_IOMUX_PINCM9[PF] Bits */
#define MSP_IOMUX_PINCM9_PF_UNCONNECTED                             (0X00000000)
#define MSP_IOMUX_PINCM9_PF_GPIOA_DIO04                             (0X00000001)
#define MSP_IOMUX_PINCM9_PF_TIMG8_CCP1                              (0X00000002)
#define MSP_IOMUX_PINCM9_PF_SPI0_POCI                               (0X00000003)
#define MSP_IOMUX_PINCM9_PF_UART2_RTS                               (0X00000004)
#define MSP_IOMUX_PINCM9_PF_TIMA0_CCP3                              (0X00000005)
#define MSP_IOMUX_PINCM9_PF_SYSCTL_LFCLKIN                          (0X00000006)
#define MSP_IOMUX_PINCM9_PF_TIMG7_CCP1                              (0X00000007)
#define MSP_IOMUX_PINCM9_PF_TIMA0_CCP1_CMPL                         (0X00000008)
#define MSP_IOMUX_PINCM9_PF_I2C1_SCL                                (0X00000009)

/* MSP_IOMUX_PINCM10[PF] Bits */
#define MSP_IOMUX_PINCM10_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM10_PF_GPIOA_DIO05                            (0X00000001)
#define MSP_IOMUX_PINCM10_PF_TIMG8_CCP0                             (0X00000002)
#define MSP_IOMUX_PINCM10_PF_SPI0_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM10_PF_TIMA_FAULT1                            (0X00000004)
#define MSP_IOMUX_PINCM10_PF_TIMG0_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM10_PF_TIMG6_CCP0                             (0X00000006)
#define MSP_IOMUX_PINCM10_PF_SYSCTL_FCC_IN                          (0X00000007)

/* MSP_IOMUX_PINCM11[PF] Bits */
#define MSP_IOMUX_PINCM11_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM11_PF_GPIOA_DIO06                            (0X00000001)
#define MSP_IOMUX_PINCM11_PF_TIMG8_CCP1                             (0X00000002)
#define MSP_IOMUX_PINCM11_PF_SPI0_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM11_PF_TIMA_FAULT0                            (0X00000004)
#define MSP_IOMUX_PINCM11_PF_TIMG0_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM11_PF_SYSCTL_HFCLKIN                         (0X00000006)
#define MSP_IOMUX_PINCM11_PF_TIMG6_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM11_PF_TIMA0_CCP2_CMPL                        (0X00000008)

/* MSP_IOMUX_PINCM12[PF] Bits */
#define MSP_IOMUX_PINCM12_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM12_PF_GPIOB_DIO00                            (0X00000001)
#define MSP_IOMUX_PINCM12_PF_UART0_TX                               (0X00000002)
#define MSP_IOMUX_PINCM12_PF_SPI1_CS2_POCI2                         (0X00000003)
#define MSP_IOMUX_PINCM12_PF_TIMA1_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM12_PF_TIMA0_CCP2                             (0X00000005)

/* MSP_IOMUX_PINCM13[PF] Bits */
#define MSP_IOMUX_PINCM13_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM13_PF_GPIOB_DIO01                            (0X00000001)
#define MSP_IOMUX_PINCM13_PF_UART0_RX                               (0X00000002)
#define MSP_IOMUX_PINCM13_PF_SPI1_CS3_CD_POCI3                      (0X00000003)
#define MSP_IOMUX_PINCM13_PF_TIMA1_CCP1                             (0X00000004)
#define MSP_IOMUX_PINCM13_PF_TIMA0_CCP2_CMPL                        (0X00000005)

/* MSP_IOMUX_PINCM14[PF] Bits */
#define MSP_IOMUX_PINCM14_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM14_PF_GPIOA_DIO07                            (0X00000001)
#define MSP_IOMUX_PINCM14_PF_COMP0_OUT                              (0X00000002)
#define MSP_IOMUX_PINCM14_PF_SYSCTL_CLK_OUT                         (0X00000003)
#define MSP_IOMUX_PINCM14_PF_TIMG8_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM14_PF_TIMA0_CCP2                             (0X00000005)
#define MSP_IOMUX_PINCM14_PF_TIMG8_IDX                              (0X00000006)
#define MSP_IOMUX_PINCM14_PF_TIMG7_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM14_PF_TIMA0_CCP1                             (0X00000008)

/* MSP_IOMUX_PINCM15[PF] Bits */
#define MSP_IOMUX_PINCM15_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM15_PF_GPIOB_DIO02                            (0X00000001)
#define MSP_IOMUX_PINCM15_PF_UART3_TX                               (0X00000002)
#define MSP_IOMUX_PINCM15_PF_UART2_CTS                              (0X00000003)
#define MSP_IOMUX_PINCM15_PF_I2C1_SCL                               (0X00000004)
#define MSP_IOMUX_PINCM15_PF_TIMA0_CCP3                             (0X00000005)
#define MSP_IOMUX_PINCM15_PF_UART1_CTS                              (0X00000006)
#define MSP_IOMUX_PINCM15_PF_TIMG6_CCP0                             (0X00000007)
#define MSP_IOMUX_PINCM15_PF_TIMA1_CCP0                             (0X00000008)

/* MSP_IOMUX_PINCM16[PF] Bits */
#define MSP_IOMUX_PINCM16_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM16_PF_GPIOB_DIO03                            (0X00000001)
#define MSP_IOMUX_PINCM16_PF_UART3_RX                               (0X00000002)
#define MSP_IOMUX_PINCM16_PF_UART2_RTS                              (0X00000003)
#define MSP_IOMUX_PINCM16_PF_I2C1_SDA                               (0X00000004)
#define MSP_IOMUX_PINCM16_PF_TIMA0_CCP3_CMPL                        (0X00000005)
#define MSP_IOMUX_PINCM16_PF_UART1_RTS                              (0X00000006)
#define MSP_IOMUX_PINCM16_PF_TIMG6_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM16_PF_TIMA1_CCP1                             (0X00000008)

/* MSP_IOMUX_PINCM17[PF] Bits */
#define MSP_IOMUX_PINCM17_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM17_PF_GPIOB_DIO04                            (0X00000001)
#define MSP_IOMUX_PINCM17_PF_UART1_TX                               (0X00000002)
#define MSP_IOMUX_PINCM17_PF_UART3_CTS                              (0X00000003)
#define MSP_IOMUX_PINCM17_PF_TIMA1_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM17_PF_TIMA0_CCP2                             (0X00000005)
#define MSP_IOMUX_PINCM17_PF_TIMA1_CCP0_CMPL                        (0X00000006)

/* MSP_IOMUX_PINCM18[PF] Bits */
#define MSP_IOMUX_PINCM18_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM18_PF_GPIOB_DIO05                            (0X00000001)
#define MSP_IOMUX_PINCM18_PF_UART1_RX                               (0X00000002)
#define MSP_IOMUX_PINCM18_PF_UART3_RTS                              (0X00000003)
#define MSP_IOMUX_PINCM18_PF_TIMA1_CCP1                             (0X00000004)
#define MSP_IOMUX_PINCM18_PF_TIMA0_CCP2_CMPL                        (0X00000005)
#define MSP_IOMUX_PINCM18_PF_TIMA1_CCP1_CMPL                        (0X00000006)

/* MSP_IOMUX_PINCM19[PF] Bits */
#define MSP_IOMUX_PINCM19_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM19_PF_GPIOA_DIO08                            (0X00000001)
#define MSP_IOMUX_PINCM19_PF_UART1_TX                               (0X00000002)
#define MSP_IOMUX_PINCM19_PF_SPI0_CS0                               (0X00000003)
#define MSP_IOMUX_PINCM19_PF_UART0_RTS                              (0X00000004)
#define MSP_IOMUX_PINCM19_PF_TIMA0_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM19_PF_TIMA1_CCP0_CMPL                        (0X00000006)

/* MSP_IOMUX_PINCM20[PF] Bits */
#define MSP_IOMUX_PINCM20_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM20_PF_GPIOA_DIO09                            (0X00000001)
#define MSP_IOMUX_PINCM20_PF_UART1_RX                               (0X00000002)
#define MSP_IOMUX_PINCM20_PF_SPI0_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM20_PF_UART0_CTS                              (0X00000004)
#define MSP_IOMUX_PINCM20_PF_TIMA0_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM20_PF_RTC_RTC_OUT                            (0X00000006)
#define MSP_IOMUX_PINCM20_PF_TIMA0_CCP0_CMPL                        (0X00000007)
#define MSP_IOMUX_PINCM20_PF_TIMA1_CCP1_CMPL                        (0X00000008)
#define MSP_IOMUX_PINCM20_PF_SYSCTL_CLK_OUT                         (0X00000009)

/* MSP_IOMUX_PINCM21[PF] Bits */
#define MSP_IOMUX_PINCM21_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM21_PF_GPIOA_DIO10                            (0X00000001)
#define MSP_IOMUX_PINCM21_PF_UART0_TX                               (0X00000002)
#define MSP_IOMUX_PINCM21_PF_SPI0_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM21_PF_I2C0_SDA                               (0X00000004)
#define MSP_IOMUX_PINCM21_PF_TIMA1_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM21_PF_TIMG12_CCP0                            (0X00000006)
#define MSP_IOMUX_PINCM21_PF_TIMA0_CCP2                             (0X00000007)
#define MSP_IOMUX_PINCM21_PF_I2C1_SDA                               (0X00000008)
#define MSP_IOMUX_PINCM21_PF_SYSCTL_CLK_OUT                         (0X00000009)

/* MSP_IOMUX_PINCM22[PF] Bits */
#define MSP_IOMUX_PINCM22_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM22_PF_GPIOA_DIO11                            (0X00000001)
#define MSP_IOMUX_PINCM22_PF_UART0_RX                               (0X00000002)
#define MSP_IOMUX_PINCM22_PF_SPI0_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM22_PF_I2C0_SCL                               (0X00000004)
#define MSP_IOMUX_PINCM22_PF_TIMA1_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM22_PF_COMP0_OUT                              (0X00000006)
#define MSP_IOMUX_PINCM22_PF_TIMA0_CCP2_CMPL                        (0X00000007)
#define MSP_IOMUX_PINCM22_PF_I2C1_SCL                               (0X00000008)

/* MSP_IOMUX_PINCM23[PF] Bits */
#define MSP_IOMUX_PINCM23_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM23_PF_GPIOB_DIO06                            (0X00000001)
#define MSP_IOMUX_PINCM23_PF_UART1_TX                               (0X00000002)
#define MSP_IOMUX_PINCM23_PF_SPI1_CS0                               (0X00000003)
#define MSP_IOMUX_PINCM23_PF_SPI0_CS1_POCI1                         (0X00000004)
#define MSP_IOMUX_PINCM23_PF_TIMG8_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM23_PF_UART2_CTS                              (0X00000006)
#define MSP_IOMUX_PINCM23_PF_TIMG6_CCP0                             (0X00000007)
#define MSP_IOMUX_PINCM23_PF_TIMA1_CCP0_CMPL                        (0X00000008)

/* MSP_IOMUX_PINCM24[PF] Bits */
#define MSP_IOMUX_PINCM24_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM24_PF_GPIOB_DIO07                            (0X00000001)
#define MSP_IOMUX_PINCM24_PF_UART1_RX                               (0X00000002)
#define MSP_IOMUX_PINCM24_PF_SPI1_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM24_PF_SPI0_CS2_POCI2                         (0X00000004)
#define MSP_IOMUX_PINCM24_PF_TIMG8_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM24_PF_UART2_RTS                              (0X00000006)
#define MSP_IOMUX_PINCM24_PF_TIMG6_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM24_PF_TIMA1_CCP1_CMPL                        (0X00000008)

/* MSP_IOMUX_PINCM25[PF] Bits */
#define MSP_IOMUX_PINCM25_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM25_PF_GPIOB_DIO08                            (0X00000001)
#define MSP_IOMUX_PINCM25_PF_UART1_CTS                              (0X00000002)
#define MSP_IOMUX_PINCM25_PF_SPI1_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM25_PF_TIMA0_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM25_PF_COMP1_OUT                              (0X00000005)

/* MSP_IOMUX_PINCM26[PF] Bits */
#define MSP_IOMUX_PINCM26_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM26_PF_GPIOB_DIO09                            (0X00000001)
#define MSP_IOMUX_PINCM26_PF_UART1_RTS                              (0X00000002)
#define MSP_IOMUX_PINCM26_PF_SPI1_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM26_PF_TIMA0_CCP1                             (0X00000004)
#define MSP_IOMUX_PINCM26_PF_TIMA0_CCP0_CMPL                        (0X00000005)

/* MSP_IOMUX_PINCM27[PF] Bits */
#define MSP_IOMUX_PINCM27_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM27_PF_GPIOB_DIO10                            (0X00000001)
#define MSP_IOMUX_PINCM27_PF_TIMG0_CCP0                             (0X00000002)
#define MSP_IOMUX_PINCM27_PF_TIMG8_CCP0                             (0X00000003)
#define MSP_IOMUX_PINCM27_PF_COMP1_OUT                              (0X00000004)
#define MSP_IOMUX_PINCM27_PF_TIMG6_CCP0                             (0X00000005)

/* MSP_IOMUX_PINCM28[PF] Bits */
#define MSP_IOMUX_PINCM28_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM28_PF_GPIOB_DIO11                            (0X00000001)
#define MSP_IOMUX_PINCM28_PF_TIMG0_CCP1                             (0X00000002)
#define MSP_IOMUX_PINCM28_PF_TIMG8_CCP1                             (0X00000003)
#define MSP_IOMUX_PINCM28_PF_SYSCTL_CLK_OUT                         (0X00000004)
#define MSP_IOMUX_PINCM28_PF_TIMG6_CCP1                             (0X00000005)

/* MSP_IOMUX_PINCM29[PF] Bits */
#define MSP_IOMUX_PINCM29_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM29_PF_GPIOB_DIO12                            (0X00000001)
#define MSP_IOMUX_PINCM29_PF_UART3_TX                               (0X00000002)
#define MSP_IOMUX_PINCM29_PF_TIMA0_CCP2                             (0X00000003)
#define MSP_IOMUX_PINCM29_PF_TIMA_FAULT1                            (0X00000004)
#define MSP_IOMUX_PINCM29_PF_TIMA0_CCP1                             (0X00000005)

/* MSP_IOMUX_PINCM30[PF] Bits */
#define MSP_IOMUX_PINCM30_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM30_PF_GPIOB_DIO13                            (0X00000001)
#define MSP_IOMUX_PINCM30_PF_UART3_RX                               (0X00000002)
#define MSP_IOMUX_PINCM30_PF_TIMA0_CCP3                             (0X00000003)
#define MSP_IOMUX_PINCM30_PF_TIMG12_CCP0                            (0X00000004)
#define MSP_IOMUX_PINCM30_PF_TIMA0_CCP1_CMPL                        (0X00000005)

/* MSP_IOMUX_PINCM31[PF] Bits */
#define MSP_IOMUX_PINCM31_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM31_PF_GPIOB_DIO14                            (0X00000001)
#define MSP_IOMUX_PINCM31_PF_SPI1_CS3_CD_POCI3                      (0X00000002)
#define MSP_IOMUX_PINCM31_PF_SPI1_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM31_PF_SPI0_CS3_CD_POCI3                      (0X00000004)
#define MSP_IOMUX_PINCM31_PF_TIMG12_CCP1                            (0X00000005)
#define MSP_IOMUX_PINCM31_PF_TIMG8_IDX                              (0X00000006)
#define MSP_IOMUX_PINCM31_PF_TIMA0_CCP0                             (0X00000007)

/* MSP_IOMUX_PINCM32[PF] Bits */
#define MSP_IOMUX_PINCM32_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM32_PF_GPIOB_DIO15                            (0X00000001)
#define MSP_IOMUX_PINCM32_PF_UART2_TX                               (0X00000002)
#define MSP_IOMUX_PINCM32_PF_SPI1_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM32_PF_UART3_CTS                              (0X00000004)
#define MSP_IOMUX_PINCM32_PF_TIMG8_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM32_PF_TIMG7_CCP0                             (0X00000006)

/* MSP_IOMUX_PINCM33[PF] Bits */
#define MSP_IOMUX_PINCM33_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM33_PF_GPIOB_DIO16                            (0X00000001)
#define MSP_IOMUX_PINCM33_PF_UART2_RX                               (0X00000002)
#define MSP_IOMUX_PINCM33_PF_SPI1_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM33_PF_UART3_RTS                              (0X00000004)
#define MSP_IOMUX_PINCM33_PF_TIMG8_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM33_PF_TIMG7_CCP1                             (0X00000006)

/* MSP_IOMUX_PINCM34[PF] Bits */
#define MSP_IOMUX_PINCM34_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM34_PF_GPIOA_DIO12                            (0X00000001)
#define MSP_IOMUX_PINCM34_PF_UART3_CTS                              (0X00000002)
#define MSP_IOMUX_PINCM34_PF_SPI0_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM34_PF_TIMG0_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM34_PF_CANFD0_CANTX                           (0X00000005)
#define MSP_IOMUX_PINCM34_PF_TIMA0_CCP3                             (0X00000006)
#define MSP_IOMUX_PINCM34_PF_SYSCTL_FCC_IN                          (0X00000007)

/* MSP_IOMUX_PINCM35[PF] Bits */
#define MSP_IOMUX_PINCM35_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM35_PF_GPIOA_DIO13                            (0X00000001)
#define MSP_IOMUX_PINCM35_PF_UART3_RTS                              (0X00000002)
#define MSP_IOMUX_PINCM35_PF_SPI0_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM35_PF_UART3_RX                               (0X00000004)
#define MSP_IOMUX_PINCM35_PF_TIMG0_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM35_PF_CANFD0_CANRX                           (0X00000006)
#define MSP_IOMUX_PINCM35_PF_TIMA0_CCP3_CMPL                        (0X00000007)

/* MSP_IOMUX_PINCM36[PF] Bits */
#define MSP_IOMUX_PINCM36_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM36_PF_GPIOA_DIO14                            (0X00000001)
#define MSP_IOMUX_PINCM36_PF_UART0_CTS                              (0X00000002)
#define MSP_IOMUX_PINCM36_PF_SPI0_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM36_PF_UART3_TX                               (0X00000004)
#define MSP_IOMUX_PINCM36_PF_TIMG12_CCP0                            (0X00000005)
#define MSP_IOMUX_PINCM36_PF_SYSCTL_CLK_OUT                         (0X00000006)

/* MSP_IOMUX_PINCM37[PF] Bits */
#define MSP_IOMUX_PINCM37_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM37_PF_GPIOA_DIO15                            (0X00000001)
#define MSP_IOMUX_PINCM37_PF_UART0_RTS                              (0X00000002)
#define MSP_IOMUX_PINCM37_PF_SPI1_CS2_POCI2                         (0X00000003)
#define MSP_IOMUX_PINCM37_PF_I2C1_SCL                               (0X00000004)
#define MSP_IOMUX_PINCM37_PF_TIMA1_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM37_PF_TIMG8_IDX                              (0X00000006)
#define MSP_IOMUX_PINCM37_PF_TIMA1_CCP0_CMPL                        (0X00000007)
#define MSP_IOMUX_PINCM37_PF_TIMA0_CCP2                             (0X00000008)

/* MSP_IOMUX_PINCM38[PF] Bits */
#define MSP_IOMUX_PINCM38_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM38_PF_GPIOA_DIO16                            (0X00000001)
#define MSP_IOMUX_PINCM38_PF_COMP2_OUT                              (0X00000002)
#define MSP_IOMUX_PINCM38_PF_SPI1_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM38_PF_I2C1_SDA                               (0X00000004)
#define MSP_IOMUX_PINCM38_PF_TIMA1_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM38_PF_TIMA1_CCP1_CMPL                        (0X00000006)
#define MSP_IOMUX_PINCM38_PF_TIMA0_CCP2_CMPL                        (0X00000007)
#define MSP_IOMUX_PINCM38_PF_SYSCTL_FCC_IN                          (0X00000008)

/* MSP_IOMUX_PINCM39[PF] Bits */
#define MSP_IOMUX_PINCM39_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM39_PF_GPIOA_DIO17                            (0X00000001)
#define MSP_IOMUX_PINCM39_PF_UART1_TX                               (0X00000002)
#define MSP_IOMUX_PINCM39_PF_SPI1_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM39_PF_I2C1_SCL                               (0X00000004)
#define MSP_IOMUX_PINCM39_PF_TIMA0_CCP3                             (0X00000005)
#define MSP_IOMUX_PINCM39_PF_TIMG7_CCP0                             (0X00000006)
#define MSP_IOMUX_PINCM39_PF_TIMA1_CCP0                             (0X00000007)

/* MSP_IOMUX_PINCM40[PF] Bits */
#define MSP_IOMUX_PINCM40_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM40_PF_GPIOA_DIO18                            (0X00000001)
#define MSP_IOMUX_PINCM40_PF_UART1_RX                               (0X00000002)
#define MSP_IOMUX_PINCM40_PF_SPI1_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM40_PF_I2C1_SDA                               (0X00000004)
#define MSP_IOMUX_PINCM40_PF_TIMA0_CCP3_CMPL                        (0X00000005)
#define MSP_IOMUX_PINCM40_PF_TIMG7_CCP1                             (0X00000006)
#define MSP_IOMUX_PINCM40_PF_TIMA1_CCP1                             (0X00000007)

/* MSP_IOMUX_PINCM41[PF] Bits */
#define MSP_IOMUX_PINCM41_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM41_PF_GPIOA_DIO19                            (0X00000001)
#define MSP_IOMUX_PINCM41_PF_DEBUGSS_SWDIO                          (0X00000002)

/* MSP_IOMUX_PINCM42[PF] Bits */
#define MSP_IOMUX_PINCM42_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM42_PF_GPIOA_DIO20                            (0X00000001)
#define MSP_IOMUX_PINCM42_PF_DEBUGSS_SWCLK                          (0X00000002)

/* MSP_IOMUX_PINCM43[PF] Bits */
#define MSP_IOMUX_PINCM43_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM43_PF_GPIOB_DIO17                            (0X00000001)
#define MSP_IOMUX_PINCM43_PF_UART2_TX                               (0X00000002)
#define MSP_IOMUX_PINCM43_PF_SPI0_PICO                              (0X00000003)
#define MSP_IOMUX_PINCM43_PF_SPI1_CS1_POCI1                         (0X00000004)
#define MSP_IOMUX_PINCM43_PF_TIMA1_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM43_PF_TIMA0_CCP2                             (0X00000006)

/* MSP_IOMUX_PINCM44[PF] Bits */
#define MSP_IOMUX_PINCM44_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM44_PF_GPIOB_DIO18                            (0X00000001)
#define MSP_IOMUX_PINCM44_PF_UART2_RX                               (0X00000002)
#define MSP_IOMUX_PINCM44_PF_SPI0_SCLK                              (0X00000003)
#define MSP_IOMUX_PINCM44_PF_SPI1_CS2_POCI2                         (0X00000004)
#define MSP_IOMUX_PINCM44_PF_TIMA1_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM44_PF_TIMA0_CCP2_CMPL                        (0X00000006)

/* MSP_IOMUX_PINCM45[PF] Bits */
#define MSP_IOMUX_PINCM45_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM45_PF_GPIOB_DIO19                            (0X00000001)
#define MSP_IOMUX_PINCM45_PF_COMP2_OUT                              (0X00000002)
#define MSP_IOMUX_PINCM45_PF_SPI0_POCI                              (0X00000003)
#define MSP_IOMUX_PINCM45_PF_TIMG8_CCP1                             (0X00000004)
#define MSP_IOMUX_PINCM45_PF_UART0_CTS                              (0X00000005)
#define MSP_IOMUX_PINCM45_PF_TIMG7_CCP1                             (0X00000006)

/* MSP_IOMUX_PINCM46[PF] Bits */
#define MSP_IOMUX_PINCM46_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM46_PF_GPIOA_DIO21                            (0X00000001)
#define MSP_IOMUX_PINCM46_PF_UART2_TX                               (0X00000002)
#define MSP_IOMUX_PINCM46_PF_TIMG8_CCP0                             (0X00000003)
#define MSP_IOMUX_PINCM46_PF_UART1_CTS                              (0X00000004)
#define MSP_IOMUX_PINCM46_PF_TIMA0_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM46_PF_TIMG6_CCP0                             (0X00000006)

/* MSP_IOMUX_PINCM47[PF] Bits */
#define MSP_IOMUX_PINCM47_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM47_PF_GPIOA_DIO22                            (0X00000001)
#define MSP_IOMUX_PINCM47_PF_UART2_RX                               (0X00000002)
#define MSP_IOMUX_PINCM47_PF_TIMG8_CCP1                             (0X00000003)
#define MSP_IOMUX_PINCM47_PF_UART1_RTS                              (0X00000004)
#define MSP_IOMUX_PINCM47_PF_TIMA0_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM47_PF_SYSCTL_CLK_OUT                         (0X00000006)
#define MSP_IOMUX_PINCM47_PF_TIMA0_CCP0_CMPL                        (0X00000007)
#define MSP_IOMUX_PINCM47_PF_TIMG6_CCP1                             (0X00000008)

/* MSP_IOMUX_PINCM48[PF] Bits */
#define MSP_IOMUX_PINCM48_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM48_PF_GPIOB_DIO20                            (0X00000001)
#define MSP_IOMUX_PINCM48_PF_SPI0_CS2_POCI2                         (0X00000002)
#define MSP_IOMUX_PINCM48_PF_SPI1_CS0                               (0X00000003)
#define MSP_IOMUX_PINCM48_PF_TIMA0_CCP2                             (0X00000004)
#define MSP_IOMUX_PINCM48_PF_TIMG12_CCP0                            (0X00000005)
#define MSP_IOMUX_PINCM48_PF_TIMA_FAULT1                            (0X00000006)
#define MSP_IOMUX_PINCM48_PF_TIMA0_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM48_PF_TIMA1_CCP1_CMPL                        (0X00000008)

/* MSP_IOMUX_PINCM49[PF] Bits */
#define MSP_IOMUX_PINCM49_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM49_PF_GPIOB_DIO21                            (0X00000001)
#define MSP_IOMUX_PINCM49_PF_SPI1_POCI                              (0X00000002)
#define MSP_IOMUX_PINCM49_PF_TIMG8_CCP0                             (0X00000003)

/* MSP_IOMUX_PINCM50[PF] Bits */
#define MSP_IOMUX_PINCM50_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM50_PF_GPIOB_DIO22                            (0X00000001)
#define MSP_IOMUX_PINCM50_PF_SPI1_PICO                              (0X00000002)
#define MSP_IOMUX_PINCM50_PF_TIMG8_CCP1                             (0X00000003)

/* MSP_IOMUX_PINCM51[PF] Bits */
#define MSP_IOMUX_PINCM51_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM51_PF_GPIOB_DIO23                            (0X00000001)
#define MSP_IOMUX_PINCM51_PF_SPI1_SCLK                              (0X00000002)
#define MSP_IOMUX_PINCM51_PF_COMP0_OUT                              (0X00000003)
#define MSP_IOMUX_PINCM51_PF_TIMA_FAULT0                            (0X00000004)

/* MSP_IOMUX_PINCM52[PF] Bits */
#define MSP_IOMUX_PINCM52_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM52_PF_GPIOB_DIO24                            (0X00000001)
#define MSP_IOMUX_PINCM52_PF_SPI0_CS3_CD_POCI3                      (0X00000002)
#define MSP_IOMUX_PINCM52_PF_SPI0_CS1_POCI1                         (0X00000003)
#define MSP_IOMUX_PINCM52_PF_TIMA0_CCP3                             (0X00000004)
#define MSP_IOMUX_PINCM52_PF_TIMG12_CCP1                            (0X00000005)
#define MSP_IOMUX_PINCM52_PF_TIMA0_CCP1_CMPL                        (0X00000006)
#define MSP_IOMUX_PINCM52_PF_TIMA1_CCP0_CMPL                        (0X00000007)

/* MSP_IOMUX_PINCM53[PF] Bits */
#define MSP_IOMUX_PINCM53_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM53_PF_GPIOA_DIO23                            (0X00000001)
#define MSP_IOMUX_PINCM53_PF_UART2_TX                               (0X00000002)
#define MSP_IOMUX_PINCM53_PF_SPI0_CS3_CD_POCI3                      (0X00000003)
#define MSP_IOMUX_PINCM53_PF_TIMA0_CCP3                             (0X00000004)
#define MSP_IOMUX_PINCM53_PF_TIMG0_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM53_PF_UART3_CTS                              (0X00000006)
#define MSP_IOMUX_PINCM53_PF_TIMG7_CCP0                             (0X00000007)
#define MSP_IOMUX_PINCM53_PF_TIMG8_CCP0                             (0X00000008)

/* MSP_IOMUX_PINCM54[PF] Bits */
#define MSP_IOMUX_PINCM54_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM54_PF_GPIOA_DIO24                            (0X00000001)
#define MSP_IOMUX_PINCM54_PF_UART2_RX                               (0X00000002)
#define MSP_IOMUX_PINCM54_PF_SPI0_CS2_POCI2                         (0X00000003)
#define MSP_IOMUX_PINCM54_PF_TIMA0_CCP3_CMPL                        (0X00000004)
#define MSP_IOMUX_PINCM54_PF_TIMG0_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM54_PF_UART3_RTS                              (0X00000006)
#define MSP_IOMUX_PINCM54_PF_TIMG7_CCP1                             (0X00000007)
#define MSP_IOMUX_PINCM54_PF_TIMA1_CCP1                             (0X00000008)

/* MSP_IOMUX_PINCM55[PF] Bits */
#define MSP_IOMUX_PINCM55_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM55_PF_GPIOA_DIO25                            (0X00000001)
#define MSP_IOMUX_PINCM55_PF_UART3_RX                               (0X00000002)
#define MSP_IOMUX_PINCM55_PF_SPI1_CS3_CD_POCI3                      (0X00000003)
#define MSP_IOMUX_PINCM55_PF_TIMG12_CCP1                            (0X00000004)
#define MSP_IOMUX_PINCM55_PF_TIMA0_CCP3                             (0X00000005)
#define MSP_IOMUX_PINCM55_PF_TIMA0_CCP1_CMPL                        (0X00000006)

/* MSP_IOMUX_PINCM56[PF] Bits */
#define MSP_IOMUX_PINCM56_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM56_PF_GPIOB_DIO25                            (0X00000001)
#define MSP_IOMUX_PINCM56_PF_UART0_CTS                              (0X00000002)
#define MSP_IOMUX_PINCM56_PF_SPI0_CS0                               (0X00000003)
#define MSP_IOMUX_PINCM56_PF_TIMA_FAULT2                            (0X00000004)

/* MSP_IOMUX_PINCM57[PF] Bits */
#define MSP_IOMUX_PINCM57_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM57_PF_GPIOB_DIO26                            (0X00000001)
#define MSP_IOMUX_PINCM57_PF_UART0_RTS                              (0X00000002)
#define MSP_IOMUX_PINCM57_PF_SPI0_CS1_POCI1                         (0X00000003)
#define MSP_IOMUX_PINCM57_PF_TIMA0_CCP3                             (0X00000004)
#define MSP_IOMUX_PINCM57_PF_TIMG6_CCP0                             (0X00000005)
#define MSP_IOMUX_PINCM57_PF_TIMA1_CCP0                             (0X00000006)

/* MSP_IOMUX_PINCM58[PF] Bits */
#define MSP_IOMUX_PINCM58_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM58_PF_GPIOB_DIO27                            (0X00000001)
#define MSP_IOMUX_PINCM58_PF_COMP2_OUT                              (0X00000002)
#define MSP_IOMUX_PINCM58_PF_SPI1_CS1_POCI1                         (0X00000003)
#define MSP_IOMUX_PINCM58_PF_TIMA0_CCP3_CMPL                        (0X00000004)
#define MSP_IOMUX_PINCM58_PF_TIMG6_CCP1                             (0X00000005)
#define MSP_IOMUX_PINCM58_PF_TIMA1_CCP1                             (0X00000006)

/* MSP_IOMUX_PINCM59[PF] Bits */
#define MSP_IOMUX_PINCM59_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM59_PF_GPIOA_DIO26                            (0X00000001)
#define MSP_IOMUX_PINCM59_PF_UART3_TX                               (0X00000002)
#define MSP_IOMUX_PINCM59_PF_SPI1_CS0                               (0X00000003)
#define MSP_IOMUX_PINCM59_PF_TIMG8_CCP0                             (0X00000004)
#define MSP_IOMUX_PINCM59_PF_TIMA_FAULT0                            (0X00000005)
#define MSP_IOMUX_PINCM59_PF_CANFD0_CANTX                           (0X00000006)
#define MSP_IOMUX_PINCM59_PF_TIMG7_CCP0                             (0X00000007)

/* MSP_IOMUX_PINCM60[PF] Bits */
#define MSP_IOMUX_PINCM60_PF_UNCONNECTED                            (0X00000000)
#define MSP_IOMUX_PINCM60_PF_GPIOA_DIO27                            (0X00000001)
#define MSP_IOMUX_PINCM60_PF_RTC_RTC_OUT                            (0X00000002)
#define MSP_IOMUX_PINCM60_PF_SPI1_CS1_POCI1                         (0X00000003)
#define MSP_IOMUX_PINCM60_PF_TIMG8_CCP1                             (0X00000004)
#define MSP_IOMUX_PINCM60_PF_TIMA_FAULT2                            (0X00000005)
#define MSP_IOMUX_PINCM60_PF_CANFD0_CANRX                           (0X00000006)
#define MSP_IOMUX_PINCM60_PF_TIMG7_CCP1                             (0X00000007)

#define MSP_PORT_INDEX_BY_NAME(x) ((x == "PORTA")?0:1)

/* creates a concatination of the correct pin function based on the CM 
 * and the function suffix. Will evaluate to the pin function number above. */
#define MSP_PIN_FUNCTION(cm, func) (MSP_IOMUX_PINCM##cm##_PF_##func)

#define MSP_PINMUX(pincm, func) (((pincm - 1) << 0x10 ) | MSP_PIN_FUNCTION(pincm, func))


#endif