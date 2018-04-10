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

int main(void)
{
	u8 Value;
	DDRA=0xFF;
	DDRD=0xFF;
	Lcd_vidInit();
	while (1)
	{
		Value=U8KEY_PAD();
		Lcd_vidWriteCharctr(Value);
	}

	return 0;
}




