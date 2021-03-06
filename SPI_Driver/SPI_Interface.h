/*
 * SPI_Interface.h
 *
 *  Created on: Mar 3, 2018
 *      Author: mohragab
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



void SPI_VidMasterInit(void);
void SPI_VidSlaveInit(void);
u8 SPI_U8MasterTransferData(u8 Data);
u8 SPI_U8SlaveTransferData(u8 Data);
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK  7
#define dummy_data 0XFF
#endif /* SPI_INTERFACE_H_ */

