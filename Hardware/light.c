#include "led.h"
#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "key.h"
#include "light.h"


void Light_Init(void)
{
	GPIO_InitTypeDef GPIO_InisStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);//��a2?������?����?����1?��
	GPIO_InisStructure.GPIO_Mode = GPIO_Mode_IPU;//�������룬1Ϊ����
	GPIO_InisStructure.GPIO_Pin  =  Light;
	GPIO_InisStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LEDPORT,&GPIO_InisStructure);
}


u8 LightseGet(void)
{
     return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7);
}
