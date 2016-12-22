<?php
/**
 * @file
 * ct_shared_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_shared_fields_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_2' => array(
      'name' => 'CTA Display sections',
      'machine_name' => 'vocabulary_2',
      'description' => 'Call to action block - which section to show them in.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vocabulary_3' => array(
      'name' => 'Downloads categories',
      'machine_name' => 'vocabulary_3',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
