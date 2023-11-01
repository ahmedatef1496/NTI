/*
 * NTI.c
 *
 * Created: 10/17/2023 12:39:43 PM
 * Author : atef
 */ 
#include "app/app.h"
u8 flag=0,data[5][20],Total_C=0;
u8 string [20]="first",string2[20]="second",ch='A';
void spi_f ();
void spi_rec ();
int main(void)
{
 //spi_rec ();

}

void spi_rec ()
{
		u8 x=0,i=0;
		DIO_Init();
		LCD_Init();
		//UART_Init();
		GLOBALE_ENABLE();
		SPI_voidSlaveInit();
		SPI_RX_InterruptEnaple();
		SPI_RX_SetCallBack(spi_f);
		while(1)
		{
			
			

			

		}
}
void spi_f ()
{
		static u8 i=0,j;
 		data[i][j]=SPI_RecNoBlock();
		 if (data[i][j]=='\0')
		 {
			 flag++;
			 LCD_WriteString(data[i]);
			 i++;
		 }
		 else
		 {
			 j++;
		 }
		
															
																													  

}
