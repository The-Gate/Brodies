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
             title="<?php print t('Home'); ?>"><img src="/sites/all/themes/brodies201612/images/header-logo.jpg" class="img-responsive" /></a>
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
        <div class="col-xs-6"><p><?php echo $site_slogan; ?></p></div>
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
