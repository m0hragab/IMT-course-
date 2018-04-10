/*
 * DIO.c
 *
 *  Created on: Jan 13, 2018
 *      Author: mohragab
 */
#include "DIO.h"
#include "MACROS.h"
#include "STD_TYPES.h"

void Dio_vidsetpinValue(u8 u8portNumberCpy,u8 u8pinNumberCpy,u8 u8ValueCpy)

{
	switch(u8portNumberCpy)
	{
	case Dio_PORTA:
		if(u8ValueCpy==STD_HIGH)
		{
			setbit(PORTA,u8pinNumberCpy);
		}
		else if(u8ValueCpy==STD_LOW)
		{
		  clearbit(PORTA,u8pinNumberCpy);
		}
	break;
	case Dio_PORTB:
			if(u8ValueCpy==STD_HIGH)
			{
				setbit(PORTB,u8pinNumberCpy);
			}
			else if(u8ValueCpy==STD_LOW)
			{
			  clearbit(PORTB,u8pinNumberCpy);
			}
		break;
	case Dio_PORTC:
				if(u8ValueCpy==STD_HIGH)
				{
					setbit(PORTC,u8pinNumberCpy);
				}
				else if(u8ValueCpy==STD_LOW)
				{
				  clearbit(PORTC,u8pinNumberCpy);
				}
			break;
	case Dio_PORTD:
					if(u8ValueCpy==STD_HIGH)
					{
						setbit(PORTD,u8pinNumberCpy);
					}
					else if(u8ValueCpy==STD_LOW)
					{
					  clearbit(PORTD,u8pinNumberCpy);
					}
				break;
	}
}
u8 Dio_u8GetpinValue(u8 u8portNumberCpy,u8 u8pinNumberCpy)
{
u8 u8returnvalue=0;
switch(u8portNumberCpy)
{

case Dio_PORTA:
	u8returnvalue=getbit(PINA, u8pinNumberCpy);

	break;
case Dio_PORTB:
	u8returnvalue=getbit(PINB, u8pinNumberCpy);
	break;
case Dio_PORTC:
	u8returnvalue=getbit(PINC, u8pinNumberCpy);
	break;
case Dio_PORTD:
	u8returnvalue=getbit(PIND, u8pinNumberCpy);
	break;
}
return u8returnvalue;
}

void Dio_vidsetpinDirection(u8 u8portNumber,u8 u8pinNumberCpy,u8 u8DirectionCpy)
{
	switch(u8portNumber)
	{

	case Dio_PORTA:
			if(u8DirectionCpy==0)
			{
			clearbit(DDRA,u8pinNumberCpy);
			}
			else if (u8DirectionCpy==1)
			{
			 setbit(DDRA,u8pinNumberCpy);
			}
			break;
	case Dio_PORTB:
			if(u8DirectionCpy==0)
			{
			clearbit(DDRB,u8pinNumberCpy);
			}
			else if (u8DirectionCpy==1)
			{
			 setbit(DDRB,u8pinNumberCpy);
			}
			break;
	case Dio_PORTC:
			if(u8DirectionCpy==0)
			{
			clearbit(DDRC,u8pinNumberCpy);
			}
			else if (u8DirectionCpy==1)
			{
			 setbit(DDRC,u8pinNumberCpy);
			}
			break;
	case Dio_PORTD:
			if(u8DirectionCpy==0)
			{
			clearbit(DDRD,u8pinNumberCpy);
			}
			else if (u8DirectionCpy==1)
			{
			 setbit(DDRD,u8pinNumberCpy);
			}
			break;
	}

}

void Dio_vidsetportDirection (u8 u8portNumberCpy,u8 u8ValueCpy)
{
	switch(u8portNumberCpy)
		{
		case Dio_PORTA:
			DDRA=u8ValueCpy;
			break;
		case Dio_PORTB:
				DDRB=u8ValueCpy;
				break;
		case Dio_PORTC:
				DDRC=u8ValueCpy;
				break;
		case Dio_PORTD:
				DDRD=u8ValueCpy;
				break;
		}
}

void Dio_vidsetportValue(u8 u8portNumberCpy,u8 u8ValueCpy)
{
switch (u8portNumberCpy)
{
case Dio_PORTA:
	PORTA=u8ValueCpy;
	break;
case Dio_PORTB:
	PORTB=u8ValueCpy;
	break;
case Dio_PORTC:
	PORTC=u8ValueCpy;
	break;
case Dio_PORTD:
	PORTD=u8ValueCpy;
	break;
}

}

u8 Dio_u8GetportValue(u8 u8portNumberCpy)
{
	switch(u8portNumberCpy)
	{
	case Dio_PORTA:
		return PINA;
		break;
	case Dio_PORTB:
			return PINB;
			break;
	case Dio_PORTC:
			return PINC;
			break;
	case Dio_PORTD:
			return PIND;
			break;
	default:
		return 0;
	}

}


