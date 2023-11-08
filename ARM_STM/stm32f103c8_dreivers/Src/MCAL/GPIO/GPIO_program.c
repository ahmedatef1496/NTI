#include "../../../Inc/MCAL/GPIO/GPIO_config.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_private.h"


#if GPIO_MODE==_PORT_MODE
/************* Function OF Set Pin Direction *************************/

void  GPIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            if (Copy_u8Pin <= 7)
            {//LOW   //0b0001
                GPIO_A->CRL &= ~((0b1111)      << (Copy_u8Pin * 4));
                GPIO_A->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_A->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
                GPIO_A->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;

        /*** PORT B ***/

        case GPIOB:
            if (Copy_u8Pin <= 7)
            {//LOW
                GPIO_B->CRL &= ~((0b1111)      << (Copy_u8Pin * 4));
                GPIO_B->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_B->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
                GPIO_B->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;

        /*** PORT C ***/

        case GPIOC:
            if (Copy_u8Pin <= 7)
            {//LOW
                GPIO_C->CRL &= ~((0b1111)      << (Copy_u8Pin * 4));
                GPIO_C->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_C->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
                GPIO_C->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;
        default:       break;
    }
}

/*************   Function OF Set Pin Value   *************************/
/***************** Options of Copy_u8Value:
                                            HIGH
                                            LOW     ******************/

void GPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if (Copy_u8Pin < 16)
	{
		if (Copy_u8Value == HIGH)
		{
			switch (Copy_u8PORT)
			{
			case GPIOA:
				GPIO_A->BSRR = (1 << Copy_u8Pin);
				break;

			case GPIOB:
				GPIO_B->BSRR = (1 << Copy_u8Pin);
				break;

			case GPIOC:
				GPIO_C->BSRR = (1 << Copy_u8Pin);
				break;

			default:
				break;
			}
		}
		else if (Copy_u8Value == LOW)
		{
			switch (Copy_u8PORT)
			{
			case GPIOA:
				GPIO_A->BRR = (1 << Copy_u8Pin);
				break;

			case GPIOB:
				GPIO_B->BRR = (1 << Copy_u8Pin);
				break;
			case GPIOC:
				GPIO_C->BRR = (1 << Copy_u8Pin);
				break;

			default:
				break;
			}
		}
	}
}
/*************   Function OF Get Pin Value   *************************/

u8 GPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 LOC_u8Result = 0;
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            LOC_u8Result = READ_BIT (GPIO_A->IDR, Copy_u8Pin);
            break;

        /*** PORT B ***/

        case GPIOB:
            LOC_u8Result = READ_BIT (GPIO_B->IDR, Copy_u8Pin);
            break;

        /*** PORT C ***/

        case GPIOC:
            LOC_u8Result = READ_BIT (GPIO_C->IDR, Copy_u8Pin);
            break;

        default :       break;
    }
    return LOC_u8Result;
}

/*************   Function OF Toggle Pin Value   **********************/

void  GPIO_voidTogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
    switch (Copy_u8Port)
	{
		 /*** PORT A ***/

		case GPIOA:
			TOGGLE_BIT(GPIO_A->ODR,Copy_u8Pin);
		  break;

		/*** PORT B ***/

		case GPIOB:
			TOGGLE_BIT(GPIO_B->ODR,Copy_u8Pin);
		  break;

		/*** PORT C ***/

		case GPIOC:
			TOGGLE_BIT(GPIO_C->ODR,Copy_u8Pin);
		  break;

		default :       break;
	}
}

/*************   Function OF Set Pin PULL   *************************/
/***************** Options of Copy_u8Pull:
                                            PULL_UP
                                           PULL_DOWN ***************/
void  GPIO_voidSetPinPull (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Pull)
{
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_A->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_A->ODR, Copy_u8Pin);
            }
            break;

        /*** PORT B ***/

        case GPIOB:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_B->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_B->ODR, Copy_u8Pin);
            }
            break;

        /*** PORT C ***/

        case GPIOC:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_C->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_C->ODR, Copy_u8Pin);
            }
            break;

        default :       break;
    }
}
void GPIO_voidSetPortValue(u8 Copy_u8PORT, u32 Copy_u8Value){
	switch (Copy_u8PORT){
	case GPIOA:
		GPIO_A->ODR = Copy_u8Value;
		break;

	case GPIOB:
		GPIO_B->ODR = Copy_u8Value;
		break;

	case GPIOC:
		Copy_u8Value &= 0xE0000000;
		GPIO_C->ODR = Copy_u8Value;
		break;

	default:
		break;
	}
}
void GPIO_voidSetPortMode(u8 Copy_u8PORT, u32 Copy_u8ModeL, u32 Copy_u8ModeH){
	switch (Copy_u8PORT){
	case GPIOA:
		GPIO_A->CRL = Copy_u8ModeL;
		GPIO_A->CRH = Copy_u8ModeH;
		break;

	case GPIOB:
		GPIO_A->CRL = Copy_u8ModeL;
		GPIO_A->CRH = Copy_u8ModeH;
		break;

	case GPIOC:
		GPIO_A->CRL = Copy_u8ModeL;
		GPIO_A->CRH = Copy_u8ModeH;
		break;

	default:
		break;
	}
}

#elif GPIO_MODE==_PIN_MODE

