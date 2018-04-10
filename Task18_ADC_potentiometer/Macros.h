/*
 * Macros.h
 *This file includes:
 *	>> #define SET_BIT(Byte,Pos) ,CLEAR_BIT(Byte,Pos) and TOGGLE_BIT(Byte,Pos)
 *	>> #define SET_BYTE(Byte) and CLEAR_BYTE(Byte)
 *	>> #define SET_NIBBLE_HIGH(Byte), SET_NIBBLE_LOW(Byte) ,CLEAR_NIBBLE_HIGH(Byte)
 *	and CLEAR_NIBBLE_LOW(Byte)
 *	>> #define GET_BIT(Reg,Bit)
 *  Created on: 6/1/2017
 *      Author: Asmaa
 */

#ifndef MACROS_H_
#define MACROS_H_

/* for one Bit */
#define SET_BIT(Byte,Pos)  Byte|=(1<<Pos)
#define CLEAR_BIT(Byte,Pos)  Byte&=(~(1<<Pos))
#define TOGGLE_BIT(Byte,Pos)  Byte^=(1<<Pos)

/*for all byte */
#define SET_BYTE(Byte)  Byte|=(0xFF)
#define CLEAR_BYTE(Byte)  Byte&=(0x00)

/*for half of a byte */
#define SET_NIBBLE_HIGH(Byte)  Byte|=(0xF0)
#define SET_NIBBLE_LOW(Byte)  Byte|=(0x0F)
#define CLEAR_NIBBLE_HIGH(Byte)  Byte&=(0x0F)
#define CLEAR_NIBBLE_LOW(Byte)  Byte&=(0xF0)

/* to read input bit */
#define GET_BIT(Reg,Bit)  (Reg>>Bit)&1           /*(Reg&(1<<Bit))>>Bit is another logic*/

#endif /* MACROS_H_ */
