#include "stm32f10x.h"                  // Device header
/** @brief 初始化LEDA1,A2
  * @param	无
  * @retval	无
  */
void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);
}
/** @brief 点亮A1LED1
  * @param	无
  * @retval	无
  */
void LED1_ON(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
/** @brief 熄灭A1LED1
  * @param	无
  * @retval	无
  */
void LED1_OFF(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
/** @brief 点亮A2LED2
  * @param	无
  * @retval	无
  */
void LED2_ON(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
/** @brief 熄灭A2LED2
  * @param	无
  * @retval	无
  */
void LED2_OFF(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
