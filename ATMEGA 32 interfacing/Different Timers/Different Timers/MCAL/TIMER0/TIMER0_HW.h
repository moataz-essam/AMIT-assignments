/*
 * TIMER0_HW.h
 *
 * Created: 9/23/2020 12:17:55 AM
 *  Author: Moataz
 */ 


#ifndef TIMER0_HW_H_
#define TIMER0_HW_H_

#include "../../utils/STD_types.h"

#define OC0_DIR		*((volatile uint8*)0x37)
#define OC0_PIN		3

#define TCCR0		*((volatile uint8*)0x53)
#define TCNT0		*((volatile uint8*)0x52)
#define OCR0		*((volatile uint8*)0x5C)
#define TIMSK		*((volatile uint8*)0x59)
#define TIFR		*((volatile uint8*)0x58)
#define SFIOR		*((volatile uint8*)0x50)

#endif /* TIMER0_HW_H_ */