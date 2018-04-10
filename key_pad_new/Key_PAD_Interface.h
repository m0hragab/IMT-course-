/*
 * Key_PAD_Interface.h
 *
 *  Created on: Feb 9, 2018
 *      Author: mohragab
 */

#ifndef KEY_PAD_INTERFACE_H_
#define KEY_PAD_INTERFACE_H_
#define ROW0_PORT Dio_PORTB
#define ROW0_PIN 0
#define ROW1_PORT Dio_PORTB
#define ROW1_PIN 1
#define ROW2_PORT Dio_PORTB
#define ROW2_PIN 2
#define ROW3_PORT Dio_PORTB
#define ROW3_PIN 3
#define COL0_PORT Dio_PORTB
#define COL0_PIN 4
#define COL1_PORT Dio_PORTB
#define COL1_PIN 5
#define COL2_PORT Dio_PORTB
#define COL2_PIN 6
#define COL3_PORT Dio_PORTB
#define COL3_PIN 7
void keypad_vidinit(void);
u8 keyPAD_U8GetKey(void);
#endif /* KEY_PAD_INTERFACE_H_ */
