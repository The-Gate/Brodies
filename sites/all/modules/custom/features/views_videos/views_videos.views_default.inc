<?php
/**
 * @file
 * views_videos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_videos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Videos';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'picture_mapping' => 'col_3_fixed',
    'fallback_image_style' => '',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 1,
    'image_link' => '',
  );
  /* Field: Content: Video url */
  $handler->display->display_options['fields']['field_video_url']['id'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['table'] = 'field_data_field_video_url';
  $handler->display->display_options['fields']['field_video_url']['field'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['label'] = '';
  $handler->display->display_options['fields']['field_video_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_url']['type'] = 'text_plain';
  /* Field: Content: Related services */
  $handler->display->display_options['fields']['field_related_service']['id'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['fields']['field_related_service']['field'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['label'] = '';
  $handler->display->display_options['fields']['field_related_service']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_service']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_service']['delta_offset'] = '0';
  /* Field: Content: Related sector */
  $handler->display->display_options['fields']['field_related_sector']['id'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['field'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['label'] = '';
  $handler->display->display_options['fields']['field_related_sector']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_sector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_sector']['delta_offset'] = '0';
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
    'video' => 'video',
  );
  /* Filter criterion: Related services (field_related_service) (selective) */
  $handler->display->display_options['filters']['field_related_service_nid_selective']['id'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['field'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['ui_name'] = 'Related services (field_related_service) (selective)';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_service_nid_selective']['expose']['operator_id'] = '';
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
  /* Filter criterion: Related sector (field_related_sector) (selective) */
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['id'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['field'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['ui_name'] = 'Related sector (field_related_sector) (selective)';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['expose']['operator_id'] = '';
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
  $handler->display->display_options['select_labels'] = array(
    'field_related_service_nid_selective' => 'Related services',
    'field_related_sector_nid_selective' => 'Related sector',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'videos';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Videos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-header';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['videos'] = $view;

  return $export;
}
