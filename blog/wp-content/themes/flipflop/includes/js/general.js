/*-----------------------------------------------------------------------------------*/
/* GENERAL SCRIPTS */
/*-----------------------------------------------------------------------------------*/


jQuery(document).ready(function(){

	// Table alt row styling
	jQuery( '.entry table tr:odd' ).addClass( 'alt-table-row' );
	
	// FitVids - Responsive Videos
	jQuery( ".post, .widget, .panel" ).fitVids();
	
	// Add class to parent menu items with JS until WP does this natively
	jQuery("ul.sub-menu, ul.children").parents('li').addClass('parent');
	
	
	// Responsive Navigation (switch top drop down for select)
	jQuery('ul#top-nav').mobileMenu({
		switchWidth: 767,                   //width (in px to switch at)
		topOptionText: 'Select a page',     //first option text
		indentString: '&nbsp;&nbsp;&nbsp;'  //string for indenting nested items
	});
  	
  	
  	
  	// Show/hide the main navigation
  	jQuery('.nav-toggle').click(function() {
	  jQuery('#navigation').slideToggle('fast', function() {
	  	return false;
	    // Animation complete.
	  });
	});
	
	// Stop the navigation link moving to the anchor (Still need the anchor for semantic markup)
	jQuery('.nav-toggle a').click(function(e) {
        e.preventDefault();
    });
    
    
    
    
    // add class to each list item on archive page
    jQuery('.archiveList > li').addClass(function(i){return "archiveItem" + (i + 1);});
    
    // add class to each category in sidebar
    
    jQuery('.jcl_widget > li').addClass(function(i){return "categoryNo" + (i + 1);});
    
    // expand sidebar categorys if on correct page
    /*
    jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/bclaims/.test(loc)) {
    jQuery('li.categoryNo1 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo2, li.categoryNo3, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol, #woodojo_twitterprofile-2, #woodojo_tweets-2').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	jQuery('#woodojo_twitterprofile-4, #woodojo_tweets-4').addClass('inline');
  	}
  	 
	});
	
	 jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/corporate/.test(loc)) {
    jQuery('li.categoryNo1, li.categoryNo3, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	}
	});

	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/employment/.test(loc)) {
    jQuery('li.categoryNo3 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo1, li.categoryNo2, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol, #woodojo_twitterprofile-2, #woodojo_tweets-2').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	jQuery('#woodojo_twitterprofile-7, #woodojo_tweets-7').addClass('inline');
  	}
	});
	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/family-law/.test(loc)) {
    jQuery('li.categoryNo1, li.categoryNo3, li.categoryNo2, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	}
	});
	
	
	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/health-and-safety/.test(loc)) {
    jQuery('li.categoryNo5 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo2, li.categoryNo3, li.categoryNo4, li.categoryNo1, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	}
	});
	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/planning/.test(loc)) {
    jQuery('li.categoryNo1, li.categoryNo3, li.categoryNo2, li.categoryNo5, li.categoryNo4, li.categoryNo7, li.categoryNo8, li.categoryNo9, span.jcl_symbol').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	}
	});
	

	
    
    jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/public-law/.test(loc)) {
    jQuery('li.categoryNo7 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo2, li.categoryNo3, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo1, li.categoryNo8, li.categoryNo9, span.jcl_symbol, #woodojo_twitterprofile-2, #woodojo_tweets-2').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	jQuery('#woodojo_twitterprofile-6, #woodojo_tweets-6').addClass('inline');
  	}
	});
	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/renewables/.test(loc)) {
    jQuery('li.categoryNo8 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo2, li.categoryNo3, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo1, li.categoryNo9, span.jcl_symbol').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	}
	});
	
	jQuery(function() {
  	var loc = window.location.href; // returns the full URL
  	if(/technology/.test(loc)) {
    jQuery('li.categoryNo9 ul li').addClass('expandedBrod');
    jQuery('li.categoryNo2, li.categoryNo3, li.categoryNo4, li.categoryNo5, li.categoryNo6, li.categoryNo7, li.categoryNo8, li.categoryNo1, span.jcl_symbol, #woodojo_twitterprofile-2, #woodojo_tweets-2').addClass('hidden');
  	jQuery('#jcl_widget-2 h3').text('subcategories');
  	jQuery('#woodojo_twitterprofile-3, #woodojo_tweets-3').addClass('inline');
  	}
	});*/
    
    // split post content into two columns
/*    jQuery('.post .entry').columnize({ columns: 2 });*/
  

  /* Quicker version of the above , also included active sub items 
     as previously categories didnt stay open when in a sub category  */
  jQuery( function() {

      var item = jQuery('.widget_jcl_widget'),
          active = item.find(' > ul > li > a').hasClass('jcl_active'),
          subItem = item.find(' > ul > li > ul > li > a.jcl_active').hasClass('jcl_active');

          if( active ) {
             item.find('> ul > li > a.jcl_active ~ ul > li').show();
          }

          if ( subItem ) {

              item.find('> h3').text('Subcategories');
              item.find(' > ul > li > ul > li > a.jcl_active').parent().show().siblings().show();
          } 
  });
    
    jQuery('.archiveItem6').before('<div style="clear:both"></div>');
    jQuery('.archiveItem10').before('<div style="clear:both"></div>');


});