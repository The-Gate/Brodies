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
if (isset($node)) {
  switch ($node->type) {
    // don't display the title on these content types;
    case 'graduate_homepage':
      unset($title);
      break;
    //    case 'webform':
    //      if (isset($node->field_require_login_['und'][0]['value']) and $node->field_require_login_['und'][0]['value'] == '1') {
    //        global $user;
    //        if ($user->uid == 0) {
    //         $page['content'] =  l("Login","user/login",array('query' => drupal_get_destination()));;
    //        }
    //      }
    //      break;
  }
  switch ($node->nid) {
    // don't display the title on these content types;
    case '9678':
      unset($title);
      break;
  }
}
$multi_col_text_class = '';
if (!empty($node) and !empty($node->field_2_column_text['und'][0]['value'])) {
  $multi_col_text_class = ' multi_col_text ';
}
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
            <button type="button" class="navbar-toggle" data-toggle="collapse"
                    data-target="#navbar-collapse">
              <div class="menu-block text-menu"><?php print t('Menu'); ?></div>
              <div
                class="menu-block text-close"><?php print t('Close'); ?></div>
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
<div class="header-border"></div>
<div
  class="main-container <?php print $container_class; ?><?php echo $multi_col_text_class; ?>">

  <header role="banner" id="page-header">
    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-4 sidebar-first" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div
          class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
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
        print render($page['content']);
        ?>
      </div>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-4 sidebar-second" role="complementary">
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
