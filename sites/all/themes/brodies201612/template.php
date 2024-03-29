<?php

/**
 * @file
 * The primary PHP file for this theme.
 */
function brodies201612_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Montserrat:400,600,700&display=swap&subset=latin-ext', ['type' => 'external']);
  // slick can potentially appear on any page
  drupal_add_css('sites/all/libraries/slick/slick/slick.css', ['type' => 'file']);
  drupal_add_css('sites/all/libraries/slick/slick/slick-theme.css', ['type' => 'file']);
  drupal_add_js('sites/all/libraries/slick/slick/slick.min.js', ['weight' => 5]);
  drupal_add_css('sites/all/libraries/font-awesome/css/font-awesome.min.css', ['type' => 'file']);
  drupal_add_js('//cdn.jsdelivr.net/youtube-google-analytics/8.0.2/lunametrics-youtube.gtm.min.js', [
    'type' => 'external',
    'scope' => 'header',
    'weight' => 5000,
  ]);
  //drupal_add_js('sites/all/themes/brodies201612/js/lunametrics-youtube.gtm.js',array('type' => 'file'));
  $node = menu_get_object();
  if ($node && $node->type) {
    switch ($node->type) {
      case 'webform':
        $result = db_query("select plid,menu_name from {menu_links} where link_path = 'node/" . $node->nid . "'")->fetchAll();
        if (isset($result[0]->plid)) {
          switch ($result[0]->menu_name) {
            case 'menu-microsites':
              $variables['theme_hook_suggestions'][] = 'html__microsite_page';
              break;
            case 'menu-graduate-main-menu':

              $variables['classes_array'][] = "page-graduate";
              break;
          }
        }

        break;
      case 'microsite_page':
        // "page-microsite.tpl.php".
        $variables['theme_hook_suggestions'][] = 'html__microsite_page';
        break;
      case 'lpage':
      case 'lpagef':
        $variables['classes_array'][] = "page-landing";
        break;
      case 'graduate_homepage':
      case 'graduate_content':
        $variables['classes_array'][] = "page-graduate";
        break;
      case 'landing_page':
        drupal_add_css('sites/all/themes/brodies201612/css/landing-page-overrides.css', [
          'group' => CSS_THEME,
          'type' => 'file',
          'weight' => 500,
        ]);
        break;
    }
  }
}

function brodies201612_process_page(&$variables) {
  $col_double = 'col-md-6 col-md-push-3';
  if (!empty($variables['page']['sidebar_first'])) {
    $col_single = 'col-md-9 col-md-push-3';
  }
  else {
    $col_single = 'col-md-9';
  }
  if (isset($variables['node'])) {
    switch ($variables['node']->type) {
      case 'microsite_page':
        $variables['theme_hook_suggestions'][] = 'page__microsite_page';
        break;
      case 'webform':
        $result = db_query("select plid,menu_name from {menu_links} where link_path = 'node/" . $variables['node']->nid . "'")->fetchAll();
        if (isset($result[0]->plid)) {
          switch ($result[0]->menu_name) {
            case 'menu-microsites':
              $variables['theme_hook_suggestions'][] = 'page__microsite_page';
              break;
            case 'menu-graduate-main-menu':

              $col_double = 'col-md-4';
              $col_single = 'col-md-8';
              $variables['theme_hook_suggestions'][] = 'page__graduate';
              break;
          }
        }
        else {
          $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
        }

        break;

      case 'graduate_homepage':
      case 'graduate_content':

        $col_double = 'col-md-4';
        $col_single = 'col-md-8';
        $variables['theme_hook_suggestions'][] = 'page__graduate';


      default:
        $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
        break;
    }


    //    if (($variables['node']->type == 'microsite_page' || $variables['node']->type == 'webform')) {
    //      if ($variables['node']->type == 'webform') {
    //        $mlid = db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $variables['node']->nid . "'")->fetchField();
    //        if ($mlid > 0) {
    //          $variables['theme_hook_suggestions'][] = 'page__microsite_page';
    //        }
    //      }
    //      else {
    //        // "page-microsite.tpl.php".
    //        $variables['theme_hook_suggestions'][] = 'page__microsite_page';
    //      }
    //    }
    //    else {
    //      $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    //    }
  }
  elseif ($the_view = views_get_page_view()) {
    if (isset($the_view->name)) {
      $variables['theme_hook_suggestions'][] = 'page__views__' . $the_view->name;
    }
  }


  // if there is a left column, remove the gap between them
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="' . $col_double . ' no-padding-left-md no-padding-right-md"';
    $variables['sidebar_first_column_class'] = ' class="col-md-3 sidebar-first col-md-pull-6"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="' . $col_single . ' no-padding-left-md"';
    $variables['sidebar_first_column_class'] = ' class="col-md-3 sidebar-first col-md-pull-9"';
  }


  $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
}

