<?php
/**
 * @file
 * ct_business_sectors_legal_services.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_business_sectors_legal_services_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_title_icon'.
  $field_bases['field_title_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_title_icon',
    'global_block_settings' => 1,
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
