#include "stm32f10x.h"                  // Device header


//��翪�ؽ�Do��PA3
void CNTSENSOR_Init(void)
{
    //�ⲿ�ж����ò��裬��EXTI�����ṹͼ
    //1������RCCʱ��
    //2������GPIO
    //3������AFIOѡ���ж�����
    //4������EXITѡ�񴥷���ʽ
    //5������NVIC�����ȼ�
    
    //1������RCCʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//GPIOBʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //AFIOʱ��
    //EXIT����Ҫ����ʱ�ӣ�NVIC�ں����裨����Ҫ����ʱ�ӣ����ǹ�����APB2���ߵ�
    

    //2������GPIO
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//�����ֲ��31 EXTI����������ģʽ
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    //3������AFIOѡ���ж����ţ�stm32f10x_gpio.h�У�
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);//AFIO�ж�ѡ�������ⲿ�ж���10
    
    //4������EXITѡ�񴥷���ʽ
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line0;            //�ж���·10
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //�жϻ����¼�ѡ��
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //�����ж���
    EXTI_Init(&EXTI_InitStruct);
    
    //5������NVIC�����ȼ����ں����趼������  misc.h���棩
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //NVIC���ȼ�����,��������ֻ������һ�Σ���main��ã�
    NVIC_InitTypeDef NVIC_InitStruct;
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;       //�ж�ͨ��ѡ��
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //��Ӧ���ȼ�������жϲ������ã�
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //ͨ������
    NVIC_Init(&NVIC_InitStruct);
}

uint16_t CntSensor_Cnt = 0;
//startup_stm32f10x_ld.s����ø��жϺ���
//void EXTI0_IRQHandler(void)
//{
//    if(EXTI_GetITStatus(EXTI_Line0) == SET)//�ж��Ƿ����ж�10����
//    {
//        CntSensor_Cnt++;
//        EXTI_ClearITPendingBit(EXTI_Line0);//����жϱ�־
//    }
//}

uint16_t CNTSENSOR_Get(void)
{
    return CntSensor_Cnt;
}
