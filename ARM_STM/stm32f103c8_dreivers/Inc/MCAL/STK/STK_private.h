/*
 * 	STK_private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: atef
 */
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


/*******************   Register Definition     ***********************/

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;
/*******************   BASE Address Definition    *********************/

#define STK_BASE_ADDRESS	0xE000E010 		//define the boundary address of STK

#define STK			((volatile STK_t *) STK_BASE_ADDRESS)

#endif /* STK_PRIVATE_H */
