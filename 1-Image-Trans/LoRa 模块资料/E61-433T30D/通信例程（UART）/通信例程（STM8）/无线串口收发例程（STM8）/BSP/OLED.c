#include "OLED.h"
#include "font.h"

void LCD_Write_Cmd(uint8_t cmd)
{
  SPI_Chip_Select(OLED);
  OLED_CMD_low;
  SPI_Send_Byte(cmd);
  SPI_Chip_Select(NONE);
}
void LCD_Write_Data(uint8_t data)
{
  SPI_Chip_Select(OLED);
  OLED_CMD_high;
  SPI_Send_Byte(data);
  SPI_Chip_Select(NONE);
}
void LCD_Set_Position(uint8_t line,uint8_t column)
{
  LCD_Write_Cmd(0xb0 + (line&0x07));
  LCD_Write_Cmd(0x10 + ((column>>4)&0x0F));
  LCD_Write_Cmd(column & 0x0F);
}
void LCD_Init()
{
  uint16_t j=0;
  OLED_Reset_low;         // Reset OLED
  for (j=0; j<1000; j++);
  OLED_Reset_high;
  
  LCD_Write_Cmd(0xae);    // Close OLED panel
  LCD_Write_Cmd(0x00);    // set low column address
  LCD_Write_Cmd(0x10);    // set high column address
  LCD_Write_Cmd(0x40);    // Set Mapping RAM Display Start Line (0x00~0x3F)
  LCD_Write_Cmd(0x81);    // set contrast control register
  LCD_Write_Cmd(0xcf);    // Set SEG Output Current Brightness
  LCD_Write_Cmd(0xa1);    // Set SEG/Column Mapping       0xa0 0xa1
  LCD_Write_Cmd(0xc8);    // Set COM/Row Scan Direction   0xc0 0xc8
  LCD_Write_Cmd(0xa6);    // set normal display
  LCD_Write_Cmd(0xa8);    // set multiplex ratio(1 to 64)
  LCD_Write_Cmd(0x3f);    // 1/64 duty
  LCD_Write_Cmd(0xd3);    // set display offset Shift Mapping RAM Counter
  LCD_Write_Cmd(0x00);    // not offset
  LCD_Write_Cmd(0xd5);    // set display clock divide ratio/oscillator frequency
  LCD_Write_Cmd(0x80);    // set divide ratio, Set Clock as 100 Frames/Sec
  LCD_Write_Cmd(0xd9);    // set pre-charge period
  LCD_Write_Cmd(0xf1);    // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  LCD_Write_Cmd(0xda);    // set com pins hardware configuration
  LCD_Write_Cmd(0x12);
  LCD_Write_Cmd(0xdb);    // set vcomh
  LCD_Write_Cmd(0x40);    // Set VCOM Deselect Level
  LCD_Write_Cmd(0x20);    // Set Page Addressing Mode (0x00/0x01/0x02)
  LCD_Write_Cmd(0x02);    //
  LCD_Write_Cmd(0x8d);    // set Charge Pump enable/disable
  LCD_Write_Cmd(0x14);    // set(0x10) disable
  LCD_Write_Cmd(0xa4);    // Disable Entire Display On (0xa4/0xa5)
  LCD_Write_Cmd(0xa6);    // Disable Inverse Display On (0xa6/a7)
  LCD_Write_Cmd(0xaf);    // turn on oled panel
  LCD_Fill(0x00);
}
void LCD_Fill(uint8_t data)
{
  uint8_t y,x;
  for (y=0; y<8; y++)
  {
    LCD_Write_Cmd(0xb0 + y);
    LCD_Write_Cmd(0x01);
    LCD_Write_Cmd(0x10);
    for (x=0; x<128; x++)
      LCD_Write_Data(data);
  }
}
void LCD_Display_Char(uint8_t line,uint8_t column,uint8_t ch)
{
  uint8_t j = 0;
  uint16_t pos = 0;
  if (ch < ' ')
    return;
  pos = 16 * (ch-' ');    
  LCD_Set_Position(line,column);
  for (j=0;j<8;j++)
    LCD_Write_Data(Font8x16[pos++]);   
  LCD_Set_Position(line+1,column);
  for (j=0;j<8;j++)
    LCD_Write_Data(Font8x16[pos++]);
}
void LCD_Display_String(uint8_t line,uint8_t column,uint8_t *string)
{
  while (*string)
  {
    LCD_Display_Char(line,column,*string++);
    column += 8;
  }
}
