<?php

//brodies pages 

function br_sector_page($node) {
  $mobile = mis_is_mobile();

  if (br_popup_request_check() && isset($_GET['text-only'])) {
    return '<h1>' . $node->title . '</h1><div class="body">' . $node->body . '</div>';
  }

  $left = $right = '';

  $body = '<div class="body">' . $node->body . '</div>' . $more;

  if ($llinks) {
    $left = '<h2>' . $ltitle . '</h2><ul>' . $llinks . '</ul>';
  }

  if ($node->type == 'sector' || $node->type == 'service') {

    if ($node->field_related_cs[0]['nid']) {
      $cs_node = node_load($node->field_related_cs[0]['nid']);
      $image = '';
      if ($cs_node->field_teaser_image[0]['filepath']) {
        $filepath = imagecache_create_url('related-cs-thumb', $cs_node->field_teaser_image[0]['filepath']);
        $image = '<img src="' . $filepath . '" alt="' . check_plain($cs_node->title) . '" />';
      }
    }
  }
  $rtn_string = '<div class="sector">';

  if (strlen($left) > 0) {
    $rtn_string .= '<div class="left">' . $left . '</div>';
  }
  $rtn_string .= $video . '<div class="content">' . $body . '</div>';
  if (strlen($right) > 0) {
    $rtn_string .= '<div class="right">' . $right . '</div>';
  }
  $rtn_string .= '<div class="ff"></div></div>';

  if ($mobile) {
    if ($node->field_related_video[0]['nid']) {
      $video_node = node_load($node->field_related_video[0]['nid']);
      $video_data = br_get_video_data($video_node->field_video_url[0]['value'], TRUE);
      $video = '<div class="text">' . (isset($_GET['text-only']) ? '<a href="' . url($_GET['q']) . '">&lt; back to video</a>' : '<a href="?text-only" class="popup">Text only</a>') . '</div><div class="video">' . $video_data['embed'] . '</div>';
      $more = '<a href="?text-only" class="popup">Read more &raquo;</a>';
      $body = '<div class="short">' . $node->teaser . '</div>';
    }
    return '<div class="back"><a href="' . url('<front>') . '">&laquo; Back</a></div>' .
        ($video_data['embed'] ? '<div class="video">' . $video_data['embed'] . '</div>' : '') .
        '<div class="body">' . $node->body . '</div>' .
        br_area('cs', $node) . br_area('news', $node) . br_area('people', $node) . br_area('sae', $node);
  }

  return $rtn_string;
}

function br_listing($type, $popup = FALSE, $stype = '') {
  $sql_count = NULL;
  $mobile = mis_is_mobile();
  $order = $out = $joins = $thumb = $filters = $filter_text = '';
  $filter_names = $args = array();
  $rpp = 0;
  $no_results = '<p>No results found.</p>';
  //standard filters
  if ($type != 'win') {
    if ($_GET['sector'] && is_numeric($_GET['sector'])) {
      $name = db_result(db_query("SELECT title FROM {node} where nid = %d and type = 'sector'", $_GET['sector']));
      if ($name) {
        $joins .= ' INNER JOIN {content_field_related_sector} rsec on field_related_sector_nid = ' . (int) $_GET['sector'] . ' AND rsec.vid = n.vid';
        //right order
        $order_nids = array();
        $result = db_query("SELECT field_related_" . $type . "_nid as rid FROM content_field_related_" . $type . " r INNER JOIN {node} n on n.nid = %d AND n.vid = r.vid ORDER BY delta ", $_GET['sector']);
        while ($data = db_fetch_object($result)) {
          $order_nids[$data->rid] = $data->rid;
        }

        if (count($order_nids)) {
          $order = " ORDER BY FIND_IN_SET(n.nid, '" . implode(',', $order_nids) . "') ";
        }

        $filter_names[] = 'Sector: ' . $name;
      }
    }
  }

  if ($_GET['service'] && is_numeric($_GET['service'])) {
    $name = db_result(db_query("SELECT title FROM {node} where nid = %d and type = 'service'", $_GET['service']));
    if ($name) {
      $joins .= ' INNER JOIN {content_field_related_service} rser on field_related_service_nid = ' . (int) $_GET['service'] . ' AND rser.vid = n.vid';
      $filter_names[] = 'Service: ' . $name;
    }
  }

  switch ($type) {
    case 'win':
      $rpp = 6;

      if ($_GET['sector'] && is_numeric($_GET['sector'])) {
        $name = db_result(db_query("SELECT title FROM {node} where nid = %d and type = 'sector'", $_GET['sector']));
        if ($name) {
          $wjoins .= ' INNER JOIN {content_field_related_sector} rsec on field_related_sector_nid = ' . (int) $_GET['sector'] . ' AND rsec.vid = n.vid';
        }
      }

      if ($_GET['service'] && is_numeric($_GET['service'])) {
        $name = db_result(db_query("SELECT title FROM {node} where nid = %d and type = 'service'", $_GET['service']));
        if ($name) {
          $wjoins .= ' INNER JOIN {content_field_related_service} rser on field_related_service_nid = ' . (int) $_GET['service'] . ' AND rser.vid = n.vid';
        }
      }

      $sql = "SELECT n.nid, n.title FROM {node} n INNER JOIN content_type_win br on n.vid = br.vid " . $wjoins . " WHERE status = 1 and type='" . $type . "' " . $filters . " ORDER BY field_w_date_value DESC";
      break;

    case 'download':
      $rpp = 6;
      $filter_text .= br_search('download');

      if ($_GET['category'] && is_numeric($_GET['category'])) {
        $wjoins .= ' INNER JOIN term_node tn on n.vid = tn.vid and tn.tid=' . $_GET['category'] . ' ';
      }

      if ($_GET['keyword']) {
        $filters .= " AND ( n.title like ('%%%s%%') OR nr.body like ('%%%s%%'))";
        $args[] = $_GET['keyword'];
        $args[] = $_GET['keyword'];
      }

      $sql = "SELECT n.nid, n.title FROM {node} n INNER JOIN node_revisions nr on nr.vid = n.vid INNER JOIN content_type_download br on n.vid = br.vid " . $wjoins . " WHERE status = 1 and type='" . $type . "' " . $filters . " ORDER BY field_d_date_value DESC";
      break;

    case 'people':
      $rpp = 30;
      if ($_GET['a-z']) {
        $lstart = $_GET['a-z'][0];
        $lend = $_GET['a-z'][1];
        $having .= ' HAVING letter >= "' . $lstart . '" AND letter <= "' . $lend . '" ';
        $filter_names[] = 'Letters: ' . strtoupper($lstart . ' - ' . $lend);
      }
      if ($_GET['partners']) {
        $filters .= ' AND field_people_partner_value = 1 ';
        $filter_names[] = 'Partners';
      }
      if (!$order) {
        $order = "ORDER BY field_people_sname_value ASC";
      }

      $filters .= $stype == 'profile' ? ' AND field_people_section_value = 2 ' : 'AND (field_people_section_value = 1 OR field_people_section_value is NULL ) ';


      if ($stype == 'profile' || ($_GET['partners'] || $_GET['sector'] || $_GET['service'] || $_GET['a-z'])) {
        $sql = "SELECT SUBSTRING(field_people_sname_value, 1, 1) as letter, n.nid, n.title, filepath, p.*, nr.teaser, nr.body FROM {content_type_people} p INNER JOIN {node} n on n.vid = p.vid LEFT JOIN {content_field_people_section} ps on ps.vid = p.vid
        LEFT JOIN {content_field_teaser_image} ti on ti.vid = n.vid LEFT JOIN {files} f on f.fid = field_teaser_image_fid LEFT JOIN {node_revisions} nr on nr.vid = n.vid " . $joins . " WHERE 1 " . $filters . " " . $having . $order;
        $rpp = 0;
      }

      if ($mobile) {
        $filter_text .= br_search('people');
      }
      break;
    case 'cs':
      if (!$order) {
        $order = "ORDER BY n.title ASC";
      }

      //$sql = "SELECT n.nid, n.title, nr.teaser, nr.body, filepath, cs.* FROM {content_type_cs} cs INNER JOIN {node} n on n.vid = cs.vid LEFT JOIN {content_field_teaser_image} ti on ti.vid = n.vid LEFT JOIN {files} f on f.fid = field_teaser_image_fid LEFT JOIN {node_revisions} nr on nr.vid = n.vid " . $joins . " WHERE 1 " . $filters . " " . $having . " " . $order;

      $sql = "SELECT n.nid, n.title, cs.* FROM {content_type_cs} cs INNER JOIN {node} n on n.vid = cs.vid LEFT JOIN {node_revisions} nr on nr.vid = n.vid " . $joins . " WHERE 1 " . $filters . " " . $having . " " . $order;

      $no_results = '<p><b>A number of related case studies coming soon. Please refer to the main page text in the meantime, for examples of expertise and recent clients.</b></p>';

      if ($mobile) {
        $rpp = 0;
      }
      break;
    case 'event':
      if ($_REQUEST['q'] == 'seminars-and-events') {
        $filters .= " AND field_event_type_value = 'seminar' ";
        $filter_names[] = 'Seminars';
      }
      else {
        $filters .= " AND field_event_type_value = 'event' ";
        $filter_names[] = 'Events';
      }

      if ($_GET['location'] && is_numeric($_GET['location'])) {
        $name = db_result(db_query("SELECT title FROM {node} where nid = %d and type = 'location'", $_GET['location']));
        if ($name) {
          $filters .= ' AND field_event_location_nid = ' . (int) $_GET['location'] . ' ';
          $filter_names[] = 'Location: ' . $name;
        }
      }

      if ($_GET['date'] && is_numeric($_GET['date'])) {
        $filters .= ' AND field_event_date_value = ' . (int) $_GET['date'] . ' ';
        $filter_names[] = 'Date: ' . date('l j F Y', (int) $_GET['date']);
      }
      $filters .= 'AND (IF(e.field_event_visibility_value, e.field_event_visibility_value, e.field_event_date_value) > ' . time() . ' ) ';


      if ($_GET['category']) {
        $ctype = '';
        if ($ctype = db_result(db_query("SELECT type FROM node where nid = %d and (type = 'sector' OR type = 'service')", $_GET['category']))) {
          $filters .= ' AND e.vid in (SELECT vid FROM content_field_related_' . $ctype . ' where field_related_' . $ctype . '_nid = ' . (int) $_GET['category'] . ') ';
        }
      }

      $sql = "SELECT n.nid, n.title, e.*, n1.title as location, nr.teaser, nr.body, e.field_event_type_value FROM {content_type_event} e INNER JOIN {node} n on n.vid = e.vid LEFT JOIN {node} n1 on n1.nid = e.field_event_location_nid LEFT JOIN {node_revisions} nr on nr.vid = n.vid " . $joins . " WHERE 1 " . $filters . " ORDER BY e.field_event_date_value ASC";
      break;
    case 'news':
      if (arg(0) == 'node' && arg(1)) {
        $node = node_load(arg(1));
        if ($node->type == 'cnews') {
          $filters .= 'AND field_news_category_nid = ' . (int) arg(1);
        }
        else {
          return '';
        }
      }

      if ($_GET['tag']) {
        $filters .= ' AND ns.vid in (SELECT vid FROM term_node where tid = ' . (int) $_GET['tag'] . ')';
      }
      $sql = "SELECT n.nid, n.title, nr.teaser, filepath  FROM {content_type_news} ns INNER JOIN {node} n on n.vid = ns.vid LEFT JOIN {content_field_teaser_image} ti on ti.vid = ns.vid LEFT JOIN {files} f on ti.field_teaser_image_fid = f.fid LEFT JOIN {node_revisions} nr on nr.vid = n.vid WHERE n.status = 1 " . $filters . " ORDER BY created DESC";

      if (mis_is_mobile()) {
        $out .= '<div class="back"><a href="' . url('node/53') . '">&laquo; Back</a></div>';
      }

      break;
    case 'lupdate':
      if ($_GET['legal-area'] && is_numeric($_GET['legal-area'])) {
        $filters .= ' AND field_l_area_nid = ' . (int) $_GET['legal-area'] . ' ';
      }

      if ($_GET['year'] && is_numeric($_GET['year'])) {
        $filters .= ' AND YEAR(from_unixtime(field_l_date_value)) = ' . (int) $_GET['year'] . ' ';
      }

      if ($_GET['keyword']) {
        $filters .= ' AND (nr.title like ("%%%s%%")
                              OR nr.body like ("%%%s%%")
                              OR u.field_l_left_value like ("%%%s%%")
                              ) ';
        $args[] = $_GET['keyword'];
        $args[] = $_GET['keyword'];
        $args[] = $_GET['keyword'];
      }

      $order = ' ORDER BY field_l_date_value desc, field_l_id_value DESC ';
      if ($_GET['sort']) {
        switch ($_GET['sort']) {
          case 'date-recent-last':
            $order = ' ORDER BY field_l_date_value ASC ';
            break;
          case 'heading-az':
            $order = ' ORDER BY n.title ASC ';
            break;
          case 'heading-za':
            $order = ' ORDER BY n.title DESC ';
            break;
        }
      }

      $sql = "SELECT n.nid, n.title, u.*, nr.teaser FROM {content_type_lupdate} u INNER JOIN {node} n on n.vid = u.vid LEFT JOIN {node_revisions} nr on nr.vid = n.vid WHERE type='" . $type . "' and status=1 " . $filters . " " . $order;
      $rpp = 10;

      if (mis_is_mobile()) {
        $out .= '<div class="back"><a href="' . url('node/62') . '">&laquo; Back</a></div>';
      }
      break;
    case 'publication':
      if ($_GET['area'] && is_numeric($_GET['area'])) {
        $filters .= ' AND field_p_area_nid = ' . (int) $_GET['area'] . ' ';
      }

      if ($_GET['year'] && is_numeric($_GET['year'])) {
        $filters .= ' AND YEAR(from_unixtime(field_p_date_value)) = ' . (int) $_GET['year'] . ' ';
      }

      if ($_GET['year'] || $_GET['area']) {
        $sql = "SELECT n.nid, n.title, p.*, nr.body, f.* FROM {content_type_publication} p INNER JOIN {node} n on n.vid = p.vid LEFT JOIN {node_revisions} nr on nr.vid = n.vid LEFT JOIN {files} f on f.fid = field_p_file_fid WHERE type='" . $type . "' and n.status= 1 " . $filters . " ORDER BY p.field_p_date_value DESC ";
      }

      if (mis_is_mobile()) {
        $out .= '<div class="back"><a href="' . url('node/62') . '">&laquo; Back</a></div>';
      }

      break;
    case 'video':
      if (strlen($order) < 1) {
        $order = "ORDER BY n.changed desc";
      }
      $sql = "SELECT n.nid, n.title, filepath, cs.field_video_url_value, nr.body FROM {content_type_video} cs INNER JOIN {node} n on n.vid = cs.vid LEFT JOIN {node_revisions} nr on nr.vid = n.vid LEFT JOIN {content_field_teaser_image} ti on ti.vid = n.vid LEFT JOIN {files} f on f.fid = field_teaser_image_fid " . $joins . " WHERE 1 " . $filters . " " . $order;
      $no_results = '<p>No results found</p>';
      $rpp = 6;
      $no_top_pager = TRUE;
      break;

    default:
      $sql = "SELECT n.nid, n.title FROM {node} n WHERE type='" . $type . "' and status=1 ORDER BY title ASC";
      break;
  }

  if ($popup) {
    //$sql .= ' LIMIT 0,3';
  }

  if ($sql) {
    if ($rpp && !$popup) {
      $result = pager_query($sql, $rpp, 0, $sql_count, $args);
    }
    else {
      $result = db_query($sql, $args);
    }
  }

  $count = 0;
  $current_letter = '';
  if ($result) {
    while ($data = db_fetch_object($result)) {
      $count++;
      if ((!(empty($data->letter))) and ( !($data->letter == $current_letter))) {
        $out .='<div class="result-header"><h2>' . $data->letter . '</h2></div>';
        $current_letter = $data->letter;
      }
      $out .= br_print_row($data, $type, $popup ? $count : FALSE, $count, $stype);
    }
  }

  if (count($filter_names) && !$filter_names) {
    $filter_text = '<div class="filter-name">' . implode(', ', $filter_names) . '</div><div class="clear"></div>';
  }

  if (!$out) {
    if ($sql) {
      $out = '' . $no_results . '';
    }
    else {
      $out = '<b>Choose filter to see results.</b>';
    }
  }
  else if ($popup) {
    $out .= '<h2 class="all">' . l('All ' . drupal_get_title(), $_GET['q'], array('query' => drupal_query_string_encode($_GET, array('q')), 'html' => TRUE)) . '</h2>';
  }

  if ($rpp && $count) {
    $out = '<div class="listing-wrapper">' . $out . '</div><div class="ff"></div>' . br_pager($rpp, $mobile);
  }

  return '<div class="listing l-' . $type . '">' . $filter_text . $out . '</div>';
}

