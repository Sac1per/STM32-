#ifndef __SERVER_H_
#define __SERVER_H_


#include "stm32f10x.h"                  // Device header
#include "pwm.h"
#include "Delay.h"

void SERVER_Init(void);
//void SERVER_SetAngle(float Angle);
void ServoAuto(void);
#endif
