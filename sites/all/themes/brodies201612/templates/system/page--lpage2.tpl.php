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
<div class="navbar-wrapper">
    <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
        <div class="<?php print $container_class; ?>">
            <div class="navbar-header">
                <?php if ($logo): ?>
                  <div class="logo-wrapper-mobile">
                      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                          <img src="/sites/all/themes/brodies201612/images/logo-landing.png" alt="<?php print t('Home'); ?>"/>
                      </a>
                  </div>
                <?php endif; ?>

                <?php if (!empty($site_name)): ?>
                  <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
                <?php endif; ?>

                <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
                  <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
                      <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
                      <span class="icon-bar"></span>
                      <span class="icon-bar"></span>
                      <span class="icon-bar"></span>
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
                      <img src="/sites/all/themes/brodies201612/images/logo-landing.png" alt="<?php print t('Home'); ?>"/>
                  </a>
              </div>
            <?php endif; ?>
        </div>


    </header>
    <?php
    if (isset($node->field_lp_bkg_image)) {
      print('<div id ="landing-background" class = "landing-background clearfix" style = "background-image:url(\'' . file_create_url($node->field_lp_bkg_image[LANGUAGE_NONE][0]['uri']) . '\')"></div>');
    }
    ?>
</div>
<div class="main-container <?php print $container_class; ?>">

    <header role="banner" id="page-header">
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
            <div class="col-md-12">
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
            <div class="col-md-8 col-left main-content">
                <?php
                $vdata = br_get_video_data($node->field_lp_v_link[LANGUAGE_NONE][0]['value']);
                $video = '<a href="' . $node->field_lp_v_link[LANGUAGE_NONE][0]['value'] . '" class="vi"><span class="video" style="display:none">' . drupal_json_encode(array('video' => $vdata['embed'])) . '</span><img class="video-thumb img-responsive"src="' . file_create_url($node->field_lp_v_image[LANGUAGE_NONE][0]['uri']) . '" /></a>';
                print $video;
                print render($page['content']);
                if (isset($node->field_lp_dl_file_1[LANGUAGE_NONE][0]['uri'])) {
                  $style_1 = '';
                  if ($node->field_lp_dl_img_1[LANGUAGE_NONE][0]['uri']) {
                    $dlih1 = image_get_info($node->field_lp_dl_img_1[LANGUAGE_NONE][0]['uri']);
                    $dlih1S = (!empty($dlih1['height'])) ? ';min-height:' . $dlih1['height'] . 'px;' : '';
                    $style_1 = ' style="background-image:url(\'' . file_create_url($node->field_lp_dl_img_1[LANGUAGE_NONE][0]['uri']) . '\');' . $dlih1S . '"';
                  }
                  $title_1 = (isset($node->field_lp_dl_title_1[LANGUAGE_NONE][0]['value'])) ? $node->field_lp_dl_title_1[LANGUAGE_NONE][0]['value'] : "Download File";
                  print '<div class="landing-download"><div class="landing-download-item item-1"' . $style_1 . '><a href="' . file_create_url($node->field_lp_dl_file_1[LANGUAGE_NONE][0]['uri']) . '" target="_blank">' . $title_1 . '</a></div></div>';
                }
                ?>
            </div>
            <div class="col-md-4 col-right">
                <?php
                // included webform
                if (isset($node->field_block_reference[LANGUAGE_NONE][0][moddelta])) {
                  $blockDetails = explode(':', $node->field_block_reference[LANGUAGE_NONE][0][moddelta]);
                  $block = module_invoke($blockDetails[0], 'block_view', $blockDetails[1]);
                  if (!empty($block['content'])) {
                    print ('<div class="block-wrapper">' . $block['content'] . '</div>');
                  }
                }

                //////  Key Contacts
                if (isset($node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']) or isset($node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value'])):
                  ?>
                  <div class="cta contacts">
                      <h3>Key Contacts</h3>
                      <?php if (isset($node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value'])) :
                        ?>
                        <div class="contact">
                            <div class="contact-img"><a href="<?php print $node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']; ?>"><img alt="<?php print $node->field_lp_contact_l_name[LANGUAGE_NONE][0]['value']; ?>" src="<?php print file_create_url($node->field_lp_contact_l_img[LANGUAGE_NONE][0]['uri']); ?>"></a></div>
                            <div class="contact-info">
                                <p><a href="<?php print $node->field_lp_contact_l_url[LANGUAGE_NONE][0]['value']; ?>"><?php print $node->field_lp_contact_l_name[LANGUAGE_NONE][0]['value']; ?></a></p>
                            </div>
                        </div>
                      <?php endif; ?>
                      <?php if (isset($node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value'])) : ?>
                        <div class="contact">
                            <div class="contact-img"><a href="<?php print $node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value']; ?>"><img alt="<?php print $node->field_lp_contact_r_name[LANGUAGE_NONE][0]['value']; ?>" src="<?php print file_create_url($node->field_lp_contact_r_img[LANGUAGE_NONE][0]['uri']); ?>"></a></div>
                            <div class="contact-info">
                                <p><a href="<?php print $node->field_lp_contact_r_url[LANGUAGE_NONE][0]['value']; ?>"><?php print $node->field_lp_contact_r_name[LANGUAGE_NONE][0]['value']; ?></a></p>
                            </div>
                        </div
                      <?php endif; ?>>
                  </div>
                  <?php
                endif;
                ?>
            </div>
            <div class="clearfix"></div>
            <?php
            //////  block 1

            $blockClass = " col-md-8";
            if (isset($node->field_lp_dl_file_2[LANGUAGE_NONE][0]['uri']) or isset($node->field_lp_dl_file_3[LANGUAGE_NONE][0]['uri']) or isset($node->field_lp_dl_file_4[LANGUAGE_NONE][0]['uri'])):
              ?>
              <div class="col-md-4"><div class="cta feeds"><h3>Associated downloads</h3><ul><?php
                          if (!empty($node->field_lp_dl_file_2[LANGUAGE_NONE][0]['uri'])) {
                            $title_1 = (isset($node->field_lp_dl_title_2[LANGUAGE_NONE][0]['value'])) ? $node->field_lp_dl_title_2[LANGUAGE_NONE][0]['value'] : "Download File";
                            $linkContent1 = (!empty($node->field_lp_dl_img_2[LANGUAGE_NONE][0]['uri'])) ? '<img src="' . file_create_url($node->field_lp_dl_img_2[LANGUAGE_NONE][0]['uri']) . '" />' : $title_1;
                            print('<li><a href="/' . $node->field_lp_dl_file_2[0]['filepath'] . '" target="_blank">' . $linkContent1 . '</a></li>');
                          }
                          if (!empty($node->field_lp_dl_file_3[LANGUAGE_NONE][0]['uri'])) {
                            $title_2 = (isset($node->field_lp_dl_title_3[LANGUAGE_NONE][0]['value'])) ? $node->field_lp_dl_title_3[LANGUAGE_NONE][0]['value'] : "Download File";
                            $linkContent2 = (!empty($node->field_lp_dl_img_3[LANGUAGE_NONE][0]['uri'])) ? '<img src="' . file_create_url($node->field_lp_dl_img_3[LANGUAGE_NONE][0]['uri']) . '" />' : $title_2;
                            print('<li><a href="/' . $node->field_lp_dl_file_3[0]['filepath'] . '" target="_blank">' . $linkContent2 . '</a></li>');
                          }
                          if (!empty($node->field_lp_dl_file_4[LANGUAGE_NONE][0]['uri'])) {
                            $title_3 = (isset($node->field_lp_dl_title_4[LANGUAGE_NONE][0]['value'])) ? $node->field_lp_dl_title_4[LANGUAGE_NONE][0]['value'] : "Download File";
                            $linkContent3 = (!empty($node->field_lp_dl_img_4[LANGUAGE_NONE][0]['uri'])) ? '<img src="' . file_create_url($node->field_lp_dl_img_4[LANGUAGE_NONE][0]['uri']) . '" />' : $title_1;
                            print('<li><a href="/' . $node->field_lp_dl_file_4[0]['filepath'] . '" target="_blank">' . $linkContent3 . '</a></li>');
                          }
                          ?></ul>
                  </div></div>
              <?php
              $blockClass = " col-md-4";
            endif;
            ?>


            <?php
            //////  block 4
            if (isset($node->field_lp_blog[LANGUAGE_NONE][0]['value'])):
              ?>
              <div class="<?php echo $blockClass; ?>"><div class="cta feeds"><h3>Recent Publications</h3><?= $node->field_lp_blog[LANGUAGE_NONE][0]['value']; ?><?php if (isset($node->field_lp_blog_more[LANGUAGE_NONE][0]['value'])): ?>

                      <?php endif; ?></div></div>
            <?php endif; ?>

            <?php
//////  block 3
            if (isset($node->field_lp_news[LANGUAGE_NONE][0]['value'])):
              ?>
              <div class="col-md-4"><div class="cta feeds"><h3>Useful Links</h3><?= $node->field_lp_news[LANGUAGE_NONE][0]['value']; ?><?php if (isset($node->field_lp_new_more[LANGUAGE_NONE][0]['value'])): ?>
                      <?php endif; ?></div></div>
                    <?php endif; ?>

        </section>
    </div>
</div>
