<?php
/**
 * @file
 * ct_landing_page_with_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_landing_page_with_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_landing_page_with_paragraphs_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Landing page built of multiple content blocks that can be added, removed or reordered as required.'),
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
function ct_landing_page_with_paragraphs_paragraphs_info() {
  $items = array(
    'header_title' => array(
      'name' => 'Header Title',
      'bundle' => 'header_title',
      'locked' => '1',
    ),
    'multi_column' => array(
      'name' => 'Multi-Column',
      'bundle' => 'multi_column',
      'locked' => '1',
    ),
    'people' => array(
      'name' => 'People',
      'bundle' => 'people',
      'locked' => '1',
    ),
    'quote_slideshow' => array(
      'name' => 'Quote Slideshow',
      'bundle' => 'quote_slideshow',
      'locked' => '1',
    ),
    'text_content' => array(
      'name' => 'Text Content',
      'bundle' => 'text_content',
      'locked' => '1',
    ),
    'video_block' => array(
      'name' => 'Video Block',
      'bundle' => 'video_block',
      'locked' => '1',
    ),
  );
  return $items;
}
