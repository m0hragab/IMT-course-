/*

 * main.c
 *
 *  Created on: Feb 17, 2018
 *      Author: mohragab
 */
#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
#include"Delay_interface.h"

u32 Desired_Time=0;
u8 End_Flag=0;
u32 MS_VAR=0;
u16 ovf_count=0;

int main(void)
{

	Dio_vidSetPinDirection(Dio_PORTB,2,STD_HIGH);
	Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);


	while(1)
	{

		Dio_vidSetPinValue(Dio_PORTB,2,STD_HIGH);
		HI_Delay(5000);
		Dio_vidSetPinValue(Dio_PORTB,2,STD_LOW);
		HI_Delay(5000);


	}
	return 0;

}

ISR(TIMER0_OVF_vect)
{
	ovf_count++;
	if(ovf_count==32)
	{
		ovf_count=0;
		TCNT0=192;
		MS_VAR++;
		if(MS_VAR==Desired_Time)
		{
			MS_VAR=0;
			End_Flag=1;

		}
	}
}

