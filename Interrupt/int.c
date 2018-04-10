/*
 * int.c
 *
 *  Created on: Jan 19, 2018
 *      Author: mohragab
 */

#include"Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
int main(void)
{
	DDRD=0XFF;

	setbit(SREG,7);//ENABALE GLOBALE INTERRUPT
	clearbit(MCUCR,1);//
	setbit(MCUCR,1);
	setbit(GICR,6);
    Dio_vidSetPinDirection(Dio_PORTD,2,0);//set bit input
    Dio_vidSetPinValue(Dio_PORTD,2,1);//pull up switch off ==1



	while(1)
	{
		Dio_vidSetPinValue(Dio_PORTD,7,STD_LOW);
	}



	return 0;
}

ISR(INT0_vect)
{
	Dio_vidSetPinValue(Dio_PORTD,7,STD_HIGH);
	_delay_ms(1000);

}

