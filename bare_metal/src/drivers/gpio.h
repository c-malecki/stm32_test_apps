#ifndef _GPIO_H
#define _GPIO_H

#include "base.h"
#include <stdint.h>

typedef struct
{
    volatile uint32_t MODER; // 0x00
    volatile uint32_t OTYPER; // 0x04
    volatile uint32_t OSPEEDR; // 0x08
    volatile uint32_t PUPDR; // 0x0C
    volatile uint32_t IDR; // 0x10
    volatile uint32_t ODR; // 0x14
    volatile uint32_t BSRR; // 0x18
    volatile uint32_t LCKR; // 0x1C
    volatile uint32_t AFRL; // 0x20
    volatile uint32_t AFRH; // 0x24
} GPIO_T;

#define GPIOA_MODER_OFFSET (0x00UL)
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA + GPIOA_MODER_OFFSET))

#define GPIOA_OTYPER_OFFSET (0x04UL)
#define GPIOA_OTYPER (*(volatile uint32_t *)(GPIOA + GPIOA_OTYPER_OFFSET))

#define GPIOA_OSPEEDR_OFFSET (0x08UL)
#define GPIOA_OSPEEDR (*(volatile uint32_t *)(GPIOA + GPIOA_OSPEEDR_OFFSET))

#define GPIOA_PUPDR_OFFSET (0x0CUL)
#define GPIOA_PUPDR (*(volatile uint32_t *)(GPIOA + GPIOA_PUPDR_OFFSET))

// Input Data Register
#define GPIOA_IDR_OFFSET (0x10UL)
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA + GPIOA_IDR_OFFSET))

// Output Data Register
#define GPIOA_ODR_OFFSET (0x14UL)
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA + GPIOA_ODR_OFFSET))

#define GPIOA_BSRR_OFFSET (0x18UL)
#define GPIOA_BSRR (*(volatile uint32_t *)(GPIOA + GPIOA_BSRR_OFFSET))

#define GPIOA_LCKR_OFFSET (0x1CUL)
#define GPIOA_LCKR (*(volatile uint32_t *)(GPIOA + GPIOA_LCKR_OFFSET))

#define GPIOA_AFRL_OFFSET (0x20UL)
#define GPIOA_AFRL (*(volatile uint32_t *)(GPIOA + GPIOA_AFRL_OFFSET))

#define GPIOA_AFRH_OFFSET (0x24UL)
#define GPIOA_AFRH (*(volatile uint32_t *)(GPIOA + GPIOA_AFRH_OFFSET))

#endif // _GPIO_H