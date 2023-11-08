/*
 * GPIO_interface.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../../lib/std_types.h"
#include "../../lib/utils.h"
#include "../RCC/RCC_interface.h"

/***************    PULL  definition      *******************/
#define PULL_UP     0
#define PULL_DOWN   1

/***************   GPIO(PORT) definition  *******************/
#define GPIOA       0
#define GPIOB       1
#define GPIOC       2

/***************   PIN definition         *******************/
typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINA8,
	PINA9,
	PINA10,
	PINA11,
	PINA12,
	PINA13,
	PINA14,
	PINA15,
	PINB0=16,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINB8,
	PINB9,
	PINB10,
	PINB11,
	PINB12,
	PINB13,
	PINB14,
	PINB15,
	PINC13=32,
	PINC14=33,
	PINC15=34,
	TOTAL_PINS
}DIO_Pin_type;
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

/***************   INPUT Mode definition   ******************/
#define INPUT_ANALOG                0b0000
#define INPUT_FLOATING              0b0100
#define INPUT_PULL_UP_DOWN          0b1000

/***************   OUTPUT Mode definition  ******************/

//FOR 10MHZ
#define OUTPUT_SPEED_10MHZ_PP       0b0001
#define OUTPUT_SPEED_10MHZ_OD       0b0101
#define OUTPUT_SPEED_10MHZ_AFPP     0b1001
#define OUTPUT_SPEED_10MHZ_AFOD     0b1101

//FOR 2MHZ
#define OUTPUT_SPEED_2MHZ_PP        0b0010
#define OUTPUT_SPEED_2MHZ_OD        0b0110
#define OUTPUT_SPEED_2MHZ_AFPP      0b1010
#define OUTPUT_SPEED_2MHZ_AFOD      0b1110

//FOR 50MHZ
#define OUTPUT_SPEED_50MHZ_PP       0b0011
#define OUTPUT_SPEED_50MHZ_OD       0b0111
#define OUTPUT_SPEED_50MHZ_AFPP     0b1011
#define OUTPUT_SPEED_50MHZ_AFOD     0b1111

/***************   Function definition    ******************/
#if GPIO_MODE == _PORT_MODE

void  GPIO_voidSetPinDirection    (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void  GPIO_voidSetPinValue        (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8    GPIO_u8GetPinValue          (u8 Copy_u8Port, u8 Copy_u8Pin);
void  GPIO_voidTogglePinValue     (u8 Copy_u8Port, u8 Copy_u8Pin);
void  GPIO_voidSetPinPull         (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Pull);
void  GPIO_voidSetPortValue(u8 Copy_u8PORT, u32 Copy_u8Value);
void  GPIO_voidSetPortMode(u8 Copy_u8PORT, u32 Copy_u8ModeL, u32 Copy_u8ModeH);


#elif GPIO_MODE == _PIN_MODE

void  GPIO_voidSetPinDirection    (u8 Copy_u8Pin, u8 Copy_u8Mode);
void  GPIO_voidSetPinValue        (u8 Copy_u8Pin, u8 Copy_u8Value);
u8    GPIO_u8GetPinValue          (u8 Copy_u8Pin);
void  GPIO_voidTogglePinValue     (u8 Copy_u8Pin);
void  GPIO_voidSetPinPull         (u8 Copy_u8Pin, u8 Copy_u8Pull);

#endif

#endif /* GPIO_INTERFACE_H_ */
