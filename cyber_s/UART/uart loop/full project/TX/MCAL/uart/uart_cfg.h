/*
 * uart.h
 *
 * Created: 5/11/2023 11:12:28 PM
 *  Author: atef
 */ 


#ifndef UART_H_
#define UART_H_

#define UART_BAUDRATE         9600

#define UART_DATA_BITS        8        /* 5, 6, 7, 8, or 9 */

#define UART_PARITY_BIT       0        /* 0=OFF  1=ODD  2=EVEN */

#define UART_STOP_BITS        1        /* 1 or 2 */

typedef enum
{
	DEVICE_0,
	DEVICE_1,
	DEVICE_2,
	TOTAL_DEVICES
}en_UART_DeviceS_t;

typedef enum
{
	NORMAL_SPEED,
	DOUBLE_SPEED,
	TOTAL_SPEED_MODE
} en_UART_SPEED_MODE_t;

typedef enum
{
	_4_MHZ,
	_8_MHZ,
	_16_MHZ,
	TOTAL_CPU_F
} en_UART_CPU_F_t;

typedef enum
{
	BAUD_2400,
	BAUD_4800,
	BAUD_9600,
	BAUD_14400,
	BAUD_19200,
	BAUD_28800,
	TOTAL_BAUD_RATE
} en_UART_BUAD_RATE_t;

typedef enum
{
	NO_PARITY,
	EVEN_PARITY,
	ODD_PARITY
} en_UART_PARITY_MODE_t;

typedef enum
{
	ASYNCHRONOUS,
	SYNCHRONOUS
} en_UART_SYNCH_MODE_t;

typedef enum
{
	_5_DATA_BITS,
	_6_DATA_BITS,
	_7_DATA_BITS,
	_8_DATA_BITS,
	_9_DATA_BITS,
} en_UART_N_DATA_BITS_t;

typedef enum
{
	ONE_STOP_BIT,
	TWO_STOP_BIT
} en_UART_N_STOP_BITS_t;


typedef enum
{
	TRANSMITTER  ,
	RECEIVER	   ,
	TRANSCEIVER
}en_UART_Device_role_t;

typedef struct{
	en_UART_Device_role_t    Device_role;
	en_UART_SPEED_MODE_t     SPEED_MODE ;
	en_UART_CPU_F_t          CPU_F ;
	en_UART_BUAD_RATE_t      BUAD_RATE;
	en_UART_PARITY_MODE_t    SYNCH_MODE;
	en_UART_SYNCH_MODE_t     PARITY_MODE;
	en_UART_N_DATA_BITS_t    N_DATA_BITS;
	en_UART_N_STOP_BITS_t    N_STOP_BITS;
	
}ST_UART_cfg;

#endif /* UART_H_ */