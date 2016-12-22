<?php
/**
 * @file
 * ct_news.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_news_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_news_category'.
  $field_bases['field_news_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_category',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'career' => 0,
        'cnews' => 'cnews',
        'cs' => 0,
        'event' => 0,
        'location' => 0,
        'news' => 0,
        'overview' => 0,
        'page' => 0,
        'people' => 0,
        'sector' => 0,
        'service' => 0,
        'slide' => 0,
        'story' => 0,
        'video' => 0,
      ),
      'view' => array(
        'args' => array(
          0 => '',
        ),
        'display_name' => 'default',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'news',
  );

  // Exported field_base: 'field_teaser_image'.
  $field_bases['field_teaser_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_teaser_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'video',
  );

  // Exported field_base: 'taxonomy_vocabulary_1'.
  $field_bases['taxonomy_vocabulary_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'taxonomy_vocabulary_1',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'vocabulary_1',
          'parent' => 0,
        ),
      ),
      'required' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
