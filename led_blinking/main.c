/*
 * led.c
 *
 *  Created on: Jan 4, 2018
 *      Author: mohragab
 */
#include"led.h"
//#include<avr/io.h>
#include<util/delay.h>

int main(void)
{

	DDRB = 0b11111111;

   while(1)
   {


		 PORTB =0b11111111;
		 _delay_ms(50);
		 PORTB =0b00000000;
		 _delay_ms(50);
   }

	return 0;
}

