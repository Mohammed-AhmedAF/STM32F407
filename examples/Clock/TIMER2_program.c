#include "STD_TYPES.h"
#include "Macros.h"
#include "TIMER2_private.h"
#include "TIMER2_interface.h"

void (*TIM2_CallBack) (void);

void TIMER2_vidInit(u8 u8CountDirection) {
	/*Counter direction*/
	if (u8CountDirection == TIMER2_UPCOUNT) {
	CLEAR_BIT(TIM2_CCR1,4); /*Counter is counting up*/
	}
	else {
	SET_BIT(TIM2_CCR1,4);
	}
	
	/*Enabling interrupt*/
	SET_BIT(TIM2_DIER,0);
	
	/*Auto reload value*/
	TIM2_ARR = 49999;
	/*Start counter*/
	SET_BIT(TIM2_CR1,0);
}

/*
*This function takes a pointer to a function that will
* be called when a timer interrupt happens.
*/
void TIMER2_vidSetCallBack(void (*funcPtr) (void)) {
	TIM2_CallBack = funcPtr;
}

void TIM2_IRQHandler(void) {
	TIM2_CallBack();
}

