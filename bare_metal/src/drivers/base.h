#ifndef _BASE_H
#define _BASE_H

/*
  APB1 is the base addr for peripherals and all offsets are calculated from this addr
*/

#define PERIPHERAL_BASE (0x40000000UL)

/*
  APB1                          0x4000 0000
  *****************************************
  PWR                           0x4000 7000
  I2C3                          0x4000 5C00
  I2C2                          0x4000 5800
  I2C1                          0x4000 5400
  USART2                        0x4000 4400
  I2S3ext                       0x4000 4000
  SPI3 / I2S3                   0x4000 3C00
  SPI2 / I2S2                   0x4000 3800
  I2S2ext                       0x4000 3400
  IWDG                          0x4000 3000
  WWDG                          0x4000 2C00
  RTC and BKP Registers         0x4000 2800
  TIM5                          0x4000 0C00
  TIM4                          0x4000 0800
  TIM3                          0x4000 0400
  TIM2                          0x4000 0000
*/

#define APB1_PERIPHERAL_OFFSET (0x0000UL)
#define APB1_PERIPHERAL (PERIPHERAL_BASE + APB1_PERIPHERAL_OFFSET)

// #define PWR_OFFSET (0x00007000UL)
// #define PWR (APB1_PERIPHERAL + PWR_OFFSET)

#define I2C3_OFFSET (0x00005C00UL)
#define I2C3 (APB1_PERIPHERAL + I2C3_OFFSET)

#define I2C2_OFFSET (0x00005800UL)
#define I2C2 (APB1_PERIPHERAL + I2C2_OFFSET)

#define I2C1_OFFSET (0x00005400UL)
#define I2C1 (APB1_PERIPHERAL + I2C1_OFFSET)

#define USART2_OFFSET (0x00004400UL)
#define USART2 (APB1_PERIPHERAL + USART2_OFFSET)

#define I2S3EXT_OFFSET (0x00004000UL)
#define I2S3EXT (APB1_PERIPHERAL + I2S3EXT_OFFSET)

#define SPI3_I2S3_OFFSET (0x00003C00UL)
#define SPI3_I2S3 (APB1_PERIPHERAL + SPI3_I2S3_OFFSET)

#define SPI2_I2S2_OFFSET (0x00003800UL)
#define SPI2_I2S2 (APB1_PERIPHERAL + SPI2_I2S2_OFFSET)

#define I2S2EXT_OFFSET (0x00003400UL)
#define I2S2EXT (APB1_PERIPHERAL + I2S2EXT_OFFSET)

#define IWDG_OFFSET (0x00003000UL)
#define IWDG (APB1_PERIPHERAL + IWDG_OFFSET)

#define WWDG_OFFSET (0x00002C00UL)
#define WWDG (APB1_PERIPHERAL + WWDG_OFFSET)

// #define RTC_AND_BKP_REGS_OFFSET (0x00002800UL)
// #define RTC_AND_BKP_REGS (APB1_PERIPHERAL + RTC_AND_BKP_REGS_OFFSET)

#define TIM5_OFFSET (0x00000C00UL)
#define TIM5 (APB1_PERIPHERAL + TIM5_OFFSET)

#define TIM4_OFFSET (0x00000800UL)
#define TIM4 (APB1_PERIPHERAL + TIM4_OFFSET)

#define TIM3_OFFSET (0x00000400UL)
#define TIM3 (APB1_PERIPHERAL + TIM3_OFFSET)

#define TIM2_OFFSET (0x00000000UL)
#define TIM2 (APB1_PERIPHERAL + TIM2_OFFSET)

/*
  APB2                          0x4000 7400
  *****************************************
  SPI5 / I2S5                   0x400 15000
  TIM11                         0x400 14800
  TIM10                         0x400 14400
  TIM9                          0x400 14000
  EXTI                          0x400 13C00
  SYSCFG                        0x400 13800
  SPI4/I2S4                     0x400 13400
  SPI1/I2S1                     0x400 13000
  SDIO                          0x400 12C00
  ADC1                          0x400 12000
  USART6                        0x400 11400
  USART1                        0x400 11000
  TIM1                          0x400 10000
*/

#define APB2_PERIPHERAL_OFFSET (0x00007400UL)
#define APB2_PERIPHERAL (PERIPHERAL_BASE + APB2_PERIPHERAL_OFFSET)

#define SPI5_I2S5_OFFSET (0x00015000UL)
#define SPI5_I2S5 (APB2_PERIPHERAL + SPI5_I2S5_OFFSET)

