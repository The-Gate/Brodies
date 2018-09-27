<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php
// content link
if (isset($row->field_field_lp_cta_l_url[0]['raw']['safe_value'])) {
// external
  $link = $row->field_field_lp_cta_l_url[0]['raw']['safe_value'];
}
else {
  // internal
  $link = drupal_get_path_alias('node/' . $row->nid);
}
?>

<?php
// content type 
$nt_class = $nt_title = $target = '';
switch ($row->node_type) {
  case 'feed_import':
    $nt_class = 'blog';
    $nt_title = 'Blog';
    $raw_date = $row->node_created;
    $target = ' target="_blank"';
    break;
  case 'lupdate':
    $nt_class = 'legal';
    $nt_title = 'Legal Update';
    $raw_date = $row->field_field_l_date[0]['raw']['value'];
    break;
  case 'news':
    $nt_class = 'news';
    $nt_title = 'News';
    $raw_date = $row->node_created;
    break;
}
echo '<div class="icon"><span class="icon-img ' . $nt_class . '"></span>' . $nt_title . '</div>';
?>
<?php
//image: col-3--lg--thumb-fixed
$img_style = 'col-3--lg--thumb-fixed-mod-height';
// feed import - external image
if (!(empty($row->field_field_d_url[0]['raw']))) {
  $html = trim($row->field_field_d_url[0]['raw']['value']);
  $doc = new DOMDocument();
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);
  $src = $xpath->evaluate("string(//img/@src)"); # "/images/image.jpg"
  if (isset($src)) {
    $img = theme('imagecache_external', array(
      'path' => $src,
      'style_name' => $img_style,
    ));
  }
}
// news / legal update iamge - internal image
elseif (!empty($row->field_field_teaser_image)) {
  $img = render($row->field_field_teaser_image);
}
if (isset($img)) {
  echo($img);
}
else {
  echo('<img class="img-responsive" src="/sites/all/themes/brodies201612/images/brexit-hub/bgimg-legalupdate.jpg" width="290" height="120" alt="">');
}
?>
<div class="bg-wrap">
<h2><?php print truncate_utf8($row->node_title, 55, TRUE, TRUE); ?></h2>
<p class="date"><?php echo format_date($raw_date, 'brodies_date_only_long_'); ?></p>
<p class="abstract"><?php echo truncate_utf8(filter_xss($row->_field_data['nid']['entity']->body['und'][0]['safe_value'], array()), 110, TRUE, TRUE); ?></p>
<p class="read-more <?php echo $nt_class; ?>"><a href="<?php echo $link; ?>"<?php echo  $target; ?>>Read more</a></p>
</div>