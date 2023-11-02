/*
 * eeprom.h
 *
 * Created: 5/1/2023 11:00:20 PM
 *  Author: atef
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "i2c.h"

void eeprom_init(void);
/*-------------------------16--------------------------*/
u8 EEPROM_writeByte(u16 u16addr, u8 u8data);
u8 EEPROM_readByte(u16 u16addr, u8 *u8data);
u8 eeprom_WriteString (u16 u16_Saddr, u8 *u8_Pdata);
u8 eeprom_ReadString (u16 u16_Saddr, u8 *u8_Pdata);
/*-------------------------256--------------------------*/
u8 EEPROM_writeByte_256(u16 u16_addr, u8 u8data);
u8 EEPROM_readByte_256(u16 u16addr, u8 *u8data);
u8 eeprom_WriteString_256 (u16 u16_Saddr, u8 *u8_Pdata);
u8 eeprom_ReadString_256 (u16 u16_Saddr, u8 *u8_Pdata);



void eeprom_test (void);
void eeprom_test_string(void);
void eeprom_test_256(void);
void eeprom_test_string_256(void);

#endif /* EEPROM_H_ */