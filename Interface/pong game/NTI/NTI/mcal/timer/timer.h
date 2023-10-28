/*
 * timer.h
 *
 * Created: 5/12/2023 3:36:24 PM
 *  Author: atef
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../dio/dio.h"
/*================================================================================================================*/
/********   TIMER0 [TCCR0] BITS   *******/
#define     CS00          0              // TIMER0 Prescaller Clock Select BIT 0
#define     CS01          1              // TIMER0 Prescaller Clock Select BIT 1
#define     CS02          2              // TIMER0 Prescaller Clock Select BIT 2
#define     WGM01         3              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     COM00         4              // Compare Match Output Mode BIT 0 (OC0) behavior
#define     COM01         5              // Compare Match Output Mode BIT 1 (OC0) behavior
#define     WGM00         6              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     FOC0          7              // Force Output Compare
/*================================================================================================================*/

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


typedef enum EN_timerError_t
{
	TIMER_OK,
	TIMER_Error
}EN_timerError_t;

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;
typedef enum{
	SCALER_1=1,
	SCALER_8=8,
	SCALER_64=64,
	SCALER_256=256,
	SCALER_1024=1024
}Scaler_type;
/**********************************************************/
/*                       Timer-0                          */
/**********************************************************/
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer0Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;

typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

void Timer0_Init(Timer0Mode_type mode);
void Timer0_OC0Mode(OC0Mode_type mode);
void Timer0_InitValue(u8 timerInitValue);
EN_timerError_t Timer0_start(Timer0Scaler_type scaler);
void Timer0_reset();
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void Timer0_OV_SetCallBack(void(*LocalFptr)(void));
void Timer0_OC_SetCallBack(void(*LocalFptr)(void));
 void Timer0_setTimerValue(u8 timerValue);
u32 set_time (u16 PRE_SCALER,f64 DesiedTime);
void timer_delay(u16 Delay); 

/**********************************************************/
/*                       Timer-1                          */
/**********************************************************/
typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;



void Timer1_InputCaptureEdge(ICU_Edge_type edge);

void Timer1_Init( Timer1Mode_type mode);
EN_timerError_t Timer1_start(Timer1Scaler_type scaler);

void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);


void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));
/**********************************************************/
/*                       Timer-2                          */
/**********************************************************/
typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_64,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024,
	EXTERNAL2_FALLING,
	EXTERNAL2_RISING
}Timer2Scaler_type;

typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE

}Timer2Mode_type;


typedef enum
{
	OC2_DISCONNECTED=0,
	OC2_TOGGLE,
	OC2_NON_INVERTING,
	OC2_INVERTING

}OC2Mode_type; 

/**********************************************************/
/*                       Timer-2                          */
/**********************************************************/
void Timer2_Init(Timer2Mode_type mode);
void Timer2_OC0Mode(OC0Mode_type mode);
void Timer2_InitValue(u8 timerInitValue);
EN_timerError_t Timer2_start(Timer2Scaler_type scaler);
void Timer2_reset();
void Timer2_OV_InterruptEnable(void);
void Timer2_OV_InterruptDisable(void);
void Timer2_OC_InterruptEnable(void);
void Timer2_OC_InterruptDisable(void);
void Timer2_OV_SetCallBack(void(*LocalFptr)(void));
void Timer2_OC_SetCallBack(void(*LocalFptr)(void));
#endif /* TIMER_H_ */