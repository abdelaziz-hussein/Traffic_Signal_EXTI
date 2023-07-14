/*
 * LCD_Config.h
 *
 *  Created on: May 20, 2023
 *      Author: Abdelaziz
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*
 * configuration connection LCD PIns on MC
 */
#define LCD_PIN_E	DIO_PIN_11
#define LCD_PIN_RW	DIO_PIN_10
#define LCD_PIN_RS	DIO_PIN_9

#define LCD_PIN_07 	DIO_PIN_7
#define LCD_PIN_06 	DIO_PIN_6
#define LCD_PIN_05 	DIO_PIN_5
#define LCD_PIN_04 	DIO_PIN_4
/*
 * Configuration  LCD Modes
 */
#define LCD_mode	_4_pins
#define LCD_Display	Display_on
#define LCD_cursor	Cursor_on
#define LCD_Blink	Blink_off
#define LCD_NoLines	Two_line
#define LCD_Font	_5in7Dot
	/*
	 *  LCD_Display Mode ON 1 , off 0
	 */
#define	Display_on	1
#define	Display_off	0
/*
 * LCD_cursor Mode ON 1 or off 0
 */
#define Cursor_on	1
#define Cursor_off	0
/*
 * LCD_Blink Mode ON 1 or off 0
 */
#define Blink_on	1
#define Blink_off	0
/*
 * LCD number of lines "one line "0" or Two lines "1" "
 */
#define Two_line	1
#define One_line	0
/*
 * LCD Font Mode 5*7 Dot "0" or 5*10 dot "1"
 */
#define _5in7Dot	0
#define _5in10Dot	1
/*
 * 1st Line start from 0x00 to 0x27
 * 2nd Line Start From 0x40 to 0x67
 */
#define LCD_1stLine_Start 0x00
#define LCD_1stLine_End   (0b00100111) // add 1 at the end to match DDRAM register
#define LCD_2ndLine_Start 0x40
#define LCD_2ndLine_End   (0b01100111) // add 1 at the end to match DDRAM register

#endif /* LCD_CONFIG_H_ */
