$(document).ready(function(){
  $('#main-menu span').click(function(){
    $(this).parent().parent().toggleClass('active')
  });
  
  $('#block-br-104 a').click(function(){    
    if ($(this).parent().find('ul').length) {
      $(this).parent().toggleClass('active');
      return false;
    }
  });
  
  //$('.listing.l-cs').QBscroller();
  
  $('#br-search-form select, #br-search-form .form-checkbox, #br-search-form .form-text').change_filter();
});  


(function ($) {
  // qb scroller
  $.fn.QBscroller = function(options) {    
    $(this).html('<div class="grid">' + $(this).html() + '</div>')
    iwidth = $(this).find('.item:first').width();
    $(this).find('.grid').css({'width' : (iwidth + 40) * $(this).find('.item').length + 20 + 'px'})
  }  
}(jQuery));

(function ($) {  
  $.fn.change_filter = function(options) {  
        
    $(this).change(function(){
      if ($(this).attr('type') == 'text') {
        $(this).parents('form').submit(function(){ return false });        
      }
      
      var val;
      name = $(this).attr('name');
      if ($(this).is(":checkbox")) {      
        if (!$(this).hasClass('negative') && $(this).attr("checked") == true || $(this).hasClass('negative') && $(this).attr("checked") != true) {
          val = $(this).val();
        }
      }
      else 
        val = $(this).val();
      
      search_path = $('#search_path').val();
      
      current_url_no_query = document.location + '';
      current_url_no_query = current_url_no_query.replace('http://', '');
      current_url_no_query = current_url_no_query.substring(current_url_no_query.indexOf('/'));

      if (current_url_no_query.indexOf('?') != -1) {
        current_url_no_query = current_url_no_query.substring(0, current_url_no_query.indexOf('?'));
      }
      
      current_url = document.location + '';       
      if (search_path) {
        if (current_url_no_query != search_path) {
          current_url = search_path;
        }
      }
            
      d_url = '';
      if (current_url.indexOf('#') != '-1') {
        d_url = current_url.substring(current_url.indexOf('#') + 1, current_url.length);  
        current_url = current_url.substring(0, current_url.indexOf('#'));  
        current_url = current_url.indexOf('?') == -1?d_url:d_url + current_url.substring(current_url.indexOf('?'), current_url.length); 
      }              
      
      //remove existing sort name
      if (val) {    
        if (current_url.indexOf(name + '=') != -1) {        
          start = current_url.indexOf(name + '=') + name.length + 1;
          stop = current_url.indexOf('&', start);      
          stop = stop == -1?current_url.length:stop;              
          
          new_url = current_url.replace(name + '=' + current_url.substr(start, stop - start), name + '=' + val);        
        }    
        else {        
          glue = (current_url.indexOf('?') == -1)?'?':'&';    
          new_url = current_url + glue + name + "=" + val;      
        }
      }
      else {              
        start = current_url.indexOf(name + '=');
        //new_url = current_url;
        //if (start != -1) {
          stop = current_url.indexOf('&', start); 
          stop = stop == -1?current_url.length:stop;                    
          new_url = current_url.replace(current_url.substr(start, stop - start), '');          
       // }
      }
          
      if ((new_url.indexOf('?') + 1) == new_url.length || (new_url.lastIndexOf('&') + 1) == new_url.length) {      
        new_url = new_url.substr(0, new_url.length - 1);
      }
                
      document.location = new_url;
    });    
  }
}(jQuery));