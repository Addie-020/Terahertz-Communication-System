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
#include "stm32f0xx.h"
#include "uart.h"
#include "key.h"
#include "led.h"
#include <stdio.h>

 void delay (int cnt) 
{
  while (cnt--);
}

int main(void)
{ 
/* USART1 config 9600 8-N-1 */
  USART_Configuration();
	KEY_Init();//按键初始化
	LED_Init();

  while (1)
  {
		if( KEY_Down(GPIOA,GPIO_Pin_0) ==0)//判定按键是否按下
			{
				printf("Ebyte");
				LED_Open();//打开led灯
				delay(700000);
				LED_Close();//关掉led灯
			}   



	 }
}
