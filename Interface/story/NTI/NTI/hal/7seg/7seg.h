/*
 * _7seg.h
 *
 * Created: 3/24/2023 11:39:34 AM
 *  Author: atef
 */ 

#include "../../mcal/dio/dio.h"

#ifndef _7SEG_H_
#define _7SEG_H_

void segmantt_display_C (volatile unsigned char* Reg , unsigned char number);
void segmantt_display_A (volatile unsigned char* Reg , unsigned char number);
void segmantt_display_2D(volatile unsigned char* Reg1 ,volatile unsigned char* Reg2 ,unsigned char number);
void segmantt_display_2D_HEX(volatile unsigned char* Reg1 ,volatile unsigned char* Reg2 ,unsigned char number);
void segmantt_display_BCD (volatile unsigned char* Reg , unsigned char number);
void segmantt_display_BCD_2D (volatile unsigned char* Reg , unsigned char number);
void segmantt_display_BCD_2D_HEX (volatile unsigned char* Reg , unsigned char number);
void segmantt_MUL_display_1D(volatile unsigned char* Reg , unsigned char number);
void segmantt_MUL_init(volatile unsigned char* Reg , unsigned char bit1,unsigned char bit2);
void PRO_segmantt_MUL_display_2D(volatile unsigned char* DReg ,volatile unsigned char* CReg , unsigned char bit1,unsigned char bit2, unsigned char number);
void KIT_segmantt_MUL_display_2D(volatile unsigned char* DReg ,volatile unsigned char* CReg , unsigned char bit1,unsigned char bit2, unsigned char number);





#endif /* 7SEG_H_ */