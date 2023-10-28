/*
 * app.c
 *
 * Created: 10/20/2023 7:10:26 PM
 *  Author: atef
 */ 
#include "app.h"
/*--------------------------------------------------*/

u8 person[] = {
	0x04,
	0x0A,
	0x04,
	0x1F,
	0x04,
	0x0A,
	0x0A,
	0x11
};

char ball[] = {
	0x00,
	0x0E,
	0x1F,
	0x1F,
	0x1F,
	0x0E,
	0x00,
	0x00
};
u8 location1 =0x01;
u8 location2 =0x02;

	u8 pA_X = 2, pA_Y = 0,pB_X = 2,pB_Y = 19,b_X = 0,b_Y =10;
	u8 input ;
	u8 bflag=0;
void pong_init()
{

	pA_X = 0;
	pA_Y = 0;
	pB_X = 0;
	pB_Y = 19;
	b_X = 0;
	b_Y =10;


	LCD_CustomChar(location1,person);
	LCD4_SetCursor(pA_X,pA_Y);
	LCD_WriteChar(location1);
	LCD_CustomChar(location1,person);
	LCD4_SetCursor(pB_X,pB_Y);
	LCD_WriteChar(location1);
	LCD_CustomChar(location2,ball);
	LCD4_SetCursor(b_X,b_Y);
	LCD_WriteChar(location2);
}

void PongGame()
{
	input=KEYPAD_GetKey();
	if(input=='9')
	{
		
		if(pA_X>0)
		{
			LCD4_ClearLoc(pA_X,pA_Y,1);
			pA_X--;
			LCD4_SetCursor(pA_X,pA_Y);
			LCD_WriteChar(location1);
		}

	}
	else if(input=='3')
	{
		_delay_ms(30);
		if(pA_X<3)
		{
			LCD4_ClearLoc(pA_X,pA_Y,1);
			pA_X++;
			LCD4_SetCursor(pA_X,pA_Y);
			LCD_WriteChar(location1);
		}
	}
	else if(input=='7')
	{
		_delay_ms(30);
		if(pB_X>0)
		{
			LCD4_ClearLoc(pB_X,pB_Y,1);
			pB_X--;
			LCD4_SetCursor(pB_X,pB_Y);
			LCD_WriteChar(location1);
		}

	}
	else if(input=='1')
	{
		_delay_ms(30);
		if(pB_X<3)
		{
			LCD4_ClearLoc(pB_X,pB_Y,1);
			pB_X++;
			LCD4_SetCursor(pB_X,pB_Y);
			LCD_WriteChar(location1);
		}
	}
	else if(input=='4')  //UP
	{
		if(b_X>0)
		{

			b_X--;


		}

	}
	else if(input=='6')
	{
		
		if(b_X<4&&b_X!=3)
		{

			b_X++;

		}

	}
	else
	{

	}

	if(bflag==0)
	{
		if(b_Y <19)
		{
			b_Y++;
			LCD4_SetCursor(b_X,b_Y);
			LCD_WriteChar(location2);
			_delay_ms(100);
			LCD4_ClearLoc(b_X,b_Y,1);
		}
		else
		{
			b_Y= 9;

		}

	}
	else if(bflag==1)
	{
		if(b_Y>0)
		{
			b_Y--;
			LCD4_SetCursor(b_X,b_Y);
			LCD_WriteChar(location2);
			_delay_ms(100);
			LCD4_ClearLoc(b_X,b_Y,1);
		}
		else
		{
			b_Y=9;

		}

	}


}

