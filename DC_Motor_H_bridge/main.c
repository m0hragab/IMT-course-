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

	 Dio_vidsetportDirection (Dio_PORTD,0xff) ;
	 Dio_vidsetportValue(Dio_PORTD,0xFF) ;

	while(1)
	{

		Dio_vidsetpinValue(Dio_PORTD,0,STD_HIGH) ;
		Dio_vidsetpinValue(Dio_PORTD,1,STD_HIGH) ;
		Dio_vidsetpinValue(Dio_PORTD,2,STD_LOW) ;
	    Dio_vidsetpinValue(Dio_PORTD,3,STD_LOW) ;
	    _delay_ms(2000);
	    Dio_vidsetpinValue(Dio_PORTD,0,STD_LOW) ;
	    Dio_vidsetpinValue(Dio_PORTD,1,STD_LOW) ;
	    Dio_vidsetpinValue(Dio_PORTD,2,STD_HIGH) ;
	    Dio_vidsetpinValue(Dio_PORTD,3,STD_HIGH) ;
	    _delay_ms(2000);

	}

return 0;
}
