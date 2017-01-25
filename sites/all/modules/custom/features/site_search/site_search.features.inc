<?php
/**
 * @file
 * site_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function site_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function site_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : null,
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  $items['limited_type_index'] = entity_import('search_api_index', '{
    "name" : "Limited Type Index",
    "machine_name" : "limited_type_index",
    "description" : null,
    "server" : "database_search",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_d_date" : { "type" : "date" },
        "field_date" : { "type" : "date" },
        "field_event_guest" : { "type" : "text", "boost" : "0.3" },
        "field_event_l_details" : { "type" : "text", "boost" : "0.2" },
        "field_event_location" : { "type" : "integer", "entity_type" : "node" },
        "field_event_speakers" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_event_type" : { "type" : "text", "boost" : "0.2" },
        "field_l_area" : { "type" : "integer", "entity_type" : "node" },
        "field_l_date" : { "type" : "date" },
        "field_l_left" : { "type" : "text", "boost" : "0.5" },
        "field_lp_cta_l_text" : { "type" : "text", "boost" : "0.2" },
        "field_lp_cta_l_title" : { "type" : "text", "boost" : "0.2" },
        "field_lp_cta_r_text" : { "type" : "text", "boost" : "0.2" },
        "field_lp_cta_r_title" : { "type" : "text", "boost" : "0.2" },
        "field_news_category" : { "type" : "integer", "entity_type" : "node" },
        "field_p_area" : { "type" : "integer", "entity_type" : "node" },
        "field_p_date" : { "type" : "date" },
        "field_p_v_text_1" : { "type" : "text", "boost" : "0.2" },
        "field_p_v_text_2" : { "type" : "text", "boost" : "0.2" },
        "field_p_v_text_3" : { "type" : "text", "boost" : "0.2" },
        "field_p_v_text_4" : { "type" : "text", "boost" : "0.2" },
        "field_people_fname" : { "type" : "text" },
        "field_people_job" : { "type" : "text" },
        "field_people_location" : { "type" : "integer", "entity_type" : "node" },
        "field_people_sname" : { "type" : "text", "boost" : "2.0" },
        "field_sector_teaser" : { "type" : "text", "boost" : "0.8" },
        "field_service_teaser" : { "type" : "text", "boost" : "0.8" },
        "field_w_date" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "taxonomy_vocabulary_1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "taxonomy_vocabulary_3" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "title" : { "type" : "text", "boost" : "5.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "application" : "application",
              "asub" : "asub",
              "call_to_action" : "call_to_action",
              "hidden" : "hidden",
              "payment" : "payment",
              "slide" : "slide"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_event_guest" : true,
              "field_event_type" : true,
              "field_event_l_details" : true,
              "field_l_left" : true,
              "field_people_fname" : true,
              "field_people_job" : true,
              "field_people_sname" : true,
              "field_sector_teaser" : true,
              "field_service_teaser" : true,
              "field_p_v_text_1" : true,
              "field_p_v_text_2" : true,
              "field_p_v_text_3" : true,
              "field_p_v_text_4" : true,
              "field_lp_cta_l_title" : true,
              "field_lp_cta_l_text" : true,
              "field_lp_cta_r_title" : true,
              "field_lp_cta_r_text" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_event_guest" : true,
              "field_event_type" : true,
              "field_event_l_details" : true,
              "field_l_left" : true,
              "field_people_fname" : true,
              "field_people_job" : true,
              "field_people_sname" : true,
              "field_sector_teaser" : true,
              "field_service_teaser" : true,
              "field_p_v_text_1" : true,
              "field_p_v_text_2" : true,
              "field_p_v_text_3" : true,
              "field_p_v_text_4" : true,
              "field_lp_cta_l_title" : true,
              "field_lp_cta_l_text" : true,
              "field_lp_cta_r_title" : true,
              "field_lp_cta_r_text" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "field_event_guest" : true,
              "field_event_type" : true,
              "field_event_l_details" : true,
              "field_l_left" : true,
              "field_people_fname" : true,
              "field_people_job" : true,
              "field_people_sname" : true,
              "field_sector_teaser" : true,
              "field_service_teaser" : true,
              "field_p_v_text_1" : true,
              "field_p_v_text_2" : true,
              "field_p_v_text_3" : true,
              "field_p_v_text_4" : true,
              "field_lp_cta_l_title" : true,
              "field_lp_cta_l_text" : true,
              "field_lp_cta_r_title" : true,
              "field_lp_cta_r_text" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_event_guest" : true,
              "field_event_type" : true,
              "field_event_l_details" : true,
              "field_l_left" : true,
              "field_people_fname" : true,
              "field_people_job" : true,
              "field_people_sname" : true,
              "field_sector_teaser" : true,
              "field_service_teaser" : true,
              "field_p_v_text_1" : true,
              "field_p_v_text_2" : true,
              "field_p_v_text_3" : true,
              "field_p_v_text_4" : true,
              "field_lp_cta_l_title" : true,
              "field_lp_cta_l_text" : true,
              "field_lp_cta_r_title" : true,
              "field_lp_cta_r_text" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_event_guest" : true,
              "field_event_type" : true,
              "field_event_l_details" : true,
              "field_l_left" : true,
              "field_people_fname" : true,
              "field_people_job" : true,
              "field_people_sname" : true,
              "field_sector_teaser" : true,
              "field_service_teaser" : true,
              "field_p_v_text_1" : true,
              "field_p_v_text_2" : true,
              "field_p_v_text_3" : true,
              "field_p_v_text_4" : true,
              "field_lp_cta_l_title" : true,
              "field_lp_cta_l_text" : true,
              "field_lp_cta_r_title" : true,
              "field_lp_cta_r_text" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function site_search_default_search_api_server() {
  $items = array();
  $items['database_search'] = entity_import('search_api_server', '{
    "name" : "Database Search",
    "machine_name" : "database_search",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : { "limited_type_index" : {
          "nid" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "taxonomy_vocabulary_3" : {
            "table" : "search_api_db_limited_type_index_taxonomy_vocabulary_3",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_d_date" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_d_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "taxonomy_vocabulary_1" : {
            "table" : "search_api_db_limited_type_index_taxonomy_vocabulary_1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_date" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_news_category" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_news_category",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_event_guest" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.3"
          },
          "field_event_location" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_event_location",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_event_speakers" : {
            "table" : "search_api_db_limited_type_index_field_event_speakers",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_event_type" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_event_l_details" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_l_area" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_l_area",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_l_date" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_l_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_l_left" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_people_fname" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_people_job" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_people_location" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_people_location",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_people_sname" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "2.0"
          },
          "field_p_area" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_p_area",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_p_date" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_p_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_sector_teaser" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.8"
          },
          "field_service_teaser" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.8"
          },
          "field_p_v_text_1" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_p_v_text_2" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_p_v_text_3" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_p_v_text_4" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_w_date" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "field_w_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_lp_cta_l_title" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_lp_cta_l_text" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_lp_cta_r_title" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "field_lp_cta_r_text" : {
            "table" : "search_api_db_limited_type_index_text",
            "type" : "text",
            "boost" : "0.2"
          },
          "search_api_language" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_limited_type_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_limited_type_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
