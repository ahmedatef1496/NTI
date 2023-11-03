/*
 * us.h
 *
 * Created: 5/17/2023 3:42:56 PM
 *  Author: atef
 */ 


#ifndef US_H_
#define US_H_

#include "../../mcal/timer/icu/icu.h"



#define ICU_TRIGGER_CH     PINB3 


void US_init();
u8 US_getdistance(u16 *pu16_distance);



#endif /* US_H_ */