/*
 * SPI_interface.h
 *
 * Created: 10/30/2023 9:49:10 AM
 *  Author: Dell
 */ 

#include "../dio/dio.h"
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);
void SPI_RX_SetCallBack(void(*localfptr)(void));
 void SPI_SendNoBlock(u8 data);
 u8 SPI_RecNoBlock(void);


#endif /* SPI_INTERFACE_H_ */