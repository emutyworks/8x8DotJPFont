<?php 
/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
mb_language('Japanese');
mb_internal_encoding('UTF-8');

$img = imagecreatefrompng("../misaki_png_2015-04-10/misaki_gothic.png");

$char_list = "
　、。，．・：；？！゛゜´｀¨＾￣＿ヽヾゝゞ〃仝々〆〇ー―‐／＼〜∥｜…‥‘’“”（）〔〕［］
｛｝〈〉《》「」『』【】＋－±×÷＝≠＜＞≦≧∞∴♂♀°′″℃￥＄￠￡％＃＆＊＠§☆★○●◎◇
◆□■△▲▽▼※〒→←↑↓〓・・・・・・・・・・・∈∋⊆⊇⊂⊃∪∩・・・・・・・・∧∨￢⇒⇔∀
∃・・・・・・・・・・・∠⊥⌒∂∇≡≒≪≫√∽∝∵∫∬・・・・・・・Å‰♯♭♪†‡¶・・・・◯
・・・・・・・・・・・・・・・０１２３４５６７８９・・・・・・・ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ
ＰＱＲＳＴＵＶＷＸＹＺ・・・・・・ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ・・・・
ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのは
ばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをん・・・・・・・・・・・
ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハ
バパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶ・・・・・・・・
ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ・・・・・・・・αβγδεζηθικλμνξο
πρστυφχψω・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・・
АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ・・・・・・・・・・・・・
・・абвгдеёжзийклмнопрстуфхцчшщъыьэюя・・・・・・・・・・・・・─
│┌┐┘└├┬┤┴┼━┃┏┓┛┗┣┳┫┻╋┠┯┨┷┿┝┰┥┸╂・";

$char_list2 = "
①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮⑯⑰⑱⑲⑳ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩ・㍉㌔㌢㍍㌘㌧㌃㌶㍑㍗㌍㌦㌣㌫㍊㌻
㎜㎝㎞㎎㎏㏄㎡・・・・・・・・㍻〝〟№㏍℡㊤㊥㊦㊧㊨㈱㈲㈹㍾㍽㍼≒≡∫∮∑√⊥∠∟⊿∵∩∪・・・
";

$char_list = str_replace(array("\r\n","\n","\r"), '', $char_list);
$char_list2 = str_replace(array("\r\n","\n","\r"), '', $char_list2);

$list = array();
$list_cnt = 0;
$char_cnt = 0;
for($yy = 0; $yy < 8; $yy++){
  for($xx = 0; $xx < 94; $xx++){
    $hex = array();
    for($x = 0; $x < 8; $x++){
      $bin = '';
      for($y = 7; $y >= 0; $y--){
        $rgb = imagecolorat($img, $x+($xx * 8), $y + ($yy * 8));
        $colors = imagecolorsforindex($img, $rgb);
        if($colors['red'] != '0'){
          $bin.="0";
        }else{
          $bin.="1";
        }
      }
      $hex[] = sprintf("0x%02s",dechex(bindec($bin)));
    }

    if(hexdec($hex[0])==0 
      && hexdec($hex[1])==0
      && hexdec($hex[2])==0
      && hexdec($hex[3])==0
      && hexdec($hex[4])==0
      && hexdec($hex[5])==0
      && hexdec($hex[6])==0
      && hexdec($hex[7])==0
      ){
      $char_cnt++;
    }else{
      $list[$list_cnt]['hex'] = implode(",", $hex);
      $list[$list_cnt]['char'] = mb_substr($char_list,$char_cnt,1);
      $list_cnt++;
      $char_cnt++;
    }
  }
}

$list_cnt2 = 0;
$char_cnt2 = 0;
for($yy = 12; $yy < 13; $yy++){
  for($xx = 0; $xx < 94; $xx++){
    $hex = array();
    for($x = 0; $x < 8; $x++){
      $bin = '';
      for($y = 7; $y >= 0; $y--){
        $rgb = imagecolorat($img, $x+($xx * 8), $y + ($yy * 8));
        $colors = imagecolorsforindex($img, $rgb);
        if($colors['red'] != '0'){
          $bin.="0";
        }else{
          $bin.="1";
        }
      }
      $hex[] = sprintf("0x%02s",dechex(bindec($bin)));
    }

    if(hexdec($hex[0])==0 
      && hexdec($hex[1])==0
      && hexdec($hex[2])==0
      && hexdec($hex[3])==0
      && hexdec($hex[4])==0
      && hexdec($hex[5])==0
      && hexdec($hex[6])==0
      && hexdec($hex[7])==0
      ){
      $char_cnt2++;
    }else{
      $list[$list_cnt + $list_cnt2]['hex'] = implode(",", $hex);
      $list[$list_cnt + $list_cnt2]['char'] = mb_substr($char_list2,$char_cnt2,1);
      $list_cnt2++;
      $char_cnt2++;
    }
  }
}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
<title></title>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
</head>
<body>
<?php

for($i = 0; $i < $list_cnt; $i++){
  printf("{ %s },/* %s */<br>", $list[$i]['hex'], $list[$i]['char']);
}

for($i = 0; $i < $list_cnt2; $i++){
  printf("{ %s },/* %s */<br>", $list[$list_cnt + $i]['hex'], $list[$list_cnt + $i]['char']);
}

?>
</body>
</html>
