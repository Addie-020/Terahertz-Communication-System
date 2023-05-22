/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * πŸÕ¯    :http://www.cdebyte.com
  * Ã‘±¶    :http://yhmcu.taobao.com
  * ∞¢¿Ô∞Õ∞Õ:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 
#ifndef __LED_H
#define	__LED_H

#include "stm32f0xx.h"
#define LED1_PIN      GPIO_Pin_4
#define LED2_PIN       GPIO_Pin_3
#define LED1_PORT       GPIOA	
#define LED2_PORT       GPIOA
void LED_Init(void);
void LED_Open(void);
void LED_Close(void);
void LED1_Toggle(void);
#endif /* __LED_H */

