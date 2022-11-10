#include "led.h"
#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "key.h"
#define KEYSPEED1 100
#define KEYSPEED2 10
uint8_t a=0,b=0,c=0;


void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InisStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InisStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InisStructure.GPIO_Pin  =  KEY1|KEY2|KEY3;
	GPIO_InisStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEYPORT,&GPIO_InisStructure);
	//GPIO_SetBits(LEDPORT,LED1|LED2|LED3|BEE);
}

uint8_t KEY_GetNum(void)
{
    uint8_t KeyNum = 0;
    
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 0)
    {
        Delay_ms(20);   
        while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) == 0);  
        Delay_ms(20);   
        KeyNum = 1;

    }
    
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5) == 0)
    {
        Delay_ms(20); 
        while((KeyNum = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)) == 0);  
        Delay_ms(20);  
        KeyNum = 2;

    }
    
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6) == 0)
    {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6) == 0);  
        Delay_ms(20);
        KeyNum = 3;

    }
    
    return KeyNum;
}

void Key1Delay(void)
{
    if(!GPIO_ReadInputDataBit(GPIOB,KEY1))
    {
        Delay_ms(20);
        if(!GPIO_ReadInputDataBit(GPIOB,KEY1))
        {
            while (!GPIO_ReadInputDataBit(GPIOB,KEY1) && c<KEYSPEED1)
            {
                c++;
                Delay_ms(10);
            }
            if(c>=KEYSPEED1)//“ª¥Œ≥§∞¥
            {   
                
                LED_OFF();
                while (!GPIO_ReadInputDataBit(GPIOB,KEY1));//À… ÷ºÏ≤‚
              
                
            }
            else
            {
                for (b = 0; b< KEYSPEED2; b++)//À´ª˜ºÏ≤‚
                {
                    Delay_ms(20);
                    if (!GPIO_ReadInputDataBit(GPIOB,KEY1))
                    {
                        a=1;
                        
                        LED_Flu();
                        while (!GPIO_ReadInputDataBit(GPIOB,KEY1));//À… ÷ºÏ≤‚
                    }
                    
                }
                if(a == 0)
                {
                    LED_ON();
                }
                
            }
            a=0;
            c=0;
            
        }
        
    }

}
