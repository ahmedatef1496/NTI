/*
 * LCD_Cfg.h
 *
 * Created: 4/1/2023 4:11:09 PM
 *  Author: atef
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_



#define M_5X7_2lines          0x38
#define Display_ON_No_C       0x0c
#define Display_ON_C          0x0e
#define Display_ON_C_Blanking 0x0f
#define CLR_INS               0x01
#define increment_No_shift    0X06

#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT



#define  RS   PINA1
#define  RW   PINA2
#define  EN   PINA3
#define  D7   PINA7
#define  D6   PINA6
#define  D5   PINA5
#define  D4   PINA4

#define LCD_PORT  PB



#endif /* LCD_CFG_H_ */