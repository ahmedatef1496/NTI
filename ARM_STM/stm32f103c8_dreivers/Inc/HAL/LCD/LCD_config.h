/*
 * LCD_config.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define M_5X7_2lines          0x38
#define Display_ON_No_C       0x0c
#define Display_ON_C          0x0e
#define Display_ON_C_Blanking 0x0f
#define CLR_INS               0x01
#define increment_No_shift    0X06

#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT


#if GPIO_MODE== _PORT_MODE
#define  RS   PIN4
//#define  RW   PINA2
#define  EN   PIN5
#define  D7   PIN3
#define  D6   PIN2
#define  D5   PIN1
#define  D4   PIN0

#define LCD_PORT  GPIOB

#elif GPIO_MODE== _PIN_MODE

#define  RS   PINB4
#define  EN   PINB5
#define  D7   PINB3
#define  D6   PINB2
#define  D5   PINB1
#define  D4   PINB0

#define LCD_PORT  GPIOB

#endif

#endif /* LCD_CONFIG_H_ */
