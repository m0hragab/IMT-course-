/*
 * Main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: mohragab
 */
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
//Control intenisity of light
int main(void)
{
TCCR0=0b01101001;
TCNT0=0;
OCR0=90;
DDRB=0XFF;//oc0 b3 pwm signal
while(1);





	return 0;

}
