/*
 * keyPad.c
 *
 *  Created on: Jan 12, 2018
 *      Author: mohragab
 */
#include"Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "LCD.h"

int main(void)
{

	u8 R , C;
	Dio_vidSetPortDirection(Dio_PORTA,0b11111111);
	Dio_vidSetPortDirection(Dio_PORTD,0b11111111);

	Lcd_vidInit();
	_delay_ms(100);
	Dio_vidSetPortDirection(Dio_PORTB,0b00001111);

	DDRB=0x0f;
	PORTB = 0xff;
	Lcd_vidSendCommand(clear_display);
while(1)
{

	for(R=0;R<=3;R++)
	{
		clearbit(PORTB,R);
		for(C=4;C<=7;C++)
		{
			if(getbit(PINB,C)==0)
			{

				Lcd_vidWriteCharctr(R+'0');
				Lcd_vidWriteCharctr((C-4)+'0');
				_delay_ms(120);
				while(getbit(PINB,C)==0);
			}

		}
		setbit(PORTB,R);
	}
    _delay_ms(50);
	Lcd_vidSendCommand(clear_display);
}
return 0;
}

