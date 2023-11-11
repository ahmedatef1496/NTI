/*
 * exi.h
 *
 * Created: 5/8/2023 8:26:04 AM
 *  Author: atef
 */ 


#ifndef EXI_H_
#define EXI_H_
#include "../../SERVIES/utils.h"
#include "../../SERVIES/memmap.h"
#include "../../SERVIES/std_typs.h"

#define  GLOBALE_ENABLE  sei

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

typedef enum extintError{
	EXTINT_OK,
	WRONG_INT_NUMBER
}en_extintError_t;


void EXI_Init(void);
void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));


#endif /* EXI_H_ */