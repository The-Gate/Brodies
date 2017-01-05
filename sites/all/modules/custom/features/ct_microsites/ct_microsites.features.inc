<?php
/**
 * @file
 * ct_microsites.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ct_microsites_node_info() {
  $items = array(
    'microsite_page' => array(
      'name' => t('Microsite Page'),
      'base' => 'node_content',
      'description' => t('Microsite Page content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'microsite_wrapper' => array(
      'name' => t('Microsite Wrapper'),
      'base' => 'node_content',
      'description' => t('The miscrosite content FOR ALL the miscrosite pages. FOR EXAMPLE the banner image.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
