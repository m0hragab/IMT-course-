/*
 * LCD_pro.c
 *
 *  Created on: Feb 3, 2018
 *      Author: mohragab
 */
#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "LCD_Interface.h"
void lcd_vidinit(void)
{

	//INTIALIZE DATA
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d0,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d1,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d2,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d3,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d4,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d5,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d6,STD_HIGH);
	Dio_vidSetPinDirection(LCD_DATA_PORT,lcd_d7,STD_HIGH);
	//INTIALIZE CONTROL
	Dio_vidSetPinDirection(LCD_CTRL_PORT,RS,STD_HIGH);
	Dio_vidSetPinDirection(LCD_CTRL_PORT,RW,STD_HIGH);
	Dio_vidSetPinDirection(LCD_CTRL_PORT,E,STD_HIGH);

	lcd_vidsendcommand(LCD_8MODE_2L);
	_delay_ms(2);
	lcd_vidsendcommand(LCD_ON_NOCURSER);
	_delay_ms(2);
	lcd_vidsendcommand(LCD_CLEAR_SCREEN);
	_delay_ms(2);
}

void lcd_vidsendcommand(u8 comand)
{
	Dio_vidSetPinValue(LCD_CTRL_PORT,RS,STD_LOW);
	Dio_vidSetPinValue(LCD_CTRL_PORT,RW,STD_LOW);
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d0,getbit(comand,0));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d1,getbit(comand,1));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d2,getbit(comand,2));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d3,getbit(comand,3));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d4,getbit(comand,4));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d5,getbit(comand,5));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d6,getbit(comand,6));
	Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d7,getbit(comand,7));
	Dio_vidSetPinValue(LCD_CTRL_PORT,E,STD_HIGH);
    _delay_ms(2);
    Dio_vidSetPinValue(LCD_CTRL_PORT,E,STD_LOW);


}

void lcd_vidwritechar(u8 data)
{
	    Dio_vidSetPinValue(LCD_CTRL_PORT,RS,STD_HIGH);
		Dio_vidSetPinValue(LCD_CTRL_PORT,RW,STD_LOW);

		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d0,getbit(data,0));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d1,getbit(data,1));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d2,getbit(data,2));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d3,getbit(data,3));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d4,getbit(data,4));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d5,getbit(data,5));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d6,getbit(data,6));
		Dio_vidSetPinValue(LCD_DATA_PORT,lcd_d7,getbit(data,7));
		Dio_vidSetPinValue(LCD_CTRL_PORT,E,STD_HIGH);
	    _delay_ms(2);
	    Dio_vidSetPinValue(LCD_CTRL_PORT,E,STD_LOW);
}

void Lcd_vidWriteString(u8* pu8StringCpy)
{

  /* Local loop index */
  u8 u8Index = 0;

  while (pu8StringCpy[u8Index] != 0)
  {
    /* Write Character on LCD */
	  lcd_vidwritechar(pu8StringCpy[u8Index]);

    /* Increment local loop index */
    u8Index++;

    /* Delay to let the LCD show the character */
    _delay_ms(2);
  }

}

void Lcd_vidGOTO(u8 row,u8 col)
{
	if (row==1)
	{
		lcd_vidsendcommand(0x80+col);
	}
	else if (row==2)
	{
		lcd_vidsendcommand(0xC0+col);
	}
	//lcd_vidsendcommmand((row==0)?(0x80+col):(0xc0+col))
}



