/*
 * keypad and LCD Queue mang.c
 *
 * Created: 10/14/2020 2:01:52 AM
 * Author : Moataz
 */ 

#define F_CPU	16000000ul
#include <util/delay.h>

#include "MCAL/DIO/DIO.h"
#include "HAL/KP/KP.h"
#include "HAL/LCD/LCD.h"
#include "Source/FreeRTOS.h"
#include "Source/task.h"
#include "Source/queue.h"

void Sender (void *p);
void Receiver (void *p);

QueueHandle_t xqueue;
int main(void)
{
	LCD_init();
	KP_init();
	xqueue = xQueueCreate(5,sizeof(uint8));
	if (xqueue != NULL)
	{
		xTaskCreate(Sender,"Sender_Task",300,NULL,1,NULL);
		xTaskCreate(Receiver,"Recv_Task",300,NULL,2,NULL);
		vTaskStartScheduler();
	}
	while (1)
	{}
}

void Sender (void *p)
{
	uint8 display = 0;
	while (1)
	{
		display = KP_Get_Key();
		xQueueSendToBack(xqueue,&display,portMAX_DELAY);
		vTaskDelay(100/portTICK_PERIOD_MS);
	}
}

void Receiver (void *p)
{
	uint8 value;
	while (1)
	{
		xQueueReceive(xqueue,&value,portMAX_DELAY);
		if (value != 0)
		{
			LCD_GotoXY(0,0);
			LCD_SendChar(value);
		}
	}
}