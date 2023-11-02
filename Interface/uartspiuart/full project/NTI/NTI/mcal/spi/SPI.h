

#ifndef SPI_H_
#define SPI_H_
#include "../dio/dio.h"

typedef enum{
	SLAVE,
	MASTER
	
	
	}SPI_Mode_type;


void SPI_Init(SPI_Mode_type mode);

void SPI_SendReceive(u8 *data);

void SPI_SendNoBlock(u8 data);

u8 SPI_ReceivePerodic(u8*pdata);


/*Enable SPI Interrupt Mode*/
/*
 * ENABLE_INTERRUPT
 * DISABLE_INTERRUPT
 *
 */
 
#define INTERRUPT_MODE ENABLE_INTERRUPT

/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define DATA_ORDER  LSB_FIRST

/*Master or Slave Select*/
/*
 * MASTER
 * SLAVE
 *
 */

#define MASTER_SLAVE_MODE  MASTER
/*
 * Clock Polarity mode
 * IDLE_LOW >> leading edge is rising
 * IDLE_HIGH >> leading edge is falling
 *
 */
#define CLOCK_POLARITY  IDLE_LOW


/* Clock Phase Mode
 *
 * ZERO >> sample at leading and setup at trailing
 * ONE >> sample at trailing and setup at rising
 *
 */

#define CLOCK_PHASE ZERO

/* CLOCK
 *
 * MODE_F/4
 * MODE_F/2
 *
 */

#define SPI_FREQUENCY  QUARTER_FREQ


#endif /* SPI_H_ */