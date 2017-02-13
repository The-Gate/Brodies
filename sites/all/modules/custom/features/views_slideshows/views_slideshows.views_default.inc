<?php
/**
 * @file
 * views_slideshows.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_slideshows_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'overview_slider_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Overview slider listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'col-md-8  col-md-offset-2 no-padding-left-md no-padding-right-md';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['optionset'] = 'clone_of_default';
  $handler->display->display_options['style_options']['skin'] = 'grid';
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'title' => 0,
    'field_sector_teaser' => 0,
    'field_teaser_image' => 0,
  );
  $handler->display->display_options['style_options']['slide_overlay'] = '';
  $handler->display->display_options['style_options']['grid'] = '8';
  $handler->display->display_options['style_options']['grid_medium'] = '6';
  $handler->display->display_options['style_options']['grid_small'] = '4';
  $handler->display->display_options['style_options']['visible_slides'] = '8';
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['style_options']['cache'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Display Listing Roll Over Text */
  $handler->display->display_options['fields']['field_sector_teaser']['id'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['table'] = 'field_data_field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['field'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_sector_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sector_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sector_teaser']['type'] = 'text_plain';
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'scroller-display-list',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'sector' => 'sector',
  );

  /* Display: Business Sectors */
  $handler = $view->new_display('block', 'Business Sectors', 'block');

  /* Display: Legal Services */
  $handler = $view->new_display('block', 'Legal Services', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser text */
  $handler->display->display_options['fields']['field_service_teaser']['id'] = 'field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['table'] = 'field_data_field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['field'] = 'field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_service_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_service_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_service_teaser']['type'] = 'text_plain';
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'scroller-display-list',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Menu children */
  $handler->display->display_options['arguments']['menu_children_filter']['id'] = 'menu_children_filter';
  $handler->display->display_options['arguments']['menu_children_filter']['table'] = 'node';
  $handler->display->display_options['arguments']['menu_children_filter']['field'] = 'menu_children_filter';
  $handler->display->display_options['arguments']['menu_children_filter']['default_action'] = 'default';
  $handler->display->display_options['arguments']['menu_children_filter']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['menu_children_filter']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['menu_children_filter']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['menu_children_filter']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['menu_children_filter']['target_menu'] = 'menu-sector';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'service' => 'service',
  );
  $export['overview_slider_listing'] = $view;

  $view = new view();
  $view->name = 'overview_slider_listing_mobile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Overview slider listing - mobile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'col-md-8  col-md-offset-2 no-padding-left-md no-padding-right-md';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Display Listing Roll Over Text */
  $handler->display->display_options['fields']['field_sector_teaser']['id'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['table'] = 'field_data_field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['field'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_sector_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sector_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sector_teaser']['type'] = 'text_plain';
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'scroller-display-list',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'sector' => 'sector',
  );

  /* Display: Business Sectors - Mobile */
  $handler = $view->new_display('block', 'Business Sectors - Mobile', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'picture_mapping' => 'col_3',
    'fallback_image_style' => '',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Display Listing Roll Over Text */
  $handler->display->display_options['fields']['field_sector_teaser']['id'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['table'] = 'field_data_field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['field'] = 'field_sector_teaser';
  $handler->display->display_options['fields']['field_sector_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_sector_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sector_teaser']['type'] = 'text_plain';

  /* Display: Legal Services - Mobile */
  $handler = $view->new_display('block', 'Legal Services - Mobile', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'picture_mapping' => 'col_3',
    'fallback_image_style' => '',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser text */
  $handler->display->display_options['fields']['field_service_teaser']['id'] = 'field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['table'] = 'field_data_field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['field'] = 'field_service_teaser';
  $handler->display->display_options['fields']['field_service_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_service_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_service_teaser']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Menu children */
  $handler->display->display_options['arguments']['menu_children_filter']['id'] = 'menu_children_filter';
  $handler->display->display_options['arguments']['menu_children_filter']['table'] = 'node';
  $handler->display->display_options['arguments']['menu_children_filter']['field'] = 'menu_children_filter';
  $handler->display->display_options['arguments']['menu_children_filter']['default_action'] = 'default';
  $handler->display->display_options['arguments']['menu_children_filter']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['menu_children_filter']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['menu_children_filter']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['menu_children_filter']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['menu_children_filter']['target_menu'] = 'menu-sector';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'service' => 'service',
  );
  $export['overview_slider_listing_mobile'] = $view;

  $view = new view();
  $view->name = 'slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'field_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['slide_overlay'] = '';
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['style_options']['cache'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_slide_image']['id'] = 'field_slide_image';
  $handler->display->display_options['fields']['field_slide_image']['table'] = 'field_data_field_slide_image';
  $handler->display->display_options['fields']['field_slide_image']['field'] = 'field_slide_image';
  $handler->display->display_options['fields']['field_slide_image']['label'] = '';
  $handler->display->display_options['fields']['field_slide_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slide_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
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
    'slide' => 'slide',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['slideshow'] = $view;

  return $export;
}
