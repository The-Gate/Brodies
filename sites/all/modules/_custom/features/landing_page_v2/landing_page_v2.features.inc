<?php

/**
 * Implementation of hook_node_info().
 */
function landing_page_v2_node_info() {
  $items = array(
    'lpage2' => array(
      'name' => t('Landing page v2'),
      'module' => 'features',
      'description' => t('Landing page variation 2'),
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
