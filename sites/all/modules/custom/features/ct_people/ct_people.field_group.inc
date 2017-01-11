<?php
/**
 * @file
 * ct_people.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_people_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business_sectors|node|people|default';
  $field_group->group_name = 'group_business_sectors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_p_related';
  $field_group->data = array(
    'label' => 'Business Sectors',
    'weight' => '9',
    'children' => array(
      0 => 'field_related_sector',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-business-sectors field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_business_sectors|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legal_services|node|people|default';
  $field_group->group_name = 'group_legal_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_p_related';
  $field_group->data = array(
    'label' => 'Legal Services',
    'weight' => '10',
    'children' => array(
      0 => 'field_related_service',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-legal-services field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_legal_services|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_main|node|people|default';
  $field_group->group_name = 'group_p_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main details',
    'weight' => '9',
    'children' => array(
      0 => 'field_people_fname',
      1 => 'field_people_id',
      2 => 'field_people_partner',
      3 => 'field_people_section',
      4 => 'field_people_sname',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_main|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_main|node|people|form';
  $field_group->group_name = 'group_p_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main details',
    'weight' => '-3',
    'children' => array(
      0 => 'field_people_email',
      1 => 'field_people_fname',
      2 => 'field_people_id',
      3 => 'field_people_job',
      4 => 'field_people_location',
      5 => 'field_people_partner',
      6 => 'field_people_phone',
      7 => 'field_people_section',
      8 => 'field_people_sname',
      9 => 'field_people_vcard',
      10 => 'field_teaser_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_main|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_main|node|people|teaser';
  $field_group->group_name = 'group_p_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main details',
    'weight' => '1',
    'children' => array(
      0 => 'field_people_email',
      1 => 'field_people_fname',
      2 => 'field_people_job',
      3 => 'field_people_location',
      4 => 'field_people_phone',
      5 => 'field_people_sname',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => '',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_p_main|node|people|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_related|node|people|default';
  $field_group->group_name = 'group_p_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '7',
    'children' => array(
      0 => 'group_business_sectors',
      1 => 'group_legal_services',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_p_related|node|people|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_related|node|people|form';
  $field_group->group_name = 'group_p_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '0',
    'children' => array(
      0 => 'field_related_sector',
      1 => 'field_related_service',
      2 => 'field_relation_exclude',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_related|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_related|node|people|teaser';
  $field_group->group_name = 'group_p_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_sector',
      1 => 'field_related_service',
      2 => 'field_relation_exclude',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_related|node|people|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Business Sectors');
  t('Legal Services');
  t('Main details');
  t('Related content');

  return $field_groups;
}