/*
 * EXTI.c
 *
 * Created: 9/15/2020 10:29:00 PM
 *  Author: Moataz
 */ 

#include "EXTI.h"

void EXTI_init(void)
{
	//initialization of external interrupt 0
	#if (EXTI_INT0_EN == ENABLE)
		CLR_BIT(DDR_D,PIN2);
		EXTI_SetEdge(INT0,EXTI_INT0_EDGE);
		EXTI_EnINT(INT0);
	#endif
	//initialization of external interrupt 1
	#if (EXTI_INT1_EN == ENABLE)
		CLR_BIT(DDR_D,PIN3);
		EXTI_SetEdge(INT0,EXTI_INT1_EDGE);
		EXTI_EnINT(INT1);
	#endif
	//initialization of external interrupt 2
	#if (EXTI_INT2_EN == ENABLE)
		CLR_BIT(DDR_B,PIN2);
		EXTI_SetEdge(INT0,EXTI_INT2_EDGE);
		EXTI_EnINT(INT2);
	#endif
}

void EXTI_SetEdge(EXTI_IntType IntType, EXTI_EdgeType edgetype)
{
	switch(IntType)
	{
		case INT0:
			if (edgetype == LowCycle)
			{
				MCUCR |= LowCycle;
			}
			else if (edgetype == AnyChange )
			{
				MCUCR |= AnyChange;
			}
			else if(edgetype == FallingEdge)
			{
				MCUCR |= FallingEdge;
			}
			else if(edgetype == RisingEdge)
			{
				MCUCR |= RisingEdge;
			}
			break;
		case INT1:
			if (edgetype == LowCycle)
			{
				MCUCR |= (LowCycle<<2);
			}
			else if (edgetype == AnyChange)
			{
				MCUCR |= (AnyChange<<2);
			}
			else if(edgetype == FallingEdge)
			{
				MCUCR |= (FallingEdge<<2);
			}
			else if(edgetype == RisingEdge)
			{
				MCUCR |= (RisingEdge<<2);
			}
			break;
		case INT2:
			if(edgetype == FallingEdge)
			{
				CLR_BIT(MCUCSR,BIT6);
			}
			else if(edgetype == RisingEdge)
			{
				SET_BIT(MCUCSR,BIT6);
			}
			break;
	}
}

void EXTI_EnINT(EXTI_IntType IntType)
{
	switch(IntType)
	{
		case INT0:
			SET_BIT(GICR,BIT6);
			break;
		case INT1:
			SET_BIT(GICR,BIT7);
			break;
		case INT2:
			SET_BIT(GICR,BIT5);
			break;
	}
}

void EXTI_DisINT(EXTI_IntType IntType)
{
	switch(IntType)
	{
		case INT0:
			CLR_BIT(GICR,BIT6);
			break;
		case INT1:
			CLR_BIT(GICR,BIT7);
			break;
		case INT2:
			CLR_BIT(GICR,BIT5);
			break;
	}
}