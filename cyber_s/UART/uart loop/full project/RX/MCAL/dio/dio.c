/*
 * dio.c
 *
 * Created: 4/13/2023 6:42:07 AM
 *  Author: atef
 */ 
#include "dio.h"
#include "dio_private.h"
//PORT MODE
/*///////////////////////// PORT MODE /////////////////////////////////////////////
    en_dioError_t  DIO_InitPin(DIO_Port_type port, u8 pin_num, DIO_PinStatus_type status)	
    {
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
    en_dioError_t  DIO_WritePin(DIO_Port_type port, u8 pin_num, DIO_PinVoltage_type volt)		
    {
	    en_dioError_t error= DIO_OK;
	    if (port<8)
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
    en_dioError_t  DIO_TogglePin(DIO_Port_type port, u8 pin_num)						
    {
	    en_dioError_t error = DIO_OK;
	    if (pin_num< 8)
	    {
		    switch(port)
		    {
			    case PA:
			    TGL_BIT(PORTA,pin_num);
			    break;
			    case PB:
			    TGL_BIT(PORTB,pin_num);
			    break;
			    case PC:
			    TGL_BIT(PORTC,pin_num);
			    break;
			    case PD:
			    TGL_BIT(PORTD,pin_num);
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
    en_dioError_t  DIO_ReadPin(DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type *volt)
    {
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
    en_dioError_t  DIO_WritePort(DIO_Port_type port,u8 value)
    {
	    en_dioError_t error = DIO_OK;
	    if (port < 3)
	    {

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
	    }
	    else
	    {
		    error = WRONG_PIN_NUMBER;
	    }
	    return error;
    }
//////////////////////////////////////////////////////////////////////*/
//pin MODE
  void DIO_Init_All(void)
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
			  TGL_BIT(PORTA,pin_num);
			  break;
			  case PB:
			  TGL_BIT(PORTB,pin_num);
			  break;
			  case PC:
			  TGL_BIT(PORTC,pin_num);
			  break;
			  case PD:
			  TGL_BIT(PORTD,pin_num);
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
	  if (port < 3)
	  {

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
	  }
	  else
	  {
		  error = WRONG_PIN_NUMBER;
	  }
	  return error;
  }