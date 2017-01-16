<?php
/**
 * @file
 * ct_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact|node|cnews|default';
  $field_group->group_name = 'group_person_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cnews';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related_content';
  $field_group->data = array(
    'label' => 'Key Contacts',
    'weight' => '5',
    'children' => array(
      0 => 'field_related_people',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-person-contact field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_person_contact|node|cnews|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|cnews|default';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cnews';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'related content',
    'weight' => '3',
    'children' => array(
      0 => 'group_person_contact',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_content|node|cnews|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|win|default';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'win';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'related content',
    'weight' => '2',
    'children' => array(
      0 => 'group_related_secotrs',
      1 => 'group_related_services',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_content|node|win|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_secotrs|node|win|default';
  $field_group->group_name = 'group_related_secotrs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'win';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related_content';
  $field_group->data = array(
    'label' => 'Related Sectors',
    'weight' => '6',
    'children' => array(
      0 => 'field_related_sector',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-secotrs field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_secotrs|node|win|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_services|node|win|default';
  $field_group->group_name = 'group_related_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'win';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related_content';
  $field_group->data = array(
    'label' => 'Related Services',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_service',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-services field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_services|node|win|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Key Contacts');
  t('Related Sectors');
  t('Related Services');
  t('related content');

  return $field_groups;
}