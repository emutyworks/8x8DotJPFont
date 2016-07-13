#include "Arduboy.h"
#include "misaki_font.c"

Arduboy arduboy;

PROGMEM const uint8_t mes1[] = 
{
  //スライムがあらわれた！
  0xae,0xde,0x99,0xd5,0x4e,0x44,0x8b,0x91,0x8e,0x61,0x09
};
PROGMEM const uint8_t mes2[] =
{
  //→たたかう
  0x35,0x61,0x61,0x4d,0x48,
};
PROGMEM const uint8_t mes3[] =
{
  //　まもる
  0x00,0x80,0x84,0x8d,
};
PROGMEM const uint8_t mes4[] =
{
  //　にげる
  0x00,0x6d,0x54,0x8d
};

void setup()
{
  arduboy.start();
  arduboy.clearDisplay();

  uint8_t f;
  uint8_t x = 0;

  for(uint8_t i = 0; i < sizeof(mes1); i++)
  {
    f = pgm_read_word_near(mes1 + i);
    arduboy.drawBitmap(x, 0,  misaki_font[ f ], 8, 8, WHITE);
    x = x + 8;
  }
  
  x = 0;
  for(uint8_t i = 0; i < sizeof(mes2); i++)
  {
    f = pgm_read_word_near(mes2 + i);
    arduboy.drawBitmap(x, 16,  misaki_font[ f ], 8, 8, WHITE);
    x = x + 8;
  }

  x = 0;
  for(uint8_t i = 0; i < sizeof(mes3); i++)
  {
    f = pgm_read_word_near(mes3 + i);
    arduboy.drawBitmap(x, 24,  misaki_font[ f ], 8, 8, WHITE);
    x = x + 8;
  }

  x = 0;
  for(uint8_t i = 0; i < sizeof(mes4); i++)
  {
    f = pgm_read_word_near(mes4 + i);
    arduboy.drawBitmap(x, 32,  misaki_font[ f ], 8, 8, WHITE);
    x = x + 8;
  }

  arduboy.display();
}

void loop()
{
  if(!(arduboy.nextFrame())){
    return;
  }
}
