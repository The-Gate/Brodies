<?php
/**
 * @file
 * ct_landing_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_landing_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottom_columns|node|lpagef|form';
  $field_group->group_name = 'group_bottom_columns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpagef';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom Columns',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_blk_1',
      1 => 'field_lp_blk_1_colour',
      2 => 'field_lp_blk_2',
      3 => 'field_lp_blk_2_colour',
      4 => 'field_lp_blk_3',
      5 => 'field_lp_blk_3_colour',
      6 => 'field_lp_blk_4',
      7 => 'field_lp_blk_4_colour',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bottom-columns field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_bottom_columns|node|lpagef|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_3rd|node|lpage|default';
  $field_group->group_name = 'group_lp_3rd';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3rd list',
    'weight' => '2',
    'children' => array(
      0 => 'field_lp_3rd_content',
      1 => 'field_lp_3rd_more',
      2 => 'field_lp_3rd_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_3rd|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_3rd|node|lpage|form';
  $field_group->group_name = 'group_lp_3rd';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3rd list',
    'weight' => '2',
    'children' => array(
      0 => 'field_lp_3rd_content',
      1 => 'field_lp_3rd_more',
      2 => 'field_lp_3rd_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_3rd|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_3rd|node|lpage|teaser';
  $field_group->group_name = 'group_lp_3rd';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3rd list',
    'weight' => '2',
    'children' => array(
      0 => 'field_lp_3rd_content',
      1 => 'field_lp_3rd_more',
      2 => 'field_lp_3rd_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_3rd|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_left|node|lpage|default';
  $field_group->group_name = 'group_lp_c_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact left',
    'weight' => '3',
    'children' => array(
      0 => 'field_lp_contact_l_img',
      1 => 'field_lp_contact_l_name',
      2 => 'field_lp_contact_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_left|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_left|node|lpage|form';
  $field_group->group_name = 'group_lp_c_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact left',
    'weight' => '3',
    'children' => array(
      0 => 'field_lp_contact_l_img',
      1 => 'field_lp_contact_l_name',
      2 => 'field_lp_contact_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_left|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_left|node|lpage|teaser';
  $field_group->group_name = 'group_lp_c_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact left',
    'weight' => '3',
    'children' => array(
      0 => 'field_lp_contact_l_img',
      1 => 'field_lp_contact_l_name',
      2 => 'field_lp_contact_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_left|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_right|node|lpage|default';
  $field_group->group_name = 'group_lp_c_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact right',
    'weight' => '4',
    'children' => array(
      0 => 'field_lp_contact_r_img',
      1 => 'field_lp_contact_r_name',
      2 => 'field_lp_contact_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_right|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_right|node|lpage|form';
  $field_group->group_name = 'group_lp_c_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact right',
    'weight' => '4',
    'children' => array(
      0 => 'field_lp_contact_r_img',
      1 => 'field_lp_contact_r_name',
      2 => 'field_lp_contact_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_right|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_c_right|node|lpage|teaser';
  $field_group->group_name = 'group_lp_c_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact right',
    'weight' => '4',
    'children' => array(
      0 => 'field_lp_contact_r_img',
      1 => 'field_lp_contact_r_name',
      2 => 'field_lp_contact_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_c_right|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_l|node|lpage|default';
  $field_group->group_name = 'group_lp_cta_l';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Bottom CTA',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_cta_l_image',
      1 => 'field_lp_cta_l_text',
      2 => 'field_lp_cta_l_title',
      3 => 'field_lp_cta_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_l|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_l|node|lpage|form';
  $field_group->group_name = 'group_lp_cta_l';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Bottom CTA',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_cta_l_image',
      1 => 'field_lp_cta_l_text',
      2 => 'field_lp_cta_l_title',
      3 => 'field_lp_cta_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_l|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_l|node|lpage|teaser';
  $field_group->group_name = 'group_lp_cta_l';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Bottom CTA',
    'weight' => '5',
    'children' => array(
      0 => 'field_lp_cta_l_image',
      1 => 'field_lp_cta_l_text',
      2 => 'field_lp_cta_l_title',
      3 => 'field_lp_cta_l_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_l|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_r|node|lpage|default';
  $field_group->group_name = 'group_lp_cta_r';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Bottom CTA',
    'weight' => '6',
    'children' => array(
      0 => 'field_lp_cta_r_image',
      1 => 'field_lp_cta_r_text',
      2 => 'field_lp_cta_r_title',
      3 => 'field_lp_cta_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_r|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_r|node|lpage|form';
  $field_group->group_name = 'group_lp_cta_r';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Bottom CTA',
    'weight' => '6',
    'children' => array(
      0 => 'field_lp_cta_r_image',
      1 => 'field_lp_cta_r_text',
      2 => 'field_lp_cta_r_title',
      3 => 'field_lp_cta_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_r|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_cta_r|node|lpage|teaser';
  $field_group->group_name = 'group_lp_cta_r';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Bottom CTA',
    'weight' => '6',
    'children' => array(
      0 => 'field_lp_cta_r_image',
      1 => 'field_lp_cta_r_text',
      2 => 'field_lp_cta_r_title',
      3 => 'field_lp_cta_r_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_cta_r|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_header|node|lpage|default';
  $field_group->group_name = 'group_lp_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '-1',
    'children' => array(
      0 => 'field_lp_h_image',
      1 => 'field_lp_h_style',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_header|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_header|node|lpage|form';
  $field_group->group_name = 'group_lp_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '-1',
    'children' => array(
      0 => 'field_lp_h_image',
      1 => 'field_lp_h_style',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_header|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_header|node|lpage|teaser';
  $field_group->group_name = 'group_lp_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '-1',
    'children' => array(
      0 => 'field_lp_h_image',
      1 => 'field_lp_h_style',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_header|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_under|node|lpage|default';
  $field_group->group_name = 'group_lp_under';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Under content',
    'weight' => '1',
    'children' => array(
      0 => 'field_lp_blog',
      1 => 'field_lp_blog_more',
      2 => 'field_lp_news',
      3 => 'field_lp_new_more',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_under|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_under|node|lpage|form';
  $field_group->group_name = 'group_lp_under';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Under content',
    'weight' => '1',
    'children' => array(
      0 => 'field_lp_blog',
      1 => 'field_lp_blog_more',
      2 => 'field_lp_news',
      3 => 'field_lp_new_more',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_under|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_under|node|lpage|teaser';
  $field_group->group_name = 'group_lp_under';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Under content',
    'weight' => '1',
    'children' => array(
      0 => 'field_lp_blog',
      1 => 'field_lp_blog_more',
      2 => 'field_lp_news',
      3 => 'field_lp_new_more',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_under|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_video|node|lpage|default';
  $field_group->group_name = 'group_lp_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '0',
    'children' => array(
      0 => 'field_lp_v_image',
      1 => 'field_lp_v_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_video|node|lpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_video|node|lpage|form';
  $field_group->group_name = 'group_lp_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '0',
    'children' => array(
      0 => 'field_lp_v_image',
      1 => 'field_lp_v_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_video|node|lpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lp_video|node|lpage|teaser';
  $field_group->group_name = 'group_lp_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpage';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '0',
    'children' => array(
      0 => 'field_lp_v_image',
      1 => 'field_lp_v_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_lp_video|node|lpage|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|lpagef|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lpagef';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '4',
    'children' => array(
      0 => 'field_lp_v_image',
      1 => 'field_lp_v_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_video|node|lpagef|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('3rd list');
  t('Bottom Columns');
  t('Contact left');
  t('Contact right');
  t('Header');
  t('Left Bottom CTA');
  t('Right Bottom CTA');
  t('Under content');
  t('Video');

  return $field_groups;
}
