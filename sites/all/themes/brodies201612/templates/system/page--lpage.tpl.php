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
$landingBGOpen = $landingBGClose = null;
// landing pages have a custom background set up
if (isset($node->field_lp_bkg_image)) {
  $landingBGOpen = '<div id ="landing-background" class="landing-background clearfix" style="background-image:url(\'' . file_create_url($node->field_lp_bkg_image[LANGUAGE_NONE][0]['uri']) . '\')">';
  $landingBGClose = '</div>';
}
?>

<?php if (isset($node->field_lp_h_style)) : ?>
  <div class="nav-bar-wrapper-outer" style="<?php print $node->field_lp_h_style[LANGUAGE_NONE][0]['value']; ?>">
    <?php endif; ?>
    <?php if (isset($node->field_lp_h_image)) : ?>
      <div class="nav-bar-wrapper" style="<?php print 'background-image:url(\'' . file_create_url($node->field_lp_h_image[LANGUAGE_NONE][0]['uri']) . '\')'; ?>">
        <?php endif; ?>
        <div class="navbar-wrapper">
            <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
                <div class="<?php print $container_class; ?>">

                    <div class="navbar-header">
                        <?php if ($logo): ?>
                          <div class="logo-wrapper-mobile">
                              <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                                  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                              </a>
                          </div>
                        <?php endif; ?>

                        <?php if (!empty($site_name)): ?>
                          <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
                        <?php endif; ?>

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
                              <?php if (!empty($page['navigation'])): ?>
                                <?php print render($page['navigation']); ?>
                              <?php endif; ?>
                          </nav>
                      </div>
                    <?php endif; ?>
                    <?php if ($logo): ?>
                      <div class="logo-wrapper-desktop">
                          <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                          </a>
                      </div>
                    <?php endif; ?>
                    <?php
                    if ($title) {
                      if (isset($node->field_lp_title_img[LANGUAGE_NONE][0]['uri'])) {
                        print '<h1 class="page-header"><img src="' . file_create_url($node->field_lp_title_img[LANGUAGE_NONE][0]['uri']) . '" alt="' . $title . '"></h1>';
                      }
                      else {
                        print '<h1 class="page-header">' . $title . '</h1>';
                      }
                    }
                    ?>
                </div>
            </header>
        </div>
        <?php if (isset($node->field_lp_h_image)) : ?>
      </div>
    <?php endif; ?>
    <?php if (isset($node->field_lp_h_style)) : ?>
  </div>
<?php endif; ?>
<?php if (isset($landingBGOpen)): ?>
  <?php print $landingBGOpen; ?>
