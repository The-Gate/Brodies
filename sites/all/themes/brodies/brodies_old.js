$(document).ready(function(){
  // align top orange border if title > 1 line
  if ($('#content .middle h1').length >0){
    var titleHeight = ($('#content .middle h1').css('line-height')).replace(/[^-\d\.]/g, '');
    if($('#content .middle h1').height() > titleHeight){
      if($('#content .middle h1').height() > 27){
        $('#content > .left,#content > .right').css({
          'padding-top':($('#content .middle h1').height()-titleHeight)+'px'
        })
      }
    }
  }
  // hide contact / video / case study if empty
  $('#block-views-Key_Contacts-block_1 .field-content > .node').wrap('<div class="field-item"></div>');
  if($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length == 0){
  //$('#block-views-Key_Contacts-block_1').addCss('hide');
  } else {
    if($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length > 2){
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item').slice(2).addClass('hide');
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item:last-child').after('<div class="field-item field-item-expand"><div class="node"><h2><a href="#">Meet the team</a></h2></div></div>');
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').addClass('plus');
    }
  }
  if($('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').length == 0){
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1').css({
      'display':'none'
    });
  } else {
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
    // add the video pop[ up to the related videos
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').each(function(){
      $(this).find('.field-field-video-url .field-item').addClass('hide');
      $(this).find('h2 a').attr("href", $(this).find('.field-field-video-url .field-item').text()).attr("target","_blank");
    });
  }
  if($('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').length == 0){
    $('#block-views-Case_Studies-block_1').css({
      'display':'none'
    });
  } else {
    $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
  }
  $('#block-views-Key_Contacts-block_1 label').click(function(e){
    e.preventDefault();
    $('#block-views-Key_Contacts-block_1 .field-content > .field-item').removeClass('hide');
    if($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length > 2){
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item:not(.field-item-expand)').slice(2).addClass('hide');
 
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').addClass('plus');
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').removeClass('minus');
    }
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
    $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
  });
  
  $('#block-views-Key_Contacts-block_1 .field-item-expand a').click(function(e){
    e.preventDefault();
    if ($(this).parent().parent().parent().attr('class') == 'field-item field-item-expand plus') {
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item').removeClass('hide');
      $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
      $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
      $(this).parent().parent().parent().addClass('minus');
      $(this).parent().parent().parent().removeClass('plus');
    } 
    else if ($(this).parent().parent().parent().attr('class') == 'field-item field-item-expand minus') {
      $('#block-views-Key_Contacts-block_1 .field-content > .field-item:not(.field-item-expand)').slice(2).addClass('hide');
      $(this).parent().parent().parent().addClass('plus');
      $(this).parent().parent().parent().removeClass('minus');
    }
  });
  
  $('#block-views-Related_Video-block_1 label').click(function(e){
    e.preventDefault();
    $('#block-views-Key_Contacts-block_1 .field-content > .field-item').addClass('hide');
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').removeClass('hide');
    $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
  });
  $('#block-views-Case_Studies-block_1 label').click(function(e){
    e.preventDefault();
    $('#block-views-Key_Contacts-block_1 .field-content > .field-item').addClass('hide');
    $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
    $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').removeClass('hide');
  });
  
  // hide related sector title if no content
  if ($('#block-views-Related_Areas-block_1').length >0 ){
    if ($('#block-views-Related_Areas-block_1 .field-content > .field-item').length == 0 ){
      console.log('here agin');
      $('label.views-label-field-related-sector-nid').css({
        'color':'#fff'
      });
    }
  }
  
  // top news full width is no image
  if ($('.view-top-news').length > 0){
    
    $('.view-display-id-block_1 .field-content,.view-display-id-block_2 .field-content').each(function(){
      console.log($(this).find('.img'));
      if($(this).find('.img').html()==''){
        $(this).find('.col-left').css({
          'width':'100%',
          'margin-right':'0'
        });
        $(this).find('.col-right').css({
          'display':'none'
        });
      }
    });
  
  }
  
  //featured area videos and pages
  $('#content .area.vop').switcher();  
  $('.area.vop a').click(function(){
    
    var content = '';
    eval('content = ' + $('span', $(this).next()).html());
    
    if ($('#display').hasClass('on')) {
      init_popup('<div class="video">' + content.video + '</div>');
    }
    else {      
      
      if ($('#display .cont').hasClass('disp-on')) {
        //check if different
        if ($(this).attr('href') == $('#display .cont .video').attr('rel')) {
          return false;
        }        
      }
                
      $('#display .cont').html('<div class="video" rel="' + $(this).attr('href') + '">' + content.video + '<div class="close"></div></div>');
      if (!$('#display .cont').hasClass('disp-on')) {
        $('#display .cont').addClass('disp-on');        
        $('#display .cont').stop().animate({
          'bottom' : 0
        }, 1000, 'easeInOutExpo');
      }      
      $('#display .cont .close').click(function(){ 

        $('#display .cont').stop().animate({
          'bottom' : -404 + 'px'
        }, 1000, 'easeInOutExpo', function(){
          $('#display .cont').html('');
          $(this).removeClass('disp-on')
        });
      });
    }
    return false;        
  });
  
  //init scroller 2
  $('#display .sector-list,#display  .service-list').scroller({
    start: 0, 
    next: 0, 
    speed: 1000, 
    buttons_opacity: 45, 
    easingf: 'easeInOutExpo', 
    padding: 0
  });   
  $('#br-search-form select, #br-search-form .form-checkbox, #br-search-form .form-text').change_filter();
  
  //init header scroll
  $('#slideshow .slide').hide();
  $('#slideshow .slide:first').show();
  setTimeout(swap_slide, 8000, 'slow');
  
  //popups
  $('.popup').popups();
  
  $('#content .l-video a').click(function(){    
    var content = '';
    eval('content = ' + $('span', $(this)).html());
    init_popup('<div class="video">' + content.video + '</div>');    
    return false;
  });
  
    
  $('.view-Related-Video a').click(function(){  
    var video_id =  $.trim($(this).attr("href").split('v=')[1]);  
    init_popup('<div class="video"><iframe src="http://www.youtube.com/embed/'+video_id+'?wmode=opaque&autoplay=1" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe></div>');    
    return false;
  });
  if ($('#block-views-CTA_Blocks-block_1,#block-views-CTA_Blocks-block_2').length > 0){
    $('.views-field-field-cta-text-value a,.views-field-field-cta-text-value-1 a').each(function(e){
      var this_url = $(this).attr("href");
      if ( (this_url.search("youtube") == -1) && (this_url.search("http") >= 0)){
        $(this).attr("target","_blank");;
      }
    } );
    $('.views-field-field-cta-text-value a,.views-field-field-cta-text-value-1 a').click(function(e){  
      var this_url = $(this).attr("href");
      if ( this_url.search("youtube") > 0){
        var video_id = $.trim($(this).attr("href").split('v=')[1]);  
        init_popup('<div class="video"><iframe src="http://www.youtube.com/embed/'+video_id+'?wmode=opaque&autoplay=1" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe></div>');    
        return false;
      } else if ( this_url.search("http") > 0){
        $(this).attr("target","_blank");;
      }
    });
  }

  $('#display .item span').click(function(){ //ie fix
    document.location = $(this).parents('.item').find('a').attr('href');
  });
});

