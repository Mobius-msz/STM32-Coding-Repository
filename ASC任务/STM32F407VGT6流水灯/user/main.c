#include "stm32f4xx.h"                  // Device header
#include "Delay.h"
#include "LED.h"

int main(void)
{
	LED_Init();							//初始化LED，PD12~PD15
	
	while(1)
	{
		/* 正向流水：LED1 -> LED2 -> LED3 -> LED4 */
		LED_AllOff(); LED1_ON(); Delay_ms(200);
		LED_AllOff(); LED2_ON(); Delay_ms(200);
		LED_AllOff(); LED3_ON(); Delay_ms(200);
		LED_AllOff(); LED4_ON(); Delay_ms(200);
		
		/* 反向流水：LED3 -> LED2 */
		LED_AllOff(); LED3_ON(); Delay_ms(200);
		LED_AllOff(); LED2_ON(); Delay_ms(200);
	}
}
