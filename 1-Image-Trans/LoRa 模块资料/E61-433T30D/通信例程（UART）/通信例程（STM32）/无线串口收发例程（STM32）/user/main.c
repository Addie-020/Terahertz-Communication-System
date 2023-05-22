/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * ����    :http://www.cdebyte.com
  * �Ա�    :http://yhmcu.taobao.com
  * ����Ͱ�:http://http://shop1399568656388.1688.com
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
	KEY_Init();//������ʼ��
	LED_Init();

  while (1)
  {
		if( KEY_Down(GPIOA,GPIO_Pin_0) ==0)//�ж������Ƿ���
			{
				printf("Ebyte");
				LED_Open();//��led��
				delay(700000);
				LED_Close();//�ص�led��
			}   



	 }
}
