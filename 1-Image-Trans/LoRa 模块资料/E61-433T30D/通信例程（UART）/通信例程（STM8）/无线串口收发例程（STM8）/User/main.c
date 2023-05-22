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
#include "main.h"
bool Uart_recive_flag=FALSE;
bool Uart_Send_flag=FALSE;
uint8_t UART_recive_buffer[10],counter=0;
uint8_t UART_Send_table[]="CDEBYTE";
int main(void)
{
  Init_CPU();
  LED_Blink();
  while(1)
  {
    if(Uart_recive_flag==TRUE)
    {
      Uart_recive_flag=FALSE;
      LED_Blink();
      counter=0;
    }
    if(Uart_Send_flag==TRUE)
    {
      Uart_Send_flag=FALSE;
      UART_Send_Buffer(UART_Send_table,7);
    }
  }
}
void Key_Press_callback(void)
{
  EXTI_ClearITPendingBit(EXTI_IT_Pin1);
  Uart_Send_flag=TRUE;
}
void UART_recive_callback(void)
{
  UART_recive_buffer[counter]=USART_ReceiveData8();
  counter++;
  if(SET==USART_GetFlagStatus(USART_FLAG_IDLE))
  {
    if( UART_recive_buffer[0]=='C'&&
        UART_recive_buffer[1]=='D'&&
        UART_recive_buffer[2]=='E'&&
        UART_recive_buffer[3]=='B'&&
        UART_recive_buffer[4]=='Y'&&
        UART_recive_buffer[5]=='T'&&
        UART_recive_buffer[6]=='E' )
    {
      Uart_recive_flag=TRUE;
    }
    
  }
}