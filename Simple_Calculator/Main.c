/*
 * keyPad.c
 *
 *  Created on: Jan 12, 2018
 *      Author: mohragab
 */
#include"Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "LCD.h"
#include"Key_Pad_Driver.h"
#include<avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000
//u16 sum(u16 ,u16 );
int main(void)
{
	u8 pressed_key=0;
	KEY_PAD_vidInit();
	Lcd_vidInit();
	_delay_ms(10);
	u8 flag=0;
	u8 x[2]={0};
	u8 y[2]={0};
	u16 num1=0;
	u16 num2=0;
	u8 i=0;
	u8 j=0;
	u8 operation=0;
	u16 result=0;
	u8 base10=10;
	u8 t=0;
	u8 o=0;
	while (1)
	{

		while(pressed_key!='=')
		{
		pressed_key=U8KEY_PAD();
		if(pressed_key=='c')
		{
          Lcd_vidSendCommand(clear_display);
		}
		else
		{
		    Lcd_vidWriteCharctr(pressed_key);
		    if((pressed_key=='+')||(pressed_key=='-')||(pressed_key=='*')||(pressed_key=='/'))
		    {
		    	if(pressed_key=='c')
		    	{
		    	    Lcd_vidSendCommand(clear_display);
		    	}
		    	operation=pressed_key;
		    	flag=1;
		    }
		    else if((flag==0)&&(pressed_key!='='))
		    {
		    	if(pressed_key=='c')
		    	 {
		    	  Lcd_vidSendCommand(clear_display);
		    	 }
		    	x[i]=pressed_key-'0';
		    	_delay_ms(20);
		    	++i;
		    }
		    else if((flag==1)&&(pressed_key!='='))
		    {
		    	if(pressed_key=='c')
		    	 {
		    	  Lcd_vidSendCommand(clear_display);
		    	 }
		    	y[j]=pressed_key-'0';
		    	_delay_ms(20);
		    	++j;
		    }
		}

		num1=(x[0]*base10)+x[1];
	   	num2=(y[0]*base10)+y[1];
	 if(pressed_key=='=')
	 {
	 switch(operation)
	 {
	 case'+':
		 result=num1+num2;
		 t=((result/10)%10);
		 o=(result%10);
		 Lcd_vidWriteCharctr((t+'0'));
		 Lcd_vidWriteCharctr((o+'0'));
		 //Lcd_vidWriteCharctr(result+0x30);

		 flag=0;num1=0;num2=0;operation=0;i=0;j=0;pressed_key=0;
		 break;
	 }
	}
	}
	}
	return 0;
}


