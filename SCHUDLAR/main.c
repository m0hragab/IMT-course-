/*

 * main.c
 *
 *  Created on: Feb 17, 2018
 *      Author: mohragab
 */
#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
#include"RTO_Interface.h"

TASK_TYPE TASK1;
void Toggle(void);

/*u16 LED_4000MS=0;
u16 LED_1000MS =0;
u16 LED_500MS=0;
u16 LED_250MS=0;*/
u8 i;


int main(void)
{

	Dio_vidSetPinDirection(Dio_PORTB,0,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,0,STD_LOW);
	Dio_vidSetPinDirection(Dio_PORTB,1,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,1,STD_LOW);
	Dio_vidSetPinDirection(Dio_PORTB,2,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
	Dio_vidSetPinDirection(Dio_PORTB,3,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,3,STD_LOW);

	TASK1.first_delay=0;
	TASK1.priodicity=500;
	TASK1.state=RTO_u8TASK_RUNNING;
	TASK1.ptrfun=Toggle;
	RTO_VidInit();
	RTO_VidCreate(&TASK1,0);


	return 0;
}

void Toggle(void)
{

}
