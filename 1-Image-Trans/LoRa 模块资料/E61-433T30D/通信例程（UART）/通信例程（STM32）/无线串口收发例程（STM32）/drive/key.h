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
#ifndef __KEY_H
#define	__KEY_H

#include "stm32f0xx.h"

void KEY_Init(void);
uint8_t KEY_Down(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /* __KEY_H */

