<?php
/**
 * @file
 * graduate_section.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function graduate_section_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_graduate_banner|form';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_graduate_banner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_cta_l_title',
      1 => 'field_cta_link',
      2 => 'field_lp_cta_l_text',
      3 => 'field_title_icon',
      4 => 'field_lp_cta_r_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overlay field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_overlay|field_collection_item|field_graduate_banner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_graduate_cta|form';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_graduate_cta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '3',
    'children' => array(
      0 => 'field_lp_cta_l_title',
      1 => 'field_lp_cta_l_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overlay field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_overlay|field_collection_item|field_graduate_cta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_graduate_slideshow|form';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_graduate_slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '3',
    'children' => array(
      0 => 'field_cta_text',
      1 => 'field_lp_cta_l_title',
      2 => 'field_lp_cta_l_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overlay field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_overlay|field_collection_item|field_graduate_slideshow|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overlay');

  return $field_groups;
}
