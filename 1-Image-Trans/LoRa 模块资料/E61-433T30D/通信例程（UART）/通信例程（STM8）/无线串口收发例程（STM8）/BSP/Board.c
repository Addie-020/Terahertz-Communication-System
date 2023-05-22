#include "Board.h"
void Init_CLK(void)
{
  CLK_MasterPrescalerConfig(CLK_MasterPrescaler_HSIDiv1);
}
void Init_GPIO(void)
{
  /* GPIO Initial */
  GPIO_Init(GPIOB,GPIO_Pin_1,GPIO_Mode_In_FL_IT);
  EXTI_SetPinSensitivity(EXTI_Pin_1,EXTI_Trigger_Rising);
  GPIO_ExternalPullUpConfig(GPIOB,GPIO_Pin_1,ENABLE);
    
  GPIO_Init(GPIOB,GPIO_Pin_0,GPIO_Mode_Out_PP_High_Slow);
  GPIO_SetBits(GPIOB,GPIO_Pin_0);
  /* End of GPIO Initial*/
}
void Init_Uart(void)
{
  CLK_PeripheralClockConfig(CLK_Peripheral_USART,ENABLE);
  USART_Init(9600,USART_WordLength_8D,USART_StopBits_1,USART_Parity_No,(USART_Mode_TypeDef)(USART_Mode_Tx|USART_Mode_Rx));
  USART_ITConfig(USART_IT_IDLE,ENABLE);
  USART_ITConfig(USART_IT_RXNE,ENABLE);
  USART_Cmd(ENABLE);
}
void Init_CPU(void)
{
  Init_CLK();
  Init_GPIO();
  Init_Uart();
  enableInterrupts();
}
void LED_Blink(void)
{
  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
  _delay_ms(400);
  GPIO_SetBits(GPIOB,GPIO_Pin_0);
}
void UART_Send_Buffer(uint8_t *pBuffer,uint8_t length)
{
  uint8_t i;
  for(i=0;i<length;i++)
  {
    while(RESET==USART_GetFlagStatus(USART_FLAG_TXE));
    USART_SendData8(pBuffer[i]);
  }
}
void _delay_ms(uint16_t ms)
{
  uint16_t i;
  for(i=0;i<ms;i++)
    _delay_us(1000);
}
inline void _delay_us(uint16_t us)
{
  uint16_t i;
  for(i=0;i<us;i++)
  {
    __no_operation();__no_operation();__no_operation();__no_operation();
    __no_operation();__no_operation();__no_operation();__no_operation();
    __no_operation();__no_operation();__no_operation();__no_operation();
    __no_operation();__no_operation();__no_operation();__no_operation();
  }
}
