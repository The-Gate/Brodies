<?php
/**
 * @file
 * events_seminars_ct_view.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function events_seminars_ct_view_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function events_seminars_ct_view_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function events_seminars_ct_view_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event or Seminar'),
      'base' => 'node_content',
      'description' => t('Event / Seminar content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
