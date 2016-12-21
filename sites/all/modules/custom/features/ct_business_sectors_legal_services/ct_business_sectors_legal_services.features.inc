<?php
/**
 * @file
 * ct_business_sectors_legal_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_business_sectors_legal_services_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_business_sectors_legal_services_node_info() {
  $items = array(
    'sector' => array(
      'name' => t('Business Sector'),
      'base' => 'node_content',
      'description' => t('Business Sector content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service' => array(
      'name' => t('Legal Service'),
      'base' => 'node_content',
      'description' => t('Legal service content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
