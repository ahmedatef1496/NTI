 /*
 * CFile1.c
 *
 * Created: 10/27/2023 
 *  Author: atef
 */ 
#include "timer.h"

/*************************Pointer to functions to be assigned to ISR**************************/
static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer0_OC_Fptr)  (void)=NULLPTR;
static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;
static void (*Timer2_OVF_Fptr) (void)=NULLPTR;
static void (*Timer2_OC_Fptr)  (void)=NULLPTR;
/******************************************************************************************/
/**********************************************************/
/*                       Timer-0                          */
/**********************************************************/

/**********************************Timer 0 functions***************************************/
void Timer0_Init(Timer0Mode_type mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
}
void Timer0_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
		case OC0_DISCONNECTED:
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		case OC0_NON_INVERTING:
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case OC0_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}
 EN_timerError_t Timer0_start(Timer0Scaler_type scaler)
 {
	 switch (scaler) {
		 case TIMER0_STOP:
		 case TIMER0_SCALER_1:
		 case TIMER0_SCALER_8:
		 case TIMER0_SCALER_64:
		 case TIMER0_SCALER_256:
		 case TIMER0_SCALER_1024:
		 case EXTERNAL0_FALLING:
		 case EXTERNAL0_RISING:
		 TCCR0&=0XF8;//0b11111000
		 TCCR0|=scaler;
		 return TIMER_OK;
		 default:
		 return TIMER_Error;
	 }
 }
 void Timer0_SetTimerValue(u8 timerValue)
 {
	 TCNT0 = timerValue;
 }
 
   void Timer0_ReadTimerValue(u8 *timerValue)
   {
	   *timerValue =TCNT0 ;
	   
   }
 
 void Timer0_reset()
 {
	 TCCR0 &= 0x00;
	 CLR_BIT(TIFR, 0);
	 TCNT0 = 0;
	 
 }
/*********************************Timer 0 Call Back functions*******************************/
void Timer0_OV_SetCallBack(void(*LocalFptr)(void))
 { 
	 Timer0_OVF_Fptr=LocalFptr;
 }
void Timer0_OC_SetCallBack(void(*LocalFptr)(void))
  {
	  Timer0_OC_Fptr=LocalFptr;
  }
/*********************************Timer 0 ISR functions*************************************/
ISR(TIMER0_OVF_vect)
 { 
	 if(Timer0_OVF_Fptr!=NULLPTR)
	 {
		 Timer0_OVF_Fptr();
	 }
 }
ISR(TIMER0_OC_vect)
{
	if(Timer0_OC_Fptr!=NULLPTR)
	{
		Timer0_OC_Fptr();
	}
}
/******************************Timer 0 Interrupt functions**********************************/
 void Timer0_OV_InterruptEnable(void)
 {
	 SET_BIT(TIMSK,TOIE0);
 }
 void Timer0_OV_InterruptDisable(void)
 {
	 CLR_BIT(TIMSK,TOIE0);
 }
 void Timer0_OC_InterruptEnable(void)
 {
	 SET_BIT(TIMSK,OCIE0);
 }
 void Timer0_OC_InterruptDisable(void)
 {
	 CLR_BIT(TIMSK,OCIE0);
 }
/**********************************************************/
/*                       Timer-1                          */
/**********************************************************/

/**********************************Timer 1 functions****************************************/
void Timer1_Init( Timer1Mode_type mode)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}

}
EN_timerError_t Timer1_start(Timer1Scaler_type scaler)
 {
	 switch (scaler) {
		 case TIMER1_STOP:
		 case TIMER1_SCALER_1:
		 case TIMER1_SCALER_8:
		 case TIMER1_SCALER_64:
		 case TIMER1_SCALER_256:
		 case TIMER1_SCALER_1024:
		 case EXTERNAL1_FALLING:
		 case EXTERNAL1_RISING:
		 TCCR1B&=0XF8;
		 TCCR1B|=scaler;
		 return TIMER_OK;
		 default:
		 return TIMER_Error;
	 }
 }
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLR_BIT(TCCR1B,ICES1);
}

  void Timer1_ReadTimerValue(u16 *timerValue)
  {
	  *timerValue =TCNT1 ;
	  
  }
  void Timer1_SetTimerValue(u16 timerValue)
  {
	  TCNT1=timerValue ;
	  
  }
/****************************Timer 1 Interrupt functions***********************************/

void Timer1_ICU_InterruptEnable (void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable (void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable (void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable (void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions******************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULLPTR)
	{
		Timer1_OVF_Fptr();
	}
} 
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULLPTR)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULLPTR)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}

/******************************************************************************************/
/**********************************************************/
/*                       Timer-2                          */
/**********************************************************/
/**********************************Timer 2 functions****************************************/

