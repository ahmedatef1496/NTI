/*
 * app.h
 *
 * Created: 10/17/2023 2:42:56 PM
 *  Author: atef
 */ 


#ifndef APP_H_
#define APP_H_

#include "../hal/lcd/lcd.h"
#include "../mcal/dio/dio.h"
#include "../hal/button/button.h"
#include "../hal/keypad/KeyPad.h"
#include "../mcal/exi/exi.h"
#include "../hal/lm35/lm35.h"
#include "../hal/ldr/ldr.h"
//#include "../mcal/timer/timer.h"


void pong_init();
void movePlayers(void);
// void PongGame();
// void PongGameV2();
 void PongGameV3();
 void calculator ();
// void story ();
#endif /* APP_H_ */