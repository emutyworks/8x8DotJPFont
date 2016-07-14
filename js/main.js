/*
8x8dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
var char_list = "　、。，．・：；？！［］「」『』【】＋－±×÷＝≠＜＞℃￥＄￠￡％＃＆＊＠§☆★○●◎◇◆□■△▲▽▼※〒→←↑↓０１２３４５６７８９ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶ";

var add_comment = true;

$(function($){
 $('#add_comment').prop("checked", add_comment);
});

function set_comment(){
  if($('#add_comment').prop('checked')){
    add_comment = true;
  }else{
    add_comment = false;
  }
}

function convert_text_to_hex(){
  var text = $('#edit').val();
  var list = '';
  var str = '';
  var hex = '';

  text += '\n'; 

  for(var i = 0; i < text.length; i++){
    var row = text.charAt(i);
    if(row != '\n'){
      str += row;
	    var h = char_list.indexOf(row).toString(16);
	    hex += '0x' + ('00' + h).slice(-2) + ',';    	
    }else{
      if(add_comment){
        list += '//' + str + '\n{ ' + hex + ' };\n';
      }else{
        list += '{ ' + hex + ' };\n';
      }
      hex = '';
      str = '';
    }
  }
  $('#hex').val(list);

}


