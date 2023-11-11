/*
 * BCM.c
 *
 * Created: 5/22/2023 9:00:25 PM
 * Author : atef
 */ 

#include "app/app.h"
  #define  NRC        "7F2735"
u32 key=0x27353535,random_num=0x12345678;
u16 service_send=0x3101,service_rec=0x7101,securty_req=0x2701,securty_ans=0x6701,enc_send=0x2702,enc_rec=0x6702,routine =0xAA00;

void f1 ();
void f2 ();
u8 flag=0,data[5][20],Total_C=0;
u32 gen_num()
{
	static u32 i=1;
	random_num =(random_num*i)-3*i+random_num;
	i+=2;
	
	return random_num;
	
	
}

int main(void)
{
	u8 x=0, flag_a=0,flag_b=0;
	int i,k;
	u16 num=0;
	DIO_Init_All();
	LCD_Init();
	GLOBALE_ENABLE();
	UART_Init();
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(UART_RX_FUN);
	char *ptr;
	u32 ECode,serv;
 
	while(1)
	{

		f1();   //rec

		while(Total_C>0)   // i have messages
		{

			serv = strtol (data[0],&ptr,16);
			ECode = strtol(ptr,&ptr, 16);
			Total_C--;
			if (serv==securty_req)
			{
				flag_a=1;
				LCD_Clear();
				LCD_SetCursor(0,0);
				random_num =gen_num();
				LCD_WriteHex(securty_ans);
				LCD_WriteString("  ");
				LCD_WriteHexlong(random_num);
			}
			else if(serv==service_send)
			{
				if (flag_b==1) //u have access
				{ 
					if (ECode==routine)
					{   
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteHex(service_send);
						LCD_WriteString("  ");
						LCD_WriteHex(routine);
						SET_BIT(PORTB,0);
						flag_b=0;
						flag_a=0;    
					} 
					else
					{
								LCD_Clear();
								LCD_SetCursor(0,0);
								LCD_WriteString(NRC);
					}
					
				} 
				else
				{
													LCD_Clear();
													LCD_SetCursor(0,0);
													LCD_WriteString("ACCESS DENIED ");
				}
				
			}
			else if( serv==enc_send)
			{

				if (flag_a==1)
				{


					if ((random_num^key)==ECode)
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
					  LCD_WriteHex(enc_rec);
						flag_a=0;
						flag_b=1;
					}
					else
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteString(NRC);
						flag_a=0;
					}

				}
				else
				{
					LCD_Clear();
					LCD_SetCursor(0,0);
					LCD_WriteString(NRC);
					flag_a=0;
				}

			}


		}


	}

}


void f1 ()
{ 
	static  Rec_C=0,R_flag=0;
	R_flag=UART_ReceiveStringAshync_V3(&data[0]);
	 if (R_flag==UART_FREE)
	 {
		// LCD_SetCursor(1,10);
		// LCD_WriteString(data[Rec_C]);
		// LCD_WriteString("   ");
		// Rec_C++;
		 Total_C++;

		 R_flag=0;
		 
	 }
	 else
	 {
		 
	 }
	 
} 

