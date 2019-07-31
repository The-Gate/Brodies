<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
// sort out the heading & title

$title_output = '';
$title_output .= '<a id="main-content"></a>';
$title_output .= render($title_prefix);

// set up titles and title icons
//$default_icon = FALSE;
// where in the template does this title appear: above / default
$title_postion = 'default';
// show title ONLY on mobile
$mobile_only = FALSE;
$mobile_only_class = ' visible-xs';
$show_breadcrumb_filler = TRUE;

if (isset($node)) {
  switch ($node->type) {
    // don't display the title on these content types;
    case 'homepage':
      if (!isset($node->field_show_title) or $node->field_show_title[LANGUAGE_NONE][0]['value'] == 0) {
        unset($title);
      }
      $show_breadcrumb_filler = FALSE;
      break;
    case 'overview':
      $mobile_only = TRUE;
      $show_breadcrumb_filler = FALSE;
      break;
    case 'news':
    case 'win':
      $customTitle = 'News';
      //      $default_icon = 'title-icon-default-news.png';
      break;
    //    case 'cs':
    //      $default_icon = 'title-icon-default-case-studies.png';
    //      break;
    //    case 'cnews':
    //      $default_icon = 'title-icon-default-news.png';
    //      break;
    case 'lupdate':
      $customTitle = 'Legal updates';
      //      $default_icon = 'title-icon-default-binformed.png';
      break;
    //    case 'publication':
    //    case 'video':
    //    case 'download':
    //      $default_icon = 'title-icon-default-binformed.png';
    //      break;
    case 'event':
      $customTitle = 'Seminars';
      //      $default_icon = 'title-icon-default-binformed.png';
      break;
    case 'larea':
      $title = 'Legal updates: ' . $title;
      break;
    //    case 'people':
    //      $default_icon = 'title-icon-default-people.png';
    //      break;
    case 'sector':
      $title_postion = 'above';
      //      $default_icon = 'title-icon-default-business-sectors.png';
      break;
    case 'service':
      //      $default_icon = 'title-icon-default-legal-services.png';
      $title_postion = 'above';
      break;
    default:
      // check fr page tempaltes in specific sections
      if (isset($node->nid)) {
        $this_menu_trail = menu_get_active_trail();
        if (is_array($this_menu_trail)) {
          $this_menu = end($this_menu_trail);
          $parent_id = ((int) $this_menu['p1'] > 0) ? $this_menu['p1'] : $this_menu['mlid'];
          if ($parent_id > 0) {
            switch ($parent_id) {
              // seminars / binformed
              //              case 248;
              //              case 1042;
              //                $default_icon = 'title-icon-default-binformed.png';
              //                break;
              // about us
              //              case 231;
              //                $default_icon = 'title-icon-default-about.png';
              //                break;
              // careers
              //              case 1004;
              //                $default_icon = 'title-icon-default-careers.png';
              //                break;
              // contact
              case 823;
                $show_breadcrumb_filler = FALSE;
                break;
            }
          }
        }
        //        switch ($node->nid) {
        //          // seminars homepage;
        //          case 44;
        //            $default_icon = 'title-icon-default-binformed.png';
        //            break;
        //        }
      }
      break;
  }
}
else {
  // views pages
  if (isset($theme_hook_suggestions)) {
    // people listing
    //    if (in_array('page__views__people_listing', $theme_hook_suggestions)) {
    //      $default_icon = 'title-icon-default-people.png';
    //    }
    // news
    //    if (in_array('page__views__top_news', $theme_hook_suggestions)) {
    //      $default_icon = 'title-icon-default-news.png';
    //    }
    // case study listing
    //    if (in_array('page__views__Case_Studies', $theme_hook_suggestions)) {
    //      $default_icon = 'title-icon-default-case-studies.png';
    //    }
    // binformed section
    //    if (in_array('page__views__videos', $theme_hook_suggestions) or
    //      in_array('page__views__latest_legal_update', $theme_hook_suggestions) or
    //      in_array('page__views__publications_archive', $theme_hook_suggestions) or
    //      in_array('page__views__guides_downloads', $theme_hook_suggestions)
    //    ) {
    //      $default_icon = 'title-icon-default-binformed.png';
    //    }
  }
}
$title_class = $mobile_only ? 'page-header' . $mobile_only_class : 'page-header';
if (isset($customTitle)) {
  $title_output .= '<h1 class="' . $title_class . '"><span class="text-wrapper">' . $customTitle . '</span></h1>';
}
elseif (!empty($title)) {
  $title_output .= '<h1 class="' . $title_class . '"><span class="text-wrapper">' . $title . '</span></h1>';
}
$title_output .= render($title_suffix);

