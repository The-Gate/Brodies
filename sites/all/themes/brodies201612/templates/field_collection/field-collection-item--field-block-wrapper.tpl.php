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
// link text/url: field-cta-link
// webform : field_is_webform
// webform : field_open_in_new_tab_
$is_webform_link = false;
$open_in_new_link = false;
if (isset($content['field_is_webform']['#items'][0]['value'])) {
  if ($content['field_is_webform']['#items'][0]['value'] == '1') {
    $is_webform_link = true;
  }
  unset($content['field_is_webform']);
}
if (isset($content['field_cta_link'])) {
  $link = strip_tags($content['field_cta_link'][0]['#markup']);
  unset($content['field_cta_link']);
}
if (isset($content['field_cta_text'])) {
  $linktext = strip_tags($content['field_cta_text'][0]['#markup']);
  unset($content['field_cta_text']);
}
if (isset($content['field_open_in_new_tab_']['#items'][0]['value'])) {
  if ($content['field_open_in_new_tab_']['#items'][0]['value'] == '1') {
    $open_in_new_link = true;
  }
  unset($content['field_open_in_new_tab_']);
}
$linkBackgroundStyle = '';
$linkWrapperBackgroundStyle = '';
if (isset($content['field_title_icon']['#items'][0])) {
  $height = $content['field_title_icon']['#items'][0]['height'];
  $width = $content['field_title_icon']['#items'][0]['width'];
  $img_url = file_create_url($content['field_title_icon']['#items'][0]['uri']);
  $button_height = (($height + 20) > 60) ? ($height + 20) : 60;
  $linkBackgroundStyle = 'style="background: url(\'' . $img_url . '\'); padding-left: ' . ($width + 20) . 'px;width:calc(100vw - 40px); max-width:100%; height:' . $button_height . 'px; background-position:0 50%; display:table-cell; vertical-align:middle; background-repeat:no-repeat;"';

  unset($content['field_title_icon']);
}

if (isset($content['field_lp_blk_1_colour'][0]['#markup'])) {
  $colour_raw = trim($content['field_lp_blk_1_colour'][0]['#markup']);
  if (strlen($colour_raw) == 7) {
    $linkWrapperBackgroundStyle = 'style="background: ' . $colour_raw . ';"';
  }
  elseif (strlen($colour_raw) > 7) {
    $colour_array = explode(' ', $colour_raw);
    if (count($colour_array) == 2) {
      $linkWrapperBackgroundStyle = ' style="background: ' . $colour_array[0] . ';background: linear-gradient(' . $colour_array[0] . ',' . $colour_array[1] . ');" ';
    }
  }

  if ((strlen($linkWrapperBackgroundStyle) > 0) && (strlen($linkBackgroundStyle) == 0)) {
    $linkBackgroundStyle = 'style="background:transparent;"';
  }
  unset($content['field_lp_blk_1_colour']);
}
// build link
if (isset($link)) {
  $link_output = '<div class="cta-link"' . $linkWrapperBackgroundStyle . '>';
  if (!$is_webform_link) {
    $new_tab = ($open_in_new_link) ? ' target="_blank"' : '';
    $link_output .= '<a href="' . $link . '"' . $new_tab . $linkBackgroundStyle . '>' . $linktext . '</a>';
  }
  else {
    $link_output .= '<a href="#" ' . $linkBackgroundStyle . 'class="wf" data-input-element="' . $linktext . '">' . $link . '</a>';
  }
  $link_output .="</div>";
}
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <?php
        print render($content);
        if (isset($link_output)) {
          echo $link_output;
        }
        ?>
    </div>

</div>
