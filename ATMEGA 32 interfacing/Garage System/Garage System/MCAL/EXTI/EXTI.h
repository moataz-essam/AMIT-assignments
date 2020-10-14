/*
 * EXTI.h
 *
 * Created: 9/15/2020 10:28:48 PM
 *  Author: Moataz
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "..\..\utils\STD_types.h"
#include "..\..\utils\BitMath.h"
#include "..\..\utils\interrupts.h"
#include "..\DIO\DIO_HW.h"
#include "EXTI_HW.h"
#include "EXTI_types.h"
#include "..\..\config\EXTI_cfg.h"

void EXTI_init(void);
void EXTI_SetEdge(EXTI_IntType IntType, EXTI_EdgeType edgetype);
void EXTI_EnINT(EXTI_IntType IntType);
void EXTI_DisINT(EXTI_IntType IntType);

#endif /* EXTI_H_ */