<?php
/**
 * @file
 * ct_binformed_section.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_binformed_section_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_file|node|download|default';
  $field_group->group_name = 'group_d_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'download';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File',
    'weight' => '-1',
    'children' => array(
      0 => 'field_d_file',
      1 => 'field_d_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_d_file|node|download|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_file|node|download|form';
  $field_group->group_name = 'group_d_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'download';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File',
    'weight' => '-1',
    'children' => array(
      0 => 'field_d_file',
      1 => 'field_d_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_d_file|node|download|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_file|node|download|teaser';
  $field_group->group_name = 'group_d_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'download';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_d_file|node|download|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('File');

  return $field_groups;
}
