/*
 * key_PAD_pro.c
 *
 *  Created on: Feb 9, 2018
 *      Author: mohragab
 */
#include "Macros.h"
#include "Std_Types.h"
#include "Dio.h"
#include "LCD_Interface.h"
#include "key_PAD_Interface.h"



void keypad_vidinit(void)
{
	Dio_vidSetPinDirection(ROW0_PORT,ROW0_PIN,STD_HIGH);//SET ROWS O/P
	Dio_vidSetPinDirection(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinDirection(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinDirection(ROW3_PORT,ROW3_PIN,STD_HIGH);

	Dio_vidSetPinDirection(COL0_PORT,COL0_PIN,STD_LOW);//SET COL INPUT
	Dio_vidSetPinValue(COL0_PORT,COL0_PIN,STD_HIGH);//make COL PULL UP

	Dio_vidSetPinDirection(COL1_PORT,COL1_PIN,STD_LOW);
	Dio_vidSetPinValue(COL1_PORT,COL1_PIN,STD_HIGH);

	Dio_vidSetPinDirection(COL2_PORT,COL2_PIN,STD_LOW);
	Dio_vidSetPinValue(COL2_PORT,COL2_PIN,STD_HIGH);

	Dio_vidSetPinDirection(COL3_PORT,COL3_PIN,STD_LOW);
	Dio_vidSetPinValue(COL3_PORT,COL3_PIN,STD_HIGH);

}

u8 key_PAD_U8Get_Key(void)
{
	u8 x=0;
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	x|=(Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x|=(Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x|=(Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x|=(Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);

	switch(x)
	{
	case 0x07:
		return'/';
	case 0x0B:
		return 3;
	case 0x0D:
		return 2;
	case 0x0E:
		return 1;

	}

	x=0;
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	x|=(Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x|=(Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x|=(Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x|=(Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);

	switch(x)
	{
	case 0x07:
		return'*';
	case 0x0B:
		return 6;
	case 0x0D:
		return 5;
	case 0x0E:
		return 4;

	}
	x=0;
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_LOW);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_HIGH);

	x|=(Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x|=(Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x|=(Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x|=(Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);

	switch(x)
	{
	case 0x07:
		return'+';
	case 0x0B:
		return 9;
	case 0x0D:
		return 8;
	case 0x0E:
		return 7;

	}
	x=0;
	Dio_vidSetPinValue(ROW0_PORT,ROW0_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW1_PORT,ROW1_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW2_PORT,ROW2_PIN,STD_HIGH);
	Dio_vidSetPinValue(ROW3_PORT,ROW3_PIN,STD_LOW);


	x|=(Dio_u8GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x|=(Dio_u8GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x|=(Dio_u8GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x|=(Dio_u8GetPinValue(COL3_PORT,COL3_PIN)<<3);

	switch(x)
	{
	case 0x07:
		return'-';
	case 0x0B:
		return '=';
	case 0x0D:
		return 0;
	case 0x0E:
		return 'c';

	}
	return 0xff;
}