void  GPIO_voidSetPinDirection (u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	  u8  u8Port;
	  u8   u8Pin;
	  u8Port =  Copy_u8Pin/16;
      u8Pin  =  Copy_u8Pin%16;
    switch (u8Port)
    {


        case 0:
            if (u8Pin <= 7)
            {//LOW   //0b0001
                GPIO_A->CRL &= ~((0b1111)      << (u8Pin * 4));
                GPIO_A->CRL |=  ((Copy_u8Mode) << (u8Pin * 4));
            }
            else if (u8Pin <= 15)
            {//HIGH
                GPIO_A->CRH &= ~((0b1111)      << ((u8Pin - 8) * 4));
                GPIO_A->CRH |=  ((Copy_u8Mode) << ((u8Pin - 8) * 4));
            }
            break;

        case 1:
            if (u8Pin <= 7)
            {//LOW
                GPIO_B->CRL &= ~((0b1111)      << (u8Pin * 4));
                GPIO_B->CRL |=  ((Copy_u8Mode) << (u8Pin * 4));
            }
            else if (u8Pin <= 15)
            {//HIGH
                GPIO_B->CRH &= ~((0b1111)      << ((u8Pin - 8) * 4));
                GPIO_B->CRH |=  ((Copy_u8Mode) << ((u8Pin - 8) * 4));
            }
            break;



        case GPIOC:
            if (u8Pin <= 7)
            {//LOW
                GPIO_C->CRL &= ~((0b1111)      << (u8Pin * 4));
                GPIO_C->CRL |=  ((Copy_u8Mode) << (u8Pin * 4));
            }
            else if (u8Pin <= 15)
            {//HIGH
                GPIO_C->CRH &= ~((0b1111)      << ((u8Pin - 8) * 4));
                GPIO_C->CRH |=  ((Copy_u8Mode) << ((u8Pin - 8) * 4));
            }
            break;
        default:       break;
    }
}



/*************   Function OF Set Pin Value   *************************/
/***************** Options of Copy_u8Value:
                                            HIGH
                                            LOW     ******************/

void GPIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value)
{
	  u8  u8Port;
	  u8   u8Pin;
	  u8Port = (Copy_u8Pin /16);
      u8Pin=  (Copy_u8Pin %16);

	if (u8Pin < 16)
	{
		if (Copy_u8Value == HIGH)
		{
			switch (u8Port)
			{
			case GPIOA:
				GPIO_A->BSRR = (1 << u8Pin);
				break;

			case GPIOB:
				GPIO_B->BSRR = (1 << u8Pin);
				break;

			case GPIOC:
				GPIO_C->BSRR = (1 << u8Pin);
				break;

			default:
				break;
			}
		}
		else if (Copy_u8Value == LOW)
		{
			switch (u8Port)
			{
			case GPIOA:
				GPIO_A->BRR = (1 << u8Pin);
				break;

			case GPIOB:
				GPIO_B->BRR = (1 << u8Pin);
				break;
			case GPIOC:
				GPIO_C->BRR = (1 << u8Pin);
				break;

			default:
				break;
			}
		}
	}
}

/*************   Function OF Get Pin Value   *************************/

u8 GPIO_u8GetPinValue (u8 Copy_u8Pin)
{
	  u8  u8Port;
	  u8   u8Pin;
	  u8Port = (Copy_u8Pin /16);
      u8Pin=  (Copy_u8Pin %16);
    u8 LOC_u8Result = 0;
    switch (u8Port)
    {


        case GPIOA:
            LOC_u8Result = READ_BIT (GPIO_A->IDR, u8Pin);
            break;



        case GPIOB:
            LOC_u8Result = READ_BIT (GPIO_B->IDR, u8Pin);
            break;



        case GPIOC:
            LOC_u8Result = READ_BIT (GPIO_C->IDR, u8Pin);
            break;

        default :       break;
    }
    return LOC_u8Result;
}


/*************   Function OF Toggle Pin Value   **********************/

void  GPIO_voidTogglePinValue (u8 Copy_u8Pin)
{
	  u8   u8Port;
	  u8   u8Pin;
	  u8Port = (Copy_u8Pin /16);
      u8Pin=  (Copy_u8Pin %16);

    switch (u8Port)
	{


		case GPIOA:
			TOGGLE_BIT(GPIO_A->ODR,u8Pin);
		  break;



		case GPIOB:
			TOGGLE_BIT(GPIO_B->ODR,u8Pin);
		  break;



		case GPIOC:
			TOGGLE_BIT(GPIO_C->ODR,u8Pin);
		  break;

		default :       break;
	}
}

/*************   Function OF Set Pin PULL   *************************/
/***************** Options of Copy_u8Pull:
                                            PULL_UP
                                           PULL_DOWN ***************/

void  GPIO_voidSetPinPull( u8 Copy_u8Pin, u8 Copy_u8Pull)
{
	    u8  u8Port;
        u8   u8Pin;
        u8Port = (Copy_u8Pin /16);
        u8Pin=  (Copy_u8Pin %16);

    switch (u8Port)
    {


        case GPIOA:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_A->ODR, u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_A->ODR, u8Pin);
            }
            break;



        case GPIOB:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_B->ODR, u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_B->ODR, u8Pin);
            }
            break;



        case GPIOC:
            if (Copy_u8Pull == PULL_UP)
            {
                SET_BIT (GPIO_C->ODR, u8Pin);
            }
            else if (Copy_u8Pull == PULL_DOWN)
            {
                CLR_BIT (GPIO_C->ODR, u8Pin);
            }
            break;

        default :       break;
    }
}

#endif
