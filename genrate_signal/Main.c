/*
 * Main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
	Dio_vidSetPortDirection(Dio_PORTC,0xff);

	while(1)
	{
		Dio_vidSetPinValue(Dio_PORTC,0,STD_HIGH);
		_delay_ms(25);
		Dio_vidSetPinValue(Dio_PORTC,0,STD_LOW);
		_delay_ms(12);

	}

	return 0;

}
