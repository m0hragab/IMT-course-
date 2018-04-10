/*
 * LCD.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Toshiba
 */

#ifndef LCD_H_
#define LCD_H_

#define clear_display 0b00000001
#define return_home 0b00000010
#define entery_mode_set 0b00000110
#define display_on_off_control 0b00001100
#define function_set 0b00111000

#define RS 0
#define RW 1
#define E 2

void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8 u8CmdCpy);
void Lcd_vidWriteCharctr(u8 u8DataCpy);
void Lcd_vidWriteString(u8* pu8StringCpy);
void Lcd_vidGOTO(u8 row,u8 col);


#endif /* LCD_H_ */
