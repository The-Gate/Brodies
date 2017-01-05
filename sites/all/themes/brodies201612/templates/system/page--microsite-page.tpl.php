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
// get the parent wrapper details
$mlid = db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $node->nid . "'")->fetchField();
$link_path = db_query("SELECT link_path FROM {menu_links} WHERE mlid = :mlid", array(':mlid' => $mlid))->fetchField();
$parent_node = node_load(substr($link_path, 5));

$children = array();
$menuItems_array = array();
$result = db_query("select mlid, plid, link_path, link_title from menu_links where menu_name='menu-microsites' and plid=:mlid and hidden=0 order by weight, link_title", array(':mlid' => $mlid));
while ($row = $result->fetchAssoc()) {
  $children[] = node_load(substr($row['link_path'], 5));
  $menuItems_array[$row['link_path']] = $row['link_title'];
}
if (!empty($_GET['calendar'])) {
  $cal_dtstart = dateToCal($parent_node->field_microsite_date['und'][0]['value']);
  $cal_dtend = dateToCal($parent_node->field_microsite_date['und'][0]['value2']);
  $cal_uid = $parent_node->uid;
  //$cal_description = escapeString(strip_tags(nl2br($node->teaser)));
  $cal_url = escapeString(url($parent_node->path, array('absolute' => TRUE)));
  $cal_summary = escapeString(strip_tags(nl2br($parent_node->title)));
  $cal_description = $cal_summary . ': ' . $cal_url;
  if ($_GET['calendar'] == 'ical') {
    header('Content-type: text/calendar; charset=utf-8');
    header('Content-Disposition: attachment; filename=ical.ics');
    print
        'BEGIN:VCALENDAR
VERSION:2.0
PRODID:-//hacksw/handcal//NONSGML v1.0//EN
CALSCALE:GREGORIAN
BEGIN:VEVENT
DTSTART:' . $cal_dtstart . '
DTEND:' . $cal_dtend . '
UID:' . $cal_uid . '
DTSTAMP:' . $cal_dtstart . '
DESCRIPTION:' . $cal_description . '
URL;VALUE=URI:' . $cal_url . '
SUMMARY:' . $cal_summary . '
END:VEVENT
END:VCALENDAR';
    exit();
  }
}

function dateToCal($timestamp) {
  return date('Ymd\THis\Z', $timestamp);
}

function escapeString($string) {
  return preg_replace('/([\,;])/', '\\\$1', $string);
}
?>
<div class="gridContainer clearfix">
    <div id="msHeader">
        <div id="HeaderTop">
            <div id="headerTopButton"><a href="/" target="_blank">Main Brodies site</a></div>
            <div id="headerTopSocial"><span><a href="https://www.facebook.com/BrodiesLLP"><img src="/sites/all/themes/brodies201612/microsites/images/social-fb-over.png" width="29" height="29" border="0" alt="Facebook"></a><a href="https://plus.google.com/+brodies/posts"><img src="/sites/all/themes/brodies201612/microsites/images/social-gplus-over.png" width="29" height="29" alt="GooglePlus"></a><a href="http://www.linkedin.com/company/brodies-llp"><img src="/sites/all/themes/brodies201612/microsites/images/social-li-over.png" width="29" height="29" alt="LinkedIn"></a><a href="https://twitter.com/BrodiesLLP"><img src="/sites/all/themes/brodies201612/microsites/images/social-tw-over.png" width="29" height="29" alt="Twitter"></a><a href="https://www.youtube.com/BrodiesLLP"><img src="/sites/all/themes/brodies201612/microsites/images/social-yt-over.png" width="29" height="29" alt="YouTube"></a></span></div>     
        </div>
        <div id="headerBanner"><img src="<?php print file_create_url($parent_node->field_microsite_banner[LANGUAGE_NONE][0]['uri']); ?>" /></div>
        <div id="headerMenu"><?php
            //print_r($children);
            $header_menu_right = '';
            $header_menu_array = array_reverse($children);
            foreach ($header_menu_array as $child_node) {
              if ($child_node->field__microsite_header_link['und'][0]['value'] == 1) {
                //print_r($child_node);
                $header_menu_right .= l($menuItems_array['node/' . $child_node->nid], url(drupal_get_path_alias('node/' . $child_node->nid)));
              }
            }
            ?><div id="headerMenuRight"><?php print($header_menu_right); ?></div>
        </div>
    </div>
    <div id="pageContent">
        <div id="mobileMenu"><div class="right">
                <?php
                if (!empty($parent_node->field_microsite_date['und'][0]['value'])) {
                  print('<ul class="merge-list"><li><a href="?calendar=ical">Add to calendar</a></li></ul>');
                }
                if ($page['sidebar_second']) {
                  print render($page['sidebar_second']);
                }
                ?>
            </div>
        </div>
        <div id="fullCol">
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
            <?php if ($title) : ?><h1><?php print $title ?></h1><?php endif; ?>
            <?php print render($page['content']); ?>
        </div>
        <div id="rightCol"><div class="right">
                <?php
                if (!empty($parent_node->field_microsite_date['und'][0]['value'])) {
                  print('<ul class="merge-list"><li><a href="?calendar=ical">Add to calendar</a></li></ul>');
                }
                if ($page['sidebar_second']) {
                  print render($page['sidebar_second']);
                }
                ?>
            </div>
        </div>
    </div>
    <div id="footer" class="zone zone-footer"><?php print render($page['footer']); ?></div>
</div>
