/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * 官网    :http://www.cdebyte.com
  * 淘宝    :http://yhmcu.taobao.com
  * 阿里巴巴:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 

#include "led.h"
/**********************************************/
/* 函数功能； led灯 初始化                     */
/* 入口参数：无                               */
/**********************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitStruct.GPIO_Pin = LED1_PIN ;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed =GPIO_Speed_Level_3;
  GPIO_Init(LED1_PORT, &GPIO_InitStruct);
	GPIO_SetBits(LED1_PORT, LED1_PIN);
}

/**********************************************/
/* 函数功能；打开led灯                        */
/* 入口参数：无                               */
/**********************************************/
void LED_Open(void)
{
	 GPIO_ResetBits(LED1_PORT, LED1_PIN );
	}
/**********************************************/
/* 函数功能； 关掉led灯                        */
/* 入口参数：无                               */
/**********************************************/
void LED_Close(void)
{
		GPIO_SetBits(LED1_PORT, LED1_PIN );
}

/**********************************************/
/* 函数功能；led翻转                          */
/* 入口参数：无                               */
/**********************************************/
void LED1_Toggle(void)
{
GPIO_WriteBit(GPIOA, GPIO_Pin_4, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_4))));
}
