/*
 * i2c_cfg.h
 *
 * Created: 4/29/2023 5:36:02 AM
 *  Author: atef
 */ 


#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#include "math.h"
#define  SCL_CLK  400000

/*************************************************************
 * Note: SCL frequency = (fOSC) / (16 + 2 (BIT_RATE) * 4 ^ (PRESCALE))
 *  BIT_RATE=((fOSC /SCL_CLK)-16/(2*(4^PRESCALE)))     
 * (1) PRESCALE (0 -> 3)
 * (2) BIT_RATE (0 -> 255)
 * 
 *************************************************************/
/* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
#define I2C_CFG_BITRATE                         12
#define I2C_CFG_PRESCALE                        0

/*OR*/

/*BITRATE GENERATOR */
#define  BITRATE(TWSR)  (((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))))





#endif /* I2C_CFG_H_ */