/*
 * Trafic_Jam_With_EXTI.c
 *
 *  Created on: Jul 8, 2023
 *      Author: Abdelaziz
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_Interface.h"
#include "Trafic_Jam_with_EXTI.h"

void Trafic_voidLedOn(u8 Led_Color) {
	if (Led_Color == Trafic_Green_LED) {
		Led_voidOn(Trafic_Green_LED);
		Led_voidOFF(Trafic_Yellow_LED);
		Led_voidOFF(Trafic_Red_LED);



	} else if (Led_Color == Trafic_Yellow_LED) {
		Led_voidOFF(Trafic_Green_LED);
		Led_voidOn(Trafic_Yellow_LED);
		Led_voidOFF(Trafic_Red_LED);



	}
	else if (Led_Color == Trafic_Red_LED) {
			Led_voidOFF(Trafic_Green_LED);
			Led_voidOFF(Trafic_Yellow_LED);
			Led_voidOn(Trafic_Red_LED);





		}
}
