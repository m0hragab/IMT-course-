/*
 * led.h
 *
 *  Created on: Jan 4, 2018
 *      Author: mohragab
 */

#ifndef LED_H_
#define LED_H_
typedef char u8;
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

#endif /* LED_H_ */