function brodies201612_preprocess_node(&$variables) {
  if ($variables['node'] && $variables['node']->type) {
    switch ($variables['node']->type) {
      case 'service':
      case 'sector':
        // add inline video to content
        // replace {video} string
        //check videos inline
        if (!$variables['teaser']) {
          // teasers get caught up in this - only put video in full page 
          $videos_html = '';
          for ($i = 1; $i < 5; $i++) {
            if (isset($variables['node']->{'field_p_v_image_' . $i}['und'][0]['uri']) && isset($variables['node']->{'field_p_v_text_' . $i}['und'][0]['value']) && isset($variables['node']->{'field_p_v_url_' . $i}['und'][0]['value'])) {
              $vdata = br_get_video_data($variables['node']->{'field_p_v_url_' . $i}['und'][0]['value']);
              $videos_html .= '<div class="col-md-3 col-sm-6 ivideo video-' . $i . '"><a class="vi" href="' . $variables['node']->{'field_p_v_url_' . $i}['und'][0]['value'] . '"><span class="video" style="display:none;">' . drupal_json_encode(['video' => $vdata['embed']]) . '</span><img class="img-responsive" src="' . image_style_url('col-3--lg', $variables['node']->{'field_p_v_image_' . $i}['und'][0]['uri']) . '"><p>' . $variables['node']->{'field_p_v_text_' . $i}['und'][0]['value'] . '</p><span class="view">PLAY VIDEO</span></a></div>';
            }
          }
          if ($videos_html) {
            $videos_html = '<div class="videos">' . $videos_html . '<div class="clearfix"></div></div>';
          }
          $variables['content']['body'][0]['#markup'] = str_replace('{videos}', $videos_html, $variables['content']['body'][0]['#markup']);
        }
        break;
      case 'video':
        if (!$variables['teaser']) {
          $vdata = br_get_video_data($variables['field_video_url'][0]['safe_value']);
          $videos_html = '<a class="vi" href="' . $variables['field_video_url'][0]['safe_value'] . '"><span class="video" style="display:none;">' . drupal_json_encode(['video' => $vdata['embed']]) . '</span><img class="img-responsive" src="' . image_style_url('col-3--lg', $variables['field_teaser_image'][0]['uri']) . '"></a></div>';
          $variables['content']['body'][0]['#markup'] = '<div class="col-md-9">' . $variables['content']['body'][0]['#markup'] . '</div><div class="col-md-3">' . $videos_html . '</div>';
          $variables['content']['field_video_url'][0]['#markup'] = '';
          $variables['content']['field_teaser_image'] = '';
        }
        break;
    }
  }
}

// remove the boostrap dropdown menu
function brodies201612_menu_link__menu_block($variables) {
  $keep_bootstrap_array = [
    'menu_link__menu_block__3',
    'menu_link__menu_block__10',
    'menu_link__menu_block__11',
    'menu_link__menu_block__12',
  ];
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
  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : [];
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : [];

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

function br_get_video_data($url, $thumbnail = FALSE) {
  if (strpos($url, 'vimeo') !== FALSE) {
    $vid = substr($url, strrpos($url, '/') + 1);
    if (!$thumbnail) {
      $hash = unserialize(file_get_contents("//vimeo.com/api/v2/video/$vid.php"));
      $thumbnail = $hash[0]['thumbnail_large'];
    }
    $embed = '<iframe src="//player.vimeo.com/video/' . $vid . '" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
  }
  else {
    if (strpos($url, 'youtube') !== FALSE) {
      $vid = substr($url, strrpos($url, '?v=') + 3);
      if (!$thumbnail) {
        $thumbnail = '//img.youtube.com/vi/' . $vid . '/hqdefault.jpg';
      }
      $embed = '<iframe src="//www.youtube.com/embed/' . $vid . '?wmode=opaque&autoplay=1&rel=0" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
    }
  }

  if ($vid) {
    return ['vid' => $vid, 'thumbnail' => $thumbnail, 'embed' => $embed];
  }
  return FALSE;
}

/**
 * the homepage filed collection needs the top level wrapper removed to allow
 * for content defined width;
 *
 * @param type $variables
 *
 * @return type
 */
function brodies201612_field_collection_view($variables) {
  $element = $variables['element'];
  return $element['#children'];
}

function brodies201612_form_alter(&$form, &$form_state, $form_id) {

  if ($form_id == 'views_exposed_form') {
    $view = $form_state['view'];
    if ($view->name == 'search') {
      $form['submit']['#value'] = '<i class="fa fa-search" aria-hidden="true"></i>';
    }
  }

}


function brodies201612_form_webform_client_form_alter(&$form, &$form_state, $form_id) {
  $form['#attributes'] = ['OnSubmit' => 'customGAIntegration();'];
  $js = "
    function customGAIntegration(){
      if (jQuery('.node-type-landing-page').length >0){
        if (typeof ga === 'function') {
          ga('send', {
            hitType: 'event',
            eventCategory: 'Form',
            eventAction: 'submit',
            eventLabel: '" . $form['#node']->title . "'
          });
        }
      }
    }";
  drupal_add_js($js, [
    'type' => 'inline',
    'scope' => 'header',
    'weight' => 5000,
  ]);
}

// provide location template name options.
function brodies201612_preprocess_location(&$variables) {
  $query = db_select('location_instance', 'n');
  $nid_field = $query->addField('n', 'nid');
  $query->condition('lid', $variables['location']['lid']);
  $result = $query->execute();
  foreach ($result as $n) {
    $node = node_load($n->nid);
    $variables['theme_hook_suggestions'][] = 'location__node__' . $node->type;
    $variables['theme_hook_suggestions'][] = 'location__node_' . $n->nid;
  }
}
