<?php
/**
 * @file
 * ct_overview.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_overview_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_overview_node_info() {
  $items = array(
    'overview' => array(
      'name' => t('Overview page'),
      'base' => 'node_content',
      'description' => t('Overview page - gathering content from specific category (sector, service)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
