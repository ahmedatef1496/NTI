/*
 * dio.c
 *
 * Created: 10/17/2023 12:42:15 PM
 *  Author: atef
 */ 

#include "dio.h" 
#include "dio_private.h"


void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0; i<TOTAL_PINS; i++)
	{
		DIO_initpin(i,PinsStatusArray[i]);
	}
}   
 en_dioError_t  DIO_initpin  (DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port = pin/8 ;
	u8 pin_num =pin % 8;
	en_dioError_t error = DIO_OK;
	
	if (pin_num < 8)
	{

		switch(status)
		{
			case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT( DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT( DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT( DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				SET_BIT( DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
				default:
				error = WRONG_PORT_NUMBER;
				break;
			}
			break;
			case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
				default:
				error = WRONG_PORT_NUMBER;
				break;
			}
			break;

			case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
				default:
				error = WRONG_PORT_NUMBER;
				break;
			}
			break;
			default:
			error = WRONG_PORT_NUMBER;
			break;
		}
	}
	else
	{
		error = WRONG_PIN_NUMBER;
	}
	return error;

}
 en_dioError_t  DIO_writepin (DIO_Pin_type pin,DIO_PinVoltage_type volt)
 {  
   /* to make it work just with pin num*/
	 DIO_Port_type port = pin/8 ;
	 u8 pin_num =pin % 8;
	 en_dioError_t error= DIO_OK;
	 if (pin_num<8)
	 {
		 switch (volt)
		 {
			 case HIGH:

			 switch(port)
			 {
				 case PA:

				 SET_BIT(PORTA,pin_num);
				 break;
				 case PB:

				 SET_BIT(PORTB,pin_num);
				 break;
				 case PC:

				 SET_BIT(PORTC,pin_num);
				 break;
				 case PD:

				 SET_BIT(PORTD,pin_num);
				 break;
				 default:
				 error = WRONG_PORT_NUMBER;
				 break;
			 }
			 break;

			 case LOW:

			 switch(port)
			 {
				 case PA:

				 CLR_BIT(PORTA,pin_num);
				 break;
				 case PB:

				 CLR_BIT(PORTB,pin_num);
				 break;
				 case PC:

				 CLR_BIT(PORTC,pin_num);
				 break;
				 case PD:

				 CLR_BIT(PORTD,pin_num);
				 break;
				 default:
				 error = WRONG_PORT_NUMBER;
				 break;
			 }

			 break;

			 default:
			 error = WRONG_VALUE;
			 break;

		 }
	 }
	 else
	 {
		 error = WRONG_PIN_NUMBER;
	 }
	 return error;

 }
 en_dioError_t  DIO_readpin  (DIO_Pin_type pin,DIO_PinVoltage_type *volt)
 {
	 DIO_Port_type port = pin/8 ;
	 u8 pin_num =pin % 8;
	 en_dioError_t error = DIO_OK;
	 if (pin_num < 8)
	 {

		 switch(port)
		 {
			 case PA:

			 *volt=READ_BIT(PINA,pin_num);
			 break;
			 case PB:

			 *volt=READ_BIT(PINB,pin_num);
			 break;
			 case PC:

			 *volt=READ_BIT(PINC,pin_num);
			 break;
			 case PD:

			 *volt=READ_BIT(PIND,pin_num);
			 break;
			 default:
			 error = WRONG_PORT_NUMBER;
			 break;
		 }

	 }
	 else
	 {
		 error = WRONG_PIN_NUMBER;
	 }
	 return error;
 }
 en_dioError_t  DIO_togglepin(DIO_Pin_type pin)
 {
	 DIO_Port_type port = pin/8 ;
	 u8 pin_num =pin % 8;
	 en_dioError_t error = DIO_OK;
	 if (pin_num< 8)
	 {
		 switch(port)
		 {
			 case PA:
			 TOGGLE_BIT(PORTA,pin_num);
			 break;
			 case PB:
			 TOGGLE_BIT(PORTB,pin_num);
			 break;
			 case PC:
			 TOGGLE_BIT(PORTC,pin_num);
			 break;
			 case PD:
			 TOGGLE_BIT(PORTD,pin_num);
			 break;
			 default:
			 error = WRONG_PORT_NUMBER;
			 break;
		 }
	 }
	 else
	 {
		 error = WRONG_PIN_NUMBER;
	 }
	 return error;
 }
 en_dioError_t  DIO_WritePort(DIO_Port_type port,u8 value)
 {
	 en_dioError_t error = DIO_OK;
	 
		 switch(port)
		 {
			 case PA:

			 PORTA=value;
			 break;
			 case PB:

			 PORTB=value;
			 break;
			 case PC:

			 PORTC=value;
			 break;
			 case PD:

			 PORTD=value;
			 break;
			 default:
			 error = WRONG_PORT_NUMBER;
			 break;
		 }
	 

	 return error;
 }  
 en_dioError_t  DIO_ReadPort(DIO_Port_type port,u8 *value)
  {
	  en_dioError_t error = DIO_OK;

		  switch(port)
		  {
			  case PA:

			  *value=PORTA;
			  break;
			  case PB:

			  *value=PORTB;
			  break;
			  case PC:

			  *value=PORTC;
			  break;
			  case PD:

			  *value=PORTD;
			  break;
			  default:
			  error = WRONG_PORT_NUMBER;
			  break;
		  }
	  

	  return error;
  }
  
  
en_dioError_t  DIO_WritePin_port(char *port, u8 pin_num, DIO_PinVoltage_type volt)
{


	switch (volt)
	{
		case HIGH:
		SET_BIT(*port,pin_num);
		break;

		case LOW:
		CLR_BIT(*port,pin_num);
		break;
	}

}

DIO_PinVoltage_type DIO_ReadPin2(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	
	return volt;
	
	
}