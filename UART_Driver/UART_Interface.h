/*
 * UART_Interface.h
 *
 *  Created on: Mar 2, 2018
 *      Author: mohragab
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
void UART_VidInit(void);
void UART_VidSendByte(u8 Byte);
u8 UART_U8ReceiveByte(void);

#endif /* UART_INTERFACE_H_ */
