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
#define ROW_INIT   0

#define ROW_FIN    4

#define COL_INIT   4

#define COL_FIN    8

#define NOT_PRESSED    0
#endif /* MACROS_H_ */
