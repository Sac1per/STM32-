#include "servo.h"
uint16_t Ser[5]={500,1000,1500,2000,2500};

void SERVER_Init(void)
{
    PWM_Init();
}

// void SERVER_SetAngle(float Angle)
// {

//     PWM_Setcompare1(Angle / 180 *2000+500);
// }

//void ServoAuto(void)
//{
//    uint8_t i,j;
//    
//    for(i=0;i<4;i++)
//    {
//      PWM_Setcompare1(Ser[i]);
//      Delay_s(1);
//    }

//    for(j=3;i>=0;j--)
//    {
//      PWM_Setcompare1(Ser[j]);
//      Delay_s(1);
//    }


//}
void ServoAuto(void)
{
   PWM_Setcompare1(500);
	
}
