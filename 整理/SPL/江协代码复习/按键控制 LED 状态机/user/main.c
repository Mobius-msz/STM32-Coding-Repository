#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
int main(void){
	OLED_Init();
	OLED_ShowString(1,1,"");
	while(1){
		
	}
	
}
