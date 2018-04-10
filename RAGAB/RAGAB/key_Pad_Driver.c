/*
 * key_Pad_Driver.c
 *
 *  Created on: Jan 19, 2018
 *      Author: mohragab
 */
#include"Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "LCD.h"
#include"Key_Pad_Driver.h"
#include<avr/delay.h>
#include <util/delay.h>
u8 U8KEY_PAD(void)
{

	u8 arr[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','x'},{'=','0','#','/'}};
	u8 R , C;
	u8 x =0;
	DDRB=0X0F;
	PORTB=0XFF;
	while (1)
	{
		for(R=0;R<=3;R++)
		{
			clearbit(PORTB,R);
			for(C=4;C<8;C++)
			{
				if(Dio_u8GetPinValue(Dio_PORTB,C)==0)
				{
					x =arr[R][C-4];
					while(Dio_u8GetPinValue(Dio_PORTB,C)==0);
					_delay_ms(120);
					return x;
				}
			}
			setbit(PORTB,R);
		}
	}

}

