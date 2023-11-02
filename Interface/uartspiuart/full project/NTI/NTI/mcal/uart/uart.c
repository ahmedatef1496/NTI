/*
 * uart.c
 *
 * Created: 5/11/2023 11:13:32 PM
 *  Author: atef
 */

#include "uart.h"


u8 *Pu8_g_TX_STR,*Pu8_g_RX_STR;
volatile u8 u8_g_RX_STR[20],u8_g_TX_STR[20],RX_flag=0,TX_falg=1;

/*************************Pointer to functions to be assigned to ISR**************************/
static void (*UART_RX_Fptr) (void)=NULLPTR;
static void (*UART_TX_Fptr) (void)=NULLPTR;



extern const ST_UART_cfg UART_cfg[TOTAL_DEVICES];
 
void UART_Init(void)
{
	/*Set the Baud rate*/
	u16 UBRRVAL=((F_CPU/(16L*UART_BAUDRATE))-1);
	UBRRH=(u8)(UBRRVAL>>8);
	UBRRL=(u8)(UBRRVAL);
	
	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	/*UART Transmitter and Receiver Enable*/
	//UCSRB =(1<<TXEN )|(1<<RXEN );
	        switch(UART_cfg[DEVICE_0].Device_role)
	        {
		        case TRANSMITTER:
		        SET_BIT( UCSRB,TXEN);
		        break;
		        case RECEIVER:
		        SET_BIT( UCSRB,RXEN);
		        break;
		        case TRANSCEIVER:
                UCSRB =(1<<TXEN )|(1<<RXEN );
		        break;
	        }
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/ 	
	/* DATA BITS*/
	u8 data=UART_DATA_BITS;
	if(data==5)
	{
		CLR_BIT(UCSRC ,UCSZ1 );
		CLR_BIT(UCSRC ,UCSZ0 );
	}else if(data==6)
	{
		CLR_BIT(UCSRC ,UCSZ1 );
		SET_BIT(UCSRC ,UCSZ0 );
	}else if(data==7)
	{
		SET_BIT(UCSRC ,UCSZ1 );
		CLR_BIT(UCSRC ,UCSZ0 );
	}else if(data==8)
	{
		SET_BIT(UCSRC ,UCSZ1 );
		SET_BIT(UCSRC ,UCSZ0 );
	}else if (data==9)
	{
		SET_BIT(UCSRB ,UCSZ2 );
		SET_BIT(UCSRC ,UCSZ1 );
		SET_BIT(UCSRC ,UCSZ0 );
	}
	/*PARITY*/
	u8 parity=UART_PARITY_BIT;
	if(parity==0)
	{
		CLR_BIT(UCSRC ,UPM1 );
		CLR_BIT(UCSRC ,UPM0 );
	}else if(parity==1)
	{
		SET_BIT(UCSRC ,UPM1 );
		SET_BIT(UCSRC ,UPM0 );
	}else if(parity==2)
	{
		SET_BIT(UCSRC ,UPM1 );
		CLR_BIT(UCSRC ,UPM0 );
	}
	/*STOP BITS*/
	u8 stop = UART_STOP_BITS;
	if(stop==1)
	{
		CLR_BIT(UCSRC ,USBS );
	}else if(stop==2)
	{
		SET_BIT(UCSRC ,USBS );
	}

} 

/*************************send**************************/
void UART_SendByte( u8 u8data)
{
	/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for 
	 * transmitting a new byte so wait until this flag is set to one */
	while(!READ_BIT(UCSRA,UDRE));
	/* Put the required data in the UDR register and it also clear the UDRE flag as 
	 * the UDR register is not empty now */	 
	UDR = u8data;
	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transimission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/	
}

void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_SendByte(str[i]);
	}

}

void UART_SendByteNoBlock( u8 u8data)
{
	
	UDR = u8data;

}
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}
void UART_RX_SetCallBack(void(*LocalFptr)(void))
{
	UART_RX_Fptr=LocalFptr;
}
/*************************recieve**************************/

void UART_RecieveByte(u8* pu8Data)
{
	/* RXC flag is set when the UART receive data so wait until this 
	 * flag is set to one */
	while(!READ_BIT(UCSRA,RXC));
	/* Read the received data from the Rx buffer (UDR) and the RXC flag 
	   will be cleared after read this data */	 
    *pu8Data=UDR;		
}

void UART_ReceiveString(u8*str,u8 endch)
{
	u8 i=0;
	UART_RecieveByte(&str[i]);
	for(;str[i]!=endch;)
	{
		i++;
		UART_RecieveByte(&str[i]);
		
	}
	str[i]=0;
	LCD4_SetCursor(3,0);
	LCD_WriteChar('D');
	
}
en_UARTError_t UART_ReceivePerodic(u8 *pu8data)
{
	en_UARTError_t status =STATUS_OK;
	
	if (READ_BIT(UCSRA,RXC))
	{
		*pu8data=UDR;
		status = RECIEVED ;
	}
	else
	{
		status= RECIEVE_ERROR;
	}
	return status;
}



