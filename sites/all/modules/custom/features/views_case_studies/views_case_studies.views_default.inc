<?php
/**
 * @file
 * views_case_studies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_case_studies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Case_Studies';
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
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Related case studies */
  $handler->display->display_options['fields']['field_related_cs']['id'] = 'field_related_cs';
  $handler->display->display_options['fields']['field_related_cs']['table'] = 'field_data_field_related_cs';
  $handler->display->display_options['fields']['field_related_cs']['field'] = 'field_related_cs';
  $handler->display->display_options['fields']['field_related_cs']['label'] = '';
  $handler->display->display_options['fields']['field_related_cs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_cs']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_related_cs']['settings'] = array(
    'node_reference_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_related_cs']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;

  /* Display: related case studies */
  $handler = $view->new_display('block', 'related case studies', 'block_1');

  /* Display: Case studies Page */
  $handler = $view->new_display('page', 'Case studies Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Case studies';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'col-md-8';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_class'] = 'col-md-4';
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'picture_mapping' => 'col_4',
    'fallback_image_style' => '',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 1,
    'image_link' => 'content',
  );
  /* Field: Content: Related sector */
  $handler->display->display_options['fields']['field_related_sector']['id'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['field'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['label'] = '';
  $handler->display->display_options['fields']['field_related_sector']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_sector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_sector']['delta_offset'] = '0';
  /* Field: Content: Related services */
  $handler->display->display_options['fields']['field_related_service']['id'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['fields']['field_related_service']['field'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['label'] = '';
  $handler->display->display_options['fields']['field_related_service']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_service']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_service']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Related sector (field_related_sector) (selective) */
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['id'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['field'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['ui_name'] = 'Related sector (field_related_sector) (selective)';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['expose']['label'] = 'Related sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['expose']['identifier'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['selective_display_field'] = 'field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Related services (field_related_service) (selective) */
  $handler->display->display_options['filters']['field_related_service_nid_selective']['id'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['field'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['ui_name'] = 'Related services (field_related_service) (selective)';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_service_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['expose']['label'] = 'Related services';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['expose']['identifier'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_related_service_nid_selective']['selective_display_field'] = 'field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cs' => 'cs',
  );
  $handler->display->display_options['path'] = 'case-studies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Case Studies ';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-header';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['Case_Studies'] = $view;

  return $export;
}
