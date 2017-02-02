<?php
/**
 * @file
 * events_seminars_ct_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function events_seminars_ct_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'seminars';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Seminars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Seminars';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="date">[field_event_date]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Where */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event_location']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_event_location']['type'] = 'node_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="read-more-block">[view_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Related sector */
  $handler->display->display_options['fields']['field_related_sector']['id'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['field'] = 'field_related_sector';
  $handler->display->display_options['fields']['field_related_sector']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_sector']['delta_offset'] = '0';
  /* Field: Content: Related services */
  $handler->display->display_options['fields']['field_related_service']['id'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['fields']['field_related_service']['field'] = 'field_related_service';
  $handler->display->display_options['fields']['field_related_service']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_service']['delta_offset'] = '0';
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_event_date_1']['id'] = 'field_event_date_1';
  $handler->display->display_options['fields']['field_event_date_1']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date_1']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Content: When -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Visibility time (field_event_visibility) */
  $handler->display->display_options['filters']['field_event_visibility_value']['id'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['table'] = 'field_data_field_event_visibility';
  $handler->display->display_options['filters']['field_event_visibility_value']['field'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_visibility_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_visibility_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_visibility_value']['default_date'] = 'now';
  /* Filter criterion: Content: When -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['value'] = array(
    'seminar' => 'seminar',
  );
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;
  /* Filter criterion: When -  start date (field_event_date) (selective) */
  $handler->display->display_options['filters']['field_event_date_value_selective']['id'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value_selective']['field'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['ui_name'] = 'When -  start date (field_event_date) (selective)';
  $handler->display->display_options['filters']['field_event_date_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['identifier'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_value_selective']['selective_display_field'] = 'field_event_date_1';
  $handler->display->display_options['filters']['field_event_date_value_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Where (field_event_location) (selective) */
  $handler->display->display_options['filters']['field_event_location_nid_selective']['id'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['field'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['ui_name'] = 'Where (field_event_location) (selective)';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_event_location_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['identifier'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_location_nid_selective']['selective_display_field'] = 'field_event_location';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Related sector (field_related_sector) (selective) */
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['id'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['field'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['ui_name'] = 'Related sector (field_related_sector) (selective)';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['group'] = 2;
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
  /* Filter criterion: Related services (field_related_service) (selective) */
  $handler->display->display_options['filters']['field_related_service_nid_selective']['id'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['field'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['ui_name'] = 'Related services (field_related_service) (selective)';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['group'] = 2;
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
  $handler->display->display_options['select_labels'] = array(
    'field_event_l_details_value_selective' => 'Location',
    'field_related_sector_nid_selective' => 'sector',
    'field_event_date_value_selective' => 'Date',
    'field_related_service_nid_selective' => 'services ',
    'field_event_location_nid_selective' => 'Location',
  );

  /* Display: Main Seminar Listing */
  $handler = $view->new_display('block', 'Main Seminar Listing', 'block');

  /* Display: Related Seminars */
  $handler = $view->new_display('block', 'Related Seminars', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related seminars';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'is-table-row';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Related sector (field_related_sector) */
  $handler->display->display_options['relationships']['field_related_sector_nid']['id'] = 'field_related_sector_nid';
  $handler->display->display_options['relationships']['field_related_sector_nid']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['relationships']['field_related_sector_nid']['field'] = 'field_related_sector_nid';
  $handler->display->display_options['relationships']['field_related_sector_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_related_sector_nid']['delta'] = '-1';
  /* Relationship: Content: Related services (field_related_service) */
  $handler->display->display_options['relationships']['field_related_service_nid']['id'] = 'field_related_service_nid';
  $handler->display->display_options['relationships']['field_related_service_nid']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['relationships']['field_related_service_nid']['field'] = 'field_related_service_nid';
  $handler->display->display_options['relationships']['field_related_service_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_related_service_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
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
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="text-wrapper">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_event_date]</div>
<div class="views-field-body">[body]</div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Visibility time (field_event_visibility) */
  $handler->display->display_options['filters']['field_event_visibility_value']['id'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['table'] = 'field_data_field_event_visibility';
  $handler->display->display_options['filters']['field_event_visibility_value']['field'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_visibility_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_visibility_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_visibility_value']['default_date'] = 'now';
  /* Filter criterion: Content: When -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['value'] = array(
    'seminar' => 'seminar',
  );
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;

  /* Display: Main Events Listing */
  $handler = $view->new_display('block', 'Main Events Listing', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Visibility time (field_event_visibility) */
  $handler->display->display_options['filters']['field_event_visibility_value']['id'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['table'] = 'field_data_field_event_visibility';
  $handler->display->display_options['filters']['field_event_visibility_value']['field'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_visibility_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_visibility_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_visibility_value']['default_date'] = 'now';
  /* Filter criterion: Content: When -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;
  /* Filter criterion: When -  start date (field_event_date) (selective) */
  $handler->display->display_options['filters']['field_event_date_value_selective']['id'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value_selective']['field'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['ui_name'] = 'When -  start date (field_event_date) (selective)';
  $handler->display->display_options['filters']['field_event_date_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['identifier'] = 'field_event_date_value_selective';
  $handler->display->display_options['filters']['field_event_date_value_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_value_selective']['selective_display_field'] = 'field_event_date_1';
  $handler->display->display_options['filters']['field_event_date_value_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Where (field_event_location) (selective) */
  $handler->display->display_options['filters']['field_event_location_nid_selective']['id'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['field'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['ui_name'] = 'Where (field_event_location) (selective)';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_event_location_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['identifier'] = 'field_event_location_nid_selective';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_location_nid_selective']['selective_display_field'] = 'field_event_location';
  $handler->display->display_options['filters']['field_event_location_nid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Related sector (field_related_sector) (selective) */
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['id'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['field'] = 'field_related_sector_nid_selective';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['ui_name'] = 'Related sector (field_related_sector) (selective)';
  $handler->display->display_options['filters']['field_related_sector_nid_selective']['group'] = 2;
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
  /* Filter criterion: Related services (field_related_service) (selective) */
  $handler->display->display_options['filters']['field_related_service_nid_selective']['id'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['field'] = 'field_related_service_nid_selective';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['ui_name'] = 'Related services (field_related_service) (selective)';
  $handler->display->display_options['filters']['field_related_service_nid_selective']['group'] = 2;
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

  /* Display: Related Events */
  $handler = $view->new_display('block', 'Related Events', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'is-table-row';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Related sector (field_related_sector) */
  $handler->display->display_options['relationships']['field_related_sector_nid']['id'] = 'field_related_sector_nid';
  $handler->display->display_options['relationships']['field_related_sector_nid']['table'] = 'field_data_field_related_sector';
  $handler->display->display_options['relationships']['field_related_sector_nid']['field'] = 'field_related_sector_nid';
  $handler->display->display_options['relationships']['field_related_sector_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_related_sector_nid']['delta'] = '-1';
  /* Relationship: Content: Related services (field_related_service) */
  $handler->display->display_options['relationships']['field_related_service_nid']['id'] = 'field_related_service_nid';
  $handler->display->display_options['relationships']['field_related_service_nid']['table'] = 'field_data_field_related_service';
  $handler->display->display_options['relationships']['field_related_service_nid']['field'] = 'field_related_service_nid';
  $handler->display->display_options['relationships']['field_related_service_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_related_service_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
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
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="text-wrapper">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_event_date]</div>
<div class="views-field-body">[body]</div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Visibility time (field_event_visibility) */
  $handler->display->display_options['filters']['field_event_visibility_value']['id'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['table'] = 'field_data_field_event_visibility';
  $handler->display->display_options['filters']['field_event_visibility_value']['field'] = 'field_event_visibility_value';
  $handler->display->display_options['filters']['field_event_visibility_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_visibility_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_visibility_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_visibility_value']['default_date'] = 'now';
  /* Filter criterion: Content: When -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;
  $export['seminars'] = $view;

  return $export;
}