void UART_RecieveByteNoBlock(u8* pu8Data)
{
	*pu8Data=UDR;
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}
void UART_TX_SetCallBack(void(*LocalFptr)(void))
{
	UART_TX_Fptr=LocalFptr;
}










ISR(UART_RXC_vect)
{   
	if(UART_RX_Fptr!=NULLPTR)
	{
		UART_RX_Fptr();
	}
}


ISR(UART_TX_vect)
{
	if(UART_TX_Fptr!=NULLPTR)
	{
		UART_TX_Fptr();
	}
}


/***************************************************************************************/

void UART_RX_FUN ()  //using g_string
{
	static u8 i=0;
	UART_RecieveByteNoBlock(&u8_g_RX_STR[i]);
	i++;
	RX_flag++;
}



void UART_ReceiveStringAshync (u8 *str) //just for testing 
{ 
	static u8 i=0;
	if (RX_flag>0)
	{
		LCD_SetCursor(1,i);
		LCD_WriteChar(u8_g_RX_STR[i]);
		
		i++;
		RX_flag--;
	} 
/*	Pu8_RX_STR=u8_g_RX_STR;*/
	
}

en_UARTError_t UART_ReceiveStringAshync_V3 (u8 *str) //just for testing
{
	static u8 u8StringCounter=0,u8ReceiveCounter=0;
	 en_UARTError_t status=0;
	if (RX_flag>0)
	{
		if (u8_g_RX_STR[u8ReceiveCounter]==13)
		{    
			
			u8StringCounter=0;
			u8ReceiveCounter++;
			RX_flag--;
			//TOGGLE_BIT(PORTB,0);
			status = UART_FREE;     //string complete
		}
      else
	  {
		 
		 str[u8StringCounter] = u8_g_RX_STR[u8ReceiveCounter] ;
			 
//      	  LCD_SetCursor(1,u8StringCounter);   //to write ch recd on lcd
// 		  LCD_WriteChar(str[u8StringCounter]);
// 		  LCD_WriteString("   ");  
		 	u8StringCounter++;
			u8ReceiveCounter++;
			
		 	RX_flag--;  
		    status=UART_RECIEVEING;    //receive string 

		
	  }
	  


	}
	
	return status;
	
}



void UART_RX_FUN_V2 ()
{
	static u8 i=0;
	UART_RecieveByteNoBlock(&Pu8_g_RX_STR[i]);
	i++;

}


 void UART_TX_FUN (void)
 {
	 static u8 j=1;
	 static u8 i=1;
	 if (Pu8_g_TX_STR[i]!=0)
	 {
		 UART_SendByteNoBlock(Pu8_g_TX_STR[i]);
		 i++;  //big problem if no stop if
	 }
	 else
	 {
		 i=1;
		 //we could disable int here for safty
	 }
	 

 }
 void UART_SendStringAshync(u8*str)
 {
	 static u8 i=0;
	 

	 //FIRST byte
	 UART_SendByteNoBlock(str[0]);
	 // COPY address of string
	 Pu8_g_TX_STR=str;
 }
  void UART_TX_FUN_V3 (void)
  {
	  TX_falg=1;
  }
 void UART_SendStringRunnable()    //Ashync_V2  should be in while sami asych
 {
	 static u8 i=0;
	 
  if (TX_falg==1)                     //init value of flag is 1 to send first byte
  {
 	if (Pu8_g_TX_STR[i]!=0)
	  	{
	        UART_SendByteNoBlock(Pu8_g_TX_STR[i]);
	        i++;
	    }
  } 
  TX_falg=0;
	 

 }
en_UARTError_t UART_SendStringAshync_V3(u8*str)    
  {   
	  en_UARTError_t state =0;
	  static u8 i=0;

	  if (TX_falg==1)                     
	  { 
	
		  if (str[i]==0)
		  { 
			  str[i]=13;
			  UART_SendByteNoBlock(str[i]);  //send the null //enter just for testing 
			  i=0;
			//  TOGGLE_BIT(PORTB,1);
			  state =UART_FREE;
              

			 
		  }
		  else
		  {
			   UART_SendByteNoBlock(str[i]);
			   i++;
			  
			   state=UART_SENDING;

		  }
	  }
	  
	  TX_falg=0;
	  return state;

  }
void UART_SendStringSetter(u8*str)
{
	Pu8_g_TX_STR=str;
}


void UART_ReceiveStringD(u8*str)
{
	u8 i, prev,flag=1;
	
	UART_RecieveByte(&str[0]);
	prev=str[0];
	for (i=0;flag;)
	{
		i++;
		UART_RecieveByte(&str[i]);
		if (str[i]==0x0A && prev==0x0D)
		{
			flag=0;
		}
		prev=str[i];
	}
	str[i]=0;
	str[i-1]=0;
}


