!function($){Drupal.behaviors.page_helpers={attach:function(context,settings){function init_popup(e){$("body").append('<div id="overlay"></div>'),$("body").append('<div id="popup"></div>'),$("#popup").html(e),$("#popup").append('<div class="close"></div>'),$("#overlay").click(function(){pop_overlay()}),$("#popup .close").click(function(){return pop_overlay(),!1}),center_popup()}function pop_overlay(){$("#popup").remove(),$("#overlay").remove()}function mark_header(e){e.setRequestHeader("X-Drupal-Render-Mode","json/popups")}function center_popup(){id="popup";var e=$(window).scrollTop();max_height=$(window).height(),max_width=$(window).width(),new_height=$("#"+id).height(),center_top=max_height>new_height+100?(max_height-new_height)/2:100,$("#"+id).css({top:e+center_top+"px",height:"auto","z-index":1e3})}function readMoreSetup(){if($(".page-landing").length>0){if($(window).width()>screen_md_min){var e=$(".col-md-6.col-right").height();$(".col-md-6.col-left .text-wrapper").height()>e&&($(".lp2-show-more").remove(),e-30>0&&($(".col-md-6.col-left .text-wrapper").css({height:e-30,overflow:"hidden"}),$(".col-md-6.col-left .text-wrapper").after('<div class="lp2-show-more"><a href="#" class="closed more-link">MORE</a></div>')),$(".lp2-show-more a").click(function(i){i.preventDefault(),$(this).hasClass("closed")?($(".col-md-6.col-left .text-wrapper").css({height:"",overflow:""}),$(this).removeClass("closed"),$(this).text("HIDE")):e-30>0&&($(".col-md-6.col-left .text-wrapper").css({height:e-30,overflow:"hidden"}),$(this).addClass("closed"),$(this).text("MORE"))}))}else $(".col-md-6.col-left .text-wrapper").css({height:"",overflow:""}),$(".lp2-show-more").remove();$(".col a.more-link").length>0&&($(".mask").remove(),$(".col a.more-link").each(function(){$(this).parent().after('<div class="mask"></div>')}))}}function doneResizing(){readMoreSetup()}var screen_xs_min=480,screen_sm_min=768,screen_md_min=992;if($("h1.page-header").length>0){var titleHeight=$("h1.page-header").css("line-height").replace(/[^-\d\.]/g,"");$("h1.page-header").height()>titleHeight&&$("h1.page-header").height()>27&&$(".region-sidebar-first,.region-sidebar-second").css({"padding-top":$("h1.page-header").height()-titleHeight+"px"})}if($(".field-name-body img.media-element").length>0&&$(".field-name-body img.media-element").each(function(){var e=$(this).data("picture-align"),i="";"undefined"!=typeof e&&(i="pull-"+e,$(this).parent().addClass(i))}),$(".sidebar-second .field-name-field-related-people > .field-items > .field-item").length>2&&($(".sidebar-second .field-name-field-related-people > .field-items > .field-item").slice(2).addClass("hide"),$(".sidebar-second .field-name-field-related-people > .field-items > .field-item:last-child").after('<div class="field-item field-item-expand"><div class="read-more-block"><a href="#">Meet the team</a></div></div>'),$(".sidebar-second .field-name-field-related-people > .field-items > .field-item.field-item-expand").addClass("plus")),$(".sidebar-second .field-name-field-related-people .field-item-expand a").click(function(e){e.preventDefault(),"field-item field-item-expand plus"==$(this).parent().parent().attr("class")?($(".sidebar-second .field-name-field-related-people > .field-items > .field-item").removeClass("hide"),$(this).parent().parent().addClass("minus"),$(this).parent().parent().removeClass("plus")):"field-item field-item-expand minus"==$(this).parent().parent().attr("class")&&($(".sidebar-second .field-name-field-related-people > .field-items > .field-item:not(.field-item-expand)").slice(2).addClass("hide"),$(this).parent().parent().addClass("plus"),$(this).parent().parent().removeClass("minus"))}),$(".vi").click(function(e){e.preventDefault();var content="";return eval("content = "+$("span.video",this).html()),init_popup('<div class="video">'+content.video+"</div>"),!1}),$(".field-name-field-related-people, .field-name-field-event-speakers").length>0&&$(".field-name-field-related-people .field-name-field-people-email .field-item, .field-name-field-event-speakers .field-name-field-people-email .field-item").each(function(){var e='<div class="read-more-block"><a href="mailto:'+$(this).text()+'">Email</a></div>';$(this).text(""),$(this).append(e)}),$(".node-type-people").length>0&&($(".related-wrapper h2 span").text(function(e,i){return fname=$(".field-name-field-people-fname").text(),fname=fname.replace(/\s*$/,""),i.replace("##name##",fname)}),$(".field-name-field-people-email").length>0&&$(".field-name-field-people-email .field-item").each(function(){var e='<a href="mailto:'+$(this).text()+'">'+$(this).text()+"</a>";$(this).text(""),$(this).append(e)}),$(".field-name-field-people-phone").length>0&&$(".field-name-field-people-phone .field-item").each(function(){phoneRaw=$(this).text(),phoneClean=phoneRaw.replace(/\D/g,""),phoneClean=phoneClean.replace(/^(44)/,"");var e='<a href="tel:'+phoneClean+'">'+$(this).text()+"</a>";$(this).text(""),$(this).append(e)})),$("#edit-field-people-partner-value-wrapper .form-control").removeClass("form-control"),$(".field-name-body blockquote").length>1&&($(".field-name-body blockquote").each(function(){$(this).prepend('<img src="/sites/all/themes/brodies201612/images/quote-open.png" class="quote-open">').append('<img src="/sites/all/themes/brodies201612/images/quote-close.png" class="quote-close">'),$(this).nextUntil("blockquote","p").filter(function(){return $(this).hasClass("quote-title-1")||$(this).hasClass("quote-title-2")}).add(this).wrapAll('<div class="quote-slide"></div>')}),$(".quote-slide").wrapAll('<div class="slick-quote col-md-10 col-md-offset-1"></div>'),$(".slick-quote").after('<div class="clearfix"></div>'),$(".slick-quote").slick({adaptiveHeight:!0})),$(".field-name-field-graduate-slideshow .field-item .grad-slide").length>1&&($(".field-name-field-graduate-slideshow .field-item .grad-slide").wrapAll('<div class="slick-grad mod-quote"></div>'),$(".field-name-field-graduate-slideshow .field-item .slick-grad").after('<div class="clearfix"></div>'),$(".field-name-field-graduate-slideshow .field-item .slick-grad").slick({autoplay:!0,autoplaySpeed:2e3,fade:!0,dots:!0,speed:500,infinite:!0,prevArrow:!1,nextArrow:!1,cssEase:"ease-in-out"})),$(".field-name-field-graduate-slideshow-bottom .field-item .grad-slide").length>1&&($(".field-name-field-graduate-slideshow-bottom .field-item .grad-slide").wrapAll('<div class="slick-grad-quote mod-quote"></div>'),$(".field-name-field-graduate-slideshow-bottom .field-item .slick-grad-quote").after('<div class="clearfix"></div>'),$(".field-name-field-graduate-slideshow-bottom .field-item .slick-grad-quote").slick({autoplay:!0,autoplaySpeed:2e3,fade:!0,dots:!0,speed:500,infinite:!0,cssEase:"ease-in-out"})),$(".node-type-webform.page-graduate .webform-progressbar").length>0&&($(".webform-progressbar .webform-progressbar-number").text($(".webform-progressbar .webform-progressbar-number").text().replace("Page","Step")),$(".node-type-webform.page-graduate .webform-progressbar").appendTo($(".node-type-webform.page-graduate form > div > fieldset:first > legend")),$(".node-type-webform.page-graduate  form > div > fieldset:first > legend").append('<div class="title-icon"><img src="/sites/all/themes/brodies201612/images/title-icons/title-icon-graduates.png"></div>'),$(".glyphicon-ok").addClass("glyphicon-floppy-save").removeClass("glyphicon-ok"),$(".webform-previous, .webform-next,.btn-primary.form-submit").wrapAll('<div class="pull-right"></div>')),$("#block-views-search-block .view-content").prepend($(".view-search .view-header")),$(".close-results").click(function(e){e.preventDefault(),$("#block-views-search-block .view-content, #block-views-search-block .view-header,#block-views-search-block .pager").remove()}),$("#edit-search-api-views-fulltext-wrapper #edit-search-api-views-fulltext").focusin(function(){$(window).width()<screen_sm_min&&$("html,body").animate({scrollTop:$(this).offset().top-2*$(this).height()},800)}),$(".ckeditor-tabber").length>0){var all_content=$(".ckeditor-tabber dd").hide();$(".ckeditor-tabber dt").on("click",function(){all_content.hide("fast"),$(this).next("dd").slideToggle("fast",function(){if($(this).offset().top<$(window).scrollTop()){var e=$(this).offset().top-100;$(window).scrollTop(e)}})})}$(".node-type-lpagef").length>0&&readMoreSetup(),$(".main-content .seminar-buttons").length>0&&0==$(".main-content .custom-seminar-form").length&&$(".main-content .seminar-buttons").prependTo($(".region-pre-content"));var resizeId;$(window).resize(function(){clearTimeout(resizeId),resizeId=setTimeout(doneResizing,500)})}}}(jQuery);
//# sourceMappingURL=brodies-dist.js.map