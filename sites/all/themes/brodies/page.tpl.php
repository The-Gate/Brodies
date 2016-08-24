<?php
$ntype = $node->type;
// set up some CSS classes
$css_page_id = (isset($node->nid)) ? ' page-id-' . $node->nid : '';
$css_page_section_by_path = '';
if (isset($node->path)) {
  $pathway = explode('/', $node->path);
  foreach ($pathway as $path) {
    $css_page_section_by_path .= ' section-' . $path;
  }
}
$content_in_display = (($node->type == 'overview') && (!($node->nid == 53)) && $content && !$is_front && (arg(2) != 'edit'));
if ($node->type == 'page') { //service subpage test
  if ($parent_path = db_result(db_query("SELECT link_path FROM menu_links where mlid = (SELECT plid FROM `menu_links` where link_path = 'node/%d' and menu_name = 'menu-sector' and depth = 3)", $node->nid))) {
    $pnid = substr($parent_path, strpos($parent_path, '/') + 1);
    if ($pnid) {
      $pnode = node_load($pnid);
      if ($pnode->type == 'service') {
        include(drupal_get_path('module', 'br') . '/br.pages.inc');
        $display_content = br_sector_page($pnode);
        $ntype = 'service';
      }
    }
  }
}

$node_bg_class = '';
$node_bg_image = '';
if ($node->type == 'sector' or $node->type == 'service') {
  if (!empty($node->field_lp_bkg_image[0]['filepath'])) {
    $node_bg_container_class = ' page-bg-container ';
    $node_bg_class = ' page-bg ';
    $node_bg_image = ' style="background:url(\'/' . $node->field_lp_bkg_image[0]['filepath'] . '\');"';
  }
}
?><!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
    <head>
<?php print $head ?>
        <meta name="robots" content="NOODP">
        <title><?php print $head_title ?></title>
        <?php print $styles ?>
        <?php print $scripts ?>    
        <!--[if lte IE 8]>
        <script src="/sites/all/themes/brodies/html5shiv.js"></script>
          <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/ie-fix.css" />
          <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/ie-fix-2.css" />
        <![endif]--> 
        <!--[if lte IE 7]>
          <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/ie7.css" />
        <![endif]-->
        <!--[if gte IE 9]>
      <style type="text/css">
        .gradient {
           filter: none;
        }
      </style>
    <![endif]-->
    </head>
    <body>
        <div id="page">
            <div id="container" <?php print ($node ? 'class="content-' . $ntype . $css_page_id . $css_page_section_by_path . $node_bg_container_class . ($is_front ? ' front' : '') . '"' : ''); ?>>
                <header id="header" class="section section-header clearfix">
<?php
if (isset($headerBackground)) {
  print('<div id="zone-header-background" class=" zone-header-background clearfix">' . $headerBackground . '</div>');
}
?>
                    <div id="zone-header" class="zone zone-header clearfix">
                        <div id="main-menu" class="clearfix"><?php print $main_menu ?></div>
<?php print $header ?>
                        <div id="logo"><?php print $header_logo ?></div>
                        <div id="display" <?php print ($content_in_display || $display_content ? 'class="on"' : '') ?>><div class="cont"><?php
                        print ($content_in_display ? $content : '');
                        print $display_content;
?></div></div>
                        <div id="stripe" class="clearfix"></div>     
                        <div id="stripe-menu" class="clearfix"><?php print $stripe_menu ?></div>      
                        <div id="slogan" class="clearfix"><span><?php print $header_slogan ?></span></div>
                    </div>    
                </header>     
                <section id="section-content" class="section section-content<?php echo $node_bg_class ; ?>" <?php echo $node_bg_image; ?>>
                         <div id="content" class="zone zone-content">
                         <?php if ($tabs || $tabs2) : ?><div class="controls"><ul><?php print $tabs ?> <?php print $tabs2 ?></ul></div><?php endif; ?>      
                         <?php print $messages ?>
                         <?php if ($left) : ?><div class="left"><?php print $left ?></div><?php endif; ?> 
                    <div class="middle<?php
                    if (($left and ! $right) or ( (!$left and $right))) {
                      echo ' wide';
                    }
                    elseif ((!$left and ! $right)) {
                      echo ' full';
                    }
                    ?>">
                    <?php if ($title && !$is_front && (!($node->type == 'overview') or $node->nid == 53)) : ?><h1><?php print $title ?></h1><div class="title-icon"><?php
                           if ($node->type == 'sector' or $node->type == 'service') {
                             if (!empty($node->field_title_icon[0]['view'])) {
                               print ($node->field_title_icon[0]['view']);
                             }
                             else {
                               $field = content_fields('field_title_icon', $node->type);
                               print(theme('image', $field['widget']['default_image']['filepath']));
                             }
                           }
                           ?></div><?php endif; ?>
                        <?php print ($content_in_display ? '' : $content); ?>
                            <?php print $middle; ?>
                    </div>
                        <?php if ($right) : ?><div class="right"><?php print $right ?></div><?php endif; ?> 
                    <div class="ff">&nbsp;</div>
            </div>
            </section>

<?php if (($postscript_left) or ( $postscript_right)) { ?>
              <section id="section-postscript" class="section section-postscript">
                  <div id="postscript" class="zone zone-postscript">
  <?php if ($postscript_left) { ?>
                        <div id="postscript-left" class="zone zone-postscript-left"><?php print $postscript_left; ?></div>
                      <?php } ?> 
                      <?php if ($postscript_right) { ?>
                        <div id="postscript-right" class="zone zone-postscript-right"><?php print $postscript_right; ?></div>
                      <?php } ?> 
                  </div>
          </div>
          </section>
<?php } ?> 

        <footer id="section-footer" class="section section-footer">
            <div id="footer" class="zone zone-footer">    	
                <div class="left"><?php print $footer_left ?></div>      
                <div class="right"><?php print $footer_right ?></div> 
                <div class="ff">&nbsp;</div>     
<?php print $footer ?>       
            </div>
        </footer>
        </div>
<?php print $closure ?>
        </div>

        </div>    
        <script>
          (function (i, s, o, g, r, a, m) {
              i['GoogleAnalyticsObject'] = r;
              i[r] = i[r] || function () {
                  (i[r].q = i[r].q || []).push(arguments)
              }, i[r].l = 1 * new Date();
              a = s.createElement(o),
                      m = s.getElementsByTagName(o)[0];
              a.async = 1;
              a.src = g;
              m.parentNode.insertBefore(a, m)
          })(window, document, 'script', '//www.google-analytics.com/analytics.js', 'ga');

          ga('create', 'UA-2774438-9', 'brodies.co.uk');
          ga('send', 'pageview');

        </script>
    </body>
</html>
