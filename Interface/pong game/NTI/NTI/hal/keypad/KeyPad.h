

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "KeyPad_cfg.h"

void KEYPAD_Init(void);

u8 KEYPAD_GetKey(void);

void KEYPAD_InitNTI(void);

u8 KEYPAD_GetKeyNTI(void);

#endif /* KEYPAD_H_ */