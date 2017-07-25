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
  $view->name = 'guides_downloads';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Guides & downloads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Guides & downloads';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Downloads categories */
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['id'] = 'taxonomy_vocabulary_3';
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['table'] = 'field_data_taxonomy_vocabulary_3';
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['field'] = 'taxonomy_vocabulary_3';
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['taxonomy_vocabulary_3']['delta_offset'] = '0';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_d_thumbail']['id'] = 'field_d_thumbail';
  $handler->display->display_options['fields']['field_d_thumbail']['table'] = 'field_data_field_d_thumbail';
  $handler->display->display_options['fields']['field_d_thumbail']['field'] = 'field_d_thumbail';
  $handler->display->display_options['fields']['field_d_thumbail']['label'] = '';
  $handler->display->display_options['fields']['field_d_thumbail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_d_thumbail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_thumbail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_d_thumbail']['type'] = 'picture';
  $handler->display->display_options['fields']['field_d_thumbail']['settings'] = array(
    'picture_mapping' => 'col_3_fixed',
    'fallback_image_style' => '',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 1,
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_d_date']['id'] = 'field_d_date';
  $handler->display->display_options['fields']['field_d_date']['table'] = 'field_data_field_d_date';
  $handler->display->display_options['fields']['field_d_date']['field'] = 'field_d_date';
  $handler->display->display_options['fields']['field_d_date']['label'] = '';
  $handler->display->display_options['fields']['field_d_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_d_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_date']['settings'] = array(
    'format_type' => 'brodies_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Download Url */
  $handler->display->display_options['fields']['field_d_url']['id'] = 'field_d_url';
  $handler->display->display_options['fields']['field_d_url']['table'] = 'field_data_field_d_url';
  $handler->display->display_options['fields']['field_d_url']['field'] = 'field_d_url';
  $handler->display->display_options['fields']['field_d_url']['label'] = '';
  $handler->display->display_options['fields']['field_d_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_d_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_url']['type'] = 'text_plain';
  /* Field: Content: Download File */
  $handler->display->display_options['fields']['field_d_file']['id'] = 'field_d_file';
  $handler->display->display_options['fields']['field_d_file']['table'] = 'field_data_field_d_file';
  $handler->display->display_options['fields']['field_d_file']['field'] = 'field_d_file';
  $handler->display->display_options['fields']['field_d_file']['label'] = '';
  $handler->display->display_options['fields']['field_d_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_d_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_d_file']['alter']['text'] = '<a href="[field_d_file]" target="_blank">Download guide</a>';
  $handler->display->display_options['fields']['field_d_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_d_file']['empty'] = '<a href="[field_d_url]" target="_blank">Open Guide</a>';
  $handler->display->display_options['fields']['field_d_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_d_file']['type'] = 'file_url_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-8 no-padding-left-md">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_d_date]</div>
<div class="views-field-body">[body]</div>
<div class="views-taxonomy-list"><h3>Categories:</h2> [taxonomy_vocabulary_3] </div>
<div class="read-more-block">[field_d_file]</div>
</div>
<div class="col-md-3 col-md-offset-1 no-padding-right-md">
<div class="img">[field_d_thumbail]</div>
</div>
<div class="clearfix"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'download' => 'download',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Downloads categories (taxonomy_vocabulary_3) (selective) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['id'] = 'taxonomy_vocabulary_3_tid_selective';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['table'] = 'field_data_taxonomy_vocabulary_3';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['field'] = 'taxonomy_vocabulary_3_tid_selective';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['ui_name'] = 'Downloads categories (taxonomy_vocabulary_3) (selective)';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['expose']['identifier'] = 'taxonomy_vocabulary_3_tid_selective';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['selective_display_field'] = 'taxonomy_vocabulary_3';
  $handler->display->display_options['filters']['taxonomy_vocabulary_3_tid_selective']['selective_items_limit'] = '100';
  $handler->display->display_options['select_labels'] = array(
    'taxonomy_vocabulary_3_tid_selective' => 'Categories',
    'combine' => 'Search by keyword',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'binformed/guides-and-downloads';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Guides & Downloads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sector';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['guides_downloads'] = $view;

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
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
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
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Post date Asc|Oldest first
Post date Desc|Newest first
Title Asc|A -> Z
Title Desc|Z -> A',
        'reset' => 1,
        'reset_label' => 'Reset Sort',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
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
    'field_l_area_nid' => array(
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
    'field_l_date_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
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
        'datepicker_options' => '',
      ),
    ),
  );
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_l_date']['id'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['fields']['field_l_date']['field'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['label'] = '';
  $handler->display->display_options['fields']['field_l_date']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_l_left']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_l_left']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_l_date]</div>
