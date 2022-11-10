#ifndef _LED_H_
#define _LED_H_

#define LEDPORT GPIOA
#define LED1 GPIO_Pin_1
#define LED2 GPIO_Pin_2
#define LED3 GPIO_Pin_3
#define BEE GPIO_Pin_4


void LED_Init(void);
void LED_Flu (void);
void LED_Flash(void);
void LED_Mix(int n);
void LED_ON(void);
void LED_OFF(void);
void Bee1(void);
void LED_Breath(void);
void Bee2(void);
void Music(void);
#endif
