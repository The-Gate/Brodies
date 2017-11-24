<?php
/**
 * @file
 * ct_landing_page_with_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_landing_page_with_paragraphs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner|node|landing_page|form';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero Banner',
    'weight' => '2',
    'children' => array(
      0 => 'field_banner_image',
      1 => 'field_cta_link',
      2 => 'field_lp_cta_l_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-banner field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_banner|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottom_block|node|landing_page|form';
  $field_group->group_name = 'group_bottom_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom Block',
    'weight' => '4',
    'children' => array(
      0 => 'field_block_reference',
      1 => 'field_l_left',
      2 => 'field_lp_blk_1_colour',
      3 => 'field_title_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bottom-block field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_bottom_block|node|landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom Block');
  t('Hero Banner');

  return $field_groups;
}
