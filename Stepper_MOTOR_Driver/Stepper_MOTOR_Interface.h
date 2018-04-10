/*
 * Stepper_MOTOR_Interface.h
 *
 *  Created on: Mar 7, 2018
 *      Author: mohragab
 */

#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_

void STEPPER_MOTOR_vidinit(u8 portnum);
void STEPPER_MOTOR_vidturnright(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2,u8 portnum3,u8 pinnum3,u8 portnum4,u8 pinnum4);
void STEPPER_MOTOR_vidturnleft(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2,u8 portnum3,u8 pinnum3,u8 portnum4,u8 pinnum4);
void STEPPER_MOTOR_vidstop(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2,u8 portnum3,u8 pinnum3,u8 portnum4,u8 pinnum4);
//void STEPPER_MOTOR_vidbreak(u8 portnum1,u8 pinnum1,u8 portnum2,u8 pinnum2,u8 portnum3,u8 pinnum3,u8 portnum4,u8 pinnum4);

#endif /* STEPPER_MOTOR_INTERFACE_H_ */
