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
<?php if (isset($variables['field_video_url'][0]['safe_value'])): ?>
  <div class="col-sm-offset-2 col-sm-8">
      <div class="embed-responsive embed-responsive-16by9 youtubeframe">
          <iframe class="embed-responsive-item" src="<?php echo $variables['field_video_url'][0]['safe_value']; ?>?rel=0" frameborder="0" allowfullscreen></iframe>
      </div>
  </div>
  <div class="clearfix"></div>
<?php endif; ?>