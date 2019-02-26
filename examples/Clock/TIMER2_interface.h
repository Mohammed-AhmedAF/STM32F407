#ifndef _TIMER2_INTERFACE_H
#define _TIMER2_INTERFACE_H


#define TIMER2_UPCOUNT 1
#define TIMER2_DOWNCOUNT 0

void TIMER2_vidInit(u8 u8CountDirection);
void TIMER2_vidSetCallBack(void (*ptrFun) (void));

#endif
