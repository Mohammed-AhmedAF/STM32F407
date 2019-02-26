#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

void NVIC_vidSetEnable(u8 u8ID);
void NVIC_vidClearEnable(u8 u8ID);

/*NVIC IDs*/
#define NVIC_ID_TIMER2 28
#define NVIC_ID_TIMER3 29
#define NVIC_ID_TIMER4 30
#define NVIC_ID_EXTI0 6
#define NVIC_ID_EXTI1 7
#define NVIC_ID_EXTI2 8
#define NVIC_ID_EXTI3 9
#define NVIC_ID_EXTI4 10

#endif
