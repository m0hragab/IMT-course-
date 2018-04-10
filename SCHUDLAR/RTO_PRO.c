/*
 * RTO_PRO.c
 *
 *  Created on: Mar 16, 2018
 *      Author: mohragab
 */
#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include<avr/io.h>
#include"util/delay.h"
#include"RTO_Interface.h"
u16 ovf_count=0;
TASK_TYPE * ARR_TASK[RTO_U8MAXTASK_NUM];
void RTO_VidInit(void)
{
	u8 i=0;
	TCCR0=0b00000001;//no prescaler 1024
	TCNT0=0;
	setbit(TIMSK,0); //ENABLE TIMER OVERFLOW//PIE enable
	setbit(SREG,7);
	for(i=0;i<RTO_U8MAXTASK_NUM;i++)
	{
		ARR_TASK[i]= RTO_NULL;
	}
}



void RTO_VidSCHEDULAR(void)
{
	u8 i=0;
	for(i=0;i<RTO_U8MAXTASK_NUM;i++)
	{
		if(ARR_TASK[i]!=RTO_NULL)
		{
			if(ARR_TASK[i]->state==RTO_u8TASK_RUNNING)
			{
				if(ARR_TASK[i]->first_delay==0)
				{
					ARR_TASK[i]->ptrfun();
					ARR_TASK[i]->first_delay=ARR_TASK[i]->priodicity-1;
				}
				else
				{
					ARR_TASK[i]->first_delay--;
				}
			}
		}
	}
}

void RTO_VidCreate(TASK_TYPE * TASKPTR,u8 TASK_PRIORITY)
{
	ARR_TASK[TASK_PRIORITY]=TASKPTR;
}

ISR(TIMER0_OVF_vect)
{
	ovf_count++;
	if(ovf_count==32)
	{
		ovf_count=0;
		TCNT0=192;
		RTO_VidSCHEDULAR();
	}
}

