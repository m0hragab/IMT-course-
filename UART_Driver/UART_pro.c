/*
 * UART_pro.c
 *
 *  Created on: Mar 2, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>
#include <util/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include "UART_Interface.h"

void UART_VidInit(void)
{
	setbit(UCSRB,4);//RX_EN
	setbit(UCSRB,3);//tx_en
	setbit(UCSRC,2);//UCSZ1
	setbit(UCSRC,1);//UCSZ0
	clearbit(UCSRA,2);//UCSZ2
	UBRRH=0;
	UBRRL=51;

}

void UART_VidSendByte(u8 Byte)
{
	while(getbit(UCSRA,5)==0);//CONFIRM REGISITER CLEAR
	UDR=Byte;
}


u8 UART_U8ReceiveByte(void)
{
	while(getbit(UCSRA,7)==0);
	return UDR;
}
