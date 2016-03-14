$(document).ready(function () {
    $('#main-menu span').click(function () {
        $(this).parent().parent().toggleClass('active')
    });

    $('#block-br-104 a').click(function () {
        if ($(this).parent().find('ul').length) {
            $(this).parent().toggleClass('active');
            return false;
        }
    });

    // move people image to correct place
    if ($('.section-people-sub').length > 0) {
        console.log($('.node-people .content').length);
        $('.node-people .content').prepend($('#block-views-peson_details-block_1'));
    }

    // hide contact / video / case study if empty
    $('#block-views-Key_Contacts-block_1 .field-content > .node').wrap('<div class="field-item"></div>');
    if ($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length == 0) {
        //$('#block-views-Key_Contacts-block_1').addCss('hide');
    } else {
        if ($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length > 2) {
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item').slice(2).addClass('hide');
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item:last-child').after('<div class="field-item field-item-expand"><div class="node"><h2><a href="#">Meet the team</a></h2></div></div>');
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').addClass('plus');
        }
    }
    if ($('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').length > 0) {
        // add the video pop[ up to the related videos
        $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').each(function () {
            $(this).find('img').wrap('<a class="video-link" href="' + $(this).find('.field-field-video-url .field-item').text() + '" target="_blank"></a>');
            $(this).find('h2').remove();
            $(this).find('.field-field-video-url .field-item').remove();
        });
        $('#block-views-Related_Video-block_1').prependTo('#content > .node > .content .sector');
    } else{
         $('#block-views-Related_Video-block_1').css({
            'display': 'none'
        });
    }
    if ($('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').length == 0) {
        $('#block-views-Case_Studies-block_1').css({
            'display': 'none'
        });
    }
    $('#block-views-Key_Contacts-block_1 label').click(function (e) {
        e.preventDefault();
        $('#block-views-Key_Contacts-block_1 .field-content > .field-item').removeClass('hide');
        if ($('#block-views-Key_Contacts-block_1 .field-content > .field-item').length > 2) {
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item:not(.field-item-expand)').slice(2).addClass('hide');

            $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').addClass('plus');
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item.field-item-expand').removeClass('minus');
        }
        $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
        $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
    });

    $('#block-views-Key_Contacts-block_1 .field-item-expand a').click(function (e) {
        e.preventDefault();
        if ($(this).parent().parent().parent().attr('class') == 'field-item field-item-expand plus') {
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item').removeClass('hide');
            $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
            $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
            $(this).parent().parent().parent().addClass('minus');
            $(this).parent().parent().parent().removeClass('plus');
        }
        else if ($(this).parent().parent().parent().attr('class') == 'field-item field-item-expand minus') {
            $('#block-views-Key_Contacts-block_1 .field-content > .field-item:not(.field-item-expand)').slice(2).addClass('hide');
            $(this).parent().parent().parent().addClass('plus');
            $(this).parent().parent().parent().removeClass('minus');
        }
    });

    $('#block-views-Related_Video-block_1 label').click(function (e) {
        e.preventDefault();
        $('#block-views-Key_Contacts-block_1 .field-content > .field-item').addClass('hide');
        $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').removeClass('hide');
        $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').addClass('hide');
    });
    $('#block-views-Case_Studies-block_1 label').click(function (e) {
        e.preventDefault();
        $('#block-views-Key_Contacts-block_1 .field-content > .field-item').addClass('hide');
        $('#block-views-Related_Video-block_1 .field-content > .field-item,#block-views-Related_Video-block_1 .field-content > .node').addClass('hide');
        $('#block-views-Case_Studies-block_1 .field-content > .field-item,#block-views-Case_Studies-block_1 .field-content > .node').removeClass('hide');
    });

    // hide related sector title if no content
    if ($('#block-views-Related_Areas-block_1').length > 0) {
        if ($('#block-views-Related_Areas-block_1 .field-content > .field-item').length == 0 && $('#block-views-Related_Areas-block_1 .field-content > a').length == 0) {
            //console.log('here agin');
            $('label.views-label-field-related-sector-nid').css({
                'color': '#fff'
            });
        }
        if ($('#block-views-Related_Areas-block_1 .field-content > a').length == 1) {
            $('#block-views-Related_Areas-block_1 .field-content > a').wrap('<div class="field-item field-item-0"></div>');
        }
    }

    // top news full width is no image
    if ($('.view-top-news').length > 0) {

        $('.view-display-id-block_1 .field-content,.view-display-id-block_2 .field-content').each(function () {
            //console.log($(this).find('.img'));
            if ($(this).find('.img').html() == '') {
                $(this).find('.col-left').css({
                    'width': '100%',
                    'margin-right': '0'
                });
                $(this).find('.col-right').css({
                    'display': 'none'
                });
            }
        });

    }

    //$('.listing.l-cs').QBscroller();

    $('#br-search-form select, #br-search-form .form-checkbox, #br-search-form .form-text').change_filter();
});


