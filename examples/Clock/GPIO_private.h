#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

typedef struct {
	unsigned int MODER;
	unsigned int OTYPER;
	unsigned int OSPEEDR;
	unsigned int PUPDR;
	unsigned int IDR;
	unsigned int ODR;
	unsigned int BSRR;
	unsigned int LCKR;
	unsigned int AFRL;
	unsigned int AFRH;
	
}GPIO_TYPE;

#define GPIOA ((GPIO_TYPE*) 0x40020000)
#define GPIOB ((GPIO_TYPE*) 0x40020400)
#define GPIOC ((GPIO_TYPE*) 0x40020800)
#define GPIOD ((GPIO_TYPE*) 0x40020C00)


#endif