function br_pager($rpp, $mobile = FALSE) {
  global $pager_page_array, $pager_total, $pager_total_items;
  return //'<div class="totals">Viewing page '. ($pager_page_array[0] + 1) .' of '. $pager_total[0] .',  giving '. $pager_total_items[0] .' results</div>'. 
      theme('pager', NULL, $rpp, 0, array(), $mobile ? 5 : 9);
}

function br_print_row($data, $type, $popup = FALSE, $count = 0, $stype = '') {
  $mobile = mis_is_mobile();

  if ($popup) {
    $image = '';
    if ($data->filepath) {
      $src = imagecache_create_url('page-full-width', $data->filepath);
      $image = '<a href="' . url('node/' . $data->nid) . '"><img src="' . $src . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/></a>';
    }

    $body = $data->body;
    //break after 1st paragraph
    if (strpos($body, '</p>', 20) !== FALSE) {
      $body = substr($body, 0, strpos($body, '</p>', 20) + 4);
    }

    if ($popup == 1) {
      $content = '<h1>' . $data->title . '</h1>' . $image . (strlen($body) > 100 ? substr($body, 0, 199) . '...' : $body)
          . '<div class="more">' . l('Continue&nbsp;Reading', 'node/' . $data->nid, array('html' => TRUE)) . '</div>';
    }
    else {
      $content = '<h2>' . l(($popup - 1) . '. ' . $data->title, 'node/' . $data->nid) . '</h2>' . (strlen($data->teaser) > 100 ? substr($data->teaser, 0, 199) . '...' : $data->teaser) . ' <span class="more">' . l('Continue&nbsp;Reading', 'node/' . $data->nid, array('html' => TRUE)) . '</span>';
    }
  }
  else {
    switch ($type) {
      case 'people';
        if ($mobile) {
          $content = $image . '<h3>' . $data->title . '</h3><div class="more">' . l('More information', 'node/' . $data->nid, array('query' => drupal_get_destination())) . '</div>';
        }
        else {
          $content = '<div class="col-left"><div class="img">' . ($data->filepath ? ($stype != 'profile' ? '<a href="' . url('node/' . $data->nid) . '"><img src="' . imagecache_create_url('people-list-thumb', $data->filepath) . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/></a>' : '<img src="' . imagecache_create_url('people-list-thumb', $data->filepath) . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/>') : '&nbsp;') . '</div></div><div class="col-right"><div class="name">' . ($stype != 'profile' ? l($data->field_people_sname_value . ', ' . $data->field_people_fname_value, 'node/' . $data->nid) : $data->field_people_sname_value . ', ' . $data->field_people_fname_value) . '</div><div class="nr">' . $data->field_people_phone_value . '</div><div class="email">' . l('Email', 'mailto:' . $data->field_people_email_value) . '</div></div><div class="ff"></div>';
        }
        break;
      case 'win';
        $node = node_load($data->nid);
        $src = $node->field_w_image[0]['filepath'];
        $image = '<img src="' . $src . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/>';
        if (user_access('edit any win content')) {
          $controls = '<div class="controls">' . l(t('Edit'), 'node/' . $data->nid . '/edit', array('query' => drupal_get_destination())) . '</div>';
        }
        $content = '<div class="il"><h3>' . $node->title . '</h3><div class="date">' . date("d.m.y", $node->field_w_date[0]['value']) . '</div><div class="text">' . $node->body . '</div></div><div class="ir">' . $image . '</div><div class="ff"></div>' . $controls;

        break;
      case 'download';
        $node = node_load($data->nid);
        $src = $node->field_d_thumbail[0]['filepath'];
        $image = '<img src="' . $src . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/>';
        if (user_access('edit any dowload content')) {
          $controls = '<div class="controls">' . l(t('Edit'), 'node/' . $data->nid . '/edit', array('query' => drupal_get_destination())) . '</div>';
        }

        $cats = '';
        if (count($node->taxonomy)) {
          $catsa = array();
          foreach ($node->taxonomy as $term) {
            $catsa[] = ucfirst(strtolower($term->name));
          }
          $cats = '<div class="cats"><b>Category:</b> ' . implode(', ', $catsa) . '</div>';
        }

        $download = '';
        if ($node->field_d_file[0]['filepath']) {
          $dhref = $node->field_d_file[0]['filepath'];
          if (strpos($dhref, '.pdf') !== FALSE) {
            $blank = TRUE;
          }
        }

        if ($node->field_d_url[0]['value']) {
          $dhref = $node->field_d_url[0]['value'];
          $blank = TRUE;
        }

        if ($dhref) {
          $download = '<a href="' . $dhref . '"' . ($blank ? ' target="_blank"' : '') . ' class="download">Download guide</a>';
        }

        $content = '<div class="il"><h3>' . $node->title . '</h3><div class="date">' . date("d.m.y", $node->field_d_date[0]['value']) . '</div><div class="text">' . $node->body . '</div>' . $cats . $download . '</div><div class="ir">' . $image . '</div><div class="ff"></div>' . $controls;

        break;
      case 'cs';
        $content = $image . '<h3>' . l($data->title, 'node/' . $data->nid) . '</h3><div class="ff"></div>';
        if ($mobile) {
          $content = $image . '<h3>' . $data->title . '</h3><div class="more">' . l('More information', 'node/' . $data->nid, array('query' => drupal_get_destination())) . '</div>';
        }
        break;
      case 'event';
        $details_html = '';
        $details = array('When' => date('l j F Y', $data->field_event_date_value), 'Time' => date('H:i', $data->field_event_date_value) . ' - ' . date('H:i', $data->field_event_date_value2), 'Where' => $data->location);
        foreach ($details as $label => $value) {
          $details_html .= '<div><div>' . $label . ':</div><span>' . $value . '</span></div>';
        }
        $book = '';
        $node = node_load($data->nid);
        if ($data->field_event_type_value == 'seminar') {
          if ($node->field_event_full[0]['value']) {
            $book = '<div class="ff"></div><div class="booked">Fully booked</div>';
            $book .= l('Seminar waiting list', 'node/' . $data->nid, array('query' => 'seminar-waiting-list=' . $data->nid . '&' . drupal_get_destination(), 'attributes' => array('class' => 'booked')));
          }
          else {
            $book = br_book_link($data);
          }
        }
        $content = '<h3>' . l($data->title, 'node/' . $data->nid) . '</h3><div class="details">' . $details_html . $book . '<div class="ff"></div></div><div class="text">' . $data->teaser . '</div><div class="more">' . l('More info', 'node/' . $data->nid, array('html' => TRUE)) . '</div><div class="ff"></div>';
        break;
      case 'news':
        if ($data->filepath) {
          $src = imagecache_create_url($count == 1 || $count == 2 ? 'news-list-full' : 'news-list-half', $data->filepath);
          $image = '<a href="' . url('node/' . $data->nid) . '"><img src="' . $src . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/></a>';
        }
        if ($count == 1 || $count == 2) {
          $popup = 1;
        }

        $node = node_load($data->nid);
        $date = $node->field_date[0]['value'] ? $node->field_date[0]['value'] : $node->created;
        $content = $image . '<div class="text"><h3>' . l($data->title, 'node/' . $data->nid, array('html' => TRUE)) . '</h3><div class="date">' . date("d.m.y", $date) . '</div>' . ($popup ? $data->teaser : '') . '</div>';
        break;
      case 'lupdate':
        $node = node_load($data->nid);
        $date = $node->field_date[0]['value'] ? $node->field_date[0]['value'] : $node->field_l_date[0]['value'];
        $content = '<div class="u-right"><h3>' . l($data->title, 'node/' . $data->nid) . '</h3><div class="date">' . date("d.m.y", $date) . '</div></div>';
        break;
      case 'publication':
        $type = strtoupper(substr($data->filemime, strrpos($data->filemime, '/') + 1));
        $size = round($data->filesize / 1000, 1) . ' KB';
        $controls = '';
        if (user_access('edit any publication content')) {
          $controls = '<div class="controls">' . l(t('Edit'), 'node/' . $data->nid . '/edit', array('query' => drupal_get_destination())) . '</div>';
        }

        $node = node_load($data->nid);
        $date = $node->field_date[0]['value'] ? $node->field_date[0]['value'] : $node->field_p_date[0]['value'];

        $content = '<h3>' . $data->title . ' [' . $type . ' ' . $size . ']</h3>' . $controls . '<div class="date">' . date("d.m.y", $date) . '</div><div class="text">' . $data->body . '</div>' . l('&raquo; Download ' . $data->title . ' document', $data->filepath, array('attributes' => array('class' => 'download', 'target' => '_blank'), 'html' => TRUE));
        break;
      case 'video';
        $image = '&nbsp;';
        $vdata = br_get_video_data($data->field_video_url_value, $data->filepath ? '/' . $data->filepath : '');
        $controls = '';
        if ($mobile) {
          $content = $vdata['embed'] . '<h3>' . $data->title . '</h3><div class="desc">' . strip_tags($data->body) . '</div>';
        }
        else {
          if (user_access('edit any publication content')) {
            $controls = '<div class="controls">' . l(t('Edit'), 'node/' . $data->nid . '/edit', array('query' => drupal_get_destination())) . '</div>';
          }
          $thumbnail_img = '';
          if (strpos($vdata['thumbnail'], 'http') === 0) {
            $thumbnail_img = $vdata['thumbnail'];
          }
          else {
            $thumbnail_img = imagecache_create_url('video-list', ltrim($vdata['thumbnail'], '/'));
          }
          $content = $controls . '<div class="col-left"><h3>' . $data->title . '</h3><div class="desc">' . strip_tags($data->body) . '</div></div><div class="col-right"><a target="_blank" href="' . $data->field_video_url_value . '"><div class="img"><img src="' . $thumbnail_img . '" alt="' . check_plain($data->title) . '" title="' . check_plain($data->title) . '"/><span>' . drupal_to_js(array('video' => $vdata['embed'])) . '</span></div></a></div><div class="ff"></div>';
        }

        break;
      default:
        $content = l($data->title, 'node/' . $data->nid, array('html' => TRUE));
        break;
    }
  }
  return '<div class="item' . ($popup && $popup == 1 ? ' featured' : '') . ($count ? ' item-' . $count : '') . '">' . $content . '</div>';
}

function br_book_link($data) {
  if ($_SESSION['seminars'][$data->nid]) {
    $title = 'remove';
  }
  else {
    $title = 'Add to Basket';
  }

  return l($title, $_GET['q'], array('query' => 'book-seminar=' . $data->nid . '&' . drupal_get_destination(), 'attributes' => array('class' => 'book')));
}

function br_search($type) {
  $title = 'Filter';
  switch ($type) {
    case 'people':
      $path = 'node/3';
      $title = 'People filters';
      break;
    case 'cs':
      $path = 'node/3126';
      $title = 'Cases filters';
      break;
    case 'event':
      $path = 'node/44';
      $title = 'Seminar search';
      break;
    case 'lupdate':
      $path = 'node/63';
      $title = 'Legal Updates Search';
      break;
    case 'publication':
      $path = 'node/64';
      $title = 'Publications Archive Search';
      break;
    case 'video':
      $path = 'node/594';
      $title = 'Search';
      break;
    case 'win':
      $path = 'recent-wins';
      $title = 'Filter';
      break;
    case 'download':
      $path = 'guides-and-downloads';
      $title = 'Search for Guides and Resources';
      break;
  }

  if (count($_GET) > 1) {
    $clear .= '<div class="clear">' . l('Clear filters', $path) . '</div>';
  }

  return '<div class="submenu"><h2>' . l($title, $path) . '</h2><input type="hidden" id="search_path" value="' . check_plain(url($path)) . '" />' . drupal_get_form('br_search_form', $type) . $clear . '</div>';
}

function br_search_form($form_state, $type) {
  drupal_add_js("
  $(document).ready(function(){
    $('#content .left select.form-select').ieSelectWidth
    ({
        containerClassName : 'select-container',
        overlayClassName : 'select-overlay'
    });
  }
  );
  ", 'inline');

  $form = array();

  $form['sector'] = array(
    '#type' => 'select',
    '#options' => array('' => 'Sector') + br_node_options_list('sector', $type),
    '#default_value' => $_GET['sector'],
    '#weight' => 10
  );

  $form['service'] = array(
    '#type' => 'select',
    '#options' => array('' => 'Service') + br_node_options_list('service', $type),
    '#default_value' => $_GET['service'],
    '#weight' => 20
  );

  if (count($form['service']['#options']) == 1) {
    unset($form['service']);
  }

  if (count($form['sector']['#options']) == 1) {
    unset($form['sector']);
  }

  switch ($type) {
    case 'people':
      $form['a-z'] = array(
        '#type' => 'select',
        '#options' => array('' => t('Search by A-Z'), 'ad' => t('A-D'), 'eh' => t('E-H'), 'il' => t('I-L'), 'mp' => t('M-P'), 'qt' => t('Q-T'), 'uz' => t('U-Z')),
        '#default_value' => $_GET['a-z'],
        '#weight' => 5
      );
      //$form['service']['#weight'] = 8;     
      $form['partners'] = array(
        '#type' => 'checkbox',
        '#prefix' => '<div class="label partners">Partners</div>',
        '#default_value' => $_GET['partners'],
        '#weight' => 25
      );
      break;
    case 'event':
      unset($form['service']);
      $seminars = $_REQUEST['q'] == 'seminars-and-events';

      //$form['services'] = array('#value' => '<ul><li>' . l('Seminars', 'node/44', array('html' => TRUE)) . '</li></ul>', '#weight' => 5);
      unset($form['sector']);
      $sql = "SELECT nid, title, type FROM node where status = 1
      and nid in (SELECT field_related_sector_nid FROM content_field_related_sector rs
      INNER JOIN content_type_event cs on cs.vid = rs.vid) OR nid in (SELECT field_related_service_nid FROM content_field_related_service rs
      INNER JOIN content_type_event cs on cs.vid = rs.vid) order by type desc, title ASC";
      $result = db_query($sql);
      $options = array('' => 'Category');
      while ($data = db_fetch_object($result)) {
        $options[ucfirst($data->type)][$data->nid] = $data->title;
      }

      $form['category'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $_GET['category'],
        '#weight' => 10
      );

      $weight = (arg(0) == 'node' && arg(1) == 47) ? 8 : 35;


      $form['events'] = array('#value' => '<ul><li>' . l('Events', 'node/47', array('html' => TRUE)) . '</li></ul>', '#weight' => $weight);
      if (!db_result(db_query("SELECT count(*) FROM content_type_event e inner join node n on n.vid = e.vid and status = 1 WHERE field_event_type_value = 'event' "))) {
        $form['events']['#access'] = FALSE;
      }
      $form['location'] = array(
        '#type' => 'select',
        '#options' => array('' => 'Location') + br_node_options_list('location'),
        '#default_value' => $_GET['location'],
        '#weight' => 12
      );

      $dates = array('' => 'Date');
      $sql = "SELECT distinct(field_event_date_value) FROM {content_type_event} e INNER JOIN node n on n.vid = e.vid where field_event_date_value > %d and status = 1 AND field_event_type_value='" . ($seminars ? 'seminar' : 'event') . "' order by field_event_date_value ASC";
      $result = db_query($sql, time());
      while ($data = db_fetch_object($result)) {
        $dates[$data->field_event_date_value] = date('l j F Y', $data->field_event_date_value);
      }

      $form['date'] = array(
        '#type' => 'select',
        '#options' => $dates,
        '#default_value' => $_GET['location'],
        '#weight' => 14
      );
      break;
    case 'lupdate':
      unset($form['service'], $form['sector']);
      $form['legal-area'] = array(
        '#type' => 'select',
        '#title' => 'Legal Update Area',
        '#options' => array('' => 'All Legal Update Areas') + br_node_options_list('larea'),
        '#default_value' => $_GET['legal-area'],
        '#weight' => 20
      );

      $form['year'] = array(
        '#type' => 'select',
        '#title' => 'Year',
        '#options' => array('' => 'View all years') + br_get_distinct(),
        '#default_value' => $_GET['year'],
        '#weight' => 21
      );

      $form['keyword'] = array(
        '#type' => 'textfield',
        '#title' => 'Search by Keyword',
        '#default_value' => $_GET['keyword'],
        '#weight' => 22,
        '#attributes' => array('placeholder' => 'Search by Keyword')
      );

      $form['sort'] = array(
        '#type' => 'select',
        '#title' => 'Sort By',
        '#options' => array('' => 'Date (most recent first)', 'date-recent-last' => 'Date (most recent last)', 'heading-az' => 'Heading (A - Z)', 'heading-za' => 'Heading (Z - A)'),
        '#default_value' => $_GET['sort'],
        '#weight' => 23
      );

      break;
    case 'publication':
      unset($form['service'], $form['sector']);
      $form['area'] = array(
        '#type' => 'select',
        '#title' => 'Area',
        '#options' => array('' => 'All Areas') + br_node_options_list('parea'),
        '#default_value' => $_GET['area'],
        '#weight' => 20
      );

      $form['year'] = array(
        '#type' => 'select',
        '#title' => 'Year Published',
        '#options' => array('' => 'View all years') + br_get_distinct('content_type_publication', 'YEAR(from_unixtime(field_p_date_value))'),
        '#default_value' => $_GET['year'],
        '#weight' => 21
      );

      break;
    case 'download';
      $form['keyword'] = array(
        '#type' => 'textfield',
        '#title' => 'Search by Keyword',
        '#default_value' => $_GET['keyword'],
        '#weight' => 22,
          //'#attributes' => array('placeholder' => 'Search by Keyword')
      );

      $categories = array();
      foreach (taxonomy_get_tree(3) as $term) {
        if (db_result(db_query('SELECT nid FROM term_node where tid=' . $term->tid . ' '))) {
          $categories[$term->tid] = ucfirst($term->name);
        }
      }

      $form['category'] = array(
        '#type' => 'select',
        '#title' => 'Filter your search',
        '#default_value' => $_GET['category'],
        '#options' => array('' => 'Categories') + $categories,
        '#weight' => 23,
        '#suffix' => '<div class="ff"></div>',
          //'#attributes' => array('placeholder' => 'Search by Keyword')
      );

      unset($form['service'], $form['sector']);
      break;
  }

  return $form;
}

function br_get_distinct($table = 'content_type_lupdate', $field = 'YEAR(from_unixtime(field_l_date_value))') {
  $dates = array();
  $cid = 'br_legal_' . $table . $field;
  $cache = cache_get($cid);
  if ($cache->data) {
    $dates = $cache->data;
  }
  else {
    $result = db_query('SELECT distinct ' . $field . ' as lyear FROM {' . $table . '} order by lyear DESC');
    while ($data = db_fetch_object($result)) {
      $dates[$data->lyear] = $data->lyear;
    }
    $cache = cache_set($cid, $dates);
  }
  return $dates;
}

function br_node_options_list($type, $stype = FALSE) {
  $options = array();

  $sql = "SELECT nid, title FROM {node} where type='%s' and status = 1 order by title ASC";
  if ($stype == 'cs') {
    if ($type == 'sector') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_sector_nid FROM content_field_related_sector rs
INNER JOIN content_type_cs cs on cs.vid = rs.vid) order by title ASC";
    }
    elseif ($type == 'service') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_service_nid FROM content_field_related_service rs
INNER JOIN content_type_cs cs on cs.vid = rs.vid) order by title ASC";
    }
  }

  if ($stype == 'video') {
    if ($type == 'sector') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_sector_nid FROM content_field_related_sector rs
INNER JOIN content_type_video cs on cs.vid = rs.vid) order by title ASC";
    }
    elseif ($type == 'service') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_service_nid FROM content_field_related_service rs
