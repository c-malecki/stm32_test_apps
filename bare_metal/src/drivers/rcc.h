#ifndef _RCC_H
#define _RCC_H

#include "base.h"
#include <stdint.h>

#define RCC_AHB1_ENR_OFFSET (0x30UL)
#define RCC_AHB1_ENR (*(volatile uint32_t *)(RCC + RCC_AHB1_ENR_OFFSET))

#define RCC_AHB2_ENR_OFFSET (0x34UL)
#define RCC_AHB2_ENR (*(volatile uint32_t *)(RCC + RCC_AHB2_ENR_OFFSET))

#define RCC_APB1_ENR_OFFSET (0x40UL)
#define RCC_APB1_ENR (*(volatile uint32_t *)(RCC + RCC_APB1_ENR_OFFSET))

#define RCC_APB2_ENR_OFFSET (0x44UL)
#define RCC_APB2_ENR (*(volatile uint32_t *)(RCC + RCC_APB2_ENR_OFFSET))

#endif // _RCC_H