/*
 * TWI_Interface.h
 *
 *  Created on: Mar 10, 2018
 *      Author: mohragab
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
#define START_CONDITION 0X08
#define REPEATED_START 0X10
#define SLA_W_ACK 0X18
#define SLA_R_ACK 0X40
#define DATA_TX_ACK 0X28
void TWI_VidInit(void);
void TWI_VidSendStart(void);
void TWI_VidSendByte(u8 Byte);
void TWI_VidSendStop(void);
u8 TWI_U8ReceivewithnoACK(void);
u8 TWI_u8CheckAck(u8 ACK);
#endif /* TWI_INTERFACE_H_ */
