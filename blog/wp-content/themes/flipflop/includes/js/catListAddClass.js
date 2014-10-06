// version 1.5.0
// http://welcome.totheinter.net/columnizer-jquery-plugin/
// created by: Adam Wulf @adamwulf, adam.wulf@gmail.com

jQuery(document).ready(function(){


 
 jQuery("ul#archiveList li").each(function(i) {
     this.addClass("archive"+(i+1));
    });

});