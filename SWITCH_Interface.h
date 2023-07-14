/*
 * SWITCH_Interface.h
 *
 *  Created on: May 19, 2023
 *      Author: Abdelaziz
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/*
 * define Switch pins connections with MC
 */
#define SWITCH_0_PIN 	DIO_PIN_24
#define SWITCH_1_PIN	DIO_PIN_25
#define SWITCH_2_PIN	DIO_PIN_26

/*
 * HAL Switch Functions
 */

void SWITCH_voidInit(void);
u8 SWITCH_u8IsPressed(u8 switch_no);

#endif /* SWITCH_INTERFACE_H_ */
