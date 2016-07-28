<?php
/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
// peaple teaser display
?>

<div id="node-<?php
print $node->nid;
?>" class="l-people node<?php
     if ($sticky) {
       print ' sticky';
     }
     ?><?php
     if (!$status) {
       print ' node-unpublished';
     }
     ?> clear-block">
    <div class="item embedded">
        <div class="col-left">
            <div class="img"><a href="<?php print $node_url ?>"><?php print $field_teaser_image[0]['view']; ?></a></div>
        </div>
        <div class="col-right">
            <div class="name"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></div>
            <div class="nr"><?php print $field_people_phone[0]['view']; ?></div>
            <div class="email"><a href="<?php
                $email = trim($field_people_email[0]['view']);
                print($email);
                ?>">Email</a></div>
        </div>
        <div class="ff"></div>
    </div>
    <div class="related-people-sidebar">
        <?php if (!$page): ?>
          <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
        <?php endif; ?>
        <div class="content">
            <?php print $content ?>
        </div>
    </div>
</div>