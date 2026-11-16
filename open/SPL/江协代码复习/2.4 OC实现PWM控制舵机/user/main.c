#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "Delay.h"
#include "Servo.h"
uint8_t Angle;
int main(void){
	OLED_Init();
	Servo_Init();
	OLED_ShowString(1,1,"");
	while(1){
		for(Angle=0;Angle<180;Angle+=10){
			Servo_SetAngle(Angle);
			Delay_ms(40);
		}
		for(Angle=180;Angle>0;Angle-=10){
			Servo_SetAngle(Angle);
			Delay_ms(40);
		}
	}
	
}
