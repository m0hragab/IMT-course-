/*
 * main.c
 *
 *  Created on: Feb 9, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "LCD.h"
#include "key_Pad_Driver.h"
#include <util/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>

int main(void)
{
	u8 flag=0;
	u8 val[3]={0};
	u8 intensity=0;
	u8 i=0;
	u8 line[]="intensity:";
	u8 line2[]="OCR0= ";
	u8 pressed_key;
	TCCR0=0b01101001;
	TCNT0=0;
	OCR0=0;
	Dio_vidSetPinDirection(Dio_PORTB,3,STD_HIGH);////oc0 b3 pwm signal
	Lcd_vidInit();
	KEY_PAD_vidInit();
	_delay_ms(2);
	pressed_key=0;
	while (1)
	{
		Lcd_vidGOTO(1,0);
		Lcd_vidWriteString(line);
		while(flag==0)
		{
			pressed_key= U8KEY_PAD();
			Lcd_vidWriteCharctr(pressed_key);
			if((pressed_key>='0')&&(pressed_key<='9')&&(flag==0))
			{

				val[i]=pressed_key-'0';
				_delay_ms(100);
				i++;
			}
			if(i==3)
			{
				flag=1;
				break;
			}

		}

		intensity=(val[0]*100)+(val[1]*10)+val[2];
		OCR0=intensity;
		Lcd_vidGOTO(2,0);
		Lcd_vidWriteString(line2);
		Lcd_vidWriteCharctr((intensity/100)%10+'0');
		Lcd_vidWriteCharctr((intensity/10)%10+'0');
		Lcd_vidWriteCharctr(intensity%10+'0');
		_delay_ms(20);
		flag=0;
		pressed_key=0;
		i=0;
	}

	return 0;
}
