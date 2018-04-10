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
#include<avr/io.h>
#include"util/delay.h"


int main(void)
{

	Dio_vidSetPinDirection(Dio_PORTB,2,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
    u8 i;

	while(1)
	{

		for(i=0;i<9;i++)
		{
		Dio_vidSetPinValue(Dio_PORTB,2,STD_HIGH);
		_delay_us(1500);
		Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
		_delay_us(18500);
		}
        _delay_us(1000);

        for(i=0;i<9;i++)
        {

            Dio_vidSetPinValue(Dio_PORTB,2,STD_HIGH);
            _delay_us(1000);
            Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
            _delay_us(19000);
        }


	}
	return 0;

}
