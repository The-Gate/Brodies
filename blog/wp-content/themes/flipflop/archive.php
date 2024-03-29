<?php get_header(); ?>
    
    <div id="content">
    <div class="col-full">
    	
    	<?php woo_main_before(); ?>
    	
		<section id="main" class="col-left"> 

		<?php if (have_posts()) : $count = 0; ?>
        
            <?php if (is_category()) { ?>
        	<header class="archive-header">
        		<h1 class="fl"><?php echo single_cat_title(); ?></h1> 
        		<span class="fr archive-rss"><?php $cat_id = get_cat_ID( single_cat_title( '', false ) ); echo '<a href="' . get_category_feed_link( $cat_id, '' ) . '">' . __( "RSS feed for this section", "woothemes" ) . '</a>'; ?></span>
        	</header>                    
            <?php } ?>

        <?php
        	// Display the description for this archive, if it's available.
        	woo_archive_description();
        ?>
        
	        <div class="fix"></div>
	        
        	<div id="archive-latest" class="col-full">
        
        	<?php if (is_category()) { ?>
        		<h3 class="section-title"><?php echo single_cat_title(); ?></h3> 
        		
            <?php } elseif (is_day()) { ?>
            	<h3 class="section-title"><?php the_time( get_option( 'date_format' ) ); ?></h3>

            <?php } elseif (is_month()) { ?>
            	<h3 class="section-title"><?php the_time( 'F, Y' ); ?></h3>

            <?php } elseif (is_year()) { ?>
            	<h3 class="section-title"><?php the_time( 'Y' ); ?></h3>

            <?php } elseif (is_author()) { ?>
            	<h3 class="section-title"><?php _e( 'Author', 'woothemes' ); ?></h3>

            <?php } elseif (is_tag()) { ?>
            	<h3 class="section-title"><?php echo single_tag_title( '', true ); ?></h3>
            
            <?php } ?>
        
        	<ul class="archiveList">
        	
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
            
		<?php get_sidebar(); ?>

	</div><!-- /.col-full-->
    </div><!-- /#content -->		
		
<?php get_footer(); ?>