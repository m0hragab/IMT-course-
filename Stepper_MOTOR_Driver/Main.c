/*
 * Main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: mohragab
 */

#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
#include "Dio.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "Stepper_MOTOR_Interface.h"




int main(void)
{
	STEPPER_MOTOR_vidinit(Dio_PORTB);

	while(1)
	{

		STEPPER_MOTOR_vidturnright(Dio_PORTB,0,Dio_PORTB,1,Dio_PORTB,2,Dio_PORTB,3);
		//STEPPER_MOTOR_vidstop(Dio_PORTB,0,Dio_PORTB,1,Dio_PORTB,2,Dio_PORTB,3);
		STEPPER_MOTOR_vidturnleft(Dio_PORTB,0,Dio_PORTB,1,Dio_PORTB,2,Dio_PORTB,3);

	}

	return 0;
}