INNER JOIN content_type_video cs on cs.vid = rs.vid) order by title ASC";
    }
  }

  if ($stype == 'win') {
    if ($type == 'sector') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_sector_nid FROM content_field_related_sector rs
INNER JOIN content_type_win cs on cs.vid = rs.vid) order by title ASC";
    }
    elseif ($type == 'service') {
      $sql = "SELECT nid, title FROM node where status = 1
and nid in (SELECT field_related_service_nid FROM content_field_related_service rs
INNER JOIN content_type_win cs on cs.vid = rs.vid) order by title ASC";
    }
  }

  $result = db_query($sql, $type);
  while ($data = db_fetch_object($result)) {
    $options[$data->nid] = $data->title;
  }

  return $options;
}

function br_people_page($node) {
  if (br_popup_request_check()) {
    $out .= '<h1>' . $node->title . '</h1>';
  }

//  $photo_path = $node->field_teaser_image[0]['filepath'];
//  if ($photo_path) {
//    $filepath = imagecache_create_url('people-page-photo', $photo_path);
//    $out .= '<div class="picture"><img src="' . $filepath . '" alt="' . check_plain($node->title) . '" title="' . check_plain($node->title) . '" /></div>';
//  }

  $fields = array(
    'Service' => 'field_related_service',
    'Sector' => 'field_related_sector',
    'Location' => 'field_people_location',
    'Job' => 'field_people_job',
    'Direct line' => 'field_people_phone',
    'Email address' => 'field_people_email',
  );

  $count = 0;
  foreach ($fields as $name => $field_data) {
    $value = $node->{$field_data}[0]['value'];
    //filepath    
    if ($node->{$field_data}[0]['filepath']) {
      $value = l('Download vCard', $node->{$field_data}[0]['filepath'], array('attributes' => array('target' => '_blank')));
    }
    else if ($node->{$field_data}[0]['nid']) {
      $glue = $value = '';
      foreach ($node->{$field_data} as $item) {
        $nid = $item['nid'];
        if ($node->field_relation_exclude[0]['nid']) {
          foreach ($node->field_relation_exclude as $ex_nid) {
            if ($ex_nid['nid'] == $nid) {
              continue 2;
            }
          }
        }
        $title = db_result(db_query("SELECT title FROM {node} WHERE nid = %d ", $nid));
        $value .= $glue . ($field_data == 'field_people_location' ? $title : l($title, 'node/' . $nid));
        $glue = ', ';
      }
    }

    if ($field_data == 'field_people_email') {
      $value = l($value, 'mailto:' . $value);
    }

    if ($value)
      $out .= '<div class="field"><h3>' . $name . ':</h3><p>' . $value . '</p></div>' . ( ++$count % 2 == 0 ? ' <div class="ff"></div>' : '');
  }

  $out .= '<div class="ff"></div><div class="bio">' . $node->content['body']['#value'] . '</div>';

  return $out;
}

function br_edit_content($type, $filter = '') {
  $output = '';

  $access = 'edit any ' . $type . ' content';
  $type_name = str_replace('_', ' ', $type);

  $title = t('Editing @content_name content', array('@content_name' => $type_name));

  $intro = l(t(' + Add new @type content', array('@type' => $type_name)), 'node/add/' . str_replace('_', '-', $type), array('attributes' => array('class' => 'edit-btn'), 'query' => 'destination=content/edit/' . $type))
      . ' ' . t('or reorder, remove existing items using table below');

  switch ($type) {
    case 'enquiry':
      $intro = '';
      $title = t('Enquiries :: @type', array('@content_name' => $type_name, '@type' => ucwords(str_replace('-', ' ', $filter))));
      break;
  }

  if (!user_access($access)) {
    return t('You don\'t have permission to access this page');
  }

  drupal_set_title($title);
  //get all type nodes in form/table with remove checkbox and edit link
  $output .= '<p>' . $intro . '</p>';
  $output .= drupal_get_form('br_content_edit_form', $type, $filter);

  return $output;
}

