/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {
  $(window).load(function () {
    $('#block-gmap_location-0').append($('.location-locations-wrapper'));
    /**
     * make the addresses into an ordered list
     */
    $('.location-locations-wrapper > .vcard').wrap('<li></li>')
    $('.location-locations-wrapper > li').wrapAll('<ol></ol>');

  });
}(jQuery));
