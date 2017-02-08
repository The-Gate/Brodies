<?php
/**
 * @file
 * views_people.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_people_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Key_Contacts';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Related people */
  $handler->display->display_options['fields']['field_related_people']['id'] = 'field_related_people';
  $handler->display->display_options['fields']['field_related_people']['table'] = 'field_data_field_related_people';
  $handler->display->display_options['fields']['field_related_people']['field'] = 'field_related_people';
  $handler->display->display_options['fields']['field_related_people']['label'] = '';
  $handler->display->display_options['fields']['field_related_people']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_people']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_related_people']['settings'] = array(
    'node_reference_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_related_people']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['Key_Contacts'] = $view;

  $view = new view();
  $view->name = 'people_listing';
  $view->description = 'lists and filters all active people';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'People listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our People';
  $handler->display->display_options['css_class'] = 'col-md-10  col-md-offset-1';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_related_sector_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_related_service_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_people_partner_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_people_sname_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'col-md-6';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_people_fname' => 'field_people_fname',
    'field_people_sname' => 'field_people_sname',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, your search did not match anyone.';
  $handler->display->display_options['empty']['area']['format'] = '2';
  /* Field: Content: Second Name */
  $handler->display->display_options['fields']['field_people_sname_1']['id'] = 'field_people_sname_1';
  $handler->display->display_options['fields']['field_people_sname_1']['table'] = 'field_data_field_people_sname';
  $handler->display->display_options['fields']['field_people_sname_1']['field'] = 'field_people_sname';
  $handler->display->display_options['fields']['field_people_sname_1']['label'] = '';
  $handler->display->display_options['fields']['field_people_sname_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_sname_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_sname_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_people_sname_1']['settings'] = array(
    'trim_length' => '1',
  );
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_class'] = 'col-sm-3';
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'picture_mapping' => 'col_3',
    'fallback_image_style' => 'col-3--lg--thumb-fixed',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 1,
    'image_link' => 'content',
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_people_fname']['id'] = 'field_people_fname';
  $handler->display->display_options['fields']['field_people_fname']['table'] = 'field_data_field_people_fname';
  $handler->display->display_options['fields']['field_people_fname']['field'] = 'field_people_fname';
  $handler->display->display_options['fields']['field_people_fname']['label'] = '';
  $handler->display->display_options['fields']['field_people_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_fname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_people_fname']['type'] = 'text_plain';
  /* Field: Content: Second Name */
  $handler->display->display_options['fields']['field_people_sname']['id'] = 'field_people_sname';
  $handler->display->display_options['fields']['field_people_sname']['table'] = 'field_data_field_people_sname';
  $handler->display->display_options['fields']['field_people_sname']['field'] = 'field_people_sname';
  $handler->display->display_options['fields']['field_people_sname']['label'] = '';
  $handler->display->display_options['fields']['field_people_sname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_sname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_sname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_people_sname']['type'] = 'text_plain';
  /* Field: Content: Job */
  $handler->display->display_options['fields']['field_people_job']['id'] = 'field_people_job';
  $handler->display->display_options['fields']['field_people_job']['table'] = 'field_data_field_people_job';
  $handler->display->display_options['fields']['field_people_job']['field'] = 'field_people_job';
  $handler->display->display_options['fields']['field_people_job']['label'] = '';
  $handler->display->display_options['fields']['field_people_job']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_job']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_people_location']['id'] = 'field_people_location';
  $handler->display->display_options['fields']['field_people_location']['table'] = 'field_data_field_people_location';
  $handler->display->display_options['fields']['field_people_location']['field'] = 'field_people_location';
  $handler->display->display_options['fields']['field_people_location']['label'] = '';
  $handler->display->display_options['fields']['field_people_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_location']['type'] = 'node_reference_plain';
  /* Field: Content: Direct line */
  $handler->display->display_options['fields']['field_people_phone']['id'] = 'field_people_phone';
  $handler->display->display_options['fields']['field_people_phone']['table'] = 'field_data_field_people_phone';
  $handler->display->display_options['fields']['field_people_phone']['field'] = 'field_people_phone';
  $handler->display->display_options['fields']['field_people_phone']['label'] = '';
  $handler->display->display_options['fields']['field_people_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_phone']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More info';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="person-wrapper">
