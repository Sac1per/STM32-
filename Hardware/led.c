#include "led.h"
#include "stm32f10x.h" // Device header
#include "Delay.h"


uc16 music1[78]={ //音乐1的数�?�?（�?�数�?音调，偶数是长度�?
330,750,
440,375,
494,375,
523,750,
587,375,
659,375,
587,750,
494,375,
392,375,
440,1500,
330,750,
440,375,
494,375,
523,750,
587,375,
659,375,
587,750,
494,375,
392,375,
784,1500,
659,750,
698,375,
784,375,
880,750,
784,375,
698,375,
659,750,
587,750,
659,750,
523,375,
494,375,
440,750,
440,375,
494,375,
523,750,
523,750,
494,750,
392,750,
440,3000
};

void Music(void){ //MIDI音乐
	u16 i,e;
	for(i=0;i<39;i++){
		for(e=0;e<music1[i*2]*music1[i*2+1]/1000;e++){
			GPIO_WriteBit(LEDPORT,BEE,(BitAction)(0)); //蜂鸣器接口输�?0
			Delay_us(500000/music1[i*2]); //延时		
			GPIO_WriteBit(LEDPORT,BEE,(BitAction)(1)); //蜂鸣器接口输出高电平1
			Delay_us(500000/music1[i*2]); //延时	
		}	
	}
}


void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InisStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);//��a2?������?����?����1?��
	GPIO_InisStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InisStructure.GPIO_Pin  =  LED1|LED2|LED3|BEE;
	GPIO_InisStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LEDPORT,&GPIO_InisStructure);
	GPIO_SetBits(LEDPORT,LED1|LED2|LED3|BEE);
}


void LED_Flu(void)
{
			GPIO_WriteBit(LEDPORT,LED1,(BitAction)(0));
			Delay_ms(300);
			GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1));
	
			GPIO_WriteBit(LEDPORT,LED2,(BitAction)(0));
			Delay_ms(300);
			GPIO_WriteBit(LEDPORT,LED2,(BitAction)(1));
	
			GPIO_WriteBit(LEDPORT,LED3,(BitAction)(0));
			Delay_ms(300);
			GPIO_WriteBit(LEDPORT,LED3,(BitAction)(1));
}

void LED_Flash(void)
{
		LED_ON();
		Delay_ms(200);
		LED_OFF();
		Delay_ms(200);
}

void LED_ON(void)
{
	GPIO_ResetBits(LEDPORT,LED1|LED2|LED3);
}

void LED_OFF(void)
{
	GPIO_SetBits(LEDPORT,LED1|LED2|LED3);
}



void LED_Mix(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		LED_Flash();
	}
	for(j=0;j<n;j++)
	{
		LED_Flu();
	}
	

}

void LED_Breath(void)
{
	u8	flag;
	u16 t,i;
	flag=0;
	t=1;
	while (1)
	{
		
	if(flag == 0)//��
	{
		for(i = 0;i<20;i++)
		{
			LED_OFF();
			Delay_us(t);
			LED_ON();
			Delay_us(501-t);
		}
		t++;
		if(t==500)
		{
			flag=1;
		}
	 }
	if(flag == 1)//��
	{
		for(i = 0;i<20;i++)
		{
			LED_OFF();
			Delay_us(t);
			LED_ON();
			Delay_us(501-t);
		}
		t--;
		if(t==1)
		{
			flag=0;
		}
		}	
	}
	
	
}
void Bee1(void)
{
		u16  i;
		for ( i = 0; i < 200; i++)//调节蜂鸣器时�?
		{
			GPIO_ResetBits(LEDPORT,BEE);
			Delay_us(500);
			GPIO_SetBits(LEDPORT,BEE);
			Delay_us(500);//调节占空比发出不同�?�率的声�?
		}
		
		
}

void Bee2(void)
{
		u16  i;
		for ( i = 0; i < 300; i++)//调节蜂鸣器时�?
		{
			GPIO_ResetBits(LEDPORT,BEE);
			Delay_us(200);
			GPIO_SetBits(LEDPORT,BEE);
			Delay_us(300);//调节占空比发出不同�?�率的声�?
		}
		
		
}
