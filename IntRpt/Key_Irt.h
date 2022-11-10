#ifndef _Key_Int_H_
#define _Key_Int_H_



#include "stm32f10x.h"

// #define KEY1_INT_GPIO_PORT         GPIOB//组 PB
// #define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)//时钟需要开启AFIO 配置中断 APB2
// #define KEY1_INT_GPIO_PIN          GPIO_Pin_4//引脚

// #define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB//端口
// #define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource4//引脚
// #define KEY1_INT_EXTI_LINE         EXTI_Line0//中断线
// #define KEY1_INT_EXTI_IRQ          EXTI0_IRQn//中断源中断/事件
// #define KEY1_IRQHandler            EXTI4_IRQHandler//中断服务函数


void  Key1_Init(void);
void  Key2_Init(void);
#endif
