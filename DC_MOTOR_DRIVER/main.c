/*
 * main.c
 *
 *  Created on: Feb 2, 2018
 *      Author: mohragab
 */
#include "DIO.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "DC_MOTOR_Interface.h"
#include<util/delay.h>

int main(void)
{

	DC_MOTOR_vidinit(Dio_PORTA);

	while(1)
	{
       DC_MOTOR_vidturnright(Dio_PORTA,0,Dio_PORTA,1);
       _delay_ms(1000);
       DC_MOTOR_vidstop(Dio_PORTA,0,Dio_PORTA,1);
       _delay_ms(5000);
       DC_MOTOR_vidturnleft(Dio_PORTA,0,Dio_PORTA,1);
       _delay_ms(1000);
       DC_MOTOR_vidbreak(Dio_PORTA,0,Dio_PORTA,1);
       _delay_ms(1000);

	}





	return 0;
}

