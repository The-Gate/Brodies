(function ($) {
    Drupal.behaviors.page_helpers = {
        attach: function (context) {
            //breakpoints
            var screen_xs_min = 480;
            // Small screen / tablet
            var screen_sm_min = 768;
            // Medium screen / desktop
            var screen_md_min = 992;
            // Large screen / wide desktop



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

            if ($('.field-name-field-related-people').length > 0) {
                $('.field-name-field-related-people .field-name-field-people-email .field-item').each(function () {
                    var emailLink = '<div class="read-more-block"><a href="mailto:' + $(this).text() + '">Email</a></div>';
                    $(this).text('');
                    //console.log(emailLink) 
                    $(this).append(emailLink);
                });
            }

            if ($('.node-type-people').length > 0) {
                $(".related-wrapper h2 span").text(function (index, text) {
                    return text.replace("##name##", $('.field-name-field-people-fname').text());
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
                        phoneClean = phoneRaw.replace(/\D/g,'');
                        phoneClean = phoneClean.replace(/^(44)/,"");;
                        var phoneLink = '<a href="tel:' +phoneClean + '">' + $(this).text() + '</a>';
                        $(this).text('');
                        $(this).append(phoneLink);
                    });
                }
            }
            $('#edit-field-people-partner-value-wrapper .form-control').removeClass('form-control');

            // landing page
            // if the main content is longer than the right video image, hide under a 'more' link
            function readMoreSetup() {
                if ($('.page-landing').length > 0) {
                    if ($(window).width() > screen_md_min) {
                        var rheight = $('.col-md-6.col-right').height();
                        if ($('.col-md-6.col-left .text-wrapper').height() > rheight) {
                            $('.lp2-show-more').remove();
                            if ((rheight - 30) > 0) {
                                $('.col-md-6.col-left .text-wrapper').css({'height': rheight - 30, 'overflow': 'hidden'});
                                $('.col-md-6.col-left .text-wrapper').after('<div class="lp2-show-more"><a href="#" class="closed more-link">MORE</a></div>');
                            }
                            $('.lp2-show-more a').click(function (e) {
                                e.preventDefault();
                                if ($(this).hasClass('closed')) {
                                    $('.col-md-6.col-left .text-wrapper').css({'height': '', 'overflow': ''});
                                    $(this).removeClass('closed')
                                    $(this).text('HIDE');
                                } else {
                                    if ((rheight - 30) > 0) {
                                        $('.col-md-6.col-left .text-wrapper').css({'height': rheight - 30, 'overflow': 'hidden'});
                                        $(this).addClass('closed')
                                        $(this).text('MORE');
                                    }
                                }
                            });
                        }

                    } else {
                        $('.col-md-6.col-left .text-wrapper').css({'height': '', 'overflow': ''});
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

       