#ifndef _TIMER2_PRIVATE_H
#define _TIMER2_PRIVATE_H

/*Registers definitions*/
#define TIM2_CR1 * ((u32*) 0x40000000)
#define TIM2_CR2 *  ((u32*) 0x40000004)
#define TIM2_SMCR * ((u32*) 0x40000008)
#define TIM2_DIER * ((u32*) 0x4000000C)
#define TIM2_SR * ((u32*) 0x40000010)
#define TIM2_EGR * ((u32*) 0x40000014)
#define TIM2_CCMR1 * ((u32*) 0x4000018)
#define TIM2_CCMR2 * ((u32*) 0x4000001C)
#define TIM2_CCER * ((u32*) 0x40000020)
#define TIM2_CNT * ((u32*) 0x40000024)
#define TIM2_PSC * ((u32*) 0x40000028)
#define TIM2_ARR * ((u32*) 0x4000002C)
#define TIM2_CCR1 * ((u32*) 0x40000034)
#define TIM2_CCR2 * ((u32*) 0x40000038)
#define TIM2_CCR3 * ((u32*) 0x4000003C)
#define TIM2_CCR4 * ((u32*) 0x40000040)
#define TIM2_DCR * ((u32*) 0x40000048)
#define TIM2_DMAR * ((u32*) 0x4000004C)
#define TIM2_OR * ((u32*) 0x40000050)

#endif