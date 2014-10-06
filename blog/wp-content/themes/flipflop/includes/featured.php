<?php
/**
 * Homepage Slider
 */
	global $wp_query, $post, $woo_options, $panel_error_message, $woothemes_column_generator;

	$token = 'featured';

	$settings = array(
					'thumb_single' => 'false', 
					'single_w' => 200, 
					'single_h' => 200, 
					'thumb_single_align' => 'alignright',
					$token . '_entries' => 3,
					$token . '_order' => 'DESC',
					$token . '_sliding_direction' => 'vertical',
					$token . '_effect' => 'slide',
					$token . '_speed' => '7',
					$token . '_hover' => 'false',
					$token . '_touchswipe' => 'true',
					$token . '_animation_speed' => '0.6',
					$token . '_pagination' => 'false',
					$token . '_nextprev' => 'true', 
					$token . '_post_content' => 'content', 
					$token . '_category' => '', 
					$token . '_tag' => ''
					);
					
	$settings = woo_get_dynamic_values( $settings );
	
	$count = 0;
?>

<?php
	$featposts = $settings[$token . '_entries']; // Number of featured entries to be shown
	$orderby = 'date';
	if ( $settings[$token . '_order'] == 'rand' ) {
		$orderby = 'rand';
	}

	$args = array(
						'post_type' => 'post', 
						'numberposts' => intval( $featposts ), 
						'order' => $settings[$token . '_order'], 
						'orderby' => $orderby, 
						'suppress_filters' => 0
					);

	/* Taxonomy Query Arguments */
	if ( intval( $settings[$token . '_category'] ) > 0 || intval( $settings[$token . '_tag'] ) > 0 ) {
	 	$args['tax_query'] = array();
	 	$args['tax_query']['relation'] = 'AND';

	 	if ( intval( $settings[$token . '_category'] ) > 0 ) {
	 		$args['tax_query'][] = array( 'taxonomy' => 'category', 'field' => 'id', 'terms' => intval( $settings[$token . '_category'] ) );
	 	}
	 	if ( intval( $settings[$token . '_tag'] ) > 0 ) {
	 		$args['tax_query'][] = array( 'taxonomy' => 'post_tag', 'field' => 'id', 'terms' => intval( $settings[$token . '_tag'] ) );
	 	}
	}

	$slides = get_posts( $args ); ?>
<?php if ( count( $slides ) > 0 ) { $slide_ids = array(); ?>  
	<section id="featured" class="col-full">
	
	<nav id="post-entries" class="col-full">
		<div id="post-nav-links"></div>
	</nav>
		
	    <ul class="slides fix">
	        
            <?php foreach( $slides as $post ) { setup_postdata( $post ); $count++; ?>    
	        <?php $woothemes_column_generator->current_column = 2; ?>
	            <li id="slide-<?php echo $count; ?>" class="slide slide-id-<?php the_ID(); ?>">
	        		
			<article <?php post_class( 'fix ' . esc_attr( $woothemes_column_generator->get_layout_by_id( get_the_ID() ) ) ); ?>>
			
                <header>
                
	                <h1><a href="<?php the_permalink(); ?>" rel="bookmark" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h1>
	                
                </header>

                <?php woo_post_meta(); ?>
                
	           <div class="section-body">

				<?php echo woo_embed( 'width=580' ); ?>
                <?php if ( $settings['thumb_single'] == 'true' && ! woo_embed( '' ) ) { woo_image( 'width=' . $settings['single_w'] . '&height=' . $settings['single_h'] . '&class=thumbnail ' . $settings['thumb_single_align'] ); } ?>
                
                <section class="entry fix">
                	<?php
                		if ( $settings['featured_post_content'] == 'content' ) {
                			echo '<div class="column column-01">' . "\n";
                			the_content();
                			echo '</div><!--/.column-->' . "\n";
                		} else {
                			the_excerpt();
                		}
                	?>
					<?php wp_link_pages( array( 'before' => '<div class="page-link">' . __( 'Pages:', 'woothemes' ), 'after' => '</div>' ) ); ?>
				</section>
									                
				</div><!-- .section-body -->
                                
            </article><!-- .post -->

				<?php if ( isset( $woo_options['woo_post_author'] ) && $woo_options['woo_post_author'] == 'true' ) { ?>			
				<div class="section-body">
				<aside id="post-author" class="fix">
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
				</div>
				<?php } ?>
	            	
	            </li><!--/.slide-->
	            
			<?php
				$slide_ids[] = get_the_ID();
				}
				// Track which posts we've loaded here, for exclusion in the "recent entries" section.
				if ( is_array( $slide_ids ) && ( count( $slide_ids ) > 0 ) ) { update_option( 'woo_exclude', maybe_serialize( $slide_ids ) ); } 
				wp_reset_postdata();
			?> 
			
	    </ul><!-- /.slides -->
	    
	    
	</section><!-- /#featured -->
<?php
// Slider Settings
/*
$slideDirection = $settings['featured_sliding_direction'];
$animation = $settings['featured_effect'];
*/
$animation = "fade";
if ( $settings['featured_speed'] == "Off" ) { $slideshow = 'false'; } else { $slideshow = 'true'; }
$pauseOnHover = $settings['featured_hover'];
$touchSwipe = $settings['featured_touchswipe'];
$slideshowSpeed = $settings['featured_speed'] * 1000; // milliseconds
$animationDuration = $settings['featured_animation_speed'] * 1000; // milliseconds
$pagination = $settings['featured_pagination'];
$nextprev = $settings['featured_nextprev']; 
?>

<script type="text/javascript">
   jQuery(window).load(function() {
   	jQuery('#featured').flexslider({
   		/* slideDirection: "<?php echo $slideDirection; ?>", */
   		animation: "<?php echo $animation; ?>",
   		controlsContainer: "#post-entries #post-nav-links",
   		slideshow: <?php echo $slideshow; ?>,
   		directionNav: <?php echo $nextprev; ?>,
   		controlNav: <?php echo $pagination; ?>,
   		pauseOnHover: <?php echo $pauseOnHover; ?>,
   		slideshowSpeed: <?php echo $slideshowSpeed; ?>, 
   		animationDuration: <?php echo $animationDuration; ?>
   	});
   	jQuery( '#slides' ).addClass( 'loaded' );
   });
	
</script>

<?php } else { ?>
	<div class="col-full"><?php echo do_shortcode('[box type="info"]Please add some slides in the WordPress admin backend to show in the Featured Slider.[/box]'); ?></div>
<?php } ?> 
