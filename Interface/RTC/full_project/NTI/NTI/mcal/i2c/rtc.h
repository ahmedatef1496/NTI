/*
 * rtc.h
 *
 * Created: 11/3/2023 10:13:29 AM
 *  Author: atef
 */ 

#include "i2c.h"
#include <stdbool.h>
#ifndef RTC_H_
#define RTC_H_



#define Device_Write_address	0xD1
#define Device_Read_address		0xD0
#define SECONDS_ADDRESS         0x00
#define DAY_ADDRESS		        0x00

u8 RTC_Read_Clock (u8 add, u8 *sec, u8 *min,u8 *hour);
u8 RTC_Read_Calendar (u8 address, u8 *day, u8 *date,u8 *month,u8 *year);
void rtc_test ();

#endif /* RTC_H_ */