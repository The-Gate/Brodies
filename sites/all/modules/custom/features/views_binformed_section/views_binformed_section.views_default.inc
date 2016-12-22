<?php
/**
 * @file
 * views_binformed_section.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_binformed_section_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'latest_legal_update';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_l_date']['id'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['fields']['field_l_date']['field'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['label'] = '';
  $handler->display->display_options['fields']['field_l_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_l_date']['settings'] = array(
    'format_type' => 'brodies_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Legal left */
  $handler->display->display_options['fields']['field_l_left']['id'] = 'field_l_left';
  $handler->display->display_options['fields']['field_l_left']['table'] = 'field_data_field_l_left';
  $handler->display->display_options['fields']['field_l_left']['field'] = 'field_l_left';
  $handler->display->display_options['fields']['field_l_left']['label'] = '';
  $handler->display->display_options['fields']['field_l_left']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lupdate' => 'lupdate',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search by keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Content: Area (field_l_area) */
  $handler->display->display_options['filters']['field_l_area_nid']['id'] = 'field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['table'] = 'field_data_field_l_area';
  $handler->display->display_options['filters']['field_l_area_nid']['field'] = 'field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_l_area_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['operator_id'] = 'field_l_area_nid_op';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['label'] = 'Area';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['operator'] = 'field_l_area_nid_op';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['identifier'] = 'field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Date (field_l_date) */
  $handler->display->display_options['filters']['field_l_date_value']['id'] = 'field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['filters']['field_l_date_value']['field'] = 'field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_l_date_value']['expose']['operator_id'] = 'field_l_date_value_op';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['operator'] = 'field_l_date_value_op';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['identifier'] = 'field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_l_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_l_date_value']['year_range'] = '2006:+0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'binformed/legal-updates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Legal Updates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sector';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Recent Updates */
  $handler = $view->new_display('block', 'Recent Updates', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Updates';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_l_date']['id'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['fields']['field_l_date']['field'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['label'] = '';
  $handler->display->display_options['fields']['field_l_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_l_date']['settings'] = array(
    'format_type' => 'brodies_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lupdate' => 'lupdate',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  $export['latest_legal_update'] = $view;

  return $export;
}
