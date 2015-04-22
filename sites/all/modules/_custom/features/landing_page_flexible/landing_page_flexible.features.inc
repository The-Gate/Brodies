<?php

/**
 * Implementation of hook_node_info().
 */
function landing_page_flexible_node_info() {
  $items = array(
    'lpagef' => array(
      'name' => t('Landing Page - Flexible'),
      'module' => 'features',
      'description' => t('Landing page with flexible bottom blocks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
