#include "stm32f10x.h"                  // Device header
#include "Delay.h"
/** @brief 初始化按键，B11,B1
  * @param	无
  * @retval	无
  */
void Key_Init(GPIO_TypeDef *port, uint16_t Pins,uint8_t If_Up){
	if      (port == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    else if (port == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    else if (port == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    else if (port == GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    else return;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	if(If_Up) GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	else GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=Pins;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(port,&GPIO_InitStructure);
}
/** @brief 返回按键值，B1按键按下返回1，B11按键按下返回2，未按下返回0
  * @param	无
  * @retval	0，1，2
  */

uint8_t Read_Key(GPIO_TypeDef *port, uint16_t Pin){
	if(GPIO_ReadInputDataBit(port,Pin)==RESET) return 1;
	else return 0;
}
void Key_Loop(void){
	
}

