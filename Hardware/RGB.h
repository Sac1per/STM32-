#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define LED_RED_ON GPIO_SetBits(GPIOB,GPIO_Pin_13)			//红色亮
#define LED_RED_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_13)	//红色灭
#define LED_GREEN_ON GPIO_SetBits(GPIOB,GPIO_Pin_14)			//绿色亮
#define LED_GREEN_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_14)	//绿色灭
#define LED_BLUE_ON GPIO_SetBits(GPIOB,GPIO_Pin_15)			//蓝色亮
#define LED_BLUE_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_15)	//蓝色灭

#define RED 0
#define GREEN 1
#define BLUE 2
#define PURPLE 3
#define CYAN 4
#define YELLOW 5
#define WHITE 6
#define BLACK 7

void RGB_Init(void);
void RGB(uint32_t color);
void Rainbow(void);
void Sevencol(uint32_t i);
void TIM3_Int_Init(u16 arr,u16 psc);

