/*
 * EXTI_HW.h
 *
 * Created: 9/15/2020 10:28:17 PM
 *  Author: Moataz
 */ 


#ifndef EXTI_HW_H_
#define EXTI_HW_H_



#define MCUCR	*((volatile uint8*)0X55)
#define MCUCSR	*((volatile uint8*)0X54)
#define GICR	*((volatile uint8*)0X5B)
#define GIFR	*((volatile uint8*)0X5A)

#endif /* EXTI_HW_H_ */