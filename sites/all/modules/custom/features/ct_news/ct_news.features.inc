<?php
/**
 * @file
 * ct_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_news_node_info() {
  $items = array(
    'cnews' => array(
      'name' => t('News Category'),
      'base' => 'node_content',
      'description' => t('News Category'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('News content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'win' => array(
      'name' => t('Recent Win'),
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
