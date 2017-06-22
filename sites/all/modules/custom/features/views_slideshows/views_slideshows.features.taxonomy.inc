<?php
/**
 * @file
 * views_slideshows.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function views_slideshows_taxonomy_default_vocabularies() {
  return array(
    'slideshow_type' => array(
      'name' => 'Slideshow type',
      'machine_name' => 'slideshow_type',
      'description' => 'which slideshow this should show on',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
