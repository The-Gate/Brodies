<?php
/**
 * @file
 * Template for displaying single location.
 */
?>
<div class="location vcard col-md-3 no-padding-left-md" itemscope itemtype="http://schema.org/PostalAddress">
    <?php if (!empty($map_link)): ?>
      <?php
      $find = array('See map: ', 'Google Maps');
      $replace = array('', 'Show on map');
      $map_link = str_replace($find, $replace, $map_link);
      ?>
      <div class="seminar-button map-link">
          <?php print $map_link; ?>
      </div>
    <?php endif; ?>
</div>
<div class="clearfix"></div>