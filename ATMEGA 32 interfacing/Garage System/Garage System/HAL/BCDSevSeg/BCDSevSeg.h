/*
 * BCDSevSeg.h
 *
 * Created: 9/15/2020 10:29:43 PM
 *  Author: Moataz
 */ 


#ifndef BCDSEVSEG_H_
#define BCDSEVSEG_H_

#define F_CPU 16000000ul
#include <util/delay.h>
#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\config\BCDSevSeg_cfg.h"

/***functions prototype***/
void BCDSevSeg_init();
void BCDSevSeg_1_EN();
void BCDSevSeg_1_DIS();
void BCDSevSeg_2_EN();
void BCDSevSeg_2_DIS();
void BCDSevSeg_Write(uint8 num);

#endif /* BCDSEVSEG_H_ */