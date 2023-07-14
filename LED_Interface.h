/*
 * LED_Interface.h
 *
 *  Created on: May 19, 2023
 *      Author: Abdelaziz
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
/*
 * HAL LED Functions
 */
void Led_voidInit (void);
void Led_voidOn (u8 Led_num);
void Led_voidOFF(u8 Led_num);
void Led_voidToggle(u8 Led_num);
/*
 * define LEDs PIN ON KIT
 */

#define LED_0	DIO_PIN_29
#define LED_1	DIO_PIN_30
#define LED_2	DIO_PIN_31

#endif /* LED_INTERFACE_H_ */
