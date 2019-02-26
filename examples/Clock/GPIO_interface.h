#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13

#define GPIO_MODE_INPUT 0
#define GPIO_MODE_GPOUTPUT 1
#define GPIO_MODE_ALTERNATE 2
#define GPIO_MODE_ANALOG 3


void GPIO_vidSetPinMode(u8,u8,u8);
void GPIO_vidSetPinValue(u8,u8,u8);

#endif
