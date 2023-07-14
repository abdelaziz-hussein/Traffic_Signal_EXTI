/*
 * LCD_Prog.c
 *
 *  Created on: May 20, 2023
 *      Author: Abdelaziz
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_register.h"
#include "LCD_Priv.h"
#include "LCD_Config.h"
#include "LCD_interface.h"
#include "avr/delay.h"

#if (LCD_mode == _4_pins)

void LCD_voidInit(void) {
	_delay_ms(50);

	LCD_voidWriteCommand(CONCBIT(0, 0, 1, 0, LCD_NoLines, LCD_Font, 0, 0));
	_delay_ms(5);
	LCD_voidWriteCommand(
			CONCBIT(0, 0, 0, 0, 1, LCD_Display, LCD_cursor, LCD_Blink));
	_delay_ms(5);
	LCD_voidWriteCommand(0x01);
	_delay_ms(5);
	LCD_voidWriteCommand(0b00000110);
}
/*
 * most used Commands Enable , Clear Screen , return Home and shift Right and Left
 */
void LCD_voidEnable(void) {
	DIO_voidSetPin(LCD_PIN_E, High);
	_delay_ms(1);
	DIO_voidSetPin(LCD_PIN_E, Low);
	_delay_ms(50);
}
void LCD_voidClearScreen(void) {
	LCD_voidWriteCommand(0x01);
}
void LCD_voidHome(void) {
	LCD_voidWriteCommand(0x02);
}
void LCD_voidShiftLeft(void)
{
	LCD_voidWriteCommand(0b00011000);
}
void LCD_voidShiftRight(void)
{
	LCD_voidWriteCommand(0b00011100);
}
/*
 * Write Data Functions
 */
void LCD_voidWriteChar(u8 character) {
	DIO_voidSetPin(LCD_PIN_RS, High);
	DIO_voidSetPin(LCD_PIN_RW, Low);

/*if(LCD_u8ReadAdress()==LCD_1stLine_End)
{
	LCD_voidGoToXY(1, 0);
}
else if(LCD_u8ReadAdress()==LCD_2ndLine_End)
{
	LCD_voidGoToXY(0, 0);
}*/

	DIO_voidSetPin(LCD_PIN_07, GETBIT(character, 7));
	DIO_voidSetPin(LCD_PIN_06, GETBIT(character, 6));
	DIO_voidSetPin(LCD_PIN_05, GETBIT(character, 5));
	DIO_voidSetPin(LCD_PIN_04, GETBIT(character, 4));
	LCD_voidEnable();
	DIO_voidSetPin(LCD_PIN_07, GETBIT(character, 3));
	DIO_voidSetPin(LCD_PIN_06, GETBIT(character, 2));
	DIO_voidSetPin(LCD_PIN_05, GETBIT(character, 1));
	DIO_voidSetPin(LCD_PIN_04, GETBIT(character, 0));
	LCD_voidEnable();

}
void LCD_voidWriteString(u8 *string) {
	u8 i = 0;
	while ((*(string + i)) != '\0') {
		LCD_voidWriteChar(*(string + i));
		i++;
	}

}
void LCD_voidWriteVariable(u16 variable) {
	//LCD_voidWriteChar((variable + 48));
	u8 sum[10],j=0;
		for (u16 i=variable;i>0;i=i/10)
		{
			sum[j]=i%10;
			j++;
		}
		for (s8 k=j-1;k>=0;k=k-1)// j-1 alshan akher rakam sum [j] hata5doh we ba3daha betzawed j++ fa keda ha access rakam 3ashwa2y
		{
			LCD_voidWriteChar(((sum[k])+48));

		}

}
/*
 * write Command function
 */
void LCD_voidWriteCommand(u8 command) {
	DIO_voidSetPin(LCD_PIN_RS, Low);
	DIO_voidSetPin(LCD_PIN_RW, Low);

	DIO_voidSetPin(LCD_PIN_07, GETBIT(command, 7));
	DIO_voidSetPin(LCD_PIN_06, GETBIT(command, 6));
	DIO_voidSetPin(LCD_PIN_05, GETBIT(command, 5));
	DIO_voidSetPin(LCD_PIN_04, GETBIT(command, 4));
	LCD_voidEnable();
	DIO_voidSetPin(LCD_PIN_07, GETBIT(command, 3));
	DIO_voidSetPin(LCD_PIN_06, GETBIT(command, 2));
	DIO_voidSetPin(LCD_PIN_05, GETBIT(command, 1));
	DIO_voidSetPin(LCD_PIN_04, GETBIT(command, 0));
	LCD_voidEnable();
}

/*
 * Moving cursor Function
 */
void LCD_voidGoToXY(u8 line, u8 raw) {
	if (line == 0) {
		LCD_voidWriteCommand(0b10000000 | (raw));
	} else if (line == 1) {
		LCD_voidWriteCommand(0b11000000 | (raw));
	}
}


#elif (LCD_mode == _8_pins)



#endif
