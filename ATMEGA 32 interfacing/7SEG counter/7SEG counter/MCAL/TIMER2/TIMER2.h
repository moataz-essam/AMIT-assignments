/*
 * TIMER2.h
 *
 * Created: 10/5/2020 10:05:08 PM
 *  Author: Moataz
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "../../utils/BitMath.h"
#include "../../utils/interrupts.h"
#include "TIMER2_HW.h"
#include "TIMER2_types.h"
#include "../../config/TIMER2_cfg.h"

////////////*****clock prescaling*****////////////////////////////
#define TIMER2_PRESCALER_CLR			0b11111000
#define TIMER2_PRESCALER_1				0b00000001
#define TIMER2_PRESCALER_8				0b00000010
#define TIMER2_PRESCALER_32				0b00000011
#define TIMER2_PRESCALER_64				0b00000100
#define TIMER2_PRESCALER_128			0b00000101
#define TIMER2_PRESCALER_256			0b00000110
#define TIMER2_PRESCALER_1024			0b00000111

////////////*****Timer 2  modes*****////////////////////////////
#define TIMER2_MODE_CLR					0b10110111
#define TIMER2_MODE_NORMAL				0b00000000
#define TIMER2_MODE_PHASE_CORRECT		0b01000000
#define TIMER2_MODE_CTC					0b00001000
#define TIMER2_MODE_FAST_PWM			0b01001000

////////////*****compare modes*****////////////////////////////
#define CMP_MODE_CLR					0b11001111
//compare modes if mode selected is fast PWM
#define CMP_MODE_NON_INVERT				0b00100000
#define CMP_MODE_INVERT					0b00110000
//compare modes if the selected mode is phase correct PWM
#define CMP_MODE_ClrUp_SetDown			0b00100000
#define CMP_MODE_SetUp_ClrDown			0b00110000
//compare mode if mode selected is normal PWM or CTC
#define CMP_MODE_TOGGLE_OC2				0b00010000
#define CMP_MODE_CLR_OC2				0b00100000
#define CMP_MODE_SET_OC2				0b00110000
////////////**********************////////////////////////////

void TIMER2_init(void);
void TIMER2_clr_counter(void);
void TIMER2_PRELOAD_COUNTER(uint8 preload_count);
void TIMER2_OutputCompare(uint8 PointOfCompare);
void TIMER2_INT_EN(void);
void TIMER2_INT_DIS(void);
//uint8 TIMER2_readCounterSteps(void);

#endif /* TIMER2_H_ */