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
    return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function phptemplate_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();
  $vars['tabs'] = menu_primary_local_tasks();
  $vars['section'] = 'default';
  if ($_REQUEST['q']) {
    $path = explode('/', $_REQUEST['q']);
    $vars['section'] = !$path[1]?$path[0]:$path[0] .'-sub';
  }
  
  //header menu
  
  $header_list = menu_navigation_links('menu-mobile-top', 0);    
  foreach ($header_list as $class => $link_data) {    
    if ($link_data['title'] != '<break>') {
      $keys = array_keys($header_list);
      $current = array_search($class, $keys);
      if ($current !== FALSE && $keys[$current + 1]) {        
        if ($header_list[$keys[$current + 1]]['title'] == '<break>') {
          $break = ' margin-bottom';
        }
      }
      
      $header_menu .= '<li class="'. $class . $break .'">'. l($link_data['title'], $link_data['href'], array('attributes' => (strpos($link_data['href'], 'http://') !== FALSE ? array('target' => '_blank') : NULL))) .'</li>';
      $break = '';
    }
    else {
      $break = ' margin-top';
    }
  }
   
  $vars['mobile_top_menu'] = '<span>Menu</span> <ul>'. $header_menu .'</ul>';  
  
  /*
  
  $header_list = menu_navigation_links('menu-header', 0);
  $header_menu = $controls . str_replace(array('class="links"'), array(' '), theme('links', $header_list));  
  $vars['main_menu'] = $header_menu;    
 
  if (user_access('administer menu')) {
    $controls = '<div class="controls">'. l('Edit menu', 'admin/build/menu-customize/menu-sector', array('query' => drupal_get_destination())) .'</div>';
  }
  
  $header_list = menu_navigation_links('menu-sector', 0);
  $header_menu = $controls . str_replace(array('class="links"'), array(' '), theme('links', $header_list));  
  $vars['stripe_menu'] = $header_menu;
  */      
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
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $comment),
      '!datetime' => format_date($comment->timestamp)
    ));
}

/**
 * Returns the themed submitted-by string for the node.
 */
function phptemplate_node_submitted($node) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created),
    ));
}

function phptemplate_preprocess_block(&$vars) {   
  if ($vars['block']->module == 'block' && user_access('administer blocks')) {           
    $vars['controls'] = '<div class="controls">'. l('Edit block', 'admin/build/block/configure/block/'. $vars['block']->delta, array('query' => drupal_get_destination())) .'</div>';
  }
  
  if ($vars['block']->module == 'menu') {
    if (user_access('administer menu')) {                 
      $vars['controls'] = '<div class="controls">'. l('Edit menu', 'admin/build/menu-customize/'. $vars['block']->delta, array('query' => drupal_get_destination())) .'</div>';
    }
  }
}

