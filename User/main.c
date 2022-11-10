#include "stm32f10x.h" // Device header
#include "led.h"
#include "Delay.h"
#include "key.h"
#include "light.h"
#include "OLED.h"
#include "Func.h"
#include "Key_Irt.h"
#include "cntligelec.h"
#include "Turncnt.h"
#include "adc.h"
#include "HC_SR04.h"
#include "usart.h"
#include "dht11.h"
#include "RGB.h"
#include "servo.h"
#include "pwm.h"
int16_t Num;
uint32_t i;
extern uint16_t  ADC_DMA_IN[2];
//extern float Distance;
uint8_t B[2];
int main(void)
{
		 RGB_Init();
		Sevencol(i);
		//Delay_ms(2000);//DHT11用
		 SERVER_Init();
		
		// CNTSENSOR_Init();
	  	LED_Init();
		//Key_Init();
		// Light_Init();
		ADC_Configuration(); //ADC初始化设置
		OLED_Init();
   	Key1_Init();//按键1中断
		Key2_Init();
		// ENCODER_Init();
		OLED_ShowString(1,1,"SAC1");
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		//OLED_ShowString(4, 1,"dis:     cm");	
	 //HC_SR04_init();
		// USART1_Init(115200);
		if(DHT11_Init()==0)
		{ 	//DHT11初始化	返回0成功，1失败
			OLED_ShowString(1, 1,"Humidity:   %   ");
			//显示字符串
			OLED_ShowString(2, 1,"Temperature:   C");
		}
		else
		{
			OLED_ShowString(1, 1,"DHT11INIT ERROR!");
		}
		Delay_ms(2000);//DHT11初始化后必要的延时（不得小于1秒）
		OLED_ShowString(3,1,"LIT:");
		OLED_ShowString(4,1,"RIN:");
  	//HC_SR04_start(); 
		
		
		
	 while(1)
	 {
	 	LED_Flu();
	
		if(DHT11_ReadData(B)==0)
		{//读出温湿度值  指针1是湿度 20～90%，指针2是温度 0～50C，数据为十进制
			//OLED_ShowNum(1,10,B[0]/10,1);//显示湿度值
			OLED_ShowNum(1,10,B[0],2);//显示湿度值
			OLED_ShowNum(2,13,B[1],2);//显示湿度值
			//OLED_ShowNum(1,11,B[0]%10,1);//
			//OLED_ShowNum(2,13,B[1]/10,1);//显示温度值
			//OLED_ShowNum(2,14,B[1]%10,1);//
		}
		else
		{
			OLED_ShowString(1, 1,"DHT11INIT ERROR!"); //显示字符串
		}
		
		OLED_ShowNum(3,5,ADC_DMA_IN[0],4);
		OLED_ShowNum(4,5,ADC_DMA_IN[1],4);
		Delay_ms(2000); //延时，刷新数据的频率（不得小于1秒）
		
	  	
//		th=ADC_DMA_IN7/1000+0x30;
//		OLED_ShowString(2,1,"LIT");
//		//OLED_ShowNum(3,1,ADC_DMA_IN7+0x30,6);
//		OLED_ShowNum(3,1,th,1);
//		OLED_ShowNum(3,2,ADC_DMA_IN7%1000/100+0x30,1);
//		OLED_ShowNum(3,3,ADC_DMA_IN7%100/10+0x30,1);
//		OLED_ShowNum(3,4,ADC_DMA_IN7%10+0x30,1);
		
		
		//OLED_ShowNum(3,5,TIM_GetCounter(TIM2),4);	
		//OLED_ShowNum(4,5,s,4);	
		//Delay_ms(500); //延时
		if(B[0]+B[0]%10 < 60 && B[1]+B[1]%10 >25 && ADC_DMA_IN[0]<2000 && ADC_DMA_IN[1]>3000)
		{
			LED_Mix(2);
			Bee2();
			TIM_SetCompare1(TIM3,2700);
			Delay_s(1);
			TIM_SetCompare1(TIM3,500);
		}
	
	
	 }
 }


