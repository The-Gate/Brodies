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
$person_node = node_load($content['field_related_people'][0]['#markup']);
$person_name = $person_node->title;
$person_job = $person_node->field_people_job[LANGUAGE_NONE][0]['safe_value'];
$img = render($content['field_lp_contact_l_img']);
?>
<div class="col-sm-4">
    <div class="content">
        <div class="cta-img"><?php echo $img; ?></div>
        <div class="cta-title-wrapper">
            <div class="cta-title"><?php echo $person_name; ?></div>
            <div class="cta-title"><?php echo $person_job; ?></div>
        </div>
    </div>
</div>
