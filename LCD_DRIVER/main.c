/*
 * main.c
 *
 *  Created on: Feb 3, 2018
 *      Author: mohragab
 */



#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "Dio.h"
#include "LCD_Interface.h"
int main (void)
{
u8 i;
u8 name[]="Omar";
lcd_vidinit();
while(1)
{

	/*Lcd_vidGOTO(1,0);
	Lcd_vidWriteString(name);
	_delay_ms(1000);
	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	Lcd_vidGOTO(2,4);
	Lcd_vidWriteString(name);
	_delay_ms(1000);
	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	Lcd_vidGOTO(1,8);
	Lcd_vidWriteString(name);
	_delay_ms(1000);
	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	Lcd_vidGOTO(2,12);
	Lcd_vidWriteString(name);
	_delay_ms(1000);
	lcd_vidsendcommand(LCD_CLEAR_SCREEN);*/

	//looping char
	/*for(i=0;i<=15;i++)
	{
		Lcd_vidGOTO(1,i);
		lcd_vidwritechar('w');
		_delay_ms(1000);
		lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	}
	for(i=15;i>=0;i--)
	{
	 Lcd_vidGOTO(2,i);
	 lcd_vidwritechar('w');
	 _delay_ms(1000);
	 lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	 if(i==0)
		 break;
	}*/







//sin wave Code
	for(i=0;i<13;i++)
    {
    	if(i%2==0)
    	{

    	Lcd_vidGOTO(1,i);
    	Lcd_vidWriteString(name);
    	_delay_ms(1000);
    	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
    	}
    	else if(i%2!=0)
    	{
        Lcd_vidGOTO(2,i);
        Lcd_vidWriteString(name);
    	_delay_ms(1000);
    	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
    	}
    }




}


return 0;
}

