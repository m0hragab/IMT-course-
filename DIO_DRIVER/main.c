/*
 * main.c
 *
 *  Created on: Jan 6, 2018
 *      Author: mohragab
 */

#include"DIO.C"
#include<util/delay.h>
#include"DIO.h"
#include"STD_TYPES.h"
#include"MACROS.h"

int main(void)
{

	//Dio_vidsetpinDirection(Dio_PORTA,0,1);open led
	//switch
	Dio_vidsetpinDirection(Dio_PORTA,0,1);
	Dio_vidsetpinDirection(PORTA,3,0);
	Dio_vidsetpinValue(Dio_PORTA,3,1);
	while(1)
	{
		//Dio_vidsetpinValue(Dio_PORTA,0,1); open led

		if((Dio_u8GetpinValue(Dio_PORTA,3))==0)
		{
			Dio_vidsetpinValue(Dio_PORTA,0,1);
		}
		else if((Dio_u8GetpinValue(Dio_PORTA,3))==1)
		{
			Dio_vidsetpinValue(Dio_PORTA,0,0);
		}
	}



return 0;
}

