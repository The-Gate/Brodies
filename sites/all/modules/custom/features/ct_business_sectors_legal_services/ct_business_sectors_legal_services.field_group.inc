<?php
/**
 * @file
 * ct_business_sectors_legal_services.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_business_sectors_legal_services_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_videos|node|service|default';
  $field_group->group_name = 'group_p_videos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline Videos',
    'weight' => '3',
    'children' => array(
      0 => 'field_p_v_image_1',
      1 => 'field_p_v_text_1',
      2 => 'field_p_v_url_1',
      3 => 'field_p_v_image_2',
      4 => 'field_p_v_text_2',
      5 => 'field_p_v_url_2',
      6 => 'field_p_v_image_3',
      7 => 'field_p_v_text_3',
      8 => 'field_p_v_url_3',
      9 => 'field_p_v_image_4',
      10 => 'field_p_v_text_4',
      11 => 'field_p_v_url_4',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_videos|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_videos|node|service|form';
  $field_group->group_name = 'group_p_videos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline Videos',
    'weight' => '10',
    'children' => array(
      0 => 'field_p_v_image_1',
      1 => 'field_p_v_text_1',
      2 => 'field_p_v_url_1',
      3 => 'field_p_v_image_2',
      4 => 'field_p_v_text_2',
      5 => 'field_p_v_url_2',
      6 => 'field_p_v_image_3',
      7 => 'field_p_v_text_3',
      8 => 'field_p_v_url_3',
      9 => 'field_p_v_image_4',
      10 => 'field_p_v_text_4',
      11 => 'field_p_v_url_4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_videos|node|service|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_videos|node|service|teaser';
  $field_group->group_name = 'group_p_videos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline Videos',
    'weight' => '6',
    'children' => array(
      0 => 'field_p_v_image_1',
      1 => 'field_p_v_text_1',
      2 => 'field_p_v_url_1',
      3 => 'field_p_v_image_2',
      4 => 'field_p_v_text_2',
      5 => 'field_p_v_url_2',
      6 => 'field_p_v_image_3',
      7 => 'field_p_v_text_3',
      8 => 'field_p_v_url_3',
      9 => 'field_p_v_image_4',
      10 => 'field_p_v_text_4',
      11 => 'field_p_v_url_4',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_p_videos|node|service|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_binformed|node|sector|default';
  $field_group->group_name = 'group_related_binformed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related';
  $field_group->data = array(
    'label' => 'Binformed - sharing our knowledge',
    'weight' => '12',
    'children' => array(
      0 => 'field_related_binformed',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-binformed field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_binformed|node|sector|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_binformed|node|service|default';
  $field_group->group_name = 'group_related_binformed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_service_related';
  $field_group->data = array(
    'label' => 'Binformed - sharing our knowledge',
    'weight' => '2',
    'children' => array(
      0 => 'field_related_binformed',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-binformed field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_binformed|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_secotrs|node|sector|default';
  $field_group->group_name = 'group_related_secotrs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related';
  $field_group->data = array(
    'label' => 'Related Sectors',
    'weight' => '13',
    'children' => array(
      0 => 'field_related_service',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-secotrs field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_secotrs|node|sector|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_secotrs|node|service|default';
  $field_group->group_name = 'group_related_secotrs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_service_related';
  $field_group->data = array(
    'label' => 'Related Sectors',
    'weight' => '3',
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
  $field_groups['group_related_secotrs|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_services|node|sector|default';
  $field_group->group_name = 'group_related_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related';
  $field_group->data = array(
    'label' => 'Related Services',
    'weight' => '14',
    'children' => array(
      0 => 'field_related_sector',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-related-services field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_related_services|node|sector|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_services|node|service|default';
  $field_group->group_name = 'group_related_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_service_related';
  $field_group->data = array(
    'label' => 'Related Services',
    'weight' => '4',
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
  $field_groups['group_related_services|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_video|node|sector|default';
  $field_group->group_name = 'group_related_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_related';
  $field_group->data = array(
    'label' => 'Related Video',
    'weight' => '15',
    'children' => array(
      0 => 'field_related_video',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-video field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_video|node|sector|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_video|node|service|default';
  $field_group->group_name = 'group_related_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_service_related';
  $field_group->data = array(
    'label' => 'Related Video',
    'weight' => '5',
    'children' => array(
      0 => 'field_related_video',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_related_video|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|sector|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '1',
    'children' => array(
      0 => 'group_related_secotrs',
      1 => 'group_related_services',
      2 => 'group_related_binformed',
      3 => 'group_related_video',
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
  $field_groups['group_related|node|sector|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|sector|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '5',
    'children' => array(
      0 => 'field_related_people',
      1 => 'field_related_service',
      2 => 'field_related_cs',
      3 => 'field_related_event',
      4 => 'field_related_video',
      5 => 'field_related_sector',
      6 => 'field_related_binformed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related|node|sector|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|sector|teaser';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sector';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '4',
    'children' => array(
      0 => 'field_related_people',
      1 => 'field_related_service',
      2 => 'field_related_cs',
      3 => 'field_related_event',
      4 => 'field_related_video',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_related|node|sector|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_related|node|service|default';
  $field_group->group_name = 'group_service_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '1',
    'children' => array(
      0 => 'group_related_secotrs',
      1 => 'group_related_services',
      2 => 'group_related_binformed',
      3 => 'group_related_video',
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
  $field_groups['group_service_related|node|service|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_related|node|service|form';
  $field_group->group_name = 'group_service_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '4',
    'children' => array(
      0 => 'field_related_people',
      1 => 'field_related_sector',
      2 => 'field_related_cs',
      3 => 'field_related_video',
      4 => 'field_related_service',
      5 => 'field_related_binformed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_service_related|node|service|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_related|node|service|teaser';
  $field_group->group_name = 'group_service_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '3',
    'children' => array(
      0 => 'field_related_people',
      1 => 'field_related_sector',
      2 => 'field_related_cs',
      3 => 'field_related_video',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_service_related|node|service|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Binformed - sharing our knowledge');
  t('Inline Videos');
  t('Related Sectors');
  t('Related Services');
  t('Related Video');
  t('Related content');

  return $field_groups;
}
