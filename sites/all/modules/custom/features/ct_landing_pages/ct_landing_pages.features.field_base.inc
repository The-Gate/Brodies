<?php
/**
 * @file
 * ct_landing_pages.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_landing_pages_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_block_reference'.
  $field_bases['field_block_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_reference',
    'global_block_settings' => 1,
    'indexes' => array(
      'moddelta' => array(
        0 => 'moddelta',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(),
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  return $field_bases;
}
