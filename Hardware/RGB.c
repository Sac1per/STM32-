#include "RGB.h"
#include "Delay.h"
void RGB_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//以GPIO_InitTyepeDef为原型的结构体GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOA时钟
  
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP ;//GPIO模式推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//GPIO速度50M
	GPIO_Init(GPIOB,&GPIO_InitStruct);//初始化GPIO
}


void RGB(uint32_t color)
{
	switch(color)
	{
		case RED:
        {
			LED_GREEN_OFF;
			LED_BLUE_OFF;
			LED_RED_ON;
		}
        break;
		case GREEN:
        {
			LED_RED_OFF;
			LED_BLUE_OFF;
			LED_GREEN_ON;
		}
        break;
		case BLUE:
        {
			LED_GREEN_OFF;
			LED_RED_OFF;
			LED_BLUE_ON;
		}
        break;
		case YELLOW:
        {
			LED_BLUE_OFF;
			LED_GREEN_ON;
			LED_RED_ON;
		}
        break;
		case PURPLE:
        {
			LED_BLUE_ON;
			LED_GREEN_OFF;
			LED_RED_ON;
		}
        break;
		case CYAN:
        {
			LED_BLUE_ON;
			LED_GREEN_ON;
			LED_RED_OFF;
		}
        break;
		case WHITE:
        {
			LED_BLUE_ON;
			LED_GREEN_ON;
			LED_RED_ON;
		}
        break;
		case BLACK:
        {
			LED_BLUE_OFF;
			LED_GREEN_OFF;
			LED_RED_OFF;
		}
        break;
		default:
        break;
	}
}

void Sevencol(uint32_t i)
{
    for(i = 0;i <8;i++)
		{
			RGB(i);
			Delay_ms(300);
		}
}


void Rainbow(void)
{
    uint32_t i;
    for(i = 0;i < 2000;i++)//红色混绿色，绿色由暗变量
		{
			LED_RED_ON ;
			LED_GREEN_ON;
			LED_BLUE_OFF;
			Delay_us(i);
			LED_RED_ON ;
			LED_GREEN_OFF;
			LED_BLUE_OFF;
			Delay_us(2000-i);
		}
		for(i = 0;i < 2000;i++)//红色混绿色，红色由亮变暗
		{
			LED_RED_OFF ;
			LED_GREEN_ON;
			LED_BLUE_OFF;
			Delay_us(i);
			LED_RED_ON ;
			LED_GREEN_ON;
			LED_BLUE_OFF;
			Delay_us(2000-i);
		}
		for(i = 0;i < 2000;i++)//绿色混蓝色，蓝色由暗变量
		{
			LED_GREEN_ON ;
			LED_BLUE_ON;
			LED_RED_OFF;
			Delay_us(i);
			LED_GREEN_ON ;
			LED_BLUE_OFF;
			LED_RED_OFF;
			Delay_us(2000-i);
		}
		for(i = 0;i < 2000;i++)//绿色混蓝色，绿色由亮变暗
		{
			LED_RED_OFF;
			LED_GREEN_OFF ;
			LED_BLUE_ON;
			Delay_us(i);
			LED_RED_OFF;
			LED_GREEN_ON ;
			LED_BLUE_ON;
			Delay_us(2000-i);
		}
			for(i = 0;i < 2000;i++)//红色混蓝色，红色由暗变量
		{
			LED_GREEN_OFF ;
			LED_BLUE_ON;
			LED_RED_ON;
			Delay_us(i);
			LED_GREEN_OFF ;
			LED_BLUE_ON;
			LED_RED_OFF;
			Delay_us(2000-i);
		}
		for(i = 0;i < 2000;i++)//红色混蓝色，蓝色由亮变暗
		{
			LED_RED_ON;
			LED_GREEN_OFF ;
			LED_BLUE_OFF;
			Delay_us(i);
			LED_RED_ON;
			LED_GREEN_OFF ;
			LED_BLUE_ON;
			Delay_us(2000-i);
		}
}


