
#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#include "LCD.h"

u8 reading=0;


int main(void)
{
	//Dio_vidSetPortDirection(Dio_PORTB,0xff);
    //Dio_vidSetPortDirection(Dio_PORTA,0x00);
	u8 analog;
	MCUCR=0b00000011;//enable ISC/INT0
	GICR=0b01000000;//enable PIE/INT0
	SREG=0b10000000;//enable Global interrupt/INT0
	Dio_vidSetPinDirection(Dio_PORTD,2,STD_LOW);//MAKE PIN INPUT PORT D2//PULL UP
	Dio_vidSetPinValue(Dio_PORTD,2,STD_HIGH);//SET PIN TO HIGH D2// PULL UP
	clearbit(ADMUX,7);//SAME VREF as VCC
	setbit(ADMUX,6);//SAME VREF as VCC
	setbit(ADMUX,5);//LEFT ADDJUSTED
	setbit(ADCSRA,7);//ENABLE ADC
	clearbit(ADCSRA,6);//DISABLE START CONVERSION
	setbit(ADCSRA,5);//ENABLE AUTO TRIGGER
	setbit(ADCSRA,4);//INTERRUPT FLAG
	setbit(ADCSRA,3);//INTERRUPT ENABLE
	setbit(ADCSRA,2);//PRESCALLER 128
	setbit(ADCSRA,1);//PRESCALLER 128
	setbit(ADCSRA,0);//PRESCALLER 128
	clearbit(SFIOR,7);
	setbit(SFIOR,6);
	clearbit(SFIOR,5);


while(1)
{

	analog=(reading*5)/256;

	if(analog>2)
	{
		Dio_vidSetPinValue(Dio_PORTB,0,STD_HIGH);
		Dio_vidSetPinValue(Dio_PORTB,1,STD_LOW);

	}

	else
	{
		Dio_vidSetPinValue(Dio_PORTB,0,STD_LOW);
		Dio_vidSetPinValue(Dio_PORTB,1,STD_HIGH);
	}
}




	return 0;
}

ISR(INT0_vect)
{

}

ISR(ADC_vect)
{
	reading=ADCH;
}
