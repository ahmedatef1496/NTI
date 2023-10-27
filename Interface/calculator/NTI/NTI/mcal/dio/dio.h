/*
 * dio.h
 *
 * Created: 10/17/2023 12:43:55 PM
 *  Author: atef
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../services/MemMap.h"
#include "../../services/StdTypes.h"
#include "../../services/Utils.h"

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	LOW=0,
	HIGH,
}DIO_PinVoltage_type;

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;

typedef enum dioError{
	DIO_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_VALUE,
	WRONG_DIRECTION
}en_dioError_t;

void DIO_Init(void);
en_dioError_t  DIO_initpin   (DIO_Pin_type pin,DIO_PinStatus_type status);
en_dioError_t  DIO_writepin  (DIO_Pin_type pin,DIO_PinVoltage_type volt);
en_dioError_t  DIO_readpin   (DIO_Pin_type pin,DIO_PinVoltage_type *volt);
en_dioError_t  DIO_togglepin (DIO_Pin_type pin);
en_dioError_t  DIO_WritePort (DIO_Port_type port,u8 value);
en_dioError_t  DIO_ReadPort  (DIO_Port_type port,u8 *value);
DIO_PinVoltage_type DIO_ReadPin2(DIO_Pin_type pin);

en_dioError_t  DIO_WritePin_port(char *port, u8 pin_num, DIO_PinVoltage_type volt);

#endif /* DIO_H_ */