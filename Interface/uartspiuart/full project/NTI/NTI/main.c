/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"
void uart_send ();
void uart_rec ();
u8 flag=0,data[10][20],Total_C=0,alarm_flag1=0,alarm_flag3=0,alarm_flag2=0;
u8 string [20]="first",string2[20]="second",ch='A';
void uartTspi();

int main(void)
{    

		
     uartTspi();


}


void uartTspi()
{
	u8 x=0,i=0,j=0;
	DIO_Init();
	LCD_Init();
	UART_Init();
	SPI_MasterInit();
	//DIO_writepin(PINB4,LOW);
	GLOBALE_ENABLE();

	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(UART_RX_FUN);
	LCD_SetCursor(0,0);
	LCD_WriteString("recd");
	LCD_SetCursor(0,10);
	LCD_WriteString("sent");
	while(1)
	{
		uart_rec();   //rec
		LCD_SetCursor(0,8);
		LCD_WriteNumber(Total_C); //display number of waiting strings to be se
		
		if (Total_C>0)
		{
			while(data[i][j] != 0)
			{
				SPI_u8Transfer(data[i][j]);
				j++;
				_delay_ms(1);
				flag=0;
			}
			if (flag==0)
			{ 
				     data[i][j]=0;
				     SPI_u8Transfer(data[i][j]);
					 LCD_SetCursor(1,10);
					 LCD_WriteString(data[i]);
					 LCD_WriteString("     ");
					 flag=1;
					 			i++;
					 			j=0;
					 			Total_C--;
			}


			
			
			
			
		}

	}
}
/*test receiving from trminal  as string */

void uart_rec ()
{
	static  Rec_C=0,R_flag=0;
	R_flag=UART_ReceiveStringAshync_V3(&data[Rec_C]);
	if (R_flag==UART_FREE)
	{
		LCD_SetCursor(1,0);
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
void uart_send ()
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