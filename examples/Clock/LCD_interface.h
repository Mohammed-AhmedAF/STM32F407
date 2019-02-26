#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8CommandCpy);
void LCD_vidWriteCharacter(u8 u8CharacterCpy);
void LCD_vidWriteString(u8 * u8StringPtrCpy);
void LCD_vidWriteNumber(u16 u16NumberCpy);
void LCD_vidGoToXY(s8,s8);
void LCD_vidWriteInPlace(u8,u8,u8);


/*Data port definitions*/
#define LCD_D0_PORT GPIO_PORTA
#define LCD_D1_PORT GPIO_PORTA
#define LCD_D2_PORT GPIO_PORTA
#define LCD_D3_PORT GPIO_PORTA
#define LCD_D4_PORT GPIO_PORTA
#define LCD_D5_PORT GPIO_PORTA
#define LCD_D6_PORT GPIO_PORTA
#define LCD_D7_PORT GPIO_PORTA

/*Command port definitions*/
#define LCD_RS_PORT GPIO_PORTA
#define LCD_RW_PORT GPIO_PORTA
#define LCD_EN_PORT GPIO_PORTA

/*Data pin definitions*/
#define LCD_D0_PIN GPIO_PIN0
#define LCD_D1_PIN GPIO_PIN1
#define LCD_D2_PIN GPIO_PIN2
#define LCD_D3_PIN GPIO_PIN3
#define LCD_D4_PIN GPIO_PIN4
#define LCD_D5_PIN GPIO_PIN5
#define LCD_D6_PIN GPIO_PIN6
#define LCD_D7_PIN GPIO_PIN7

/*Command pin definitions*/
#define LCD_RS_PIN GPIO_PIN8
#define LCD_RW_PIN GPIO_PIN9
#define LCD_EN_PIN GPIO_PIN10

/*Macros defined to be used with the GoTOXY function*/
#define LCD_XPOS0 0
#define LCD_XPOS1 1
#define LCD_XPOS2 2
#define LCD_XPOS3 3
#define LCD_XPOS4 4
#define LCD_XPOS5 5
#define LCD_XPOS6 6
#define LCD_XPOS7 7
#define LCD_XPOS8 8
#define LCD_XPOS9 9
#define LCD_XPOS10 10
#define LCD_XPOS11 11
#define LCD_XPOS12 12
#define LCD_XPOS13 13
#define LCD_XPOS14 14
#define LCD_XPOS15 15
#define LCD_XPOS16 16
#define LCD_XPOS17 17
#define LCD_XPOS18 18
#define LCD_XPOS19 19

#define LCD_YPOS0 0
#define LCD_YPOS1 1
#define LCD_YPOS2 2
#define LCD_YPOS3 3
/*This macro is used to shift the clock digits
 *on LCD row.
 * */
#define  LCD_XPOS_SHIFT 5

/*Definitions of LCD commands*/
#define LCD_CLEAR_SCREEN 0x00
#define LCD_RETURN_HOME 0x01


#endif
