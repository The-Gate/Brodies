<?php
/**
 * @file
 * Fallback-Template for HTML Mail messages.
 */
$css_file = realpath(drupal_get_path('theme', 'brodies201612')) . '/css/mail.css';
if (!empty($css_file) && file_exists($css_file)) {
  $css = file_get_contents($css_file);
}
?>

<html>
    <head>
        <style type="text/css">
            <!--
            <?php print $css ?>
            -->
        </style>
    </head>
    <body>
        <div class="htmlmail-body">
            <?php 
            $find_tags = array('fieldset','label','for=','<span class="field-prefix"></span>','<span class="field-suffix"></span>','<legend>','</legend>');
            $replace_tags = array('div','b','class=','','','<div class="legend">','</div>');
            $body=preg_replace('/class=".*?"/', '', $body);
            echo str_replace($find_tags, $replace_tags, $body);
            //echo $body;
            ?>
        </div>
    </body>
</html>
