/*
 * LED_Prog.c
 *
 *  Created on: May 19, 2023
 *      Author: Abdelaziz
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "LED_Register.h"
#include "LED_Priv.h"
#include "LED_Config.h"
#include "LED_Interface.h"

/*
 * initialization function by set all LEDs off ,
 * constrains should be connected series on MC "ex. LED0 on PIN 29 , LED_1 on 30 , so on
 */
void Led_voidInit (void)
{	for (u8 i;i<Led_Qty;i++)
	{
		Led_voidOFF(LED_0+i);
	}
}
/*
 * Function to Set LED ON
 */
void Led_voidOn (u8 Led_num)
{ if (Led_num==LED_0)
	{
		#if (LED_0_Config==Forward)
		{
			DIO_voidSetPin(LED_0, High);
		}
		#elif (LED_0_Config==Reverse)
		{
			DIO_voidSetPin(LED_0, Low);
		}
		#endif
	}
 else if (Led_num==LED_1)
	{
		#if (LED_1_Config==Forward)
		{
			DIO_voidSetPin(LED_1, High);
		}
		#elif (LED_1_Config==Reverse)
		{
			DIO_voidSetPin(LED_1, Low);
		}
		#endif
	}
 else if (Led_num==LED_2)
 	{
 		#if (LED_2_Config==Forward)
 		{
 			DIO_voidSetPin(LED_2, High);
 		}
 		#elif (LED_2_Config==Reverse)
 		{
 			DIO_voidSetPin(LED_2, Low);
 		}
		#endif
 	}
}

/*
 * Function to set LED off
 */
void Led_voidOFF(u8 Led_num)
{
	if (Led_num==LED_0)
		{
			#if (LED_0_Config==Forward)
			{
				DIO_voidSetPin(LED_0, Low);
			}
			#elif (LED_0_Config==Reverse)
			{
				DIO_voidSetPin(LED_0, High);
			}
			#endif
		}
	 else if (Led_num==LED_1)
		{
			#if (LED_1_Config==Forward)
			{
				DIO_voidSetPin(LED_1, Low);
			}
			#elif (LED_1_Config==Reverse)
			{
				DIO_voidSetPin(LED_1, High);
			}
			#endif
		}
	 else if (Led_num==LED_2)
	 	{
	 		#if (LED_2_Config==Forward)
	 		{
	 			DIO_voidSetPin(LED_2, Low);
	 		}
	 		#elif (LED_2_Config==Reverse)
	 		{
	 			DIO_voidSetPin(LED_2, High);
	 		}
			#endif
	 	}
}
/*
 * Function to Toggle LED
 */
void Led_voidToggle(u8 Led_num)
{
	if(Led_num==LED_0)
	{
		DIO_voidTogglePin(LED_0);
	}
	else if (Led_num==LED_1)
	{
		DIO_voidTogglePin(LED_1);
	}
	else if (Led_num==LED_2)
	{
			DIO_voidTogglePin(LED_2);
	}

}


