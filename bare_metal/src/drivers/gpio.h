#ifdef _GPIO_H
#define _GPIO_H

#include "base.h"

#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_MODER (*(volatile unsigned int *)(GPIOA + GPIOA_MODER_OFFSET))

#define GPIOA_OTYPER_OFFSET (0x04)
#define GPIOA_OTYPER (*(volatile unsigned int *)(GPIOA + GPIOA_OTYPER_OFFSET))

#define GPIOA_OSPEEDR_OFFSET (0x08)
#define GPIOA_OSPEEDR (*(volatile unsigned int *)(GPIOA + GPIOA_OSPEEDR_OFFSET))

#define GPIOA_PUPDR_OFFSET (0x0C)
#define GPIOA_PUPDR (*(volatile unsigned int *)(GPIOA + GPIOA_PUPDR_OFFSET))

// Input Data Register
#define GPIOA_IDR_OFFSET (0x10)
#define GPIOA_IDR (*(volatile unsigned int *)(GPIOA + GPIOA_IDR_OFFSET))

// Output Data Register
#define GPIOA_ODR_OFFSET (0x14)
#define GPIOA_ODR (*(volatile unsigned int *)(GPIOA + GPIOA_ODR_OFFSET))

#define GPIOA_BSRR_OFFSET (0x18)
#define GPIOA_BSRR (*(volatile unsigned int *)(GPIOA + GPIOA_BSRR_OFFSET))

#define GPIOA_LCKR_OFFSET (0x1C)
#define GPIOA_LCKR (*(volatile unsigned int *)(GPIOA + GPIOA_LCKR_OFFSET))

#define GPIOA_AFRL_OFFSET (0x20)
#define GPIOA_AFRL (*(volatile unsigned int *)(GPIOA + GPIOA_AFRL_OFFSET))

#define GPIOA_AFRH_OFFSET (0x24)
#define GPIOA_AFRH (*(volatile unsigned int *)(GPIOA + GPIOA_AFRH_OFFSET))

#endif // _GPIO_H