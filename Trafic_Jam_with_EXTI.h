/*
 * Trafic_Jam_with_EXTI.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Abdelaziz
 */

#ifndef TRAFIC_JAM_WITH_EXTI_H_
#define TRAFIC_JAM_WITH_EXTI_H_

#define Trafic_Green_LED	LED_0
#define Trafic_Yellow_LED	LED_1
#define Trafic_Red_LED		LED_2

#define Trafic_Green_Time	9
#define Trafic_Yellow_Time	5
#define Trafic_Red_Time		9


void Trafic_voidLedOn(u8 Led_Color);

#endif /* TRAFIC_JAM_WITH_EXTI_H_ */
