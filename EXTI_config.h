/*
 * EXTI_config.h
 *
 *  Created on: May 24, 2023
 *      Author: Abdelaziz
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*
 * EXTI Modes INT0 & INT1 :-
 *
 *  EXTI_LowLevel_Mode 	>>The low level of INTx generates an interrupt request.
 *  EXTI_ChangeLogic_Mode >>Any logical change on INTx generates an interrupt request.
 *  EXTI_Falling_Mode  	>>The falling edge of INT0 generates an interrupt request.
 *  EXTI_Rising_Mode		>>The rising edge of INT0 generates an interrupt request.
 *
 *   EXTI INT 2 :-
 *    EXTI_Falling_Mode  	>>The falling edge of INT0 generates an interrupt request.
 *  EXTI_Rising_Mode		>>The rising edge of INT0 generates an interrupt request.
 */
#define EXTI_INT_0_MODE	 EXTI_Rising_Mode
#define EXTI_INT_1_MODE	 EXTI_Rising_Mode
#define EXTI_INT_2_MODE	 EXTI_Rising_Mode
/*
 * initial Statues of INTx (Enable or Disable)
 */
#define EXTI_InitState_INT0	EXTI_InitState_Enable
#define EXTI_InitState_INT1	EXTI_InitState_Enable
#define EXTI_InitState_INT2	EXTI_InitState_Enable
/*
 * Interrupt Sense Control External Interrupt 0
 */
#define EXTI_ISC00_BIT		0
#define EXTI_ISC01_BIT		1
/*
 * Interrupt Sense Control External Interrupt 1
 */
#define EXTI_ISC10_BIT		2
#define EXTI_ISC11_BIT		3
/*
 * Interrupt Sense Control External Interrupt 2
 */
#define EXTI_ISC2_BIT		6

/*
 * EXternal interrupt Enable BITs
 */
#define EXTI_INT0_BIT			6
#define EXTI_INT1_BIT			7
#define EXTI_INT2_BIT			5
/*
 * External interrupt Flags
 */
#define EXTI_INTF0_BIT			6
#define EXTI_INTF1_BIT			7
#define EXTI_INTF2_BIT			5



#endif /* EXTI_CONFIG_H_ */
