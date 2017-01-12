<?php
/**
 * @file
 * ct_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_news_taxonomy_default_vocabularies() {
  return array(
    'section' => array(
      'name' => 'Section',
      'machine_name' => 'section',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vocabulary_1' => array(
      'name' => 'News tags',
      'machine_name' => 'vocabulary_1',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
