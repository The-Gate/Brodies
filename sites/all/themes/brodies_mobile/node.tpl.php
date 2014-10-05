<?php
  if ($_GET['destination']) {
    $data = br_back_url($_GET['destination']);    
    print '<div class="back"><a href="'. url($data['q'], array('query' => $data['query'])) .'">&laquo; Back</a></div>';
  }
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?>">
<?php if ($page == 0): ?>
  <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<?php endif; ?>

  <div class="content clear-block">
    <?php print $content ?>
  </div>
  <?php 
   if (array_search($node->type, array('cs', 'news', 'sector', 'service', 'people')) !== FALSE) : ?><div class="top"><a href="#top">Back to top</a></div><?php endif;
  
  ?>
</div>
