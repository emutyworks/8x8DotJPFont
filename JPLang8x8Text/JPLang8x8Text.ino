#include "Arduboy.h"
#include "misaki_font_f0.h" //8x8 dot Hiragana, Katakana and Symbol
#include "misaki_font_f1.h" //4x8 dot Alphabet, Katakana and Symbol

Arduboy arduboy;

//2016ねん7ガツ16にち Arduboyで
PROGMEM const uint8_t mes1[] = { 0xf1, 0x12,0x10,0x11,0x16, 0xf0, 0x6f,0x95, 0xf1, 0x17, 0xf0, 0xa1,0xb9, 0xf1, 0x11,0x16, 0xf0, 0x6d,0x63, 0xf1, 0x00,0x21,0x52,0x44,0x55,0x42,0x4f,0x59, 0xf0, 0x69, };
//カタカナ・ひらがな・ﾊﾝｶｸｶﾀｶﾅ が
PROGMEM const uint8_t mes2[] = { 0xf0, 0xa0,0xb4,0xa0,0xbf,0x05,0x74,0x8b,0x4e,0x6c,0x05, 0xf1, 0x88,0x9b,0x74,0x76,0x74,0x7e,0x74,0x83,0x00, 0xf0, 0x4e, };
//ひょうじできるようになりました！
PROGMEM const uint8_t mes3[] = { 0xf0, 0x74,0x89,0x48,0x5a,0x69,0x4f,0x8d,0x8a,0x48,0x6d,0x6c,0x8c,0x80,0x59,0x61,0x09, };

void setup()
{
  arduboy.start();
  arduboy.clearDisplay();

  drawText(0, 0, mes1, sizeof(mes1));
  drawText(0, 8, mes2, sizeof(mes2));
  drawText(0, 16, mes3, sizeof(mes3));

  arduboy.display();
}

void drawText(uint8_t x, uint8_t y, const uint8_t *mes, uint8_t cnt)
{
  uint8_t f;
  uint8_t mode;
  
  for(uint8_t i = 0; i < cnt; i++)
  {
    f = pgm_read_byte_near(mes + i);

    if(f == 0xf0){//8x8 dot
      mode = 0xf0;
      continue;
    }else if(f == 0xf1){//4x8 dot
      mode = 0xf1;
      continue;
    }

    if(mode == 0xf0){
      arduboy.drawBitmap(x, y,  misaki_font_f0[ f ], 8, 8, WHITE);
      x = x + 8;
    }else if(mode == 0xf1){
      arduboy.drawBitmap(x, y,  misaki_font_f1[ f ], 4, 8, WHITE);
      x = x + 4;  
    }
  }
}

void loop()
{
  if(!(arduboy.nextFrame())){
    return;
  }
}
