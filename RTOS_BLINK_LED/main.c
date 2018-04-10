/*
 * main.c
 *
 *  Created on: Dec 21, 2017
 *      Author: EngOm
 */
#include"Std_Types.h"
#include "Macros.h"
#include "Dio.h"
#include "FreeRTOS.h"
#include "task.h"
void led_blink(void * pv);
xTaskHandle led_Handle;

/*int main(void)
{
    Dio_vidSetPortDirection(Dio_PORTB,0xff);
	Dio_vidSetPinDirection(Dio_PORTB,0,STD_HIGH);
	xTaskCreate(led_blink,"led_blink",40,NULL,1,&led_Handle);
    vTaskStartScheduler();
	return 0;
}

void led_blink(void * pv)
{
	portTickType lastcount;
	const portTickType priodicity =500;
	lastcount=xTaskGetTickCount();
	while(1)
	{
		TOGGLE_BIT(PORTB,0);
		vTaskDelay(500);
	}
}*/


int main(void)
{
    Dio_vidSetPortDirection(Dio_PORTB,0xff);
	Dio_vidSetPinDirection(Dio_PORTB,0,STD_HIGH);
	xTaskCreate(led_blink,"led_blink",60,NULL,1,&led_Handle);
    vTaskStartScheduler();
	return 0;
}

void led_blink(void * pv)
{
	portTickType lastcount;
	const portTickType priodicity =500;

	while(1)
	{
		TOGGLE_BIT(PORTB,0);
		lastcount=xTaskGetTickCount();
		vTaskDelayUntil(&lastcount,priodicity);
	}
}

