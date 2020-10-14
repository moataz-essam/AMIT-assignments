/*
 * TIMER2_types.h
 *
 * Created: 10/5/2020 10:05:57 PM
 *  Author: Moataz
 */ 


#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_

typedef enum
{
	CS20,
	CS21,
	CS22,
	WGM21,
	COM20,
	COM21,
	WGM20,
	FOC2
}TIMER2_TCCR0_BITS;

typedef enum
{
	TCR2UB,
	OCR2UB,
	TCN2UB,
	AS2
}TIMER2_ASSR_BITS;

typedef enum
{
	TOIE2 = 6,
	OCIE2
}TIMER2_TIMSK_BITS;

typedef enum
{
	TOV2 = 6,
	OCF2
}TIMER2_TIFR_BITS;

#endif /* TIMER2_TYPES_H_ */