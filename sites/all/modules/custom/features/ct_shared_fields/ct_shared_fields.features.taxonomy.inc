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
    'vacancy_location' => array(
      'name' => 'Vacancy Location',
      'machine_name' => 'vacancy_location',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vacancy_practice' => array(
      'name' => 'Vacancy Practice',
      'machine_name' => 'vacancy_practice',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vacancy_role' => array(
      'name' => 'Vacancy Role',
      'machine_name' => 'vacancy_role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vacancy_type' => array(
      'name' => 'Vacancy Type',
      'machine_name' => 'vacancy_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
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
