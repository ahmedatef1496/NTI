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


static void (*SPI_RX_fptr)(void)=NULLPTR;

void SPI_voidMasterInit(void)
{
	(SPCR) = 0x00;
	// 1- choose master mode.
	SET_BIT((SPCR),MSTR);
	
	// 2- select clock polarity.
	(SPCR) |= (SPI_CLK_POL<<CPOL); 
	
	// 3- select clock Phase.
	(SPCR) |= (SPI_CLK_PH<<CPHA);
	
	// 4- select Data Order.
	(SPCR) |= (SPI_DATA_ORDER<<DORD);
	
	// 5- Double Speed select.
	CLR_BIT((SPSR),SPI2X);
	(SPSR) |= (SPI_DOUBLE_SPEED<<SPI2X);
	
	// 6- Select the speed.
	(SPCR) |= (SPI_FREQ<<SPR0);
	
	// 7- Enable SPI.
	SET_BIT((SPCR),SPE);
}

void SPI_voidSlaveInit(void)
{
	(SPCR) = 0x00;
	// 1- choose master mode.
	CLR_BIT((SPCR),MSTR);
	
	// 2- select clock polarity.
	(SPCR) |= (SPI_CLK_POL<<CPOL);
	
	// 3- select clock Phase.
	(SPCR) |= (SPI_CLK_PH<<CPHA);
	
	// 4- select Data Order.
	(SPCR) |= (SPI_DATA_ORDER<<DORD);
	
	// 5- Double Speed select.
	CLR_BIT((SPSR),SPI2X);
	(SPSR) |= (SPI_DOUBLE_SPEED<<SPI2X);
	
	// 6- Select the speed.
	(SPCR) |= (SPI_FREQ<<SPR0);
	
	// 7- Enable SPI.
	SET_BIT((SPCR),SPE);
}

u8 SPI_u8Transfer(u8 Copy_Data)
{
	(SPDR) = Copy_Data;
	while(!READ_BIT((SPSR), SPIF));
	return (SPDR);
}




void SPI_voidEnableInt()
{
	SET_BIT((SPCR),SPIE);
}

void SPI_voidDisableInt()
{
	CLR_BIT((SPCR),SPIE);
}





void SPI_RX_InterruptEnaple(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_RX_InterruptDisaple(void)
{
	CLR_BIT(SPCR,SPIE);
}

void SPI_RX_SetCallBack(void(*localfptr)(void))
{
	SPI_RX_fptr=localfptr;
}
ISR(SPI_STC_vect)
{
	if(SPI_RX_fptr!=NULLPTR)
	{
		SPI_RX_fptr();
	}
}