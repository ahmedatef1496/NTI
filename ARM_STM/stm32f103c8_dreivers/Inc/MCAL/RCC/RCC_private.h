/*
 * RCC_private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: atef
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*******************   Register Definition     ***********************/
typedef struct {

	volatile u32 CR       ;
	volatile u32 CFGR     ;
	volatile u32 CIR      ;
	volatile u32 APB2RSTR ;
	volatile u32 APB1RSTR ;
	volatile u32 AHBENR   ;
	volatile u32 APB2ENR  ;
	volatile u32 APB1ENR  ;
	volatile u32 BDCR     ;
	volatile u32 CSR      ;
}RCC_t;

/*******************   BASE Address Definition    *********************/

#define RCC_BASE_ADDRESS	0x40021000		//define the boundary address of RCC

#define RCC ( ( volatile RCC_t* ) RCC_BASE_ADDRESS)


#endif // RCC_PRIVATE_H
