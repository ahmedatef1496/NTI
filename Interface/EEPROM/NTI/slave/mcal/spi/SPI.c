


#include "SPI.h"



void SPI_Init(SPI_Mode_type mode)
{
	if (mode==MASTER)
	{
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		CLR_BIT(SPCR,MSTR);
	}
	
	//CLOCK 2 MHZ
	
	// SPI ENABLE
	SET_BIT(SPCR,SPE);
	
}



void SPI_SendReceive(u8 *data)
{
	SPDR=*data;
	while(!READ_BIT(SPSR,SPIF));

}


void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}