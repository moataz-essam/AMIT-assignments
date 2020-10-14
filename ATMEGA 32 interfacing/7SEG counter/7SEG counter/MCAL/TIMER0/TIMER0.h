/*
 * TIMER0.h
 *
 * Created: 9/23/2020 12:39:46 AM
 *  Author: Moataz
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../utils/BitMath.h"
#include "../../utils/interrupts.h"
#include "TIMER0_HW.h"
#include "TIMER0_types.h"
#include "../../config/TIMER0_cfg.h"

////////////*****clock prescaling*****////////////////////////////
#define TIMER0_PRESCALER_CLR			0b11111000
#define TIMER0_PRESCALER_1				0b00000001
#define TIMER0_PRESCALER_8				0b00000010
#define TIMER0_PRESCALER_64				0b00000011
#define TIMER0_PRESCALER_256			0b00000100
#define TIMER0_PRESCALER_1024			0b00000101
#define TIMER0_ExtClock_FALLING			0b00000110
#define TIMER0_ExtClock_RISING			0b00000111

////////////*****Timer 0  modes*****////////////////////////////
#define TIMER0_MODE_CLR					0b10110111
#define TIMER0_MODE_NORMAL				0b00000000
#define TIMER0_MODE_PHASE_CORRECT		0b01000000
#define TIMER0_MODE_CTC					0b00001000
#define TIMER0_MODE_FAST_PWM			0b01001000

////////////*****compare modes*****////////////////////////////
#define CMP_MODE_CLR					0b11001111
//compare modes if mode selected is fast PWM
#define CMP_MODE_NON_INVERT				0b00100000
#define CMP_MODE_INVERT					0b00110000
//compare modes if the selected mode is phase correct PWM
#define CMP_MODE_ClrUp_SetDown			0b00100000
#define CMP_MODE_SetUp_ClrDown			0b00110000
//compare mode if mode selected is normal PWM or CTC
#define CMP_MODE_TOGGLE_OC0				0b00100000
#define CMP_MODE_CLR_OC0				0b00110000
#define CMP_MODE_SET_OC0				0b00110000
////////////**********************////////////////////////////

void TIMER0_init(void);
void TIMER0_clr_counter(void);
void TIMER0_PRELOAD_COUNTER(uint8 preload_count);
void TIMER0_OutputCompare(uint8 PointOfCompare);
void TIMER0_INT_EN(void);
void TIMER0_INT_DIS(void);
//uint8 TIMER0_readCounterSteps(void);

#endif /* TIMER0_H_ */