#ifndef _OLED_H_
#define _OLED_H_

#include "Board.h"

//Initial SPI and GPIO first
#define OLED_Reset_high GPIO_SetBits(GPIOB,GPIO_Pin_2);
#define OLED_Reset_low GPIO_ResetBits(GPIOB,GPIO_Pin_2);

#define OLED_CMD_high GPIO_SetBits(GPIOD,GPIO_Pin_0);
#define OLED_CMD_low GPIO_ResetBits(GPIOD,GPIO_Pin_0);

/* private functions */
void LCD_Write_Cmd(uint8_t cmd);
void LCD_Write_Data(uint8_t data);
void LCD_Set_Position(uint8_t line,uint8_t column);
/* public functions */
void LCD_Init();
void LCD_Fill(uint8_t color);
void LCD_Display_Char(uint8_t line,uint8_t column,uint8_t ch);
void LCD_Display_String(uint8_t line,uint8_t column,uint8_t *string);
#endif