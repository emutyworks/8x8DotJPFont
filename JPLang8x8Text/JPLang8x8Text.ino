#include "Arduboy.h"
#include "misaki_font.c"

Arduboy arduboy;

//スライムがあらわれた！
PROGMEM const uint8_t mes1[] = { 0xae,0xde,0x99,0xd5,0x4e,0x44,0x8b,0x91,0x8e,0x61,0x09, };
//→たたかう
PROGMEM const uint8_t mes2[] = { 0x35,0x61,0x61,0x4d,0x48, };
//　まもる
PROGMEM const uint8_t mes3[] = { 0x00,0x80,0x84,0x8d, };
//　にげる
PROGMEM const uint8_t mes4[] = { 0x00,0x6d,0x54,0x8d, };

void setup()
{
  arduboy.start();
  arduboy.clearDisplay();

  drawFont(0, 0, mes1, sizeof(mes1));
  drawFont(0, 16, mes2, sizeof(mes2));
  drawFont(0, 24, mes3, sizeof(mes3));
  drawFont(0, 32, mes4, sizeof(mes4));

  arduboy.display();
}

void drawFont(uint8_t x, uint8_t y, const uint8_t *mes, uint8_t cnt)
{
  uint8_t f;
  
  for(uint8_t i = 0; i < cnt; i++)
  {
    f = pgm_read_byte_near(mes + i);
    arduboy.drawBitmap(x, y,  misaki_font[ f ], 8, 8, WHITE);
    x = x + 8;
  }
}

void loop()
{
  if(!(arduboy.nextFrame())){
    return;
  }
}
