#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void){
	PWM_Init();
}
void Servo_SetAngle(uint8_t Angle){
	PWM_SetCompare(25 + (uint16_t)(Angle * 100UL / 180));
}
