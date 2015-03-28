<?php

/**
 * Implementation of hook_node_info().
 */
function microsites_node_info() {
  $items = array(
    'microsite_page' => array(
      'name' => t('Microsite Page'),
      'module' => 'features',
      'description' => t('Microsite Page content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'microsite_wrapper' => array(
      'name' => t('Microsite Wrapper'),
      'module' => 'features',
      'description' => t('The miscrosite content for all the miscrosite pages. For example the banner image.'),
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
