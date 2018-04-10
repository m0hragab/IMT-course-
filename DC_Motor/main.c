/*
 * main.c
 *
 *  Created on: Jan 13, 2018
 *      Author: mohragab
 */



#include <util/delay.h>
#include"STD_TYPES.h"
#include"DIO.h"
#include "MACROS.h"

int main(void)
{

	 Dio_vidsetportDirection (Dio_PORTB,0xff) ;
	 Dio_vidsetportValue(Dio_PORTB,0xFF) ;

	while(1)
	{
		u8 i;
		for(i=0;i<=10;i++)
		{
		Dio_vidsetpinValue(Dio_PORTB,0,STD_HIGH) ;
		Dio_vidsetpinValue(Dio_PORTB,1,STD_LOW) ;
		_delay_ms(500);
		Dio_vidsetpinValue(Dio_PORTB,0,STD_LOW) ;
		Dio_vidsetpinValue(Dio_PORTB,1,STD_HIGH);
		_delay_ms(500);
		if(i==10)
			break;
	    }
		Dio_vidsetpinValue(Dio_PORTB,0,STD_LOW) ;
		Dio_vidsetpinValue(Dio_PORTB,1,STD_LOW) ;
		_delay_ms(2000);
	}

return 0;
}
