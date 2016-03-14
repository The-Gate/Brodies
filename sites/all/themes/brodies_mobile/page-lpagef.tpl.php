<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
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
    <div id="page" class="lp lpf">
      <div id="container">
        <div id="landing-background" class="landing-background clearfix" style="background-image:url('/<?php print $node->field_lp_bkg_image[0]['filepath'] ?>')">
          <header id="header" class="section section-header clearfix">
            <div id="zone-header" class="zone zone-header clearfix">
              <div id="main-menu" class="clearfix"><?php print $main_menu ?></div>
              <?php print $header ?>
              <div id="logo"><?php print $header_logo ?></div>            
              <div id="stripe" class="clearfix"></div>     
              <div id="stripe-menu" class="clearfix"><?php print $stripe_menu ?></div>      
              <div id="slogan" class="clearfix"><span><?php print $header_slogan ?></span></div>
              <?php
              if ($title) {
                if (isset($node->field_lp_title_img[0]['filepath'])) {
                  print ('<h1><img src="/'.$node->field_lp_title_img[0]['filepath'].'" alt="'.$title.'"></h1>');
                }
                else {
                  print ('<h1>' . $title . '</h1>');
                }
              }
              ?>
            </div>    
          </header>     
          <section id="section-content" class="section section-content">
            <div id="content" class="zone zone-content">
              <?php if ($tabs || $tabs2) : ?><div class="controls"><ul><?php print $tabs ?> <?php print $tabs2 ?></ul></div><?php endif; ?>      
              <?php print $messages ?>
<?php print $content; ?>              
              <div class="ff">&nbsp;</div>
            </div>
          </section>
        </div>
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

<?php print $analytics ?>
  </body>
</html>
