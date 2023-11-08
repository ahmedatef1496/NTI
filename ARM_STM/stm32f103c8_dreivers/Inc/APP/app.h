/*
 * app.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */


#ifndef APP_APP_H_
#define APP_APP_H_

#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/NVIC/NVIC_interface.h"
#include "../MCAL/STK/STK_interface.h"

void main_init();
void NVIC_test ();
void STK_TEST();
#endif /* APP_APP_H_ */