(function ($) {
    // qb scroller
    $.fn.QBscroller = function (options) {
        $(this).html('<div class="grid">' + $(this).html() + '</div>')
        iwidth = $(this).find('.item:first').width();
        $(this).find('.grid').css({'width': (iwidth + 40) * $(this).find('.item').length + 20 + 'px'})
    }
}(jQuery));

(function ($) {
    $.fn.change_filter = function (options) {

        $(this).change(function () {
            if ($(this).attr('type') == 'text') {
                $(this).parents('form').submit(function () {
                    return false
                });
            }

            var val;
            name = $(this).attr('name');
            if ($(this).is(":checkbox")) {
                if (!$(this).hasClass('negative') && $(this).attr("checked") == true || $(this).hasClass('negative') && $(this).attr("checked") != true) {
                    val = $(this).val();
                }
            }
            else
                val = $(this).val();

            search_path = $('#search_path').val();

            current_url_no_query = document.location + '';
            current_url_no_query = current_url_no_query.replace('http://', '');
            current_url_no_query = current_url_no_query.substring(current_url_no_query.indexOf('/'));

            if (current_url_no_query.indexOf('?') != -1) {
                current_url_no_query = current_url_no_query.substring(0, current_url_no_query.indexOf('?'));
            }

            current_url = document.location + '';
            if (search_path) {
                if (current_url_no_query != search_path) {
                    current_url = search_path;
                }
            }

            d_url = '';
            if (current_url.indexOf('#') != '-1') {
                d_url = current_url.substring(current_url.indexOf('#') + 1, current_url.length);
                current_url = current_url.substring(0, current_url.indexOf('#'));
                current_url = current_url.indexOf('?') == -1 ? d_url : d_url + current_url.substring(current_url.indexOf('?'), current_url.length);
            }

            //remove existing sort name
            if (val) {
                if (current_url.indexOf(name + '=') != -1) {
                    start = current_url.indexOf(name + '=') + name.length + 1;
                    stop = current_url.indexOf('&', start);
                    stop = stop == -1 ? current_url.length : stop;

                    new_url = current_url.replace(name + '=' + current_url.substr(start, stop - start), name + '=' + val);
                }
                else {
                    glue = (current_url.indexOf('?') == -1) ? '?' : '&';
                    new_url = current_url + glue + name + "=" + val;
                }
            }
            else {
                start = current_url.indexOf(name + '=');
                //new_url = current_url;
                //if (start != -1) {
                stop = current_url.indexOf('&', start);
                stop = stop == -1 ? current_url.length : stop;
                new_url = current_url.replace(current_url.substr(start, stop - start), '');
                // }
            }

            if ((new_url.indexOf('?') + 1) == new_url.length || (new_url.lastIndexOf('&') + 1) == new_url.length) {
                new_url = new_url.substr(0, new_url.length - 1);
            }

            document.location = new_url;
        });
    }
}(jQuery));