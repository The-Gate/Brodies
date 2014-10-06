<?php
/**
 * Template Name: Archives Page
 *
 * The archives page template displays a conprehensive archive of the current
 * content of your website on a single page. 
 *
 * @package WooFramework
 * @subpackage Template
 */
 
 global $woo_options; 
 get_header();

 $latest_posts = intval( apply_filters( 'woo_archives_latest_posts_total', 12 ) );
 $image_args = array( 'width' => '210', 'height' => '80', 'class' => 'thumbnail', 'link' => 'img' );
 $posts_by_month = intval( apply_filters( 'woo_archives_posts_by_month_total', 20 ) );
?> 
    <div id="content">
    <div class="col-full">
    
    	<?php woo_main_before(); ?>
    
		<section id="main" class="fullwidth">
			
			<article <?php post_class(); ?>>
			    
			    <header>
			    	<h1><?php the_title(); ?></h1>
			    </header>
			    
			    <section class="entry fix">
		
					<div id="archive-latest" class="col-full">
																	  
		            <?php woo_loop_before(); ?>
		            
		            <?php
		            	if ( have_posts() ) { the_post();
		            		the_content();
		            	}
		            ?>
				    <h3 class="section-title"><?php printf( __( 'Latest %s Posts', 'woothemes' ), $latest_posts ); ?></h3>												  
				    <ul class="section-body">											  
				        <?php
				        	$query = new WP_Query( array( 'posts_per_page' => intval( $latest_posts ), 'post_type' => 'post', 'post_status' => 'publish' ) );
				        	if ( $query->have_posts() ) {
				        		while ( $query->have_posts() ) { $query->the_post();
				        ?>	  
				            <li <?php post_class(); ?>><a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>"><?php woo_image( $image_args ); ?><div class="title"><?php the_title(); ?></div></a></li>
				        <?php
				        		}
				        	}
				        	
				        	unset( $query ); // We're done with $query, so remove it.
				        ?>					  
				    </ul>	
				    
				    <?php woo_loop_after(); ?>	
				    
					</div><!--/#archive-latest-->
					
					<?php
						$paged = 0; if ( is_paged() ) { $paged = get_query_var( 'paged' ); }
						$query = new WP_Query( array( 'posts_per_page' => intval( $posts_by_month ), 'paged' => $paged ) );
						/* Loop through and collect the posts by year -> month. */
						if ( $query->have_posts() ) {
							$sorted_posts = array();
							$html = '';
							
							while( $query->have_posts() ) {
								$query->the_post();

								$sorted_posts[(string)get_the_date( 'Y' )][(string)get_the_date( 'm' )][get_the_ID()] = $post;
							}

							/* Now that we have the posts sorted by year and month, loop through and create the HTML. */
							if ( is_array( $sorted_posts ) && count( $sorted_posts ) > 0 ) {
								$post = $original_post; // Preserve the original $post variable.
								$count = 1;
								foreach ( $sorted_posts as $k => $v ) { // Years Loop
									if ( is_array( $v ) && count( $v ) > 0 ) {
										foreach ( $v as  $i => $j ) { // Months Loop
											if ( ! is_array( $j ) || ( is_array( $j ) && count( $j ) <= 0 ) ) { continue; } // Don't show anything if we don't have posts here.

											$month_name = date( 'F', mktime( 0, 0, 0, $i ) );
											$number = count( $j );
											$html .= '<li class="year-' . esc_attr( intval( $k ) ) . ' month-archive month-' . esc_attr( strtolower( $month_name ) ) . ' fl widget post">' . "\n";
											$html .= '<h3>' . $month_name . ' ' . $k . ' <span> ' . _n( '1 Post', sprintf( '%s Posts', $number ), $number, 'woothemes' ) . '</span></h3>' . "\n";
											$html .= '<ul class="posts-list">' . "\n";
											foreach ( $j as $l => $post ) {
												setup_postdata( $post );
												$html .= '<li class="post-id-' . esc_attr( get_the_ID() ) . '"><a href="' . esc_url( get_permalink( get_the_ID() ) ) . '" title="' . the_title_attribute( array( 'echo' => 0 ) ) . '">' . get_the_title( get_the_ID() ) . '</a></li>' . "\n";
											}
											$html .= '</ul><!--/.posts-list-->' . "\n";
											$html .= '</li><!--/.month-archive-->' . "\n";
											$count++;
										}
									}
								}
								$saved_post = $post;
							}
						}
					?>
					<div id="archive-dates" class="col-full">												  
					    <h3 class="section-title"><?php _e( 'Archives by Dates', 'woothemes' ); ?></h3>
					    <div class="section-body">
						<?php if ( $html != '' ) { echo $html; } ?>
						</div><!--/.section-body-->
						<?php woo_pagination( array(), $query ); ?>
					</div><!--/#archive-dates-->

					<div id="categories" class="section_categories col-full">											
					    <h3 class="section-title"><?php _e( 'Categories', 'woothemes' ); ?></h3>	  
					    <ul class="section-body">											  
					        <?php wp_list_categories( 'title_li=&hierarchical=0&show_count=1' ); ?>	
					    </ul>											  
					</div><!--/#archive-categories-->	 												  

				</section><!-- /.entry -->
			    			
			</article><!-- /.post -->                 
                
        </section><!-- /#main -->
        
        <?php woo_main_after(); ?>

	</div><!-- /.col-full -->
    </div><!-- /#content -->		
		
<?php get_footer(); ?>