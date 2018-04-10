/*
 * main.c
 *
 *  Created on: Jan 5, 2018
 *      Author: mohragab
 */
#include"led.h"
#include<util/delay.h>
#include"type_get.h"
int main(void)
{
	setbit(DDRA,0);
	clearbit(DDRA,3);
	setbit(PORTA,3);
	while(1)
	{
		if(getbit(PINA,3)==0)
		{
			setbit(PORTA,0);
			_delay_ms(100);
		}
		else
		{
			clearbit(PORTA,0);
			_delay_ms(100);
		}
	}


}

