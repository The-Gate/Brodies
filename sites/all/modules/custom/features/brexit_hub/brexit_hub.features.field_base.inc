<?php
/**
 * @file
 * brexit_hub.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function brexit_hub_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_unique_ref'.
  $field_bases['field_unique_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unique_ref',
    'global_block_settings' => 1,
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
