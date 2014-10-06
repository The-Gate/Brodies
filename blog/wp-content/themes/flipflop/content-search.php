<?php
/**
 * The default template for displaying content
 */

	global $woo_options;
  
?>

	<article <?php post_class(); ?>>
	
	    <?php 
	    	if ( isset( $woo_options['woo_post_content'] ) && $woo_options['woo_post_content'] != 'content' ) { 
	    		woo_image( 'width=100&height=100&class=thumbnail alignleft' ); 
	    	} 
	    ?>
	    
		<header>
			<h1><a href="<?php the_permalink(); ?>" rel="bookmark" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h1>
			
			<aside class="post-meta">
				<ul>
					<li class="post-date"><span><?php echo get_the_date( $date_format ); ?></span></li>
				</ul>
			</aside>
				
		</header>

		<section class="entry">
			<?php the_excerpt(); ?>
		</section>

	</article><!-- /.post -->