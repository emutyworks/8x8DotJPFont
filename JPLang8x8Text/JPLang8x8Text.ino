#include "Arduboy.h"
#include "misaki_font.h"

Arduboy arduboy;

//吾輩は猫である。名前はまだ無い。
PROGMEM const uint8_t mes1[] = { 0xf2, 0x00,0x01, 0xf0, 0x71, 0xf2, 0x02, 0xf0, 0x69,0x44,0x8d,0x02, 0xf2, 0x03,0x04, 0xf0, 0x71,0x80,0x62, 0xf2, 0x05, 0xf0, 0x46,0x02, };
//　どこで生れたかとんと見当がつかぬ。何でも薄暗いじめじめした所でニャーニャー泣いていた事だけは記憶している。吾輩はここで始めて人間というものを見た。
PROGMEM const uint8_t mes2[] = { 0xf0, 0x00,0x6b,0x55,0x69, 0xf2, 0x06, 0xf0, 0x8e,0x61,0x4d,0x6a,0x95,0x6a, 0xf2, 0x07,0x08, 0xf0, 0x4e,0x66,0x4d,0x6e,0x02, 0xf2, 0x09, 0xf0, 0x69,0x84, 0xf2, 0x0a,0x0b, 0xf0, 0x46,0x5a,0x83,0x5a,0x83,0x59,0x61, 0xf2, 0x0c, 0xf0, 0x69,0xc0,0xd8,0xee,0xc0,0xd8,0xee, 0xf2, 0x0d, 0xf0, 0x46,0x68,0x46,0x61, 0xf2, 0x0e, 0xf0, 0x62,0x53,0x71, 0xf2, 0x0f,0x10, 0xf0, 0x59,0x68,0x46,0x8d,0x02, 0xf2, 0x00,0x01, 0xf0, 0x71,0x55,0x55,0x69, 0xf2, 0x11, 0xf0, 0x83,0x68, 0xf2, 0x12,0x13, 0xf0, 0x6a,0x46,0x48,0x84,0x70,0x94, 0xf2, 0x07, 0xf0, 0x61,0x02, };

void setup()
{
  //arduboy.start();
  arduboy.beginNoLogo();
  arduboy.clearDisplay();
  
  drawText(0, 0, mes1, sizeof(mes1));
  drawText(0, 8, mes2, sizeof(mes2));
//  drawText(0, 16, mes3, sizeof(mes3));
  
  arduboy.display();
}

void loop()
{
  if (!(arduboy.nextFrame())) return;
}

void drawText(uint8_t x, uint8_t y, const uint8_t *mes, uint8_t cnt)
{
  uint8_t pb;
  uint8_t page;
  uint8_t screen_start = 0;
  uint8_t screen_end = 128;

  if (x < screen_start) {
    x = screen_start;
  }
  
  for (uint8_t i = 0; i < cnt; i++) {
    pb = pgm_read_byte_near(mes + i);

    switch (pb) {
      case MISAKI_FONT_F0_PAGE:
        page = MISAKI_FONT_F0_PAGE;
        continue;
      case MISAKI_FONT_F1_PAGE:
        page = MISAKI_FONT_F1_PAGE;
        continue;
      case MISAKI_FONT_F2_PAGE:
        page = MISAKI_FONT_F2_PAGE;
        continue;
    }

    if (!page) {
      continue;
    }

    switch (page) {
      #ifdef MISAKI_FONT_F0_H
        case MISAKI_FONT_F0_PAGE:
          if (pb > MISAKI_FONT_F0_SIZE) {
            continue;
          }      
          if ((x + 8) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f0[ pb ], 8, 8, WHITE);
          x = x + 8;    
          break;
      #endif
      #ifdef MISAKI_FONT_F1_H
        case MISAKI_FONT_F1_PAGE:
          if (pb > MISAKI_FONT_F1_SIZE) {
            continue;
          }      
          if ((x + 4) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f1[ pb ], 4, 8, WHITE);
          x = x + 4;  
          break;
      #endif
      #ifdef MISAKI_FONT_F2_H
        case MISAKI_FONT_F2_PAGE:
          if (pb > MISAKI_FONT_F2_SIZE) {
            continue;
          }      
          if ((x + 8) > screen_end) {
            x = screen_start;   
            y = y + 8;
          }
          arduboy.drawBitmap(x, y,  misaki_font_f2[ pb ], 8, 8, WHITE);
          x = x + 8;    
          break;
      #endif
    }
  }
}
