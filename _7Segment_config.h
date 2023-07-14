/*
 * _7Segment_config.h
 *
 *  Created on: May 22, 2023
 *      Author: Abdelaziz
 */

#ifndef _7SEGMENT_CONFIG_H_
#define _7SEGMENT_CONFIG_H_
/*
 * Configuration 7Segment Pins "4 pins to decoder ,deliver 0-9 "
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
#define _7Segment_Pin_A 	DIO_PIN_20
#define _7Segment_Pin_B 	DIO_PIN_21
#define _7Segment_Pin_C 	DIO_PIN_22
#define _7Segment_Pin_D 	DIO_PIN_23
/*
 * configuration 7Segment Dot
 */
#define _7Segment_Pin_PD 	DIO_PIN_8
/*
 * configuration Enable Pin of each segment
 */
#define _7Segment_Pin_Enable_1 	DIO_PIN_18
#define _7Segment_Pin_Enable_2 	DIO_PIN_19
/*
 * Define 7 segment Mode "comman_anode or comman_cathod"
 */
#define _7segment_Mode	Common_anode

#endif /* 7SEGMENT_CONFIG_H_ */
