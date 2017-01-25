var go_submit = false;
Drupal.behaviors.init_crm_start_value = function (context) {  
  $('.start_clear').clear_start();  
};
/**
 * Attaches the autocomplete behaviour to all required fields
 */

 
Drupal.autocompleteAutoAttach = function () {
  var acdb2 = [];
  $('input.ajax_search').each(function () {    
    var uri = '/' + this.value;    
    
    if (!acdb2[uri]) {
      acdb2[uri] = new Drupal.ACDB2(uri);
    }
    var input_id = this.id.substr(0, this.id.length - 12);
    var input = $('#' + input_id)
      .attr('autocomplete', 'OFF')[0]; 
    
    //add settings  
    input.header_text =      
    $('#' + input_id + '-header-text').html();
    input.flyout_margin =      
    $('#' + input_id + '-flyout-margin').val(); 
    
    $(input).parents('form').submit(Drupal.autocompleteSubmit2);
    new Drupal.jsAC2(input, acdb2[uri]);
  });
}


/**
 * Prevents the form from submitting if the suggestions popup is open
 * and closes the suggestions popup when doing so.
 */
Drupal.autocompleteSubmit2 = function (obj) {    
  if ($(obj.target).find('input.ajax_search').length) {
    return go_submit;  
  }
  else {
    return true;
  }
}

/**
 * An AutoComplete object
 */
Drupal.jsAC2 = function (input, db) {
  var ac = this;
  this.input = input;
  this.db = db;  
  this.header_text = input.header_text;
  this.flyout_margin = input.flyout_margin;
  
  $(this.input)
    .keydown(function (event) { return ac.onkeydown(this, event); })
    .keyup(function (event) { ac.onkeyup(this, event) })
    .blur(function () { ac.hidePopup(); ac.db.cancel(); })
    .focus(function () { ac.showPopup(); });

};

/**
 * Handler for the "keydown" event
 */
Drupal.jsAC2.prototype.showPopup = function (type) {
  empty = {};
  
  if (type == 'throbber') {
    this.showThrobber = true;        
    //empty[0] = '<div class="popup_throbber"><img src="/sites/all/themes/revolve/gfx/throbber.gif"/></div>';
  }
  else
    empty[0] = ' ';  
    
  this.infoText = true;
  this.populatePopup();
  this.found(empty);
}


/**
 * Handler for the "keydown" event
 */
Drupal.jsAC2.prototype.onkeydown = function (input, e) {
  if (!e) {
    e = window.event;
  }
  switch (e.keyCode) {
    case 40: // down arrow
      this.selectDown();
      return false;
    case 38: // up arrow
      this.selectUp();
      return false;
    default: // all other keys
      return true;
  }
}

/**
 * Handler for the "keyup" event
 */
Drupal.jsAC2.prototype.onkeyup = function (input, e) {
  if (!e) {
    e = window.event;
  }
  switch (e.keyCode) {
    case 16: // shift
    case 17: // ctrl
    case 18: // alt
    case 20: // caps lock
    case 33: // page up
    case 34: // page down
    case 35: // end
    case 36: // home
    case 37: // left arrow
    case 38: // up arrow
    case 39: // right arrow
    case 40: // down arrow
      return true;

    case 9:  // tab
    case 13: // enter
    case 27: // esc
      if (this.selected)
        this.hidePopup(e.keyCode);
      return true;

    default: // all other keys
      if (input.value.length >= 0)
        this.populatePopup();
      else
        this.hidePopup(e.keyCode);
      return true;
  }
}

/**
 * Puts the currently highlighted suggestion into the autocomplete field
 */
Drupal.jsAC2.prototype.select = function (node) {
  this.input.value = node.autocompleteValue;
}

/**
 * Get current selected element
 */
Drupal.jsAC2.prototype.getSelectedNr = function () {
  current_element = this.selected;
  count = 0;
  current_element_nr = 0;
  if (this.selected && !this.list) {
    this.list = $('li', this.popup);
  }
  
  if (this.list && current_element) {    
    $.each(this.list, function(){      
      if(this == current_element) {
        current_element_nr = count;
        return;
      }
      count++;
    });
  }
  
  return current_element_nr;    
}
 
