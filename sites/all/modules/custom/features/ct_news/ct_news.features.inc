<?php
/**
 * @file
 * ct_news.features.inc
 */

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
  );
  drupal_alter('node_info', $items);
  return $items;
}
