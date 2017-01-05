<?php
/**
 * @file
 * ct_microsites.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ct_microsites_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-microsites.
  $menus['menu-microsites'] = array(
    'menu_name' => 'menu-microsites',
    'title' => 'Microsites',
    'description' => 'top level will hold each microsite.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Microsites');
  t('top level will hold each microsite.');

  return $menus;
}
