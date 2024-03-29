<?php
/**
 * @file
 * ct_case_studies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_case_studies_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cs_related|node|cs|default';
  $field_group->group_name = 'group_cs_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cs';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '2',
    'children' => array(
      0 => 'group_related_secotrs',
      1 => 'group_related_services',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'related-wrapper col-md-12',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_cs_related|node|cs|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cs_related|node|cs|form';
  $field_group->group_name = 'group_cs_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cs';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '-2',
    'children' => array(
      0 => 'field_related_sector',
      1 => 'field_related_service',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_cs_related|node|cs|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cs_related|node|cs|teaser';
  $field_group->group_name = 'group_cs_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cs';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '-2',
    'children' => array(
      0 => 'field_related_sector',
      1 => 'field_related_service',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_cs_related|node|cs|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_secotrs|node|cs|default';
  $field_group->group_name = 'group_related_secotrs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cs';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_cs_related';
  $field_group->data = array(
    'label' => 'Business sectors',
    'weight' => '11',
    'children' => array(
      0 => 'field_related_sector',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Business sectors',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'related-item',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related_secotrs|node|cs|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_services|node|cs|default';
  $field_group->group_name = 'group_related_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cs';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_cs_related';
  $field_group->data = array(
    'label' => 'Legal services',
    'weight' => '12',
    'children' => array(
      0 => 'field_related_service',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Legal services',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'related-item',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related_services|node|cs|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Business sectors');
  t('Legal services');
  t('Related content');

  return $field_groups;
}