function br_content_edit_form($form_state, $type, $filter = '') {
  $form = array();
  $order = TRUE;
  $csv = $_GET['CSV'] ? TRUE : FALSE;
  $csv_data = array();
  $type_order_field = !$type_order_field ? 'field_' . $type . '_order_value' : $type_order_field;
  $sort = TRUE;
  $filter_sql = '';

  $sql = "SELECT * FROM {content_type_" . $type . "} c               
          LEFT JOIN {node} n ON c.nid = n.nid           
          " . ($type_order_field ? "ORDER BY " . $type_order_field : "");

  //some alternations            
  switch ($type) {
    case 'slide':
      $sql = "SELECT * FROM {content_type_" . $type . "} c               
          LEFT JOIN {node} n ON c.nid = n.nid
          LEFT JOIN {files} f on f.fid = c.field_slide_image_fid            
          " . ($type_order_field ? "ORDER BY " . $type_order_field : "");
      break;
    case 'enquiry':
      if ($filter) {
        $types_nr = array('contact-us' => '1');
        $type_nr = $types_nr[$filter];

        $filter_sql .= ' WHERE field_enq_type_value = ' . $type_nr;
      }

      $sql = "SELECT c.*, n.*, nr.* FROM {content_type_" . $type . "} c               
          LEFT JOIN {node} n ON c.nid = n.nid
          LEFT JOIN {node_revisions} nr ON n.vid = nr.vid
          " . $filter_sql . "                         
          ORDER BY created DESC";
      $order = FALSE;

      break;
  }

  $result = db_query($sql);

  $form['list']['#tree'] = TRUE;
  $form['list']['#theme'] = 'br_content_edit_draggable_form';
  $count = 0;

  while ($data = db_fetch_object($result)) {
    $form['list'][$data->nid]['title'] = array('#value' => $data->title);

    $form['list'][$data->nid]['edit'] = array('#value' => l(t('Edit'), 'node/' . $data->nid . '/edit', array('query' => 'destination=content/edit/' . $type, 'attributes' => array('class' => 'edit'))));
    $form['list'][$data->nid]['remove'] = array('#type' => 'checkbox', '#default_value' => $data->status);
    $form['list'][$data->nid]['#row_status'] = !$data->status ? 'unpublished' : '';

    if ($type == 'slide') {
      $form['list'][$data->nid]['image'] = array('#value' => '<img src="' . imagecache_create_url('related-cs-thumb', $data->filepath) . '" />');
    }

    if ($type_order_field && $order)
      $form['list'][$data->nid]['sort'] = array('#type' => 'weight', '#delta' => 50,
        '#default_value' => $data->$type_order_field);
  }


  $form['type'] = array(
    '#type' => 'hidden',
    '#value' => $type
  );

  $form['list']['#edit_type'] = $type;
  $form['list']['#filter'] = $filter;
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function br_content_edit_form_submit($form_state, $form_values) {
  $type = $form_values['values']['type'];

  $type_order_field = '';

  switch ($type) {
    default:
      $type_order_field = 'field_' . $type . '_order_value';
      break;
  }

  foreach ($form_values['values']['list'] as $nid => $values) {
    db_query("UPDATE {node} set status = %d where nid = %d", $values['remove'], $nid);

    if ($type_order_field) {
      db_query("UPDATE {content_type_" . $type . "} set " . $type_order_field . " = %d where nid = %d", $values['sort'], $nid);
    }
  }

  drupal_set_message(t('Data updated'));
}

function theme_br_content_edit_draggable_form($form) {

  switch ($form['#edit_type']) {
    case 'slide':
      $header = array('', t('Image'), t('Title'), t('Published'), t('Edit'), t('Sort'));
      $fields = array('image', 'title', 'remove', 'edit', 'sort');
      break;
    default:
      $header = array('', t('Title'), t('Published'), t('Edit'), t('Sort'));
      $fields = array('title', 'remove', 'edit', 'sort');
      break;
  }

  if (array_search('sort', $fields) !== FALSE) {
    drupal_add_tabledrag('edit-sort', 'order', 'sibling', 'sort');
  }

  foreach (element_children($form) as $key) {
    // Add class to group weight fields for drag and drop.
    $row = array();
    if (array_search('sort', $fields) !== FALSE) {
      $row[] = ''; //This is important. We need to start with an empty element for the drag handle.
      $form[$key]['sort']['#attributes']['class'] = 'sort';
    }

    foreach ($fields as $field_name) {
      $row[] = drupal_render($form[$key][$field_name]);
    }

    $rows[] = array('data' => $row, 'class' => (array_search('sort', $fields) !== FALSE ? 'draggable ' : '') . $form[$key]['#row_status']); //note the difference between $row and $rows
  }

  if (count($rows))
    $output = theme('table', $header, $rows, array('id' => 'edit-sort', 'class' => 'content_edit', 'cellspacing' => 1));


  $output .= drupal_render($form);
  return $output;
}

function dateToCal($timestamp) {
  date_default_timezone_set('UTC');
  $cal_date = date('Ymd\THis\Z', $timestamp);
  return $cal_date;
}

// Escapes a string of characters
function escapeString($string) {
  return preg_replace('/([\,;])/', '\\\$1', $string);
}

function br_event_page($node) {



  if (!empty($_GET['calendar'])) {
    $cal_dtstart = dateToCal($node->field_event_date[0]['value']);
    $cal_dtend = dateToCal($node->field_event_date[0]['value2']);
    $cal_uid = $node->uid;
    $cal_location = escapeString(strip_tags(nl2br($node->field_event_l_details[0]['value'])));
    //$cal_description = escapeString(strip_tags(nl2br($node->teaser)));
    $cal_description = '';
    $cal_url = escapeString(url($_GET['q'], array('absolute' => TRUE)));
    $cal_summary = escapeString(strip_tags(nl2br($node->title)));
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
LOCATION:' . $cal_location . '
DESCRIPTION:' . $cal_description . '
URL;VALUE=URI:' . $cal_url . '
SUMMARY:' . $cal_summary . '
END:VEVENT
END:VCALENDAR';
      exit();
    }

    if ($_GET['calendar'] == 'vcal') {
      header("Content-Type: text/x-vCalendar");
      header("Content-Disposition: inline; filename=vcal.vcs");
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
LOCATION:' . $cal_location . '
DESCRIPTION:' . $cal_description . '
URL;VALUE=URI:' . $cal_url . '
SUMMARY:' . $cal_summary . '
END:VEVENT
END:VCALENDAR';
      exit();
    }
  }
  $out = '<div class="text">' . $node->content['body']['#value'] . '</div>';
  $calendar_links = '<span class="calendars">' . l('iCalendar', $_GET['q'], array('query' => 'calendar=ical')) . '<br />' . l('vCalendar', $_GET['q'], array('query' => 'calendar=vcal')) . '</span>';
  $details = array(
    'When' => date('l j F Y', $node->field_event_date[0]['value']),
    'Time' => date('H:i', $node->field_event_date[0]['value']) . ' - ' . date('H:i', $node->field_event_date[0]['value2']),
    'Where' => db_result(db_query("SELECT title FROM {node} where nid = %d", $node->field_event_location[0]['nid'])), ' ' => $node->field_event_l_details[0]['value'],
    'Add to calendar' => $calendar_links
  );
  $book = '';
  $book_form = '';
  if ($node->field_event_type[0]['value'] == 'seminar') {
    if ($node->field_event_full[0]['value']) {
      if (isset($_GET['seminar-waiting-list'])) {
        $book_form.= drupal_get_form('br_waiting_list_form', $node);
        $book_form .= '<div class="ff"></div>';
      }
      else {
        $book = '<div class="ff"></div>';
        if ($node->field_event_full[0]['value']) {
          $book .= '<div class="booked info">Fully booked</div>';
        }
        $book .= l('Seminar waiting list', $_GET['q'], array('query' => 'seminar-waiting-list=' . $data->nid . '&' . drupal_get_destination(), 'attributes' => array('class' => 'booked')));
        ;
      }
    }
    else {
      $book .= br_book_link($node);
    }
  }
  $out .= '<div class="details">';
  foreach ($details as $label => $value) {
    if ($value) {
      $out .= '<div><div>' . ($label != ' ' ? $label . ':' : '&nbsp;') . '</div><span>' . $value . '</span></div>';
    }
  }
  $out .= $book . '</div><div class="ff"></div>';
  $out .= $book_form;
  if ($node->field_event_speakers[0]['nid']) {
    $out .= '<div class="speakers"><b>Speakers:</b>';
    $result = db_query("SELECT ns.title, p.*
,
(SELECT GROUP_CONCAT(n1.title SEPARATOR ', ') FROM content_field_related_sector rs
  INNER JOIN node n1 on n1.nid = rs.field_related_sector_nid WHERE rs.vid = p.vid ORDER by title ) as sectors
,
(SELECT GROUP_CONCAT(n1.title SEPARATOR ', ') FROM content_field_related_service rs
  INNER JOIN node n1 on n1.nid = rs.field_related_service_nid WHERE rs.vid = p.vid ORDER by title ) as services
  
FROM content_field_event_speakers s
INNER JOIN node n on n.vid = s.vid and n.status = 1 and n.nid = %d
LEFT JOIN node ns on ns.nid = field_event_speakers_nid
LEFT JOIN content_type_people p on p.vid = ns.vid order by delta", $node->nid);
    while ($data = db_fetch_object($result)) {
      $extra = array();
      if ($data->field_people_partner_value) {
        $extra[] = 'Partner';
      }

      if ($data->sectors) {
        $extra[] = $data->sectors;
      }

      if ($data->services) {
        $extra[] = $data->services;
      }

      $out .= '<div class="field"><div>' . l($data->title, 'node/' . $data->nid) . '</div>' . (count($extra) ? ' <span class="extra">' . implode(', ', $extra) . '</span>' : '') . '<div class="ff"></div></div>';
    }
    $out .= '</div><div class="ff"></div>';
  }

  if ($node->field_event_audience[0]['value']) {
    $out .= '<div class="audience"><b>Audience:</b>';
    foreach ($node->field_event_audience as $data) {
      $out .= '<div>' . $data['value'] . '</div>';
    }
    $out .= '</div>';
  }

  if ($node->field_related_sector[0]['nid']) {
    $out .= '<div class="audience"><b>Sectors:</b>';
    foreach ($node->field_related_sector as $data) {
      $out .= '<div>' . db_result(db_query("SELECT title FROM {node} where nid = %d", $data['nid'])) . '</div>';
    }
    $out .= '</div>';
  }

  if ($node->field_related_service[0]['nid']) {
    $out .= '<div class="audience services"><b>Services:</b>';
    foreach ($node->field_related_service as $data) {
      $out .= '<div>' . db_result(db_query("SELECT title FROM {node} where nid = %d", $data['nid'])) . '</div>';
    }
    $out .= '</div>';
  }

  if ($node->field_event_guest[0]['value']) {
    $out .= '<div class="guest">' . $node->field_event_guest[0]['value'] . '</div>';
  }
  return $out;
}

function br_waiting_list_form($form_init, $event) {
  $form = array();
  $form['intro'] = array('#value' => '<h2>Please fill in the form below and we\'ll place you on our seminar waiting lis. We will inform you as soon as possible if a space arises.</h2><p>Fields marked with <span class="form-required">*</span> are required.</p>');
  $form['#attributes'] = array('class' => 'custom-form');
  $form['first-name'] = array(
    '#type' => 'textfield',
    '#title' => 'First name',
    '#required' => TRUE,
    '#weight' => 10,
  );

  $form['last-name'] = array(
    '#type' => 'textfield',
    '#title' => 'Last Name',
    '#required' => TRUE,
    '#weight' => 20,
  );

  $form['company'] = array(
    '#type' => 'textfield',
    '#title' => 'Company',
    '#required' => TRUE,
    '#weight' => 25,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#required' => TRUE,
    '#weight' => 40,
  );

  $form['telephone-number'] = array(
    '#type' => 'textfield',
    '#title' => 'Telephone Number',
    '#required' => TRUE,
    '#weight' => 50,
  );

  $form['captcha'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'image_captcha/Image',
    '#title' => '',
    '#weight' => 60,
  );

  $form['event'] = array(
    '#type' => 'value',
    '#value' => $event,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#weight' => 70,
    '#prefix' => '<div class="ff"></div>'
  );

  return $form;
}

function br_waiting_list_form_validate($form_state, $form_values) {
  $email = $form_values['values']['email'];

  if (!valid_email_address($email)) {
    form_set_error('email', 'Enter valid email address');
  }
}

function br_waiting_list_form_submit($form_init, $form_values) {
  global $user;
  $values = $form_values['values'];
  $event = $values['event'];
  unset($form_values['values']['event']);

  $form_values['values']['submission-time'] = date("Y-m-d H:i", time());
  $params['contact_details'] = $form_values['values'];
  $params['contact_details']['related seminar'] = $event->title . ' ' . url('node/' . $event->nid, array('absolute' => TRUE));
  $admin_email = 'contact@brodies.com';

  drupal_mail('br', 'waiting-list', $admin_email, language_default(), $params);

  //redirect to thank you
  unset($_REQUEST['destination']);
  drupal_goto('thank-you-waiting-list');
}

function br_events_checkout() {
  if (isset($_GET['clear'])) {
    unset($_SESSION['seminars']);
    drupal_goto();
  }

  if ($_GET['book-seminar']) {
    if (db_result(db_query("SELECT n.nid FROM {node} n INNER JOIN content_type_event e on e.vid = n.vid WHERE field_event_type_value = 'seminar' AND n.nid = %d", $_GET['book-seminar']))) {
      if ($_SESSION['seminars'][$_GET['book-seminar']]) {
        unset($_SESSION['seminars'][$_GET['book-seminar']]);
      }
      else {
        $_SESSION['seminars'][$_GET['book-seminar']] = $_GET['book-seminar'];
      }
      drupal_goto();
    }
  }

  $nr = count($_SESSION['seminars']);
  $out = '<div class="checkout"><h2>Basket</h2><div class="basket-items">You have ' . (int) $nr . ' ' . format_plural($nr, 'seminar', 'seminars') . ' on your list.' . ($nr ? l('Clear basket', $_GET['q'], array('attributes' => array('class' => 'clear'), 'query' => 'clear&' . drupal_get_destination())) . l('Confirm', 'seminars-and-events/checkout', array('attributes' => array('class' => 'checkout'), 'query' => drupal_get_destination())) : '') . '</div></div>';
  return $out;
}

function br_page_seminars_checkout() {
  $sdata = $_SESSION['seminars'];
  $out = '<div class="node">';
  if (mis_is_mobile()) {
    $out .= '<div class="back"><a href="' . url('node/44') . '">&laquo; Back</a></div>';
  }
  if (count($sdata)) {
    $out .= '<p>You are about to book places on the following ' . format_plural(count($sdata), 'seminar', 'seminars') . '</p>';
    $out .= '<div class="seminars">';
    foreach ($sdata as $nid) {
      $out .= '<div><span>' . l(db_result(db_query("SELECT title FROM {node} n where nid = %d", $nid)), 'node/' . $nid) . '</span>' . br_book_link((object) array('nid' => $nid)) . '<div class="ff"></div></div>';
    }
    $out .= '</div><p>Please remove any seminars you are no longer interested in.</p>';
    $out .= drupal_get_form('br_seminars_form');
  }
  else {
    $out .= 'No seminars selected yet';
  }
  $out .= '</div>';

  return $out;
}

function br_seminars_form() {

  $form = array();
  $form['intro'] = array('#value' => '<h2>Your details</h2><p>Fields marked with <span class="form-required">*</span> are required.</p>');
  $form['#attributes'] = array('class' => 'custom-form');
  $form['first-name'] = array(
    '#type' => 'textfield',
    '#title' => 'First name',
    '#required' => TRUE,
  );

  $form['surname'] = array(
    '#type' => 'textfield',
    '#title' => 'Surname',
    '#required' => TRUE,
  );

  $form['position'] = array(
    '#type' => 'textfield',
    '#title' => 'Position',
    '#required' => TRUE,
  );

  $form['company'] = array(
    '#type' => 'textfield',
    '#title' => 'Company',
    '#required' => TRUE,
  );

  $form['address-line-1'] = array(
    '#type' => 'textfield',
    '#title' => 'Address Line 1',
    '#required' => TRUE,
  );

  $form['address-line-2'] = array(
    '#type' => 'textfield',
    '#title' => 'Address Line 2',
  );

  $form['address-line-3'] = array(
    '#type' => 'textfield',
    '#title' => 'Address Line 3',
  );

  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => 'City',
    '#required' => TRUE,
  );

  $form['postcode'] = array(
    '#type' => 'textfield',
    '#title' => 'Postcode',
    '#required' => TRUE,
  );

  $form['telephone-number'] = array(
    '#type' => 'textfield',
    '#title' => 'Telephone Number',
    '#required' => TRUE,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

function br_seminars_form_validate($form_state, $form_values) {
  $email = $form_values['values']['email'];

  if (!valid_email_address($email)) {
    form_set_error('email', 'Enter valid email address');
  }
}

function br_seminars_form_submit($form_state, $form_values) {
  global $user;
  $values = $form_values['values'];

  //send email
  $form_values['values']['submission-time'] = date("Y-m-d H:i", time());
  $params['contact_details'] = $form_values['values'];


  $out = $values['first-name'] . " " . $values['surname'] . " from IP address " . $_SERVER['REMOTE_ADDR'] . " booked the following seminars:<table border='1'>
<tr><td>Name</td><td>Location</td><td>Time & Date</td><td>Places</td></tr>";
  foreach ($_SESSION['seminars'] as $nid) {
    $data = db_fetch_object(db_query("SELECT n.title, field_event_date_value as timestart, field_event_date_value2 as timeend, n1.title as location FROM node n INNER join content_type_event e on n.vid = e.vid left join node n1 on n1.nid = e.field_event_location_nid where n.nid = %d", $nid));
    $out .= "<tr>";
    $out .= "<td>" . l($data->title, 'node/' . $nid, array('absolute' => TRUE)) . "</td>";
    $out .= "<td>" . $data->location . "</td>";
    $out .= "<td>" . date('d M Y H:i', $data->timestart);
    if (isset($data->timeend)) {
      $out .= ' - ' . date('d M Y H:i', $data->timeend);
    }
    $out .= "</td>";
    $out .= "<td>1</td></tr>";
  }
  $out .= '</table><br><br>
  <b>Lead Delegate</b><br>
<br>
<table border="1" width="100%">
<tbody>
<tr>
<td width="50%">Name:</td>
<td width="50%">' . $values['first-name'] . " " . $values['surname'] . '</td>
</tr>
<tr>
<td>Email:</td>
<td>' . $values['email'] . '</td>
</tr>
<tr>
<td>Contact Telephone Number:</td>
<td>' . $values['telephone-number'] . '</td>
</tr>
<tr>
<td>Position:</td>
<td>' . $values['position'] . '</td>
</tr>
<tr>
<td>Company:</td>
<td>' . $values['company'] . '</td>
</tr>
<tr>
<td>Address Line 1:</td>
<td>' . $values['address-line-1'] . '</td>
</tr>
<tr>
<td>Address Line 2:</td>
<td>' . $values['address-line-2'] . '</td>
</tr>
<tr>
<td>Address Line 3:</td>
<td>' . $values['address-line-3'] . '</td>
</tr>
<tr>
<td>City:</td>
<td>' . $values['city'] . '</td>
</tr>
<tr>
<td>Postcode:</td>
<td>' . $values['postcode'] . '</td>
</tr>
</tbody>
</table>';
  $params['seminars'] = $out;
  unset($_SESSION['seminars']);

  $admin_email = 'seminars@brodies.com';
  //$admin_email = 'callum@sakurabrae.co.uk';
  drupal_mail('br', 'seminars-checkout-admin', $admin_email, language_default(), $params);

  //redirect to thank you
  $_REQUEST['destination'] = 'thank-you-checkout';
  drupal_goto('thank-you-checkout');
}

function br_news_submenu($mobile = FALSE) {
  $options = br_node_options_list('cnews');
  $ltitle = 'Recent News Categories';
  if (count($options)) {
    foreach ($options as $nid => $title) {
      $llinks .= '<li>' . l($title, 'node/' . $nid, array('html' => TRUE)) . '</li>';
    }
  }
  else {
    $llinks = '<li>No related services</li>';
  }
  return (!$mobile ? '<h2>' . $ltitle . '</h2>' : '') . '<ul>' . $llinks . '</ul>';
}

function br_print_news($data, $count) {
  $out = '';
  if ($count == 0) {
    if ($data->filepath) {
      $filepath = imagecache_create_url('news-display-main', $data->filepath);
    }
    $out = '<div class="f-item ' . (!$filepath ? 'no-image' : '') . '" ' . ($filepath ? 'style="background-image:url(\'' . $filepath . '\')"' : '') . '><div class="blue"><h1>' . l($data->title, 'node/' . $data->nid) . '</h1>' . $data->teaser . l('Read more &raquo;', 'node/' . $data->nid, array('html' => TRUE)) . '</div></div>';
  }
  else {
    $filepath = imagecache_create_url('news-display-other', $data->filepath);
    $out = '<div class="f-item" style="background-image:url(\'' . $filepath . '\')"><div class="blue"><h2>' . l($data->title, 'node/' . $data->nid) . '</h2></div></div>';
  }


  return $out;
}

function br_overview_page($node) {
  $type = $node->field_over_type[0]['value'];
  if ($type != 'hp') {
    if ($type == 'news') {
      $mobile = mis_is_mobile();
      $left = br_news_submenu($mobile);
      if ($mobile) {
        $out .= '<div class="back"><a href="' . url('<front>') . '">&laquo; Back</a></div>';
        $out .= '<div class="news">
          <div class="left">' . $left . '</div>                  
          <div class="ff"></div>
       </div>';
      }
      else {
        $news = array();
        if ($node->field_over_news[0]['nid']) {
          foreach ($node->field_over_news as $data) {
            $news[$data['nid']] = $data['nid'];
          }
        }

        $result = db_query("SELECT n.nid, n.title, nr.teaser, filepath FROM {node} n INNER JOIN {content_type_news} s on s.vid = n.vid LEFT JOIN {content_field_teaser_image} ti on ti.vid = s.vid LEFT JOIN {files} f on ti.field_teaser_image_fid = f.fid LEFT JOIN {node_revisions} nr on nr.vid = n.vid WHERE n.status = 1 and n.nid in (" . implode(',', $news) . ")");
        while ($data = db_fetch_object($result)) {
          $news[$data->nid] = br_print_news($data, array_search($data->nid, array_keys($news)));
        }

        $news = array_values($news);

        $out = '<div class="news">
          <div class="left">' . $left . '</div>
          <div class="middle">          
            ' . $news[0] . '          
          </div>
          <div class="right">
            ' . $news[1] . $news[2] . '
          </div>        
          <div class="ff"></div>
       </div>';
      }
    }
    else {
      $filter = '';
      $rpp = 8;
      if ($type == 'service') {
        $filter = " INNER JOIN menu_links ml on ml.link_path = concat('node/', s.nid) and depth = 2 ";
      }

      $result = db_query("SELECT n.nid, n.title, field_" . $type . "_teaser_value, f.filepath FROM {node} n INNER JOIN {content_type_" . $type . "} s on s.vid = n.vid " . $filter . " LEFT JOIN {content_field_teaser_image} ti on ti.vid = s.vid LEFT JOIN {files} f on ti.field_teaser_image_fid = f.fid WHERE n.status = 1 ORDER by n.title");

      $frames = array();
      $count = 0;
      while ($data = db_fetch_object($result)) {
        $filepath = imagecache_create_url('scroller-display-list', $data->filepath);
        $frames[floor($count / $rpp)] .= '<div class="item i-' . $count . '" style="background-image:url(\'' . $filepath . '\')"><span class="title">' . $data->title . '</span><span class="teaser">' . $data->{"field_" . $type . "_teaser_value"} . '</span><a href="' . url('node/' . $data->nid) . '" title="' . check_plain($data->title) . '">&nbsp;</a></div>';
        $count++;
      }
      if (count($frames)) {
        $out = br_slider($frames, $type);
      }
    }
  }
  return $out;
}

function br_contact_form($form_state, $type = 'request-brochure') {
  $form = array();
  $form['intro'] = array('#value' => '<h2>Your details</h2><p>Fields marked with <span class="form-required">*</span> are required.</p>');
  $form['#attributes'] = array('class' => 'custom-form');
  $form['first-name'] = array(
    '#type' => 'textfield',
    '#title' => 'First name',
    '#required' => TRUE,
    '#weight' => 10,
  );

  $form['last-name'] = array(
    '#type' => 'textfield',
    '#title' => 'Last Name',
    '#required' => TRUE,
    '#weight' => 20,
  );

  $form['company'] = array(
    '#type' => 'textfield',
    '#title' => 'Company',
    '#required' => FALSE,
    '#weight' => 30,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#required' => TRUE,
    '#weight' => 40,
  );

  $form['telephone-number'] = array(
    '#type' => 'textfield',
    '#title' => 'Telephone Number',
    '#required' => TRUE,
    '#weight' => 50,
  );

  $form['captcha'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'image_captcha/Image',
    '#title' => '',
    '#weight' => 60,
  );

  $form['type'] = array(
    '#type' => 'value',
    '#value' => $type,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#weight' => 70,
    '#prefix' => '<div class="ff"></div>'
  );

  if ($type == 'tennis') {
    $form['event'] = array(
      '#type' => 'select',
      '#title' => 'Event',
      '#required' => TRUE,
      '#options' => array('Brodies Champions of Tennis Final' => 'Brodies Champions of Tennis Final', 'Legends Exhibition Match' => 'Legends Exhibition Match'),
      '#weight' => 5,
    );

    unset($form['captcha']);
    $form['bid-amount'] = array(
      '#type' => 'textfield',
      '#title' => 'Bid Amount (£)',
      '#required' => TRUE,
      '#weight' => 55,
    );

    $form['terms'] = array(
      '#type' => 'checkbox',
      '#title' => '<span class="form-required" title="This field is required.">*</span> Please tick this box to accept our <a href="/bidding-terms-and-conditions" target="_blank">terms and conditions</a>',
      '#required' => TRUE,
      '#return_value' => 1,
      '#weight' => 65,
    );

    $form['code'] = array('#value' => "
<!-- Start of Async HubSpot Analytics Code -->
    <script type=\"text/javascript\">
        (function(d,s,i,r) {
            if (d.getElementById(i)){return;}
            var n=d.createElement(s),e=d.getElementsByTagName(s)[0];
            n.id=i;n.src='//js.hubspot.com/analytics/'+(Math.ceil(new Date()/r)*r)+'/151463.js';
            e.parentNode.insertBefore(n, e);
        })(document,\"script\",\"hs-analytics\",300000);
    </script>
<!-- End of Async HubSpot Analytics Code -->");
    if (user_access('edit any publication content')) {
      if (isset($_GET['get-bids'])) {
        br_print_tennis_results_csv();
      }

      $form['controls'] = array(
        '#value' => '<div class="controls">' . l(t('Download bids CSV'), $_GET['q'], array('query' => 'get-bids')) . '</div>',
        '#weight' => 0,
      );
    }
  }

  if ($type == 'contact') {
    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => 'Title',
      '#weight' => 5,
    );

    $form['company']['#title'] = 'Company/Organisation';

    $form['address-1'] = array(
      '#type' => 'textfield',
      '#title' => 'Address line 1',
      '#weight' => 31,
    );

    $form['address-2'] = array(
      '#type' => 'textfield',
      '#title' => 'Address line 2',
      '#weight' => 32,
    );

    $form['postcode'] = array(
      '#type' => 'textfield',
      '#title' => 'Postcode',
      '#weight' => 33,
    );

    $form['fax'] = array(
      '#type' => 'textfield',
      '#title' => 'Fax',
      '#weight' => 55,
    );
    $form['email']['#weight'] = 56;
    $form['telephone-number']['#required'] = FALSE;

    $form['message'] = array(
      '#type' => 'textarea',
      '#title' => 'Message',
      '#required' => TRUE,
      '#resizable' => FALSE,
      '#weight' => 59,
    );
  }

  return $form;
}

function br_print_csv_row($row) {
  $glue = '';
  foreach ($row as $field_value) {
    $field_value = str_replace(array("\n", "\r"), array("; ", ""), strip_tags($field_value));
    print $glue . '"' . str_replace('"', '""', $field_value) . '"';
    $glue = ',';
  }
  print "\r\n";
}

function br_print_tennis_results_csv() {
  header("Content-type: application/csv");
  header("Content-Disposition: attachment; filename=results.csv");
  header("Pragma: no-cache");
  header("Expires: 0");

  $result = variable_get('br_tennis_submits', array());
  br_print_csv_row(array('Event', 'Bid Amount [£]', 'First Name', 'Last Name', 'Company', 'Email', 'Phone', 'Submission time'));

  foreach ($result as $event => $bid_data) {
    foreach ($bid_data as $bid_amount => $data) {
      $data = $data[0];
      $row = array($event, $bid_amount, $data['first-name'], $data['last-name'], $data['company'], $data['email'], $data['telephone-number'], $data['submission-time']);
      br_print_csv_row($row);
    }
  }

  exit();
}

function br_contact_form_validate($form_state, $form_values) {
  $email = $form_values['values']['email'];

  if (!valid_email_address($email)) {
    form_set_error('email', 'Enter valid email address');
  }

  if ($form_values['values']['bid-amount'] && !is_numeric($form_values['values']['bid-amount'])) {
    form_set_error('bid-amount', 'Enter numeric value for the bid amount field');
  }

  if ($form_values['values']['type'] == 'tennis') {
    if (!$form_values['values']['terms']) {
      form_set_error('terms', 'You need to accept terms and conditions.');
    }

    $result = variable_get('br_tennis_submits', array());
    if (isset($result[$form_values['values']['event']][$form_values['values']['bid-amount']])) {
      form_set_error('bid-amount', 'The bid amount £' . $form_values['values']['bid-amount'] . ' for "' . $form_values['values']['event'] . '" has already been submitted.<br /><br />
Please try again by entering different bid.');
    }
  }
}

function br_contact_form_submit($form_state, $form_values) {
  global $user;
  $values = $form_values['values'];
  $type = $values['type'];
  unset($form_values['values']['type']);

  $form_values['values']['submission-time'] = date("Y-m-d H:i", time());
  $params['contact_details'] = $form_values['values'];

  if ($values['type'] == 'tennis') {
    $result = variable_get('br_tennis_submits', array());
    $result[$values['event']][$values['bid-amount']] = array($params['contact_details']);
    variable_set('br_tennis_submits', $result);
  }

  switch ($type) {
    case 'request-brochure':
      $admin_email = 'publications@brodies.com';
      break;
    case 'tennis':
      $admin_email = 'champstennisauction@brodies.com';
      break;
    case 'contact':
      $admin_email = 'mailbox@brodies.com';
      break;

    default;
      $admin_email = 'mailbox@brodies.com';
      break;
  }

  drupal_mail('br', $type, $admin_email, language_default(), $params);

  //redirect to thank you
  unset($_REQUEST['destination']);
  drupal_goto('thank-you-' . $type);
}

function br_page_import() {
  return '';
  mysql_connect("localhost", "root", "");
  mysql_select_db("brodies_cms");
  $result = mysql_query("select * from tbl_legalupdates");
  $count = 0;
  while ($row = mysql_fetch_object($result)) {
    $count++;
    $match = array(
      1 => 65, //<option value="1">Banking</option>       
      3 => 68, //<option value="3">Corporate</option>  
      4 => 579, //<option value="4">Private Client</option> 
      5 => 581, //<option value="5">Public Law & Regulation</option> 
      6 => 577, //<option value="6">Employment, Pensions & Benefits</option>       
      8 => 67, //<option value="8">Dispute Resolution & Litigation</option> 
      9 => 1861, //<option value="9">Planning & Environment</option> 
      10 => 580, //<option value="10">Property</option> 
      11 => 582, //<option value="11">Tax</option> 
      12 => 583, //<option value="12">Technology, Information & Outsourcing</option> 
      14 => 585, //<option value="14">Construction & Engineering</option>
      15 => 1862, //">Public Sector Services</option> 
      16 => 588, //<option value="16">Family Law</option>         
      18 => 589, //">Projects</option>  
      19 => 1863, //">Firmwide</option>  
      25 => 1864, //">Corporate Restructuring & Insolvency</option>        
      27 => 1865, //">Insurance & Risk</option>
      30 => 1866, //">Shipping</option>      
      31 => 1867, //">Intellectual Property</option>    
    );

    /*
      $new_node = (object) NULL;
      $new_node->type = 'lupdate';
      $new_node->title = $row->strHeading;
      $new_node->uid = 1; //saved as superadmin
      $new_node->created = time();
      $new_node->changed = time();
      $new_node->status = 1;
      $new_node->comment = 0;
      $new_node->promote = 0;
      $new_node->moderate = 0;
      $new_node->sticky = 0;
      $new_node->body = $row->strDescription .'<!--break-->'. $row->strCopy;

      $new_node->field_l_left[0]['value'] = $row->strDisplayName;
      $new_node->field_l_id[0]['value'] = $row->ID;
      $new_node->field_l_date[0]['value'] = mktime(0, 0, 0, 1, 1, $row->intYear);
      $new_node->field_old_path[0]['value'] = 'knowledge/details/'. $row->title_id;
     */
    $new_node = node_load(db_result(db_query("SELECT nid FROM {content_type_lupdate} where field_l_id_value = %d", $row->ID)));
    if ($match[$row->intAreaID]) {

      $new_node->field_l_area[0]['nid'] = $match[$row->intAreaID];
    }
    //node_save($new_node);    
    node_save($new_node);
  }
  sm($count);

  /*
    $area_service = array(
    1 => 22,
    2 => 153,
    3 => 23,
    4 => 145,
    5 => 153,
    6 => 0,
    7 => 144,
    8 => 146,
    9 => 157,
    10 => 0,
    11 => 156,
    12 => 143,
    13 => 146,
    14 => 0,
    15 => 149,
    16 => 152,
    17 => 154,
    18 => 0,
    );
    $body = $form_values['values']['message'];
    $name = $form_values['values']['name'];
    $new_node = (object) NULL;
    $new_node->type = 'blog';
    $new_node->title = 'Blog story from form @ '. date('Y-m-d H:i:s') .' by  '. $name;
    $new_node->uid = 1; //saved as superadmin
    $new_node->created = time();
    $new_node->changed = time();
    $new_node->status = 0;
    $new_node->comment = 0;
    $new_node->promote = 0;
    $new_node->moderate = 0;
    $new_node->sticky = 0;
    $new_node->body = $body;


    // add CCK field data
    $new_node->field_blog_published_date[0]['value'] = date('Y-m-d');
    $new_node->field_blog_c_email[0]['value'] = $form_values['values']['mail'];

    // image prepare for save
    $tmp_filename = $_FILES['files']['tmp_name']['file'];
    if ($tmp_filename) {
    $filename = $_FILES['files']['name']['file'];
    $final_file = str_replace(basename($tmp_filename), $filename, $tmp_filename);
    rename($tmp_filename, $final_file);
    $file_field = field_file_save_file($final_file, array(), file_directory_path());
    $new_node->field_blog_file[0] = $file_field;
    unlink($final_file);
    }

    //save new node
    node_save($new_node);

   */
  return 'ok';
}

function is_available($url, $timeout = 30) {
  $ch = curl_init(); // get cURL handle
  // set cURL options
  $opts = array(CURLOPT_RETURNTRANSFER => true, // do not output to browser
    CURLOPT_URL => $url, // set URL
    CURLOPT_NOBODY => true, // do a HEAD request only
    CURLOPT_TIMEOUT => $timeout);   // set timeout
  curl_setopt_array($ch, $opts);

  curl_exec($ch); // do it!

  $retval = curl_getinfo($ch, CURLINFO_HTTP_CODE) == 200; // check if HTTP OK

  curl_close($ch); // close handle

  return $retval;
}

function downloadFile($url, $path) {
  $newfname = $path;
  $file = fopen($url, "rb");
  if ($file) {
    $newf = fopen($newfname, "wb");

    if ($newf)
      while (!feof($file)) {
        fwrite($newf, fread($file, 1024 * 8), 1024 * 8);
      }
  }

  if ($file) {
    fclose($file);
  }

  if ($newf) {
    fclose($newf);
    return TRUE;
  }

  return FALSE;
}

function br_search_page($keyword = '') {
  global $user;

  if (strlen($keyword) < 2) {
    $html = 'Enter at least 2 characters';
  }
  else {
    $max = 4;

    $result_array = array();

    $args = array($keyword, $keyword);
    $result = db_query("
              SELECT n.nid, n.title, r.body, n.type 
              FROM {node} n                              
              LEFT JOIN {node_revisions} r on r.vid = n.vid                                            
              WHERE (n.title like '%s%%' or r.body like '%%%s%%')                                     
              ORDER BY n.title ASC
              ", $args);

    $count = 0;
    $item_keywords = array();
    while ($data = db_fetch_object($result)) {
      $nid = $data->nid;
      if (count($result_array[$data->type]) < $max) {
        $result_array[$data->type][$nid] = array($data->type, $data->title, strip_tags($data->body));
      }
    }
    $html = '<div class="search-results">';

    if (!count($result_array)) {
      $html .= t('No results found for keyword "@keyword"', array('@keyword' => $keyword));
    }
    else {
      $content_data = array(
        'page' => t('Pages'), #
        'overview' => t('Pages'), #
        'news' => t('News'), #
        'service' => t('Services'), #
        'sector' => t('Sectors'), #
        'cs' => t('Case studies'), #
        'career' => t('Career Opportunities'), #
        'event' => t('Events & Seminars'), #
        'lupdate' => t('Legal Updates'), #
        'people' => t('People'), #
        'publication' => t('Publications Archive'), #
        'video' => t('Videos'),
      );

      //crns_highlight_search_text
      foreach ($content_data as $type => $name) {
        if (!count($result_array[$type])) {
          continue;
        }

        $html .= '<h2>' . $name . '</h2>' . '<ul>';

        foreach ($result_array[$type] as $key => $result) {
          switch ($type) {
            default:
              $html .= '<li><div searchlink="' . url('node/' . $key) . '">' . l(br_search_text($result[1], $keyword, 0, TRUE), 'node/' . $key, array('html' => TRUE)) . '</div><div class="desc">' . br_search_text($result[2], $keyword, 50) . '</div></li>';
              break;
            case 'publication':
              $filename = db_result(db_query("SELECT f.filepath FROM {content_type_publication} p INNER JOIN {node} n on n.vid = p.vid LEFT JOIN {files} f on f.fid = field_p_file_fid WHERE p.nid = %d", $key));
              $html .= '<li><div searchlink="' . url($filename) . '">' . l(br_search_text($result[1], $keyword, 0, TRUE), $filename, array('html' => TRUE)) . '</div><div class="desc">' . br_search_text($result[2], $keyword, 50) . '</div></li>';
              break;
            case 'video':
              $data = db_fetch_object(db_query("SELECT field_video_url_value, filepath FROM {content_type_video} p INNER JOIN {node} n on n.vid = p.vid LEFT JOIN {content_field_teaser_image} ti on ti.vid = n.vid LEFT JOIN {files} f on f.fid = field_teaser_image_fid WHERE p.nid = %d", $key));
              $image = '&nbsp;';
              $vdata = br_get_video_data($data->field_video_url_value, $data->filepath ? '/' . $data->filepath : '');

              $html .= '<li><div searchlink="' . url($data->field_video_url_value) . '">' . l(br_search_text($result[1], $keyword, 0, TRUE), $data->field_video_url_value, array('html' => TRUE)) . '</div><div class="desc">' . br_search_text($result[2], $keyword, 50) . '</div></li>';
              break;
          }
        }

        $html .= '</ul>';
      }
    }

    $html .= '</div>';
  }

  $matches[1] = $html;

  if (!br_popup_request_check()) {
    return $html;
  }
  else {
    print drupal_to_js($matches);
    exit();
  }
}

function br_search_text($text, $keyword, $cut = 0, $leave_result = FALSE) {
  $return_text = '';
  $text = strip_tags($text);
  //find the first occurence  
  $first_place = mb_strpos(drupal_strtolower($text), drupal_strtolower($keyword));

  if ($first_place !== FALSE) {
    $keyword_length = drupal_strlen($keyword);
    $left_text = '';
    $right_text = '';

    $return_text .= drupal_substr($text, 0, $first_place) . '<strong>' . drupal_substr($text, $first_place, drupal_strlen($keyword)) . '</strong>' . drupal_substr($text, $first_place + drupal_strlen($keyword), (drupal_strlen($text) - ($first_place + drupal_strlen($keyword))));
  }
  else {
    if ($leave_result == TRUE) {
      return $text;
    }
    else {
      return '';
    }
  }

  if ($cut) {
    $keyword = '<strong>' . $keyword . '</strong>';
    //strong open and close
    $cut = $cut + 17;
    $first_place = mb_strpos(drupal_strtolower($return_text), drupal_strtolower($keyword));
    if ($cut < drupal_strlen($keyword)) {
      $start_cut = $first_place;
      $cut = drupal_strlen($keyword);
    }
    else {
      $start_cut = $first_place - round((($cut - drupal_strlen($keyword)) / 2), 0);

      if ($start_cut < 0)
        $start_cut = 0;
    }

    if ($start_cut > 0) {
      $left_text = '...';
    }

    if (($start_cut + $cut) < drupal_strlen($return_text)) {
      $right_text = '...';
    }

    $return_text = $left_text . drupal_substr($return_text, $start_cut, $cut) . $right_text;
  }

  return $return_text;
}

function br_redirection() {
  //custom  
  unset($_REQUEST['destination'], $_GET['destination']);
  if ((strpos($_REQUEST['q'], 'publications/details') === 0 || strpos($_REQUEST['q'], 'knowledge/details') === 0) && ($_REQUEST['id'] || $_REQUEST['ID'])) {
    $nid = db_result(db_query("SELECT n.nid FROM {content_type_lupdate} l INNER JOIN {node} n on n.vid = l.vid WHERE l.field_l_id_value = %d", $_REQUEST['id'] ? $_REQUEST['id'] : $_REQUEST['ID']));
    drupal_goto('node/' . $nid);
  } // /publications/details/?id=985 → legal update , /knowledge/details/?id=1157 → legal update

  if (strpos($_REQUEST['q'], 'images/pages') === 0) {
    $file = substr($_REQUEST['q'], strrpos($_REQUEST['q'], '/') + 1);
    drupal_goto('sites/default/files/pages/' . $file);
  } //http://www.brodies.com/images/pages/fines%20update%20march%202013.pdf

  if (strpos($_REQUEST['q'], '_content/publications/pdf/') === 0) {
    $file = substr($_REQUEST['q'], strrpos($_REQUEST['q'], '/') + 1);
    drupal_goto('sites/default/files/' . $file);
  } //_content/publications/pdf/Annual%20Review%202009.pdf

  if ((strpos($_REQUEST['q'], 'people/details') === 0) && ($_REQUEST['id'] || $_REQUEST['ID'])) {
    $nid = db_result(db_query("SELECT n.nid FROM {content_type_people} l INNER JOIN {node} n on n.vid = l.vid WHERE l.field_people_id_value = %d", $_REQUEST['id'] ? $_REQUEST['id'] : $_REQUEST['ID']));
    drupal_goto('node/' . $nid);
  } // /people/details/?ID=4 → people_node
  //old path URL /knowledge/details/title-id → legal update
  $path = $_REQUEST['q'];
  $nid = db_result(db_query("SELECT n.nid FROM {content_field_old_path} l INNER JOIN {node} n on n.vid = l.vid and n.status = 1 WHERE l.field_old_path_value = '%s'", $path));
  if ($nid) {
    drupal_goto(drupal_goto('node/' . $nid));
  }
  //404
  print br_not_found();
  exit();
}

function br_not_found() {
  drupal_set_header($_SERVER['SERVER_PROTOCOL'] . ' 404 Not Found');

  watchdog('page not found', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

  // Keep old path for reference, and to allow forms to redirect to it.
  if (!isset($_REQUEST['destination'])) {
    $_REQUEST['destination'] = $_GET['q'];
  }

  $path = drupal_get_normal_path('404-page-not-found');
  if ($path && $path != $_GET['q']) {
    // Set the active item in case there are tabs to display, or other
    // dependencies on the path.
    menu_set_active_item($path);
    $return = menu_execute_active_handler($path);
  }

  if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
    drupal_set_title(t('Page not found'));
    $return = t('The requested page could not be found.');
  }

  // To conserve CPU and bandwidth, omit the blocks.
  print theme('page', $return, FALSE);
}

function br_generate_csv($csv_data, $csvname = '') {
  header("Content-type: application/csv");
  header("Content-Disposition: attachment; filename=" . $csvname . "export-" . date('d-M-Y', time()) . ".csv");
  header("Pragma: no-cache");
  header("Expires: 0");

  foreach ($csv_data as $row) {
    $glue = '';
    foreach ($row as $field_value) {
      $field_value = str_replace(array("\r"), array(""), strip_tags($field_value));
      print $glue . '"' . str_replace('"', '""', $field_value) . '"';
      $glue = ',';
    }
    print "\n";
  }
  exit();
}

function br_applications_page($app_id = '', $step = 1, $uid = 0, $sub_id = 0) {
  global $user;

  if (!$user->uid) {
    drupal_set_message('You need to log in to access this area.');
    drupal_goto('user', drupal_get_destination());
  }

  if (arg(0) == 'admin') {
    drupal_goto(arg(1));
  }

  if ($app_id == 'submissions') {

    $csv = array();
    $app_id = $step;
    for ($step = 1; $step <= 11; $step++) {
      $form_data = br_application_form('', $step);
      $count = 0;
      if ($step == 2) {
        for ($i = 1; $i < 5; $i++) {
          $form_data['subject-' . $i] = array('#type' => 1, '#title' => 'Subjects year ' . $i);
          $form_data['grade-' . $i] = array('#type' => 1, '#title' => 'Grade year ' . $i);
          $form_data['attempts-' . $i] = array('#type' => 1, '#title' => 'Attempts year ' . $i);
        }
      }

      if ($step == 5) {
        $form_data['name'] = array('#type' => 1, '#title' => 'Name of employer');
        $form_data['time'] = array('#type' => 1, '#title' => 'Period of time in employment');
        $form_data['job_title'] = array('#type' => 1, '#title' => 'Job title and main duties');
      }

      foreach ($form_data as $name => $field) {
        if (array_search($name, array('next', 'back', 'draft', '#prefix', '#stepbr')) !== FALSE || (!$field['#type']) || $field['#type'] == 'value') {
          continue;
        }
        $count++;
        $csv[0][] = $count == 1 ? 'Step ' . $step . " - " . strip_tags($form_data['#stepbr']) : '';
        $csv[1][$name] = $field['#better'] ? $field['#better'] : $field['#title'];
      }
    }
    drupal_set_title('Application Status Overview');

    if ($uid) {
      if ($uid == 'remove') {
        if ($nid = db_result(db_query("SELECT nid FROM {node} where nid = %d and type = 'asub' ", $sub_id))) {
          node_delete($sub_id);
          drupal_set_message("Submission removed");
        }

        drupal_goto(arg(0) . '/' . arg(1) . '/' . arg(2));
      }
      else {

        $result = db_query("SELECT n.nid FROM {node} n INNER JOIN {content_type_asub} ca on n.vid = ca.vid where " . ($_GET['not-completed'] ? '( field_as_completed_value <> 1 OR field_as_completed_value is null) ' : 'field_as_completed_value = 1') . " and field_as_app_nid = %d " . ($uid == 'csv' ? '' : 'and uid = ' . $uid) . " order by n.changed desc", $app_id);

        $count = 2;

        if ($_GET['simple']) {
          $csv = array(
            0 => array('' => 'Simple submissions report'),
            1 => array(
              'full_name' => 'Full name',
              'email' => 'Email Address',
              'mobile' => 'Mobile Phone Number',
              'equality_gender' => 'Gender',
              'university_collegue' => 'Name of University / College',
              'submission_date' => 'Submission Date'
            ),
          );
        }

        while ($data = db_fetch_object($result)) {
          $nid = $data->nid;
          $pnode = node_load($nid);
          $sub = unserialize($pnode->body);

          foreach ($csv[1] as $field_name => $title) {
            $value = '';
            if ($field_name == 'submission_date') {
              $value = date("H:i d M y", $pnode->changed);
            }
            elseif (strpos($field_name, 'subject') !== FALSE || strpos($field_name, 'grade') !== FALSE || strpos($field_name, 'attempt') !== FALSE) {
              $data = explode('-', $field_name);

              foreach ($sub[2][$data[0]][$data[1]] as $ikey => $item) {
                $value .= ' (' . ($ikey + 1) . ') ' . $item . " \n ";
              }
            }
            elseif (strpos($field_name, 'name') === 0 || strpos($field_name, 'time') === 0 || strpos($field_name, 'job_title') === 0) {
              foreach ($sub[5][$field_name] as $ikey => $item) {
                $value .= ' (' . ($ikey + 1) . ') ' . $item . " \n ";
              }
            }
            else {
              foreach ($sub as $step => $values) {
                foreach ($values as $fname => $fvalue) {
                  if ($fname == $field_name) {
                    $value = $fvalue;
                    break 2;
                  }
                }
              }
            }

            $csv[$count][$field_name] = $value;
          }
          $count++;
        }

        if (count($csv) > 1) {
          br_generate_csv($csv);
          exit();
        }
        else {
          drupal_set_message('Not enough form submissions');
          drupal_goto(arg(0));
        }
      }
    }

    $app = node_load($app_id);
    $result = db_query("SELECT * FROM {content_type_asub} a INNER JOIN {node} n on n.vid = a.vid          
      LEFT JOIN node_revisions nr on nr.vid = n.vid  
      LEFT JOIN users u on u.uid = n.uid
      where field_as_completed_value = 1 and field_as_app_nid = %d ORDER BY n.changed DESC", $app_id);
    $out .= '<h2>Submission for "' . $app->title . '"</h2>';
    while ($data = db_fetch_object($result)) {
      $sub = unserialize($data->body);
      $rows[] = array(
        date("H:i d M Y", $data->changed),
        $sub[1]['full_name'],
        $data->mail,
        /* $sub[1]['full_name'] .'<br />'.
          $sub[2]['university_collegue'] .', phone: '. $sub[1]['phone_number'] .'<br />'.
          $sub[1]['home_address'] .' '. $sub[1]['postcode']
          , */
        l('Download CSV', 'application-forms/submissions/' . $app->nid . '/' . $data->uid) . '<br />' .
        l('Remove', 'application-forms/submissions/' . $app->nid . '/remove/' . $data->nid)
      );
    }

    if ($rows) {
      $out .= theme("table", array('Completion Date', 'Name', 'Email', 'Action'), $rows, array('cellspacing' => 1));
      $out .= '<br /><table><tr><th>Download Completed</th><th>Download Incomplete</th></tr><tr><td>' . l('All fields', 'application-forms/submissions/' . $app_id . '/csv') . '</td><td>' . l('All fields', 'application-forms/submissions/' . $app_id . '/csv', array('query' => 'not-completed=1')) . '</td></tr>
	  <tr><td>' . l('Main details', 'application-forms/submissions/' . $app_id . '/csv', array('query' => 'simple=1')) . '</td><td>' . l('Main details', 'application-forms/submissions/' . $app_id . '/csv', array('query' => 'not-completed=1&simple=1')) . '</td></tr></table>';
    }
    else {
      $out .= '<p>No submissions</p>';
    }

    $out .= '<br /><br />' . l('< BACK', 'application-forms') . '';
    ;
  }
  else if ($app_id) {
    $app = node_load($app_id);
    if ($app->type == 'application') {
      $sub_data = db_fetch_object(db_query("SELECT n1.changed as last_update, nr.body, a.field_as_completed_value FROM {content_type_asub} a   
      INNER JOIN {node} n1 on n1.vid = a.vid and n1.uid = %d
      LEFT JOIN node_revisions nr on nr.vid = n1.vid WHERE a.field_as_app_nid = %d ", $user->uid, $app_id));
      if ($sub_data->field_as_completed_value == 1) {
        drupal_set_message('This form was already completed');
        drupal_goto(arg(0));
      }


      if ($app->status == 0 && $_GET['over'] != 'g£jas1ysd13!') {
        drupal_set_message('This application is closed');
        drupal_goto(arg(0));
      }


      if (!is_numeric($step) || $step > 11) {
        $step = 1;
      }
      //load current details
      //show step 1      
      $out .= drupal_get_form('br_application_form', $step);
    }
  }
  else {
    $out .= "<h2>Overview</h2><p>Welcome to our online application form, by creating an account you’ve taken the first step to potentially becoming a Brodies trainee of the future. Take your time when completing the form, make sure that you answer all the questions fully and that you give strong examples which highlight that you have the skills and competencies we are looking for in our trainees.</p><p>Good luck!</p><p>Closing dates for applications : <b>Friday 9th October 2015</b></p><p><b>Please note:</b> You are eligible to apply if you are a minimum of 4th year of your LLB or 1st year of your accelerated LLB and you should be on track for a 2:1</p>";

    $result = db_query("SELECT n.nid, n.title, n.status FROM {node} n 
      where n.type = 'application' ORDER BY n.created DESC limit 0,1", $user->uid);

    $rows = array();
    while ($data = db_fetch_object($result)) {
      $sub_data = db_fetch_object(db_query("SELECT n1.changed as last_update, nr.body, a.field_as_completed_value FROM {content_type_asub} a   
      INNER JOIN {node} n1 on n1.vid = a.vid and n1.uid = %d
      LEFT JOIN node_revisions nr on nr.vid = n1.vid WHERE a.field_as_app_nid = %d ", $user->uid, $data->nid));
      $max = 11;
      $step_nr = 0;
      if ($defauls = unserialize($sub_data->body)) {
        $step_nr = max(array_keys($defauls));
      }

      $actions = array();
      if (!$sub_data->field_as_completed_value && $data->status == 1) {
        $actions[] = l($step_nr ? 'Continue' : 'Start', arg(0) . '/' . $data->nid . ($defauls['draft'] ? '/' . $defauls['draft'] : ''));
      }

      if ($data->status == 0) {
        $actions[] = 'application closed';
      }

      if (user_access('view submissions')) {
        $actions[] = l('View submissions', arg(0) . '/submissions/' . $data->nid);
      }


      $rows[] = array(
        $data->title,
        ($sub_data->field_as_completed_value ? 'Completed' : ($step_nr ? 'Step ' . $step_nr . ' / ' . $max : 'Empty')),
        $sub_data->last_update ? date("H:i d M Y", $sub_data->last_update) : 'Never Updated',
        implode(' / ', $actions)
      );
    }
    $out .= theme("table", array('Application Title', 'Status', 'Last Update', 'Action'), $rows, array('cellspacing' => 1));
  }
  return '<div class="applications">' . $out . '</div>';
}

function br_application_form($form_state, $step) {
  global $user;
  $steps = 11;
  $form = array('#prefix' => '<div class="progress">Step ' . $step . ' of ' . $steps . '</div>');
  $form['intro'] = array('#value' => '<p>Fields marked with <span class="form-required">*</span> are required</p><BR />');

  if ($nid = db_result(db_query("SELECT n.nid FROM {node} n INNER JOIN {content_type_asub} ca on n.vid = ca.vid where uid = %d and field_as_app_nid = %d ", $user->uid, arg(1)))) {
    $pnode = node_load($nid);
    $defaults = unserialize($pnode->body);
    $_SESSION['applications'][arg(1)] = $defaults;
  }

  switch ($step) {
    case 1:
      $title = 'Personal details';
      $form['full_name'] = array(
        '#title' => 'Full name',
        '#required' => TRUE,
        '#type' => 'textfield'
      );

      $form['nationality'] = array(
        '#title' => 'Nationality',
        '#required' => FALSE,
        '#type' => 'textfield'
      );

      $form['right_to_work'] = array(
        '#title' => 'Do you have the right to work in UK?',
        '#required' => FALSE,
        '#type' => 'radios',
        '#options' => array('yes' => 'YES', 'no' => 'NO'),
        '#clearfix' => TRUE
      );

      $form['completed diploma'] = array(
        '#title' => 'I will have completed my diploma and can be considered for a traineeship in',
        '#type' => 'checkboxes',
        '#options' => array(
          '2016' => '2016',
          '2017' => '2017',
        )
      );

      $form['applied_in_past_pre'] = array('#value' => '<div class="form-item" style="clear:both">
 <label>Please advise if you have applied to Brodies in the past and if so, when was this?: <span title="This field is required." class="form-required">*</span></label>
 <div class="item-left">');

      $form['applied_in_past'] = array(
        '#title' => 'Please advise if you have applied to Brodies in the past and if so, when was this?',
        '#required' => TRUE,
        '#type' => 'radios',
        '#clear' => TRUE,
        '#options' => array('yes' => 'YES', 'no' => 'NO')
      );

      $form['applied_when'] = array(
        '#required' => FALSE,
        '#type' => 'textarea',
        '#rows' => 2,
        '#clear' => TRUE,
        '#title' => 'When applied',
        '#resizable' => FALSE,
        '#prefix' => '</div><div class="item-right">',
        '#suffix' => '</div><div class="ff"></div></div>'
      );

      $form['applied_in_past_placement'] = array(
        '#title' => 'Have you applied to Brodies in the past for a summer placement or traineeship?',
        '#required' => TRUE,
        '#type' => 'select',
        '#options' => array('no' => 'No',
          'yes Summer Placement 2013' => 'Yes Summer Placement 2013',
          'Yes Traineeship 2013' => 'Yes Traineeship 2013',
          'Yes Summer Placement 2014' => 'Yes Summer Placement 2014',
          'Yes Traineeship 2014' => 'Yes Traineeship 2014',
          'Yes Summer Placement 2015' => 'Yes Summer Placement 2015',
          'Yes Traineeship 2015' => 'Yes Traineeship 2015',
        )
      );

      $form['interviewed_with_brodies'] = array(
        '#title' => 'If you have interviewed with Brodies in the past, please provide details below',
        '#required' => FALSE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
        '#prefix' => '<br />',
      );

      $form['break'] = array(
        '#value' => '<hr />',
      );

      $form['home_address'] = array(
        '#required' => TRUE,
        '#title' => 'Home Address',
        '#type' => 'textarea',
        '#resizable' => FALSE,
        '#prefix' => '<div class="col1">',
      );

      $form['term_time_address'] = array(
        '#required' => FALSE,
        '#title' => 'Term Time Address',
        '#type' => 'textarea',
        '#resizable' => FALSE,
        '#prefix' => '</div><div class="col2">',
        '#suffix' => '</div><div class="ff"></div>',
      );

      $form['postcode'] = array(
        '#required' => TRUE,
        '#title' => 'Postcode',
        '#type' => 'textfield',
        '#prefix' => '<div class="col1">',
      );

      $form['term_postcode'] = array(
        '#required' => FALSE,
        '#title' => 'Postcode',
        '#type' => 'textfield',
        '#prefix' => '</div><div class="col2">',
        '#suffix' => '</div><div class="ff"></div>',
      );

      $form['phone_number'] = array(
        '#required' => TRUE,
        '#title' => 'Phone Number',
        '#type' => 'textfield',
        '#prefix' => '<div class="col1">',
      );

      $form['term_phone_number'] = array(
        '#required' => FALSE,
        '#title' => 'Term Phone Number',
        '#type' => 'textfield',
        '#prefix' => '</div><div class="col2">',
        '#suffix' => '</div><div class="ff"></div>',
      );

      $form['email'] = array(
        '#required' => TRUE,
        '#title' => 'Email Address',
        '#type' => 'textfield',
        '#prefix' => '<div class="col1">',
      );

      $form['mobile'] = array(
        '#required' => TRUE,
        '#title' => 'Mobile Phone Number',
        '#type' => 'textfield',
        '#prefix' => '</div><div class="col2">',
        '#suffix' => '</div><div class="ff"></div>',
      );

      $form['helth_limitations'] = array(
        '#title' => 'Please tell us of any health limitations or special requirements that may affect your attendance at an assessment centre',
        '#required' => FALSE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );

      break;


    case 2:
      $title = 'Education - <span>your law degree</span>';

      $form['university_collegue'] = array(
        '#title' => 'Name of University / College',
        '#required' => TRUE,
        '#type' => 'textfield'
      );

      $form['dates_attended'] = array(
        '#title' => 'Dates attended',
        '#required' => FALSE,
        '#type' => 'textfield'
      );

      $form['subjects'] = array('#value' => '<p>Please list all the subjects you have studied and have yet to study for your law degree, the marks for each year for
each subject and the number of attempts. <span class="notice">Please declare mark, rather than pass/fail subjects.</span></p>' . br_multiple_field($defaults[$step], 'subjects'));

      $form['further_information'] = array(
        '#title' => 'Further Information',
        '#required' => FALSE,
        '#pre_label' => '<!--<p>Please provide details of the subjects you have, or are due to study at fourth year level. If you have completed fourth year, please also indicate your marks and number of attempts.</p>--><p>If you have taken a year out, please provide details below. (maximum of 150 words)</p>',
        '#type' => 'textarea',
        '#attributes' => array('maxlength' => 1000),
        '#resizable' => FALSE,
      );
      break;


    case 3:
      $title = 'Education - <span>other degrees</span>';
      $form['intro'] = array('#value' => '<p>Please provide details of any other degrees or educational qualifications, including diplomas.</p>');
      $form['eduction_other_degrees_university'] = array(
        '#title' => 'Name of university/college',
        '#required' => FALSE,
        '#type' => 'textfield',
        '#better' => 'Education other degrees - university/college name'
      );

      $form['eduction_other_degrees_qualifications'] = array(
        '#title' => 'Qualifications',
        '#required' => FALSE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
        '#rows' => 12,
        '#better' => 'Education other degrees - qualifications'
      );

      break;

    case 4:
      $title = 'Education - <span>school</span>';
      $form['education_school'] = array(
        '#title' => 'Name of school/college',
        '#required' => FALSE,
        '#type' => 'textfield',
        '#better' => 'Education school - school/college name'
      );

      $form['eduction_school_qualifications'] = array(
        '#title' => 'Qualifications',
        '#required' => FALSE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
        '#rows' => 12,
        '#pre_label' => '<p>Please list the Scottish Higher Certificate (or equivalent) exams you have taken. <br /><b>e.g.</b> English Higher A</p>',
        '#better' => 'Education school - qualifications'
      );

      break;

    case 5:
      $title = 'Employment';
      $form['intro'] = array('#value' => '<p>Please state full employment history</p>');
      $form['employment_history'] = array('#value' => br_multiple_field($defaults[$step], 'employment'));

      $form['emplotment_other'] = array(
        '#title' => 'Are there any other relevant experiences you would like to tell us about? (maximum of 200 words)',
        '#no-colon' => TRUE,
        '#required' => FALSE,
        '#type' => 'textarea',
        '#attributes' => array('maxlength' => 1000),
        '#resizable' => FALSE,
      );
      break;

    case 6:
      $title = 'Outside activities/interests';
      $form['free_time'] = array(
        '#title' => 'Please tell us how you like to spend your free time (maximum of 150 words)',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#rows' => 12,
        '#resizable' => FALSE,
      );
      break;

    case 7:
      $title = 'Supporting Information';
      $form['effective_communication'] = array(
        '#title' => 'Please tell us about an occasion where you have had to be an effective communicator. (maximum of 200 words)',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );

      $form['team_contribution'] = array(
        '#title' => 'At Brodies we aim to always go “Above and Beyond” for our clients. Please tell us about a time you have exceeded someone’s expectations of you. (maximum of 200 words)',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );

      $form['commercial_awareness'] = array(
        '#title' => 'What is your understanding of the term \'Commercial Awareness\'? and from your research of Brodies give us an example of how you think we demonstrate this as a firm (maximum of 200 words) ?',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );
      $form['pursue_career'] = array(
        '#title' => 'Please explain why you have decided to pursue a career with Brodies (maximum of 200 words)',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );
      $form['selling_points'] = array(
        '#title' => 'What are your unique selling points (maximum of 200 words) ?',
        '#required' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );
      break;

    case 8:
      $title = 'References';
      $form['academic_r_name'] = array(
        '#required' => TRUE,
        '#title' => 'Name',
        '#type' => 'textfield',
        '#prefix' => '<p>We will contact your referee by email unless you tell us otherwise.</p><div class="col1"><h2>Academic reference:</h2>',
      );

      $form['academic_r_e_address'] = array(
        '#required' => TRUE,
        '#title' => 'Email Address',
        '#type' => 'textfield',
      );

      $form['academic_r_phone'] = array(
        '#required' => TRUE,
        '#title' => 'Phone number',
        '#type' => 'textfield',
      );

      $form['academic_r_address'] = array(
        '#required' => TRUE,
        '#title' => 'Address',
        '#resizable' => FALSE,
        '#type' => 'textarea',
      );

      $form['academic_r_postcode'] = array(
        '#required' => TRUE,
        '#title' => 'Postcode',
        '#type' => 'textfield',
      );

      $form['academic_e_name'] = array(
        '#required' => TRUE,
        '#title' => 'Name',
        '#type' => 'textfield',
        '#prefix' => '</div><div class="col2"><h2>Employment/Character reference:</h2>',
      );

      $form['academic_e_e_address'] = array(
        '#required' => TRUE,
        '#title' => 'Email Address',
        '#type' => 'textfield',
      );

      $form['academic_e_phone'] = array(
        '#required' => TRUE,
        '#title' => 'Phone number',
        '#type' => 'textfield',
      );

      $form['academic_e_address'] = array(
        '#required' => TRUE,
        '#title' => 'Address',
        '#resizable' => FALSE,
        '#type' => 'textarea',
      );

      $form['academic_e_postcode'] = array(
        '#required' => TRUE,
        '#title' => 'Postcode',
        '#type' => 'textfield',
        '#suffix' => '</div><div class="ff"></div>',
      );

      break;

    case 9:
      $title = 'Equality monitoring';
      $form['intro'] = array('#value' => '<p>We operate a policy of equality and diversity in the recruitment process. To help us monitor this policy, please complete the form below.</p><p>You are not required to complete this form but are encouraged to do so to ensure that the survey is as accurate as possible. The information you supply will be kept in strict confidence and will be used for statistical purposes only. It does not form part of the selection procedure.  </p>');

      $form['equality_gender'] = array(
        //'#required' => TRUE,
        '#title' => 'What is your gender?',
        '#no-colon' => TRUE,
        '#type' => 'textfield',
      );

      $form['equality_disability'] = array(
        //'#required' => TRUE,
        '#title' => 'Do you have a disability that requires the Firm to make a reasonable adjustment to the recruitment process?',
        '#no-colon' => TRUE,
        '#type' => 'textarea',
        '#resizable' => FALSE,
      );

      $form['equality_ethnic'] = array(
        //'#required' => TRUE,
        '#title' => 'What is your ethnic group?',
        '#no-colon' => TRUE,
        '#type' => 'textfield',
      );
      break;


    case 10:
      $title = 'Data Protection';
      $form['intro'] = array('#value' => '<p>I confirm that Brodies may keep my application on file for the next 2 years, after which it will be deleted in accordance with Brodies data protection obligations.</p>');

      $form['confirm_information'] = array(
        '#required' => TRUE,
        '#return_value' => 'Yes',
        '#title' => 'I also confirm that all information detailed on this application form is true to the best of my knowledge.',
        '#type' => 'checkbox',
      );

      break;

    case 11:
      $title = 'Submit confirmation';
      $form['intro'] = array('#value' => '<p>Are you sure that you want submit the application?</p>');

      break;
  }

  $form['step'] = array('#value' => $step, '#type' => 'value');
  $form['#stepbr'] = $title;

  if ($defaults[$step]) {
    foreach ($form as $field => $data) {
      if (isset($defaults[$step][$field])) {
        $form[$field]['#default_value'] = $defaults[$step][$field];
      }
    }
  }

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => $step == 1 ? 'Back to overview' : 'Previous step',
    '#prefix' => '<div class="buttons">'
  );

  $form['draft'] = array(
    '#type' => 'submit',
    '#value' => 'Save as Draft',
  );

  $form['next'] = array(
    '#type' => 'submit',
    '#value' => ($step + 1 == $steps) ? 'Complete' : 'Continue to step ' . ($step + 1) . ' of ' . $steps,
    '#suffix' => '</div>'
  );

  if ($step == 11) {
    $form['next']['#value'] = 'Yes I\'m sure, send the application';
  }

  drupal_set_title($title);

  return $form;
}

function br_multiple_field($def, $type) {

  drupal_add_js("
    $(document).ready(function(){
      $('.add-field').click(function(){
        var table = $(this).prev();    
        var tr = '<tr>' + $('tr:last', table).html() + '</tr>'            
        $(table).append(tr);
        $('tr:last input', table).val('');    
      }); 
      
    });
  ", 'inline');

  switch ($type) {
    case 'subjects':
      $add = 'add subject';
      for ($i = 1; $i < 5; $i++) {
        $rows = array();
        for ($s = 0; $s <= (max(count($_POST['subject'][$i] ? $_POST['subject'][$i] : $def['subject'][$i]), 3)) - 1; $s++) {
          $rows[] = array(
            $s == 1 ? br_year($i) : '',
            br_input('subject[' . $i . '][]', $_POST['subject'][$i][$s] ? $_POST['subject'][$i][$s] : $def['subject'][$i][$s]),
            br_input('grade[' . $i . '][]', $_POST['grade'][$i][$s] ? $_POST['grade'][$i][$s] : $def['grade'][$i][$s]),
            br_input('attempts[' . $i . '][]', $_POST['attempts'][$i][$s] ? $_POST['attempts'][$i][$s] : $def['attempts'][$i][$s]),
          );
        }
        $out .= theme('table', array(array('data' => 'Year', 'width' => '40px'), array('data' => 'Subject',), array('data' => 'Grade', 'width' => '70'), array('data' => 'Attempts', 'width' => '70')), $rows) . '<div class="add-field">' . $add . '</div>';
      }
      break;

    case 'employment':
      $add = 'add employment';

      $rows = array();
      for ($s = 0; $s <= (max(count($_POST['name'] ? $_POST['name'] : $def['name']), 3)) - 1; $s++) {
        $rows[] = array(
          array('data' => br_input('name[]', $_POST['name'][$s] ? $_POST['name'][$s] : $def['name'][$s]), 'valign' => 'top'),
          array('data' => br_input('time[]', $_POST['time'][$s] ? $_POST['time'][$s] : $def['time'][$s]), 'valign' => 'top'),
          br_input('job_title[]', $_POST['attempts'][$s] ? $_POST['job_title'][$s] : $def['job_title'][$s], 'textarea', 5),
        );
      }
      $out .= theme('table', array(array('data' => 'Name of employer', 'width' => '30%'), array('data' => 'Period of time in employment', 'width' => '20%'), array('data' => 'Job title and main duties', 'width' => '50%')), $rows) . '<div class="add-field">' . $add . '</div>';

      break;
  }

  $out = '<div class="multiple">' . $out . '</div>';

  return $out;
}

function br_input($name, $def, $type = 'text', $height = 0) {
  if ($type == 'textarea') {
    return '<textarea type="text" name="' . $name . '" ' . ($height ? ' rows="' . $height . '" ' : '') . '>' . ($def ? $def : '') . '</textarea/>';
  }
  else
    return '<input type="text" value="' . check_plain($def ? $def : '') . '" name="' . $name . '" />';
}

function br_year($year) {
  switch ($year) {
    case 1: return 'One';
    case 2: return 'Two';
    case 3: return 'Three';
    case 4: return 'Four';
  }
}

function br_application_form_validate($form_state, $form_values) {
  $values = $form_values['values'];
  $step = $values['step'];
  $op = $form_values['values']['op'];
  unset($values['step'], $values['back'], $values['op'], $values['draft'], $values['next'], $values['form_build_id'], $values['form_token'], $values['form_id']);
  $default = $_SESSION['applications'][arg(1)];

  if (strpos($op, 'Back') !== FALSE) {
    drupal_get_messages(NULL, TRUE);
    drupal_goto('application-forms');
  }

  if (strpos($op, 'Draft') !== FALSE || strpos($op, 'Previous') !== FALSE) {
    $default[$step] = $values;
    if ($step == 2) {
      $default[$step]['subject'] = $_POST['subject'];
      $default[$step]['grade'] = $_POST['grade'];
      $default[$step]['attempts'] = $_POST['attempts'];
    }
    else if ($step == 5) {
      $default[$step]['name'] = $_POST['name'];
      $default[$step]['time'] = $_POST['time'];
      $default[$step]['job_title'] = $_POST['job_title'];
    }

    drupal_get_messages(NULL, TRUE);
    if (strpos($op, 'Draft') !== FALSE) {
      $default['draft'] = $step;
      drupal_set_message('Draft saved', 'blue');
      br_application_save($default);
      drupal_goto($_GET['q']);
    }
    else {
      br_application_save($default);
    }

    if (strpos($op, 'Previous') !== FALSE) {
      drupal_goto('application-forms/' . arg(1) . '/' . ($step - 1));
    }
  }

  if ($step == 1) {
    if (!valid_email_address($values['email'])) {
      form_set_error('email', 'Please provide valid email address');
    }
  }

  if ($step == 10) {
    if (!$values['confirm_information']) {
      form_set_error('confrism', 'You need to confirm that all information detailed on this application form is true to the best of your knowledge');
    }
  }
}

function br_application_form_submit($form_state, $form_values) {
  error_reporting(E_ALL);
  ini_set('display_errors', '1');

  $values = $form_values['values'];
  $step = $values['step'];
  $op = $form_values['values']['op'];
  unset($values['step'], $values['back'], $values['op'], $values['draft'], $values['next'], $values['form_build_id'], $values['form_token'], $values['form_id']);
  $subjects = array();
  global $user;
  $default = $_SESSION['applications'][arg(1)];
  $default[$step] = $values;
  if ($step == 2) {
    $default[$step]['subject'] = $_POST['subject'];
    $default[$step]['grade'] = $_POST['grade'];
    $default[$step]['attempts'] = $_POST['attempts'];
  }
  else if ($step == 5) {
    $default[$step]['name'] = $_POST['name'];
    $default[$step]['time'] = $_POST['time'];
    $default[$step]['job_title'] = $_POST['job_title'];
  }

  if (strpos($op, 'Yes') !== FALSE) {
    $default['completed'] = 1;
    $user_email = $user->mail;
    $admin_email = 'graduaterecruitment@brodies.com';
    //$admin_email = 'grant.mckendry@thegateworldwide.com';
    //$admin_email = 'callum@sakurabrae.co.uk';
    $app = node_load(arg(1));
    $details_url = url('application-forms/submissions/' . arg(1) . '/' . $user->uid, array('absolute' => TRUE));
    $details = br_application_submission_format($default);
    $params = array(
      'application_name' => $app->title,
      'app_url' => $details_url,
      'submit_details' => $details,
      'full_name' => $default[1]['full_name'],
    );
    drupal_mail('br', 'application-confirm-user', $user_email, language_default(), $params);
    drupal_mail('br', 'application-confirm-admin', $admin_email, language_default(), $params);
  }

  br_application_save($default);
  if (strpos($op, 'Back') !== FALSE) {
    drupal_goto('application-forms');
  }
  else if (strpos($op, 'Previous') !== FALSE) {
    drupal_goto('application-forms/' . arg(1) . ($step > 1 ? '/' . ($step - 1) : ''));
  }
  else if (strpos($op, 'Continue') !== FALSE || strpos($op, 'Complete') !== FALSE) {
    drupal_goto('application-forms/' . arg(1) . '/' . ($step + 1));
  }
  else if ($default['completed']) {

    //email form to trainees@brodies.com
    //mark as completed

    drupal_set_message('Application completed');
    drupal_goto('application-forms');
  }
}

function br_application_submission_format($sub) {

  for ($step = 1; $step <= 11; $step++) {
    $form_data = br_application_form('', $step);
    $count = 0;

    if ($step == 2) {
      $form_data['edu_history'] = array('#type' => 1, '#title' => 'Please list all the subjects you have studied (and have yet to study) for your law degree, the marks for each year for each subject and the number of attempts. Please declare mark, rather than pass/fail.');
    }

    if ($step == 5) {
      $form_data['emp_history'] = array('#type' => 1, '#title' => 'Please state full employment history');
    }

    $hname = strip_tags($form_data['#stepbr']);
    if ($hname == 'References') {
      $hname = 'Academic Reference';
    }

    $out .= '<h2>' . $hname . '</h2><table width="90%" cellspacing="5">';
    foreach ($form_data as $name => $field) {
      if (array_search($name, array('next', 'back', 'draft', '#prefix', '#stepbr', 'postcode', 'term_postcode')) !== FALSE || (!$field['#type']) || $field['#type'] == 'value') {
        continue;
      }
      $count++;

      $field_name = $name;
      if ($field_name == 'academic_e_name') {
        $out .= '</table><h2>Character Reference</h2><table width="90%" cellspacing="5">';
      }

      if ($field_name == 'edu_history') {
        $data = explode('-', $field_name);
        $value = "<table cellspacing='5'><tr><th>Year</th><th>Subjects</th><th>Grade</th><th>Attempts</th></tr>";
        foreach ($sub[2]['subject'] as $year => $item) {
          foreach ($sub[2]['subject'][$year] as $sub_key => $sub_item) {
            $value .= '<tr><td>' . $year . '</td><td>' . $sub[2]['subject'][$year][$sub_key] . '</td><td>' . $sub[2]['grade'][$year][$sub_key] . '</td><td>' . $sub[2]['attempts'][$year][$sub_key] . '</td></tr>';
          }
        }
        $value .= "</table>";
      }
      elseif ($field_name == 'emp_history') {
        $value = "<table cellspacing='5'><tr><th>Name of employer</th><th>Period of time in employment</th><th>Job title and main duties</th></tr>";
        foreach ($sub[5]['name'] as $ikey => $item) {
          $value .= '<tr><td>' . $sub[5]['name'][$ikey] . '</td><td>' . $sub[5]['time'][$ikey] . '</td><td>' . $sub[5]['job_title'][$ikey] . '</td></tr>';
        }
        $value .= "</table>";
      }
      else {
        foreach ($sub as $step => $values) {
          if (is_array($values) && count($values)) {
            foreach ($values as $fname => $fvalue) {
              if ($fname == $field_name) {
                $value = $fvalue;
                if ($field_name == 'home_address') {
                  $value = str_replace("\n", ', ', $value) . '</td></tr><tr><td width="30%"><i>Home postcode</i><br /><br /></td><td width="70%">' . $sub[1]['postcode'];
                }
                if ($field_name == 'term_time_address') {
                  $value = str_replace("\n", ', ', $value) . '</td></tr><tr><td width="30%"><i>Term Time Postcode</i><br /><br /></td><td width="70%">' . $sub[1]['term_postcode'];
                }
                break 2;
              }
            }
          }
        }
      }

      $out .= '<tr><td width="30%"><i>' . ($field['#better'] ? $field['#better'] : $field['#title']) . '</i><br /><br /></td><td width="70%">' . $value . '</td></tr>';
    }
    $out .= '</table>';
  }
  $out = str_replace('<td', '<td style="vertical-align:top;" valign="top" ', $out);
  return $out;
}

function br_application_save($values) {
  global $user;

  if ($nid = db_result(db_query("SELECT n.nid FROM content_type_asub a INNER JOIN node n  on a.vid = n.vid and uid = %d where field_as_app_nid = %d ", $user->uid, arg(1)))) {
    $pnode = node_load($nid);
  }
  else {
    $pnode = (object) NULL;
    $pnode->type = 'asub';
    $pnode->uid = $user->uid;
    $pnode->created = time();
    $pnode->status = 0;
    $node->comment = 0;
    $node->promote = 0;
    $node->moderate = 0;
    $node->sticky = 0;
    $pnode->title = 'Submission from uid ' . $user->uid . ', app ' . arg(1);
  }

  if ($values['completed']) {
    $pnode->field_as_completed[0]['value'] = 1;
  }

  $pnode->field_as_app[0]['nid'] = arg(1);
  $pnode->body = serialize($values);
  node_save($pnode);
}

function br_landing_page($node) {
  $feeds = '<div class="feeds">
                <div class="feed"><h3>News</h3>' . $node->field_lp_news[0]['value'] . '<div class="mask"></div><a class="view" href="' . $node->field_lp_new_more[0]['value'] . '">More</a></div>
                <div class="feed"><h3>Blog</h3>' . $node->field_lp_blog[0]['value'] . '<div class="mask"></div><a class="view" href="' . $node->field_lp_blog_more[0]['value'] . '">More</a></div>
                <div class="ff"></div>
          </div>';
  $_GET['test'] = 1;
  if ($_GET['test']) {
    $contacts = '<div class="feed"><h3>' . $node->field_lp_3rd_name[0]['value'] . '</h3>' . $node->field_lp_3rd_content[0]['value'] . '<div class="mask"></div></div>';
  }
  else {
    $contacts = '<div class="contacts">
                <div class="contact"><a href="' . $node->field_lp_contact_l_url[0]['value'] . '"><img src="/' . $node->field_lp_contact_l_img[0]['filepath'] . '"><b>Key contact</b><p>' . $node->field_lp_contact_l_name[0]['value'] . '</p></a></div>
                <div class="contact"><a href="' . $node->field_lp_contact_r_url[0]['value'] . '"><img src="/' . $node->field_lp_contact_r_img[0]['filepath'] . '"><b>Key contact</b><p>' . $node->field_lp_contact_r_name[0]['value'] . '</p></a></div>
                <div class="ff"></div>
          </div>';
  }

  $ctas = '<div class="ctas" ' . ($_GET['test'] ? ' style="margin-top:0px;" ' : '') . '>
                <div class="cta" ' . ($_GET['test'] ? ' style="margin-left:4%;height:95px;overflow:hidden;margin-bottom:15px;" ' : '') . '><a href="' . $node->field_lp_cta_l_url[0]['value'] . '"><img src="/' . $node->field_lp_cta_l_image[0]['filepath'] . '"><div class="cont"><b>' . $node->field_lp_cta_l_title[0]['value'] . '</b><p>' . $node->field_lp_cta_l_text[0]['value'] . '</p></div></a></div>
                <div class="cta"><a href="' . $node->field_lp_cta_r_url[0]['value'] . '"><img src="/' . $node->field_lp_cta_r_image[0]['filepath'] . '"><div class="cont"><b>' . $node->field_lp_cta_r_title[0]['value'] . '</b><p>' . $node->field_lp_cta_r_text[0]['value'] . '</p></div></a></div>
                <div class="ff"></div>
          </div>';

  $vdata = br_get_video_data($node->field_lp_v_link[0]['value']);
  $video = '<a href="' . $node->field_lp_v_link[0]['value'] . '" class="vi"><span class="video" style="display:none">' . drupal_to_js(array('video' => $vdata['embed'])) . '</span><img src="/' . $node->field_lp_v_image[0]['filepath'] . '" /></a>';
  drupal_add_js("
          $(document).ready(function(){
            $('.vi').click(function(){                
              var content = '';
              eval('content = ' + $('span.video', this).html());
                            
              init_popup('<div class=\"video\">' + content.video + '</div>');
              return false;              
            });            
          });
          ", 'inline');
  return '<div class="row1">
              <div class="col-left">' . $node->body . '</div>
              <div class="col-right">' . $video . '</div>
              <div class="ff"></div>
           </div>' .
      '<div class="row2">
              <div class="col-left">' . $feeds . '</div>
              <div class="col-right">' . $contacts . $ctas . '</div>
              <div class="ff"></div>
           </div>';
}

function br_landing_page2($node) {
  $contacts = '<div class="contacts">
                <div class="contact"><a href="' . $node->field_lp_contact_l_url[0]['value'] . '"><div class="contact-img"><img src="/' . $node->field_lp_contact_l_img[0]['filepath'] . '"></div><div class="contact-info"><b>Key contact</b><p>' . $node->field_lp_contact_l_name[0]['value'] . '</p></div></a></div>
                <div class="contact"><a href="' . $node->field_lp_contact_r_url[0]['value'] . '"><div class="contact-img"><img src="/' . $node->field_lp_contact_r_img[0]['filepath'] . '"></div><div class="contact-info"><b>Key contact</b><p>' . $node->field_lp_contact_r_name[0]['value'] . '</p></div></a></div>
                <div class="ff"></div>
          </div>';

  $feeds = '<div class="feeds">
                <div class="feed"><h3>Useful Links</h3>' . $node->field_lp_news[0]['value'] . '<div class="mask"></div><a class="view" href="' . $node->field_lp_new_more[0]['value'] . '">More</a></div>
                <div class="feed"><h3>Related Publications</h3>' . $node->field_lp_blog[0]['value'] . '<div class="mask"></div><a class="view" href="' . $node->field_lp_blog_more[0]['value'] . '">More</a></div>
                <div class="ff"></div>
          </div>';

  $ctas = '<div class="landing-download"><h3>Our Expertise (PDFs)</h3>';
  if (!empty($node->field_lp_dl_file_1[0]['filepath'])) {
    $ctas .= '<div class="landing-download-item item-1" style="background-image:url(\'/' . $node->field_lp_dl_img_1[0]['filepath'] . '\')"><a href="/' . $node->field_lp_dl_file_1[0]['filepath'] . '" target="_blank">' . $node->field_lp_dl_title_1[0]['value'] . '</a></div>';
  }
  if (!empty($node->field_lp_dl_file_2[0]['filepath'])) {
    $ctas .= '<div class="landing-download-item item-1" style="background-image:url(\'/' . $node->field_lp_dl_img_2[0]['filepath'] . '\')"><a href="/' . $node->field_lp_dl_file_2[0]['filepath'] . '" target="_blank">' . $node->field_lp_dl_title_2[0]['value'] . '</a></div>';
  }
  if (!empty($node->field_lp_dl_file_3[0]['filepath'])) {
    $ctas .= '<div class="landing-download-item item-1" style="background-image:url(\'/' . $node->field_lp_dl_img_3[0]['filepath'] . '\')"><a href="/' . $node->field_lp_dl_file_3[0]['filepath'] . '" target="_blank">' . $node->field_lp_dl_title_3[0]['value'] . '</a></div>';
  }
  if (!empty($node->field_lp_dl_file_4[0]['filepath'])) {
    $ctas .= '<div class="landing-download-item item-1" style="background-image:url(\'/' . $node->field_lp_dl_img_4[0]['filepath'] . '\')"><a href="/' . $node->field_lp_dl_file_4[0]['filepath'] . '" target="_blank">' . $node->field_lp_dl_title_4[0]['value'] . '</a></div>';
  }
  $ctas .= '</div>';

  $vdata = br_get_video_data($node->field_lp_v_link[0]['value']);
  $video = '<a href="' . $node->field_lp_v_link[0]['value'] . '" class="vi"><span class="video" style="display:none">' . drupal_to_js(array('video' => $vdata['embed'])) . '</span><img src="/' . $node->field_lp_v_image[0]['filepath'] . '" /></a>';
  drupal_add_js("
          $(document).ready(function(){
            $('.vi').click(function(){                
              var content = '';
              eval('content = ' + $('span.video', this).html());
                            
              init_popup('<div class=\"video\">' + content.video + '</div>');
              return false;              
            });            
          });
          ", 'inline');
  return '<div class="row1">
              <div class="col-left"><div class="text-wrapper">' . $node->body . '</div></div>
              <div class="col-right">' . $video . '</div>
              <div class="ff"></div>
           </div>' .
      '<div class="row2">
              <div class="col-left">' . $ctas . $contacts . '</div>
              <div class="col-right">' . $feeds . '</div>
              <div class="ff"></div>
           </div>';
}

function br_landing_pagef($node) {
  $vdata = br_get_video_data($node->field_lp_v_link[0]['value']);
  $video = '<a href="' . $node->field_lp_v_link[0]['value'] . '" class="vi"><span class="video" style="display:none">' . drupal_to_js(array('video' => $vdata['embed'])) . '</span><img src="/' . $node->field_lp_v_image[0]['filepath'] . '" /></a>';
  drupal_add_js("
          $(document).ready(function(){
            $('.vi').click(function(){                
              var content = '';
              eval('content = ' + $('span.video', this).html());
                            
              init_popup('<div class=\"video\">' + content.video + '</div>');
              return false;              
            });            
          });
          ", 'inline');
  $col1 = (isset($node->field_lp_blk_1[0]['value'])) ? lp_update_output($node->field_lp_blk_1[0]['value']) : '';
  $col2 = (isset($node->field_lp_blk_2[0]['value'])) ? lp_update_output($node->field_lp_blk_2[0]['value']) : '';
  $col3 = (isset($node->field_lp_blk_3[0]['value'])) ? lp_update_output($node->field_lp_blk_3[0]['value']) : '';
  $col4 = (isset($node->field_lp_blk_4[0]['value'])) ? lp_update_output($node->field_lp_blk_4[0]['value']) : '';

  $output = '<div class="row1"><div class="col-left"><div class="text-wrapper">' . $node->body . '</div></div>';
  $output .= '<div class="col-right">' . $video . '</div><div class="ff"></div></div>';
  $output .= '<div class="row2"><div class="col-left"><div class="col"';
  if (isset($node->field_lp_blk_1_colour[0]['value'])) {
    $output .= ' style="background-color:' . $node->field_lp_blk_1_colour[0]['value'] . '"';
  }
  $output .= '>' . $col1 . '</div><div class="col l-margin"';
  if (isset($node->field_lp_blk_2_colour[0]['value'])) {
    $output .= ' style="background-color:' . $node->field_lp_blk_2_colour[0]['value'] . '"';
  }
  $output .= '>' . $col2 . '</div></div>';
  $output .= '<div class="col-right"><div class="col"';
  if (isset($node->field_lp_blk_3_colour[0]['value'])) {
    $output .= ' style="background-color:' . $node->field_lp_blk_3_colour[0]['value'] . '"';
  }
  $output .= '>' . $col3 . '</div><div class="col l-margin"';
  if (isset($node->field_lp_blk_4_colour[0]['value'])) {
    $output .= ' style="background-color:' . $node->field_lp_blk_4_colour[0]['value'] . '"';
  }
  $output .= '>' . $col4 . '</div></div><div class="ff"></div></div>';
  return $output;
}

function lp_update_output($data) {
  if (strpos($data, 'class="view"') == TRUE) {
    $data = $data . '<div class="mask"></div>';
  }
  return $data;
}
