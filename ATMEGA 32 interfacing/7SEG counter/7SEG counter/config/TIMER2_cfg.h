/*
 * TIMER2_cfg.h
 *
 * Created: 10/5/2020 10:07:21 PM
 *  Author: Moataz
 */ 


#ifndef TIMER2_CFG_H_
#define TIMER2_CFG_H_

////////////////////////////////////////////////////////////////////
/*
 * Choose mode from following list:-
 *
 * TIMER2_MODE_NORMAL
 * TIMER2_MODE_PHASE_CORRECT
 * TIMER2_MODE_CTC
 * TIMER2_MODE_FAST_PWM
 * */
#define TIMER2_MODE_SELECTED		TIMER2_MODE_CTC
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
 * CMP_MODE_TOGGLE_OC2
 * CMP_MODE_CLR_OC2
 * CMP_MODE_SET_OC2
 * */
#define CMP_MODE_SELECTED				CMP_MODE_TOGGLE_OC2
//////////////////////////////////////////////////////////////////////////
#define TIMER2_PRELOADED_COUNTER				(0)
//////////////////////////////////////////////////////////////////////////
#define TIMER2_PointOfCompare					(125)
//////////////////////////////////////////////////////////////////////////
/*
 * Choose prescaler clock from following list:-
 *
 * TIMER2_PRESCALER_1
 * TIMER2_PRESCALER_8
 * TIMER2_PRESCALER_32
 * TIMER2_PRESCALER_64
 * TIMER2_PRESCALER_128
 * TIMER2_PRESCALER_256
 * TIMER2_PRESCALER_1024
 * */
#define TIMER2_PRESCALER_SELECTED		TIMER2_PRESCALER_1024
////////////////////////////////////////////////////////////////////////////

#endif /* TIMER2_CFG_H_ */