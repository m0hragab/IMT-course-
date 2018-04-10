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
#include "LCD_Interface.h"
#include "key_PAD_Interface.h"
#include <util/delay.h>
#include <stdio.h>
u8 sum(u8,u8);

int main(void)
{
	u8 base_100=100;
	u8 base_10=10;
	u8 i=0;
	u8 j=0;
	u8 result=0,h=0,t=0,o=0,T=0;
	u8 sign=0;
	u8 flag=0;
	u8 num1[3]={0};
	u8 num2[3]={0};
	u16 x;
	u16 y;
	u8 pressed_key;
	keypad_vidinit();
	lcd_vidinit();
	_delay_ms(2);
	pressed_key=0xff;

	while (1)
	{

	  while(pressed_key!=('='))
	  {
		 pressed_key=key_PAD_U8Get_Key();
		  if(pressed_key==('c'))
		 {
			 lcd_vidsendcommand(LCD_CLEAR_SCREEN);
			 pressed_key = 0xFF;
			 sign=0,flag=0,i=0,j=0;
			 x=0;y=0;result=0;
			 break;
		 }
		  else
		  {
			  if(pressed_key!=0xff)
			  {
				 lcd_vidwritechar(pressed_key);
				 _delay_ms(10);
			  if((pressed_key=='+')||(pressed_key=='-')||(pressed_key=='*')||(pressed_key=='+'))
				 {
					 sign=pressed_key;
					 flag=1;
				 }
			  else if((flag==0)&&(pressed_key!=('=')))
			  {
				  num1[i]=pressed_key-0x30;
				  i++;
			  }
			  else if((flag==1)&&(pressed_key!=('=')))
			  {
				  num1[i]=pressed_key-0x30;
				  j++;
			  }
			  }
		  }
	  }
	  x=((num1[0])*(base_100))+((num1[1])*(base_10))+num1[2];
	  y=((num2[0])*(base_100))+((num2[1])*(base_10))+num2[2];
	  switch(sign)
		  {
		  case'+':
          result=sum(x,y);
          T=(result/1000)%10;
          h=(result/100)%10;
          t=(result/10)%10;
          o=(result)%10;
          lcd_vidwritechar(T+0X30);
          lcd_vidwritechar(h+0X30);
          lcd_vidwritechar(t+0X30);
          lcd_vidwritechar(o+0X30);

		  }

	  }

   return 0;
}

u8 sum(u8 x ,u8 y)
{

	u8 sum=0;
	sum=x+y;
	return sum;
}













