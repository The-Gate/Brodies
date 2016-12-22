<?php
/**
 * @file
 * ct_binformed_section.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_binformed_section_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_date'.
  $field_bases['field_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'granularity' => array(
        'day' => 'day',
        'month' => 'month',
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
    'type_name' => 'publication',
  );

  // Exported field_base: 'field_old_path'.
  $field_bases['field_old_path'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_old_path',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'service',
  );

  // Exported field_base: 'field_related_people'.
  $field_bases['field_related_people'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_related_people',
    'global_block_settings' => 2,
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'application' => 0,
        'asub' => 0,
        'call_to_action' => 0,
        'career' => 0,
        'cnews' => 0,
        'cs' => 0,
        'download' => 0,
        'event' => 0,
        'hidden' => 0,
        'larea' => 0,
        'location' => 0,
        'lpage' => 0,
        'lpage2' => 0,
        'lpagef' => 0,
        'lupdate' => 0,
        'microsite_page' => 0,
        'microsite_wrapper' => 0,
        'news' => 0,
        'overview' => 0,
        'page' => 0,
        'parea' => 0,
        'payment' => 0,
        'people' => 'people',
        'publication' => 0,
        'sector' => 0,
        'service' => 0,
        'slide' => 0,
        'video' => 0,
        'webform' => 0,
        'win' => 0,
      ),
      'view' => array(
        'args' => array(
          0 => '',
        ),
        'display_name' => 'default',
        'view_name' => '--',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'service',
  );

  return $field_bases;
}
