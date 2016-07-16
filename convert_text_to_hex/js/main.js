/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
var char_list = new Array();
char_list[0] = "　、。，．・：；？！［］「」『』【】＋－±×÷＝≠＜＞℃￥＄￠￡％＃＆＊＠§☆★○●◎◇◆□■△▲▽▼※〒→←↑↓０１２３４５６７８９ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶ〜…♂♀";
char_list[1] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~｡｢｣､･ｦｧｨｩｪｫｬｭｮｯｰｱｲｳｴｵｶｷｸｹｺｻｼｽｾｿﾀﾁﾂﾃﾄﾅﾆﾇﾈﾉﾊﾋﾌﾍﾎﾏﾐﾑﾒﾓﾔﾕﾖﾗﾘﾙﾚﾛﾜﾝﾞﾟ";

var char_exception = {
  '～': 0xec,
  '〜': 0xec,
};

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
  var mode = '';
  var flag = true;

  text += '\n'; 

  for(var i = 0; i < text.length; i++){
    var row = text.charAt(i);

    if(row != '\n'){
      str += row;
	    var h0 = char_list[0].indexOf(row).toString(16);
      var h1 = char_list[1].indexOf(row).toString(16);

      if(flag){
        flag = false;

        if(h1 != -1){
          mode = '0xf1';
          hex += mode + ', ' + '0x' + ('00' + h1).slice(-2) + ',';
        }else{
          mode = '0xf0';
          if(h0 == -1){ 
            var ex = char_exception[row];
            if(!ex){
              h0 = '00';
            }else{
              h0 = ex.toString(16);
            }
          }
          hex += mode + ', ' + '0x' + ('00' + h0).slice(-2) + ',';
        }
      }else{
        if(h1 != -1){
          if(mode == '0xf1'){
            hex += '0x' + ('00' + h1).slice(-2) + ',';
          }else{
            mode = '0xf1';
            hex += ' ' + mode + ', ' + '0x' + ('00' + h1).slice(-2) + ',';
          }
        }else{
          if(h0 == -1){ 
            var ex = char_exception[row];
            if(!ex){
              h0 = '00';
            }else{
              h0 = ex.toString(16);
            }
          }

          if(mode == '0xf0'){
            hex += '0x' + ('00' + h0).slice(-2) + ',';
          }else{
            mode = '0xf0';
            hex += ' ' + mode + ', ' + '0x' + ('00' + h0).slice(-2) + ',';
          }
        }
      }

    }else{
      flag = true;

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


