#ifdef _RCC_H
#define _RCC_H

#include "base.h"

#define RCC_AHB1_ENR_OFFSET (0x30)
#define RCC_AHB1_ENR (*(volatile unsign int *)(RCC + RCC_AHB1_ENR_OFFSET))

#define RCC_AHB2_ENR_OFFSET (0x34)
#define RCC_AHB2_ENR (*(volatile unsign int *)(RCC + RCC_AHB2_ENR_OFFSET))

#define RCC_APB1_ENR_OFFSET (0x40)
#define RCC_APB1_ENR (*(volatile unsign int *)(RCC + RCC_APB1_ENR_OFFSET))

#define RCC_APB2_ENR_OFFSET (0x44)
#define RCC_APB2_ENR (*(volatile unsign int *)(RCC + RCC_APB2_ENR_OFFSET))

#endif // _RCC_H