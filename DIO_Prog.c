/*
 * DIO_Prog.c
 *
 *  Created on: May 17, 2023
 *      Author: Abdelaziz
 */

#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_Private.h"
#include  "DIO_config.h"
#include "DIO_interface.h"
/*
 * initialize DIO Driver By SET Direction Of every Port "DDRA,DDRB,DDRC,DDRD"
 */
void DIO_voidInit(void)
{DDRA=CONCBIT(DIO_Pin_7_DIR,DIO_Pin_6_DIR,DIO_Pin_5_DIR,DIO_Pin_4_DIR,DIO_Pin_3_DIR,DIO_Pin_2_DIR,DIO_Pin_1_DIR,DIO_Pin_0_DIR);
 DDRB=CONCBIT(DIO_Pin_15_DIR,DIO_Pin_14_DIR,DIO_Pin_13_DIR,DIO_Pin_12_DIR,DIO_Pin_11_DIR,DIO_Pin_10_DIR,DIO_Pin_9_DIR,DIO_Pin_8_DIR);
 DDRC=CONCBIT(DIO_Pin_23_DIR,DIO_Pin_22_DIR,DIO_Pin_21_DIR,DIO_Pin_20_DIR,DIO_Pin_19_DIR,DIO_Pin_18_DIR,DIO_Pin_17_DIR,DIO_Pin_16_DIR);
 DDRD=CONCBIT(DIO_Pin_31_DIR,DIO_Pin_30_DIR,DIO_Pin_29_DIR,DIO_Pin_28_DIR,DIO_Pin_27_DIR,DIO_Pin_26_DIR,DIO_Pin_25_DIR,DIO_Pin_24_DIR);
}
/*
 * function to Set PIN , HIGH "1" or LOW "0"
 */
void DIO_voidSetPin(u8 pin_num,u8 value)
{
	if (pin_num>=DIO_PIN_0&&pin_num<=DIO_PIN_7)
	{ 	if (value==High)
		{SETBIT(PORTA,pin_num);}

		else
		{CLRBIT(PORTA,pin_num);}

	}
	else if (pin_num>=DIO_PIN_8&&pin_num<=DIO_PIN_15)
		{ 	if (value==High)
			{SETBIT(PORTB,(pin_num-8));}

			else
			{CLRBIT(PORTB,(pin_num-8));}

		}
	else if (pin_num>=DIO_PIN_16&&pin_num<=DIO_PIN_23)
		{ 	if (value==High)
			{SETBIT(PORTC,(pin_num-16));}

			else
			{CLRBIT(PORTC,(pin_num-16));}

		}
	else if (pin_num>=DIO_PIN_24&&pin_num<=DIO_PIN_31)
		{ 	if (value==High)
			{SETBIT(PORTD,(pin_num-24));}

			else
			{CLRBIT(PORTD,(pin_num-24));}

		}

}
/*
 * Function to Read and return Value From PIN ,High"1" , LOW "0"
 */
u8 DIO_u8GetPin (u8 pin_num)
{u8 value;
	if (pin_num>=DIO_PIN_0&&pin_num<=DIO_PIN_7)
	{
		value= GETBIT(PINA,pin_num);
	}
	else if (pin_num>=DIO_PIN_8&&pin_num<=DIO_PIN_15)
		{
		value= GETBIT(PINB,(pin_num-8));
		}
	else if (pin_num>=DIO_PIN_16&&pin_num<=DIO_PIN_23)
		{
		value= GETBIT(PINC,(pin_num-16));
		}
	else if (pin_num>=DIO_PIN_24&&pin_num<=DIO_PIN_31)
		{
		value= GETBIT(PIND,(pin_num-24));
		}
	return value;

}
/*
 * function to toggle PIN
 */
void DIO_voidTogglePin(u8 pin_num)
{
	if (pin_num>=DIO_PIN_0&&pin_num<=DIO_PIN_7)
		{
			TOGGLEBIT(PORTA,pin_num);
		}
		else if (pin_num>=DIO_PIN_8&&pin_num<=DIO_PIN_15)
			{
			TOGGLEBIT(PORTB,(pin_num-8));
			}
		else if (pin_num>=DIO_PIN_16&&pin_num<=DIO_PIN_23)
			{
			TOGGLEBIT(PORTC,(pin_num-16));
			}
		else if (pin_num>=DIO_PIN_24&&pin_num<=DIO_PIN_31)
			{
			TOGGLEBIT(PORTD,(pin_num-24));
			}
}
