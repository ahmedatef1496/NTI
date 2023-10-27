/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"


int main(void)
{  
	u16 ldr= 0,pot;
	 int i=0;
	u8 keypadC,buffer[10],num1[10],num2[10] ;
	DIO_PinVoltage_type volt=HIGH;  
	 DIO_Init();
	 LCD_Init();   
     KEYPAD_InitNTI();
	 while(1)
	 {  					 
	 
     calculator ();		 

	 }

}

