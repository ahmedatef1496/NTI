/*
 * _7seg.c
 *
 * Created: 3/24/2023 6:04:48 AM
 *  Author: atef
 */ 
#include "7seg.h"

void segmantt_display_C(volatile unsigned char* Reg, unsigned char number)  //one 7seg (common cathode) , one digit , one port ,number max 15
{
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	*Reg= segmatArr[number];

}


void segmantt_display_A(volatile unsigned char* Reg, unsigned char number)  //one 7seg (common Anode) , one digit , one port ,number max 15
{
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	*Reg =~segmatArr[number];

}



void segmantt_display_2D(volatile unsigned char* Reg1,volatile unsigned char* Reg2,unsigned char number)   //two 7seg (common cathode) , two digit , two port ,number max 99
{
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	unsigned char d1,d2;
	d1=number%10;
	d2=number/10;
	*Reg1=segmatArr[d1];
	*Reg2=segmatArr[d2];


}


void segmantt_display_2D_HEX(volatile unsigned char* Reg1,volatile unsigned char* Reg2,unsigned char number)   //two 7seg (common cathode) , two digit , two port ,number max 255
{
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	unsigned char d1,d2;
	d1=number & 0x0f;
	d2=number>>4;
	*Reg1=segmatArr[d1];
	*Reg2=segmatArr[d2];


}


void segmantt_display_BCD (volatile unsigned char* Reg, unsigned char number)  //7Seg with BCD
{

	*Reg=number;
}


void segmantt_display_BCD_2D_HEX (volatile unsigned char* Reg, unsigned char number) //7Seg with BCD  HEX
{
	*Reg=number;
}
void segmantt_display_BCD_2D (volatile unsigned char* Reg, unsigned char number) //7Seg with BCD    DEC
{
	unsigned char d1,d2;
	d1=number%10;
	d2=number/10;
	*Reg=0;
	*Reg|=d2<<4;
	*Reg|=d1;
}

void segmantt_MUL_init(volatile unsigned char* Reg, unsigned char bit1,unsigned char bit2)   // MUltiplexed 7 segment initialization
{
	CLR_BIT(*Reg,bit1);
	CLR_BIT(*Reg,bit2);

}
void segmantt_MUL_display_1D(volatile unsigned char* Reg, unsigned char number)   // MUltiplexed 7 segment display 1 same number on all digits
{
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	*Reg =segmatArr[number]<<1;

}

void PRO_segmantt_MUL_display_2D(volatile unsigned char* DReg,volatile unsigned char* CReg, unsigned char bit1,unsigned char bit2, unsigned char number)
{
	unsigned char d0,d1;
	int i;
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	d0=number%10;
	d1=number/10;
	for (i=0; i<250; i++)
	{

		SET_BIT(*CReg,6);
		*DReg =segmatArr[d0]<<1;
		CLR_BIT(*CReg,7);
		_delay_ms(1);
		SET_BIT(*CReg,7);
		*DReg =segmatArr[d1]<<1;
		CLR_BIT(*CReg,6);
		_delay_ms(1);
	}

}



void KIT_segmantt_MUL_display_2D(volatile unsigned char* DReg,volatile unsigned char* CReg, unsigned char bit1,unsigned char bit2, unsigned char number)
{
	unsigned char d1,d2;
	int i;
	unsigned char segmatArr[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	d1=number%10;
	d2=number/10;
	for (i=0; i<250; i++)
	{


		*DReg =segmatArr[d1]<<1;
		CLR_BIT(*CReg,7);
		SET_BIT(*CReg,6);
		_delay_ms(1);
		*DReg =segmatArr[d2]<<1;
		CLR_BIT(*CReg,6);
		SET_BIT(*CReg,7);
		_delay_ms(1);
	}

}
