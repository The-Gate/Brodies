<?php
/**
 * Index Template
 *
 * Here we setup all logic and XHTML that is required for the index template, used as both the homepage
 * and as a fallback template, if a more appropriate template file doesn't exist for a specific context.
 *
 * @package WooFramework
 * @subpackage Template
 */
	get_header();
	global $woo_options;

	$settings = array(
 				'featured' => 'true', 
 				'recent_entries_enable' => 'true', 
 				'specific_entries_enable' => 'true', 
 				'categories_grid_enable' => 'true'
 				);

 $settings = woo_get_dynamic_values( $settings );
?>
    <div id="content">
    <div class="col-full">
    
    	<?php woo_main_before(); ?>
		<section id="main" class="fullwidth">     
		<?php
			if ( ! dynamic_sidebar( 'homepage' ) ) {
				/* Featured Slider */
				if ( ( is_home() || is_front_page() ) && $settings['featured'] == 'true' ) { get_template_part ( 'includes/featured' ); }
				/* Recent Entries */
				if ( $settings['recent_entries_enable'] == 'true' ) { get_template_part( 'includes/recent-entries' ); }

				/* Specific Entries */
				if ( $settings['specific_entries_enable'] == 'true' ) { get_template_part( 'includes/specific-entries' ); }

				/* Categories Grid */
				if ( $settings['categories_grid_enable'] == 'true' ) { get_template_part( 'includes/categories-grid' ); }
			}
		?>
		</section><!-- /#main -->
		<?php woo_main_after(); ?>
		
	</div><!-- /.col-full -->
    </div><!-- /#content -->		
    
<?php get_footer(); ?>