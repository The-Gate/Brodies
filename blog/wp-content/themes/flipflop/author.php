<?php get_header(); ?>
    
    <div id="content">
    <div class="col-full">
    	
    	<?php woo_main_before(); ?>
    	
		<section id="main" class="fullwidth"> 

		<?php if ( have_posts() ) : $count = 0; ?>
        <?php
            // Get the author data in a single rotation loop, and rewind the loop in order to display posts.
            while ( have_posts() ) {
                the_post();
                $count++;

                $author_id = get_the_author_meta( 'ID' );
                $display_name = get_the_author_meta( 'display_name' );
                $feed_link = get_author_feed_link( intval( $author_id ) );
                $bio = get_the_author_meta( 'description' );

                if ( $count == 1 ) { break; }
            }

            rewind_posts();
        ?>
    	<header id="post-author" class="archive-header">
            <?php echo '<span class="fl avatar-display profile-image">' . get_avatar( $author_id, '80' ) . '</span>' . "\n"; ?>
            <div class="profile-content">
        		<h1><?php echo $display_name; ?></h1>
                <div class="bio author-description"><?php echo $bio; ?></div>
            </div><!--/.profile-content-->
    	</header>

        <?php
        	// Display the description for this archive, if it's available.
        	woo_archive_description();
        ?>
        
	        <div class="fix"></div>
	        
        	<div id="archive-latest" class="col-full">
            <span class="fl archive-rss"><a href="<?php echo esc_url( $feed_link ); ?>" class="button" title="<?php esc_attr_e( 'RSS feed for this author', 'woothemes' ); ?>"><?php _e( 'RSS feed for this author', 'woothemes' ); ?></a></span>
        	<ul class="section-body">
        	
        	<?php woo_loop_before(); ?>
        	
			<?php /* Start the Loop */ ?>
			<?php while ( have_posts() ) : the_post(); $count++; ?>

				<?php
					/* Include the Post-Format-specific template for the content.
					 * If you want to overload this in a child theme then include a file
					 * called content-___.php (where ___ is the Post Format name) and that will be used instead.
					 */
					get_template_part( 'content', 'archive' );
				?>

			<?php endwhile; ?>
            
	        <?php else: ?>
	        
	            <article <?php post_class(); ?>>
	                <p><?php _e( 'Sorry, no posts matched your criteria.', 'woothemes' ); ?></p>
	            </article><!-- /.post -->
	        
	        <?php endif; ?>  
	        
	        <?php woo_loop_after(); ?>
    		
    		</ul>
    		
			<?php woo_pagenav(); ?>
            
            </div><!--/#archive-latest-->
                
		</section><!-- /#main -->
		
		<?php woo_main_after(); ?>

	</div><!-- /.col-full -->
    </div><!-- /#content -->		
		
<?php get_footer(); ?>