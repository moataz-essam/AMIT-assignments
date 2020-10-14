/*
 * EXTI_cfg.h
 *
 * Created: 9/29/2020 9:46:39 PM
 *  Author: Moataz
 */ 


#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/*******choose the external interrupt to be enabled********/
#define EXTI_INT0_EN		ENABLE
#define EXTI_INT1_EN		ENABLE
#define EXTI_INT2_EN		DISABLE
/****************************************************/

/*******choose the trigger for the external interrupt********
from the list:
 *LowCycle
 *AnyChange
 *FallingEdge
 *RisingEdge
 */
 #define EXTI_INT0_EDGE		FallingEdge
 #define EXTI_INT1_EDGE		FallingEdge
 #define EXTI_INT2_EDGE		FallingEdge
/****************************************************/

#endif /* EXTI_CFG_H_ */