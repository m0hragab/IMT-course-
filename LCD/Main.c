/*
 * Main.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Toshiba
 */
#include"Dio.h"
#include"LCD.h"
#include "Macros.h"
#include"Std_Types.h"
#include <util/delay.h>




int main (void)
{

while(1)
{

	u8 line1[]="GOOD MORNING";
	u8 line2[]="Have a nice day :)";
	Lcd_vidInit();
	 _delay_ms(500);
	 Lcd_vidGOTO(1,0);
	 _delay_ms(500);
     Lcd_vidWriteString(line1);
     _delay_ms(500);
     Lcd_vidGOTO(2,0);
     _delay_ms(200);
     Lcd_vidWriteString(line2);
     _delay_ms(500);

}


return 0;
}

