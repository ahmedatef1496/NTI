/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"



int main(void)
{
	DIO_Init();
	LCD_Init();
	pong_init();

	while(1)
	{    
		  PongGame();
		
	  
	

	}
}
