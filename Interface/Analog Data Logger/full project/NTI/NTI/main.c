/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"
void f1 ();
void f2 ();
u8 flag=0,data[5][20],Total_C=0;
u8 string [20]="first",string2[20]="second",ch='A';
void uartTspi();

void adc()
{   u8 tempflag=0;
	u16 S ;
	static i=5;
	
	u8 adc_read =ADC_Read_NB();
	
//	lm1 =(u16)(((u32)adc_read*150*5)/(1023*1.5));
	
//  	if(lm1>70)
// 	{
// 		tempflag=2;
// 				LCD_SetCursor(1,0);
// 				LCD_WriteString("case2");
// 	}
// 	else if (lm1>45&&lm1<70)
// 	{
// 		tempflag=1;
// 				LCD_SetCursor(1,0);
// 				LCD_WriteString("case1");
// 
// 	}
// 	else if(lm1<45)
// 	{
// 		tempflag=0;
// 		LCD_SetCursor(1,0);
// 		LCD_WriteString("case0");
// 	}
if (i==5)
{  
	
	ADC_InterruptDisable();
	S =adc_read;
	S =(u16)(((u32)adc_read*150*5)/(1023*1.5));
	if (S>50)
	{
			LCD4_SetCursor(3,0);
			LCD_WriteString("S1");
			DIO_writepin(PINB5,HIGH);
	}
	else
	{
		LCD4_ClearLoc(3,0,6);
		DIO_writepin(PINB5,LOW);
	}
	LCD_SetCursor(0,0);
	LCD_WriteString("S1: ");
	
	LCD_WriteNumber(S);
	i++;
	ADC_InterruptEnable();
} 
else if(i==6)
{  
	ADC_InterruptDisable();
	S =(u16)(((u32)adc_read*150*5)/(1023*1.5));
		if (S>50)
		{
			LCD4_SetCursor(3,8);
			LCD_WriteString("S2");
			DIO_writepin(PINB6,HIGH);
		}
		else
		{
			LCD4_ClearLoc(3,7,6);
			DIO_writepin(PINB6,LOW);
		}
	LCD_SetCursor(0,7);
	LCD_WriteString("S2: ");
	LCD_WriteNumber(S);
	i++;
	ADC_InterruptEnable();
}
else if(i==7)
{  
	 ADC_InterruptDisable();
	S =(u16)(((u32)adc_read*150*5)/(1023*1.5));
			if (S>50)
			{
				LCD4_SetCursor(3,16);
				LCD_WriteString("S3");
				DIO_writepin(PINB7,HIGH);
			}
			else
			{
				LCD4_ClearLoc(3,14,6);
				DIO_writepin(PINB7,LOW);
			}
	LCD4_SetCursor(0,14);
	LCD_WriteString("S3: ");
	LCD_WriteNumber(S);
	i=5;
	ADC_InterruptEnable();
} 

     adc_channel(i);
	ADC_StartConversionNB();
}
int main(void)
{
 //uartTspi();
    int i=0;
	 	DIO_Init();
	 	LCD_Init();
   GLOBALE_ENABLE();

	ADC_Init(VREF_VCC,ADC_SCALER_64);
	ADC_SetCallBack(adc);
	ADC_InterruptEnable();
	adc_channel(CH_5);
	ADC_StartConversionNB();
	while(1)
	{ 
		
	
// 		LCD_SetCursor(0,0);
// 		LCD_WriteNumber(i);
// 		
// 		_delay_ms(10);
// 		i++;
// 	
	
	
	}
	 
	 
 	//eeprom_test_string();

}

void uartTspi()
{
	u8 x=0,i=0,j=0;
	DIO_Init();
	LCD_Init();
	UART_Init();
	SPI_voidMasterInit();
	//	DIO_writepin(PINB4,HIGH);
	DIO_writepin(PINB4,LOW);
	GLOBALE_ENABLE();

	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(UART_RX_FUN);
	LCD_SetCursor(0,0);
	LCD_WriteString("TX");
	LCD_SetCursor(0,10);
	LCD_WriteString("RX");
	while(1)
	{
		f1();   //rec
		LCD_SetCursor(0,8);
		LCD_WriteNumber(Total_C); //display number of waiting strings to be se
		
		if (Total_C>0)
		{
			while(data[i][j] != '\0')
			{
				SPI_u8Transfer(data[i][j]);
				j++;
				_delay_ms(50);
				flag=0;
			}

			SPI_u8Transfer(data[i][j]);
			i++;
			j=0;
			Total_C--;
			
			
			
			
		}

	}
}
/*test receiving from trminal  as string */

void f1 ()
{
	static  Rec_C=0,R_flag=0;
	R_flag=UART_ReceiveStringAshync_V3(&data[Rec_C]);
	if (R_flag==UART_FREE)
	{
		LCD_SetCursor(1,10);
		LCD_WriteString(data[Rec_C]);
		LCD_WriteString("   ");
		Rec_C++;
		Total_C++;

		R_flag=0;
		
	}
	else
	{
		
	}
	
}
void f2 ()
{
	static u8 Send_C=0,s_flag=0;
	
	if (Total_C>0)                     // if i  have string to send
	{
		
		
		s_flag=UART_SendStringAshync_V3(&data[Send_C]);


		if (s_flag ==UART_FREE)
		{
			Total_C--;
			Send_C++;
			s_flag=0;
			
		}
	}
	
}