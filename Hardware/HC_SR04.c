#include "stm32f10x.h"                  // Device header
#include "HC_SR04.h"
#include "Delay.h"
#include "OLED.h"
#include "led.h"
#include "sys.h"
float Distance;

void Init_TIM2(void)
{
   

	//1���ܶ�ʱ��ʱ�ӡ�
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;	
	TIM_TimeBaseInitStruct.TIM_Prescaler    = 7199;    //84��Ƶ 84000 000/84 = 1MHZ  1us
	TIM_TimeBaseInitStruct.TIM_Period		= 50000-1;  //��50000���� ��10000HZ�£���ʱ1s
	TIM_TimeBaseInitStruct.TIM_CounterMode  = TIM_CounterMode_Up; //���ϼ���
	TIM_TimeBaseInitStruct.TIM_ClockDivision= TIM_CKD_DIV1; //��Ƶ����
	//2����ʼ����ʱ��������ARR,PSC��
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);		
	
	
	TIM_Cmd(TIM2, ENABLE);
}


void HC_SR04_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(HC_SR04_TRIG_CLK|HC_SR04_ECHO_CLK, ENABLE);	 //ʹ��PB�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
	
	GPIO_InitStructure.GPIO_Pin = HC_SR04_TRIG_PIN;//Trig
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(HC_SR04_TRIG_PORT, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = HC_SR04_ECHO_PIN;//Echo
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		 //xia��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(HC_SR04_ECHO_PORT, &GPIO_InitStructure);
	

	GPIO_EXTILineConfig(HC_SR04_ECHO_EXTI_PORT_SOURCE,HC_SR04_ECHO_EXTI_PIN_SOURCE);
 
	EXTI_InitStructure.EXTI_Line=EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//�����ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ�2�� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					//�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);
 	Init_TIM2();

	
}



void HC_SR04_start(void)
{
	GPIO_SetBits(HC_SR04_TRIG_PORT,HC_SR04_TRIG_PIN);
	Delay_us(20);
	// GPIO_ResetBits(HC_SR04_TRIG_PORT,HC_SR04_TRIG_PIN);
	// Delay_ms(10);
	//GPIO_WriteBit(LEDPORT,LED1,(BitAction)(!GPIO_ReadOutputDataBit(LEDPORT,LED1)));
	//LED_Flash();
}


void EXTI15_10_IRQHandler(void)
{			
	Delay_us(10);
	//OLED_Clear();
	if(EXTI_GetITStatus(EXTI_Line12) != RESET)
	{
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5) == RESET);
		TIM_SetCounter(TIM2,0);  //��������
		TIM_Cmd(TIM2,ENABLE);  //ʹ��TIM3��ʱ��
		
		while(GPIO_ReadInputDataBit(HC_SR04_ECHO_PORT,HC_SR04_ECHO_PIN));  //�ȴ���ƽ��Ϊ�͵�ƽ
		
		TIM_Cmd(TIM2,DISABLE); //�رն�ʱ��
		
		Distance = TIM_GetCounter(TIM2)*340/200.0;  //������룺cnt * 1/10000 * 340 / 2(��λ��m)
		
		//printf("Counter:%d\n",TIM_GetCounter(TIM3));
		//printf("Distance:%f cm\r\n",Distance);
		OLED_ShowNum(4,5,Distance,4);	
		EXTI_ClearITPendingBit(EXTI_Line12);


	}  
}

