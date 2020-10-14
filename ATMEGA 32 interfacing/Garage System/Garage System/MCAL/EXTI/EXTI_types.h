/*
 * EXTI_types.h
 *
 * Created: 9/15/2020 10:28:35 PM
 *  Author: Moataz
 */ 


#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_

typedef enum
{
	LowCycle,
	AnyChange,
	FallingEdge,
	RisingEdge
}EXTI_EdgeType;

typedef enum
{
	INT0,
	INT1,
	INT2
}EXTI_IntType;

#endif /* EXTI_TYPES_H_ */