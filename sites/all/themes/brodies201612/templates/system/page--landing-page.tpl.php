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
?>
<?php
if (!empty($page['navigation_bg'])):
  // remove the header slideshow for this content type;
  if (!empty($page['navigation_bg']['views_slideshow-block_1'])) {
    unset($page['navigation_bg']['views_slideshow-block_1']);
  }
  if (isset($variables['page']['content']['system_main']['nodes'][$node->nid]['field_cta_text'])) {
    //$page['navigation_bg']['field_cta_text'] = $variables['page']['content']['system_main']['nodes'][$node->nid]['field_cta_text'];
    $header_cta = $variables['page']['content']['system_main']['nodes'][$node->nid]['field_cta_text'];
    unset($page['content']['system_main']['nodes'][$node->nid]['field_cta_text']);
  }
  if (isset($variables['page']['content']['system_main']['nodes'][$node->nid]['field_banner_image'])) {
    $background_img = image_style_url($variables['page']['content']['system_main']['nodes'][$node->nid]['field_banner_image'][0]['#image_style'], $variables['page']['content']['system_main']['nodes'][$node->nid]['field_banner_image'][0]['#item']['uri']);
    unset($page['content']['system_main']['nodes'][$node->nid]['field_banner_image']);
  }
  if (isset($variables['page']['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title'])) {
    $page['navigation_bg']['field_lp_cta_l_title'] = $variables['page']['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title'];
    unset($page['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title']);
  }
  if (isset($variables['page']['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title'])) {
    $page['navigation_bg']['field_lp_cta_l_title'] = $variables['page']['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title'];
    unset($page['content']['system_main']['nodes'][$node->nid]['field_lp_cta_l_title']);
  }
  if (isset($variables['page']['content']['system_main']['nodes'][$node->nid]['field_cta_link'])) {
    $cta_link = $variables['page']['content']['system_main']['nodes'][$node->nid]['field_cta_link'];
    unset($page['content']['system_main']['nodes'][$node->nid]['field_cta_link']);
  }
endif;
?>
<div class="navbar-wrapper">
    <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
        <div class="<?php print $container_class; ?>">
            <div class="navbar-header">
                <?php if ($logo): ?>
                  <a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                  </a>
                <?php endif;
                ?>
                <?php if (isset($header_cta['#items'][0]['safe_value'])): ?>
                  <div class="header-cta"><p><?php echo $header_cta['#items'][0]['safe_value']; ?></p></div>
                <?php endif; ?>
                <div class="search_block"><a href="/search"><i class="fa fa-search" aria-hidden="true"></i></a></div>
                <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
                  <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
                      <div class="menu-block"><?php print t('Menu'); ?></div>
                      <div class="menu-block"><span class="icon-bar"></span>
                          <span class="icon-bar"></span>
                          <span class="icon-bar"></span></div>
                  </button>
                <?php endif; ?>
            </div>
            <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
              <div class="navbar-collapse collapse" id="navbar-collapse">
                  <nav role="navigation">
                      <?php if (!empty($primary_nav)): ?>
                        <?php print render($primary_nav); ?>
                      <?php endif; ?>
                      <?php if (!empty($secondary_nav)): ?>
                        <?php print render($secondary_nav); ?>
                      <?php endif; ?>
                      <?php
                      if (!empty($page['navigation'])):
                        if (isset($page['navigation']['views_search-block'])) {
                          unset($page['navigation']['views_search-block']);
                        }
                        if (isset($page['navigation']['views_-exp-search-page'])) {
                          unset($page['navigation']['views_-exp-search-page']);
                        }
                        ?>
                        <?php print render($page['navigation']); ?>
                    </nav>
                  <?php endif; ?>
              </div>
            <?php endif; ?>

        </div>
    </header>
</div>
<?php if (!empty($page['navigation_bg'])): ?>
  <div class="navbar-background" style="background:url('<?php echo $background_img; ?>');">
      <div class="container">
          <div class="row">
              <div class="col-sm-12">
                  <?php
                  if ($title) {
                    print '<h1>' . $title . '</h1>';
                  }
                  ?>
                  <?php print render($page['navigation_bg']); ?>
                  <div class="header-cta-link"><?php
                      if (isset($cta_link['#items'][0]['safe_value'])):
                        ?><a href="#main-content"><?php
                            echo $cta_link['#items'][0]['safe_value'];
                            ?></a><?php endif;
                          ?><i class="fa fa-angle-double-down" aria-hidden="true"></i></div>
              </div>
          </div>
      </div>
  </div>
<?php endif; ?>
<a name="main-content" id="main-content-marker"></a>
<div class="main-container <?php print $container_class; ?>">
    <?php
    // remove subnavigation bar;
    if (!empty($page['header']['menu_block_3'])) {
      unset($page['header']['menu_block_3']);
    }
    ?>
    <?php if (!empty($page['header'])): ?>
      <header role="banner" id="page-header">
          <?php print render($page['header']); ?>
      </header> <!-- /#page-header -->
    <?php endif; ?>
    <div class="row">
        <section<?php print $content_column_class; ?>>
            <?php if (!empty($page['highlighted'])): ?>
              <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
            <?php endif; ?>
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
                <?php print render($page['content']); ?>
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
      <footer class="footer">

          <div class="footer-blue">
              <?php
              if (isset($page['navigation']['block_38'])) {
                print render($page['navigation']['block_38']);
              }
              if (!empty($page['footer']['block_8'])) {
                print render($page['footer']['block_8']);
              }
              ?>
          </div>
          <div class="footer-clear">
              <?php
              if (!empty($page['footer']['block_1'])) {
                print render($page['footer']['block_1']);
              }
              ?>
          </div>
      </footer>
  </div>
<?php endif; ?>
<?php
//if (isset($node->nid) && $node->nid == 13666) {
//  <script type="text/javascript">
//    var capterra_vkey = 'ec8cd8fc5f2e036509fd174bd7f963cb',
//            capterra_vid = '2109318',
//            capterra_prefix = (('https:' == document.location.protocol) ? 'https://ct.capterra.com' : 'http://ct.capterra.com');
//
//    (function () {
//        var ct = document.createElement('script');
//      ct.type = 'text/javascript';
//      ct.async = true;
//        ct.src = capterra_prefix + '/capterra_tracker.js?vid=' + capterra_vid + '&vkey=' + capterra_vkey;
//        var s = document.getElementsByTagName('script')[0];
//      s.parentNode.insertBefore(ct, s);
//    })();
//  </script>
//
//}
?>
