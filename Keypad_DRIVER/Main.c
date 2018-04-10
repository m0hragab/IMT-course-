/*
 * keyPad.c
 *
 *  Created on: Jan 12, 2018
 *      Author: mohragab
 */
#include"Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "LCD_Interface.h"
#include"Key_Pad_Driver.h"
#include<avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000

int main(void)
{
	u8 Value,i,sum;
	i=10,sum=0;
    u8 num1,num2;
	KEY_PAD_vidInit();
	lcd_vidinit();
	_delay_ms(10);
	while (1)
	{
		Value=U8KEY_PAD();
		/*u8 arr[]={Value,'\0'};
		for(i=0;i<10;i++)
		{
			switch(arr[i])
			{
			case '+':
				sum=((arr[0])+('0'))+((arr[i+1])+('0'));
				sum=sum%10;
				break;
			case'=':
				lcd_vidsendcommand(LCD_CLEAR_SCREEN);
				lcd_vidwritechar((sum)+('0'));
				break;
			}

		}*/


        	/* num1=(Value-'0')%10;
        	 num2=(Value-'0')%10;
        	 sum=num1+num2;

        	 lcd_vidwritechar((sum+'0'));*/



		if(Value=='c')
		{
			lcd_vidsendcommand(LCD_CLEAR_SCREEN);
		}
		else
		lcd_vidwritechar(Value);
	}

	return 0;
}