function swap_slide() {
  curr = $('#slideshow .slide:visible');
  next = $(curr).next();
  if (!next.length) {
    next = $('#slideshow .slide:first');
  }
  $(curr).fadeOut();
  $(next).fadeIn();
  setTimeout(swap_slide, 5000, 'slow');
}

(function ($) {
  // qb scroller
  $.fn.switcher = function(options) {
    var sw = this;
    $(sw).addClass('sw-on');
    var nav = '';
    if (!$(sw).length) return;    
    $('.item', this).each(function(key, obj){      
      
      if (key != 0) {
        $(obj).hide();        
      }      
      $(obj).addClass('sw-' + key); 
      nav += '<div' + (key != 0 ?'':' class="on" ') + ' id="sw-' + key + '"></div>';
    })
    
    $(sw).append('<div class="sw-nav">' + nav + '</div>');
    
    $('.sw-nav div', $(sw)).click(function() {
      if ($(this).hasClass('on')) {
        return;
      }      
      $(this).parents('.sw-nav').find('.on').removeClass('on');
      $(this).addClass('on');
      var sw_obj = $(this).parents('.sw-on');
      key = $(this).attr('id');
      $('.item:visible', $(sw_obj)).fadeOut();
      $('.item.' + key, $(sw_obj)).fadeIn();
    });
  }
  
}(jQuery));

function sm(text) {
  console.log(text);
}

