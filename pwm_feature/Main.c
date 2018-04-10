/*
 * Main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#include "LCD_Interface.h"

u8 volatile first_reading=0;
u8 volatile state;
u32 volatile ovf_count=0;
f32 volatile TON;
f32 volatile TOFF;
u16 volatile freq;
u8 volatile duty;
f32 volatile Ttot;


int main(void)
{
	Dio_vidSetPinDirection(Dio_PORTD,6,STD_LOW);//INPUT SIGNAL SET PIN TO INPUT
	Dio_vidSetPinValue(Dio_PORTD,6,STD_LOW);//ICB
	u8 F[]="freq= ";
	u8 D[]="Duty= ";
	u8 HZ[]="Hz";

	lcd_vidinit();
	TCCR1A=0;
	TCCR1B=0B01000001;//RISINIG EDGE
	setbit(TIMSK,5);//INPUT CAPTURE INT ENABLE
	setbit(TIMSK,2);//TIMER/COUNTER1/OVF INT ENABLE
	setbit(SREG,7);//GLOBAL INTERUPT
	while(1)
	{
		Ttot=TON+TOFF;
		freq=(u16)((f32)1/Ttot);
		duty=((f32)TON/Ttot)* 100;
		Lcd_vidGOTO(1,0);
		Lcd_vidWriteString(F);
		lcd_vidwritechar(((u8)(freq/100)) +'0');
		lcd_vidwritechar(((u8)(freq%100)/10) +'0');
		lcd_vidwritechar(((u8)(freq%100)%10) +'0');
		Lcd_vidWriteString(HZ);
		Lcd_vidGOTO(2,0);
		Lcd_vidWriteString(D);
		lcd_vidwritechar(((u8)(duty/100)) +'0');
		lcd_vidwritechar(((u8)(duty%100)/10) +'0');
		lcd_vidwritechar(((u8)(duty%100)%10) +'0');
		lcd_vidwritechar('%');

	}

	return 0;
}


ISR(TIMER1_CAPT_vect)
{
	if(first_reading==0)
	{
		TCNT1=0;
		clearbit(TCCR1B,6);//CHANGE SOURCE RAISING OR FALLING
		first_reading=1;
		state=1;
		ovf_count=0;
	}
	else
	{
		if(state==1)
		{
			TON=(f32)((ICR1+(ovf_count*65536))*(f32)((f32)1/8000000));
			state=0;
			ovf_count=0;
			setbit(TCCR1B,6);//CHANGE SOURCE RAISING OR FALLING
			TCNT1=0;
		}
		else
		{
			TOFF=(f32)((ICR1+(ovf_count*65536))*(f32)((f32)1/8000000));
			state=1;
			ovf_count=0;
			clearbit(TCCR1B,6);//"change source"
			TCNT1=0;

		}
	}
}

ISR(TIMER1_OVF_vect)
{
	ovf_count++;
}



