/*
 * DC_MOTOR_Interface.h
 *
 *  Created on: Feb 2, 2018
 *      Author: mohragab
 */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
void DC_MOTOR_vidinit(u8 portnum);
void DC_MOTOR_vidturnright(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2);//1,0
void DC_MOTOR_vidturnleft(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2);//0,1
void DC_MOTOR_vidstop(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2);//0,0
void DC_MOTOR_vidbreak(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2);//1,1

#endif /* DC_MOTOR_INTERFACE_H_ */
