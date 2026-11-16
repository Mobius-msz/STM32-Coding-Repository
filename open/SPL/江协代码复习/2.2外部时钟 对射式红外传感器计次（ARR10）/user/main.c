#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "Timer.h"
int main(void){
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"Count:");
	while(1){
		OLED_ShowNum(1,7,Timer_GetCounter(),5);
		Delay_ms(100);
	}
}
void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

