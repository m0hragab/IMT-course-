/*
 * main.c
 *
 *  Created on: Jan 4, 2018
 *      Author: mohragab
 */
#include"led.h"
#include<util/delay.h>
#include<avr/io.h>

int main(void)
{
DDRB = 0b11111111;
u8 i =0;
while(1)
{
PORTB = 0b11111111;
_delay_ms(500);
for(i=0;i<8;i++)
{

  PORTB = 0b00000001<<(i);
  _delay_ms(500);
}
PORTB = 0b00000000;
_delay_ms(500);
for(i=0;i<8;i++)
{
	PORTB = 0b10000000>>(i);
	_delay_ms(500);
}
PORTB = 0b00000000;
_delay_ms(500);
}

return 0;

}

