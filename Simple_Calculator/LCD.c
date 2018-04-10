/*
 * LCD.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Toshiba
 */
#include "Std_Types.h"
#include "Dio.h"
#include "Macros.h"
#include "LCD.h"
#include <util/delay.h>



void Lcd_vidSendCommand(u8 u8CmdCpy)
{
	Dio_vidSetPinValue(Dio_PORTC,RS,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTC,RW,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_HIGH);
	Dio_vidSetPortValue(Dio_PORTB,u8CmdCpy);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_LOW);
	_delay_ms(5);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_HIGH);



}

void Lcd_vidInit(void)
{
	Dio_vidSetPortDirection(Dio_PORTC,0xff);
    Dio_vidSetPortDirection(Dio_PORTB,0xff);
	Lcd_vidSendCommand(clear_display);
	Lcd_vidSendCommand(return_home);
	Lcd_vidSendCommand(entery_mode_set);
	Lcd_vidSendCommand(display_on_off_control);
	Lcd_vidSendCommand(function_set);

}

void Lcd_vidWriteCharctr(u8 u8DataCpy)
{
	Dio_vidSetPinValue(Dio_PORTC,RS,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTC,RW,STD_LOW);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_HIGH);
	Dio_vidSetPortValue(Dio_PORTB,u8DataCpy);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_LOW);
	_delay_ms(5);
	Dio_vidSetPinValue(Dio_PORTC,E,STD_HIGH);
	_delay_ms(10);
}


void Lcd_vidWriteString(u8* pu8StringCpy)
{

  /* Local loop index */
  u8 u8Index = 0;

  while (pu8StringCpy[u8Index] != 0)
  {
    /* Write Character on LCD */
    Lcd_vidWriteCharctr(pu8StringCpy[u8Index]);

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
		Lcd_vidSendCommand(0x80+col);
	}
	else if (row==2)
	{
		Lcd_vidSendCommand(0xC0+col);
	}
}