<div class="person person-image col-sm-6 no-padding-left-sm no-padding-right-sm">[field_teaser_image]</div>
<div class="text-wrapper col-sm-6">
<div class="person person-name name">[field_people_fname] [field_people_sname]</div>
<div class="person person-job">[field_people_job]</div>
<div class="person person-location">[field_people_location]</div>
<div class="person person-phone nr">[field_people_phone]</div>
<div class="person person-more read-more-block">[view_node]</div>
</div>
<div class="clearfix"></div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Second Name (field_people_sname) */
  $handler->display->display_options['sorts']['field_people_sname_value']['id'] = 'field_people_sname_value';
  $handler->display->display_options['sorts']['field_people_sname_value']['table'] = 'field_data_field_people_sname';
  $handler->display->display_options['sorts']['field_people_sname_value']['field'] = 'field_people_sname_value';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Related sector (field_related_sector) */
  $handler->display->display_options['filters']['field_related_sector_nid']['id'] = 'field_related_sector_nid';
  $handler->display->display_options['filters']['field_related_sector_nid']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid']['field'] = 'field_related_sector_nid';
  $handler->display->display_options['filters']['field_related_sector_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_related_sector_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_sector_nid']['expose']['operator_id'] = 'field_related_sector_nid_op';
  $handler->display->display_options['filters']['field_related_sector_nid']['expose']['operator'] = 'field_related_sector_nid_op';
  $handler->display->display_options['filters']['field_related_sector_nid']['expose']['identifier'] = 'field_related_sector_nid';
  $handler->display->display_options['filters']['field_related_sector_nid']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Related services (field_related_service) */
  $handler->display->display_options['filters']['field_related_service_nid']['id'] = 'field_related_service_nid';
  $handler->display->display_options['filters']['field_related_service_nid']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid']['field'] = 'field_related_service_nid';
  $handler->display->display_options['filters']['field_related_service_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_related_service_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_service_nid']['expose']['operator_id'] = 'field_related_service_nid_op';
  $handler->display->display_options['filters']['field_related_service_nid']['expose']['operator'] = 'field_related_service_nid_op';
  $handler->display->display_options['filters']['field_related_service_nid']['expose']['identifier'] = 'field_related_service_nid';
  $handler->display->display_options['filters']['field_related_service_nid']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'people' => 'people',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Partner (field_people_partner) */
  $handler->display->display_options['filters']['field_people_partner_value']['id'] = 'field_people_partner_value';
  $handler->display->display_options['filters']['field_people_partner_value']['table'] = 'field_data_field_people_partner';
  $handler->display->display_options['filters']['field_people_partner_value']['field'] = 'field_people_partner_value';
  $handler->display->display_options['filters']['field_people_partner_value']['value'] = array(
    'all' => 'all',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_people_partner_value']['group'] = 1;
  $handler->display->display_options['filters']['field_people_partner_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['operator_id'] = 'field_people_partner_value_op';
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['operator'] = 'field_people_partner_value_op';
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['identifier'] = 'field_people_partner_value';
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_people_partner_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_people_partner_value']['group_info']['identifier'] = 'field_people_partner_value';
  $handler->display->display_options['filters']['field_people_partner_value']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_people_partner_value']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_people_partner_value']['group_info']['default_group_multiple'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_people_partner_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'empty',
      'value' => array(),
    ),
    2 => array(
      'title' => 'Partners Only',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
  );
  $handler->display->display_options['select_labels'] = array(
    'title' => 'Search by name',
    'field_related_sector_nid' => 'Business Sector',
    'field_related_service_nid' => 'Legal Services',
    'field_people_partner_value' => 'Partner only',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-header';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'careers/profiles';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Profiles';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-header';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['people_listing'] = $view;

  $view = new view();
  $view->name = 'peson_details';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_teaser_image_fid']['id'] = 'field_teaser_image_fid';
  $handler->display->display_options['fields']['field_teaser_image_fid']['table'] = 'node_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image_fid']['field'] = 'field_teaser_image_fid';
  $handler->display->display_options['fields']['field_teaser_image_fid']['label'] = '';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_people_phone_value']['id'] = 'field_people_phone_value';
  $handler->display->display_options['fields']['field_people_phone_value']['table'] = 'node_data_field_people_phone';
  $handler->display->display_options['fields']['field_people_phone_value']['field'] = 'field_people_phone_value';
  $handler->display->display_options['fields']['field_people_phone_value']['label'] = '';
  $handler->display->display_options['fields']['field_people_phone_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_people_phone_value']['alter']['text'] = '<a href="tel:[field_people_phone_value]">Call</a>';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_people_email_value']['id'] = 'field_people_email_value';
  $handler->display->display_options['fields']['field_people_email_value']['table'] = 'node_data_field_people_email';
  $handler->display->display_options['fields']['field_people_email_value']['field'] = 'field_people_email_value';
  $handler->display->display_options['fields']['field_people_email_value']['label'] = '';
  $handler->display->display_options['fields']['field_people_email_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_people_email_value']['alter']['text'] = '<a href="mailto:[field_people_email_value]">Email</a>';
  $handler->display->display_options['fields']['field_people_email_value']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_people_email_value']['alter']['ellipsis'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_people_vcard_fid']['id'] = 'field_people_vcard_fid';
  $handler->display->display_options['fields']['field_people_vcard_fid']['table'] = 'node_data_field_people_vcard';
  $handler->display->display_options['fields']['field_people_vcard_fid']['field'] = 'field_people_vcard_fid';
  $handler->display->display_options['fields']['field_people_vcard_fid']['label'] = '';
  $handler->display->display_options['fields']['field_people_vcard_fid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_people_vcard_fid']['alter']['text'] = '<a href="[field_people_vcard_fid]" target="_blank">vCard</a>';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;

  /* Display: Person Details */
  $handler = $view->new_display('block', 'Person Details', 'block_1');
  $export['peson_details'] = $view;

  return $export;
}
