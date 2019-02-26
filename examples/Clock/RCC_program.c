#include "STD_TYPES.h"
#include "Macros.h"
#include "RCC_private.h"
#include "RCC_interface.h"

void RCC_vidEnableClock(u8 u8Prephiral) {
	switch (u8Prephiral) {
		case RCC_PREPHIRAL_GPIOA:
			RCC_AHP1ENR |= (1<<0);
		break;
		case RCC_PREPHIRAL_GPIOB:
			SET_BIT(RCC_AHP1ENR,1);
		break;
		case RCC_PREPHIRAL_GPIOC:
			SET_BIT(RCC_AHP1ENR,2);
		break;
		case RCC_PREPHIRAL_GPIOD:
			SET_BIT(RCC_AHP1ENR,3);
		break;
		case RCC_PREPHIRAL_TIMER2:
			SET_BIT(RCC_APB1ENR,0);
		break;
	}
}
