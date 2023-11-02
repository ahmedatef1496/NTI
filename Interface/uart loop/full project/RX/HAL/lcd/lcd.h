/*
 * lcd.h
 *
 * Created: 4/19/2023 1:27:17 PM
 *  Author: atef
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/dio/dio.h"

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


#endif /* LCD_H_ */