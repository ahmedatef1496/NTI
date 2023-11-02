/*
 * BCM.c
 *
 * Created: 5/22/2023 9:00:25 PM
 * Author : atef
 */ 

#include "app/app.h"
void f1 ();
void f2 ();
u8 flag=0,data[5][20],Total_C=0;

int main(void)
{
	u8 x=0,i=0;
	DIO_Init_All();
	LCD_Init();
	GLOBALE_ENABLE();
	UART_Init();
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(UART_RX_FUN);
		UART_TX_InterruptEnable();
		UART_TX_SetCallBack(UART_TX_FUN_V3);
	/* RX */
	 LCD_SetCursor(0,0);
	LCD_WriteString("RX");
    LCD_SetCursor(0,10);
    LCD_WriteString("TX");
	while(1)
	{ 

             f1();
			 f2();
  
     		 LCD_SetCursor(0,8);
     		 LCD_WriteNumber(Total_C);
      

	}

}


/*test receiving from mcu1  as string */ 

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
/*test SEND string to trminal  */ 

void f2 ()
{  		 	
	static u8 Send_C=0,s_flag=0;
		 		
	 if (Total_C>0)     //Q not empty   // check if i  have string to send 
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