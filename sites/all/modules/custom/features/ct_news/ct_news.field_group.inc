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
      'label' => 'Key Contacts',
      'instance_settings' => array(
        'classes' => 'group-person-contact field-group-accordion-item',
      ),
      'formatter' => 'open',
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
      'label' => 'related content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related-content field-group-accordion group-related-people',
        'description' => '',
        'effect' => 'bounceslide',
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
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'related content',
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
    'label' => 'Business sectors',
    'weight' => '6',
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
    'label' => 'Legal services',
    'weight' => '7',
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
  $field_groups['group_related_services|node|win|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Business sectors');
  t('Key Contacts');
  t('Legal services');
  t('related content');

  return $field_groups;
}
