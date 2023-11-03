/*
 * eeprom_holder.h
 *
 * Created: 5/3/2023 3:59:42 AM
 *  Author: atef
 */ 


#ifndef EEPROM_HOLDER_H_
#define EEPROM_HOLDER_H_


/*
en_I2CError_t eeprom_start()
{
	return I2C_start();
}
en_I2CError_t eeprom_s_address_write(u8 address)
{
	 return I2C_address_select(address,write);
}
en_I2CError_t eeprom_s_address_read(u8 address)
{
	return I2C_address_select(address,read);
}
en_I2CError_t eeprom_write(u8 *data)
{
	return I2C_data_rw(data,write,ACK);
}
en_I2CError_t eeprom_readWACK(u8 *data)
{
	 return I2C_data_rw(data,read,ACK);
}
en_I2CError_t eeprom_eeprom_readWNACK(u8 *data)
{
	return I2C_data_rw(data,read,NACK);
}
void eeprom_stop()
{
	I2C_stop();
} 
en_I2CError_t eeprom_RepeatedStart()
{
	 return I2C_repeated_start();
}

void eeprom_WriteByte(u8 *data ,u16 u16_addr)
{
		if (eeprom_start()==EVENT_OK)
		{
			if ( eeprom_s_address_write((u8)(0xA0 | ((u16_addr & 0x0700)>>7)))==SLA_W_ACK_SENT)
			{       
				if(eeprom_write((u8)(u16_addr))==DATA_WRITE_ACK_SENT)
				{ 
					if(eeprom_write(data)==DATA_WRITE_ACK_SENT)
					{
				
					I2C_stop();
					
					}
				}
			}
		}
	
}
void eeprom_ReadByte (u8 *data ,u16 u16_addr )
{
			if (eeprom_start()==EVENT_OK)
			{
				if ( eeprom_s_address_write((u8)(0xA0 | ((u16_addr & 0x0700)>>7)))==SLA_W_ACK_SENT)
				{
					if(eeprom_write((u8)(u16_addr))==DATA_WRITE_ACK_SENT)
					{
						if(eeprom_write(data)==DATA_WRITE_ACK_SENT)
						{
							if (eeprom_RepeatedStart()==REPEATED_START_NOT_SENT)
							{
								if ( eeprom_s_address_read((u8)(0xA0 | ((u16_addr & 0x0700)>>7)))==SLA_R_ACK_SENT)
								{
									if(eeprom_eeprom_readWNACK(data)==DATA_READ_NACK_SENT)
									{
										eeprom_stop();
									}
								}
								
							}
							
							
						}
					}
				}
			}
}
/*------------------------------------------------*/
/*
u8 EEPROM_writeByte1(u16 u16addr, u8 u8data)
{
	/* Send the Start Bit 
    I2C_start();
    if (I2C_getStatus() != START_STATE)
        return 0;
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    I2C_WriteData((u8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (I2C_getStatus() != SLA_W_ACK_STATE)
        return 0; 
		 
    /* Send the required memory location address 
    I2C_WriteData((u8)(u16addr));
    if (I2C_getStatus() != DATA_WRITE_ACK_STATE)
        return 0;
		
    /* write byte to eeprom 
    I2C_WriteData(u8data);
    if (I2C_getStatus() != DATA_WRITE_ACK_STATE)
        return 0;

    /* Send the Stop Bit 
    I2C_stop();
	
    return 1;
}


u8 EEPROM_readByte2(u16 u16addr, u8 *u8data)
{ 
	   PORTB=1;
	/* Send the Start Bit 
      I2C_start();
      if (I2C_getStatus() != START_STATE)
                {  PORTB=1;
					 return 0;
				 
				 }
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) 
    I2C_WriteData((u8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (I2C_getStatus() != SLA_W_ACK_STATE)
                            {    PORTB=2;
								return 0;
	                            
                            }
		
    /* Send the required memory location address 
     I2C_WriteData((u8)(u16addr));
     if (I2C_getStatus() != DATA_WRITE_ACK_STATE)
                                  {  PORTB=4;
									  return 0;
	                                  
                                  }
		
    /* Send the Repeated Start Bit 
    I2C_start();
    if (I2C_getStatus() != REP_START_STATE)
                      {  PORTB=6;
						  return 0;
	                      
                      }
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) 
    
       I2C_WriteData((u8)(0xA0 | ((u16addr & 0x0700)>>7)|1));
       if (I2C_getStatus() != SLA_R_ACK_STATE)
                       {  PORTB=8;
						   return 0;
	                       
                       }
    /* Read Byte from Memory without send ACK 
    *u8data = I2C_readWithNACK();
    if (I2C_getStatus() != DATA_READ_NACK_STATE)
                       {  PORTB=64;
						   return 0;
	                       
                       }

    /* Send the Stop Bit 
    I2C_stop();
    return 1;
}
/*
void eeprom_test2(void)
{    u8 val;
     LCD_SetCursor(0,0);
	 LCD_WriteString("befor ee : ");
    LCD_WriteNumber(val);

		
		eeprom_init();

		eeprom_WriteByte(0x0315, 0x05); 
		_delay_ms(10);
		eeprom_ReadByte(0x0315, &val);  
 
  LCD_SetCursor(1,0);
  LCD_WriteString("after ee : ");
  LCD_WriteNumber(val);
		
	while(1)
	{
		
	}
}

void I2C_TEST (void)
{ 
	u8 data; 
	if (I2C_start()==EVENT_OK)
	{    
		LCD_WriteString("start I2C_1");
		
		if ( I2C_address_select(0x10,read)==SLA_R_ACK_SENT)
		{   			
			if(I2C_data_rw(&data,read,NACK)==DATA_READ_NACK_SENT)
			{  
				 LCD_SetCursor(1,0);
			LCD_WriteString("stop I2C_1");
				I2C_stop();
			}
		}
	}
	
	if (I2C_start()==EVENT_OK)
	{
		if ( I2C_address_select(0x10,write)==SLA_W_ACK_SENT)
		{        LCD_Clear();
				 LCD_WriteString("start I2C_2");
			if(I2C_data_rw(&data,write,ACK)==DATA_WRITE_ACK_SENT)
			{ 
				 LCD_SetCursor(1,0);
				 LCD_WriteString("stop  I2C_2");
				I2C_stop();
			}
		}
	}
	
	while(1)
	{
		
	}
}
*/

#endif /* EEPROM_HOLDER_H_ */