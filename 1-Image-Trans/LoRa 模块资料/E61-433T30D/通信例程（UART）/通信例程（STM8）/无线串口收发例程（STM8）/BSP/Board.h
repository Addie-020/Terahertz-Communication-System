#ifndef _BOARD_H_
#define _BOARD_H_

#include "stm8l10x_conf.h"
/* Private functions */
void Init_CLK(void);
void Init_GPIO(void);
void Init_Uart(void);
/* Public functions */
void Init_CPU(void);

void LED_Blink(void);
void UART_Send_Buffer(uint8_t *pBuffer,uint8_t length);
void _delay_ms(uint16_t ms);
void _delay_us(uint16_t us);
#endif