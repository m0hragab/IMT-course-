/*
 * interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asmaa
 */

#include<avr/interrupt.h>
#include<util/delay.h>
#include"Std_Types.h"
#include"Dio.h"
#include"Macros.h"

/*ADMUX register pins*/
#define REFS1 PIN7
#define REFS0 PIN6
#define ADLAR PIN5
#define MUX2 PIN2
#define MUX1 PIN1
#define MUX0 PIN0

/*ADCSRA register pins (control status register */
#define ADEN PIN7
#define ADSC PIN6
#define ADIF PIN4
#define ADIE PIN3
#define ADPS2 PIN2
#define ADPS1 PIN1
#define ADPS0 PIN0

/*SREG register */
#define GIE PIN7

u8 GLOBAL_u8ReadValue=0x00;

int main(void)
{
	Dio_vidSetPortDirection(DIO_PORTC,0xFF);   //LEDS OUTPUTS
	Dio_vidSetPinDirection(DIO_PORTA,PIN4,STD_LOW);   //ANALOG PINS

	//ADC registers setup

	/* reference mode is 01 (AVCC with external capacitor at AREF pin) */
	CLEAR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

	/*Analog Channel Selection Bits:100(port A CH4)*/
	SET_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX0);

	/*ADLAR bit : ADC Left Adjust Result (Write one to left adjust the result)*/
	SET_BIT(ADMUX,ADLAR);

	/*ADPS2:0: ADC Prescaler Select Bits(selected prescaler is 64>>(110) */
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS0);

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);

	/*ADC Interrupt Enable*/
	SET_BIT(ADCSRA,ADIE);

	/*Global Interrupt Enable */
	SET_BIT(SREG,GIE);

	/*ADC Start Conversion*/
	SET_BIT(ADCSRA,ADSC);

	while(1)
	{
		PORTC=GLOBAL_u8ReadValue;
		_delay_ms(500);
		/*ADC Start Conversion*/
		SET_BIT(ADCSRA,ADSC);
	}
	return 0;
}
ISR(ADC_vect)
{
	GLOBAL_u8ReadValue=ADCH;
}
