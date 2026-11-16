#include "stm32f10x.h"                  // Device header
#include <string.h>
uint16_t LED_Pin[]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5
		,GPIO_Pin_6,GPIO_Pin_7,GPIO_Pin_8,GPIO_Pin_9,GPIO_Pin_10,GPIO_Pin_11,GPIO_Pin_12
		,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15};
/** @brief 初始化
  * @param	无
  * @retval	无
  */
void LED_Init(GPIO_TypeDef *port, uint16_t Pins)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};

    if      (port == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    else if (port == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    else if (port == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    else if (port == GPIOD) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    else return;

    GPIO_InitStructure.GPIO_Pin   = Pins;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(port, &GPIO_InitStructure);

    GPIO_SetBits(port, Pins);
}
/** @brief 点亮A1LED1
  * @param	无
  * @retval	无
  */
void LED_ON(GPIO_TypeDef *port, uint16_t Pins){
	GPIO_ResetBits(port,Pins);
}
/** @brief 熄灭A1LED1
  * @param	无
  * @retval	无
  */
void LED_OFF(GPIO_TypeDef *port, uint16_t Pins){
	GPIO_SetBits(port,Pins);
}
void LED_Turn(GPIO_TypeDef *port, uint16_t Pin){
	if(GPIO_ReadInputDataBit(port,Pin)==RESET) GPIO_SetBits(port,Pin);
	else GPIO_ResetBits(port,Pin);
}
