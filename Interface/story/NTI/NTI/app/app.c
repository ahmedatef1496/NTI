/*
 * app.c
 *
 * Created: 10/20/2023 7:10:26 PM
 *  Author: atef
 */ 
#include "app.h"

  u8 heart[] = {
	  0b00000,
	  0b01010,
	  0b11111,
	  0b11111,
	  0b01110,
	  0b00100,
	  0b00000,
	  0b00000
  };

u8 block[] = {
  0x1F,
  0x1F,
  0x11,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x1F
};
  u8 location3 =0x03;
   u8 locationx =0x01;
void story ()
{
	u8 i=0;
	LCD_CustomChar(location3,&heart);
	LCD_CustomChar(locationx,&block);
	LCD_WriteString("HI,im tourist hamo ");
	LCD4_SetCursor(1,0);
	LCD_WriteString("   i visted  EG ");
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD4_SetCursor(2,0);
	LCD_WriteString(" let me show u ");
	LCD4_SetCursor(3,0);
	LCD_WriteString("places i vasted");
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	_delay_ms(3000);
	LCD_Clear();
	for(i=0; i<11; i++)
	{
		LCD4_SetCursor(3,i);
		LCD_WriteChar(locationx);
	}
	for(i=1; i<8; i++)
	{
		LCD4_SetCursor(2,i);
		LCD_WriteChar(locationx);
	}

	LCD4_SetCursor(2,9);
	LCD_WriteChar(locationx);
	for(i=2; i<5; i++)
	{
		LCD4_SetCursor(1,i);
		LCD_WriteChar(locationx);
	}

	LCD4_SetCursor(1,6);
	LCD_WriteChar(locationx);
	LCD4_SetCursor(0,3);
	LCD_WriteChar(locationx);

	LCD4_SetCursor(0,9);
	LCD_WriteString("Pyramids");
	LCD4_SetCursor(1,9);
	LCD_WriteString("in Giza");
	LCD4_SetCursor(2,12);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	_delay_ms(3000);
	LCD_Clear();

	for(i=2; i<5; i++)
	{
		LCD4_SetCursor(3,i);
		LCD_WriteChar(locationx);
	}
	for(i=2; i<5; i++)
	{
		LCD4_SetCursor(2,i);
		LCD_WriteChar(locationx);
	}
	for(i=2; i<5; i++)
	{
		LCD4_SetCursor(1,i);
		LCD_WriteChar(locationx);
	}
	LCD4_SetCursor(0,3);
	LCD_WriteChar(locationx);

	LCD4_SetCursor(0,6);
	LCD_WriteString("cairo tower");
 	LCD4_SetCursor(1,6);
	LCD_WriteString("in capital");
	LCD4_SetCursor(2,8);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	LCD_WriteChar(location3);
	_delay_ms(3000);
	LCD_Clear();
		for(i=0; i<5; i++)
		{
			LCD4_SetCursor(1,i);
			LCD_WriteChar(location3);
		}
				for(i=1; i<4; i++)
				{
					LCD4_SetCursor(2,i);
					LCD_WriteChar(location3);
				}
		LCD4_SetCursor(2,3);
		LCD_WriteChar(location3);
		LCD4_SetCursor(0,0);
		LCD_WriteChar(location3);
				LCD4_SetCursor(0,1);
				LCD_WriteChar(location3);
						LCD4_SetCursor(0,3);
						LCD_WriteChar(location3);
								LCD4_SetCursor(0,4);
								LCD_WriteChar(location3);
		LCD4_SetCursor(0,6);
		LCD_WriteString("  7biby");
		LCD4_SetCursor(1,6);
		LCD_WriteString("come to Egypt");
		LCD4_SetCursor(2,12);
		LCD_WriteChar(location3);
		LCD_WriteChar(location3);
		LCD_WriteChar(location3);
		LCD_WriteChar(location3);
				LCD4_SetCursor(3,12);
				LCD_WriteChar(location3);
				LCD_WriteChar(location3);
				LCD_WriteChar(location3);
				LCD_WriteChar(location3);
		_delay_ms(3000);
		LCD_Clear();

}