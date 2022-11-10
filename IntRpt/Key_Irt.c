#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "servo.h"
//光电开关接Do接PB10
void Key1_Init(void)
{
    //外部中断配置步骤，看EXTI基本结构图
    //1、开启RCC时钟
    //2、配置GPIO
    //3、配置AFIO选择中断引脚
    //4、配置EXIT选择触发方式
    //5、配置NVIC：优先级
    
    //1、开启RCC时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //AFIO时钟
    //EXIT不需要开启时钟，NVIC内核外设（不需要开启时钟）不是挂载在APB2总线的
    

    //2、配置GPIO
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//技术手册表31 EXTI输入线配置模式
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    //3、配置AFIO选择中断引脚（stm32f10x_gpio.h中）
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource4);//AFIO中断选择函数，外部中断线4
    
    //4、配置EXIT选择触发方式
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line4;            //中断线路4
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //中断还是事件选择
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //开启中断线
    EXTI_Init(&EXTI_InitStruct);
    
    //5、配置NVIC：优先级（内核外设都在杂项  misc.h里面）
   
    NVIC_InitTypeDef NVIC_InitStruct;
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;       //中断通道选择
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //抢占优先级（多个中断才有作用）
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //响应优先级（多个中断才有作用）
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //通道开启
    NVIC_Init(&NVIC_InitStruct);
}


void Key2_Init(void)
{
    //外部中断配置步骤，看EXTI基本结构图
    //1、开启RCC时钟
    //2、配置GPIO
    //3、配置AFIO选择中断引脚
    //4、配置EXIT选择触发方式
    //5、配置NVIC：优先级
    
    //1、开启RCC时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //AFIO时钟
    //EXIT不需要开启时钟，NVIC内核外设（不需要开启时钟）不是挂载在APB2总线的
    

    //2、配置GPIO
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//技术手册表31 EXTI输入线配置模式
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    //3、配置AFIO选择中断引脚（stm32f10x_gpio.h中）
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);//AFIO中断选择函数，外部中断线4
    
    //4、配置EXIT选择触发方式
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line5;            //中断线路4
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;    //中断还是事件选择
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;              //开启中断线
    EXTI_Init(&EXTI_InitStruct);
    
    //5、配置NVIC：优先级（内核外设都在杂项  misc.h里面）
   
    NVIC_InitTypeDef NVIC_InitStruct;
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;       //中断通道选择
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  //抢占优先级（多个中断才有作用）
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;         //响应优先级（多个中断才有作用）
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //通道开启
    NVIC_Init(&NVIC_InitStruct);
}



void  EXTI4_IRQHandler(void)
{
  //获取中断线EXTI line状态
	if(EXTI_GetITStatus(EXTI_Line4) != RESET) 
	{
		TIM_SetCompare1(TIM3,2700);
	
		EXTI_ClearITPendingBit(EXTI_Line4);     
	}  
}
void  EXTI9_5_IRQHandler(void)
{
  //获取中断线EXTI line状态
	if(EXTI_GetITStatus(EXTI_Line5) != RESET) 
	{
		TIM_SetCompare1(TIM3,500);
	
		EXTI_ClearITPendingBit(EXTI_Line5);     
	}  
}

