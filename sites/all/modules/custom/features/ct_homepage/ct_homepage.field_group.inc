<?php
/**
 * @file
 * ct_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_homepage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_home_cta_block|form';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_home_cta_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_cta_l_title',
      1 => 'field_lp_cta_l_text',
      2 => 'field_highlight_colour',
      3 => 'field_lp_blk_1_colour',
      4 => 'field_lp_title_img',
      5 => 'field_lp_cta_r_title',
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
  $field_groups['group_overlay|field_collection_item|field_home_cta_block|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overlay');

  return $field_groups;
}
