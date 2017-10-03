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
// build link
if (isset($link)) {
  $link_output = '<div class="cta-link">';
  if (!$is_webform_link) {
    $new_tab = ($open_in_new_link) ? ' target="_blank"' : '';
    $link_output .= '<a href="' . $link . '"'.$new_tab.'>' . $linktext . '</a>';
  }
  else {
    $link_output .= '<a class="openpopup ' . $linktext . '">' . $link . '</a>';
  }
  $link_output .="</div>";
}
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <?php
        print render($content);
        if (isset($link_output)){
          echo $link_output;
        }
        ?>
    </div>
    
</div>
