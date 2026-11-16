#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "Timer.h"
volatile uint16_t Count=0;
int main(void){
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"Time Count:....s");
	while(1){
		OLED_ShowNum(1,12,Count,4);
		Delay_ms(100);
	}
}
void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		Count++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
