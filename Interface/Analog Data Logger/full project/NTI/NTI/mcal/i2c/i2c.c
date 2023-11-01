/*
 * i2c.c
 *
 * Created: 4/29/2023 2:48:47 AM
 *  Author: atef
 */ 

#include "i2c.h"
#include "i2c_cfg.h"

u8 I2C_getStatus(void)
{
	u8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWSR & 0xF8;
	return status;
}
void I2C_addressWrite(u8 I2C_address) {
	 TWDR = I2C_address+0;
 }
void I2C_addressRead(u8 I2C_address) {
	 TWDR = I2C_address+1;
 }
void I2C_WriteData(u8 data) {
	    /* Put data On TWI data Register */
    TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(!READ_BIT(TWCR,TWINT));
 } 
u8 I2C_readWithACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!READ_BIT(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
u8 I2C_readWithNACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!READ_BIT(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

/*---------------------------------------------------------------*/
void I2C_init(void)
{   
	// TWBR = 12;
	TWSR = 0x00;
    /*  pre-scaler TWPS=00 */
	//TWSR = 0x00;
   /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
   TWBR=BITRATE(TWSR);  
    //  TWBR = 0x02;
  // LCD_SetCursor(1,0);
  // LCD_WriteBinary(TWBR);
 
     /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
    TWAR = 0b00000010; // my address = 0x01 :) 
	
    TWCR = (1<<TWEN); /* enable TWI */ 
} 
en_I2CError_t I2C_start(void)
{  	

    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	 while (!(TWCR & (1<<TWINT)));	
	 		_delay_ms(10);
	if (I2C_getStatus()!=START_STATE)
	{  

		return START_NOT_SENT;
	
	} 
	else
	{ 	

		return EVENT_OK;
			
	}
	
}
en_I2CError_t I2C_repeated_start(void)
{ 
   
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
 	 while (!(TWCR & (1<<TWINT)));	

	if (I2C_getStatus()!=REP_START_STATE)
	{
		return REPEATED_START_NOT_SENT;
	} 
	else
	{
		return EVENT_OK;
	}
}
en_I2CError_t I2C_address_select(u8 adress,u8 rw)
{  
	if (rw==write)
	{
		//TWDR = adress+0;
		I2C_addressWrite(adress);
		
	}
	else if (rw ==read )
	{
		//TWDR = adress+1;
		I2C_addressRead(adress);
	}
	else
	{
		
	}
	
	       TWCR = (1 << TWINT) | (1 << TWEN);
	
			   while (!(TWCR&(1<<TWINT)));
			    
	if (I2C_getStatus()==SLA_W_ACK_STATE)
	{   
		 
		return SLA_W_ACK_SENT;
		
	}
	else if(I2C_getStatus()==SLA_W_NACK_STATE)
	{  
		
		return SLA_W_NACK_SENT;
		
	}
	if (I2C_getStatus()==SLA_R_ACK_STATE)
	{    
		
		return SLA_R_ACK_SENT;
		
	}
	else if(I2C_getStatus()==SLA_R_NACK_STATE)
	{
		return SLA_R_NACK_SENT;
		
	}
	else
	{   
		
		return SLA_RW_FAILED;	 
	}
	
}
en_I2CError_t I2C_data_rw(u8 *data,u8 rw,u8 ack)
 {  
	
	 if (rw==write)
	 {
		I2C_WriteData(data);
		
		 if (I2C_getStatus()==DATA_WRITE_ACK_STATE)
		 {
			 return DATA_WRITE_ACK_SENT;
		 }
		 else if(I2C_getStatus()==DATA_WRITE_NACK_STATE)
		 {
			 return DATA_WRITE_NACK_SENT;
		 }
		 else
		 {
			 return DATA_WRITE_FAILED;
		 }
		 
	 } 
	 
	 else if (rw==read)
	 {
		 if (ack==ACK)
		 {
			*data=I2C_readWithACK();
		 }
		 else if (ack==NACK)
		 { 
			*data=I2C_readWithNACK();
			
		 }
		 
			    
		 if (I2C_getStatus()==DATA_READ_ACK_STATE)
		 {
			 return DATA_READ_ACK_SENT;
			 
		 }
		 else if(I2C_getStatus()==DATA_READ_NACK_STATE)
		 {
			 return DATA_READ_NACK_SENT;
			 
		 }
		 else
		 {
			 return DATA_READ_FAILED;
	
		 }
		 
		 
	 }
	 
 } 
 void I2C_stop(void)
{   
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	  while (TWCR&(1<<TWSTO));
}
/*---------------------------------------------------------------*/