(function ($) {
  // qb scroller
  $.fn.scroller = function(options) {
    sc = this;
    if (!$(sc).length) return;
    
    this.vars = options; 
        
    this.vars.auto = true;    
    
    $(this).addClass('scroller');      
    first = $(this).find('.car div.frame:first')
    $(this).find('.car div.frame:last').clone().prependTo($(this).find('.car')); 
    $(first).clone().appendTo($(this).find('.car'));        
    this.vars.curr = 1;
    
    this.vars.width = $(this).width();    
    this.vars.max = $(this).find('.car div.frame').length;
    $(this).find('.car div.frame').css({
      'width': (this.vars.width - (this.vars.padding)) + 'px', 
      'float': 'left'
    });
    $(this).find('.car').css({
      'width': (this.vars.width * this.vars.max) + 'px'
    });      
    $(this).find('.car').css({
      'margin-left': -1 * this.vars.curr * this.vars.width + 'px'
    });
    
    if (this.vars.start) {
      this.vars.t = setTimeout(function(){        
        slide_move(sc, 'right'); 
      }, this.vars.start, sc);
    }
    
    $(this).find('.arrowl').bind('click', {
      element: this
    }, function(event){
      slide_stop(event.data.element);
      slide_move(event.data.element, 'left');
    });
    $(this).find('.arrowr').bind('click', {
      element: this
    }, function(event){
      slide_stop(event.data.element);
      slide_move(event.data.element, 'right');
    });
    
    $(this).bind('click', {
      element: this
    }, function(event){
      slide_stop(event.data.element);
    });
    
    update_arrows(this);
    
    function update_arrows(obj) {                
      $(obj).find('.arrows').show().css({
        'opacity' : 1.0, 
        'filter' : 'alpha(opacity=100)'
      });
      if (obj.vars.max - 2 == obj.vars.curr) {
        $(obj).find('.arrowr').hide();
      }
      if (1 == obj.vars.curr) {
        $(obj).find('.arrowl').hide();
      }
    }
    
    function slide_stop(obj) {
      obj.vars.auto = false;
      clearTimeout(obj.vars.t);
    }
    
    function slide_move(obj, dir) {    
      if (!obj)
        return;
        
      clearTimeout(obj.vars.t);
      if (obj.vars.move) {
        return false;
      }
      
      obj.vars.move = true;
      $(obj).find('.arrows').css({
        'opacity' : ('0.' + obj.vars.buttons_opacity), 
        'filter' : 'alpha(opacity=' + obj.vars.buttons_opacity + ')'
      });
        
      if (dir == 'right') {                  
        obj.vars.curr ++;   
      }    
      else  {                
        obj.vars.curr --;        
      }
      
      $(obj).find('.car').animate({
        'marginLeft': (-1) * obj.vars.curr * obj.vars.width + 'px'
      }, obj.vars.speed, obj.vars.easingf, function(){
        if (obj.vars.curr == obj.vars.max - 1) {
          obj.vars.curr = 1;
          $(obj).find('.car').css({
            'margin-left': (-1) * obj.vars.curr * obj.vars.width + 'px'
          });
        }
        
        if (obj.vars.curr == 0) {
          obj.vars.curr = obj.vars.max - 2;
          $(obj).find('.car').css({
            'margin-left': (-1) * obj.vars.curr * obj.vars.width + 'px'
          });
        }
        
        update_arrows(obj); 
        obj.vars.move = false; 
        
        if (obj.vars.auto && obj.vars.start)
          obj.vars.t = setTimeout(function(){
            slide_move(obj, 'right');
          }, obj.vars.next, obj);
      });
    }
  }
  
}(jQuery));

(function ($) {  
  $.fn.change_filter = function(options) {  
        
    $(this).change(function(){
      if ($(this).attr('type') == 'text') {
        $(this).parents('form').submit(function(){
          return false
        });        
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
      
      var search_path = $('#search_path').val();
	  
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

(function ($) {
  // popups
  $.fn.popups = function() {        
    $(this).click(function(){      
      url = $(this).attr('href');
      if (url) {
        $('body').css("cursor", "wait");
        $.ajax({          
          cache: false,
          type: 'POST',
          url: url, 
          dataType: 'json', 
          data: {}, 
          beforeSend: mark_header,
          success: function(response){             
            init_popup(response.content);
          },
          error: function() {
            console.log("Bad Response");
          },
          complete: function() {
            $('body').css("cursor", "default"); // Return the cursor to normal state.
          }
        });
      }      
      return false;
    });
  };
}(jQuery));

function init_popup(content){    
  $('body').append('<div id="overlay"></div>');     
  $('body').append('<div id="popup"></div>');    
  $('#popup').html(content);
  $('#popup').append('<div class="close"></div>');              
  $('#overlay').click(function(){
    pop_overlay();
  });
  $('#popup .close').click(function(){
    pop_overlay();
    return false;
  });
  
  center_popup();
}

function pop_overlay(){  
  $('#popup').remove();
  $('#overlay').remove();      
}

function mark_header(xhr) {
  xhr.setRequestHeader("X-Drupal-Render-Mode", 'json/popups');
}

function center_popup() {
  id = 'popup';  
  
  var scrollTop = $(window).scrollTop();
  max_height = $(window).height();
  max_width = $(window).width();            
  //calculate center
  new_height = $('#' + id).height();

  center_top = max_height > (new_height + 100)?((max_height - new_height) / 2):100;            
  
  $('#' + id).css({
    'top' : (scrollTop + center_top) + 'px', 
    'height': 'auto', 
    'z-index': 1000
  });  
}
