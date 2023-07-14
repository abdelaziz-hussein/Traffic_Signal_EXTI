/*
 * EXTI_interface.h
 *
 *  Created on: May 24, 2023
 *      Author: Abdelaziz
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidInitialization (void);
void EXTI_voidEnable(u8 INT_Number);
void EXTI_voidDisable(u8 INT_Number);

void EXTI_voidCallBack(u8 INT_Number,void (*callback)(void));

#define EXTI_INT0	0
#define EXTI_INT1	1
#define EXTI_INT2	2

/*
 * Configuration INT_PINS
 */
#define EXTI_PIN_INT0	DIO_PIN_26
#define EXTI_PIN_INT1	DIO_PIN_27
#define EXTI_PIN_INT2	DIO_PIN_10

#endif /* EXTI_INTERFACE_H_ */
