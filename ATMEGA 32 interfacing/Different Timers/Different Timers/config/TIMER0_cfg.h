/*
 * TIMER0_cfg.h
 *
 * Created: 9/23/2020 12:40:29 AM
 *  Author: Moataz
 */ 


#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

////////////////////////////////////////////////////////////////////
/*
 * Choose mode from following list:-
 *
 * TIMER0_MODE_NORMAL
 * TIMER0_MODE_PHASE_CORRECT
 * TIMER0_MODE_CTC
 * TIMER0_MODE_FAST_PWM
 * */
#define TIMER0_MODE_SELECTED		TIMER0_MODE_NORMAL
//////////////////////////////////////////////////////////////////////
/*
 * Choose compare mode from following list:-
 *
 * //compare modes if mode selected is fast PWM
 * CMP_MODE_NON_INVERT
 * CMP_MODE_INVERT
 
 //compare modes if the selected mode is phase correct PWM
 * CMP_MODE_ClrUp_SetDown
 * CMP_MODE_SetUp_ClrDown
 
 //compare mode if mode selected is normal mode or CTC
 * CMP_MODE_TOGGLE_OC0
 * CMP_MODE_CLR_OC0
 * CMP_MODE_SET_OC0
 * */
#define CMP_MODE_SELECTED				CMP_MODE_TOGGLE_OC0
//////////////////////////////////////////////////////////////////////////
#define TIMER0_PRELOADED_COUNTER				(6)
//////////////////////////////////////////////////////////////////////////
#define TIMER0_PointOfCompare					(255)
//////////////////////////////////////////////////////////////////////////
/*
 * Choose prescaler clock from following list:-
 *
 * TIMER0_PRESCALER_1
 * TIMER0_PRESCALER_8
 * TIMER0_PRESCALER_64
 * TIMER0_PRESCALER_256
 * TIMER0_PRESCALER_1024
 * TIMER0_ExtClock_FALLING
 * TIMER0_ExtClock_RISING
 * */
#define TIMER0_PRESCALER_SELECTED		TIMER0_PRESCALER_256
////////////////////////////////////////////////////////////////////////////

#endif /* TIMER0_CFG_H_ */