<?php

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">' . implode(' › ', $breadcrumb) . '</div>';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function phptemplate_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();
  $vars['tabs'] = menu_primary_local_tasks();

  //header menu
  $controls = '';
  if (user_access('administer menu')) {
    $controls = '<div class="controls">' . l('Edit menu', 'admin/build/menu-customize/menu-header', array('query' => drupal_get_destination())) . '</div>';
  }
  $header_list = menu_navigation_links('menu-header', 0);
  $header_menu = $controls . str_replace(array('class="links"'), array(' '), theme('links', $header_list));
  $vars['main_menu'] = $header_menu;

  if (user_access('administer menu')) {
    $controls = '<div class="controls">' . l('Edit menu', 'admin/build/menu-customize/menu-sector', array('query' => drupal_get_destination())) . '</div>';
  }

  $header_list = menu_navigation_links('menu-sector', 0);
  $header_menu = $controls . str_replace(array('class="links"'), array(' '), theme('links', $header_list));
  $vars['stripe_menu'] = $header_menu;

  if (($vars['node']->type == 'service' || $vars['node']->type == 'sector') && isset($_GET['text-only'])) {
    $vars['closure'] .= '<div id="overlay"></div><div id="popup"><div class="content"><h1>' . $vars['node']->title . '</h1>' . db_result(db_query("SELECT {body} FROM {node_revisions} WHERE vid = %d", $vars['node']->vid)) . '</div><a class="close" href="' . url($_GET['q']) . '">&nbsp;</a></div>';
  }



  if (arg(0) == 'admin') {
    $vars['right'] = '';
  }

  if (isset($vars['node']) && $vars['node']->type == 'lpage' && !arg(2)) {
    // "page-lpage.tpl.php".
    $vars['template_files'][] = 'page-lpage';
  }
  else if (user_access('edit any slide content')) {
    $vars['header'] .= '<div class="controls slideshow">' . l(t('Edit slideshow'), 'content/edit/slide', array('query' => str_replace('destination', 'back', drupal_get_destination()))) . '</div>';
  }
  if (isset($vars['node']) && ($vars['node']->type == 'microsite_page' || $vars['node']->type == 'webform')) {
    if ($vars['node']->type == 'webform') {
      $mlid = db_result(db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $vars['node']->nid . "'"));
      if ($mlid > 0) {
        $vars['template_files'][] = 'page-microsite';
      }
    }
    else {
      // "page-microsite.tpl.php".
      $vars['template_files'][] = 'page-microsite';
    }
  }
}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function phptemplate_menu_local_tasks() {
  return menu_primary_local_tasks();
}

/**
 * Returns the themed submitted-by string for the comment.
 */
function phptemplate_comment_submitted($comment) {
  return t('!datetime — !username', array(
    '!username' => theme('username', $comment),
    '!datetime' => format_date($comment->timestamp)
  ));
}

/**
 * Returns the themed submitted-by string for the node.
 */
function phptemplate_node_submitted($node) {
  return t('!datetime — !username', array(
    '!username' => theme('username', $node),
    '!datetime' => format_date($node->created),
  ));
}

function phptemplate_preprocess_block(&$vars) {
  if ($vars['block']->module == 'block' && user_access('administer blocks')) {
    $vars['controls'] = '<div class="controls">' . l('Edit block', 'admin/build/block/configure/block/' . $vars['block']->delta, array('query' => drupal_get_destination())) . '</div>';
  }

  if ($vars['block']->module == 'menu') {
    if (user_access('administer menu')) {
      $vars['controls'] = '<div class="controls">' . l('Edit menu', 'admin/build/menu-customize/' . $vars['block']->delta, array('query' => drupal_get_destination())) . '</div>';
    }
  }
}

function brodies_form_element($element, $value) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  if ($element['#clear']) {
    return $value;
  }

  $output = '<div class="form-item"';
  if (!empty($element['#id'])) {
    $output .= ' id="' . $element['#id'] . '-wrapper"';
  }
  $output .= ">\n";

  $required = !empty($element['#required']) || !empty($element['#extra_required']) ? '<span class="form-required" title="' . $t('This field is required.') . '">*</span>' : '';

  $req_text = !$element['#err_left'] ? '!title' . ($element['#no-colon'] ? '' : ':') . ' !required' : '!required !title' . ($element['#no-colon'] ? '' : ':');

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="' . $element['#id'] . '">' . $t($req_text, array('!title' => filter_xss_admin($title), '!required' => $required)) . "</label>\n";
    }
    else {
      $output .= ' <label>' . $t($req_text, array('!title' => filter_xss_admin($title), '!required' => $required)) . "</label>\n";
    }
  }

  if ($element['#pre_label']) {
    $output .= '<label for="' . $element['#id'] . '" class="pre">' . $element['#pre_label'] . '</label>';
  }

  $output .= " $value\n";

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">' . $element['#description'] . "</div>\n";
  }

  if ($element['#extra_suffix']) {
    $output .= $element['#extra_suffix'];
  }

  if ($element['#inline_error']) {
    $error_message = form_get_error($element);
    if ($error_message) {
      $error_id = array_search($error_message, $_SESSION['messages']['error']);

      unset($_SESSION['messages']['error'][$error_id]);
      $_SESSION['messages']['error'] = array_values($_SESSION['messages']['error']);
      if (count($_SESSION['messages']['error']) <= 0) {
        $_SESSION['messages']['error'][0] = $element['#inline_error'];
      }
    }

    $extra_label = '';
    if ($element['#suffix_label']) {
      $extra_label = $element['#suffix_label'];
      unset($element['#suffix_label']);
    }

    $output .= '<div class="inline-errors">' . ($error_message ? '<div class="error-message">' . $error_message . '</div>' : '') . $extra_label . '</div>';
  }

  if ($element['#suffix_label']) {
    $output .= '<div class="suf_label">' . $element['#suffix_label'] . '</div>';
  }

  if ($element['#clearfix']) {
    $output .= '<div class="ff"></div>';
  }

  $output .= "</div>\n";

  return $output;
}
