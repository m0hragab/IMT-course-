/*
 * main.c
 *
 *  Created on: Jan 20, 2018
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


u16 ov_count;
int main(void)
{

	Dio_vidSetPinDirection(Dio_PORTB,2,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
	TCCR0=0b00000001;//no prescaler 1024
	TCNT0=0;
    setbit(SREG,7);
    setbit(TIMSK,0);//ENABLE TIMER OVERFLOW//PIE enable

    while(1)
    {
    	if(ov_count==31250)
    	{
    		TOGGLE_BIT(PORTB,2);
    		ov_count=0;
    	}
    }


	return 0;
}


ISR(TIMER0_OVF_vect)
{
  ov_count++;
}