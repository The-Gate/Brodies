<?php
/**
 * @file
 * ct_landing_pages.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ct_landing_pages_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-lpage-body'.
  $field_instances['node-lpage-body'] = array(
    'bundle' => 'lpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Landing page',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-lpage-field_lp_3rd_content'.
  $field_instances['node-lpage-field_lp_3rd_content'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_3rd_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_3rd_content',
    'label' => '3rd list content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage-field_lp_3rd_more'.
  $field_instances['node-lpage-field_lp_3rd_more'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_3rd_more][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_3rd_more',
    'label' => '3rd list more link url',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 14,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_3rd_name'.
  $field_instances['node-lpage-field_lp_3rd_name'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_3rd_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_3rd_name',
    'label' => '3rd list name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_bkg_image'.
  $field_instances['node-lpage-field_lp_bkg_image'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_bkg_image',
    'label' => 'Page background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -2,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_blog'.
  $field_instances['node-lpage-field_lp_blog'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blog][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blog',
    'label' => 'Blog list',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage-field_lp_blog_more'.
  $field_instances['node-lpage-field_lp_blog_more'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blog_more][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blog_more',
    'label' => 'Blog list more link url',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_l_img'.
  $field_instances['node-lpage-field_lp_contact_l_img'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_img',
    'label' => 'Contact image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 9,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_l_name'.
  $field_instances['node-lpage-field_lp_contact_l_name'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_l_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_name',
    'label' => 'Contact name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 8,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_l_url'.
  $field_instances['node-lpage-field_lp_contact_l_url'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_l_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_url',
    'label' => 'Contact link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_r_img'.
  $field_instances['node-lpage-field_lp_contact_r_img'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_img',
    'label' => 'Contact image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 10,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_r_name'.
  $field_instances['node-lpage-field_lp_contact_r_name'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_r_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_name',
    'label' => 'Contact name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_contact_r_url'.
  $field_instances['node-lpage-field_lp_contact_r_url'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_r_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_url',
    'label' => 'Contact link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_l_image'.
  $field_instances['node-lpage-field_lp_cta_l_image'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_l_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 12,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_l_text'.
  $field_instances['node-lpage-field_lp_cta_l_text'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_l_text][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_l_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_l_title'.
  $field_instances['node-lpage-field_lp_cta_l_title'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_l_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_l_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_l_url'.
  $field_instances['node-lpage-field_lp_cta_l_url'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_l_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_l_url',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_r_image'.
  $field_instances['node-lpage-field_lp_cta_r_image'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_r_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 15,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_r_text'.
  $field_instances['node-lpage-field_lp_cta_r_text'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_r_text][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_r_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_r_title'.
  $field_instances['node-lpage-field_lp_cta_r_title'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_r_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_r_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_cta_r_url'.
  $field_instances['node-lpage-field_lp_cta_r_url'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_cta_r_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_cta_r_url',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 16,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_h_image'.
  $field_instances['node-lpage-field_lp_h_image'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_h_image',
    'label' => 'Header image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_h_style'.
  $field_instances['node-lpage-field_lp_h_style'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_h_style][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_h_style',
    'label' => 'Header background style',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_new_more'.
  $field_instances['node-lpage-field_lp_new_more'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_new_more][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_new_more',
    'label' => 'News list more link url',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 8,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage-field_lp_news'.
  $field_instances['node-lpage-field_lp_news'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_news][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_news',
    'label' => 'News list',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage-field_lp_v_image'.
  $field_instances['node-lpage-field_lp_v_image'] = array(
    'bundle' => 'lpage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_image',
    'label' => 'Video image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage-field_lp_v_link'.
  $field_instances['node-lpage-field_lp_v_link'] = array(
    'bundle' => 'lpage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_v_link][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_link',
    'label' => 'Video link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-body'.
  $field_instances['node-lpage2-body'] = array(
    'bundle' => 'lpage2',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-lpage2-field_lp_bkg_image'.
  $field_instances['node-lpage2-field_lp_bkg_image'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -3,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -3,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_bkg_image',
    'label' => 'Page background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -3,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_blog'.
  $field_instances['node-lpage2-field_lp_blog'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_lp_blog][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Related Publications content',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blog',
    'label' => 'Blog list',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 17,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 17,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage2-field_lp_blog_more'.
  $field_instances['node-lpage2-field_lp_blog_more'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blog_more][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blog_more',
    'label' => 'Blog list more link url',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_l_img'.
  $field_instances['node-lpage2-field_lp_contact_l_img'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 11,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 11,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_img',
    'label' => 'Contact image 1',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 11,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_l_name'.
  $field_instances['node-lpage2-field_lp_contact_l_name'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_l_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_name',
    'label' => 'Contact name 1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_l_url'.
  $field_instances['node-lpage2-field_lp_contact_l_url'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_l_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_l_url',
    'label' => 'Contact link 1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_r_img'.
  $field_instances['node-lpage2-field_lp_contact_r_img'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_img',
    'label' => 'Contact image 2',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 14,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_r_name'.
  $field_instances['node-lpage2-field_lp_contact_r_name'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_r_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_name',
    'label' => 'Contact name 2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_contact_r_url'.
  $field_instances['node-lpage2-field_lp_contact_r_url'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_contact_r_url][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_contact_r_url',
    'label' => 'Contact link 2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 15,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_file_1'.
  $field_instances['node-lpage2-field_lp_dl_file_1'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 23,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 23,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 23,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_file_1',
    'label' => 'Download File 1',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 23,
    'widget' => array(
      'active' => 0,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 23,
    ),
    'widget_type' => 'filefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_file_2'.
  $field_instances['node-lpage2-field_lp_dl_file_2'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 26,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 26,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 26,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_file_2',
    'label' => 'Download File 2',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 26,
    'widget' => array(
      'active' => 0,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 26,
    ),
    'widget_type' => 'filefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_file_3'.
  $field_instances['node-lpage2-field_lp_dl_file_3'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 29,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 29,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 29,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_file_3',
    'label' => 'Download File 3',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 29,
    'widget' => array(
      'active' => 0,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 29,
    ),
    'widget_type' => 'filefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_file_4'.
  $field_instances['node-lpage2-field_lp_dl_file_4'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 32,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 32,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 32,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_file_4',
    'label' => 'Download File 4',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 32,
    ),
    'widget_type' => 'filefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_img_1'.
  $field_instances['node-lpage2-field_lp_dl_img_1'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 24,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 24,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 24,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_img_1',
    'label' => 'Download Image 1',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 24,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 24,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_img_2'.
  $field_instances['node-lpage2-field_lp_dl_img_2'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 27,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 27,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 27,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_img_2',
    'label' => 'Download Image 2',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 27,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 27,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_img_3'.
  $field_instances['node-lpage2-field_lp_dl_img_3'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 30,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 30,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 30,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_img_3',
    'label' => 'Download Image 3',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 30,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 30,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_img_4'.
  $field_instances['node-lpage2-field_lp_dl_img_4'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 33,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 33,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 33,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_img_4',
    'label' => 'Download Image 4',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 33,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 33,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_title_1'.
  $field_instances['node-lpage2-field_lp_dl_title_1'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_dl_title_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_title_1',
    'label' => 'Download Title 1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 22,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 22,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_title_2'.
  $field_instances['node-lpage2-field_lp_dl_title_2'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_dl_title_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_title_2',
    'label' => 'Download Title 2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 25,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 25,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_title_3'.
  $field_instances['node-lpage2-field_lp_dl_title_3'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_dl_title_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_title_3',
    'label' => 'Download Title 3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 28,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 28,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_dl_title_4'.
  $field_instances['node-lpage2-field_lp_dl_title_4'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_dl_title_4][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_dl_title_4',
    'label' => 'Download Title 4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_new_more'.
  $field_instances['node-lpage2-field_lp_new_more'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_new_more][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_new_more',
    'label' => 'News list more link url',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 16,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpage2-field_lp_news'.
  $field_instances['node-lpage2-field_lp_news'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_lp_news][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Useful Links content',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_news',
    'label' => 'News list',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpage2-field_lp_v_image'.
  $field_instances['node-lpage2-field_lp_v_image'] = array(
    'bundle' => 'lpage2',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_image',
    'label' => 'Video image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 9,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpage2-field_lp_v_link'.
  $field_instances['node-lpage2-field_lp_v_link'] = array(
    'bundle' => 'lpage2',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_v_link][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_link',
    'label' => 'Video link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpagef-body'.
  $field_instances['node-lpagef-body'] = array(
    'bundle' => 'lpagef',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-lpagef-field_lp_bkg_image'.
  $field_instances['node-lpagef-field_lp_bkg_image'] = array(
    'bundle' => 'lpagef',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_bkg_image',
    'label' => 'Page background',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_1'.
  $field_instances['node-lpagef-field_lp_blk_1'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_lp_blk_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_1',
    'label' => 'Block 1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_1_colour'.
  $field_instances['node-lpagef-field_lp_blk_1_colour'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_1_colour][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'default colour is: #00245d
Leave blank for clear background',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_1_colour',
    'label' => 'Block 1 BG Colour',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_2'.
  $field_instances['node-lpagef-field_lp_blk_2'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_lp_blk_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_2',
    'label' => 'Block 2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_2_colour'.
  $field_instances['node-lpagef-field_lp_blk_2_colour'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_2_colour][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'default colour is: #00245d
Leave blank for clear background',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_2_colour',
    'label' => 'Block 2 BG Colour',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_3'.
  $field_instances['node-lpagef-field_lp_blk_3'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_3',
    'label' => 'Block 3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_3_colour'.
  $field_instances['node-lpagef-field_lp_blk_3_colour'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_3_colour][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'default colour is: #00245d
Leave blank for clear background',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_3_colour',
    'label' => 'Block 3 BG Colour',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_4'.
  $field_instances['node-lpagef-field_lp_blk_4'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_4][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_4',
    'label' => 'Block 4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-lpagef-field_lp_blk_4_colour'.
  $field_instances['node-lpagef-field_lp_blk_4_colour'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_blk_4_colour][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'default colour is: #00245d
Leave blank for clear background',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'mobile' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_blk_4_colour',
    'label' => 'Block 4 BG Colour',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 16,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-lpagef-field_lp_title_img'.
  $field_instances['node-lpagef-field_lp_title_img'] = array(
    'bundle' => 'lpagef',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -4,
      ),
      'mobile' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -4,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -4,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_title_img',
    'label' => 'Title Image [optional]',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -4,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpagef-field_lp_v_image'.
  $field_instances['node-lpagef-field_lp_v_image'] = array(
    'bundle' => 'lpagef',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_image',
    'label' => 'Video image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'landing-page',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 37,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 16,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-lpagef-field_lp_v_link'.
  $field_instances['node-lpagef-field_lp_v_link'] = array(
    'bundle' => 'lpagef',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_lp_v_link][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'cck_blocks' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lp_v_link',
    'label' => 'Video link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 38,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
    'widget_type' => 'text_textfield',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('3rd list content');
  t('3rd list more link url');
  t('3rd list name');
  t('Block 1');
  t('Block 1 BG Colour');
  t('Block 2');
  t('Block 2 BG Colour');
  t('Block 3');
  t('Block 3 BG Colour');
  t('Block 4');
  t('Block 4 BG Colour');
  t('Blog list');
  t('Blog list more link url');
  t('Body');
  t('Contact image');
  t('Contact image 1');
  t('Contact image 2');
  t('Contact link');
  t('Contact link 1');
  t('Contact link 2');
  t('Contact name');
  t('Contact name 1');
  t('Contact name 2');
  t('Download File 1');
  t('Download File 2');
  t('Download File 3');
  t('Download File 4');
  t('Download Image 1');
  t('Download Image 2');
  t('Download Image 3');
  t('Download Image 4');
  t('Download Title 1');
  t('Download Title 2');
  t('Download Title 3');
  t('Download Title 4');
  t('Header background style');
  t('Header image');
  t('Image');
  t('Landing page');
  t('Link');
  t('News list');
  t('News list more link url');
  t('Page background');
  t('Related Publications content');
  t('Text');
  t('Title');
  t('Title Image [optional]');
  t('Useful Links content');
  t('Video image');
  t('Video link');
  t('default colour is: #00245d
Leave blank for clear background');

  return $field_instances;
}
