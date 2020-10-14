/*
 * TIMER0.c
 *
 * Created: 9/23/2020 12:39:59 AM
 *  Author: Moataz
 */ 

#include "TIMER0.h"

void TIMER0_init(void)
{
	//set direction to output for OC0 pin
	SET_BIT(OC0_DIR,OC0_PIN);
	//clear TCCR0
	TCCR0 = 0x00;
	//set timer mode
	TCCR0 &= TIMER0_MODE_CLR;
	TCCR0 |= TIMER0_MODE_SELECTED;
	
	//set compare output mode
	TCCR0 &= CMP_MODE_CLR;
	TCCR0 |= CMP_MODE_SELECTED;
	
	//enable interrupt
	TIMER0_INT_EN();
	
	//set pre-scaler
	TCCR0 &= TIMER0_PRESCALER_CLR;
	TCCR0 |= TIMER0_PRESCALER_SELECTED;
	
	//add preset value to count from it to the max
	TIMER0_PRELOAD_COUNTER(TIMER0_PRELOADED_COUNTER);
	//set compare point
	TIMER0_OutputCompare(TIMER0_PointOfCompare);
}

void TIMER0_clr_counter(void)
{
	TCNT0 = 0x00;
}

void TIMER0_PRELOAD_COUNTER(uint8 preload_count)
{
	TCNT0 = preload_count;
}

void TIMER0_OutputCompare(uint8 PointOfCompare)
{
	OCR0 = PointOfCompare;
}

void TIMER0_INT_EN(void)
{
	GLOBAL_INT_EN;
	#if (TIMER0_MODE_SELECTED == TIMER0_MODE_CTC)
		SET_BIT(TIMSK,OCIE0);
	#else
		SET_BIT(TIMSK,TOIE0);
	#endif
}

void TIMER0_INT_DIS(void)
{
	#if (TIMER0_MODE_SELECTED == TIMER0_MODE_CTC)
		CLR_BIT(TIMSK,OCIE0);
	#else
		CLR_BIT(TIMSK,TOIE0);
	#endif
}