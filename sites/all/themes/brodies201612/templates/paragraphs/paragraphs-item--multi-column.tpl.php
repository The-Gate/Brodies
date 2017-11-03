<?php
/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php
// get the number of items per row
$col_count = $content['field_columns_per_row']['#items'][0]['value'];
switch ($col_count) {
  case '2':
    $col_class = "col-sm-6";
    break;
  case '3':
    $col_class = "col-sm-4";
    break;
}
?>
<div class="multiblock">
    <?php
    $total_blocks = count($content['field_block_wrapper']['#items']);
    $i = 0;
    while ($i < $total_blocks) {
      echo '<div class="' . $col_class . '">';
      echo render($content['field_block_wrapper'][$i]);
      echo '<div class="clearfix"></div>';
      echo '</div>';
      $i++;
    }
    ?>
</div>
<div class="clearfix"></div>
