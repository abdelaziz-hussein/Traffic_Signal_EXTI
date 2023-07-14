/*
 * LCD_interface.h
 *
 *  Created on: May 20, 2023
 *      Author: Abdelaziz
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/*
 * initialization LCD Function
 */
void LCD_voidInit(void);

/*
 * most used Commands
 */
void LCD_voidEnable(void);
void LCD_voidClearScreen(void);
void LCD_voidHome(void);
void LCD_voidShiftLeft(void);
void LCD_voidShiftRight(void);
/*
 * Write Data Functions
 */
void LCD_voidWriteChar(u8 character);
void LCD_voidWriteString(u8 *string);
void LCD_voidWriteVariable(u16 variable);
/*
 * write ommand function
 */
void LCD_voidWriteCommand(u8 command);

/*
 * Moving cursor Function
 */
void LCD_voidGoToXY(u8 line,u8 raw);


#endif /* LCD_INTERFACE_H_ */
