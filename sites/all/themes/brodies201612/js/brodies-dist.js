!function($){Drupal.behaviors.page_helpers={attach:function(context){function init_popup(e){$("body").append('<div id="overlay"></div>'),$("body").append('<div id="popup"></div>'),$("#popup").html(e),$("#popup").append('<div class="close"></div>'),$("#overlay").click(function(){pop_overlay()}),$("#popup .close").click(function(){return pop_overlay(),!1}),center_popup()}function pop_overlay(){$("#popup").remove(),$("#overlay").remove()}function mark_header(e){e.setRequestHeader("X-Drupal-Render-Mode","json/popups")}function center_popup(){id="popup";var e=$(window).scrollTop();max_height=$(window).height(),max_width=$(window).width(),new_height=$("#"+id).height(),center_top=max_height>new_height+100?(max_height-new_height)/2:100,$("#"+id).css({top:e+center_top+"px",height:"auto","z-index":1e3})}function readMoreSetup(){if($(".page-landing").length>0){if($(window).width()>screen_md_min){var e=$(".col-md-6.col-right").height();$(".col-md-6.col-left .text-wrapper").height()>e&&($(".lp2-show-more").remove(),e-30>0&&($(".col-md-6.col-left .text-wrapper").css({height:e-30,overflow:"hidden"}),$(".col-md-6.col-left .text-wrapper").after('<div class="lp2-show-more"><a href="#" class="closed more-link">MORE</a></div>')),$(".lp2-show-more a").click(function(i){i.preventDefault(),$(this).hasClass("closed")?($(".col-md-6.col-left .text-wrapper").css({height:"",overflow:""}),$(this).removeClass("closed"),$(this).text("HIDE")):e-30>0&&($(".col-md-6.col-left .text-wrapper").css({height:e-30,overflow:"hidden"}),$(this).addClass("closed"),$(this).text("MORE"))}))}else $(".col-md-6.col-left .text-wrapper").css({height:"",overflow:""}),$(".lp2-show-more").remove();$(".col a.more-link").length>0&&($(".mask").remove(),$(".col a.more-link").each(function(){$(this).parent().after('<div class="mask"></div>')}))}}function doneResizing(){readMoreSetup()}var screen_xs_min=480,screen_sm_min=768,screen_md_min=992;if($("h1.page-header").length>0){var titleHeight=$("h1.page-header").css("line-height").replace(/[^-\d\.]/g,"");$("h1.page-header").height()>titleHeight&&$("h1.page-header").height()>27&&$(".region-sidebar-first,.region-sidebar-second").css({"padding-top":$("h1.page-header").height()-titleHeight+"px"})}$(".vi").click(function(e){e.preventDefault();var content="";return eval("content = "+$("span.video",this).html()),init_popup('<div class="video">'+content.video+"</div>"),!1}),$(".field-name-field-related-people").length>0&&$(".field-name-field-related-people .field-name-field-people-email .field-item").each(function(){var e='<div class="read-more-block"><a href="mailto:'+$(this).text()+'">Email</a></div>';$(this).text(""),console.log(e),$(this).append(e)}),$(".node-type-lpagef").length>0&&readMoreSetup();var resizeId;$(window).resize(function(){clearTimeout(resizeId),resizeId=setTimeout(doneResizing,500)})}}}(jQuery);
//# sourceMappingURL=brodies-dist.js.map