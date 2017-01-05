<?php

/**
 * @file
 * Contains views_advanced_labels_plugin_display_extender.
 */

/**
 * Adds advanced label options to all displays.
 */
class views_advanced_labels_plugin_display_extender extends views_plugin_display_extender {

  /**
   * {@inheritdoc}
   */
  public function options_definition_alter(&$options) {
    $options['label_rewrites'] = array(
      'default' => array(),
      'unpack_translatable' => 'unpack_translatable_field_options',
    );
    $options['select_labels'] = array(
      'default' => array(),
      'translatable' => TRUE,
    );
  }

  /**
   * Extracts translatable strings from the "label_rewrites" option.
   *
   * Set as an "unpack_translatable" callback in options_definition_alter().
   */
  public function unpack_translatable_field_options(&$translatable, $storage, $option, $definition, $parents, $keys = array()) {
    foreach ($storage[$option] as $field_id => $rewrite) {
      $translatable[] = array(
        'value' => $rewrite['text'],
        'keys' => array_merge($keys, array($field_id, 'text')),
        'format' => NULL,
      );
    }
  }

}
