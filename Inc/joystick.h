#include "stm32f30x_conf.h" // STM32 config
#include "ansi.h"
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

void intiJoystick();
void readJoystick();

typedef struct{
	int8_t up, down, left , right, center;
} reJoy_s;

volatile reJoy_s joy;
volatile reJoy_s key;

#endif /* JOYSTICK_H_ */
