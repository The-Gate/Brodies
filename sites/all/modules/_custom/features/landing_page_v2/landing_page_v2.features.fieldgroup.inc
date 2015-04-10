<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function landing_page_v2_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_lp_contact
  $groups['lpage2-group_lp_contact'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpage2',
    'group_name' => 'group_lp_contact',
    'label' => 'Contact Block',
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
    'weight' => '1',
    'fields' => array(
      '0' => 'field_lp_contact_l_name',
      '1' => 'field_lp_contact_l_img',
      '2' => 'field_lp_contact_l_url',
      '3' => 'field_lp_contact_r_name',
      '4' => 'field_lp_contact_r_img',
      '5' => 'field_lp_contact_r_url',
    ),
  );

  // Exported group: group_lp_download
  $groups['lpage2-group_lp_download'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpage2',
    'group_name' => 'group_lp_download',
    'label' => 'Download Block',
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
      '0' => 'field_lp_dl_title_1',
      '1' => 'field_lp_dl_file_1',
      '2' => 'field_lp_dl_img_1',
      '3' => 'field_lp_dl_title_2',
      '4' => 'field_lp_dl_file_2',
      '5' => 'field_lp_dl_img_2',
      '6' => 'field_lp_dl_title_3',
      '7' => 'field_lp_dl_file_3',
      '8' => 'field_lp_dl_img_3',
      '9' => 'field_lp_dl_title_4',
      '10' => 'field_lp_dl_file_4',
      '11' => 'field_lp_dl_img_4',
    ),
  );

  // Exported group: group_lp_under
  $groups['lpage2-group_lp_under'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpage2',
    'group_name' => 'group_lp_under',
    'label' => 'Useful Links / Related Publications Blocks',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
        'label' => 'above',
      ),
    ),
    'weight' => '2',
    'fields' => array(
      '0' => 'field_lp_news',
      '1' => 'field_lp_new_more',
      '2' => 'field_lp_blog',
      '3' => 'field_lp_blog_more',
    ),
  );

  // Exported group: group_lp_video
  $groups['lpage2-group_lp_video'] = array(
    'group_type' => 'standard',
    'type_name' => 'lpage2',
    'group_name' => 'group_lp_video',
    'label' => 'Video',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
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
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_lp_v_image',
      '1' => 'field_lp_v_link',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Block');
  t('Download Block');
  t('Useful Links / Related Publications Blocks');
  t('Video');

  return $groups;
}
