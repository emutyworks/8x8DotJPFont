<?php 
/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
mb_language('Japanese');
mb_internal_encoding('UTF-8');

$img = imagecreatefrompng("../misaki_png_2015-04-10/misaki_4x8_jisx0201.png");

$char_list = "
                
                
 !\"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_
`abcdefghijklmno
pqrstuvwxyz{|}~ 
                
                
 ｡｢｣､･ｦｧｨｩｪｫｬｭｮｯ
ｰｱｲｳｴｵｶｷｸｹｺｻｼｽｾｿ
ﾀﾁﾂﾃﾄﾅﾆﾇﾈﾉﾊﾋﾌﾍﾎﾏ
ﾐﾑﾒﾓﾔﾕﾖﾗﾘﾙﾚﾛﾜﾝﾞﾟ";

$char_list = str_replace(array("\r\n","\n","\r"), '', $char_list);

echo $char_list."<br>";

$list = array();
$cnt = 0;
for($yy = 0; $yy < 14; $yy++){
  for($xx = 0; $xx < 16; $xx++){
    $hex = array();
    for($x = 0; $x < 4; $x++){
      $bin = '';
      for($y = 7; $y >= 0; $y--){
        $rgb = imagecolorat($img, $x+($xx * 4), $y + ($yy * 8));
        $colors = imagecolorsforindex($img, $rgb);
        if($colors['red'] != '0'){
          $bin.="0";
        }else{
          $bin.="1";
        }
      }
      $hex[] = sprintf("0x%02s",dechex(bindec($bin)));
    }
    $list[$cnt]['hex'] = implode(",", $hex);
    $list[$cnt]['char'] = mb_substr($char_list,$cnt,1);
    $cnt++;
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

$code_table = '';

$start = 32;
$end = $start + 95;
list($hex,$comment) = view_data($start,$end,$list);
$code_table .= $comment;

$start = 161;
$end = $start + 63;
list($hex,$comment) = view_data($start,$end,$list);
$code_table .= $comment;

echo "<br>".$code_table."<br><br>";

echo "\n<table border='1'>\n<tr>\n";
$cnt = 0;
for($y = 0; $y < 17; $y++){
  if($y == '0'){
    echo "<tr><td>&nbsp;</td>";
  }else{
    printf("<tr><td>%02s</td>",dechex(($y - 1) * 0x10));
  }
  for($x = 0; $x < 16; $x++){
    if($y == '0'){
      printf("<td>%02s</td>",dechex($x));
    }else{
      printf("<td>%s</td>",mb_substr($code_table,$cnt,1));
      $cnt++;
    }
  }
  echo "</tr>\n";
}
echo "</table>\n";

function view_data($start,$end,$list){
  static $cnt = 0;
  $comment = '';
  $hex = '';
  for($i = $start; $i < $end; $i++){
    $comment .= $list[$i]['char'];
    $hex .= sprintf("{ %s },/* 0x%02s %s */<br>", $list[$i]['hex'], strtoupper(dechex($cnt)), $list[$i]['char']);
    $cnt++;
  }
  //echo "#".$comment."<br>";
  echo $hex;
  
  return array($hex,$comment);
}


?>
</body>
</html>
