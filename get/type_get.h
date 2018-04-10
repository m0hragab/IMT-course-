/*
 * type_get.h
 *
 *  Created on: Jan 5, 2018
 *      Author: mohragab
 */

#ifndef TYPE_GET_H_
#define TYPE_GET_H_
#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=(~(1<<bit))
#define getbit(reg,bit) ((reg>>bit)&1)
#endif /* TYPE_GET_H_ */
