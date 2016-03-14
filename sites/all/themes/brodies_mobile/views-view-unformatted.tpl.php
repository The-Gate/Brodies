<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?>">
    <?php print $row; ?>
    <?php     
    if (($view->current_display == 'block_3' || $view->current_display == 'block_5' || $view->current_display == 'block_4') && $view->name == 'top_news') {      
      $node = node_load($view->result[$id]->nid);
      $date = $node->field_date[0]['value']?$node->field_date[0]['value']:$node->created;
      print '<div class="date">'. date("d.m.y", $date) .'</div>';
    }
    ?>
  </div>
<?php endforeach; ?>
