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
$title_content = $main_content = "";
$path = current_path();
$path_alias = drupal_lookup_path('alias', $path);
if (!($row->field_field_event_full[0]['raw']['value'] == 0)) {
  // the event is fully booked, show the join waiting list link
  if (!empty($_SESSION['seminars-waitinglist'][$row->nid])) {
    $waiting_title = 'remove';
  }
  else {
    $waiting_title = 'Join waiting list';
  }
  $event_controls = '<div class="col-md-4"><div class="seminar-button warning">Fully Booked</div></div><div class="col-md-4"><div class="seminar-button waitlist link"><a href="' . $path_alias . '?seminars-waitinglist=' . $row->nid . '&amp;destination=' . $path . '" class="book active">' . $waiting_title . '</a></div></div>';
  $col_offset = '3';
}
else {
  if (!empty($_SESSION['seminars'][$row->nid])) {
    $basket_title = 'remove';
  }
  else {
    $basket_title = 'Add to Basket';
  }
  $event_controls = '<div class="col-md-4"><div class="seminar-button add"><a href="' . $path_alias . '?book-seminar=' . $row->nid . '&amp;destination=' . $path . '" class="book active">' . $basket_title . '</a></div></div>';
  $col_offset = '6';
}
?>
<?php foreach ($fields as $id => $field): ?>
  <?php $storeContent = ''; ?>
  <?php if (!empty($field->separator)): ?>
    <?php $storeContent .= $field->separator; ?>
  <?php endif; ?>

  <?php $storeContent .= $field->wrapper_prefix; ?>
  <?php $storeContent .= $field->label_html; ?>
  <?php $storeContent .= $field->content; ?>
  <?php $storeContent .= $field->wrapper_suffix; ?>

  <?php
  switch ($id) {
    case 'title':
      $title_content = $storeContent;
      break;
    case 'field_event_date_2':
      $main_content .= str_replace(' to ', ' - ', $storeContent);
      break;
    default:
      if ($id == 'nothing') {
        // the read more button is in the global text field: 'nothing'
        $storeContent = '<div class="col-md-9 no-padding col-md-offset-' . $col_offset . '">' . $event_controls . '<div class="col-md-4 no-padding-right-md">' . $storeContent . '</div></div>';
      }
      $main_content .= $storeContent;
  }
  ?>
<?php endforeach; ?>

<?php print ($title_content); ?>
<div class="row-content-wrapper">
    <?php print ($main_content); ?>
</div>
