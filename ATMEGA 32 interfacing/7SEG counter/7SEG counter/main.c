/*
 * 7SEG counter.c
 *
 * Created: 10/5/2020 11:47:04 PM
 * Author : Moataz
 */ 

#define F_CPU	16000000ul

#include "HAL/BCDSevSeg/BCDSevSeg.h"
#include "MCAL/TIMER2/TIMER2.h"

#define NO_COMP_MATCH	125

uint8 COUNTER = 0;

int main(void)
{
	DIO_SetPinDir('A',PIN0,OUT);
	DIO_WritePin('A',PIN0,LOW);
	
	BCDSevSeg_init();
	BCDSevSeg_1_EN();
	
	TIMER2_init();
	
    while (1) 
    {
    }
}

ISR(TIMER2_COMP)
{
	static uint8 comp_counter = 0;
	comp_counter++;
	if (comp_counter == NO_COMP_MATCH)
	{
		DIO_FlipPin('A',PIN0);
		COUNTER++;
		if (COUNTER == 10)
		{
			COUNTER = 0;
		}
		comp_counter = 0;
	}
	BCDSevSeg_Write(COUNTER);
}