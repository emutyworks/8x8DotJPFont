/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
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

