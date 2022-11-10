#ifndef __CNTSENSOR_H_
#define __CNTSENSOR_H_
void CNTSENSOR_Init(void);
uint16_t CNTSENSOR_Get(void);
void EXTI3_IRQHandler(void);
#endif
