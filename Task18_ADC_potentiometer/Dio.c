/*
 * Dio.c
 *This file includes:
 *	>> Dio Interfaces functions implementations
 *  Created on: 6/1/2018
 *      Author: Asmaa
 */

/* include required header files */
#include"Std_Types.h"
#include"Dio.h"
#include"Macros.h"

/* Interface to set the value of output pin in port */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			if(u8ValueCpy==1)
			{
				SET_BIT(PORTA, u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTA, u8PinNumberCpy);
			}
			break;

		case DIO_PORTB:
			if(u8ValueCpy==1)
			{
				SET_BIT(PORTB, u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTB, u8PinNumberCpy);
			}
			break;

		case DIO_PORTC:
			if(u8ValueCpy==1)
			{
				SET_BIT(PORTC, u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTC, u8PinNumberCpy);
			}
			break;

		case DIO_PORTD:
			if(u8ValueCpy==1)
			{
				SET_BIT(PORTD, u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTD, u8PinNumberCpy);
			}
			break;
		}
}

/* Interface to get the value of input pin in port */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy)
{
	u8 result;
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			result=GET_BIT(PINA,u8PinNumberCpy);
			break;

		case DIO_PORTB:
			result=GET_BIT(PINB,u8PinNumberCpy);
			break;

		case DIO_PORTC:
			result=GET_BIT(PINC,u8PinNumberCpy);
			break;

		case DIO_PORTD:
			result=GET_BIT(PIND,u8PinNumberCpy);
			break;
	}
	return result;
}

/* Interface to set the direction of pin in port */
void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy,u8 u8DirectionCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			if(u8DirectionCpy==1)
			{
				SET_BIT(DDRA,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRA,u8PinNumberCpy);
			}
			break;

		case DIO_PORTB:
			if(u8DirectionCpy==1)
			{
				SET_BIT(DDRB,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRB,u8PinNumberCpy);
			}
			break;

		case DIO_PORTC:
			if(u8DirectionCpy==1)
			{
				SET_BIT(DDRC,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRC,u8PinNumberCpy);
			}
			break;

		case DIO_PORTD:
			if(u8DirectionCpy==1)
			{
				SET_BIT(DDRD,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRD,u8PinNumberCpy);
			}
			break;
	}
}

/* Interface to set the direction of port */
void Dio_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			DDRA=u8ValueCpy;
			break;

		case DIO_PORTB:
			DDRB=u8ValueCpy;
			break;

		case DIO_PORTC:
			DDRC=u8ValueCpy;
			break;

		case DIO_PORTD:
			DDRD=u8ValueCpy;
			break;
	}
}

/* Interface to set the output value of port */
void Dio_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			PORTA=u8ValueCpy;
			break;

		case DIO_PORTB:
			PORTB=u8ValueCpy;
			break;

		case DIO_PORTC:
			PORTC=u8ValueCpy;
			break;

		case DIO_PORTD:
			PORTD=u8ValueCpy;
			break;
	}
}

/* Interface to get the input value on port */
u8 Dio_u8GetPortValue(u8 u8PortNumberCpy)
{
	u8 result;
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			result=PINA;
			break;

		case DIO_PORTB:
			result=PINB;
			break;

		case DIO_PORTC:
			result=PINC;
			break;

		case DIO_PORTD:
			result=PIND;
			break;
	}
	return result;
}

