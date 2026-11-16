#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "AD.h"
uint16_t ADValue;
float Votage;
int main(void){
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"ADValue:");
	OLED_ShowString(2,1,"Votage:0.00V");
	
	while(1){
		ADValue=AD_GetValue();
		Votage=(float)ADValue/4095*3.3;
		
		OLED_ShowNum(1,9,ADValue,4);
		OLED_ShowNum(2,8,Votage,1);
		OLED_ShowNum(2,10,(uint16_t)(Votage*100)%100,2);
		Delay_ms(100);
	}
	
}
