<?php
/**
 * @file
 * brexit_hub.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function brexit_hub_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'brexit_hub';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Brexit Hub';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Brexit Hub';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Post Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_l_date']['id'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['fields']['field_l_date']['field'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['label'] = 'Legal Update Date';
  $handler->display->display_options['fields']['field_l_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '10';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Download Url */
  $handler->display->display_options['fields']['field_d_url']['id'] = 'field_d_url';
  $handler->display->display_options['fields']['field_d_url']['table'] = 'field_data_field_d_url';
  $handler->display->display_options['fields']['field_d_url']['field'] = 'field_d_url';
  $handler->display->display_options['fields']['field_d_url']['label'] = '';
  $handler->display->display_options['fields']['field_d_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_url']['settings'] = array(
    'imagecache_external_style' => 'medium',
    'imagecache_external_link' => '',
  );
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'col-3--lg--thumb-fixed',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_lp_cta_l_url']['id'] = 'field_lp_cta_l_url';
  $handler->display->display_options['fields']['field_lp_cta_l_url']['table'] = 'field_data_field_lp_cta_l_url';
  $handler->display->display_options['fields']['field_lp_cta_l_url']['field'] = 'field_lp_cta_l_url';
  $handler->display->display_options['fields']['field_lp_cta_l_url']['label'] = '';
  $handler->display->display_options['fields']['field_lp_cta_l_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lp_cta_l_url']['empty'] = '[path]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Date (field_l_date) */
  $handler->display->display_options['sorts']['field_l_date_value']['id'] = 'field_l_date_value';
  $handler->display->display_options['sorts']['field_l_date_value']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['sorts']['field_l_date_value']['field'] = 'field_l_date_value';
  $handler->display->display_options['sorts']['field_l_date_value']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'lupdate' => 'lupdate',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Area (field_l_area) */
  $handler->display->display_options['filters']['field_l_area_nid']['id'] = 'field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['table'] = 'field_data_field_l_area';
  $handler->display->display_options['filters']['field_l_area_nid']['field'] = 'field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['value'] = array(
    14533 => '14533',
  );
  $handler->display->display_options['filters']['field_l_area_nid']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'feed_import' => 'feed_import',
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    316 => '316',
  );
  $handler->display->display_options['filters']['tid']['group'] = 2;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'vocabulary_1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['brexit_hub'] = $view;

  $view = new view();
  $view->name = 'brexit_paginated_related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Brexit Paginated related content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Related Content */
  $handler->display->display_options['fields']['field_related_content']['id'] = 'field_related_content';
  $handler->display->display_options['fields']['field_related_content']['table'] = 'field_data_field_related_content';
  $handler->display->display_options['fields']['field_related_content']['field'] = 'field_related_content';
  $handler->display->display_options['fields']['field_related_content']['label'] = '';
  $handler->display->display_options['fields']['field_related_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_content']['settings'] = array(
    'add' => 'Add',
    'edit' => 'Edit',
    'translate' => '',
    'delete' => 'Delete',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_related_content']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_related_content']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Related Content (field_related_content) */
  $handler->display->display_options['filters']['field_related_content_value']['id'] = 'field_related_content_value';
  $handler->display->display_options['filters']['field_related_content_value']['table'] = 'field_data_field_related_content';
  $handler->display->display_options['filters']['field_related_content_value']['field'] = 'field_related_content_value';
  $handler->display->display_options['filters']['field_related_content_value']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['brexit_paginated_related_content'] = $view;

  return $export;
}
