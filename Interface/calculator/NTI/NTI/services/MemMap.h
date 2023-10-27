

#include "StdTypes.h"
#ifndef MEMMAP_H_
#define MEMMAP_H_

#define F_CPU    8000000
#include <util/delay.h>

#define  PORTA   (*(volatile unsigned char*)0X3B)
#define  DDRA    (*(volatile unsigned char*)0X3A)
#define  PINA    (*(volatile unsigned char*)0X39)

#define  PORTB   (*(volatile unsigned char*)0X38)
#define  DDRB    (*(volatile unsigned char*)0X37)
#define  PINB    (*(volatile unsigned char*)0X36)

#define  PORTC   (*(volatile unsigned char*)0X35)
#define  DDRC    (*(volatile unsigned char*)0X34)
#define  PINC    (*(volatile unsigned char*)0X33)

#define  PORTD   (*(volatile unsigned char*)0X32)
#define  DDRD    (*(volatile unsigned char*)0X31)
#define  PIND    (*(volatile unsigned char*)0X30)

/**********************************************************/
/**              External Interrupt Registers             */
/**********************************************************/
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0
/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0
/* MCUCSR */
#define JTD     7
#define ISC2    6
/* GIFR  */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* MCUCR: MCU Control Register */
#define MCUCR  *((volatile unsigned char* )0x55)

/* General Interrupt Control Register */
#define GICR   *((volatile unsigned char* )0x5B)

/* General Interrupt Flag Register */
#define GIFR   *((volatile unsigned char* )0x5A)

#define MCUCSR *((volatile unsigned char* )0x54)


/*External Interrupt Request 0*/
#define  INT0_vect				           __vector_1

/*External Interrupt Request 1*/
#define  INT1_vect					       __vector_2

/*External Interrupt Request 2*/
#define  INT2_vect					       __vector_3

/*Timer/Counter2 Compare Match*/
#define TIMER2_COMP_vect				   __vector_4

/*Timer/Counter2 Overflow*/
#define TIMER2_OV_vect					   __vector_5

/*Timer/Counter1 Capture Event*/
#define TIMER1_ICU_vect					   __vector_6

/*Timer/Counter1 Compare Match A*/
#define TIMER1_OCPA_vect				   __vector_7

/*Timer/Counter1 Compare Match B*/
#define TIMER1_OCB_vect				       __vector_8

/*Timer/Counter1 Overflow*/
#define TIMER1_OVF_vect					   __vector_9

/*Timer/Counter0 Compare Match*/
#define TIMER0_OC_vect					   __vector_10

/*Timer/Counter0 Overflow*/
#define TIMER0_OVF_vect					   __vector_11

/*Serial Transfer Complete*/
#define SPI_STC_vect					   __vector_12

/*USART, Rx Complete*/
#define UART_RXC_vect					   __vector_13

/*USART, Data Register Empty*/
#define USART_UDRE_vect					   __vector_14

/*USART, Tx Complete*/
#define UART_TX_vect					   __vector_15

/*ADC Conversion Complete*/
#define ADC_vect						   __vector_16

/*EEPROM Ready*/
#define EE_RDY_vect						   __vector_17

/*Analog Comparator*/
#define ANA_COMP_vect					   __vector_18

/*Two-wire Serial Interface*/
#define TWI_vect						   __vector_19

/*Storage Program Memory Ready*/
#define SPM_READY_vect					   __vector_20


///////////////////////////////////////////////////////
#define ISR(vector,...)	              \
void vector(void) __attribute__((signal))__VA_ARGS__ ; \
void vector(void)
///////////////////////////////////////////////////////
#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)
#define reti() __asm__ __volatile__ ("reti" ::)
#define ret()  __asm__ __volatile__ ("ret" ::)
////////////////////////////////////////////////////////
#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))

/*----------------------------------------------------------------*/



/************************************************************************/
/*						      	ADC         							*/
/************************************************************************/

#define ADMUX (*(volatile unsigned char*)0x27)

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)
#define ADC  (*(volatile unsigned short*)0x24)  //read two bytes adcl+adch

#endif /* MEMMAP_H_ */