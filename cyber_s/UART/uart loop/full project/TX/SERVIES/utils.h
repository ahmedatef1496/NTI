/*
 * utils.h
 *
 * Created: 4/13/2023 6:43:51 AM
 *  Author: atef
 */ 


#ifndef UTILS_H_
#define UTILS_H_



#define F_CPU    8000000
#include <util/delay.h>

#define  SET_BIT(reg,bit)     (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)     (reg=reg&~(1<<bit))
#define  TGL_BIT(reg,bit)     (reg=reg^(1<<bit))
#define  READ_BIT(reg,bit)    ((reg>>bit)&1)     //(reg &(1<<bit))


#endif /* UTILS_H_ */