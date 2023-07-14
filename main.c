/*
 * main.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Abdelaziz
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_INT.h"
#include "LCD_interface.h"
#include "LED_Interface.h"
#include "_7Segment_interface.h"
#include "SWITCH_Interface.h"
#include "Trafic_Jam_with_EXTI.h"
#include "avr/delay.h"

void DIO_ISR(void);
int main() {
	DIO_voidInit();
	LCD_voidInit();
	Led_voidInit();
	_7segment_voidInit();
	SWITCH_voidInit();
	EXTI_voidInitialization();
	GIE_voidEnable();
	EXTI_voidCallBack(EXTI_INT0, DIO_ISR);

	while (1) {
		/*
		 * Green Light Cycle
		 */
		LCD_voidClearScreen();
		LCD_voidWriteString("GO Green LED ");
		for (u8 i = 0; i <= Trafic_Green_Time; i++) {
			Trafic_voidLedOn(Trafic_Green_LED);
			_7segment_voidSetNumber(_7Segment_1, i);
			LCD_voidGoToXY(1, 0);
			LCD_voidWriteVariable(i);

			_delay_ms(1000);
		}
		_7segment_voidDisAbleSegment(_7Segment_1);

		/*
		 * Yellow Light Cycle
		 */
		LCD_voidClearScreen();
		LCD_voidWriteString("Stand By Yellow LED");
		for (u8 i = 0; i <= Trafic_Yellow_Time; i++) {
			Trafic_voidLedOn(Trafic_Yellow_LED);
			_7segment_voidSetNumber(_7Segment_1, i);
			LCD_voidGoToXY(1, 0);
			LCD_voidWriteVariable(i);

			_delay_ms(1000);
		}
		_7segment_voidDisAbleSegment(_7Segment_1);

		/*
		 * Red Light Cycle
		 */
		LCD_voidClearScreen();
		LCD_voidWriteString("Stop Red LED");
		for (u8 i = 0; i <= Trafic_Red_Time; i++) {
			Trafic_voidLedOn(Trafic_Red_LED);
			_7segment_voidSetNumber(_7Segment_1, i);
			LCD_voidGoToXY(1, 0);
			LCD_voidWriteVariable(i);

			_delay_ms(1000);
		}
		_7segment_voidDisAbleSegment(_7Segment_1);

	}
}

void DIO_ISR(void) {
	if (SWITCH_u8IsPressed(EXTI_PIN_INT0)) {
		Led_voidOn(Trafic_Green_LED);
		Led_voidOFF(Trafic_Yellow_LED);
		Led_voidOFF(Trafic_Red_LED);

		while (SWITCH_u8IsPressed(EXTI_PIN_INT0));
	}
}

