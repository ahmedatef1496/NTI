/*
 * SPI_program.c
 *
 * Created: 10/30/2023 9:48:53 AM
 *  Author: Dell
 */ 
#include "SPI_interface.h"
#include "SPI_config.h"

// MASTER send clock to the slave.
// Master send SS to the slave to activate it.
// Master send Data.

// ----> There is no Frame here, just Data, so it has the highest throughput.


static void (*SPI_fptr)(void)=NULLPTR;


static void SPI_prescaler(SPIScaler_type prescaler )
{
	switch (prescaler)
	{
		case PRESCALER_2:
		CLR_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_4:
		CLR_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_8:
		SET_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_16:
		SET_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_32:
		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_64:
		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
		break;
		
		case PRESCALER_128:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
		break;
	}

}
static void SPI_Master()
{
	//choose master mode.
	SET_BIT((SPCR),MSTR);
}
static void SPI_Slave()
{
	//choose slave mode.
	CLR_BIT((SPCR),MSTR);
}
static void SPI_Enable()
{
	//Enable SPI.
	SET_BIT((SPCR),SPE);
	
}
static void SPI_Disable()
{
	//Disable SPI.
	CLR_BIT((SPCR),SPE);
	
}

void SPI_MasterInit()
{
	DIO_initpin(MOSI_PIN,OUTPUT);
	DIO_initpin(MISO_PIN,INFREE);
	DIO_initpin(SS_PIN,OUTPUT);
	DIO_initpin(SCK_PIN,OUTPUT);
	DIO_writepin(SS_PIN,HIGH);
	
	// 1- choose master mode.
	SPI_Master();
	// 2- Select the speed.
	SPI_prescaler(PRESCALER_4);
	// 3- Enable SPI
	SPI_Enable();
}
void SPI_SlaveInit()
{
		DIO_initpin(MOSI_PIN,INFREE);
		DIO_initpin(MISO_PIN,OUTPUT);
		DIO_initpin(SS_PIN,INFREE);
		DIO_initpin(SCK_PIN,INFREE);
	
	// 1- choose master mode.
	SPI_Slave();
	// 2- Select the speed.
	SPI_prescaler(PRESCALER_4);
	// 3- Enable SPI
	SPI_Enable();
} 
void SPI_InterruptEnable()
{
	SET_BIT((SPCR),SPIE);
}
void SPI_InterruptDisable()
{
	CLR_BIT((SPCR),SPIE);
}
void SPI_SetCallBack(void(*localfptr)(void))
{
	SPI_fptr=localfptr;
}


u8 SPI_u8Transfer(u8 Copy_Data)
{    
#if SPI_MODE == SPI_MODE_MASTER
 
  DIO_writepin(SS_PIN,LOW);
  
	u8 flush_buffer;
	SPDR = Copy_Data;
	
	while(!READ_BIT(SPSR, SPIF));
	
	flush_buffer=SPDR;
	
    DIO_writepin(SS_PIN,HIGH);

#elif SPI_MODE == SPI_MODE_SLAVE

      	u8 flush_buffer;
      	SPDR = Copy_Data;
      	
      	while(!READ_BIT(SPSR, SPIF));
      	
      	flush_buffer=SPDR;
		  
		  return flush_buffer;
		  #endif
}

 void SPI_SendNoBlock(u8 data)
 {
	 SPDR=data;
 }
 u8 SPI_RecNoBlock(void)
 {
	 return SPDR;
 }



ISR(SPI_STC_vect)
{
	if(SPI_fptr!=NULLPTR)
	{
		SPI_fptr();
	}
}