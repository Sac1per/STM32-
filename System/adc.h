#ifndef __ADC_H
#define __ADC_H


#define ADC1_DR_Address ((uint32_t)0x4001244C)

#define ADCPORT GPIOA
#define ADC_CH7 GPIO_Pin_7
#define ADC_CH3 GPIO_Pin_3

void ADC_Configuration(void);
void ADC_GPIO_Init(void);
void ADC_DMA_Init(void);
#endif
