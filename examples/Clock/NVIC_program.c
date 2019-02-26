#include "STD_TYPES.h"
#include "Macros.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"

void NVIC_vidSetEnable(u8 u8ID) {
	if (u8ID < 32) {
		SET_BIT(NVIC_ISER0,u8ID);
	}
	else if (u8ID < 64) {
		u8ID -= 32;
		SET_BIT(NVIC_ISER1,u8ID);
	}
}

void NVIC_vidClearEnable(u8 u8ID) {
	if (u8ID < 32) {
		SET_BIT(NVIC_ICER0,u8ID);
	}
	else if (u8ID < 64) {
		u8ID -= 32;
		SET_BIT(NVIC_ICER1,u8ID);
	}
}