<div class="views-field-l-left">[field_l_left]</div>
<div class="views-field-body">[body]</div>
<div class="read-more-block">[view_node]</div>
</div>
<div class="clearfix"></div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
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
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'legal-updates-combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
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
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['operator'] = 'field_l_area_nid_op';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['identifier'] = 'legal-updates-field_l_area_nid';
  $handler->display->display_options['filters']['field_l_area_nid']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Date (field_l_date) */
  $handler->display->display_options['filters']['field_l_date_value']['id'] = 'field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['filters']['field_l_date_value']['field'] = 'field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_l_date_value']['expose']['operator_id'] = 'field_l_date_value_op';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['operator'] = 'field_l_date_value_op';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['identifier'] = 'legal-updates-field_l_date_value';
  $handler->display->display_options['filters']['field_l_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_l_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_l_date_value']['year_range'] = '-0:2006';
  $handler->display->display_options['select_labels'] = array(
    'combine' => 'Search by name',
    'field_l_area_nid' => 'Area',
    'field_l_date_value' => 'Year',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Legal Updates';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'binformed/legal-updates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Legal Updates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sector';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Recent updates */
  $handler = $view->new_display('block', 'Recent updates', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent updates';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'is-table-row';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_l_date']['id'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['table'] = 'field_data_field_l_date';
  $handler->display->display_options['fields']['field_l_date']['field'] = 'field_l_date';
  $handler->display->display_options['fields']['field_l_date']['label'] = '';
  $handler->display->display_options['fields']['field_l_date']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="text-wrapper">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_l_date]</div>
<div class="views-field-body">[body]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
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

  /* Display: Legal Update Area - associated legal updates */
  $handler = $view->new_display('block', 'Legal Update Area - associated legal updates', 'block_3');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_l_area) */
  $handler->display->display_options['arguments']['field_l_area_nid']['id'] = 'field_l_area_nid';
  $handler->display->display_options['arguments']['field_l_area_nid']['table'] = 'field_data_field_l_area';
  $handler->display->display_options['arguments']['field_l_area_nid']['field'] = 'field_l_area_nid';
  $handler->display->display_options['arguments']['field_l_area_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_l_area_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_l_area_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_l_area_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_l_area_nid']['summary_options']['items_per_page'] = '25';
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

  $view = new view();
  $view->name = 'publications_archive';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Publications Archive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications Archive';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Publish Date */
  $handler->display->display_options['fields']['field_p_date']['id'] = 'field_p_date';
  $handler->display->display_options['fields']['field_p_date']['table'] = 'field_data_field_p_date';
  $handler->display->display_options['fields']['field_p_date']['field'] = 'field_p_date';
  $handler->display->display_options['fields']['field_p_date']['label'] = '';
  $handler->display->display_options['fields']['field_p_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_p_date']['settings'] = array(
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
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Field: Content: Publication File */
  $handler->display->display_options['fields']['field_p_file']['id'] = 'field_p_file';
  $handler->display->display_options['fields']['field_p_file']['table'] = 'field_data_field_p_file';
  $handler->display->display_options['fields']['field_p_file']['field'] = 'field_p_file';
  $handler->display->display_options['fields']['field_p_file']['label'] = '';
  $handler->display->display_options['fields']['field_p_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_p_file']['alter']['text'] = '<a href="[field_p_file]" target="_blank">Download [title] document ([filesize])</a>';
  $handler->display->display_options['fields']['field_p_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_p_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_p_file']['type'] = 'file_url_plain';
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_p_area']['id'] = 'field_p_area';
  $handler->display->display_options['fields']['field_p_area']['table'] = 'field_data_field_p_area';
  $handler->display->display_options['fields']['field_p_area']['field'] = 'field_p_area';
  $handler->display->display_options['fields']['field_p_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_p_area']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-9 no-padding-left-md">
<div class="views-field-title"><h2>[title]</h2></div>
<div class="date">[field_p_date] </div>
<div class="views-field-body">[body]</div>
<div class="read-more-block">[field_p_file]</div>
</div>
<div class="clearfix"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'publication' => 'publication',
  );
  /* Filter criterion: Area (field_p_area) (selective) */
  $handler->display->display_options['filters']['field_p_area_nid_selective']['id'] = 'field_p_area_nid_selective';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['table'] = 'field_data_field_p_area';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['field'] = 'field_p_area_nid_selective';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['ui_name'] = 'Area (field_p_area) (selective)';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_p_area_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['expose']['identifier'] = 'field_p_area_nid_selective';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_p_area_nid_selective']['selective_display_field'] = 'field_p_area';
  $handler->display->display_options['filters']['field_p_area_nid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Publish Date (field_p_date) */
  $handler->display->display_options['filters']['field_p_date_value']['id'] = 'field_p_date_value';
  $handler->display->display_options['filters']['field_p_date_value']['table'] = 'field_data_field_p_date';
  $handler->display->display_options['filters']['field_p_date_value']['field'] = 'field_p_date_value';
  $handler->display->display_options['filters']['field_p_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_p_date_value']['expose']['operator_id'] = 'field_p_date_value_op';
  $handler->display->display_options['filters']['field_p_date_value']['expose']['operator'] = 'field_p_date_value_op';
  $handler->display->display_options['filters']['field_p_date_value']['expose']['identifier'] = 'field_p_date_value';
  $handler->display->display_options['filters']['field_p_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_p_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_p_date_value']['year_range'] = '-0:2004';
  $handler->display->display_options['select_labels'] = array(
    'field_p_area_nid_selective' => 'Area',
    'field_p_date_value' => 'Publish Date',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'binformed/publications-archive';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publications Archive';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sector';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_p_area) */
  $handler->display->display_options['arguments']['field_p_area_nid']['id'] = 'field_p_area_nid';
  $handler->display->display_options['arguments']['field_p_area_nid']['table'] = 'field_data_field_p_area';
  $handler->display->display_options['arguments']['field_p_area_nid']['field'] = 'field_p_area_nid';
  $handler->display->display_options['arguments']['field_p_area_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_p_area_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_p_area_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_p_area_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_p_area_nid']['summary_options']['items_per_page'] = '25';
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
    'publication' => 'publication',
  );
  $export['publications_archive'] = $view;

  return $export;
}