void Timer2_Init(Timer2Mode_type mode)
{
	switch (mode)
	{
		case TIMER2_NORMAL_MODE:
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		case TIMER2_PHASECORRECT_MODE:
		SET_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);
		break;
		case TIMER2_CTC_MODE:
		CLR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		case TIMER2_FASTPWM_MODE:
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
	}
}
void Timer2_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
		case OC0_DISCONNECTED:
		CLR_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
		break;
		case OC0_NON_INVERTING:
		CLR_BIT(TCCR2,COM00);
		SET_BIT(TCCR2,COM21);
		break;
		case OC0_INVERTING:
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
	}
}
EN_timerError_t Timer2_start(Timer2Scaler_type scaler)
{
	switch (scaler) {
		case TIMER2_STOP:
		case TIMER2_SCALER_1:
		case TIMER2_SCALER_8:
		case TIMER2_SCALER_64:
		case TIMER2_SCALER_256:
		case TIMER2_SCALER_1024:
		case EXTERNAL2_FALLING:
		case EXTERNAL2_RISING:
		TCCR2&=0XF8;//0b11111000
		TCCR2|=scaler;
		return TIMER_OK;
		default:
		return TIMER_Error;
	}
}
void Timer2_setTimerValue(u8 timerValue)
{
	TCNT2 = timerValue;
}
void Timer2_reset()
{
	TCCR2 &= 0x00;
	CLR_BIT(TIFR, 0);
	TCNT0 = 0;
	
}
/****************************Timer 2 Call Back functions************************************/
void Timer2_OV_SetCallBack(void(*LocalFptr)(void))
{
	Timer2_OVF_Fptr=LocalFptr;
}
void Timer2_OC_SetCallBack(void(*LocalFptr)(void))
{
	Timer2_OC_Fptr=LocalFptr;
}
/****************************Timer 2 ISR functions*****************************************/
ISR(Timer2_OVF_vect)
{
	if(Timer2_OVF_Fptr!=NULLPTR)
	{
		Timer2_OVF_Fptr();
	}
}
ISR(Timer2_OC_vect)
{
	if(Timer2_OC_Fptr!=NULLPTR)
	{
		Timer2_OC_Fptr();
	}
}
/****************************Timer 2 Interrupt functions***********************************/
void Timer2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer2_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}
void Timer2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void Timer2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}
/******************************************************************************************/



/*
u32 set_time (u16 PRE_SCALER,u32 DesiedTime)
{
	
	double oneTickTime = (((f64) PRE_SCALER /F_CPU ) * 1000); // in ms
	double MaxTime = oneTickTime * 256; // in ms
	u32 overflowsCount = (u32)(DesiedTime / MaxTime);
	u8 timerInitValue;
	if (overflowsCount > 1)
	{
		timerInitValue = (256 - ((DesiedTime - (MaxTime * overflowsCount) ) / oneTickTime));
	}
	else
	{
		timerInitValue = ((MaxTime - DesiedTime)/oneTickTime);
	}
	
	TCNT0 = timerInitValue;
	
	
	
	return overflowsCount;
	
}


*/












u32 set_time (u16 PRE_SCALER,f64 DesiedTime)
{ 
	double CPU_F = F_CPU;
	double oneTickTime = (PRE_SCALER /CPU_F *1000 ); // in ms
	double MaxTime = oneTickTime * 256; // in ms
	u32 overflowsCount = (u32)(DesiedTime / MaxTime);
	u8 timerInitValue;
	if (overflowsCount > 1)
	{
		timerInitValue = (256 - ((DesiedTime - (MaxTime * overflowsCount) ) / oneTickTime));
	}
	else
	{
		timerInitValue = ((MaxTime - DesiedTime)/oneTickTime);
	}
	
	// TCNT0 = timerInitValue;
	 
	
	//LCD_SetCursor(1,0);
	//LCD_WriteNumber(timerInitValue);
   return overflowsCount;
	
}


void timer_delay(u16 Delay)
{
	double CPU_F = F_CPU;
	double oneTickTime = (8 / CPU_F ) * 1000; // in ms
	double maxDelay = oneTickTime * 256; // in ms
	int overflowsCount =(u32)((Delay / maxDelay));
	u8 timerInitValue;
	if (overflowsCount > 1)
	{
		timerInitValue = (u8)(256 - ((Delay - (maxDelay * (overflowsCount - 1))) / oneTickTime));
	}
	else
	{
		timerInitValue = (u8)((maxDelay - Delay)/oneTickTime);
	}
	TCNT0 = timerInitValue;

	timer_start(TIMER0_SCALER_8);


	while(overflowsCount--)
	{
		while((READ_BIT(TIFR, 0)) == 0);
		
		SET_BIT(TIFR, 0);
	}

	TCCR0 &= ~((1 << CS01) | (1 << CS00));
}



/*****************************************************/