#define TIM11_OFFSET (0x00014800UL)
#define TIM11 (APB2_PERIPHERAL + TIM11_OFFSET)

#define TIM10_OFFSET (0x00014400UL)
#define TIM10 (APB2_PERIPHERAL + TIM10_OFFSET)

#define TIM9_OFFSET (0x00014000UL)
#define TIM9 (APB2_PERIPHERAL + TIM9_OFFSET)

#define EXTI_OFFSET (0x00013C00UL)
#define EXTI (APB2_PERIPHERAL + EXTI_OFFSET)

// #define SYSCFG_OFFSET (0x00013800UL)
// #define SYSCFG (APB2_PERIPHERAL + SYSCFG_OFFSET)

#define SPI4_I2S4_OFFSET (0x00013400UL)
#define SPI4_I2S4 (APB2_PERIPHERAL + SPI4_I2S4_OFFSET)

#define SPI1_I2S1_OFFSET (0x00013000UL)
#define SPI1_I2S1 (APB2_PERIPHERAL + SPI1_I2S1_OFFSET)

// #define SDIO_OFFSET (0x00012C00UL)
// #define SDIO (APB2_PERIPHERAL + SDIO_OFFSET)

#define ADC1_OFFSET (0x00012000UL)
#define ADC1 (APB2_PERIPHERAL + ADC1_OFFSET)

#define USART6_OFFSET (0x00011400UL)
#define USART6 (APB2_PERIPHERAL + USART6_OFFSET)

#define USART1_OFFSET (0x00011000UL)
#define USART1 (APB2_PERIPHERAL + USART1_OFFSET)

#define TIM1_OFFSET (0x00010000UL)
#define TIM1 (APB2_PERIPHERAL + TIM1_OFFSET)

/*
  AHB1                          0x4002 0000
  *****************************************
  DMA2                          0x400 26400
  DMA1                          0x400 26000
  Flash Interface Register      0x400 23C00
  RCC                           0x400 23800
  CRC                           0x400 23000
  GPIOH                         0x400 21C00
  GPIOE                         0x400 21000
  GPIOD                         0x400 20C00
  GPIOC                         0x400 20800
  GPIOB                         0x400 20400
  GPIOA                         0x400 20000
*/

#define AHB1_PERIPHERAL_OFFSET (0x00020000UL)
#define AHB1_PERIPHERAL (PERIPHERAL_BASE + AHB1_PERIPHERAL_OFFSET)

#define DMA2_OFFSET (0x00026400UL)
#define DMA2 (AHB1_PERIPHERAL + DMA2_OFFSET)

#define DMA1_OFFSET (0x00026000UL)
#define DMA1 (AHB1_PERIPHERAL + DMA1_OFFSET)

// #define FLASH_INTERFACE_REG_OFFSET (0x00023C00UL)
// #define FLASH_INTERFACE_REG (AHB1_PERIPHERAL + FLASH_INTERFACE_REG_OFFSET)

#define RCC_OFFSET (0x00023800UL)
#define RCC (AHB1_PERIPHERAL + RCC_OFFSET)

#define CRC_OFFSET (0x00023000UL)
#define CRC (AHB1_PERIPHERAL + CRC_OFFSET)

#define GPIOH_OFFSET (0x00021C00UL)
#define GPIOH (AHB1_PERIPHERAL + GPIOH_OFFSET)

#define GPIOE_OFFSET (0x00021000UL)
#define GPIOE (AHB1_PERIPHERAL + GPIOE_OFFSET)

#define GPIOD_OFFSET (0x00020C00UL)
#define GPIOD (AHB1_PERIPHERAL + GPIOD_OFFSET)

#define GPIOC_OFFSET (0x00020800UL)
#define GPIOC (AHB1_PERIPHERAL + GPIOC_OFFSET)

#define GPIOB_OFFSET (0x00020400UL)
#define GPIOB (AHB1_PERIPHERAL + GPIOB_OFFSET)

#define GPIOA_OFFSET (0x00020000UL)
#define GPIOA (AHB1_PERIPHERAL + GPIOA_OFFSET)

/*
  AHB2                          0x5000 0000
  *****************************************
  USB OTG FS                    0x5000 0000
*/

// #define AHB2_PERIPHERAL_OFFSET (0x10000000UL)
// #define AHB2_PERIPHERAL (PERIPHERAL_BASE + AHB2_PERIPHERAL_OFFSET)

/*
  M4 internal peripherals       0xE000 0000
*/

#endif // _BASE_H