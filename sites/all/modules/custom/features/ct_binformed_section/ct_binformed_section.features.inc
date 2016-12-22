<?php
/**
 * @file
 * ct_binformed_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_binformed_section_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_binformed_section_node_info() {
  $items = array(
    'download' => array(
      'name' => t('Guide or download'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'larea' => array(
      'name' => t('Legal Update Area'),
      'base' => 'node_content',
      'description' => t('Legal Update Area'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lupdate' => array(
      'name' => t('Legal Update'),
      'base' => 'node_content',
      'description' => t('Legal Update Content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'parea' => array(
      'name' => t('Publication Area'),
      'base' => 'node_content',
      'description' => t('Publication Area'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'publication' => array(
      'name' => t('Publication Archive'),
      'base' => 'node_content',
      'description' => t('Publication Archive'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
