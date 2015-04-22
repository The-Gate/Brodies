<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function landing_page_flexible_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_lp_under
  $groups['lpagef-group_lp_under'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpagef',
    'group_name' => 'group_lp_under',
    'label' => 'Bottom Columns',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '1',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'mobile' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_lp_blk_1',
      '1' => 'field_lp_blk_1_colour',
      '2' => 'field_lp_blk_2',
      '3' => 'field_lp_blk_2_colour',
      '4' => 'field_lp_blk_3',
      '5' => 'field_lp_blk_3_colour',
      '6' => 'field_lp_blk_4',
      '7' => 'field_lp_blk_4_colour',
    ),
  );

  // Exported group: group_lp_video
  $groups['lpagef-group_lp_video'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpagef',
    'group_name' => 'group_lp_video',
    'label' => 'Video',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'mobile' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_lp_v_image',
      '1' => 'field_lp_v_link',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom Columns');
  t('Video');

  return $groups;
}
