/*
 * Main.c
 *
 *  Created on: Mar 10, 2018
 *      Author: mohragab
 */


#include"Macros.h"
#include"Std_Types.h"
#include"Dio.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"LCD_Interface.h"
#include"TWI_Interface.h"
#include "EEPROM_Interface.h"

/*int main(void)
{
	u8 arr[100]="Mohragab";
	lcd_vidinit();
	EEPROM_VidInit();
	u8 i=0;
	while(i!='0')
	{
		EEPROM_U8WriteByte(i,arr[i]);
		i++;
		_delay_ms(50);
	}

	while (1);
	return 0;
}*/


int main(void)
{

	u8 receiveddata;
	lcd_vidinit();
	EEPROM_VidInit();
	u8 i=0;
	while((i!='0')&&(i<8))
	{
		EEPROM_U8ReadByte(i,&receiveddata);
		lcd_vidwritechar(receiveddata);
		i++;
		_delay_ms(50);
	}

	while(1);


	return 0;
}

