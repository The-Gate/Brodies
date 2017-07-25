<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
//overwrite any block content with a banner worked out depending on what type, page or view it showing this block.

$theme_path = '/sites/all/themes/brodies201612/images/banner-images/';
$image_src = '/sites/default/files/main-nav-background.jpg';

switch (arg(0)) {
  case 'people':
    // people listing page
    $image_src = $theme_path . 'banner-people.jpg';
    break;
  case 'case-studies':
    // case study listing page
    $image_src = $theme_path . 'banner-case-study.jpg';
    break;
  case 'news':
    // news listing page
    $image_src = $theme_path . 'banner-news.jpg';
    break;
  case 'videos':
    // videos listing page
    $image_src = $theme_path . 'banner-video.jpg';
    break;
  case 'node':
    if (is_numeric(arg(1)) && !arg(2)) {
      $node = node_load(arg(1));
      switch ($node->type) {
        case 'people':
          // people details page
          $image_src = $theme_path . 'banner-people.jpg';
          break;
        case 'cs':
          // case studies details page
          $image_src = $theme_path . 'banner-case-study.jpg';
          break;
        case 'news':
          // news details page
          $image_src = $theme_path . 'banner-news.jpg';
          break;
        default:
          // check if this page has a banner set
          if (isset($node->field_banner_image['und'][0]['uri'])) {
            $image_src = image_style_url('banner_image', $node->field_banner_image['und'][0]['uri']);
          }
          break;
      }
    }
    break;
  default:
    break;
}
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="content"<?php print $content_attributes; ?>>
        <div style="background:url('<?php echo $image_src; ?>') top center no-repeat;width: 100%; height: 261px; margin:0; background-size:cover"></div>
    </div>
</div>
