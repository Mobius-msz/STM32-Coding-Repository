#include "stm32f4xx.h"                  // Device header

/**
  * 说明：本板4颗LED接在PD12~PD15，阳极经330Ω电阻接VDD，阴极接GPIO
  *       ==> 输出低电平点亮，输出高电平熄灭
  *
  *       LED1 -> PD12 -> R20 330R -> 板上丝印 LED4 (黄绿)
  *       LED2 -> PD13 -> R11 330R -> 板上丝印 LED8 (红)
  *       LED3 -> PD14 -> R21 330R -> 板上丝印 LED2 (超红)
  *       LED4 -> PD15 -> R22 330R -> 板上丝印 LED3 (黄)
  */

/**
  * @brief  初始化LED，PD12~PD15
  * @param  无
  * @retval 无
  */
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);	//上电全部熄灭
}

/**
  * @brief  点亮LED1（PD12）
  * @param  无
  * @retval 无
  */
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}

/**
  * @brief  熄灭LED1（PD12）
  * @param  无
  * @retval 无
  */
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_12);
}

/**
  * @brief  点亮LED2（PD13）
  * @param  无
  * @retval 无
  */
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);
}

/**
  * @brief  熄灭LED2（PD13）
  * @param  无
  * @retval 无
  */
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_13);
}

/**
  * @brief  点亮LED3（PD14）
  * @param  无
  * @retval 无
  */
void LED3_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_14);
}

/**
  * @brief  熄灭LED3（PD14）
  * @param  无
  * @retval 无
  */
void LED3_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_14);
}

/**
  * @brief  点亮LED4（PD15）
  * @param  无
  * @retval 无
  */
void LED4_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_15);
}

/**
  * @brief  熄灭LED4（PD15）
  * @param  无
  * @retval 无
  */
void LED4_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_15);
}

/**
  * @brief  熄灭全部LED
  * @param  无
  * @retval 无
  */
void LED_AllOff(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}
