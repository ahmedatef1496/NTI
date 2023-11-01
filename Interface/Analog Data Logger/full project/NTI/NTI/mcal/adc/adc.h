/*
 * adc.h
 *
 * Created: 4/15/2023 5:26:01 AM
 *  Author: atef
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../dio/dio.h"

typedef enum adcError{
	ADC_OK,
	WRONG_Channel,
	WRONG_SCALER,
	WRONG_VoltRef
}en_adcError_t;


typedef enum{
	VREF_AREF,
	VREF_VCC,
	VREF_256
	
}ADC_VoltRef_type;

typedef enum{       //3SHAN ASTFAD MN ELRKM NFSH
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;


typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;


en_adcError_t ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);

en_adcError_t ADC_Read(ADC_Channel_type channel,u16 *data);

void adc_channel (ADC_Channel_type channel);
void ADC_StartConversionNB();
void ADC_SetCallBack(void(*LocalFptr)(void));
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
u8 ADC_Read_NB();
#endif /* ADC_H_ */