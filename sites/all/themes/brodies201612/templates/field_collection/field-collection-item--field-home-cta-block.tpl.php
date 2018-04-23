<?php
/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php
// set up the CTA width

$col_count = $content['field_columns_per_row_full']['#items'][0]['value'];


switch ($col_count) {
  case '4':
    $picture_name = 'col_4';
    break;
  case '6':
    $picture_name = 'col_6';
    break;
  case '12':
    $picture_name = 'col_12';
    break;
}
$col = 'col-md-' . $col_count;

// overlay
$overlay_title = '';
$isTitleImg = false;
if (!empty($content['field_lp_title_img'][0]['#item']['uri'])) {
// title - image
  $overlay_title = render($content['field_lp_title_img'][0]);
  $isTitleImg = true;
}
elseif (!empty($content['field_lp_cta_l_title'][0]['#markup'])) {
// title
  $overlay_title = $content['field_lp_cta_l_title'][0]['#markup'];
}
// text
$overlay_text = (!empty($content['field_lp_cta_l_text'][0]['#markup'])) ? $content['field_lp_cta_l_text'][0]['#markup'] : '';

// button
$overlay_button = (!empty($content['field_lp_cta_r_title'][0]['#markup'])) ? $content['field_lp_cta_r_title'][0]['#markup'] : '';

// bg colour [convert to rgba]
if (!empty($content['field_lp_blk_1_colour'][0]['#markup'])) {
  list($r, $g, $b) = sscanf(ltrim($content['field_lp_blk_1_colour'][0]['#markup'], '#'), "%02x%02x%02x");
  $overlay_bg = ' style="background:rgb(' . $r . ',' . $g . ',' . $b . '); opacity: .8;" ';
}
else {
  $overlay_bg = '';
}
// highlight colour
$overlay_highlight = (!empty($content['field_highlight_colour'][0]['#markup'])) ? $content['field_highlight_colour'][0]['#markup'] : '';

// links
$link_open = '';
$link_close = '';
if (!empty($content['field_video_url'][0]['#markup'])) {
// video link
  $vdata = br_get_video_data($content['field_video_url'][0]['#markup']);
  $link_open = '<a href="' . $content['field_video_url'][0]['#markup'] . '" class="vi"><span class="video" style="display:none">' . drupal_json_encode(array('video' => $vdata['embed'])) . '</span>';
  $link_close = '</a>';
}
elseif (!empty($content['field_cta_link'][0]['#markup'])) {
// page link
  $link_open = '<a href="' . $content['field_cta_link'][0]['#markup'] . '">';
  $link_close = '</a>';
}

$overlay_output = '';
if (strlen($overlay_title) > 0 or strlen($overlay_text) > 0 or strlen($overlay_button) > 0) {
  $overlay_output .= '<div class="cta-overlay-wrapper">';
  $overlay_output .= '<div class="cta-overlay-inner"';
  if (strlen($overlay_bg) > 0) {
    $overlay_output .= $overlay_bg;
  }
  $overlay_output .= '>';

  if (strlen($overlay_title) > 0) {
    $overlay_output .= '<div class="overlay-title';
    if (!$isTitleImg) {
      $overlay_output .= ' ' . $overlay_highlight;
    }
    $overlay_output .= '">' . $overlay_title . '</div>';
  }
  if (strlen($overlay_text) > 0) {
    $overlay_output .= '<div class="overlay-text">' . $overlay_text . '</div>';
  }
  if (strlen($overlay_button) > 0) {
    $overlay_output .= '<div class="overlay-button ' . $overlay_highlight . '">' . $link_open . $overlay_button . $link_close . '</div>';
  }
  $overlay_output .= '</div>';
  $overlay_output .= '</div>';
}

// set up the main image
// picture mapping
$img_open = '';
$img_close = '';
$fallback_image_style = 'col-12-sm-full';
if (!empty($content['field_cta_imge'][0])) {
  $image = $content['field_cta_imge'][0];
  $picture_mappings = picture_mapping_load($picture_name);
  $breakpoint_styles = picture_get_mapping_breakpoints($picture_mappings, $fallback_image_style);
// Load picture renderable array
  $picture = array(
    '#theme' => 'picture',
    '#width' => isset($image['#item']['width']) ? $image['#item']['width'] : NULL,
    '#height' => isset($image['#item']['height']) ? $image['#item']['height'] : NULL,
    '#style_name' => $fallback_image_style,
    '#breakpoints' => $breakpoint_styles,
    '#uri' => $image['#item']['uri'],
    '#alt' => isset($image['#item']['alt']) ? $image['#item']['alt'] : '',
    '#timestamp' => $image['#item']['timestamp'],
  );
  if (strlen($overlay_output) > 0) {
    $img_open = '<div class="home-cta-bg-img"><div class="hidden-sm">' . render($picture) . '</div>';
    $img_close = '</div>';
  }
  else {
    $img_open = '<div class="home-cta-bg-img">' . $link_open . render($picture) . $link_close;
    $img_close = '</div>';
  }
}
?>
<div class="<?php print $classes; ?> <?php echo $col; ?> cta-overlay"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <?php print $img_open; ?>
        <?php print $overlay_output; ?>
        <?php print $img_close; ?>
    </div>
</div>
