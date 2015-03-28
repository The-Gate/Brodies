<?php
// get the parent wrapper details
$mlid = db_result(db_query("select plid from {menu_links} where menu_name = 'menu-microsites' and link_path = 'node/" . $node->nid . "'"));
$link_path = db_result(db_query("SELECT link_path FROM {menu_links} WHERE mlid = %d", $mlid));
$parent_node = node_load(substr($link_path, 5));

$children = array();
$menuItems_array = array();
$result = db_query('select mlid, plid, link_path, link_title from menu_links where menu_name="menu-microsites" and plid=%d and hidden=0 order by weight, link_title', $mlid);
while (( $row = db_fetch_array($result))) {
  $children[] = node_load(substr($row['link_path'], 5));
  $menuItems_array[$row['link_path']] = $row['link_title'];
}
if (!empty($_GET['calendar'])) {
  $cal_dtstart = dateToCal($parent_node->field_microsite_date[0]['value']);
  $cal_dtend = dateToCal($parent_node->field_microsite_date[0]['value2']);
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
<!doctype html>
<!--[if lt IE 7]> <html class="ie6 oldie"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 oldie"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 oldie"> <![endif]-->
<!--[if gt IE 8]><!-->
<html class="">
  <!--<![endif]-->
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>   
    <link href="/sites/all/themes/brodies/microsites/css/boilerplate.css" rel="stylesheet" type="text/css">
    <link href="/sites/all/themes/brodies/microsites/css/microsites.css" rel="stylesheet" type="text/css">
    <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    <script src="/sites/all/themes/brodies/microsites/js/respond.min.js"></script>
    <script type="text/javascript">
      function MM_jumpMenu(targ, selObj, restore) { //v3.0
        eval(targ + ".location='" + selObj.options[selObj.selectedIndex].value + "'");
        if (restore)
          selObj.selectedIndex = 0;
      }
    </script>
  </head>
  <body>
    <div class="gridContainer clearfix">
      <div id="msHeader">
        <div id="HeaderTop">
          <div id="headerTopButton"><a href="/" target="_blank">Main Brodies site</a></div>
          <div id="headerTopSocial"><span><a href="https://www.facebook.com/BrodiesLLP"><img src="/sites/all/themes/brodies/microsites/images/social-fb-over.png" width="29" height="29" border="0" alt="Facebook"></a><a href="https://plus.google.com/+brodies/posts"><img src="/sites/all/themes/brodies/microsites/images/social-gplus-over.png" width="29" height="29" alt="GooglePlus"></a><a href="http://www.linkedin.com/company/brodies-llp"><img src="/sites/all/themes/brodies/microsites/images/social-li-over.png" width="29" height="29" alt="LinkedIn"></a><a href="https://twitter.com/BrodiesLLP"><img src="/sites/all/themes/brodies/microsites/images/social-tw-over.png" width="29" height="29" alt="Twitter"></a><a href="https://www.youtube.com/BrodiesLLP"><img src="/sites/all/themes/brodies/microsites/images/social-yt-over.png" width="29" height="29" alt="YouTube"></a></span></div>     
        </div>
        <div id="headerBanner"><?php
          print(theme_image($parent_node->field_microsite_banner[0]['filepath']));
          ?></div>
        <div id="headerMenu"><?php
          //print_r($children);
          $header_menu_right = '';
          $header_menu_array = array_reverse($children);
          foreach ($header_menu_array as $child_node) {
            if ($child_node->field__microsite_header_link[0]['value'] == 1) {
              //print_r($child_node);
              $header_menu_right .= l($menuItems_array['node/' . $child_node->nid], $child_node->path);
            }
          }
          ?><div id="headerMenuRight"><?php print($header_menu_right); ?></div>
        </div>
      </div>
      <div id="pageContent">
        <div id="mobileMenu"><div class="right">
            <?php
            if (!empty($parent_node->field_microsite_date[0]['value'])) {
              print('<ul class="merge-list"><li><a href="?calendar=ical">Add to calendar</a></li></ul>');
            }
            if ($right) {
              print $right;
            }
            ?>
          </div>
        </div>
      <div id="fullCol">
        <?php if ($tabs || $tabs2) : ?><div class="controls"><ul><?php print $tabs ?> <?php print $tabs2 ?></ul></div><?php endif; ?>      
        <?php print $messages ?>
        <?php if ($left) : ?><div class="left"><?php print $left ?></div><?php endif; ?> 

        <?php if ($title) : ?><h1><?php print $title ?></h1><?php endif; ?>
        <?php print $content; ?>
      </div>
      <div id="rightCol"><div class="right">
          <?php
          if (!empty($parent_node->field_microsite_date[0]['value'])) {
            print('<ul class="merge-list"><li><a href="?calendar=ical">Add to calendar</a></li></ul>');
          }
          if ($right) {
            print $right;
          }
          ?>
        </div>
      </div>
    </div>
    <div id="footer" class="zone zone-footer">    	
      <div id="footerLeft"><?php print $footer_left ?></div>      
      <div id="footerRight"><?php print $footer_right ?></div> 
      <?php print $footer ?>       
    </div>
    <?php print $closure ?>
  </div>
    
<script type="text/javascript" src="/sites/all/themes/brodies/microsites/js/map-locations-dist.js"></script>
</body>
</html>
