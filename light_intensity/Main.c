/*
 * Main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: mohragab
 */
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
#include"Dio.h"
#include"Macros.h"
#include"Std_Types.h"
//Control intenisity of light
int main(void)
{
u8 i=0;
TCCR0=0b01101001;
TCNT0=0;

Dio_vidSetPinDirection(Dio_PORTB,3,STD_HIGH);////oc0 b3 pwm signal


while(1)
{

	for(i=0;i<256;i++)
	{
      OCR0=i;
      _delay_ms(100);
	}

}

	return 0;

}
