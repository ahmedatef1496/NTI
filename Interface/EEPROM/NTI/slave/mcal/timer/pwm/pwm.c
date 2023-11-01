/*
 * pwm.c
 *
 * Created: 5/15/2023 12:21:49 AM
 *  Author: atef
 */ 
#include "pwm.h"
u32 u32_ONTicks=0,u32_OFFTicks=0;


void pwm_init()
{
	DIO_initpin(PINB0,OUTPUT);
	Timer0_Init(TIMER0_NORMAL_MODE);
	Timer0_OV_InterruptEnable();
	Timer0_OV_SetCallBack(waveGen);
	
} 

void waveGen()
{  static u32 OV=0;
	TCNT0=6;
	OV++;
	if (OV==(u32_OFFTicks+1))
	{
		DIO_writepin(PINB0,HIGH);//
	}
	else if (OV==(u32_ONTicks+u32_OFFTicks+2))
	{
		DIO_writepin(PINB0,LOW);//
		OV=0;
	}
	
}


void PWM_set_duty(u8 u8_DutyCycle,u32 u32_Freq)
{
	f64 f64_wavePeriodTime = ((f32)1 / u32_Freq)*1000000;					         // The Periodic Time for the Generated Pulse in Seconds //
	f64 f64_waveONTime = (f64_wavePeriodTime*u8_DutyCycle) / 100;		// The HIGH Level Time in Seconds //
	f64 f64_waveOFFTime = f64_wavePeriodTime - f64_waveONTime;		   // The LOW Level Time in Seconds //
	f64 f64_oneTickTime = 0.0;
	f64_oneTickTime = (f64) (((f64)PWM_PRESCALER/(f64)F_CPU)*1000000);   //1u at 8,8
	//LCD_DisplayFloat(f64_wavePeriodTime) ;
	f64 f64_max_time = (256*f64_oneTickTime); //256u
	//LCD_DisplayFloat( f64_oneTickTime) ;
	u32_ONTicks     =  f64_waveONTime/(f64_max_time-6);
	u32_OFFTicks    =  f64_waveOFFTime/(f64_max_time-6);
	DIO_writepin(PINB0,HIGH);
	//LCD_WriteNumber( u32_ONTicks ) ;
}





/* 10u base  there a problem 20% ++*/

void waveGen_hf()
{  static u32 OV=0;
	TCNT0=140;
	OV++;
	if (OV==(u32_OFFTicks))
	{
		DIO_writepin(PINB0,HIGH);
	}
	else if (OV==(u32_ONTicks+u32_OFFTicks))
	{
		DIO_writepin(PINB0,LOW);
		OV=0;
	}
	
}




void PWM_set_duty_hf(u8 u8_DutyCycle,u32 u32_Freq)
{
	f64 f64_wavePeriodTime = (f32)1 / u32_Freq*1000000;					         /* The Periodic Time for the Generated Pulse in Seconds */
	f64 f64_waveONTime = (f64_wavePeriodTime*u8_DutyCycle) / 100;		/* The HIGH Level Time in Seconds */
	f64 f64_waveOFFTime = f64_wavePeriodTime - f64_waveONTime;		   /* The LOW Level Time in Seconds */
	f64 f64_oneTickTime = 0.0;
	f64_oneTickTime = (f64) (((f64)1/(f64)F_CPU)*1000000);   //.0625 at 1,16
	//LCD_WriteNumber(f64_wavePeriodTime) ;
	f64 f64_max_time = (160*f64_oneTickTime); //10u
	//LCD_WriteNumber(  f64_waveONTime) ;
	u32_ONTicks     =  f64_waveONTime/(f64_max_time); //to make it 10u
	LCD_WriteNumber(u32_ONTicks) ;
	u32_OFFTicks    =  f64_waveOFFTime/(f64_max_time);
	LCD_SetCursor(1,0);
	LCD_WriteNumber(u32_OFFTicks) ;
	DIO_writepin(PINB0,HIGH);
}
/********************************************************************/