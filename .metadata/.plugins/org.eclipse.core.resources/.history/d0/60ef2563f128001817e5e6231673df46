/*
 * Delay_pro.c
 *
 *  Created on: Feb 17, 2018
 *      Author: mohragab
 */

#include "Dio.h"
#include"Macros.h"
#include"Std_Types.h"
#include"util/delay.h"
#include<avr/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#include"util/delay.h"
#include"Delay_interface.h"

extern u32 Desired_Time;
extern u8 End_Flag;

void HI_Delay(u32 Time)
{



TCCR0=0b00000001;//no prescaler 1024
TCNT0=0;
setbit(SREG,7);
setbit(TIMSK,0); //ENABLE TIMER OVERFLOW//PIE enable
Desired_Time=0;
End_Flag=0;
Desired_Time=Time;
while(End_Flag==0);
End_Flag=0;
clearbit(TIMSK,0); //pie Disabled

}














