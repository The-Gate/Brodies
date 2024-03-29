<?php
/**
 * Single Post Template
 *
 * This template is the default page template. It is used to display content when someone is viewing a
 * singular view of a post ('post' post_type).
 * @link http://codex.wordpress.org/Post_Types#Post
 *
 * @package WooFramework
 * @subpackage Template
 */
	get_header();
	global $woo_options;
	
/**
 * The Variables
 *
 * Setup default variables, overriding them if the "Theme Options" have been saved.
 */
	
	$settings = array(
					'thumb_single' => 'false', 
					'single_w' => 200, 
					'single_h' => 200, 
					'thumb_single_align' => 'alignright'
					);
					
	$settings = woo_get_dynamic_values( $settings );
?>
       
    <div id="content">
    <div class="col-full">
    
    	<?php woo_main_before(); ?>
    	
		<section id="main" class="col-left">
		           
        <?php
        	if ( have_posts() ) { $count = 0;
        		while ( have_posts() ) { the_post(); $count++;
        ?>
			<article <?php post_class('fix'); ?>>
			
                <header>
                
	                <h1><?php the_title(); ?></h1>
	                
                </header>

                <?php woo_post_meta(); ?>
                
	           <div class="section-body">

				<?php echo woo_embed( 'width=580' ); ?>
                <?php if ( $settings['thumb_single'] == 'true' && ! woo_embed( '' ) ) { woo_image( 'width=' . $settings['single_w'] . '&height=' . $settings['single_h'] . '&class=thumbnail ' . $settings['thumb_single_align'] ); } ?>
                
                <section class="entry fix">
                	<div class="column column-01">
                		<?php the_content(); ?>
               		</div><!--/.column-->
					<?php wp_link_pages( array( 'before' => '<div class="page-link">' . __( 'Pages:', 'woothemes' ), 'after' => '</div>' ) ); ?>
				</section>
									                
				</div><!-- .section-body -->
                                
            </article><!-- .post -->

				<?php if ( isset( $woo_options['woo_post_author'] ) && $woo_options['woo_post_author'] == 'true' ) { ?>
				<aside id="post-author"  class="fix section-body">
					<div class="profile-image"><?php echo get_avatar( get_the_author_meta( 'ID' ), '55' ); ?></div>
					<div class="profile-content">
						<h3 class="title"><?php printf( esc_attr__( 'About %s', 'woothemes' ), get_the_author() ); ?></h3>
						<div class="author-description">
						<?php the_author_meta( 'description' ); ?>
						<div class="profile-link">
							<a href="<?php echo get_author_posts_url( get_the_author_meta( 'ID' ) ); ?>">
								<?php printf( __( 'Posts by %s <span class="meta-nav">&rarr;</span>', 'woothemes' ), get_the_author() ); ?>
							</a>
						</div><!-- .profile-link -->
						</div><!-- .author-description	-->
					</div><!-- .profile-content -->
				</aside><!-- .post-author-box -->
				<?php } ?>

				<?php woo_subscribe_connect(); ?>

	        <nav id="post-entries" class="fix">
	        	<div id="home-link"><a class="button" href="<?php bloginfo( 'url' ); ?>"><?php _e('Home','woothemes'); ?></a></div>
	            <div id="post-nav-links" class="section-body">
	            	<div class="nav-prev fl"><?php previous_post_link( '%link', '<span class="meta-nav button"><span class="prev"></span></span><span class="title">%title</span>' ); ?></div>
	            	<div class="nav-next fr"><?php next_post_link( '%link', '<span class="title">%title</span><span class="meta-nav button"><span class="next"></span></span>' ); ?></div>
	            </div>
	        </nav><!-- #post-entries -->
            <?php
            	// Determine wether or not to display comments here, based on "Theme Options".
            	if ( isset( $woo_options['woo_comments'] ) && in_array( $woo_options['woo_comments'], array( 'post', 'both' ) ) ) {
            		comments_template();
            	}

				} // End WHILE Loop
			} else {
		?>
			<article <?php post_class(); ?>>
            	<p><?php _e( 'Sorry, no posts matched your criteria.', 'woothemes' ); ?></p>
			</article><!-- .post -->             
       	<?php } ?>  
        
        <?php get_template_part ( 'includes/category-panel' ); ?>

		</section><!-- #main -->
		
		<?php woo_main_after(); ?>

        <?php get_sidebar(); ?>

	</div><!-- /.col-full -->
    </div><!-- /#content -->		
		
<?php get_footer(); ?>