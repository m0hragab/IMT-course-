/*
 * Main.c
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

int main(void)
{
    u8 x;
	UART_VidInit();
	while(1)
	{
        x=UART_U8ReceiveByte();
        switch(x)
        {
        case'a':
        	UART_VidSendByte('a');
        	UART_VidSendByte('p');
        	UART_VidSendByte('p');
        	UART_VidSendByte('l');
        	UART_VidSendByte('e');
        	UART_VidSendByte('\n');
        }


	}



	return 0;
}




