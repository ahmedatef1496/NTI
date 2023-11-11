/*
 * UART_Service.h
 *
 * Created: 6/9/2023 9:53:17 AM
 *  Author: atef
 */ 


#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

#include "utils.h"
#include "std_typs.h"
#include "memmap.h"
#include "../MCAL/uart/uart.h"


void UART_SendString(u8 *pu8str);
void UART_SendNumber(u32 u32num);
void UART_ReceiveString(u8 *pu8str);
void UART_RecieveNumber(u32 *pu32num);
void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);
#endif /* UART_SERVICE_H_ */