/**
 * Highlights the next suggestion
 */
Drupal.jsAC2.prototype.selectDown = function () {      
  current_element_nr = this.getSelectedNr();
  
  if (this.selected && (this.list.get(current_element_nr+1))) {    
    this.highlight(this.list.get(current_element_nr+1));
  }
  else {
    this.list = $('li', this.popup);
    if (this.list.size() > 0) {      
      this.highlight(this.list.get(0));      
    }
  }
}

/**
 * Highlights the previous suggestion
 */
Drupal.jsAC2.prototype.selectUp = function () {
  current_element_nr = this.getSelectedNr();
  
  if (this.selected && (current_element_nr-1)>=0) {
    this.highlight(this.list.get(current_element_nr-1));
  }
}

/**
 * Highlights a suggestion
 */
Drupal.jsAC2.prototype.highlight = function (node) {
  $('li', this.popup).removeClass('selected');
  
  $(node).addClass('selected');
  this.selected = node;
}

/**
 * Unhighlights a suggestion
 */
Drupal.jsAC2.prototype.unhighlight = function (node) {
  $(node).removeClass('selected');
  this.selected = false;
}

/**
 * Hides the autocomplete suggestions
 */
Drupal.jsAC2.prototype.hidePopup = function (keycode) {
  start_hide = false;
  // Select item if the right key or mousebutton was pressed
  if (this.selected && ((keycode && keycode == 13) )) {
    //jump to url
    this.stopHide = false;            
    window.location = this.selected.searchlink;
    /*
    $(this.input).val(this.selected.searchlink);  
    if (this.selected.organisation) {
      go_submit = true;    
      $(this.input.form).submit();
    }   
    else {      
      start_hide = true;
    } 
    */               
  }
  else if (!this.stopHide){
    start_hide = true;
  }
  
  if (start_hide) {    
    // Hide popup
    var popup = this.popup;
    if (popup) {
      //this.popup = null;
     // $(popup).fadeOut('fast', function() { 
              //$(popup).remove();
              $(popup).hide(); 
     // });     
    }
    this.selected = false;
  }
  
  return;
}

/**
 * Positions the suggestions popup and starts a search
 */
Drupal.jsAC2.prototype.populatePopup = function () {
  // clear li list
  this.list = null;
  
  if (!this.popup) {
    
    this.selected = false;
    this.popup = document.createElement('div');
    this.popup.id = 'groups_autocomplete';
    this.popup.owner = this;
    
    $(this.popup).css({
      top: (this.input.offsetHeight) +'px',
      //width: (this.input.offsetWidth - 4) +'px',
      marginLeft: -10,
      backgroundColor: '#FFFFFF',
      //width: 260 + 'px',      
      display: 'none'
    });    
    $(this.popup).addClass('autocomplete gr-resacplt');
    $(this.input).before(this.popup);
  }
  else {
     $(this.popup).show();
  }
  
  if (!this.infoText) {
    // Do search  
    if (this.input.value.length > 1) {        
      this.db.owner = this;
      this.db.search(this.input.value);
    }
    else {
      this.showPopup();
    }
  }  
  else {
    this.infoText = false;
  }
}

/**
 * Fills the suggestion popup with any matches received
 */
