/*
 * DC_MOTOR_Pro.c
 *
 *  Created on: Feb 2, 2018
 *      Author: mohragab
 */
#include "MACROS.h"
#include "STD_TYPES.h"
#include "DIO.h"


void DC_MOTOR_vidinit(u8 portnum)
{
	Dio_vidsetportDirection(portnum,0xff) ;
	Dio_vidsetportValue(portnum,0xFF) ;
}

void DC_MOTOR_vidturnright(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2)
{
	Dio_vidsetpinValue(portnum1,pinnum1,STD_HIGH) ;
	Dio_vidsetpinValue(portnum2,pinnum2,STD_LOW) ;
}

void DC_MOTOR_vidturnleft(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2)
{
	Dio_vidsetpinValue(portnum1,pinnum1,STD_LOW) ;
	Dio_vidsetpinValue(portnum2,pinnum2,STD_HIGH) ;
}

void DC_MOTOR_vidstop(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2)
{
	Dio_vidsetpinValue(portnum1,pinnum1,STD_LOW) ;
	Dio_vidsetpinValue(portnum2,pinnum2,STD_LOW) ;
}

void DC_MOTOR_vidbreak(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2)
{
	Dio_vidsetpinValue(portnum1,pinnum1,STD_HIGH) ;
	Dio_vidsetpinValue(portnum2,pinnum2,STD_HIGH) ;
}
