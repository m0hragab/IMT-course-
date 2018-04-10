/*
 * LCD_Interface.h
 *
 *  Created on: Feb 3, 2018
 *      Author: mohragab
 */


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_DATA_PORT Dio_PORTB
#define LCD_CTRL_PORT Dio_PORTA
#define lcd_d0 0
#define lcd_d1 1
#define lcd_d2 2
#define lcd_d3 3
#define lcd_d4 4
#define lcd_d5 5
#define lcd_d6 6
#define lcd_d7 7
#define RS 0
#define RW 1
#define E 2
#define LCD_8MODE_2L 0x38
#define LCD_ON_NOCURSER 0x0c
#define LCD_CLEAR_SCREEN 0x01

void lcd_vidinit(void);
void lcd_vidsendcommand(u8 comand);
void lcd_vidwritechar(u8 data);
void Lcd_vidWriteString(u8* pu8StringCpy);
void Lcd_vidGOTO(u8 row,u8 col);
#endif /* LCD_INTERFACE_H_ */
