/*
* Author: Mohamed Ahmed Abd Al-Fattah
* Purpose: Clock project for STM32F407VG
*/

#include "Macros.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "TIMER2_interface.h"
#include "LCD_interface.h"
#include "CLOCK_interface.h"

u8 u8Flag;
int main(void) {
	/*Enabling clock for prephrals used*/
	RCC_vidEnableClock(RCC_PREPHIRAL_GPIOA);
	RCC_vidEnableClock(RCC_PREPHIRAL_TIMER2);
	
	/*NVIC TIMER2 global interrupt enabled*/
	NVIC_vidSetEnable(NVIC_ID_TIMER2);
	
	

	/*Timer2 initialization*/
	TIMER2_vidInit(TIMER2_UPCOUNT);
	TIMER2_vidSetCallBack(CLOCK_vidCount);
	/*Initializing LCD*/
	LCD_vidInit();


	while(1);
	return 0;
}

