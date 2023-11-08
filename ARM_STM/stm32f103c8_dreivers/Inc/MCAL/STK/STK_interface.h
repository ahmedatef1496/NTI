/*
 * STK_interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: atef
 */
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


#include "../../lib/std_types.h"
#include "../../lib/utils.h"

/******************   STK Clock Source Definition   ******************/

#define STK_SRC_AHB_8				0
#define STK_SRC_AHB					1

/******************   STK interval mode Definition   ******************/

#define STK_SINGLE_INTERVAL			0
#define STK_PERIOD_INTERVAL			1


/***************   Function definition    ******************/

void   STK_voidInit					(void);
void   STK_voidSetBusyWait			(u32 Copy_u32Ticks);
void   STK_voidSetIntervalSingle	(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void   STK_voidSetIntervalPeriodic	(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void   STK_voidStopInterval			(void);
u32    STK_u32GetElapedTime			(void);
u32    STK_u32GetRemainingTime		(void);

void   STK_voidDelay_ms				(u32 Copy_u32Ticks);

void   STK_voidStartTimer				(u32 Copy_u32Ticks);

void STK_voidStartMicros(void);
u64 Micros(void);
void STK_voidStartMillis(void);
u64 Millis(void);

#endif /* STK_INTERFACE_H */
