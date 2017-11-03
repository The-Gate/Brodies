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
$person_path = drupal_get_path_alias('node/' . $person_node->nid);
$img = image_style_url('col-3--lg', $person_node->field_teaser_image[LANGUAGE_NONE][0]['uri']);
?>
<div class="col-sm-6 col-md-4 field-name-field-related-people">
    <article>
        <div class="field field-name-field-teaser-image"><a href="<?php echo $person_path; ?>"><img class="img-responsive" src="<?php echo $img; ?>"></a>
        </div>
        <div class="text-wrapper-container">
            <div class="text-wrapper">
                <div class="field field-name-field-people-fname"><?php echo $person_node->field_people_fname[LANGUAGE_NONE][0]['safe_value']; ?></div><div class="field field-name-field-people-sname"><?php echo $person_node->field_people_sname[LANGUAGE_NONE][0]['safe_value']; ?></div>
                <div class="field field-name-field-people-job"><?php echo $person_node->field_people_job[LANGUAGE_NONE][0]['safe_value']; ?></div>
                <div class="field field-name-field-people-phone"><?php echo $person_node->field_people_phone[LANGUAGE_NONE][0]['safe_value']; ?></div>
                <div class="field field-name-field-people-email"><div class="read-more-block"><a href="mailto:<?php echo $person_node->field_people_email[LANGUAGE_NONE][0]['safe_value'];; ?>">Email</a></div></div>
            </div>
        </div>
    </article>
</div>

