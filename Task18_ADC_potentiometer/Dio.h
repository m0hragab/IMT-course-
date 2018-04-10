/*
 * Dio.h
 *This file includes:
 *	>> Dio Interfaces prototypes
 *	>> Ports definitions ex: #define DIO_PORTA 0 … B 1
 *	>> Registers Definitions ex: #define PORTA (*((u8*)0x3B)))
 *	>> Pins definitions ex: #define PIN0 0 ,... ,etc
 *  Created on: 6/1/2018
 *      Author: Asmaa
 */

#ifndef DIO_H_
#define DIO_H_

/*****Dio Interfaces prototypes*****/

/* Interface to set the value of output pin in port */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);
/* Interface to get the value of input pin in port */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);
/* Interface to set the direction of pin in port */
void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy,u8 u8DirectionCpy);
/* Interface to set the direction of port */
void Dio_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy);
/* Interface to set the output value of port */
void Dio_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy);
/* Interface to get the input value on port */
u8 Dio_u8GetPortValue(u8 u8PortNumberCpy);

/****** Ports definitions *****/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/****** Registers Definitions ******/
#define PORTA  *((u8*)0X3B)  /*output register in case of output & input mode in case of input */
#define DDRA  *((u8*)0X3A)   /*data direction register*/
#define PINA  *((u8*)0X39)   /*input register*/

#define PORTB  *((u8*)0X38)
#define DDRB  *((u8*)0X37)
#define PINB  *((u8*)0X36)

#define PORTC  *((u8*)0X35)
#define DDRC  *((u8*)0X34)
#define PINC  *((u8*)0X33)

#define PORTD  *((u8*)0X32)
#define DDRD  *((u8*)0X31)
#define PIND  *((u8*)0X30)

/****** Pins definitions ******/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif /* DIO_H_ */
