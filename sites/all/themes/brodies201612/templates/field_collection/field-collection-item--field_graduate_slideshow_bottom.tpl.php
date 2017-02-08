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
// title
$overlay_title = (!empty($content['field_lp_cta_l_title'][0]['#markup'])) ? $content['field_lp_cta_l_title'][0]['#markup'] : '';
// text
$overlay_text = (!empty($content['field_lp_cta_l_text'][0]['#markup'])) ? $content['field_lp_cta_l_text'][0]['#markup'] : '';
// subtitle
$overlay_subtitle = (!empty($content['field_cta_text'][0]['#markup'])) ? $content['field_cta_text'][0]['#markup'] : '';
// button
$overlay_button = (!empty($content['field_lp_cta_r_title'][0]['#markup'])) ? $content['field_lp_cta_r_title'][0]['#markup'] : '';

$overlay_output = '';
if (strlen($overlay_title) > 0 or strlen($overlay_text) > 0 or strlen($overlay_button) > 0) {
  if (strlen($overlay_text) > 0) {
    $overlay_output .= '<div class="overlay-text"><blockquote><img src="/sites/all/themes/brodies201612/images/quote-open.png" class="quote-open">' . $overlay_text . '<img src="/sites/all/themes/brodies201612/images/quote-close.png" class="quote-close"></blockquote></div>';
  }
  if (strlen($overlay_title) > 0) {
    $overlay_output .= '<div class="overlay-title">' . $overlay_title . '</div>';
  }
  if (strlen($overlay_subtitle) > 0) {
    $overlay_output .= '<div class="overlay-subtitle">' . $overlay_subtitle . '</div>';
  }
}

// set up the main image
// picture mapping
$img_open = '';
$img_close = '';
$fallback_image_style = 'col-12-sm-full';
$picture_name = 'col_3';
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
}
?>
<div class="<?php print $classes; ?> cta-overlay grad-slide"<?php print $attributes; ?>>
    <div class="content is-table-row"<?php print $content_attributes; ?>>
        <div class="col-sm-3"><?php print render($picture); ?></div>
        <div class="col-sm-9"><?php print $overlay_output; ?></div>
    </div>
</div>
