#ifndef _Key_Int_H_
#define _Key_Int_H_



#include "stm32f10x.h"

// #define KEY1_INT_GPIO_PORT         GPIOB//�� PB
// #define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)//ʱ����Ҫ����AFIO �����ж� APB2
// #define KEY1_INT_GPIO_PIN          GPIO_Pin_4//����

// #define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB//�˿�
// #define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource4//����
// #define KEY1_INT_EXTI_LINE         EXTI_Line0//�ж���
// #define KEY1_INT_EXTI_IRQ          EXTI0_IRQn//�ж�Դ�ж�/�¼�
// #define KEY1_IRQHandler            EXTI4_IRQHandler//�жϷ�����


void  Key1_Init(void);
void  Key2_Init(void);
#endif
