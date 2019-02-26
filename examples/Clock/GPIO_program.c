#include "STD_TYPES.h"
#include "Macros.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

void GPIO_vidSetPinMode(u8 u8PortNum, u8 u8PinNum, u8 u8Mode) {
	u8 value;
	switch (u8Mode) {
		case GPIO_MODE_INPUT:
			value = 0x0;
		break;
		case GPIO_MODE_GPOUTPUT:
			value = 0x1;
		break;
		case GPIO_MODE_ALTERNATE:
			value = 0x2;
		break;
		case GPIO_MODE_ANALOG:
			value = 0x3;
		break;
	}
	if (u8PortNum == GPIO_PORTA) {
	GPIOA->MODER |= value<<u8PinNum*2;
	}
	else if (u8PortNum == GPIO_PORTB) {
	GPIOB->MODER |= value<<u8PinNum*2;
	}
	else if (u8PortNum == GPIO_PORTC) {
	GPIOC->MODER |= value<<u8PinNum*2;
	}
	else if (u8PortNum == GPIO_PORTD) {
	GPIOD->MODER |= value<<u8PinNum*2;
	}
}

void GPIO_vidSetPinValue(u8 u8PortNum, u8 u8PinNum, u8 u8Value) {
	switch(u8PortNum) {
		case GPIO_PORTA:
			if (u8Value == STD_HIGH) {
				SET_BIT(GPIOA->ODR,u8PinNum);
			}
			else {
				CLEAR_BIT(GPIOA->ODR,u8PinNum);
			}
			break;
		case GPIO_PORTB:
			if (u8Value  == STD_HIGH) {
				SET_BIT(GPIOB->ODR,u8PinNum);
			}
			else {
				CLEAR_BIT(GPIOB->ODR,u8PinNum);
			}
			break;
		case GPIO_PORTC:
			if (u8Value == STD_HIGH) {
				SET_BIT(GPIOC->ODR,u8PinNum);
			}
			else {
				CLEAR_BIT(GPIOC->ODR,u8PinNum);
			}
			break;
		case GPIO_PORTD:
			if (u8Value == STD_HIGH) {
				SET_BIT(GPIOD->ODR,u8PinNum);
			}
			else {
				CLEAR_BIT(GPIOD->ODR,u8PinNum);
			}
	}
}
