/*
 * GIE_PROC.c
 *
 *  Created on: ??�/??�/????
 *      Author: abdelaziz
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GIE_SEG.h"
#include "GIE_PRIV.h"
#include "GIE_CONFIG.h"
#include "GIE_INT.h"

void GIE_voidEnable(void)
{
	SETBIT(SREG,GIE_ENABLE_BIT_INDEX);
}
void GIE_voidDisable(void)
{
	CLRBIT(SREG,GIE_ENABLE_BIT_INDEX);
}
