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
<div class="col-sm-6">
    <h3><?php
        print $row->node_title;
        ?></h3>
    <div class="desc"><?php
        print $view->render_field("body", $view->row_index);
        ?></div>
</div>
<div class="col-sm-6">
    <a target="_blank" class="vi" href="<?php echo $row->field_field_video_url[0]['raw']['safe_value']; ?>"><div class="img"><?php
            print $view->render_field("field_teaser_image", $view->row_index);
            if (isset($row->field_field_video_url[0]['raw']['safe_value'])):
              ?>
              <span class="video" style="display:none"><?php
                  $vdata = br_get_video_data($row->field_field_video_url[0]['raw']['safe_value']);
                  print drupal_json_encode(array('video' => $vdata['embed']));
                  ?></span><?php endif; ?></div></a>
</div>
<div class="clearfix"></div>