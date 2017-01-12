<?php
/**
 * @file
 * ct_case_studies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_case_studies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_case_studies_node_info() {
  $items = array(
    'cs' => array(
      'name' => t('Case study'),
      'base' => 'node_content',
      'description' => t('Case study content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
