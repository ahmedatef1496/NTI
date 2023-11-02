/*
 * i2c.h
 *
 * Created: 4/29/2023 2:49:04 AM
 *  Author: atef
 */ 


#ifndef I2C_H_
#define I2C_H_ 
#include "../dio/dio.h"

#define write   0
#define read    1

#define ACK   0
#define NACK    1
/*------------------------------------------------------------------*/
/* I2C Status Bits in the TWSR Register */
#define START_STATE               0x08 // start has been sent
#define REP_START_STATE           0x10 // repeated start
#define SLA_W_ACK_STATE           0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define SLA_W_NACK_STATE          0x20
#define SLA_R_ACK_STATE           0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define SLA_R_NACK_STATE          0x48
#define DATA_WRITE_ACK_STATE      0x28 // Master transmit data and ACK has been received from Slave.
#define DATA_WRITE_NACK_STATE     0x30
#define DATA_READ_ACK_STATE       0x50 // Master received data and send ACK to slave
#define DATA_READ_NACK_STATE      0x58 // Master received data but doesn't send ACK to slave
/*-----------------------------------------------------------------------------------------*/
typedef enum I2CError {
EVENT_OK,
START_NOT_SENT,
REPEATED_START_NOT_SENT,
SLA_W_ACK_SENT,
SLA_W_NACK_SENT,
SLA_R_ACK_SENT,
SLA_R_NACK_SENT,
SLA_RW_FAILED,
DATA_WRITE_ACK_SENT,
DATA_WRITE_NACK_SENT,
DATA_WRITE_FAILED,
DATA_READ_ACK_SENT,
DATA_READ_NACK_SENT,
DATA_READ_FAILED
 
} en_I2CError_t;

/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
u8 I2C_getStatus(void);
u8 I2C_readWithACK(void);
u8 I2C_readWithNACK(void);
void I2C_init(void);
en_I2CError_t I2C_start(void);
en_I2CError_t I2C_repeated_start(void);
en_I2CError_t I2C_address_select(u8 adress,u8 rw);
en_I2CError_t I2C_data_rw(u8 *data,u8 rw,u8 ack);
void I2C_stop(void); 

/*-----------------------------------*/
 void I2C_WriteData(u8 data);
#endif /* I2C_H_ */