#include "stm32f10x.h"                  // Device header
#include "Delay.h"
/** @brief 初始化按键，B11,B1
  * @param	无
  * @retval	无
  */
void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}
/** @brief 返回按键值，B1按键按下返回1，B11按键按下返回2，未按下返回0
  * @param	无
  * @retval	0，1，2
  */
uint8_t Key_GetNum(void){
	uint8_t KeyNum=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==1){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==1);
		Delay_ms(20);
		KeyNum=1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==1){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==1);
		Delay_ms(20);
		KeyNum=2;
	}
	return KeyNum;
}
/** @brief 改变A1LED灯状态
  * @param	无
  * @retval 无
  */
void LED1_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0) GPIO_SetBits(GPIOA,GPIO_Pin_1);
	else GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
/** @brief 改变A2LED灯状态
  * @param	无
  * @retval 无
  */
void LED2_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0) GPIO_SetBits(GPIOA,GPIO_Pin_2);
	else GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}


