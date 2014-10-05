<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>        
  </head>
  <body>  
  <div id="container" class="<?php print ($node?'content-'. $node->type .($is_front?' front':''):'') ; ?> section-<?php print $section; ?>">
    <div id="header">      
      <div id="main-menu"><?php print $mobile_top_menu ?></div>
      <?php print $header ?>                              
    </div>    
    <div id="display">
      <?php print $display ?>
      <img src="/sites/all/themes/brodies_mobile/gfx/banner.jpg" alt="Brodies"/>      
    </div>
    <div id="content">            
      <?php print $messages ?>               
      <a name="top"></a><?php if ($title && !$is_front) : ?><div class="title"><h1><?php print $title ?></h1></div><?php endif; ?>
      <?php print $content ; ?>                
      <div class="ff"></div>                      
    </div>
    <div id="footer">    	                  
      <?php print $footer ?>      
    </div>
  </div>
  <?php print $closure ?>
  </body>
</html>
