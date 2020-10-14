/*
 * TIMER2_HW.h
 *
 * Created: 10/5/2020 10:05:30 PM
 *  Author: Moataz
 */ 


#ifndef TIMER2_HW_H_
#define TIMER2_HW_H_

#include "../../utils/STD_types.h"

#define OC2_DIR		*((volatile uint8*)0x31)
#define OC2_PIN		7

#define TCCR2		*((volatile uint8*)0x45)
#define TCNT2		*((volatile uint8*)0x44)
#define OCR2		*((volatile uint8*)0x43)
#define ASSR		*((volatile uint8*)0x42)
#define TIMSK		*((volatile uint8*)0x59)
#define TIFR		*((volatile uint8*)0x58)
#define SFIOR		*((volatile uint8*)0x50)

#endif /* TIMER2_HW_H_ */