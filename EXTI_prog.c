/*
 * EXTI_prog.c
 *
 *  Created on: May 24, 2023
 *      Author: Abdelaziz
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void EXTI_voidInitialization(void) {
	/*
	 * initialization INT 0 Configurations
	 */
#if (EXTI_INT_0_MODE==EXTI_LowLevel_Mode)
	CLRBIT(MCUCR,EXTI_ISC00_BIT);
	CLRBIT(MCUCR,EXTI_ISC01_BIT);
#elif (EXTI_INT_0_MODE==EXTI_ChangeLogic_Mode)
	SETBIT(MCUCR,EXTI_ISC00_BIT);
	CLRBIT(MCUCR,EXTI_ISC01_BIT);
#elif (EXTI_INT_0_MODE==EXTI_Falling_Mode)
	CLRBIT(MCUCR,EXTI_ISC00_BIT);
	SETBIT(MCUCR,EXTI_ISC01_BIT);
#elif (EXTI_INT_0_MODE==EXTI_Rising_Mode)
	SETBIT(MCUCR,EXTI_ISC00_BIT);
	SETBIT(MCUCR,EXTI_ISC01_BIT);
#endif
/*
 * initialization INT 0 statue Enable or disable
 */
#if (EXTI_InitState_INT0==EXTI_InitState_Enable)
	EXTI_voidEnable(EXTI_INT0);
#elif (EXTI_InitState_INT0==EXTI_InitState_Disable)
	EXTI_voidDisable(EXTI_INT0);
#endif
/*
 * initialization INT 1 Configurations
 */
#if (EXTI_INT_1_MODE==EXTI_LowLevel_Mode)
	CLRBIT(MCUCR,EXTI_ISC10_BIT);
	CLRBIT(MCUCR,EXTI_ISC11_BIT);
#elif (EXTI_INT_1_MODE==EXTI_ChangeLogic_Mode)
	SETBIT(MCUCR,EXTI_ISC10_BIT);
	CLRBIT(MCUCR,EXTI_ISC11_BIT);
#elif (EXTI_INT_1_MODE==EXTI_Falling_Mode)
	CLRBIT(MCUCR,EXTI_ISC10_BIT);
	SETBIT(MCUCR,EXTI_ISC11_BIT);
#elif (EXTI_INT_1_MODE==EXTI_Rising_Mode)
	SETBIT(MCUCR,EXTI_ISC10_BIT);
	SETBIT(MCUCR,EXTI_ISC11_BIT);
#endif
	/*
	 * initialization INT 1 statue Enable or disable
	 */
	#if (EXTI_InitState_INT1==EXTI_InitState_Enable)
		EXTI_voidEnable(EXTI_INT1);
	#elif (EXTI_InitState_INT1==EXTI_InitState_Disable)
		EXTI_voidDisable(EXTI_INT1);
	#endif
/*
 * initialization INT 2 Configurations
 */

#if (EXTI_INT_2_MODE==EXTI_Falling_Mode)
	CLRBIT(MCUCSR,EXTI_ISC2_BIT);

#elif (EXTI_INT_2_MODE==EXTI_Rising_Mode)
	SETBIT(MCUCSR,EXTI_ISC2_BIT);

#endif
	/*
	 * initialization INT 2 statue Enable or disable
	 */
	#if (EXTI_InitState_INT2==EXTI_InitState_Enable)
		EXTI_voidEnable(EXTI_INT2);
	#elif (EXTI_InitState_INT2==EXTI_InitState_Disable)
		EXTI_voidDisable(EXTI_INT2);
	#endif

		/*
		 * Clear Flag Interrupt by set Flag =1 ;
		 */
SETBIT(GIFR,EXTI_INTF0_BIT);
SETBIT(GIFR,EXTI_INTF1_BIT);
SETBIT(GIFR,EXTI_INTF2_BIT);
}
/*
 * Enable INT Funtion
 */
void EXTI_voidEnable(u8 INT_Number) {

	if (INT_Number == EXTI_INT0) {
		SETBIT(GICR, EXTI_INT0_BIT);
	} else if (INT_Number == EXTI_INT1) {
		SETBIT(GICR, EXTI_INT1_BIT);
	} else if (INT_Number == EXTI_INT2) {
		SETBIT(GICR, EXTI_INT2_BIT);
	}
}
/*
 * Disable INT FUnction
 */
void EXTI_voidDisable(u8 INT_Number) {
	if (INT_Number == EXTI_INT0) {
		CLRBIT(GICR, EXTI_INT0_BIT);
	} else if (INT_Number == EXTI_INT1) {
		CLRBIT(GICR, EXTI_INT1_BIT);
	} else if (INT_Number == EXTI_INT2) {
		CLRBIT(GICR, EXTI_INT2_BIT);
	}

}
/*
 * Declare pointer to function which will call INT
 */
static void (*EXTI_voidSetCallBackINT0)(void);
static void (*EXTI_voidSetCallBackINT1)(void);
static void (*EXTI_voidSetCallBackINT2)(void);
/*
 * Call back Function
 */
void EXTI_voidCallBack(u8 INT_Number,void (*callback)(void))
{
if (INT_Number==EXTI_INT0)
{
	EXTI_voidSetCallBackINT0=callback;
}
else if (INT_Number==EXTI_INT1)
{
	EXTI_voidSetCallBackINT1=callback;
}
else if (INT_Number==EXTI_INT2)
{
	EXTI_voidSetCallBackINT2=callback;
}

}

/*
 * Interrupt  Function
 * Note: attribute to make sure the compiler will not remove the function as it is not used until interrupt occurs
 * From vector Table INT0 >> vector_1 because it equals Vector No. -1 (which in vector table)
 * 					 INT1 >> vector_2
 * 					 INT2 >> vector_3
 */
void __vector_1 (void) __attribute__((signal,used));
void __vector_1 (void)
{
	EXTI_voidSetCallBackINT0();
}
void __vector_2 (void) __attribute__((signal,used));
void __vector_2 (void)
{
	EXTI_voidSetCallBackINT1();
}
void __vector_3 (void) __attribute__((signal,used));
void __vector_3 (void)
{
	EXTI_voidSetCallBackINT2();
}
