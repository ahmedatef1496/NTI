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
		  PongGameV3();
		// movePlayers();
	  
	

	}
}

void led_dimer ()
{
			u8 duty;
			for(duty=0; duty<255; duty++)
			{
				OCR0=duty;
				_delay_ms(20);
			}
			for(duty=255; duty>1; duty--)
			{
				OCR0=duty;
				_delay_ms(20);
			}
}
void sbha ()
{
	 
	 LCD4_SetCursor(0,0);
	 LCD_WriteNumber(TCNT0);
	 LCD_WriteString("  ");
	 if (TCNT0==255)
	 {
		 
		 TCNT0=0;
	 }
	 
	 if (READ_BIT(PIND,0)==LOW)
	 {
		 TCNT0=0;
		 // LCD_WriteChar('a');
		 while(READ_BIT(PIND,0)==LOW);
	 }
}

void adc_int()
{  u8 tempflag=0; 
	int i=0;
				LCD4_SetCursor(0,9);
				
				
				LCD_WriteNumber(i);
				LCD_WriteString(" ");
				i++;
				_delay_ms(100);
				if (i==99)
				{
					i=0;
				}
				
				
				switch (tempflag)
				{
					case 0:
					LCD4_SetCursor(1,0);
					LCD_WriteString("lm35(0)   ");
					
					break;
					case 1:
					LCD4_SetCursor(1,0);
					LCD_WriteString("lm35(1)   ");
					break;
					case 2:
					LCD4_SetCursor(1,0);
					LCD_WriteString("lm35(2)   ");
					break;
				}
				
}
void lmtest()
{   u16 lm35=0;
	LM35_VoidInit();
			LCD4_SetCursor(0,0);
			lm35=LM35_U16Read(CH_0);
			LCD_WriteString("lm35 : ");
			//  ADC_Read(CH_0,&pot);
			LCD_WriteNumber(lm35);
			

			_delay_ms(300);	
}
void adc_check()
{   u8 tempflag=0;
	u16 lm1 ;
	u8 adc_read =ADC_Read_NB();
	lm1 =(u16)(((u32)adc_read*150*5)/(1023*1.5)); 
	
			      	 if(lm1>70)
			      	{
				      	tempflag=2;
			      	}
	else if (lm1>45&&lm1<70)
	{      
		tempflag=1;

	}
		      	else if(lm1<45)
		      	{ 
					  tempflag=0;
			      	 	}
		 

          ADC_StartConversionNB();
}
void ldrtest ()
{ u16 ldr=0;
		ldr=LDR_U16Read(CH_0);
		LCD_WriteNumber(ldr);
		if (ldr<=200)
		{
			PORTD=0x01;
		}
		else if (ldr>200 && ldr<=500)
		{
			PORTD=0x03;
		}
		else if (ldr>500 &&ldr<=800)
		{
			PORTD=0x07;
		}
		else if(ldr>800)
		{
			PORTD=0x0f;
		}

		_delay_ms(2000);
}



