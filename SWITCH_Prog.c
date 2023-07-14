/*
 * SWITCH_Prog.c
 *
 *  Created on: May 19, 2023
 *      Author: Abdelaziz
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "SWITCH_register.h"
#include "SWITCH_Priv.h"
#include "SWITCH_Config.h"
#include "SWITCH_Interface.h"

void SWITCH_voidInit(void)
{

}
u8 SWITCH_u8IsPressed(u8 switch_no)
{u8 value;
	if(switch_no==SWITCH_0_PIN )
	{
		#if (SWITCH_0_Mode==Pull_up)
		{
			if(DIO_u8GetPin(SWITCH_0_PIN)==High)
			{
				value=High;
			}
			else
			{
				value=Low;
			}
		}
		#elif (SWITCH_0_Mode==Pull_down)
		{
			if(DIO_u8GetPin(SWITCH_0_PIN)==High)
						{
							value=Low;
						}
			else
						{
							value=High;
						}

		}
		#endif
	}
else if(switch_no==SWITCH_1_PIN )
		{
			#if (SWITCH_1_Mode==Pull_up)
			{
				if(DIO_u8GetPin(SWITCH_1_PIN)==High)
				{
					value=High;
				}
				else
				{
					value=Low;
				}
			}
			#elif (SWITCH_1_Mode==Pull_down)
			{
				if(DIO_u8GetPin(SWITCH_1_PIN)==High)
							{
								value=Low;
							}
				else
							{
								value=High;
							}

			}
			#endif
		}
else if(switch_no==SWITCH_2_PIN )
		{
			#if (SWITCH_2_Mode==Pull_up)
			{
				if(DIO_u8GetPin(SWITCH_2_PIN)==High)
				{
					value=High;
				}
				else
				{
					value=Low;
				}
			}
			#elif (SWITCH_2_Mode==Pull_down)
			{
				if(DIO_u8GetPin(SWITCH_2_PIN)==High)
							{
								value=Low;
							}
				else
							{
								value=High;
							}

			}
			#endif
		}
	return value;

}
