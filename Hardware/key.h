#ifndef _KEY_H_
#define _KEY_H_

#define KEYPORT GPIOB
#define KEY1 GPIO_Pin_4
#define KEY2 GPIO_Pin_5
#define KEY3 GPIO_Pin_6

void Key_Init(void);
uint8_t KEY_GetNum(void);
void Key1Delay(void);
#endif
