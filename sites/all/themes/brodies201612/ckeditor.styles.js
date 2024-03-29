/*
Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [
            /* Block Styles */

            // These styles are already available in the "Format" drop-down list, so they are
            // not needed here by default. You may enable them to avoid placing the
            // "Format" drop-down list in the toolbar, maintaining the same features.
            /*
            { name : 'Paragraph'		, element : 'p' },
            { name : 'Heading 1'		, element : 'h1' },
            { name : 'Heading 2'		, element : 'h2' },
            { name : 'Heading 3'		, element : 'h3' },
            { name : 'Heading 4'		, element : 'h4' },
            { name : 'Heading 5'		, element : 'h5' },
            { name : 'Heading 6'		, element : 'h6' },
            { name : 'Preformatted Text', element : 'pre' },
            { name : 'Address'			, element : 'address' },
            */

            { name : 'Box'		, element : 'div', attributes : { 'class' : 'box' } },
            { name : 'Box Col-4'		, element : 'div', attributes : { 'class' : 'box col-md-4' } },
            { name : 'Prog Time'		, element : 'p', attributes : { 'class' : 'progTime' } },
            { name : 'Speaker Info'		, element : 'div', attributes : { 'class' : 'speakerInfo' } },
            { name : 'Highlight'		, element : 'p', attributes : { 'class' : 'highlight' } },
            { name : 'LP - View Link'		, element : 'a', attributes : { 'class' : 'view' } },
            { name : 'LP - Contact Wrapper'		, element : 'div', attributes : { 'class' : 'contact' } },
            { name : 'LP - Contact Image'		, element : 'div', attributes : { 'class' : 'contact-image' } },
            { name : 'LP - Contact Info'		, element : 'div', attributes : { 'class' : 'contact-info' } },
            { name : 'Blockquote Wrapper'		, element : 'div', attributes : { 'class' : 'blockquote-wrapper' } },
            { name : 'Info Panel Wrapper'		, element : 'div', attributes : { 'class' : 'infopanel-wrapper' } },
            { name : 'Image and Caption Wrapper'		, element : 'div', attributes : { 'class' : 'imagecaption-wrapper' } },
            { name : 'Quote Title 1'		, element : 'p', attributes : { 'class' : 'quote-title-1' } },
            { name : 'Quote Title 2'		, element : 'p', attributes : { 'class' : 'quote-title-2' } },
            { name : 'No  Column Split'		, element : 'div', attributes : { 'class' : 'no-split' } },
            
            
            { name : 'Quote Title 1 - Inline'		, element : 'span', attributes : { 'class' : 'quote-title-1' } },
            { name : 'Quote Title 2 - Inline'		, element : 'span', attributes : { 'class' : 'quote-title-2' } },
//            { name : 'Red Title'		, element : 'h3', styles : { 'color' : 'Red' } },

            /* Inline Styles */

            // These are core styles available as toolbar buttons. You may opt enabling
            // some of them in the "Styles" drop-down list, removing them from the toolbar.
            /*
            { name : 'Strong'			, element : 'strong', overrides : 'b' },
            { name : 'Emphasis'			, element : 'em'	, overrides : 'i' },
            { name : 'Underline'		, element : 'u' },
            { name : 'Strikethrough'	, element : 'strike' },
            { name : 'Subscript'		, element : 'sub' },
            { name : 'Superscript'		, element : 'sup' },
            */
/*
            { name : 'Marker: Yellow'	, element : 'span', styles : { 'background-color' : 'Yellow' } },
            { name : 'Marker: Green'	, element : 'span', styles : { 'background-color' : 'Lime' } },

            { name : 'Big'				, element : 'big' },
            { name : 'Small'			, element : 'small' },
            { name : 'Typewriter'		, element : 'tt' },

            { name : 'Computer Code'	, element : 'code' },
            { name : 'Keyboard Phrase'	, element : 'kbd' },
            { name : 'Sample Text'		, element : 'samp' },
            { name : 'Variable'			, element : 'var' },

            { name : 'Deleted Text'		, element : 'del' },
            { name : 'Inserted Text'	, element : 'ins' },

            { name : 'Cited Work'		, element : 'cite' },
            { name : 'Inline Quotation'	, element : 'q' },

            { name : 'Language: RTL'	, element : 'span', attributes : { 'dir' : 'rtl' } },
            { name : 'Language: LTR'	, element : 'span', attributes : { 'dir' : 'ltr' } },
*/
            /* Object Styles */
/*
            {
                    name : 'Image on Left',
                    element : 'img',
                    attributes :
                    {
                            'style' : 'padding: 5px; margin-right: 5px',
                            'border' : '2',
                            'align' : 'left'
                    }
            },

            {
                    name : 'Image on Right',
                    element : 'img',
                    attributes :
                    {
                            'style' : 'padding: 5px; margin-left: 5px',
                            'border' : '2',
                            'align' : 'right'
                    }
            }
            */
    ]);
}