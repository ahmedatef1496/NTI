#include "../../../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../../../Inc/MCAL/NVIC/NVIC_config.h"
#include "../../../Inc/MCAL/NVIC/NVIC_private.h"



void NVIC_init()
{
	SCB->AIRCR=GROUP_SUB ;
}

/*************	 Function OF Enable Interrupt  **************************/

void NVIC_voidEnableInterrupt(IRQn_Type IRQn)
{
	if (IRQn <= 31 )
	{
		SET_BIT(NVIC->ISER[0] , IRQn);
	}
	else if (IRQn <= 59)
	{
		IRQn -= 32;
		SET_BIT(NVIC->ISER[1] , IRQn);
	}
	else
	{
		/* Return error */
	}
}

/*************	 Function OF Disable Interrupt  *************************/

void NVIC_voidDisableInterrupt(IRQn_Type IRQn)
{
	if (IRQn <= 31 )
	{
		SET_BIT(NVIC->ICER[0] , IRQn);
	}
	else if (IRQn <= 59)
	{
		IRQn -= 32;
		SET_BIT(NVIC->ICER[1] , IRQn);
	}
	else
	{
		/* Return error */
	}
}

/*************	 Function OF Set Pending Flag  **************************/

void NVIC_voidSetPendingFlag(IRQn_Type IRQn)
{
	if (IRQn <= 31 )
	{
		SET_BIT(NVIC->ISPR[0] , IRQn);
	}
	else if (IRQn <= 59)
	{
		IRQn -= 32;
		SET_BIT(NVIC->ISPR[1] , IRQn);
	}
	else
	{
		/* Return error */
	}
}

/*************	 Function OF Clear Pending Flag  *************************/

void NVIC_voidClearPendingFlag(IRQn_Type IRQn)
{
	if (IRQn <= 31 )
	{
		SET_BIT(NVIC->ICPR[0] , IRQn);
	}
	else if (IRQn <= 59)
	{
		IRQn -= 32;
		SET_BIT(NVIC->ICPR[1] , IRQn);
	}
	else
	{
		/* Return error */
	}
}

/*************	 Function OF Get Active Flag  *************************/

u8 NVIC_u8GetActiveFlag(IRQn_Type IRQn)
{
	u8 Local_u8Result;
	if (IRQn <= 31 )
	{
		Local_u8Result = READ_BIT(NVIC->IABR[0], IRQn);
	}
	else if (IRQn <= 59)
	{
		IRQn -= 32;
		Local_u8Result = READ_BIT(NVIC->IABR[1], IRQn);
	}
	else
	{
		/* Return error */
	}
	return Local_u8Result;
}

/*************	 Function OF Set Priority  *************************/

void  NVIC_voidSetIntPriority (IRQn_Type IRQn, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
					  /* EX: 0x05FA0400 3 Group & 1 sub priority   for 8 G and 2 sub */
					  /* 0x100 Hex  ---> 256 Decimal  */
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((GROUP_NUMBER - 0x05FA0300)/256));
	/* external peripheral		*/ /*EXTI0 = 6*/
	if (IRQn < 60 )
	{
		NVIC->IP[IRQn] = Local_u8Priority << 4;
	}
	else
	{
		/* Report Error */
	}
	
	//SCB->AIRCR = Copy_u8Group;
}


void NVIC_voidSetIntPriority2(IRQn_Type IRQn, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	u8 Local_u8Priority = 0;


#if GROUP_NUMBER == GROUP_16_SUB_0
	priority = Copy_u8GroupPriority;
#elif GROUP_NUMBER == GROUP_8_SUB_2
	Local_u8Priority = (Copy_u8GroupPriority<<1) | Copy_u8SubPriority;
#elif GROUP_NUMBER == GROUP_4_SUB_4
	Local_u8Priority = (Copy_u8GroupPriority<<2) | Copy_u8SubPriority;
#elif GROUP_NUMBER == GROUP_2_SUB_8
	Local_u8Priority = (Copy_u8GroupPriority<<3) | Copy_u8SubPriority;
#elif GROUP_NUMBER == GROUP_0_SUB_16
	Local_u8Priority = Copy_u8SubPriority;
#endif

	if(IRQn < 61)
	{
		NVIC->IP[IRQn] = Local_u8Priority << 4;
	}
}


