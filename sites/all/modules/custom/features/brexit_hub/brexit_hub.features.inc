<?php
/**
 * @file
 * brexit_hub.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function brexit_hub_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function brexit_hub_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function brexit_hub_node_info() {
  $items = array(
    'brexit_hub' => array(
      'name' => t('Brexit Hub'),
      'base' => 'node_content',
      'description' => t('Template for the Brexit Hub'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed_import' => array(
      'name' => t('Feed Import'),
      'base' => 'node_content',
      'description' => t('node data for an XML import item'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function brexit_hub_paragraphs_info() {
  $items = array(
    'block_content' => array(
      'name' => 'Block Content',
      'bundle' => 'block_content',
      'locked' => '1',
    ),
  );
  return $items;
}
