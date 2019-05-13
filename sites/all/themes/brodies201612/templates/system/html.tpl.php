<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
    "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

    <head profile="<?php print $grddl_profile; ?>">
      <!-- Google Tag Manager -->
      <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
            new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
          j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
          'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
        })(window,document,'script','dataLayer','GTM-53WJ2RT');</script>
      <!-- End Google Tag Manager -->
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <?php print $head; ?>
        <title><?php print $head_title; ?></title>
        <?php print $styles; ?>
        <?php print $scripts; ?>
        <meta name="google-site-verification" content="QSV_lzQJ0VNBkE5Cd_oGD0wfrY5lZqSPmZ9RPDAOs68" />
    </head>
    <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <!-- Google Tag Manager (noscript) -->
    <noscript><iframe src="https://www.googletagmanager.com/ns.html?id=GTM-53WJ2RT"
                      height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
    <!-- End Google Tag Manager (noscript) -->
        <div id="skip-link">
            <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
        </div>
        <?php print $page_top; ?>
        <?php print $page; ?>
        <?php print $page_bottom; ?>

<script>
var serviceUrl = "//api.reciteme.com/asset/js?key=";
var serviceKey = "94b40d4b92bd04e0cbe0dcb5426fa6a3f697b34d";
var options = {}; // Options can be added as needed
var autoLoad = false;
var enableFragment = "#reciteEnable";
var loaded=[],frag=!1;window.location.hash===enableFragment&&(frag=!0);function loadScript(c,b){var a=document.createElement("script");a.type="text/javascript";a.readyState?a.onreadystatechange=function(){if("loaded"==a.readyState||"complete"==a.readyState)a.onreadystatechange=null,void 0!=b&&b()}:void 0!=b&&(a.onload=function(){b()});a.src=c;document.getElementsByTagName("head")[0].appendChild(a)}function _rc(c){c+="=";for(var b=document.cookie.split(";"),a=0;a<b.length;a++){for(var d=b[a];" "==d.charAt(0);)d=d.substring(1,d.length);if(0==d.indexOf(c))return d.substring(c.length,d.length)}return null}function loadService(c){for(var b=serviceUrl+serviceKey,a=0;a<loaded.length;a++)if(loaded[a]==b)return;loaded.push(b);loadScript(serviceUrl+serviceKey,function(){"function"===typeof _reciteLoaded&&_reciteLoaded();"function"==typeof c&&c();Recite.load(options);Recite.Event.subscribe("Recite:load",function(){Recite.enable()})})}"true"==_rc("Recite.Persist")&&loadService();(autoLoad&&"false"!=_rc("Recite.Persist")||frag)&&loadService();

jQuery("#reciteme").click(function(i,e){
loadService();
return false;
});
</script>
    </body>
</html>
