/*
 * NVIC_private.h
 *
 *  Created on: Nov 1, 2023
 *      Author: atef
 */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H




/*******************   Register Definition     ***********************/
typedef struct
{
	/* Enable External interrupts from 0 to 31 & from 32 to 63 */
	volatile u32 ISER[2];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	volatile u32 RESERVED0[30];
	volatile u32 ICER[2];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	volatile u32 RSERVED1[30];
	volatile u32 ISPR[2];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	volatile u32 RESERVED2[30];
	volatile u32 ICPR[2];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	volatile u32 RESERVED3[30];
	volatile u32 IABR[2];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	volatile u32 RESERVED4[62];
	volatile u8  IP[60];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	volatile u32 RESERVED5[689];
	volatile u32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}NVIC_t;

/* System control block (SCB) */
typedef struct
{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;                  /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}SCB_t;

/*******************   BASE Address Definition    *********************/

#define NVIC_Base_Address      0xE000E100      //define the boundary address of NVIC
#define SCB_Base_Address       0xE000ED00	   //define the boundary address of SCB

#define NVIC 					( ( volatile NVIC_t* ) NVIC_Base_Address )
#define SCB						( ( volatile SCB_t* ) SCB_Base_Address )



#endif // NVIC_PRIVATE_H
