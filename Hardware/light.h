#ifndef _LIGHT_H_
#define _LIGHT_H_

#define LEDPORT GPIOA
#define Light   GPIO_Pin_7


void Light_Init(void);
u8 LightseGet(void);

#endif