Drupal.jsAC2.prototype.found = function (matches) {
  // If no value in the textfield, do not show the popup.
  if (!this.input.value.length) {
    return false;
  }
  
  // Prepare matches
  var fmnu = document.createElement('div');
  $(fmnu).addClass('fmnu');  
  $(fmnu).css({    
    display: 'block'
  });
  
  var fmnu_inner = document.createElement('span');
  $(fmnu_inner).addClass('fmnu-inner');
      
  var ac = this;
  for (key in matches) {
    var header = ''; //'<div class="pad wi33 b2s">' + this.header_text + '</div>';        
    $(fmnu_inner).html(header + matches[key]);
  }      
  
  // Show popup with matches, if any
  if (this.popup) {
    if (fmnu_inner.childNodes.length > 0) {      
      $(fmnu).append(fmnu_inner);            
      $(this.popup).empty().append(fmnu).show();
      ac = this;
      //actions and values on all li elements
      $.each($('.fmnu-inner li'), function() { 
        //take link value from inside div 
        var innerDiv = this.childNodes[0];
        this.searchlink = $(innerDiv).attr("searchlink");
        this.organisation = $(innerDiv).attr("org");
                
        //add necessary actions
        $(this).mousedown(function () { 
          //jump to url        
          ac.stopHide = false;
          window.location = this.searchlink;
          /*
          $(ac.input).val(this.searchlink);                    
          ac.hidePopup();
          if (this.organisation) {
            go_submit = true;    
            $(ac.input.form).submit();
          } 
          */                       
        })
        .mouseover(function () { ac.highlight(this); })
        .mouseout(function () { ac.unhighlight(this); });
        
      });
    }
    else {
      //$(this.popup).css({visibility: 'hidden'});
      this.hidePopup();
    }
  }
}

Drupal.jsAC2.prototype.setStatus = function (status) {
  switch (status) {
    case 'begin':      
      this.showPopup('throbber');
      
      $(this.input).addClass('throbbing');            
      $('#' + $(this.input).attr("id") + '-throbber').removeClass('hide');
      break;
    case 'cancel':
    case 'error':
    case 'found':
      $('img.throbber').addClass('hide');
      $(this.input).removeClass('throbbing');
      
      break;
  }
}

/**
 * An AutoComplete DataBase object
 */
Drupal.ACDB2 = function (uri) {
  this.uri = uri;
  this.delay = 300;
  this.cache = {};
}

/**
 * Performs a cached and delayed search
 */
Drupal.ACDB2.prototype.search = function (searchString) {
  var db = this;
  this.searchString = searchString;

  // See if this key has been searched for before
  if (this.cache[searchString]) {
    return this.owner.found(this.cache[searchString]);
  }

  // Initiate delayed search
  if (this.timer) {
    clearTimeout(this.timer);
  }
  this.timer = setTimeout(function() {
    db.owner.setStatus('begin');

    // Ajax GET request for autocompletion
    $.ajax({
      type: "GET",
      url: db.uri +'/'+ Drupal.encodeURIComponent(searchString),
      beforeSend: mark_header,
      success: function (data) {
        // Parse back result
        var matches = Drupal.parseJson(data);
        if (typeof matches['status'] == 'undefined' || matches['status'] != 0) {
          db.cache[searchString] = matches;
          // Verify if these are still the matches the user wants to see
          if (db.searchString == searchString) {
            db.owner.showThrobber = false;
            db.owner.found(matches);
          }
          db.owner.setStatus('found');
        }
      },
      error: function (xmlhttp) {
       // alert('An HTTP error '+ xmlhttp.status +' occured.\n'+ db.uri);
      }
    });
  }, this.delay);
}

/**
 * Cancels the current autocomplete request
 */
Drupal.ACDB2.prototype.cancel = function() {
  if (this.owner) this.owner.setStatus('cancel');
  if (this.timer) clearTimeout(this.timer);
  this.searchString = '';
}

// Global Killswitch
if (Drupal.jsEnabled) {
  $(document).ready(Drupal.autocompleteAutoAttach);
}

(function ($) {
  // clear default values
  $.fn.clear_start = function () {
    $(this).parents('form').submit(function(){ //clear default values before submit
      $.each($('.start_clear', this), function() {
        if ($(this).val() == $(this).attr('title')){
          $(this).val('');
        }
      });
      return true;
    });

    $(this).each(function(key, obj) {
      if ($(obj).val() == '') {
        $(obj).val($(this).attr('title'));
      }      
    });
    
    $(this).focus(function(){
      if ($(this).val() == $(this).attr('title')){
        $(this).val('').addClass('scleared');
      }
    });
    $(this).blur(function(){
      if ($(this).val() == ''){
        $(this).val($(this).attr('title')).removeClass('scleared');
      }
    });
  };
}(jQuery));
