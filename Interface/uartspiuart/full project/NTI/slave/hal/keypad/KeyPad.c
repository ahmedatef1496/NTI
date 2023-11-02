

#define KEYPAD_C
#include "../../mcal/dio/dio.h"

#include "KeyPad.h"
#include "KeyPad_cfg.h"


void KEYPAD_Init(void)
{
	DIO_writepin(FIRST_OUTPUT,HIGH);
	DIO_writepin(FIRST_OUTPUT+1,HIGH);
	DIO_writepin(FIRST_OUTPUT+2,HIGH);
	DIO_writepin(FIRST_OUTPUT+3,HIGH);
}

void KEYPAD_InitNTI(void)
{
	DIO_writepin(FIRST_OUTPUT,HIGH);
	DIO_writepin(FIRST_OUTPUT+2,HIGH);
	DIO_writepin(FIRST_OUTPUT+3,HIGH);
	DIO_writepin(FIRST_OUTPUT+4,HIGH);
}

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	
	for (r=0;r<ROWS;r++)
	{ 

		DIO_writepin(FIRST_OUTPUT+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_readpin2(FIRST_INPUT+c)==LOW)
			{
				key=KeysArrayNTI[r][c];
				while(DIO_readpin2(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_writepin(FIRST_OUTPUT+r,HIGH);
	}

	
	return key;	
}
u8 KEYPAD_GetKeyNTI(void)
{
	u8 r,c,key=NO_KEY;
	
	for (r=0;r<ROWS+1;r++)
	{

		DIO_writepin(FIRST_OUTPUT+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_readpin2(FIRST_INPUT+c)==LOW)
			{
				key=KeysArrayNTI[r][c];
				while(DIO_readpin2(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_writepin(FIRST_OUTPUT+r,HIGH);
	}
	if (r==1)
	{
		r++;
	}
	
	return key;
}

void KeyPadTest ()
{
	u8 keypadC;
	static u8 i=-1;
	keypadC=KEYPAD_GetKeyNTI();
	
	if(keypadC!='T')
	{
		
		if (keypadC=='c')
		{
			LCD_ClearLoc(1,i,1);
			i--;
			
		}
		else
		{
			i++;
			LCD_SetCursor(1,i);
			LCD_WriteChar(keypadC);
			
		}
	}

}