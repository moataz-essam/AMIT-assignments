/*
 * Garage System.c
 *
 * Created: 9/29/2020 7:36:09 PM
 * Author : Moataz
 */ 

#define F_CPU 16000000ul

#define ENTER_GARAGE	EXINT0
#define EXIT_GARAGE		EXINT1
#define MAX_NO_CARS		9
#define EMPTY			0
#define EMPTY_LED_ON	DIO_WritePin('D',PIN6,HIGH)
#define EMPTY_LED_OFF	DIO_WritePin('D',PIN6,LOW)
#define FULL_LED_ON		DIO_WritePin('D',PIN7,HIGH)
#define FULL_LED_OFF	DIO_WritePin('D',PIN7,LOW)

#include "HAL/LCD/LCD.h"
#include "MCAL/EXTI/EXTI.h"
#include "HAL/BCDSevSeg/BCDSevSeg.h"

//global variable for the count of cars in the garage
uint8 COUNTER = 0;

void BUZZER_BEEB(void);

int main(void)
{
	/* set the pin of the buzzer to be output */
	DIO_SetPinDir('D',PIN5,OUT);
    /* set the pins of the led indicators to be output */
	DIO_SetPinDir('D',PIN6,OUT);
	DIO_SetPinDir('D',PIN7,OUT);
	/*set the initial output for the buzzer*/
	DIO_WritePin('D',PIN5,LOW);
	/*set the initial output for the led indicators*/
	EMPTY_LED_ON;
	FULL_LED_OFF;
	
	/*initialize for different component*/
	LCD_init();
	EXTI_init();
	BCDSevSeg_init();
	
	/*enable the global interrupt*/
	GLOBAL_INT_EN;
	
    while (1) 
    {
		//LCD make animation
		LCD_SendString("Garage System");
		for(uint8 i = 0 ; i<3 ; i++)
		{
			_delay_ms(200);
			LCD_SendCommand(LCD_MOVE_DISP_RIGHT);
		}
		for(uint8 i = 0 ; i<3 ; i++)
		{
			_delay_ms(200);
			LCD_SendCommand(LCD_MOVE_DISP_LEFT);
		}
		LCD_ClrScreen();
    }
}

void BUZZER_BEEB(void)
{
	DIO_WritePin('D',PIN5,HIGH);
	_delay_ms(100);
	DIO_WritePin('D',PIN5,LOW);
}

//interrupt service routine for adding new vehicle
ISR(ENTER_GARAGE)
{
	COUNTER++;
	if (COUNTER <= MAX_NO_CARS)
	{
		if(COUNTER == MAX_NO_CARS)
		{
			BUZZER_BEEB();
			FULL_LED_ON;
			EMPTY_LED_OFF;
		}
		else{}
		BCDSevSeg_Write(COUNTER);
	}
	else
	{
		COUNTER--;
		BUZZER_BEEB();
		FULL_LED_ON;
		EMPTY_LED_OFF;
	}
}

//interrupt service routine for subtracting a vehicle
ISR(EXIT_GARAGE)
{
	if (COUNTER == EMPTY)
	{
		//buzzer go on
		BUZZER_BEEB();
	}
	else
	{
		COUNTER--;
		BCDSevSeg_Write(COUNTER);
	}
	FULL_LED_OFF;
	EMPTY_LED_ON;
}