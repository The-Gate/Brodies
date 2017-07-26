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
<div class="mod-quote">
    <div class="content cta-overlay">
        <div class="home-cta-bg-img">
            <?php
            preg_match_all('/src="([^"]+)"/', $row->aggregator_item_description, $images);
//print('<img '.$images[0][0].'>');

            if (!empty($images[0][0])) {
              $externalpath = str_replace(array('"', 'src='), '', $images[0][0]);
              print theme('imagecache_external', array(
                'path' => $externalpath,
                'style_name' => 'col-9--lg-max-h300',
              ));
            }
            else {
              ?>
              <img class="img-responsive" src="/sites/all/themes/brodies201612/images/grad-blog-default.jpg" width="770" height="300" alt="">
              <?php
            }
            ?>

            <div class="cta-overlay-wrapper">
                <div class="slide-header"><a href="http://www.brodies.com/blog/category/traineeships/" tabindex="-1">Latest News</a></div>
                <div class="cta-overlay-inner col-sm-12 col-md-11">
                    <div class="overlay-title"><a href="<?php print $row->aggregator_item_link; ?>"><?php print $row->aggregator_item_title; ?></a></div>
                    <div class="overlay-subtitle"><?php
                        $max_length = 300;
                        $wordsafe = TRUE;
                        $add_ellipsis = TRUE;
                        $min_wordsafe_length = 1;
                        $intro = strip_tags($row->aggregator_item_description);

                        print '<div>' . truncate_utf8($intro, $max_length, $wordsafe, $add_ellipsis, $min_wordsafe_length) . ' <a class="inline-read-more" href="' . $row->aggregator_item_link . '">Read More &#187;</a></div>';
                        ?> </div>
                </div>

            </div>
        </div>

    </div>
</div>
