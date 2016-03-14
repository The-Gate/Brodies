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
    <div id="display" >
      <?php print $display ?>
      <a name="top"></a><?php if ($title && !$is_front) : ?><div class="title"><h1><?php print $title ?></h1></div><?php endif; ?>
      <div class="bkg" style="background-image:url('/<?php print $node->field_lp_h_image[0]['filepath'] ?>')"></div>      
    </div>
    <div id="content">
      <div class="bkg" style="background-image:url('/<?php print $node->field_lp_bkg_image[0]['filepath'] ?>')"><div class="mask"></div></div>
      <div class="cont">             
      <?php print $messages ?>                     
      <?php print $content ; ?>
      </div>                
      <div class="ff"></div>                      
    </div>
    <div id="footer">    	                  
      <?php print $footer ?>      
    </div>
  </div>
  <?php print $closure ?>
  </body>
</html>
