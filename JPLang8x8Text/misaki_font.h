/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
#ifndef MISAKI_FONT_H
#define MISAKI_FONT_H

#define MISAKI_FONT_F0_PAGE 0xF0
#define MISAKI_FONT_F1_PAGE 0xF1
#define MISAKI_FONT_F2_PAGE 0xF2

#define MISAKI_FONT_F0_W 8
#define MISAKI_FONT_F1_W 3
#define MISAKI_FONT_F2_W 7

#define MISAKI_FONT_F0_SIZE 0xEF
#define MISAKI_FONT_F1_SIZE 0x9D
#define MISAKI_FONT_F2_SIZE 0x13 // misaki_font_f2.h の最終行の値をここに設定する、最大0xEFまで

/*
利用しないフォントデータはヘッダファイルを読み込まないようにするとメモリが節約できます、
drawText() 実行時にフォントが無い場合は処理がスキップされます。

例) 8x8 dot ひらがな・カタカナ・記号 のみ利用
#include "misaki_font_f0.h" // 8x8 dot ひらがな・カタカナ・記号
//#include "misaki_font_f1.h" // 4x8 dot 英語・カタカナ・記号
//#include "misaki_font_f2.h" // 8x8 dot 漢字 
*/

#include "misaki_font_f0.h" // 8x8 dot ひらがな・カタカナ・記号
#include "misaki_font_f1.h" // 4x8 dot 英語・カタカナ・記号
#include "misaki_font_f2.h" // 8x8 dot 漢字 

PROGMEM const uint8_t misaki_font_0x00[1] = { 0x00 };

#endif

