#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "servo.h"
//��翪�ؽ�Do��PB10
void Key1_Init(void)
{
    //�ⲿ�ж����ò��裬��EXTI�����ṹͼ
    //1������RCCʱ��
    //2������GPIO
    //3������AFIOѡ���ж�����
    //4������EXITѡ�񴥷���ʽ
    //5������NVIC�����ȼ�
    
    //1������RCCʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//GPIOBʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //AFIOʱ��
    //EXIT����Ҫ����ʱ�ӣ�NVIC�ں����裨����Ҫ����ʱ�ӣ����ǹ�����APB2���ߵ�
    

    //2������GPIO
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//�����ֲ��31 EXTI����������ģʽ
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    //3������AFIOѡ���ж����ţ�stm32f10x_gpio.h�У�
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource4);//AFIO�ж�ѡ�������ⲿ�ж���4
    
    //4������EXITѡ�񴥷���ʽ
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line4;            //�ж���·4
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //�жϻ����¼�ѡ��
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //�����ж���
    EXTI_Init(&EXTI_InitStruct);
    
    //5������NVIC�����ȼ����ں����趼������  misc.h���棩
   
    NVIC_InitTypeDef NVIC_InitStruct;
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;       //�ж�ͨ��ѡ��
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //��Ӧ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //ͨ������
    NVIC_Init(&NVIC_InitStruct);
}


void Key2_Init(void)
{
    //�ⲿ�ж����ò��裬��EXTI�����ṹͼ
    //1������RCCʱ��
    //2������GPIO
    //3������AFIOѡ���ж�����
    //4������EXITѡ�񴥷���ʽ
    //5������NVIC�����ȼ�
    
    //1������RCCʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//GPIOBʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //AFIOʱ��
    //EXIT����Ҫ����ʱ�ӣ�NVIC�ں����裨����Ҫ����ʱ�ӣ����ǹ�����APB2���ߵ�
    

    //2������GPIO
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//�����ֲ��31 EXTI����������ģʽ
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    //3������AFIOѡ���ж����ţ�stm32f10x_gpio.h�У�
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);//AFIO�ж�ѡ�������ⲿ�ж���4
    
    //4������EXITѡ�񴥷���ʽ
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line5;            //�ж���·4
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //�жϻ����¼�ѡ��
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //�����ж���
    EXTI_Init(&EXTI_InitStruct);
    
    //5������NVIC�����ȼ����ں����趼������  misc.h���棩
   
    NVIC_InitTypeDef NVIC_InitStruct;
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;       //�ж�ͨ��ѡ��
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //��Ӧ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //ͨ������
    NVIC_Init(&NVIC_InitStruct);
}



void  EXTI4_IRQHandler(void)
{
  //��ȡ�ж���EXTI line״̬
	if(EXTI_GetITStatus(EXTI_Line4) != RESET) 
	{
		TIM_SetCompare1(TIM3,2700);
	
		EXTI_ClearITPendingBit(EXTI_Line4);     
	}  
}
void  EXTI9_5_IRQHandler(void)
{
  //��ȡ�ж���EXTI line״̬
	if(EXTI_GetITStatus(EXTI_Line5) != RESET) 
	{
		TIM_SetCompare1(TIM3,500);
	
		EXTI_ClearITPendingBit(EXTI_Line5);     
	}  
}

