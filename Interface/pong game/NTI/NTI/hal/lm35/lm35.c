#include "lm35.h"
void LM35_VoidInit(void)
{
	ADC_Init(VREF_VCC,ADC_SCALER_64);

}


u16 LM35_U16Read(u8 Copy_u8readchannel)
{
	u16 temp = 0;
	ADC_Read(Copy_u8readchannel,&temp); /* read channel two where the temp sensor is connect */
	temp = (u16)(((u32)temp*150*5)/(1023*1.5));                      /* calculate the temp from the ADC value*/
   
	 return temp;
}




