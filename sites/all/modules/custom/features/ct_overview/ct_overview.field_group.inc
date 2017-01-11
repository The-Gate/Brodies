<?php
/**
 * @file
 * ct_overview.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_overview_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_over_feat|node|overview|default';
  $field_group->group_name = 'group_over_feat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'overview';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured content',
    'weight' => '1',
    'children' => array(
      0 => 'field_over_news',
      1 => 'field_over_vop',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Featured content',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_over_feat|node|overview|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_over_feat|node|overview|form';
  $field_group->group_name = 'group_over_feat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'overview';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured content',
    'weight' => '-3',
    'children' => array(
      0 => 'field_over_news',
      1 => 'field_over_vop',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_over_feat|node|overview|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_over_feat|node|overview|teaser';
  $field_group->group_name = 'group_over_feat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'overview';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured content',
    'weight' => '-3',
    'children' => array(
      0 => 'field_over_news',
      1 => 'field_over_vop',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_over_feat|node|overview|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured content');

  return $field_groups;
}
