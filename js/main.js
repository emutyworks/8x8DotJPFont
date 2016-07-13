/*
8x8dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
var char_list = "　、。，．・：；？！［］「」『』【】＋－±×÷＝≠＜＞℃￥＄￠￡％＃＆＊＠§☆★○●◎◇◆□■△▲▽▼※〒→←↑↓０１２３４５６７８９ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶ";

function convert_text_to_hex(){
  var text = $('#edit').val();
  var text_len = text.length;
  var hex_list = '';

  for(var i = 0; i < text_len; i++){
    var row = text.charAt(i);
    if(row != '\n'){
	    var hex = char_list.indexOf(row).toString(16);
	    hex_list += '0x' + ('00' + hex).slice(-2) + ',';    	
    }else{
    	hex_list += '\n';
    }
  }
  $('#hex').val(hex_list);

}


