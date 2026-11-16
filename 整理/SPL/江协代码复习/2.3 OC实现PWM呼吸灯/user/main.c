#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "PWM.h"
uint16_t i;
int main(void){
	OLED_Init();
	PWM_Init();
	OLED_ShowString(1,1,"");
	while(1){
		for(i=0;i<100;i++){
			PWM_SetCompare(i);
			Delay_ms(10);
		}
		for(i=100;i>0;i--){
			PWM_SetCompare(i);
			Delay_ms(10);
		}
	}
}
