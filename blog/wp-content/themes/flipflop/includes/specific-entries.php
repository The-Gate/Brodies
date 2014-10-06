<?php
/**
 * Specific Entries Template Part
 *
 * Here we setup all logic and XHTML that is required for the specific entries template part, used on the homepage.
 *
 * @package WooFramework
 * @subpackage Template
 */

 global $woo_options;

 /* The Settings */
 $token = 'specific_entries';
 $settings = array(
 				$token . '_title' => '', 
 				$token . '_limit' => 6, 
 				$token . '_featured' => 2, 
 				$token . '_image_width' => 365, 
 				$token . '_image_height' => 270, 
 				$token . '_thumb_width' => 130, 
 				$token . '_thumb_height' => 80, 
 				$token . '_button_title' => '', 
 				$token . '_button_page_id' => '', 
 				$token . '_category' => '', 
 				$token . '_tag' => ''
 				);

 $settings = woo_get_dynamic_values( $settings );

 /* woo_image Arguments */
 $image_args = array( 'width' => intval( $settings[$token . '_image_width'] ), 'height' => intval( $settings[$token . '_image_height'] ), 'class' => 'thumbnail aligncenter' );
 $thumb_args = array( 'width' => intval( $settings[$token . '_thumb_width'] ), 'height' => intval( $settings[$token . '_thumb_height'] ), 'class' => 'thumbnail aligncenter' );

 /* The Query */
 $args = array(
 				'post_type' => array( 'post' ), 
 				'post_status' => 'publish', 
 				'suppress_filters' => 0, 
 				'posts_per_page' => intval( $settings[$token . '_limit'] )
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

 $query = new WP_Query( $args );

 if ( $query->have_posts() ) {
 	$date_format = get_option( 'date_format' );
 	$type = 'featured';
?>
<section id="news-in-pictures" class="col-full">
	<?php if ( $settings[$token . '_title'] != '' ) { ?><h3 class="section-title"><?php echo $settings[$token . '_title']; ?></h3><?php } ?>
		<ul class="section-body primary">  	
<?php
	while ( $query->have_posts() ) { $query->the_post();
	if ( ( $query->current_post ) == $settings[$token . '_featured'] ) {
		$type = 'small';
?>		
		</ul>
		<!-- Thumbnails -->
		<ul class="section-body secondary">
		<ul class="lc fl">
<?php
	}
	if ( $type == 'featured' ) {
?>			
	<li <?php post_class(); ?>>
	<a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>" title="<?php the_title_attribute(); ?>"><?php woo_image( $image_args ); ?></a>
	<?php the_excerpt(); ?>
	<aside class="post-meta">
		<ul>
			<li class="post-date"><span><?php echo get_the_date( $date_format ); ?></span></li>
		</ul>
	</aside>
	</li>
<?php
	} else {
?>	
	<li <?php post_class(); ?>>
	<a href="<?php echo esc_url( get_permalink( get_the_ID() ) ); ?>" title="<?php the_title_attribute(); ?>"><?php woo_image( $thumb_args ); ?></a>				
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
  // Display "All Photos" button, if instructed.
	if ( $settings[$token . '_button_title'] != '' && intval( $settings[$token . '_button_page_id'] ) != 0 ) {
		echo '<li class="chevron post fr"><div class="arrow"><div></div></div><a href="' . esc_url( get_permalink( intval( $settings[$token . '_button_page_id'] ) ) ) . '" title="' . esc_attr( $settings[$token . '_button_title'] ) . '" class="button chev fr">' . $settings[$token . '_button_title'] . '</a></li>' . "\n";
	}
?>
</ul>
</section><!-- /#news-in-pictures -->
<?php
}
unset( $query ); // Remove the $query variable as no longer needed.
?>