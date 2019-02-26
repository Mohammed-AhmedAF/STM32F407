/*
* Author: Mohamed Ahmed Abd Al-Fattah
* Purpose: LCD driver for stm32f407
*/

/* 
 * Author: Mohamed Ahmed Abd Al-Fattah
 * Purpose: 16x2 LCD driver for stm32f103c8t6 MCU
 */

#include "STD_TYPES.h"
#include "Macros.h"
#include "GPIO_interface.h"
#include "LCD_interface.h"

u16 i = 0;
void LCD_vidInit(void) {

	/*Setting mode for data pins*/
	GPIO_vidSetPinMode(LCD_D0_PORT,LCD_D0_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D1_PORT,LCD_D1_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D2_PORT,LCD_D2_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D3_PORT,LCD_D3_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D4_PORT,LCD_D4_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D5_PORT,LCD_D5_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D6_PORT,LCD_D6_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_D7_PORT,LCD_D7_PIN,GPIO_MODE_GPOUTPUT);

/*Setting mode for control pins*/
	GPIO_vidSetPinMode(LCD_RS_PORT,LCD_RS_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_RW_PORT,LCD_RW_PIN,GPIO_MODE_GPOUTPUT);
	GPIO_vidSetPinMode(LCD_EN_PORT,LCD_EN_PIN,GPIO_MODE_GPOUTPUT);
	
	/*Giving initialization commands*/
	LCD_vidSendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	LCD_vidSendCommand(LCD_RETURN_HOME); /*Move to home*/
	LCD_vidSendCommand(0b00000110); /*Set entry mode*/
	LCD_vidSendCommand(0b00001100); /*Display On/Off control*/
	LCD_vidSendCommand(0b00110000); /*Function Set*/
}

void LCD_vidSendCommand(u8 u8commandCpy) {
	GPIO_vidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,STD_LOW);
	GPIO_vidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,STD_LOW);

	GPIO_vidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(u8commandCpy,0));
	GPIO_vidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(u8commandCpy,1));
	GPIO_vidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(u8commandCpy,2));
	GPIO_vidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(u8commandCpy,3));
	GPIO_vidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(u8commandCpy,4));
	GPIO_vidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(u8commandCpy,5));
	GPIO_vidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(u8commandCpy,6));
	GPIO_vidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(u8commandCpy,7));

	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_HIGH);
	for(i = 0; i < 16000; i++);
	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_LOW);
	for (i = 0; i<16000; i++);
	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_HIGH);	

}

void LCD_vidWriteCharacter(u8 u8CharacterCpy) {
	GPIO_vidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,STD_HIGH);
	GPIO_vidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,STD_LOW);

	GPIO_vidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(u8CharacterCpy,0));
	GPIO_vidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(u8CharacterCpy,1));
	GPIO_vidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(u8CharacterCpy,2));
	GPIO_vidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(u8CharacterCpy,3));
	GPIO_vidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(u8CharacterCpy,4));
	GPIO_vidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(u8CharacterCpy,5));
	GPIO_vidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(u8CharacterCpy,6));
	GPIO_vidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(u8CharacterCpy,7));

	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_HIGH);
	for(i = 0; i < 16000; i++);
	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_LOW);
	for(i = 0; i < 16000; i++);
	GPIO_vidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,STD_HIGH);	
}

void LCD_vidWriteString(u8 * u8StringPtrCpy) {
	while (*u8StringPtrCpy != '\0') {
		LCD_vidWriteCharacter(*u8StringPtrCpy);
		u8StringPtrCpy++;
	}

}

void LCD_vidWriteNumber(u16 u16NumberCpy) {
	if(u16NumberCpy < 10) {
		LCD_vidWriteCharacter(u16NumberCpy+'0');
	}
	else {
		if (u16NumberCpy < 100) {
			LCD_vidWriteCharacter(u16NumberCpy/10+'0');
			LCD_vidWriteCharacter(u16NumberCpy%10+'0');
		}
		else if  (u16NumberCpy < 1000) {
			LCD_vidWriteCharacter(u16NumberCpy/100+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
		}
		else if (u16NumberCpy < 10000) {
			LCD_vidWriteCharacter((u16NumberCpy/1000)+'0');
			LCD_vidWriteCharacter((u16NumberCpy%1000)/100+'0');
			LCD_vidWriteCharacter(((u16NumberCpy%1000)%100)/10+'0');
			LCD_vidWriteCharacter((u16NumberCpy%1000)%10+'0');
		}
	}
}

void LCD_vidGoToXY(s8 s8xCpy, s8 s8yCpy) {
	if (s8yCpy == 1) {
			LCD_vidSendCommand(0x80+s8xCpy);
	}
	else {
			LCD_vidSendCommand(0xC0+s8xCpy);
	}
}

/*This function has been reedited to allow writing a character
 *on a specific row and a specific column.
 * */
void LCD_vidWriteInPlace(u8 u8xCpy,u8 u8yCpy, u8 u8CharCpy) {
	LCD_vidGoToXY(u8xCpy,u8yCpy);
	LCD_vidWriteCharacter(u8CharCpy);
}

