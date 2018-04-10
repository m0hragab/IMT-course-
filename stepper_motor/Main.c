/*
 * Main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"




int main(void)
{
Dio_vidSetPortDirection(Dio_PORTB,STD_HIGH);
//Dio_vidSetPortValue(Dio_PORTB,STD_HIGH);

while(1)
{
	Dio_vidSetPinValue(Dio_PORTB,0,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,1,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,3,STD_LOW);
	_delay_ms(5);
	Dio_vidSetPinValue(Dio_PORTB,0,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,1,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,3,STD_LOW);
	_delay_ms(5);
	Dio_vidSetPinValue(Dio_PORTB,0,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,1,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,3,STD_LOW);
	_delay_ms(5);
	Dio_vidSetPinValue(Dio_PORTB,0,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,1,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTB,3,STD_HIGH);
	_delay_ms(5);


}




	return 0;
}
