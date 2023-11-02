/*
 * us.c
 *
 * Created: 5/17/2023 3:42:42 PM
 *  Author: atef
 */ 

#include "us.h"


static volatile u8 flag=0;
volatile u16 t1,t2,t3;

void US_init()
{
	ICU_init();
}

static void US_trigger()
{
	DIO_writepin(ICU_TRIGGER_CH ,HIGH);
	_delay_us(10);
	DIO_writepin(ICU_TRIGGER_CH ,LOW);
	Timer1_SetTimerValue(0);
}


u8 US_getdistance(u16 *pu16_distance)
{
	u16 icu_time;
	US_trigger();
	ICU_Read(&icu_time);
	*pu16_distance =(icu_time/58); 
// 	LCD4_SetCursor(1,0);
// 	LCD_WriteNumber(icu_time);  
}

