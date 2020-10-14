/*
 * BCDSevSeg.c
 *
 * Created: 9/15/2020 10:29:57 PM
 *  Author: Moataz
 */ 

#include "BCDSevSeg.h"

void BCDSevSeg_init()
{
	/***data port initialization***/
	DIO_SetPinDir(BCDSevSeg_Data,BCDSevSeg_PIN_A,OUT);
	DIO_SetPinDir(BCDSevSeg_Data,BCDSevSeg_PIN_B,OUT);
	DIO_SetPinDir(BCDSevSeg_Data,BCDSevSeg_PIN_C,OUT);
	DIO_SetPinDir(BCDSevSeg_Data,BCDSevSeg_PIN_D,OUT);
	
	/***control port initialization***/
	DIO_SetPinDir(BCDSevSeg_Ctrl,BCDSevSeg_EN1,OUT);
	DIO_SetPinDir(BCDSevSeg_Ctrl,BCDSevSeg_EN2,OUT);
	DIO_SetPinDir(BCDSevSeg_Ctrl,BCDSevSeg_DIP,OUT);
}

void BCDSevSeg_1_EN()
{
	DIO_WritePin(BCDSevSeg_Ctrl,BCDSevSeg_EN1,HIGH);
}

void BCDSevSeg_1_DIS()
{
	DIO_WritePin(BCDSevSeg_Ctrl,BCDSevSeg_EN1,LOW);
}

void BCDSevSeg_2_EN()
{
	DIO_WritePin(BCDSevSeg_Ctrl,BCDSevSeg_EN2,HIGH);
}

void BCDSevSeg_2_DIS()
{
	DIO_WritePin(BCDSevSeg_Ctrl,BCDSevSeg_EN2,LOW);
}

void BCDSevSeg_Write(uint8 num)
{
	#if( BCDSevSeg_PORT == HIGH_NIBBLE)
	DIO_WriteHighNibVal(BCDSevSeg_Data,(num<<4));
	#endif
	#if( BCDSevSeg_PORT == LOW_NIBBLE)
	DIO_WriteLowNibVal(BCDSevSeg_Data,(num));
	#endif
}