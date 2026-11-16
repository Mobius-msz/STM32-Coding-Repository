#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "Timer.h"
int16_t Num=0;
int main(void){
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"Count:");	
	while(1){
		OLED_ShowSignedNum(1,7,Num,5);
	}
	
}

void TIM2_IRQHandler(void)//Interrupt Request Handler(中断处理函数)函数名在startup文件DCD
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
