/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"
void uart_rec();
void uart_send();
void SPI_callback ();
void spi_rec ();

u8 flag=0,data[10][20],Total_C=0;
u8 string [20]="first",string2[20]="second",ch='A';

int main(void)
{
      spi_rec ();

}

void spi_rec ()
{
		u8 x=0,i=0;
		DIO_Init();
		LCD_Init();
		UART_Init();
		GLOBALE_ENABLE();
		SPI_SlaveInit();
		SPI_InterruptEnable();
		SPI_SetCallBack(SPI_callback);
			UART_TX_InterruptEnable();
			UART_TX_SetCallBack(UART_TX_FUN_V3);
			/* TX */
			LCD_SetCursor(0,0);
			LCD_WriteString("recd");
			LCD_SetCursor(0,10);
			LCD_WriteString("sent");
		//LCD_WriteString("slave");
		while(1)
		{
			
			
       			 uart_send();   //send
					_delay_ms(1);



		}
}
void SPI_callback ()
{ 
	//LCD_WriteString("5");
		static u8 i=0,j=0;
 		data[i][j]=SPI_RecNoBlock();
		 if (data[i][j]=='\0')
		 {
			 flag++;
			// LCD_WriteNumber(flag);
			LCD4_SetCursor(1,0);
			 LCD_WriteString(data[i]);
			 LCD_WriteString("   ");
			 i++;
			 j=0;
			 Total_C++;
			 									        			 LCD_SetCursor(0,8);
			 									        			 LCD_WriteNumber(Total_C); //display number of waiting strings to be sent

		 }
		 else
		 { 
			// LCD_WriteChar(data[i][j]);
			 j++;
		 }
		
															
																													  

}
void uart_rec ()
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
void uart_send ()
{
	static u8 Send_C=0,s_flag=0;
	
	if (Total_C>0)                     // if i  have string to send
	{
		
		
		s_flag=UART_SendStringAshync_V3(&data[Send_C]);


		if (s_flag ==UART_FREE)
		{      
			   
                         
						LCD4_SetCursor(1,10);
						LCD_WriteString(data[Send_C]);
						LCD_WriteString("   ");


			Total_C--;
												        			 LCD_SetCursor(0,8);
												        			 LCD_WriteNumber(Total_C); //display number of waiting strings to be sent
			Send_C++;
			s_flag=0;
			
		}
	}
	
}