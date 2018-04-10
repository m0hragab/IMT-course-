/*
 * EEPROM_Interface.h
 *
 *  Created on: Mar 10, 2018
 *      Author: mohragab
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_VidInit(void);
u8 EEPROM_U8WriteByte(u16 LOCATION,u8 Byte);
u8 EEPROM_U8ReadByte(u16 LOCATION,u8 * Byte);

#endif /* EEPROM_INTERFACE_H_ */
