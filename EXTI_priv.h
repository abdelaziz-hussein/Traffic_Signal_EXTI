/*
 * EXTI_priv.h
 *
 *  Created on: May 24, 2023
 *      Author: Abdelaziz
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_
/*
 * EXTI Modes
 * 0  EXTI_LowLevel_Mode 	>>The low level of INTx generates an interrupt request.
 * 1  EXTI_ChangeLogic_Mode >>Any logical change on INTx generates an interrupt request.
 * 2  EXTI_Falling_Mode  	>>The falling edge of INT0 generates an interrupt request.
 * 3  EXTI_Rising_Mode		>>The rising edge of INT0 generates an interrupt request.
 */
#define EXTI_LowLevel_Mode		0
#define EXTI_ChangeLogic_Mode	1
#define EXTI_Falling_Mode 		2
#define EXTI_Rising_Mode		3
/*
 * initial state on iinterrupt
 *
 */
#define EXTI_InitState_Enable 1
#define EXTI_InitState_Disable 0
#endif /* EXTI_PRIV_H_ */
