#include "beep.h"
#include "Delay.h"

 int melody[] = {50, 50, 50, 50, 200, 200, 200, 400, 400, 500, 500, 500};
 
void BEEP_Init(void)
{ 
 GPIO_InitTypeDef  GPIO_InitStructure; 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 GPIO_SetBits(GPIOA,GPIO_Pin_4);
    
// GPIO_SetBits(GPIOA,GPIO_Pin_11);
}

void Sound(u16 frq)
{
    u32 time;
    if(frq != 1000)
    {
        time = 500000/((u32)frq);
        BEEP = 1;
        Delay_us(time);
        BEEP = 0;
        Delay_us(time);
    }else
        Delay_us(1000);
}
void Sound2(u16 time)
{
    BEEP = 1;
    Delay_ms(time);
    BEEP = 0;
    Delay_ms(time);
}

void play_successful(void)
{
    int id=0;
    for(id = 0 ;id < 12 ;id++)
    {
        Sound2(melody[id]);
    }
}
void play_failed(void)
{
    int id=0;
    for(id = 11 ;id >=0 ;id--)
    {
        Sound2(melody[id]);
    }
}
void play_music(void)
{    
//�캣���
//    uc16 tone[] = {247,262,294,330,349,392,440,294,523,587,659,698,784,1000};    
//    u8 music[]={5,5,6,8,7,6,5,6,13,13,5,5,6,8,7,6,5,3,13,13,2,2,3,5,3,5,6,3,2,1,6,6,5,6,5,3,6,5,13,13,
//                  5,5,6,8,7,6,5,6,13,13,5,5,6,8,7,6,5,3,13,13,2,2,3,5,3,5,6,3,2,1,6,6,5,6,5,3,6,1,    
//              13,8,9,10,10,9,8,10,9,8,6,13,6,8,9,9,8,6,9,8,6,5,13,2,3,5,5,3,5,5,6,8,7,6,6,10,9,9,8,6,5,6,8  };            
//    u8 time[] = {2,4,2,2,2,2,2,8,4, 4,2,4,2,2,2,2,2,8,4, 4, 2,4,2,4,2,2,4,2,2,8,2,4,2,2,2,2,2,8,4 ,4, 
//                2,4,2,2,2,2,2,8,4, 4,2,4,2,2,2,2,2,8,4,4,2,4,2,4,2,2,4,2,2,8,2,4,2,2,2,2,2,8,
//                4,2,2,2,4,2,2,2,2,2,8,4,2,2,2,4,2,2,2,2,2,8,4,2,2,2,4,2,2,5,2,6,2,4,2,2,2,4,2,4,2,2,12  };

/*************************************************************************************************************************/
    
//���տ���    
                  // 0   1   2   3   4   5   6   7  ��1  ��2 ��3 ��4 ��5 ��6��7
    uc16 tone[] ={250,262,294,330,350,393,441,495,525,589,661,700,786,882,990}; //����        
    u8 music[]={5,5,6,5,8,7,5,5,6,5,9,8,5,5,12,10,8,7,6,11,
                  11,10,8,9,8,5,5,8,5,5,12,10,8,7,6,11,11,10,8,9,8    //��������
    };     
        u8 time[] = {1,2,2,2,2,4,1,2,2,2,2,4,1,2,2,2,1,4,
                      4,1,2,2,2,2,4,1,2,4,1,2,2,2,1,4, 4,1,2,2,2,2,4,4        //����ʱ��
        }; 
                    
    u32 yanshi;
    u16 i,e;
    yanshi = 10;
    for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
        for(e=0;e<((u16)time[i])*tone[music[i]]/yanshi;e++){
            Sound((u32)tone[music[i]]);
        }    
    }
}
