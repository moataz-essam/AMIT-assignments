/*
 * TIMER2.c
 *
 * Created: 10/5/2020 10:04:46 PM
 *  Author: Moataz
 */ 

#include "TIMER2.h"

void TIMER2_init(void)
{
	//set direction to output for OC2 pin
	SET_BIT(OC2_DIR,OC2_PIN);
	//clear TCCR2
	TCCR2 = 0x00;
	//set timer mode
	TCCR2 &= TIMER2_MODE_CLR;
	TCCR2 |= TIMER2_MODE_SELECTED;
	
	//set compare output mode
	TCCR2 &= CMP_MODE_CLR;
	TCCR2 |= CMP_MODE_SELECTED;
	
	//enable interrupt
	TIMER2_INT_EN();
	
	//set pre-scaler
	TCCR2 &= TIMER2_PRESCALER_CLR;
	TCCR2 |= TIMER2_PRESCALER_SELECTED;
	
	//add preset value to count from it to the max
	TIMER2_PRELOAD_COUNTER(TIMER2_PRELOADED_COUNTER);
	//set compare point
	TIMER2_OutputCompare(TIMER2_PointOfCompare);
}

void TIMER2_clr_counter(void)
{
	TCNT2 = 0x00;
}

void TIMER2_PRELOAD_COUNTER(uint8 preload_count)
{
	TCNT2 = preload_count;
}

void TIMER2_OutputCompare(uint8 PointOfCompare)
{
	OCR2 = PointOfCompare;
}

void TIMER2_INT_EN(void)
{
	GLOBAL_INT_EN;
	#if (TIMER2_MODE_SELECTED == TIMER2_MODE_CTC)
	SET_BIT(TIMSK,OCIE2);
	#else
	SET_BIT(TIMSK,TOIE2);
	#endif
}

void TIMER2_INT_DIS(void)
{
	#if (TIMER2_MODE_SELECTED == TIMER2_MODE_CTC)
	CLR_BIT(TIMSK,OCIE2);
	#else
	CLR_BIT(TIMSK,TOIE2);
	#endif
}