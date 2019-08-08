<?php

/**
 * @file
 * vacancies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vacancies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vacancies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vacancies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vacancies';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => '2',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_location_tid_selective' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
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
    'field_practice_area_tid_selective' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
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
    'field_role_type_tid_selective' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Download File */
  $handler->display->display_options['fields']['field_d_file']['id'] = 'field_d_file';
  $handler->display->display_options['fields']['field_d_file']['table'] = 'field_data_field_d_file';
  $handler->display->display_options['fields']['field_d_file']['field'] = 'field_d_file';
  $handler->display->display_options['fields']['field_d_file']['label'] = '';
  $handler->display->display_options['fields']['field_d_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_d_file']['alter']['text'] = '<a href="[field_d_file]" target="_blank">full details</a>';
  $handler->display->display_options['fields']['field_d_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_d_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_d_file']['settings'] = array(
    'text' => 'full details',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
  /* Field: Content: Practice area */
  $handler->display->display_options['fields']['field_practice_area']['id'] = 'field_practice_area';
  $handler->display->display_options['fields']['field_practice_area']['table'] = 'field_data_field_practice_area';
  $handler->display->display_options['fields']['field_practice_area']['field'] = 'field_practice_area';
  $handler->display->display_options['fields']['field_practice_area']['exclude'] = TRUE;
  /* Field: Content: Role Type */
  $handler->display->display_options['fields']['field_role_type']['id'] = 'field_role_type';
  $handler->display->display_options['fields']['field_role_type']['table'] = 'field_data_field_role_type';
  $handler->display->display_options['fields']['field_role_type']['field'] = 'field_role_type';
  $handler->display->display_options['fields']['field_role_type']['exclude'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vacancy' => 'vacancy',
  );
  /* Filter criterion: Location (field_location) (selective) */
  $handler->display->display_options['filters']['field_location_tid_selective']['id'] = 'field_location_tid_selective';
  $handler->display->display_options['filters']['field_location_tid_selective']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_tid_selective']['field'] = 'field_location_tid_selective';
  $handler->display->display_options['filters']['field_location_tid_selective']['ui_name'] = 'Location (field_location) (selective)';
  $handler->display->display_options['filters']['field_location_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_location_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_location_tid_selective']['expose']['identifier'] = 'field_location_tid_selective';
  $handler->display->display_options['filters']['field_location_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_location_tid_selective']['selective_display_field'] = 'field_location';
  $handler->display->display_options['filters']['field_location_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Practice area (field_practice_area) (selective) */
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['id'] = 'field_practice_area_tid_selective';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['table'] = 'field_data_field_practice_area';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['field'] = 'field_practice_area_tid_selective';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['ui_name'] = 'Practice area (field_practice_area) (selective)';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['expose']['identifier'] = 'field_practice_area_tid_selective';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['selective_display_field'] = 'field_practice_area';
  $handler->display->display_options['filters']['field_practice_area_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Role Type (field_role_type) (selective) */
  $handler->display->display_options['filters']['field_role_type_tid_selective']['id'] = 'field_role_type_tid_selective';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['table'] = 'field_data_field_role_type';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['field'] = 'field_role_type_tid_selective';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['ui_name'] = 'Role Type (field_role_type) (selective)';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_role_type_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['expose']['identifier'] = 'field_role_type_tid_selective';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_role_type_tid_selective']['selective_display_field'] = 'field_role_type';
  $handler->display->display_options['filters']['field_role_type_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Vacancy type (field_vacancy_type) */
  $handler->display->display_options['filters']['field_vacancy_type_tid']['id'] = 'field_vacancy_type_tid';
  $handler->display->display_options['filters']['field_vacancy_type_tid']['table'] = 'field_data_field_vacancy_type';
  $handler->display->display_options['filters']['field_vacancy_type_tid']['field'] = 'field_vacancy_type_tid';
  $handler->display->display_options['filters']['field_vacancy_type_tid']['value'] = array(
    465 => '465',
  );
  $handler->display->display_options['filters']['field_vacancy_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_vacancy_type_tid']['vocabulary'] = 'vacancy_type';
  $handler->display->display_options['select_labels'] = array(
    'field_location_tid_selective' => 'Location',
    'field_practice_area_tid_selective' => 'Practice area',
    'field_role_type_tid_selective' => 'Role',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['vacancies'] = $view;

  return $export;
}
