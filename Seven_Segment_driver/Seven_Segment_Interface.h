/*
 * Seven_Segment_Interface.h
 *
 *  Created on: Mar 1, 2018
 *      Author: mohragab
 */

#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

void Seg_vidInit(void);
void seg_VidDisplay(u8 u8DataCpy);
#define SEVEN_SEGMENT_DATA_PORT Dio_PORTB
#define SEVEN_SEGMENT_Ctrl_PORT Dio_PORTB
#define Val_port PORTB
#define SEG_d0 0
#define SEG_d1 1
#define SEG_d2 2
#define SEG_d3 3
#define SEG_d4 4
#define SEG_d5 5
#define SEG_d6 6
#define SEG_CRTL 7


#endif /* SEVEN_SEGMENT_INTERFACE_H_ */
