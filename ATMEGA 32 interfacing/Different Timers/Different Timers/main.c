/*
 * Different Timers.c
 *
 * Created: 9/30/2020 11:25:36 PM
 * Author : Moataz
 */ 

//#define F_CPU	16000000ul

#include "MCAL/TIMER0/TIMER0.h"
#include "MCAL/DIO/DIO.h"

#define COUNT_OF_OVF		(6250)

int main(void)
{
	/*set configuration for the  3 led pins*/
	DIO_SetPinDir('C',PIN0,OUT);
	DIO_SetPinDir('C',PIN1,OUT);
	DIO_SetPinDir('C',PIN2,OUT);
	
	/*initialize output for the  3 led pins*/
	DIO_WritePin('C',PIN0,HIGH);
	DIO_WritePin('C',PIN1,HIGH);
	DIO_WritePin('C',PIN2,HIGH);
	
    /* set configuration for the timer*/
	
	TIMER0_init();
    while (1) 
    {
    }
}

ISR(TIMER0_OVF)
{
	static uint16 ovf_counter = 0;
	ovf_counter++;
	//LED 1 toggle each 100ms
	if ((ovf_counter % 25) == 0)
	{
		//toggle led 1
		DIO_FlipPin('C',PIN0);
	}
	//LED 2 toggle each 200ms
	if ((ovf_counter % 50) == 0)
	{
		//toggle led 2
		DIO_FlipPin('C',PIN1);
	}
	//LED 3 toggle each 500ms
	if ((ovf_counter % 125) == 0)
	{
		//toggle led 3
		DIO_FlipPin('C',PIN2);
	}
	if (ovf_counter == COUNT_OF_OVF)
	{
		//reset the counter of the overflow times
		ovf_counter = 0;
	}
	//preload the counter
	TIMER0_PRELOAD_COUNTER(TIMER0_PRELOADED_COUNTER);
}