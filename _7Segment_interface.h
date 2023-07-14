/*
 * _7Segment_int.h
 *
 *  Created on: May 22, 2023
 *      Author: Abdelaziz
 */

#ifndef _7SEGMENT_INT_H_
#define _7SEGMENT_INT_H_
/*
 * Function of  7 segment HAL Driver
 */
void _7segment_voidInit(void);
void _7segment_voidSetNumber(u8 seg_no, u8 number);
void _7segment_voidDisAbleSegment (u8 seg_no);
void _7segment_voidSetDot(u8 seg_no,u8 value);
/*
 * define 7Segment ID "1 or 2"
 */
#define _7Segment_1	1
#define _7Segment_2	2

#endif /* 7SEGMENT_INT_H_ */
