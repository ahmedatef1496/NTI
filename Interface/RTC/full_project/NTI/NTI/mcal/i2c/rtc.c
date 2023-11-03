/*
 * rtc.c
 *
 * Created: 11/3/2023 10:13:11 AM
 *  Author: atef
 */ 
#include "rtc.h"



static   ISPM(u8 *hour)
{
	if (*hour>12)
	{ 
		//*hour-=12;
		*hour=*hour;
		return 1 ;
		
	} 
	else if(*hour==0)
	{ 
		
       *hour+=12;
		return 0 ;
	}
	else if(*hour<=12)
	{ 
		*hour=*hour;
		
		return 0 ;
	}
	
	
}

u8 RTC_Read_Clock (u8 address, u8 *sec, u8 *min,u8 *hour)
{
    /* Send the Start Bit */
    if (I2C_start()==EVENT_OK)
    { 
        /* Send the device address, we need to get A8 A9 A10 address bits from the
         * memory location address and R/W=0 (write) */
        if (I2C_address_select(Device_Read_address,write)==SLA_W_ACK_SENT)
        { 

            /* Send the required memory location address */
            if (I2C_data_rw(address,write,ACK)==DATA_WRITE_ACK_SENT)
            {

                /* Send the Repeated Start Bit */
                if (I2C_repeated_start()==EVENT_OK)
                {  
												
                    /* Send the device address, we need to get A8 A9 A10 address bits from the
                     * memory location address and R/W=1 (Read) */

                    if (I2C_address_select(Device_Read_address,read)==SLA_R_ACK_SENT)
                    { 
												
                        /* Read Byte from Memory without send ACK */

                        if (I2C_data_rw(sec,read,ACK)==DATA_READ_ACK_SENT)
                        {
 																						
							 if (I2C_data_rw(min,read,ACK)==DATA_READ_ACK_SENT)
							{
 																								
								if (I2C_data_rw(hour,read,NACK)==DATA_READ_NACK_SENT)
								
								{
 																
									 /* Send the Stop Bit */
									 I2C_stop();
								}
								                           
							}
							


                        }
                    }
                }
            }
        }
    }
}


u8 RTC_Read_Calendar (u8 address, u8 *day, u8 *date,u8 *month,u8 *year)
{
    /* Send the Start Bit */
    if (I2C_start()==EVENT_OK)
    { 
        /* Send the device address, we need to get A8 A9 A10 address bits from the
         * memory location address and R/W=0 (write) */
        if (I2C_address_select(Device_Read_address,write)==SLA_W_ACK_SENT)
        { 

            /* Send the required memory location address */
            if (I2C_data_rw(address,write,ACK)==DATA_WRITE_ACK_SENT)
            {

                /* Send the Repeated Start Bit */
                if (I2C_repeated_start()==EVENT_OK)
                {  
												
                    /* Send the device address, we need to get A8 A9 A10 address bits from the
                     * memory location address and R/W=1 (Read) */

                    if (I2C_address_select(Device_Read_address,read)==SLA_R_ACK_SENT)
                    { 
												
                        /* Read Byte from Memory without send ACK */

                        if (I2C_data_rw(day,read,ACK)==DATA_READ_ACK_SENT)
                        {
 																						
							 if (I2C_data_rw(date,read,ACK)==DATA_READ_ACK_SENT)
							{
 																								
								if (I2C_data_rw(month,read,ACK)==DATA_READ_ACK_SENT)
								
								{
							     	if (I2C_data_rw(year,read,NACK)==DATA_READ_NACK_SENT)
								
								        {									
 																
									         /* Send the Stop Bit */
									          I2C_stop();
								       }
								}
								                           
							}
							


                        }
                    }
                }
            }
        }
    }
}





static void  RTC_ReadPrint()
{
	u8 s=0,m=0,h=0,date=0,day=0,month=0,year=0;
	char buffer[20],ampm[3]="AM";
	char* days[7]= {(u8*)"Sun",(u8*)"Mon",(u8*)"Tue",(u8*)"Wed",(u8*)"Thu",(u8*)"Fri",(u8*)"Sat"};


	while(1)
	{
		RTC_Read_Clock (SECONDS_ADDRESS,&s,&m,&h);
		s = (s>>4) * 10 + (s&0x0F);
		m = (m>>4) * 10 + (m&0x0F);
		h = (h>>4) * 10 + (h&0x0F);
		
		if (ISPM(&h)==1)
		{	
			ampm[0]='P';
		}
		else
		{
			ampm[0]='A';
		}

		sprintf(buffer, "%02d:%02d:%02d:%02s  ",h, m, s,ampm);
		LCD4_SetCursor(0,0);
		LCD_WriteString(buffer);
		/********************************************/
		RTC_Read_Calendar(3,&day,&date,&month,&year);
		date = (date>>4)  * 10 + (date&0x0F);
		month= (month>>4) * 10 + (month&0x0F);
		year = (year>>4)  * 10 + (year&0x0F);
	//	day = (day>>4)  * 10 + (day&0x0F);
		sprintf(buffer, "%02d/%02d/%02d-%03s  ",date, month, year,days[day-1]);
		LCD4_SetCursor(1,0);
		LCD_WriteString(buffer);
		LCD4_SetCursor(2,0);
		
		
	}
}

void rtc_test ()
{
	I2C_init();
	RTC_ReadPrint();
	
}