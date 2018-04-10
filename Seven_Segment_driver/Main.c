/*
 * Main.c
 *
 *  Created on: Mar 1, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "Seven_Segment_Interface.h"
#include<util/delay.h>

//Count from 0 to 9
int main(void)

{
	Seg_vidInit();
	u8 i;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			seg_VidDisplay(i);
			_delay_ms(1000);
		}
	}
	return 0;
}