//if (isset($node->field_title_icon['und'][0]['uri'])) {
//  $image = (object) $node->field_title_icon[LANGUAGE_NONE][0];
//  $image_entity = file_view($image, "page");
//  $title_output .= '<div class="title-icon">' . drupal_render($image_entity) . '</div>';
//}
//elseif (!($default_icon === false)) {
//  $title_output .= '<div class="title-icon"><img src="/' . drupal_get_path('theme', $GLOBALS['theme']) . '/images/title-icons/' . $default_icon . '"></div>';
//}
?>

<div class="navbar-wrapper">
  <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="<?php print $container_class; ?>">
      <div class="row">
        <div class="navbar-header col-xs-2">
          <a class="logo navbar-btn pull-left"
             href="<?php print $front_page; ?>"
             title="<?php print t('Home'); ?>">
            <svg version="1.1" xmlns="http://www.w3.org/2000/svg"
                 xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                 viewBox="0 0 437.9 356"
                 style="enable-background:new 0 0 437.9 356;"
                 xml:space="preserve">
                <style type="text/css">
                  .st0 {fill: none;}
                  .st1 {fill: #E5B439;}
                  .st2 {fill: #47B7A2;}
                  .st3 {fill: #598C41;}
                  .st4 {fill: #5CB5E1;}
                  .st5 {fill: #009995;}
                  .st6 {fill: #187944;}
                  .st7 {fill: #CC3388;}
                  .st8 {fill: #BA3130;}
                  .st9 {fill: #683639;}
                  .st10 {fill: #713585;}
                  .st11 {fill: #443860;}
                  .st12 {fill: #2A2B2B;}
                  .st13 {fill: #FFFFFF;}
                </style>
              <g id="Safe_Area">
                <rect class="st0" width="437.9" height="356"/>
              </g>
              <g id="Colour_Lenses">
                <g>
                  <path class="st1" d="M320.2,279.6c-29.9,20.6-63,26.3-95.7,22.1c-11.6,4.5-23.5,8.4-35.3,11c54.8,8,128.5,1.2,161.1-54.2	c-3.7,2.1-7.6,4-11.5,5.7C333.2,269.7,327,274.9,320.2,279.6z"/>
                  <path class="st1" d="M199.1,63.4c12.8-3.3,26.4-5.5,40.3-6.6c-11.4-5-22.5-9-32.7-11.9c-48.6-14.1-83.9,3-105.2,34.2 C129.1,67.7,164,62.4,199.1,63.4z"/>
                  <path class="st2" d="M136.3,293c-14-0.3-27.1-1.7-38.5-4.6c26.2,28,58.8,31.3,91.5,24.3c-2.6-0.4-5.2-0.8-7.7-1.2 C164.2,308.4,149.1,301.9,136.3,293z"/>
                  <path class="st2" d="M378.7,132.2c2.7,4.2,5.2,8.4,7.3,12.5c-2.9-14.7-10.3-30.3-23.9-46.7c-28.2-34.1-76.7-44.6-122.8-41.1 c12.6,5.5,25.5,12.1,38.1,19.9C318.3,82.2,357.1,98.8,378.7,132.2z"/>
                  <path class="st3" d="M276.1,76.5c0.4,0.1,0.9,0.1,1.3,0.2c-12.6-7.7-25.6-14.4-38.1-19.9c-13.8,1-27.5,3.3-40.3,6.6 C225.6,64.1,252.3,68.5,276.1,76.5z"/>
                  <path class="st3" d="M182.7,291.1c-15.8,1.4-31.6,2.3-46.5,1.9c12.9,8.9,27.9,15.4,45.2,18.4c2.5,0.4,5.1,0.9,7.7,1.2 c11.9-2.5,23.7-6.4,35.3-11C210.4,299.9,196.4,296.2,182.7,291.1z"/>
                  <path class="st4" d="M386,144.7c5,25.4-3.5,47.9-17.4,66.7c-1.6,7.3-4,14.4-7.3,21.2c-2.8,9.6-6.5,18.2-11,25.8 C389.3,236.9,414,198.3,386,144.7z"/>
                  <path class="st4" d="M69.8,205.4c-7.6-10.1-13.3-19.7-17.2-28.8c-18.4,31.2-20.2,66.5,18,99c7,5.9,16.3,10.1,27.1,12.8 c-3.2-3.4-6.4-7.2-9.4-11.5C72.2,254.4,67.3,229.7,69.8,205.4z"/>
                  <path class="st3" d="M338.8,264.2c4-1.8,7.8-3.7,11.5-5.7c4.5-7.7,8.2-16.2,11-25.8C356,244,348.4,254.6,338.8,264.2z"/>
                  <path class="st5" d="M277.5,76.7c0.3,0.2,0.7,0.4,1,0.6c27.5,9.6,50.9,24.3,65.4,44.2c23.6,28.6,31,60.5,24.7,89.9 c13.9-18.8,22.4-41.3,17.4-66.7c-2.1-4.1-4.5-8.2-7.3-12.5C357.1,98.8,318.3,82.2,277.5,76.7z"/>
                  <path class="st5" d="M87.8,226.5c-6.9-7.3-12.9-14.3-18-21.1c-2.5,24.3,2.4,49,18.5,71.5c3,4.2,6.2,8,9.4,11.5 c11.4,2.9,24.5,4.3,38.5,4.6C113.3,277.1,97.3,253.3,87.8,226.5z"/>
                  <path class="st6" d="M87.8,226.5c9.5,26.8,25.6,50.6,48.5,66.5c14.9,0.3,30.7-0.5,46.5-1.9c-33.8-12.8-65.4-34.6-90.3-59.8 C90.8,229.7,89.3,228.1,87.8,226.5z"/>
                  <path class="st4" d="M277.5,76.7c-0.4-0.1-0.9-0.1-1.3-0.2c0.8,0.3,1.6,0.5,2.4,0.8C278.2,77.1,277.8,76.9,277.5,76.7z"/>
                  <path class="st7" d="M101.5,79.1C57.9,97,32.4,129.8,52.6,176.6C59.4,165,68.5,154,78.7,144C81.5,119.8,89.1,97.1,101.5,79.1z"/>
                  <path class="st8" d="M273.8,279.1c-15.1,7.4-31.9,15.8-49.3,22.6c32.7,4.2,65.8-1.6,95.7-22.1c6.9-4.7,13.1-9.9,18.6-15.4 c-17,7.5-35.8,12.1-53.7,13.7C281.7,278.2,277.9,278.6,273.8,279.1z"/>
                  <path class="st8" d="M111.7,116.4c12.1-13.9,25.7-25.4,39.1-33.6c13.2-8,29.9-14.7,48.3-19.4c-35.1-1-70,4.3-97.6,15.7 c-12.3,18-19.9,40.7-22.8,64.9C89,133.7,100.4,124.4,111.7,116.4z"/>
                  <path class="st9" d="M182.7,291.1c13.7,5.2,27.7,8.8,41.8,10.6c17.4-6.8,34.2-15.2,49.3-22.6C250.7,282,216.8,288,182.7,291.1z"/>
                  <path class="st9" d="M276.1,76.5c-23.8-8-50.5-12.4-77-13.1c-18.4,4.7-35.1,11.4-48.3,19.4c-13.4,8.1-27,19.7-39.1,33.6 c16.2-11.5,32.2-20.4,44.3-25.7C185.6,77.9,232,70.8,276.1,76.5z"/>
                  <path class="st10" d="M77.6,172.7c-0.4-9.7,0-19.3,1.1-28.7C68.5,154,59.4,165,52.6,176.6c3.9,9.1,9.6,18.7,17.2,28.8 C71,194.3,73.7,183.3,77.6,172.7z"/>
                  <path class="st9" d="M364.8,216.3c-29.2,35.9-76.4,56.9-76.8,55.9c-4.5,2.1-9.3,4.5-14.2,6.9c4.1-0.5,7.8-0.9,11.2-1.2 c17.9-1.6,36.7-6.2,53.7-13.7c9.6-9.6,17.2-20.2,22.6-31.6c3.2-6.9,5.7-14,7.3-21.2C367.4,213.1,366.1,214.7,364.8,216.3z"/>
                  <path class="st9" d="M78.7,144c-1.1,9.4-1.5,19.1-1.1,28.7c7.7-20.7,19.9-40.1,34.1-56.3C100.4,124.4,89,133.7,78.7,144z"/>
                  <path class="st11" d="M69.8,205.4c5.1,6.8,11.1,13.9,18,21.1c-6.1-17.2-9.5-35.5-10.2-53.8C73.7,183.3,71,194.3,69.8,205.4z"/>
                  <path class="st12" d="M343.9,121.5c-14.5-19.9-38-34.6-65.4-44.2c-0.8-0.3-1.6-0.6-2.4-0.8C232,70.8,185.6,77.9,156,90.7 c-12.1,5.3-28.1,14.2-44.3,25.7c-14.2,16.2-26.4,35.6-34.1,56.3c0.7,18.3,4.1,36.7,10.2,53.8c1.5,1.6,3,3.2,4.6,4.8 c24.9,25.1,56.5,47,90.3,59.8c34.1-3.1,67.9-9,91.1-11.9c4.9-2.4,9.7-4.7,14.2-6.9c0.4,0.9,47.6-20,76.8-55.9 c1.3-1.6,2.6-3.2,3.8-4.9C375,182.1,367.5,150.2,343.9,121.5z"/>
                </g>
              </g>
              <g id="Type">
                <g>
                  <path class="st13" d="M357.5,169.7v-2.3h1.3c0.8,0,1.4,0.4,1.4,1.2v0c0,0.7-0.5,1.2-1.3,1.2H357.5z M355.9,173.4h1.7v-2.3h1.3 c1.7,0,3.1-0.9,3.1-2.7v0c0-1.6-1.1-2.6-2.9-2.6h-3.1V173.4z M349.1,173.4h5.5v-1.5h-3.8v-6.1h-1.7V173.4z M342.3,173.4h5.5v-1.5 H344v-6.1h-1.7V173.4z"/>
                  <g>
                    <path class="st13" d="M89.2,165.8h17.1c4.4,0,7.8,1.2,10,3.4c1.7,1.7,2.6,3.8,2.6,6.3v0.1c0,4.6-2.6,7-5.5,8.5 c4.5,1.5,7.6,4.1,7.6,9.3v0.1c0,6.8-5.6,10.5-14.1,10.5H89.2V165.8z M112.1,176.7c0-3-2.4-4.9-6.7-4.9h-9.7V182h9.2 c4.3,0,7.2-1.7,7.2-5.2V176.7z M106.4,187.6H95.8v10.5h11.1c4.6,0,7.4-1.8,7.4-5.2v-0.1C114.3,189.5,111.7,187.6,106.4,187.6z"/>
                    <path class="st13" d="M129,165.8h17c4.8,0,8.6,1.4,11,3.8c2,2.1,3.2,4.9,3.2,8.2v0.1c0,6.3-3.8,10-9.1,11.6l10.3,14.5h-8	l-9.4-13.3h-8.4v13.3H129V165.8z M145.6,184.8c4.8,0,7.9-2.5,7.9-6.4v-0.1c0-4.1-2.9-6.3-7.9-6.3h-9.8v12.8H145.6z"/>
                    <path class="st13" d="M166.2,185.1V185c0-10.9,8.4-20,20.2-20c11.9,0,20.1,9,20.1,19.9v0.1c0,10.9-8.4,20-20.2,20 S166.2,195.9,166.2,185.1z M199.5,185.1V185c0-7.5-5.5-13.7-13.1-13.7s-13,6.1-13,13.6v0.1c0,7.5,5.5,13.7,13.1,13.7 S199.5,192.6,199.5,185.1z"/>
                    <path class="st13" d="M214.9,165.8h14.2c12,0,20.3,8.2,20.3,19v0.1c0,10.8-8.3,19.1-20.3,19.1h-14.2V165.8z M221.6,172v26h7.5 c8,0,13.3-5.4,13.3-12.9V185c0-7.5-5.2-13-13.3-13H221.6z"/>
                    <path class="st13" d="M257.8,165.8h6.7v38.2h-6.7V165.8z"/>
                    <path class="st13" d="M274.7,165.8h28.3v6h-21.6v9.9h19.2v6h-19.2v10.3h21.9v6h-28.6V165.8z"/>
                    <path class="st13" d="M309,198.6l4-4.9c3.7,3.2,7.4,5,12.1,5c4.1,0,6.8-2,6.8-4.9v-0.1c0-2.8-1.5-4.2-8.6-5.9 c-8.1-2-12.7-4.4-12.7-11.5v-0.1c0-6.6,5.5-11.2,13-11.2c5.6,0,10,1.7,13.9,4.9l-3.6,5.1c-3.4-2.6-6.9-4-10.4-4 c-3.9,0-6.2,2-6.2,4.6v0.1c0,3,1.7,4.3,9.1,6.1c8.1,2,12.2,4.9,12.2,11.3v0.1c0,7.2-5.6,11.5-13.6,11.5 C319.1,204.8,313.6,202.8,309,198.6z"/>
                  </g>
                </g>
              </g>
            </svg>
          </a>
        </div>
        <div class="navbar-col-wrapper col-xs-10">
          <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
              <div class="menu-block text-menu"><?php print t('Menu'); ?></div>
              <div class="menu-block text-close"><?php print t('Close'); ?></div>
              <div class="menu-block">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="glyphicon glyphicon-remove"></span>
              </div>
            </button>
          <?php endif; ?>
          <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
            <div class="navbar-collapse collapse" id="navbar-collapse">
              <nav role="navigation">
                <?php if (!empty($primary_nav)): ?>
                  <?php print render($primary_nav); ?>
                <?php endif; ?>
                <?php if (!empty($secondary_nav)): ?>
                  <?php print render($secondary_nav); ?>
                <?php endif; ?>
                <?php if (!empty($page['navigation'])): ?>
                  <?php print render($page['navigation']); ?>
                <?php endif; ?>
              </nav>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </header>
  <?php if (!empty($site_slogan)): ?>
    <div id="slogan" class="clearfix">
      <div class="container">
        <div class="col-xs-6 col-md-2"><p><?php echo $site_slogan; ?></p></div>
      </div>
    </div>
  <?php endif; ?>

</div>

<?php if (!empty($page['navigation_bg'])): ?>
  <div class="navbar-background">
    <?php print render($page['navigation_bg']); ?>
  </div>
<?php endif; ?>
<div class="header-border"></div>
<div class="main-container <?php print $container_class; ?>">

  <header role="banner" id="page-header">
    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">
    <?php if ($title_postion == 'above') { ?>
      <div class="col-ms-12">
        <?php echo $title_output; ?>
        <?php
        if (!empty($breadcrumb)) {
          print $breadcrumb;
        }
        else {
          if ($show_breadcrumb_filler) {
            print '<div class="breadcrumb"></div>';
          }
        }
        ?>
      </div>
      <?php
    }
    ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div
          class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>


      <?php if ($title_postion == 'default') { ?>
        <?php echo $title_output; ?>
        <?php
        if (!empty($breadcrumb)) {
          print $breadcrumb;
        }
        else {
          if ($show_breadcrumb_filler) {
            print '<div class="breadcrumb"></div>';
          }
        }
        ?>
        <?php
      }
      ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>

      <?php print render($page['pre_content']); ?>
      <div class="clearfix"></div>
      <div class="main-content">
        <?php
        if (isset($customTitle)) {
          if ($title) {
            $title_class = "";
            if ($node->type == 'lupdate') {
              $title_class = ' class="section-header"';
            }
            print '<h2' . $title_class . '>' . $title . '</h2>';
          }
        }
        print render($page['content']);
        ?>
      </div>
    </section>
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside <?php print $sidebar_first_column_class; ?> role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>
    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-md-3 sidebar-second" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>


  </div>
</div>
<?php if (!empty($page['postscript'])): ?>
  <div class="postscript-wrapper">
    <div class="postscript-container <?php print $container_class; ?>">
      <div class="row">
        <aside class="col-sm-12" role="complementary">
          <?php print render($page['postscript']); ?>
        </aside>  <!-- /#postscript -->
      </div>
    </div>
  </div>
<?php endif; ?>
<?php if (!empty($page['footer'])): ?>
  <div class="footer-wrapper">
    <footer class="footer <?php print $container_class; ?>">
      <?php print render($page['footer']); ?>
    </footer>
  </div>
<?php endif; ?>
