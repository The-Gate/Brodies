(function ($) {
  Drupal.behaviors.page_helpers = {
    attach: function (context, settings) {
      //breakpoints
      var screen_xs_min = 480;
      // Small screen / tablet
      var screen_sm_min = 768;
      // Medium screen / desktop
      var screen_md_min = 992;
      // Large screen / wide desktop

      if ($(window).width() > screen_sm_min) {
        $('.menu-block-3 li.dropdown > a').click(function (e) {
          e.preventDefault();
        });
      }
      if ($(window).width() < screen_sm_min) {
        $('.menu-block-12 li.dropdown > a.dropdown-li').on('click', function (e) {
          e.preventDefault();
        });
      }

      $(document).delegate('#edit-reset', 'click', function (event) {
        event.preventDefault();
        $('#views-exposed-form-vacancies-block').each(function () {
          $('#views-exposed-form-vacancies-block select option').removeAttr('selected');
          this.reset();
          $('#views-exposed-form-vacancies-block .views-submit-button .form-submit').click();
        });
        return false;
      });

      function init_popup(content) {
        $('body').append('<div id="overlay"></div>');
        $('body').append('<div id="popup"></div>');
        $('#popup').html(content);
        $('#popup').append('<div class="close"></div>');
        $('#overlay').click(function () {
          pop_overlay();
        });
        $('#popup .close').click(function () {
          pop_overlay();
          return false;
        });

        center_popup();
      }

      function pop_overlay() {
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

        center_top = max_height > (new_height + 100) ? ((max_height - new_height) / 2) : 100;

        $('#' + id).css({
          'top': (scrollTop + center_top) + 'px',
          'height': 'auto',
          'z-index': 1000
        });
      }

      if ($('h1.page-header').length > 0) {
        var titleHeight = ($('h1.page-header').css('line-height')).replace(/[^-\d\.]/g, '');
        if ($('h1.page-header').height() > titleHeight) {
          if ($('h1.page-header').height() > 27) {
            $('.region-sidebar-first,.region-sidebar-second').css({
              'padding-top': ($('h1.page-header').height() - titleHeight) + 'px'
            })
          }
        }
      }
      if ($('.field-name-body img.media-element').length > 0) {
        $('.field-name-body img.media-element').each(function () {
          var picAlign = $(this).data('picture-align');
          var picAlignClass = '';

          if (typeof picAlign !== typeof undefined) {
            picAlignClass = 'pull-' + picAlign;
            $(this).parent().addClass(picAlignClass);
          }
        });
      }
      if ($('.field-name-body table').length > 0) {
        $('.field-name-body table').each(function () {
          $(this).addClass('table-striped').wrap('<div class="table-responsive"></div>');

        });
      }
      if ($('.infopanel-wrapper').length > 0) {
        $('.infopanel-wrapper').each(function () {
          $(this).wrap('<div class="infopanel-wrapper-outer"></div>');

        });
      }

      // show / hide key contacts in sidebar second
      if ($('.sidebar-second .field-name-field-related-people > .field-items > .field-item').length > 2) {
        $('.sidebar-second .field-name-field-related-people > .field-items > .field-item').slice(2).addClass('hide');
        $('.sidebar-second .field-name-field-related-people > .field-items > .field-item:last-child').after('<div class="field-item field-item-expand"><div class="read-more-block"><a href="#">Meet the team</a></div></div>');
        $('.sidebar-second .field-name-field-related-people > .field-items > .field-item.field-item-expand').addClass('plus');
      }
      $('.sidebar-second .field-name-field-related-people .field-item-expand a').click(function (e) {
        e.preventDefault();
        if ($(this).parent().parent().attr('class') == 'field-item field-item-expand plus') {
          $('.sidebar-second .field-name-field-related-people > .field-items > .field-item').removeClass('hide');
          $(this).parent().parent().addClass('minus');
          $(this).parent().parent().removeClass('plus');
        }
        else if ($(this).parent().parent().attr('class') == 'field-item field-item-expand minus') {
          $('.sidebar-second .field-name-field-related-people > .field-items > .field-item:not(.field-item-expand)').slice(2).addClass('hide');
          $(this).parent().parent().addClass('plus');
          $(this).parent().parent().removeClass('minus');
        }
      });
      // video pop up
      $('.vi').click(function (e) {
        e.preventDefault();
        var content = '';
        eval('content = ' + $('span.video', this).html());
        init_popup('<div class=\"video\">' + content.video + '</div>');
        return false;
      });

      // webform pop up
      $('.wf').click(function (e) {
        e.preventDefault();
        var thisFormEl = $(this).data('inputElement');
        if (!(thisFormEl == undefined) && !(thisFormEl == '')) {
          var radiogroup = $('#webform #' + thisFormEl).attr('name');
          $('#webform input[name="' + radiogroup + '"]').attr('checked', false);
          $('#webform #' + thisFormEl).attr('checked', 'checked');
        }
        var content = $('#webform').html();
        if (!(content == undefined)) {
          init_popup($('#webform').html());
        }
        else {
          init_popup('<p>Sorry, there has been an error</p>');
        }
      });
      if ($('.field-name-field-related-people, .field-name-field-event-speakers').length > 0) {
        $('.field-name-field-related-people .field-name-field-people-email .field-item, .field-name-field-event-speakers .field-name-field-people-email .field-item').each(function () {
          var emailLink = '<div class="read-more-block"><a href="mailto:' + $(this).text() + '">Email</a></div>';
          $(this).text('');                     //console.log(emailLink)
          $(this).append(emailLink);
        });
      }

      if ($('.node-type-people').length > 0) {
        $(".related-wrapper h2 span").text(function (index, text) {
          fname = $('.field-name-field-people-fname').text();
          fname = fname.replace(/\s*$/, "");

          return text.replace("##name##", fname);
        });
        if ($('.field-name-field-people-email').length > 0) {
          $('.field-name-field-people-email .field-item').each(function () {
            var emailLink = '<a href="mailto:' + $(this).text() + '">' + $(this).text() + '</a>';
            $(this).text('');
            //console.log(emailLink)
            $(this).append(emailLink);
          });
        }
        if ($('.field-name-field-people-phone').length > 0) {
          $('.field-name-field-people-phone .field-item').each(function () {
            phoneRaw = $(this).text();
            phoneClean = phoneRaw.replace(/\D/g, '');
            phoneClean = phoneClean.replace(/^(44)/, "");
            var phoneLink = '<a href="tel:' + phoneClean + '">' + $(this).text() + '</a>';
            $(this).text('');
            $(this).append(phoneLink);
          });
        }
      }
      $('#edit-field-people-partner-value-wrapper .form-control').removeClass('form-control');

      // move addtoany to end of body copy
      if ($('#block-addtoany-addtoany-button').length > 0) {
        $('.field-name-body').after($('#block-addtoany-addtoany-button'));
      }
      // blockquote slick carousel
      var blockQuoteCount = $('.field-name-body blockquote').length;
      if (blockQuoteCount > 0) {
        $('.field-name-body blockquote').each(function () {
          var text = $(this).text();
          text = text.replace("<p>", "");
          text = text.replace("</p>", "");
          $(this).text(text);
          $(this).prepend('<img src="/sites/all/themes/brodies201612/images/quote-open.png" class="quote-open">').append('<img src="/sites/all/themes/brodies201612/images/quote-close.png" class="quote-close">');
          $(this)
            .nextUntil('blockquote', 'p').filter(function (i) {
            return $(this).hasClass('quote-title-1') || $(this).hasClass('quote-title-2')
          })
            .add(this)
            .wrapAll('<div class="quote-slide"></div>');
        });
        if (blockQuoteCount > 1) {
          $('.quote-slide').wrapAll('<div class="slick-quote col-md-10 col-md-offset-1"></div>');
          $('.slick-quote').after('<div class="clearfix"></div>')
          $('.slick-quote').slick({
            adaptiveHeight: true
          });
        }
      }

      if ($('.field-name-field-graduate-slideshow .field-item .grad-slide').length > 1) {
        $('.field-name-field-graduate-slideshow .field-item .grad-slide').wrapAll('<div class="slick-grad mod-quote"></div>');
        $('.field-name-field-graduate-slideshow .field-item .slick-grad').after('<div class="clearfix"></div>')
        $('.field-name-field-graduate-slideshow .field-item .slick-grad').slick({
          autoplay: true,
          autoplaySpeed: 2000,
          fade: true,
          dots: true,
          speed: 500,
          infinite: true,
          prevArrow: false,
          nextArrow: false,
          cssEase: 'ease-in-out'

        });
      }

      if ($('.field-name-field-graduate-slideshow-bottom .field-item .grad-slide').length > 1) {
        $('.field-name-field-graduate-slideshow-bottom .field-item .grad-slide').wrapAll('<div class="slick-grad-quote mod-quote"></div>');
        $('.field-name-field-graduate-slideshow-bottom .field-item .slick-grad-quote').after('<div class="clearfix"></div>')
        $('.field-name-field-graduate-slideshow-bottom .field-item .slick-grad-quote').slick({
          autoplay: true,
          autoplaySpeed: 7000,
          fade: true,
          dots: true,
          speed: 500,
          infinite: true,
          cssEase: 'ease-in-out'

        });
      }

      if ($('.cta-quote-slick').length > 0) {
        $('.cta-quote-slick .field-items').slick({
          adaptiveHeight: true
        });
      }

      // application form - over the progress bar to the first field set heading
      if ($('.node-type-webform.page-graduate .webform-progressbar').length > 0) {
        $(".webform-progressbar .webform-progressbar-number").text($(".webform-progressbar .webform-progressbar-number").text().replace("Page", "Step"));
        $('.node-type-webform.page-graduate .webform-progressbar').appendTo($('.node-type-webform.page-graduate form > div > fieldset:first > legend'));
        $('.node-type-webform.page-graduate  form > div > fieldset:first > legend').append('<div class="title-icon"><img src="/sites/all/themes/brodies201612/images/title-icons/title-icon-graduates.png"></div>');
        $('.glyphicon-ok').addClass('glyphicon-floppy-save').removeClass('glyphicon-ok');
        $('.webform-previous, .webform-next,.btn-primary.form-submit').wrapAll('<div class="pull-right"></div>')
      }

      // search
      $('#block-views-search-block .view-content').prepend($('.view-search .view-header'));
      $('.close-results').click(function (e) {
        e.preventDefault();
        $('#block-views-search-block .view-content, #block-views-search-block .view-header,#block-views-search-block .pager').remove();
      });
      // search on mobile - move the search input to screen top to give room
      // for results
      $("#edit-search-api-views-fulltext-wrapper #edit-search-api-views-fulltext").focusin(function () {
        //                console.log('start scrollin');
        if ($(window).width() < screen_sm_min) {
          $('html,body').animate({scrollTop: ($(this).offset().top - ($(this).height() * 2))}, 800);
        }
      });


      if ($('.ckeditor-tabber').length > 0) {
        var all_content = $('.ckeditor-tabber dd').hide();
        $('.ckeditor-tabber dt').each(function () {
          $(this).prepend('<span class="ui-tabber-header-icon"></span>');
        });
        $('.ckeditor-tabber dt').on("click", function () {
          all_content.hide('fast');
          if ($(this).hasClass('active')) {
            $('.ckeditor-tabber dt').removeClass('active');
          }
          else {
            $('.ckeditor-tabber dt').removeClass('active');
            $(this).addClass('active');
            $(this).next('dd').slideToggle('fast', function () {                             //console.log('start check');
              if ($(this).offset().top < $(window).scrollTop()) {
                //console.log('this offset: ' + $(this).offset().top + ' scroll
                // window: ' + $(window).scrollTop());
                var scrollTo = ($(this).offset().top) - 100;
                $(window).scrollTop(scrollTo);
                //console.log('this offset: ' + scrollTo + ' scroll window: ' +
                // $(window).scrollTop());
              }
            })
          }

        });
      }
      if ($('.ui-accordion-header').length > 0) {
        $('.ui-accordion-header').click(function () {
          if ($(window).width() < screen_md_min) {
            var currentId = this.id;
            currentId = "#" + currentId;
            setTimeout(function () { //<-- delayed animation to solve conflicts with others "scrollto"
              $('html, body').animate({
                scrollTop: $(currentId).offset().top
              }, 1000);
            }, 500);
          }
        });
      }
      // landing page
      // if the main content is longer than the right video image, hide under a
      // 'more' link
      function readMoreSetup() {
        if ($('.page-landing').length > 0) {
          if ($(window).width() > screen_md_min) {
            var rheight = $('.col-md-6.col-right').height();
            if ($('.col-md-6.col-left .text-wrapper').height() > rheight) {
              $('.lp2-show-more').remove();
              if ((rheight - 30) > 0) {
                $('.col-md-6.col-left .text-wrapper').css({
                  'height': rheight - 30,
                  'overflow': 'hidden'
                });
                $('.col-md-6.col-left .text-wrapper').after('<div class="lp2-show-more"><a href="#" class="closed more-link">MORE</a></div>');
              }
              $('.lp2-show-more a').click(function (e) {
                e.preventDefault();
                if ($(this).hasClass('closed')) {
                  $('.col-md-6.col-left .text-wrapper').css({
                    'height': '',
                    'overflow': ''
                  });
                  $(this).removeClass('closed')
                  $(this).text('HIDE');
                }
                else {
                  if ((rheight - 30) > 0) {
                    $('.col-md-6.col-left .text-wrapper').css({
                      'height': rheight - 30,
                      'overflow': 'hidden'
                    });
                    $(this).addClass('closed')
                    $(this).text('MORE');
                  }
                }
              });
            }
          }
          else {
            $('.col-md-6.col-left .text-wrapper').css({
              'height': '',
              'overflow': ''
            });
            $('.lp2-show-more').remove();
          }

          if ($('.col a.more-link').length > 0) {
            $('.mask').remove();
            $('.col a.more-link').each(function () {
              $(this).parent().after('<div class="mask"></div>');
            });
          }
        }
      }

      if ($('.node-type-lpagef').length > 0) {
        readMoreSetup();
      }

      if ($('.main-content .seminar-buttons').length > 0 && $('.main-content .custom-seminar-form').length == 0) {
        $('.main-content .seminar-buttons').prependTo($('.region-pre-content'));
      }

      // move the add to calendar to more useful place
      if ($('.node-type-event #block-brseminarbooking-seminar-calendar').length > 0) {
        $('#block-brseminarbooking-seminar-calendar').insertAfter($('#block-system-main .field-name-body'));
      }
      if ($('.page-node-44 .block-brseminarbooking').length > 0) {
        $('.block-brseminarbooking').insertAfter($('.view-seminars .view-filters'));
      }

      // landing page - paragraphs version
      // if the first content block is a video, move hte <a name. below it
      if ($('body.node-type-landing-page').length > 0) {
        $('.paragraphs-items-field-layout-blocks > .field-name-field-layout-blocks > .field-items > .field-item:first-child').find('.youtubeframe').closest('.field-item').after($('#main-content-marker'));
      }

      function doneResizing() {
        readMoreSetup();
      }

      var resizeId;
      $(window).resize(function () {
        clearTimeout(resizeId);
        resizeId = setTimeout(doneResizing, 500);
      });
    }
  }
}(jQuery))
