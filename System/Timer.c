#include "stm32f10x.h"                  // Device header

//extern int Num;

void TIMER_Init(void)
{
	//1��RCC����ʱ��
	//2��ѡ��ʱ����Ԫ��ʱ��Դ
	//3������ʱ����Ԫ
	//4�������ж��������
	//5������NVIC
	//6���������п���
	
	//1��RCC����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//2��ѡ��ʱ����Ԫ��ʱ��Դ
	TIM_InternalClockConfig(TIM2);	//ѡ���ڲ�ʱ�ӣ���дҲ�У�Ĭ�Ͼ����ڲ�ʱ�ӣ�
	
	//3������ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;		//�ⲿʱ���˲���Ԫ�ķ�Ƶϵ����û�ã��������һ������
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	//ʱ�乫ʽCK_PSC / (PSC + 1) / (ARR + 1)  CK_PSC=72MHZ
	//��ʱ1S = 72MHZ/7200/10000
	TIM_TimeBaseInitStruct.TIM_Prescaler = 50000-1;					//��Ƶֵ
	TIM_TimeBaseInitStruct.TIM_Period = 7200-1;						//���ڣ�ARR�Զ���װ����ֵ
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter =0;				//�ظ���������ֵ���߼���ʱ�����У���0����
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	//TIM_TimeBaseInit�����Զ����»��һ���жϣ��������жϽ�����ϵ�ͻ��һ���жϵ�����
    TIM_ClearFlag(TIM2,TIM_FLAG_Update);
    
    
	//4�������ж��������
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//�����жϵ�NVICʹ��
	
	//5������NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//ѡ�����ȼ�����2
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	//6���������п���
	TIM_Cmd(TIM2, ENABLE);	//������ʱ��2
	
}

//void TIM2_IRQHandler(void)
//{
//    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//    {
//        Num++;
//        TIM_ClearITPendingBit(TIM2, TIM_IT_Update)
//    }
//}
