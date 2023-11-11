/*
 * dio.h
 *
 * Created: 4/13/2023 6:41:52 AM
 *  Author: atef
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../SERVIES/memmap.h"
#include "../../SERVIES/utils.h"
#include "../../SERVIES/std_typs.h"


typedef enum{
	PA=0,
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

typedef enum dioError{
	DIO_OK,
	WRONG_PORT_NUMBER,
	WRONG_PIN_NUMBER,
	WRONG_VALUE,
	WRONG_DIRECTION
}en_dioError_t;

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
/*////////////port mode////////////////////////////////////////////////////////
  en_dioError_t  DIO_InitPin   (DIO_Port_type port, u8 pin_num, DIO_PinStatus_type status);
  en_dioError_t  DIO_WritePin  (DIO_Port_type port, u8 pin_num, DIO_PinVoltage_type volt);
  en_dioError_t  DIO_TogglePin (DIO_Port_type port, u8 pin_num);
  en_dioError_t  DIO_ReadPin  (DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type *volt);
  en_dioError_t  DIO_WritePort (DIO_Port_type port,u8 value);
///////////////pin mode/////////////////////////////////////////////////////*/
void DIO_Init_All(void);
  en_dioError_t  DIO_initpin  (DIO_Pin_type pin,DIO_PinStatus_type status);
  en_dioError_t  DIO_writepin (DIO_Pin_type pin,DIO_PinVoltage_type volt);
  en_dioError_t  DIO_readpin  (DIO_Pin_type pin,DIO_PinVoltage_type *volt);
  en_dioError_t  DIO_togglepin(DIO_Pin_type pin);
  en_dioError_t  DIO_WritePort (DIO_Port_type port,u8 value);
////////////////////////////////////////////////////////////////////
#endif /* DIO_H_ */