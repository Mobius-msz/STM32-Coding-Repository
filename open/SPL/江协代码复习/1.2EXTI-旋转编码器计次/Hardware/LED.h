#ifndef __LED_H
#define __LED_H
void LED_Init(GPIO_TypeDef *port, uint16_t Pins);
void LED_ON(GPIO_TypeDef *port, uint16_t Pins);
void LED_OFF(GPIO_TypeDef *port, uint16_t Pins);
void LED_Turn(GPIO_TypeDef *port, uint16_t Pin);
#endif
