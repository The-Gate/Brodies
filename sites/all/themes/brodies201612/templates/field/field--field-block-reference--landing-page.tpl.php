<?php
/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used by Drupal core, which uses theme functions instead for
 * performance reasons. The markup is the same, though, so if you want to use
 * template files rather than functions to extend field theming, copy this to
 * your custom theme. See theme_field() for a discussion of performance.
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<?php
$linktext = 'Start the conversation';
$link = '#';

$inputEl = '';
if (isset($element['#object']->field_l_left[LANGUAGE_NONE][0]['safe_value'])) {
  $inputEl = ' data-input-element="' . $element['#object']->field_l_left[LANGUAGE_NONE][0]['safe_value'] . '"';
}

$linkBackgroundStyle = '';
$linkWrapperBackgroundStyle = '';
if (isset($element['#object']->field_title_icon[LANGUAGE_NONE][0])) {
  $height = $element['#object']->field_title_icon[LANGUAGE_NONE][0]['height'];
  $width = $element['#object']->field_title_icon[LANGUAGE_NONE][0]['width'];
  $img_url = file_create_url($element['#object']->field_title_icon[LANGUAGE_NONE][0]['uri']);
  $linkBackgroundStyle = ' style="background: url(\'' . $img_url . '\');padding-left: ' . ($width + 20) . 'px;height:' . ($height + 20) . 'px; background-position:10px 10px; display:table-cell; vertical-align:middle; background-repeat:no-repeat;" ';

  unset($element['#object']->field_title_icon[LANGUAGE_NONE]);
}

if (isset($element['#object']->field_lp_blk_1_colour[LANGUAGE_NONE][0]['safe_value'])) {
  $colour_raw = trim($element['#object']->field_lp_blk_1_colour[LANGUAGE_NONE][0]['safe_value']);
  if (strlen($colour_raw) == 7) {
    $linkWrapperBackgroundStyle = ' background: ' . $colour_raw . ';';
  }
  elseif (strlen($colour_raw) > 7) {
    $colour_array = explode(' ', $colour_raw);
    if (count($colour_array) == 2) {
      $linkWrapperBackgroundStyle = ' background: ' . $colour_array[0] . ';background: linear-gradient(' . $colour_array[0] . ',' . $colour_array[1] . '); ';
    }
  }
  if ((strlen($linkWrapperBackgroundStyle) > 0) && (strlen($linkBackgroundStyle)==0)) {
    $linkBackgroundStyle = 'style="background:transparent;"';
  }
  unset($element['#object']->field_lp_blk_1_colour[LANGUAGE_NONE]);
}

$link_output = '<p>If you would like further information</p>';
$link_output .= '<p style="display:inline-block; margin:1em auto;' . $linkWrapperBackgroundStyle . '"><a class="wf" href="' . $link . '"' . $linkBackgroundStyle . $inputEl . '>' . $linktext . '</a></p>';
?>


<div class="webform-block">
    <div class="intro">

        <?php
        if (isset($link_output)) {
          echo $link_output;
        }
        ?>
    </div>
    <div id="webform" class="hide">
        <div class="webform-wrapper">
            <?php foreach ($items as $delta => $item): ?>
              <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
            <?php endforeach; ?>
        </div>
    </div>
</div>



