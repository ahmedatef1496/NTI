/*
 * SPI_interface.h
 *
 * Created: 10/30/2023 9:49:10 AM
 *  Author: Dell
 */ 

#include "../dio/dio.h"
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define MOSI_PIN  PINB5
#define MISO_PIN  PINB6
#define SS_PIN    PINB4
#define SCK_PIN   PINB7


typedef enum {
	PRESCALER_2,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128
} SPIScaler_type;

void SPI_MasterInit();
void SPI_SlaveInit();
void SPI_InterruptEnable();
void SPI_InterruptDisable();
void SPI_SetCallBack(void(*localfptr)(void));
u8 SPI_u8Transfer(u8 Copy_Data);

void SPI_SendNoBlock(u8 data);
u8 SPI_RecNoBlock(void);


#endif /* SPI_INTERFACE_H_ */