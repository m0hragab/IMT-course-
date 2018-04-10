/*

 * Main.c
 *
 *  Created on: Feb 23, 2018
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

	u8 seg[10]={0XA0,0XF9,0XC4,0XD0,0X99,0X92,0X82,0XF8,0X80,0X90};
	u16 digital=0;
	u16 t=0,o=0;
	Dio_vidSetPortDirection(Dio_PORTA,0x00);
	Dio_vidSetPortDirection(Dio_PORTB,0xff);
	Dio_vidSetPortDirection(Dio_PORTD,0xff);
	Dio_vidSetPortDirection(Dio_PORTC,0xff);
	Dio_vidSetPortValue(Dio_PORTB,0xff),
	Dio_vidSetPortValue(Dio_PORTC,0xff),
	Dio_vidSetPinValue(Dio_PORTD,0,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTD,1,STD_HIGH);
	ADCSRA=0X87;//10000111
	ADMUX=0b11100000;//11100000//internal VCC 2.56


	while(1)
	{
		setbit(ADCSRA,6);//START Conversion (sc)
		while (getbit(ADCSRA,4)==0);//check if conversion done /pooling
		digital=ADCH;
		t=((digital/10)%10);
		o=(digital%10);
		PORTC=seg[t];
		PORTB=seg[o];
	}


	return 0;

}

