/*
 * led.h
 *
 *  Created on: Jan 4, 2018
 *      Author: mohragab
 */
#include "STD_TYPES.h"
#ifndef DIO_H_
#define DIO_H_
#define PORTA (*(u8*)0x3B)
#define DDRA (*(u8*)0x3A)
#define PINA (*(u8*)0x39)
#define PORTB (*(u8*)0x38)
#define DDRB (*(u8*)0x37)
#define PINB (*(u8*)0x36)
#define PORTC (*(u8*)0x35)
#define DDRC (*(u8*)0x34)
#define PINC (*(u8*)0x33)
#define PORTD (*(u8*)0x32)
#define DDRD (*(u8*)0x31)
#define PIND (*(u8*)0x30)
#define Dio_PORTA 0
#define Dio_PORTB 1
#define Dio_PORTC 2
#define Dio_PORTD 3
//interface to set the value of the output pin in port
void Dio_vidsetpinValue(u8 u8portNumberCpy,u8 u8pinNumberCpy,u8 u8ValueCpy);
//interface to get the value of input pin in port
u8 Dio_u8GetpinValue(u8 u8portNumberCpy,u8 u8pinNumberCpy);
//interface to set the direction of pin in port
void Dio_vidsetpinDirection(u8 u8portNumber,u8 u8pinNumberCpy,u8 u8DirectionCpy);
//interface to set port direction
void Dio_vidsetportDirection (u8 u8portNumberCpy,u8 u8ValueCpy);
//interface to set the output value of port
void Dio_vidsetportValue(u8 u8portNumberCpy,u8 u8ValueCpy);
//interface to get the input value on port
u8 Dio_u8GetportValue(u8 u8portNumberCpy);


#endif /* DIO_H_ */
