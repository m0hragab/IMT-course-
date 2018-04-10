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

#endif /* MACROS_H_ */
