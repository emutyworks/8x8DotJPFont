/*
8x8dot Japanese font for Arduboy

convert misaki_gothic.png to hex.
(Hiragana, Katakana and Symbol)

Copyright (c) 2016 emutyworks

-----------------------------------------------------
Original: 8x8 dot Japanese font "Misaki font"
http://www.geocities.jp/littlimi/misaki.htm

These fonts are free softwares.
Unlimited permission is granted to use, copy, and distribute it, with or without modification, 
either commercially and noncommercially.
THESE FONTS ARE PROVIDED "AS IS" WITHOUT WARRANTY.

Copyright(C) 2002-2015 Num Kadoma
*/
#ifndef MISAKI_FONT_H
#define MISAKI_FONT_H

#define MISAKI_FONT_F1_PAGE 0xF1
#define MISAKI_FONT_F0_PAGE 0xF0

#define MISAKI_FONT_F1_SIZE 0x9D
#define MISAKI_FONT_F0_SIZE 0xEF

#include "misaki_font_f0.h" // 8x8 dot Hiragana, Katakana and Symbol
#include "misaki_font_f1.h" // 4x8 dot Alphabet, Katakana and Symbol
/*
利用しないフォントデータはヘッダファイルを読み込まないようにするとメモリが節約できます。
drawText() 実行時にフォントが無い場合は処理がスキップされます。

例) 4x8 dot Alphabet, Katakana and Symbol のみ利用
//#include "misaki_font_f0.h" // 8x8 dot Hiragana, Katakana and Symbol
#include "misaki_font_f1.h" // 4x8 dot Alphabet, Katakana and Symbol

*/

#endif

