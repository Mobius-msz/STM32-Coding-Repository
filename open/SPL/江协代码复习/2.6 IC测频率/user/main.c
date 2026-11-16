#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "PWM.h"
#include "IC.h"
int main(void){
	OLED_Init();
	IC_Init();
	PWM_Init();
	OLED_ShowString(1,1,"Freq:00000Hz");
	
	PWM_SetPrescaler(720-1);
	PWM_SetCompare1(50);
	while(1){
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
	
}
