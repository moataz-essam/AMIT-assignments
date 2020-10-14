/*
 * TIMER0_types.h
 *
 * Created: 9/23/2020 12:39:27 AM
 *  Author: Moataz
 */ 


#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

typedef enum
{
	CS00,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}TIMER0_TCCR0_BITS;

typedef enum
{
	TOIE0,
	OCIE0
}TIMER0_TIMSK_BITS;

typedef enum
{
	TOV0,
	OCF0
}TIMER0_TIFR_BITS;

#endif /* TIMER0_TYPES_H_ */