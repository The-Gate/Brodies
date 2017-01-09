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
            // video pop up
            $('.vi').click(function (e) {
                e.preventDefault();
                var content = '';
                eval('content = ' + $('span.video', this).html());
                init_popup('<div class=\"video\">' + content.video + '</div>');
                return false;
            });



            // landing page
            // if the main content is longer than the right video image, hide under a 'more' link


            function readMoreSetup() {
                if ($('.node-type-lpagef').length > 0) {
                    if ($(window).width() > screen_md_min) {
                        var rheight = $('.col-md-6.col-right').height();
                        if ($('.col-md-6.col-left .text-wrapper').height() > rheight) {
                            $('.lp2-show-more').remove();
                            if ((rheight - 30) > 0) {
                                $('.col-md-6.col-left .text-wrapper').css({'height': rheight - 30, 'overflow': 'hidden'});
                                $('.col-md-6.col-left .text-wrapper').after('<div class="lp2-show-more"><a href="#" class="closed view">MORE</a></div>');
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

                    if ($('.col a.view').length > 0) {
                        $('.col a.view').each(function () {
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

       