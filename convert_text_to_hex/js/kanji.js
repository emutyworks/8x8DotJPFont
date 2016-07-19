/*
8x8 dot Japanese font for Arduboy

Copyright (c) 2016 emutyworks

Released under the MIT license
https://github.com/emutyworks/8x8DotJPFont/blob/master/LICENSE.txt
*/
$(function($){
  $('#view_data').css({ display: 'none'});
});

function create_kanji(){
  var kanji_list = $('#kanji_list').val();
  var f2_size = (kanji_list.length - 1).toString(16).toUpperCase();
  f2_size = '0x' + ('00' + f2_size).slice(-2);

  var table = '';
  for(var i = 0; i < kanji_list.length; i++){
    var row = kanji_list.charAt(i);
    var cnt = i.toString(16).toUpperCase();
    cnt = '0x' + ('00' + cnt).slice(-2);

    table += '  { ' + kanji_table[row] + ' },/* ' + cnt + ' ' + row + ' */\n';
  }

  $('#view_data').css({ display: 'inline'});
  $('#kanji_list2').val(kanji_list);
  $('#f2_size').html(f2_size);
  $('#f2_size2').html(f2_size + ' + 1');
  $('#table').html(table);
  
}