/*
 * main.c
 *
 *  Created on: Jan 5, 2018
 *      Author: mohragab
 */

#include"led.h"
#include<util/delay.h>
int main(void)

{
	u8 seg[10]={0XA0,0XF9,0XC4,0XD0,0X99,0X92,0X82,0XF8,0X80,0X90};
	u8 i;
	DDRD=0XFF;
	DDRD=0XFF;
	PORTC=0XFF;
	DDRB=0XFF;
	PORTD=0XFF;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTB=seg[i];
			//PORTA=seg[i];
			_delay_ms(1000);
		}
	}
return 0;
}
