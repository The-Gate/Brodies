<?php
/**
 * @file
 * events_seminars_ct_view.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function events_seminars_ct_view_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business_sectors|node|event|default';
  $field_group->group_name = 'group_business_sectors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_e_related';
  $field_group->data = array(
    'label' => 'Business Sectors',
    'weight' => '22',
    'children' => array(
      0 => 'field_related_sector',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Business Sectors',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-business-sectors field-group-div related-item',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_business_sectors|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_e_details|node|event|form';
  $field_group->group_name = 'group_e_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main details',
    'weight' => '-1',
    'children' => array(
      0 => 'field_event_audience',
      1 => 'field_event_date',
      2 => 'field_event_guest',
      3 => 'field_event_location',
      4 => 'field_event_speakers',
      5 => 'field_event_visibility',
      6 => 'field_event_full',
      7 => 'field_event_l_details',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_e_details|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_e_details|node|event|teaser';
  $field_group->group_name = 'group_e_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main details',
    'weight' => '-1',
    'children' => array(
      0 => 'field_event_audience',
      1 => 'field_event_date',
      2 => 'field_event_guest',
      3 => 'field_event_location',
      4 => 'field_event_speakers',
      5 => 'field_event_visibility',
      6 => 'field_event_full',
      7 => 'field_event_l_details',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_e_details|node|event|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_e_related|node|event|default';
  $field_group->group_name = 'group_e_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '11',
    'children' => array(
      0 => 'group_business_sectors',
      1 => 'group_legal_services',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'related-wrapper col-md-12',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_e_related|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_e_related|node|event|form';
  $field_group->group_name = 'group_e_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '0',
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
  $field_groups['group_e_related|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_e_related|node|event|teaser';
  $field_group->group_name = 'group_e_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '0',
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
  $field_groups['group_e_related|node|event|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legal_services|node|event|default';
  $field_group->group_name = 'group_legal_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_e_related';
  $field_group->data = array(
    'label' => 'Legal Services',
    'weight' => '23',
    'children' => array(
      0 => 'field_related_service',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Legal Services',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-legal-services field-group-div related-item',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_legal_services|node|event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Business Sectors');
  t('Legal Services');
  t('Main details');
  t('Related content');

  return $field_groups;
}
