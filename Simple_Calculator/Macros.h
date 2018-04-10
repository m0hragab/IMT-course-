/*
 * macros.h
 *
 *  Created on: Jan 6, 2018
 *      Author: Toshiba
 */

#ifndef MACROS_H_
#define MACROS_H_

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=(~(1<<bit))
#define getbit(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(Reg,bit)	Reg^=(1<<bit)
#define SET_PORT(Reg)		Reg=0xFF
#define CLEAR_PORT(Reg)		Reg=0x00
#define TOGGLE_PORT(Reg)	Reg=~Reg
#endif /* MACROS_H_ */
