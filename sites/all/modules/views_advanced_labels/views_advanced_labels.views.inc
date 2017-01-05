<?php

/**
 * @file
 * Contains the Views integration for the Views Advanced Labels module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_advanced_labels_views_plugins() {
  $plugins['display_extender']['views_advanced_labels'] = array(
    'title' => t('Views Advanced Labels'),
    'handler' => 'views_advanced_labels_plugin_display_extender',
    'enabled' => TRUE,
  );

  return $plugins;
}
