/*
 * pre.h
 *
 * Created: 5/12/2023 12:38:30 AM
 *  Author: atef
 */ 


#ifndef PRE_H_
#define PRE_H_

#include "../dio/dio.h"
#include "uart_cfg.h"
//#include "lcd.h"

typedef enum
{
	STATUS_OK = 0,
	CHANNEL_NOT_FOUND,
	CONFIG_ERROR,
	QUEUE_OVERFLOW,
	QUEUE_EMPTY,
	CALL_BACK_ERROR,
	RECIEVE_ERROR,
	RECIEVED,
	UART_FREE,
	UART_RECIEVEING,
	UART_SENDING
	
}en_UARTError_t; 


void UART_Init(void);
void UART_SendByte(u8 u8data);
void UART_RecieveByte(u8* pu8Data);
void UART_ReceiveString(u8*str,u8 endch);
void UART_SendString(u8*str);
void UART_ReceiveStringD(u8*str);
////////////////////////////////////////////////////
void UART_SendByteNoBlock( u8 u8data);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_RX_SetCallBack(void(*LocalFptr)(void));
void UART_RecieveByteNoBlock(u8* pu8Data);
u8 UART_ReceivePerodic(u8*pU8data);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_TX_SetCallBack(void(*LocalFptr)(void));



 void uart_init_noblocking();
void UART_SendStringAshync(u8*str);
void UART_ReceiveStringAshync ();
void UART_ReceiveStringAshync_V2 (u8 *str) ;
//void UART_ReceiveStringAshync (u8 *Pu8_RX_STR);
void UART_SendStringSetter(u8*str);
void UART_SendStringRunnable();

void UART_RX_FUN () ;
en_UARTError_t UART_ReceiveStringAshync_V3 (u8 *str) ;
void UART_TX_FUN_V3 (void);
en_UARTError_t UART_SendStringAshync_V3(u8*str)    ;
#endif /* PRE_H_ */