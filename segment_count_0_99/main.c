/*
 * main.c
 *
 *  Created on: Jan 6, 2018
 *      Author: mohragab
 */

#include"led.h"
#include<util/delay.h>
int main(void)

{
	u8 seg[10]={0XA0,0XF9,0XC4,0XD0,0X99,0X92,0X82,0XF8,0X80,0X90};
	u8 i;
	DDRC=0XFF;
	DDRD=0XFF;
	DDRA=0XFF;
	PORTC=0XFF;
	while(1)
	{
		for(i=0;i<100;i++){
			PORTD=seg[(i/10)%10];
			_delay_ms(500);
			PORTA=seg[i%10];
			_delay_ms(500);
	       }
	}
return 0;
}

