#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/*Register definitions*/
#define NVIC_ISER0 * ((u32*) 0xE000E100)
#define NVIC_ISER1 * ((u32*) 0xE000E104)
#define NVIC_ISER2 * ((u32*) 0xE000E108)
#define NVIC_ISER3 * ((u32*) 0xE000E10C)
#define NVIC_ISER4 * ((u32*) 0xE000E110)
#define NVIC_ISER5 * ((u32*) 0xE000E114)
#define NVIC_ISER6 * ((u32*) 0xE000E118)
#define NVIC_ISER7 * ((u32*) 0xE000E11C)

#define NVIC_ICER0 * ((u32*) 0xE000E180)
#define NVIC_ICER1 * ((u32*) 0xE000E184)
#define NVIC_ICER2 * ((u32*) 0xE000E188)
#define NVIC_ICER3 * ((u32*) 0xE000E18C)
#define NVIC_ICER4 * ((u32*) 0xE000E190)
#define NVIC_ICER5 * ((u32*) 0xE000E194)
#define NVIC_ICER6 * ((u32*) 0xE000E198)
#define NVIC_ICER7 * ((u32*) 0xE000E19C)

#endif