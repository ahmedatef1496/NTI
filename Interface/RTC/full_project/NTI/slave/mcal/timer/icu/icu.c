/*
 * icu.c
 *
 * Created: 5/16/2023 12:00:50 AM
 *  Author: atef
 */ 

#include "icu.h"
#include "icu_cfg.h"
void ovfCount ();
static volatile u16 t1,t2,ICU_flag=0;
volatile int ovc=0;
static void ICU_Read_callbackfun(void)
{
	if (ICU_flag==0)
	{
		Timer0_ReadTimerValue(&t1);
		t1=t1+ovc*TIMER0_REG_SIZE;
		EXI_TriggerEdge(ICU_EXI_INT,FALLING_EDGE);
		ICU_flag=1;
		ovc=0;
		
	}
	else if (ICU_flag==1)
	{
		Timer0_ReadTimerValue(&t2);
		t2=t2+ovc*TIMER0_REG_SIZE;
		ovc=0;

		ICU_flag=2;
	}
}
void ICU_init ()
{   
		/* to count if overflow happens*/
		Timer0_OV_SetCallBack(ovfCount);
		Timer0_OV_InterruptEnable();
	Timer0_Init(TIMER0_NORMAL_MODE);
	Timer0_start(TIMER0_SCALER_8);
	// DIO_initpin(ICU_CH,INFREE);                              // in init all pins
	EXI_Enable(ICU_EXI_INT);
	EXI_TriggerEdge(ICU_EXI_INT,RISING_EDGE);
	EXI_SetCallBack(ICU_EXI_INT, ICU_Read_callbackfun );
	

// 	

}

u8 ICU_Read(u16 *pu16_PeriodTime)
{

	u16 timeout ;
	EXI_TriggerEdge(ICU_EXI_INT,RISING_EDGE);
	Timer0_SetTimerValue(0);
	ICU_flag=0;
		while((ICU_flag<2)&&(timeout<23000))
		{
			timeout++;
			_delay_us(1);
		}
		
		if(ICU_flag==2)
		{   
			
			*pu16_PeriodTime =(t2-t1);
// 			 LCD4_SetCursor(1,0);
// 			 LCD_WriteNumber(t2-t1);
			 
			return 1 ;    //done
		}
	
	return  0; //timeout
}

void ovfCount ()
{
	ovc++;
}