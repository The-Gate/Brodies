<?php

/**
 * @file
 * The primary PHP file for this theme.
 */
function brodies201612_preprocess_html(&$variables) {
  $node = menu_get_object();
  if ($node && $node->type) {
    if ($node->type == 'webform') {
      $mlid = db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $node->nid . "'")->fetchField();
      if ($mlid > 0) {
        $variables['theme_hook_suggestions'][] = 'html__microsite_page';
      }
    }
    elseif ($node->type == 'microsite_page') {
      // "page-microsite.tpl.php".
      $variables['theme_hook_suggestions'][] = 'html__microsite_page';
    }
  }
}

function brodies201612_process_page(&$variables) {
  if (isset($variables['node']) && ($variables['node']->type == 'microsite_page' || $variables['node']->type == 'webform')) {
    if ($variables['node']->type == 'webform') {
      $mlid = db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $variables['node']->nid . "'")->fetchField();
      if ($mlid > 0) {
        $variables['theme_hook_suggestions'][] = 'page__microsite_page';
      }
    }
    else {
      // "page-microsite.tpl.php".
      $variables['theme_hook_suggestions'][] = 'page__microsite_page';
    }
  }
}

// remove the boostrap dropdown menu
function brodies201612_menu_link__menu_block($variables) {
  $keep_bootstrap_array = array('menu_link__menu_block__3');
  if (in_array($variables['element']['#theme'][0], $keep_bootstrap_array)) {
    return brodies201612_bootstrap_menu_link($variables);
  }
  else {
    return theme_menu_link($variables);
  }
}

function brodies201612_bootstrap_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  $title = $element['#title'];
  $href = $element['#href'];
  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<a class="dropdown-caret dropdown-toggle" data-toggle="dropdown"><b class="caret"></b></a><ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

      // Generate as standard dropdown.
      $title .= ' ';
      $attributes['class'][] = 'dropdown';

      $options['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      //$options['attributes']['data-target'] = '#';
      $options['attributes']['class'][] = 'dropdown-li';
      //$options['attributes']['class'][] = 'dropdown-toggle';
      //$options['attributes']['data-toggle'] = 'dropdown';
    }
  }

  // Filter the title if the "html" is set, otherwise l() will automatically
  // sanitize using check_plain(), so no need to call that here.
  if (!empty($options['html'])) {
    $title = _bootstrap_filter_xss($title);
  }

  return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options) . $sub_menu . "</li>\n";
}
