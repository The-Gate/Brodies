<?php
/**
 * The default template for displaying content
 */

	global $woo_options;
 
/**
 * The Variables
 *
 * Setup default variables, overriding them if the "Theme Options" have been saved.
 */

 $image_args = array( 'width' => '210', 'height' => '80', 'class' => 'thumbnail', 'link' => 'img' );
 
?>
	    
	<li <?php post_class(); ?>><a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>"><?php woo_image( $image_args ); ?><h3 class="title"><?php the_title(); ?></h3></a>
		<aside class="post-meta">
					<ul>
						<li class="post-date"><span><?php echo get_the_date( $date_format ); ?></span></li>
						<li class="archive-post-tags"><?php the_tags(); ?></li>
					</ul>
				</aside>
		
		<div class="archive-post-content"><?php echo substr(get_the_excerpt(), 0,300); ?>...
			<div class="archive-post-readmore"><a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>">Read More</a></div>
		</div>
		
	</li>