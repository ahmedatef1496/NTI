/*
 * LCD_interface.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef LCD_INERFACE_H_
#define LCD_INERFACE_H_

#include "../../MCAL/GPIO/GPIO_interface.h"

void LCD_Init(void);
 void LCD_WriteChar(u8 ch);
 void LCD_WriteString(u8*str);
 void LCD_WriteNumber(s32 num);
 void LCD_WriteBinary(u8 num);
 void LCD_WriteHex(u8 num);
 void LCD_SetCursor(u8 line,u8 cell);
 void LCD_Clear(void);
 void LCD_ClearLoc(u8 line ,u8 cell,u8 num);
 void LCD_WriteNumber_3D(u16 num);
 void LCD_CustomChar(u8 loc,u8*pattern);
 void LCD_DisplayFloat(f32 f32_a_number);

void LCD_PinsInit ();

void LCD4_SetCursor(u8 line,u8 cell);
void LCD4_ClearLoc(u8 line ,u8 cell,u8 num);

#endif /* LCD_INERFACE_H_ */
