#ifndef __HC_SR04_H
#define __HC_SR04_H
 
#include "stm32f10x.h"
 
#define HC_SR04_TRIG_CLK   RCC_APB2Periph_GPIOB
#define HC_SR04_TRIG_PORT  GPIOB
#define HC_SR04_TRIG_PIN   GPIO_Pin_3
 
#define HC_SR04_ECHO_CLK   RCC_APB2Periph_GPIOA
#define HC_SR04_ECHO_PORT  GPIOA
#define HC_SR04_ECHO_PIN   GPIO_Pin_12
 
#define HC_SR04_ECHO_EXTI_PORT_SOURCE   GPIO_PortSourceGPIOA
#define HC_SR04_ECHO_EXTI_PIN_SOURCE  GPIO_PinSource12
 

extern float Distance;


void HC_SR04_init(void);
void HC_SR04_start(void);

 
#endif /* __HC_SR04_H*/
