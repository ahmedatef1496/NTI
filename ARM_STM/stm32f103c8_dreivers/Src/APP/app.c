/*
 * app.c
 *
 *  Created on: Nov 8, 2023
 *      Author: atef
 */

#include "../../Inc/APP/app.h"


void TIMER (void);
void main_init()
{


	/* Initialize Clock System  */
	RCC_voidInitSysClock();
	/* Enable GPIOC Clock */
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOA_EN);
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOB_EN);
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOC_EN);

	LCD_PinsInit();
	LCD_Init();
}
void NVIC_test ()
{



	   NVIC_init();

	   LCD_WriteString((u8*)"NVIC_Test");
	   LCD4_SetCursor(1, 0);

	   NVIC_voidSetIntPriority(EXTI0_IRQn ,1, 0);
	   NVIC_voidSetIntPriority(EXTI1_IRQn ,0, 0);

	   NVIC_voidEnableInterrupt (EXTI0_IRQn );
	   NVIC_voidEnableInterrupt (EXTI1_IRQn );
	   NVIC_voidSetPendingFlag  (EXTI0_IRQn );



}


void STK_TEST()
{

	   LCD_WriteString((u8*)"STK_Test");
	   LCD4_SetCursor(1, 0);

       STK_voidInit();
       STK_voidSetIntervalPeriodic(100000,TIMER);
       GPIO_voidSetPinDirection(PINB15, OUTPUT_SPEED_10MHZ_PP);

}

void TIMER (void)
{
static u32 i =0;
LCD_SetCursor(0, 0);
LCD_WriteString((u8*)"HI_STK");
GPIO_voidTogglePinValue(PINB15);
LCD_WriteNumber(i);
i++;

}

void EXTI0_IRQHandler(void)
{

	LCD_WriteString((u8*)"EX0 ");
	NVIC_voidSetPendingFlag(EXTI1_IRQn);
	LCD_WriteString((u8*)"EX0XXXx");


}

void EXTI1_IRQHandler(void)
{
	NVIC_voidClearPendingFlag(EXTI0_IRQn);
	LCD_WriteString((u8*)"EX1 ");

}
