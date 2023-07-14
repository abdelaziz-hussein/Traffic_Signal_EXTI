/*
 * _7Segment_prog.c
 *
 *  Created on: May 22, 2023
 *      Author: Abdelaziz
 */

#include "STD_TYPES.h"
#include "BIT_MaTH.h"
#include "DIO_interface.h"
#include "_7Segment_Register.h"
#include "_7Segment_Priv.h"
#include "_7Segment_config.h"
#include "_7Segment_interface.h"
/*
 * initialization function 7 Segment
 */
void _7segment_voidInit(void) {

}
/*
 * Set number on chosen 7segment
 * D,C,B,A , 7segment number
 * 0,0,0,0 >> 0
 * 0,0,0,1 >> 1
 * 0,0,1,0 >> 2
 * 0,0,1,1 >> 3
 * 0,1,0,0 >> 4
 * 0,1,0,1 >> 5
 * 0,1,1,0 >> 6
 * 0,1,1,1 >> 7
 * 1,0,0,0 >> 8
 * 1,0,0,1 >> 9
 */
void _7segment_voidSetNumber(u8 seg_no, u8 number) {
 number+=48;  // to convert Number to its ASCII Code
	if (seg_no == _7Segment_1) {
		DIO_voidSetPin(_7Segment_Pin_Enable_1, High);

	} else if (seg_no == _7Segment_2) {

		DIO_voidSetPin(_7Segment_Pin_Enable_2, High);
	}

#if (_7segment_Mode==Common_anode)

	switch (number) {
	case '0':
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '1':
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '2':
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '3':
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '4':
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '5':
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '6':
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '7':
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '8':
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '9':
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	default:
		break;

	}
#elif (_7segment_Mode==Common_cathod)


	switch (number)
	{
	case '0' :
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '1' :
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '2' :
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '3' :
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '4' :
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '5' :
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '6' :
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '7' :
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, Low);
		DIO_voidSetPin(_7Segment_Pin_C, Low);
		DIO_voidSetPin(_7Segment_Pin_D, High);
		break;
	case '8' :
		DIO_voidSetPin(_7Segment_Pin_A, High);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	case '9' :
		DIO_voidSetPin(_7Segment_Pin_A, Low);
		DIO_voidSetPin(_7Segment_Pin_B, High);
		DIO_voidSetPin(_7Segment_Pin_C, High);
		DIO_voidSetPin(_7Segment_Pin_D, Low);
		break;
	default:
		break;


#endif
}
/*
 * Disable 7 segment Function
 */
	void _7segment_voidDisAbleSegment (u8 seg_no)
	{
		if (seg_no == _7Segment_1) {
				DIO_voidSetPin(_7Segment_Pin_Enable_1, Low);

			} else if (seg_no == _7Segment_2) {

				DIO_voidSetPin(_7Segment_Pin_Enable_2, Low);
			}
	}


/*
 * Enable 7 Segment Dot
 */
void _7segment_voidSetDot(u8 seg_no, u8 value) {
	if (seg_no == _7Segment_1) {
		DIO_voidSetPin(_7Segment_Pin_Enable_1, High);

	} else if (seg_no == _7Segment_2) {

		DIO_voidSetPin(_7Segment_Pin_Enable_2, High);
	}
	if (value == High) {
		DIO_voidSetPin(_7Segment_Pin_PD, High);
	} else if (value == Low) {
		DIO_voidSetPin(_7Segment_Pin_PD, Low);
	}
}


