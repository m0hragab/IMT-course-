/*
 * SPI_por.c
 *
 *  Created on: Mar 3, 2018
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
#include "SPI_Interface.h"

void SPI_VidMasterInit(void)
{
	Dio_vidSetPinDirection(Dio_PORTB,SS,STD_HIGH);//O/P
	Dio_vidSetPinDirection(Dio_PORTB,MOSI,STD_HIGH);//O/P
	Dio_vidSetPinDirection(Dio_PORTB,MISO,STD_LOW);//I/P
	Dio_vidSetPinDirection(Dio_PORTB,SCK,STD_HIGH);//O/P
	setbit(SPCR,6);//SPE

	setbit(SPCR,4);//Master

	clearbit(SPCR,5);//DORD

	setbit(SPCR,3);//CPOL
	setbit(SPCR,2);//CPHA

	setbit(SPCR,1);//SPR1
	setbit(SPCR,0);//SPR0

}



void SPI_VidSlaveInit(void)
{
	Dio_vidSetPinDirection(Dio_PORTB,SS,STD_LOW);//I/P
	Dio_vidSetPinValue(Dio_PORTB,SS,STD_HIGH);
	Dio_vidSetPinDirection(Dio_PORTB,MOSI,STD_LOW);//I/P
	Dio_vidSetPinDirection(Dio_PORTB,MISO,STD_HIGH);//O/P
	Dio_vidSetPinDirection(Dio_PORTB,SCK,STD_LOW);//I/P
	setbit(SPCR,6);//SPE
	clearbit(SPCR,5);//DORD
	clearbit(SPCR,4);//SLAVE
	setbit(SPCR,1);//SPR1/div128
	setbit(SPCR,0);//SPR0/div 128
	setbit(SPCR,3);//CPOL
	setbit(SPCR,2);//CPHA
}

u8 SPI_U8MasterTransferData(u8 Data)
{
	Dio_vidSetPinValue(Dio_PORTB,4,STD_LOW);
	SPDR=Data;
	while(getbit(SPSR,7)==0);
	Dio_vidSetPinValue(Dio_PORTB,4,STD_HIGH);
	return SPDR;
}


u8 SPI_U8SlaveTransferData(u8 Data)
{

	SPDR=Data;
	while(getbit(SPSR,7)==0);
	return SPDR;
}