<?php endif; ?>
<div class="main-container <?php print $container_class; ?>">

    <header role="banner" id="page-header">
        <div id="slogan" class="clearfix"><span></span></div>
        <?php print render($page['header']); ?>
    </header> <!-- /#page-header -->

    <div class="row">

        <?php if (!empty($page['sidebar_first'])): ?>
          <aside class="col-sm-3" role="complementary">
              <?php print render($page['sidebar_first']); ?>
          </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>

        <section<?php print $content_column_class; ?>>
            <?php if (!empty($page['highlighted'])): ?>
              <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
            <?php endif; ?>
            <a id="main-content"></a>

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
            <div class="col-md-6 col-left">
                <div class="text-wrapper">
                    <?php
                    print render($page['content']);
                    ?>
                </div>
            </div>
            <div class="col-md-6 col-right"><?php
                $vdata = br_get_video_data($node->field_lp_v_link[LANGUAGE_NONE][0]['value']);
                $video = '<a href="' . $node->field_lp_v_link[LANGUAGE_NONE][0]['value'] . '" class="vi"><span class="video" style="display:none">' . drupal_json_encode(array('video' => $vdata['embed'])) . '</span><img class="img-responsive"src="' . file_create_url($node->field_lp_v_image[LANGUAGE_NONE][0]['uri']) . '" /></a>';
                print $video;
                ?>
            </div>
            <div class="clearfix"></div>
            <div class="is-table-row">                
                <?php
                //////  block 1
                if (isset($node->field_lp_news[LANGUAGE_NONE][0]['value'])):
                  ?>
                  <div class="col-md-3"><div class="col bg-col"><h3>News</h3><?= $node->field_lp_news[LANGUAGE_NONE][0]['value']; ?><a class="more-link" href="<?php print $node->field_lp_new_more[LANGUAGE_NONE][0]['value'] ?>">More</a></div></div>
                <?php endif; ?>
                <?php
                //////  block 2                                    
                if (isset($node->field_lp_blog[LANGUAGE_NONE][0]['value'])):
                  ?>
                  <div class="col-md-3"><div class="col bg-col"><h3>Blog</h3><?= $node->field_lp_blog[LANGUAGE_NONE][0]['value']; ?><a class="more-link" href="<?php print $node->field_lp_blog_more[LANGUAGE_NONE][0]['value'] ?>">More</a></div></div>
                <?php endif; ?>
                <div class="col-md-3">
                    <?php
                    //////  block 3  
                    $_GET['test'] = 1;
                    if ($_GET['test']) {
                      ?>
                      <div class="col bg-col">
                          <h3><?php print $node->field_lp_3rd_name[LANGUAGE_NONE][0]['value']; ?></h3><?php print $node->field_lp_3rd_content[LANGUAGE_NONE][0]['value']; ?><div class="mask"></div>';
                    <?php }
                    else {
                      ?>
                      <div class="col">
                          <?php
                          if (isset($node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']) or isset($node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value'])):
                            if (isset($node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value'])) :
                              ?>
                              <div class="contact">
                                  <div class="contact-image"><a href="<?php print $node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']; ?>"><img alt="<?php print $node->field_lp_contact_l_name[LANGUAGE_NONE][0]['value']; ?>" src="<?php print file_create_url($node->field_lp_contact_l_img[LANGUAGE_NONE][0]['uri']); ?>"></a></div>
                                  <div class="contact-info">
                                      <p><a href="<?php print $node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']; ?>"><b>Key contact</b></a></p>
                                      <p><a href="<?php print $node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']; ?>"><?php print $node->field_lp_contact_l_name[LANGUAGE_NONE][0]['value']; ?></a></p>
                                  </div>
                              </div>
    <?php endif; ?>
    <?php if (isset($node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value'])) : ?>
                              <div class="contact">
                                  <div class="contact-image"><a href="<?php print $node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value']; ?>"><img alt="<?php print $node->field_lp_contact_r_name[LANGUAGE_NONE][0]['value']; ?>" src="<?php print file_create_url($node->field_lp_contact_r_img[LANGUAGE_NONE][0]['uri']); ?>"></a></div>
                                  <div class="contact-info">
                                      <p><a href="<?php print $node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value']; ?>"><b>Key contact</b></a></p>
                                      <p><a href="<?php print $node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value']; ?>"><?php print $node->field_lp_contact_r_name[LANGUAGE_NONE][0]['value']; ?></a></p>
                                  </div>
                              </div>
                            <?php endif; ?>
                            <?php
                          endif;
                        }
                        ?>
                    </div></div>
                <?php
                //////  block 4   
                if (isset($node->field_lp_cta_l_text[LANGUAGE_NONE][0]['value']) or isset($node->field_lp_cta_r_text[LANGUAGE_NONE][0]['value'])):
                  ?>
                  <div class="col-md-3"><div class="col">
                          <div class="cta"><a href="<?php
                                                  print $node->field_lp_cta_l_url[LANGUAGE_NONE][0]['value'];
                                                  ?>"><img src="<?php
                                     print file_create_url($node->field_lp_cta_l_image[LANGUAGE_NONE][0]['uri']);
                                     ?>"><div class="cont"><b><?php
                                          print $node->field_lp_cta_l_title[LANGUAGE_NONE][0]['value'];
                                          ?></b><p><?php
                                            print $node->field_lp_cta_l_text[LANGUAGE_NONE][0]['value'];
                                          ?></p></div></a></div>
                          <div class="cta"><a href="<?php
                                                  print $node->field_lp_cta_r_url[LANGUAGE_NONE][0]['value'];
                                                  ?>"><img src="<?php
                                     print file_create_url($node->field_lp_cta_r_image[LANGUAGE_NONE][0]['uri']);
                                     ?>"><div class="cont"><b><?php
                                          print $node->field_lp_cta_r_title[LANGUAGE_NONE][0]['value'];
                                          ?></b><p><?php
                                            print $node->field_lp_cta_r_text[LANGUAGE_NONE][0]['value'];
                                          ?></p></div></a></div>
                      </div></div>
<?php endif; ?>
            </div>
        </section>

    </div>
</div>
<?php if (isset($landingBGClose)): ?>
  <?php print $landingBGClose; ?>
<?php endif; ?>
        <?php if (!empty($page['footer'])): ?>
  <div class="footer-wrapper">
      <footer class="footer <?php print $container_class; ?>">
  <?php print render($page['footer']); ?>
      </footer>
  </div>
<?php endif; ?>
