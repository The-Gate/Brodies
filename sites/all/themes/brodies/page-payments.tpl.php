<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>    
    <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/payments.css?k" />
    <!--[if IE 7]>
      <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/ie-fix.css" />
      <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/brodies/ie-fix-2.css" />
    <![endif]-->
  </head>
  <body>
  <div id="container" class="content-payments">
    <div id="header">
      <div id="logo"><?php print $header_logo ?></div>
      <div id="back"><a href="/">Main site</a></div>      
      <div id="stripe-menu"><h1><a href="/payments">PAYMENT GATEWAY</a></h1></div>      
      <div id="slogan"><span><?php print $header_slogan ?></span></div>
    </div>    
    <div id="content" class="ccont">            
      <?php print $messages ?>      
      <?php print $middle; ?>
      <?php print $content; ?>            
      <div class="ff">&nbsp;</div>
    </div>    
    <?php print (arg(1)?'<div id="cards"></div>':''); ?>
    <div id="footer">  
	  <div class="ccont">
		  <div class="left"><?php print $footer_left ?></div>      
		  <div class="right"><?php print $footer_right ?></div> 
		  <div class="ff">&nbsp;</div>     
		  <?php print $footer ?>       
	  </div>
    </div>
  </div>
  <?php print $closure ?>
  </body>
</html>
