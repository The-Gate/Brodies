<?php
/**
 * @file
 * ct_landing_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_landing_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_landing_pages_node_info() {
  $items = array(
    'lpage' => array(
      'name' => t('Landing page'),
      'base' => 'node_content',
      'description' => t('Landing page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lpage2' => array(
      'name' => t('Landing page v2'),
      'base' => 'node_content',
      'description' => t('Landing page variation 2'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lpagef' => array(
      'name' => t('Landing Page - Flexible'),
      'base' => 'node_content',
      'description' => t('Landing page WITH flexible bottom blocks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
