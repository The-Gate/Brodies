<?php
/**
 * @file
 * graduate_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function graduate_section_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function graduate_section_node_info() {
  $items = array(
    'graduate_content' => array(
      'name' => t('Graduate Content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'graduate_homepage' => array(
      'name' => t('Graduate Homepage'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
