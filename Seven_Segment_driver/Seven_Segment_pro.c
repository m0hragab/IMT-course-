/*
 * Seven_Segment_pro.c
 *
 *  Created on: Mar 1, 2018
 *      Author: mohragab
 */
#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "Seven_Segment_Interface.h"
#include <util/delay.h>

void Seg_vidInit(void)
{
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d0,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d1,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d2,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d3,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d4,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d5,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_DATA_PORT,SEG_d6,STD_HIGH);
	Dio_vidSetPinDirection(SEVEN_SEGMENT_Ctrl_PORT,SEG_CRTL,STD_HIGH);
	Dio_vidSetPinValue(SEVEN_SEGMENT_Ctrl_PORT,SEG_CRTL,STD_HIGH);
}

void seg_VidDisplay(u8 u8DataCpy)
{
	u8 const arr[10]={0XA0,0XF9,0XC4,0XD0,0X99,0X92,0X82,0XF8,0X80,0X90};
	Val_port=arr[u8DataCpy];
}

