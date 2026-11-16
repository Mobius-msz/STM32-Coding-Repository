#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "Encoder.h"
int16_t Num=0;
int main(void){
	Encoder_Init();
	OLED_Init();
	OLED_ShowString(1,1,"Count:");
	while(1){
		Num+=Encoder_Get();
		OLED_ShowSignedNum(1,7,Num,4);
		Delay_ms(100);
	}
	
}
