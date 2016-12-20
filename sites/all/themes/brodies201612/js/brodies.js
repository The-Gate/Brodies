(function ($) {
    Drupal.behaviors.page_helpers = {
        attach: function (context) {
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

        }
    }
}(jQuery)
        )