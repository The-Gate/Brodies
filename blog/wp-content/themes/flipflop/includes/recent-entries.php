<?php
/**
 * Recent Entries Template Part
 *
 * Here we setup all logic and XHTML that is required for the recent entries template part, used on the homepage.
 *
 * @package WooFramework
 * @subpackage Template
 */

 global $woo_options;

 /* The Settings */
 $token = 'recent_entries';
 $settings = array(
 				$token . '_title' => '', 
 				$token . '_limit' => 6, 
 				$token . '_featured' => 2, 
 				$token . '_image_enable' => 'true', 
 				$token . '_image_width' => 130, 
 				$token . '_image_height' => 85, 
 				$token . '_image_align' => 'left', 
 				$token . '_button_title' => '', 
 				$token . '_button_page_id' => '', 
 				$token . '_exclude_featured' => 'true'
 				);

 $settings = woo_get_dynamic_values( $settings );

 /* woo_image Arguments */
 $image_args = array( 'width' => intval( $settings[$token . '_image_width'] ), 'height' => intval( $settings[$token . '_image_height'] ), 'class' => 'thumbnail align' . esc_attr( $settings[$token . '_image_align'] ) );

 /* The Query */
 $args = array(
 				'post_type' => array( 'post' ), 
 				'post_status' => 'publish', 
 				'suppress_filters' => 0, 
 				'posts_per_page' => intval( $settings[$token . '_limit'] )
 			);

 /* Check if we need to exclude any posts. */
 if ( $settings[$token . '_exclude_featured'] == 'true' ) {
	 $exclude = get_option( 'woo_exclude', '' );
	 if ( $exclude != '' ) {
	 	$exclude = maybe_unserialize( $exclude );
	 }

	 $to_be_excluded = array();
	 if ( is_array( $exclude ) && count( $exclude ) > 0 ) {
	 	$to_be_excluded = array_map( 'intval', $exclude );
	 	$args['post__not_in'] = $to_be_excluded;
	 }
 }

 $query = new WP_Query( $args );

 if ( $query->have_posts() ) {
 	$date_format = get_option( 'date_format' );
 	$type = 'featured';
?>
<section id="recent-entries" class="col-full">    
	<?php if ( $settings[$token . '_title'] != '' ) { ?><h3 class="section-title"><?php echo $settings[$token . '_title']; ?></h3><?php } ?>    
	<ul class="section-body primary">
<?php
	while ( $query->have_posts() ) { $query->the_post();
	if ( ( $query->current_post ) == $settings[$token . '_featured'] ) {
		$type = 'small';
?>		
		</ul>
		<!-- Recent Entries Small -->
		<ul class="section-body secondary">
		<ul class="lc fl">
<?php
	}
	if ( $type == 'featured' ) {
?>
        	<li <?php post_class(); ?>>
			<header><h2 class="title"><a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h2></header>
        
			<aside class="post-meta">
			<ul>
				<li class="post-date"><span><?php echo get_the_date( $date_format ); ?></span></li>
			</ul>
			</aside>

			<?php if ( $settings[$token . '_image_enable'] == 'true' ) { ?>
			<a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>" title="<?php the_title_attribute(); ?>"><?php woo_image( $image_args ); ?></a>
			<?php } ?>
			<?php the_excerpt(); ?>
			<div class="fix"></div>
			</li>
<?php
	} else {
?>		
        	<li <?php post_class(); ?>>     	
			<header><h3 class="title"><a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h3></header>
			                					
			<aside class="post-meta">
				<ul>
					<li class="post-date"><span><?php echo get_the_date( $date_format ); ?></span></li>
				</ul>
			</aside>
			</li>
<?php
	}
} // End WHILE Loop
?></ul><?php
  // Display "All Articles" button, if instructed.
	if ( $settings[$token . '_button_title'] != '' && intval( $settings[$token . '_button_page_id'] ) != 0 ) {
		echo '<li class="chevron post fr"><div class="arrow"><div></div></div><a href="' . esc_url( get_permalink( intval( $settings[$token . '_button_page_id'] ) ) ) . '" title="' . esc_attr( $settings[$token . '_button_title'] ) . '" class="button chev fr">' . $settings[$token . '_button_title'] . '</a></li>' . "\n";
	}
?>
</ul>			    
</section><!-- /#recent-entries -->
<?php
}
unset( $query ); // Remove the $query variable as no longer needed.
?>