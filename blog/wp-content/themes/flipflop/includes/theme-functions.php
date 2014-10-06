<?php

/*-----------------------------------------------------------------------------------

TABLE OF CONTENTS

- Add a class to the "body" tag if displaying post meta below the title.
- Wrap the comment form in a DIV with ID "form-box".
- Exclude categories from displaying on the "Blog" page template.
- Exclude categories from displaying on the homepage.
- Register WP Menus
- Breadcrumb display
- Page navigation
- Post Meta
- Subscribe & Connect
- Comment Form Fields
- Comment Form Settings
- Archive Description
- WooPagination markup
- Google maps (for contact template)
- WooCommerce compatiblity
- Load the Column Generator
- Use single-columns.php if a non-standard column layout option is selected

-----------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------*/
/* Add a class to the "body" tag if displaying post meta below the title. */
/*-----------------------------------------------------------------------------------*/

add_filter( 'body_class', 'woo_add_postmeta_body_class' );

if ( ! function_exists( 'woo_add_postmeta_body_class' ) ) {
function woo_add_postmeta_body_class ( $classes ) {
	$settings = array( 'postmeta_below_title' => 'false' );

 	$settings = woo_get_dynamic_values( $settings );

 	if ( $settings['postmeta_below_title'] == 'true' ) {
 		$classes[] = 'meta-below-title';
 	}
	return $classes;
} // End woo_add_postmeta_body_class()
}

/*-----------------------------------------------------------------------------------*/
/* Wrap the comment form in a DIV with ID "form-box". */
/*-----------------------------------------------------------------------------------*/

add_action( 'comment_form_top', 'woo_comment_form_top' );
function woo_comment_form_top () {
	echo '<div id="form-box">' . "\n";
} // End woo_comment_form_top()

add_action( 'comment_form', 'woo_comment_form_bottom' );
function woo_comment_form_bottom () {
	echo '</div><!--/#form-box-->' . "\n";
} // End woo_comment_form_bottom()

/*-----------------------------------------------------------------------------------*/
/* Exclude categories from displaying on the "Blog" page template.
/*-----------------------------------------------------------------------------------*/

// Exclude categories on the "Blog" page template.
add_filter( 'woo_blog_template_query_args', 'woo_exclude_categories_blogtemplate' );

function woo_exclude_categories_blogtemplate ( $args ) {

	if ( ! function_exists( 'woo_prepare_category_ids_from_option' ) ) { return $args; }

	$excluded_cats = array();

	// Process the category data and convert all categories to IDs.
	$excluded_cats = woo_prepare_category_ids_from_option( 'woo_exclude_cats_blog' );

	// Homepage logic.
	if ( count( $excluded_cats ) > 0 ) {

		// Setup the categories as a string, because "category__not_in" doesn't seem to work
		// when using query_posts().

		foreach ( $excluded_cats as $k => $v ) { $excluded_cats[$k] = '-' . $v; }
		$cats = join( ',', $excluded_cats );

		$args['cat'] = $cats;
	}

	return $args;

} // End woo_exclude_categories_blogtemplate()

/*-----------------------------------------------------------------------------------*/
/* Exclude categories from displaying on the homepage.
/*-----------------------------------------------------------------------------------*/

// Exclude categories on the homepage.
add_filter( 'pre_get_posts', 'woo_exclude_categories_homepage' );

function woo_exclude_categories_homepage ( $query ) {

	if ( ! function_exists( 'woo_prepare_category_ids_from_option' ) ) { return $query; }

	$excluded_cats = array();

	// Process the category data and convert all categories to IDs.
	$excluded_cats = woo_prepare_category_ids_from_option( 'woo_exclude_cats_home' );

	// Homepage logic.
	if ( is_home() && ( count( $excluded_cats ) > 0 ) ) {
		$query->set( 'category__not_in', $excluded_cats );
	}

	$query->parse_query();

	return $query;

} // End woo_exclude_categories_homepage()

/*-----------------------------------------------------------------------------------*/
/* Register WP Menus */
/*-----------------------------------------------------------------------------------*/
if ( function_exists( 'wp_nav_menu') ) {
	add_theme_support( 'nav-menus' );
	register_nav_menus( array( 'primary-menu' => __( 'Primary Menu', 'woothemes' ) ) );
	register_nav_menus( array( 'top-menu' => __( 'Top Menu', 'woothemes' ) ) );
}

/*-----------------------------------------------------------------------------------*/
/* Breadcrumb display */
/*-----------------------------------------------------------------------------------*/

add_action('woo_main_before','woo_display_breadcrumbs',10);
if (!function_exists( 'woo_display_breadcrumbs')) {
	function woo_display_breadcrumbs() {
		global $woo_options;
		if ( isset( $woo_options['woo_breadcrumbs_show'] ) && $woo_options['woo_breadcrumbs_show'] == 'true' ) {
		echo '<section id="breadcrumbs">';
			woo_breadcrumbs();
		echo '</section><!--/#breadcrumbs -->';
		}
	} // End woo_display_breadcrumbs()
} // End IF Statement


/*-----------------------------------------------------------------------------------*/
/* Page navigation */
/*-----------------------------------------------------------------------------------*/
if (!function_exists( 'woo_pagenav')) {
	function woo_pagenav() {

		global $woo_options;

		// If the user has set the option to use simple paging links, display those. By default, display the pagination.
		if ( array_key_exists( 'woo_pagination_type', $woo_options ) && $woo_options[ 'woo_pagination_type' ] == 'simple' ) {
			if ( get_next_posts_link() || get_previous_posts_link() ) {
		?>
            <nav class="nav-entries fix">
                <?php next_posts_link( '<span class="nav-prev fl">'. __( '<span class="meta-nav">&larr;</span> Older posts', 'woothemes' ) . '</span>' ); ?>
                <?php previous_posts_link( '<span class="nav-next fr">'. __( 'Newer posts <span class="meta-nav">&rarr;</span>', 'woothemes' ) . '</span>' ); ?>
            </nav>
		<?php
			}
		} else {
			woo_pagination();

		} // End IF Statement

	} // End woo_pagenav()
} // End IF Statement


/*-----------------------------------------------------------------------------------*/
/* Post Meta */
/*-----------------------------------------------------------------------------------*/

if (!function_exists( 'woo_post_meta')) {
	function woo_post_meta() {
?>
<aside class="post-meta">
	<ul>
		<li class="post-date border">
			<span><?php the_time( get_option( 'date_format' ) ); ?></span>
		</li>
		<?php the_tags( '<li class="post-tag">', ', ', '</li>' ); ?>
		<li class="post-comments">
			<?php comments_popup_link( __( 'Comment', 'woothemes' ), __( '1 Comment', 'woothemes' ), __( '% Comments', 'woothemes' ) ); ?>
		</li>
		<?php edit_post_link( __( '{ Edit }', 'woothemes' ), '<li class="edit">', '</li>' ); ?>
	</ul>
</aside>
<?php
	}
}


/*-----------------------------------------------------------------------------------*/
/* Subscribe / Connect */
/*-----------------------------------------------------------------------------------*/

if (!function_exists( 'woo_subscribe_connect')) {
	function woo_subscribe_connect($widget = 'false', $title = '', $form = '', $social = '', $contact_template = 'false') {

		//Setup default variables, overriding them if the "Theme Options" have been saved.
		$settings = array(
						'connect' => 'false', 
						'connect_title' => __('Subscribe' , 'woothemes'), 
						'connect_related' => 'true', 
						'connect_content' => __( 'Subscribe to our e-mail newsletter to receive updates.', 'woothemes' ),
						'connect_newsletter_id' => '', 
						'connect_mailchimp_list_url' => '',
						'feed_url' => '',
						'connect_rss' => '',
						'connect_twitter' => '',
						'connect_facebook' => '',
						'connect_youtube' => '',
						'connect_flickr' => '',
						'connect_linkedin' => '',
						'connect_delicious' => '',
						'connect_rss' => '',
						'connect_googleplus' => ''
						);
		$settings = woo_get_dynamic_values( $settings );

		// Setup title
		if ( $widget != 'true' )
			$title = $settings[ 'connect_title' ];

		// Setup related post (not in widget)
		$related_posts = '';
		if ( $settings[ 'connect_related' ] == "true" AND $widget != "true" )
			$related_posts = do_shortcode( '[related_posts limit="5"]' );

?>
	<?php if ( $settings[ 'connect' ] == "true" OR $widget == 'true' ) : ?>
	<aside id="connect" class="fix">
		<h3><?php if ( $title ) echo apply_filters( 'widget_title', $title ); else _e('Subscribe','woothemes'); ?></h3>

		<div <?php if ( $related_posts != '' ) echo 'class="col-left"'; ?>>
			<?php if ($settings[ 'connect_content' ] != '' AND $contact_template == 'false') echo '<p>' . stripslashes($settings[ 'connect_content' ]) . '</p>'; ?>

			<?php if ( $settings[ 'connect_newsletter_id' ] != "" AND $form != 'on' ) : ?>
			<form class="newsletter-form<?php if ( $related_posts == '' ) echo ' fl'; ?>" action="http://feedburner.google.com/fb/a/mailverify" method="post" target="popupwindow" onsubmit="window.open( 'http://feedburner.google.com/fb/a/mailverify?uri=<?php echo $settings[ 'connect_newsletter_id' ]; ?>', 'popupwindow', 'scrollbars=yes,width=550,height=520' );return true">
				<input class="email" type="text" name="email" value="<?php esc_attr_e( 'E-mail', 'woothemes' ); ?>" onfocus="if (this.value == '<?php _e( 'E-mail', 'woothemes' ); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e( 'E-mail', 'woothemes' ); ?>';}" />
				<input type="hidden" value="<?php echo $settings[ 'connect_newsletter_id' ]; ?>" name="uri"/>
				<input type="hidden" value="<?php bloginfo( 'name' ); ?>" name="title"/>
				<input type="hidden" name="loc" value="en_US"/>
				<input class="submit" type="submit" name="submit" value="<?php _e( 'Submit', 'woothemes' ); ?>" />
			</form>
			<?php endif; ?>

			<?php if ( $settings['connect_mailchimp_list_url'] != "" AND $form != 'on' AND $settings['connect_newsletter_id'] == "" ) : ?>
			<!-- Begin MailChimp Signup Form -->
			<div id="mc_embed_signup">
				<form class="newsletter-form<?php if ( $related_posts == '' ) echo ' fl'; ?>" action="<?php echo $settings['connect_mailchimp_list_url']; ?>" method="post" target="popupwindow" onsubmit="window.open('<?php echo $settings['connect_mailchimp_list_url']; ?>', 'popupwindow', 'scrollbars=yes,width=650,height=520');return true">
					<input type="text" name="EMAIL" class="required email" value="<?php _e('E-mail','woothemes'); ?>"  id="mce-EMAIL" onfocus="if (this.value == '<?php _e('E-mail','woothemes'); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e('E-mail','woothemes'); ?>';}">
					<input type="submit" value="<?php _e('Submit', 'woothemes'); ?>" name="subscribe" id="mc-embedded-subscribe" class="btn submit button">
				</form>
			</div>
			<!--End mc_embed_signup-->
			<?php endif; ?>

			<?php if ( $social != 'on' ) : ?>
			<div class="social<?php if ( $related_posts == '' AND $settings['connect_newsletter_id' ] != "" ) echo ' fr'; ?>">
		   		<?php if ( $settings['connect_rss' ] == "true" ) { ?>
		   		<a href="<?php if ( $settings['feed_url'] ) { echo esc_url( $settings['feed_url'] ); } else { echo get_bloginfo_rss('rss2_url'); } ?>" class="subscribe" title="RSS"></a>

		   		<?php } if ( $settings['connect_twitter' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_twitter'] ); ?>" class="twitter" title="Twitter"></a>

		   		<?php } if ( $settings['connect_facebook' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_facebook'] ); ?>" class="facebook" title="Facebook"></a>

		   		<?php } if ( $settings['connect_youtube' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_youtube'] ); ?>" class="youtube" title="YouTube"></a>

		   		<?php } if ( $settings['connect_flickr' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_flickr'] ); ?>" class="flickr" title="Flickr"></a>

		   		<?php } if ( $settings['connect_linkedin' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_linkedin'] ); ?>" class="linkedin" title="LinkedIn"></a>

		   		<?php } if ( $settings['connect_delicious' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_delicious'] ); ?>" class="delicious" title="Delicious"></a>

		   		<?php } if ( $settings['connect_googleplus' ] != "" ) { ?>
		   		<a href="<?php echo esc_url( $settings['connect_googleplus'] ); ?>" class="googleplus" title="Google+"></a>

				<?php } ?>
			</div>
			<?php endif; ?>

		</div><!-- col-left -->

		<?php if ( $settings['connect_related' ] == "true" AND $related_posts != '' ) : ?>
		<div class="related-posts col-right">
			<h4><?php _e( 'Related Posts:', 'woothemes' ); ?></h4>
			<?php echo $related_posts; ?>
		</div><!-- col-right -->
		<?php wp_reset_query(); endif; ?>

	</aside>
	<?php endif; ?>
<?php
	}
}

/*-----------------------------------------------------------------------------------*/
/* Comment Form Fields */
/*-----------------------------------------------------------------------------------*/

	add_filter( 'comment_form_default_fields', 'woo_comment_form_fields' );

	if ( ! function_exists( 'woo_comment_form_fields' ) ) {
		function woo_comment_form_fields ( $fields ) {

			$commenter = wp_get_current_commenter();

			$required_text = ' <span class="required">(' . __( 'Required', 'woothemes' ) . ')</span>';

			$req = get_option( 'require_name_email' );
			$aria_req = ( $req ? " aria-required='true'" : '' );
			$fields =  array(
				'author' => '<p class="comment-form-author">' .
							'<input id="author" class="txt" name="author" type="text" value="' . esc_attr( $commenter['comment_author'] ) . '" size="30"' . $aria_req . ' />' .
							'<label for="author">' . __( 'Name', 'woothemes' ) . ( $req ? $required_text : '' ) . '</label> ' .
							'</p>',
				'email'  => '<p class="comment-form-email">' .
				            '<input id="email" class="txt" name="email" type="text" value="' . esc_attr(  $commenter['comment_author_email'] ) . '" size="30"' . $aria_req . ' />' .
				            '<label for="email">' . __( 'Email', 'woothemes' ) . ( $req ? $required_text : '' ) . '</label> ' .
				            '</p>',
				'url'    => '<p class="comment-form-url">' .
				            '<input id="url" class="txt" name="url" type="text" value="' . esc_attr( $commenter['comment_author_url'] ) . '" size="30" />' .
				            '<label for="url">' . __( 'Website', 'woothemes' ) . '</label>' .
				            '</p>',
			);

			return $fields;

		} // End woo_comment_form_fields()
	}

/*-----------------------------------------------------------------------------------*/
/* Comment Form Settings */
/*-----------------------------------------------------------------------------------*/

	add_filter( 'comment_form_defaults', 'woo_comment_form_settings' );

	if ( ! function_exists( 'woo_comment_form_settings' ) ) {
		function woo_comment_form_settings ( $settings ) {

			$settings['comment_notes_before'] = '';
			$settings['comment_notes_after'] = '';
			$settings['title_reply'] = __( 'Add Comment', 'woothemes' );
			$settings['label_submit'] = __( 'Submit', 'woothemes' );
			$settings['cancel_reply_link'] = __( 'Click here to cancel reply.', 'woothemes' );

			return $settings;

		} // End woo_comment_form_settings()
	}

	/*-----------------------------------------------------------------------------------*/
	/* Misc back compat */
	/*-----------------------------------------------------------------------------------*/

	// array_fill_keys doesn't exist in PHP < 5.2
	// Can remove this after PHP <  5.2 support is dropped
	if ( !function_exists( 'array_fill_keys' ) ) {
		function array_fill_keys( $keys, $value ) {
			return array_combine( $keys, array_fill( 0, count( $keys ), $value ) );
		}
	}

/*-----------------------------------------------------------------------------------*/
/**
 * woo_archive_description()
 *
 * Display a description, if available, for the archive being viewed (category, tag, other taxonomy).
 *
 * @since V1.0.0
 * @uses do_atomic(), get_queried_object(), term_description()
 * @echo string
 * @filter woo_archive_description
 */

if ( ! function_exists( 'woo_archive_description' ) ) {
	function woo_archive_description ( $echo = true ) {
		do_action( 'woo_archive_description' );
		
		// Archive Description, if one is available.
		$term_obj = get_queried_object();
		$description = term_description( $term_obj->term_id, $term_obj->taxonomy );
		
		if ( $description != '' ) {
			// Allow child themes/plugins to filter here ( 1: text in DIV and paragraph, 2: term object )
			$description = apply_filters( 'woo_archive_description', '<div class="archive-description">' . $description . '</div><!--/.archive-description-->', $term_obj );
		}
		
		if ( $echo != true ) { return $description; }
		
		echo $description;
	} // End woo_archive_description()
}

/*-----------------------------------------------------------------------------------*/
/* WooPagination Markup */
/*-----------------------------------------------------------------------------------*/

add_filter( 'woo_pagination_args', 'woo_pagination_html5_markup', 2 );

function woo_pagination_html5_markup ( $args ) {
	$args['before'] = '<nav class="pagination woo-pagination">';
	$args['after'] = '</nav>';
	
	return $args;
} // End woo_pagination_html5_markup()


/*-----------------------------------------------------------------------------------*/
/* Google Maps */
/*-----------------------------------------------------------------------------------*/

function woo_maps_contact_output($args){

	$key = get_option('woo_maps_apikey');
	
	// No More API Key needed
	
	if ( !is_array($args) ) 
		parse_str( $args, $args );
		
	extract($args);	
		
	$map_height = get_option('woo_maps_single_height');
	$featured_w = get_option('woo_home_featured_w');
	$featured_h = get_option('woo_home_featured_h');
	$zoom = get_option('woo_maps_default_mapzoom');
	if ( $zoom == '' ) { $zoom = 6; }   
	$lang = get_option('woo_maps_directions_locale');
	$locale = '';
	if(!empty($lang)){
		$locale = ',locale :"'.$lang.'"';
	}
	$extra_params = ',{travelMode:G_TRAVEL_MODE_WALKING,avoidHighways:true '.$locale.'}';
	
	if(empty($map_height)) { $map_height = 250;}
	
	if(is_home() && !empty($featured_h) && !empty($featured_w)){
	?>
    <div id="single_map_canvas" style="width:<?php echo $featured_w; ?>px; height: <?php echo $featured_h; ?>px"></div>
    <?php } else { ?> 
    <div id="single_map_canvas" style="width:100%; height: <?php echo $map_height; ?>px"></div>
    <?php } ?>
    <script src="<?php bloginfo('template_url'); ?>/includes/js/markers.js" type="text/javascript"></script>
    <script type="text/javascript">
		jQuery(document).ready(function(){
			function initialize() {
				
				
			<?php if($streetview == 'on'){ ?>

				
			<?php } else { ?>
				
			  	<?php switch ($type) {
			  			case 'G_NORMAL_MAP':
			  				$type = 'ROADMAP';
			  				break;
			  			case 'G_SATELLITE_MAP':
			  				$type = 'SATELLITE';
			  				break;
			  			case 'G_HYBRID_MAP':
			  				$type = 'HYBRID';
			  				break;
			  			case 'G_PHYSICAL_MAP':
			  				$type = 'TERRAIN';
			  				break;
			  			default:
			  				$type = 'ROADMAP';
			  				break;
			  	} ?>
			  	
			  	var myLatlng = new google.maps.LatLng(<?php echo $geocoords; ?>);
				var myOptions = {
				  zoom: <?php echo $zoom; ?>,
				  center: myLatlng,
				  mapTypeId: google.maps.MapTypeId.<?php echo $type; ?>
				};
			  	var map = new google.maps.Map(document.getElementById("single_map_canvas"),  myOptions);
				<?php if(get_option('woo_maps_scroll') == 'true'){ ?>
			  	map.scrollwheel = false;
			  	<?php } ?>
			  	
				<?php if($mode == 'directions'){ ?>
			  	directionsPanel = document.getElementById("featured-route");
 				directions = new GDirections(map, directionsPanel);
  				directions.load("from: <?php echo $from; ?> to: <?php echo $to; ?>" <?php if($walking == 'on'){ echo $extra_params;} ?>);
			  	<?php
			 	} else { ?>
			 
			  		var point = new google.maps.LatLng(<?php echo $geocoords; ?>);
	  				var root = "<?php bloginfo('template_url'); ?>";
	  				var the_link = '<?php echo get_permalink(get_the_id()); ?>';
	  				<?php $title = str_replace(array('&#8220;','&#8221;'),'"',get_the_title(get_the_id())); ?>
	  				<?php $title = str_replace('&#8211;','-',$title); ?>
	  				<?php $title = str_replace('&#8217;',"`",$title); ?>
	  				<?php $title = str_replace('&#038;','&',$title); ?>
	  				var the_title = '<?php echo html_entity_decode($title) ?>'; 
	  				
	  			<?php		 	
			 	if(is_page()){ 
			 		$custom = get_option('woo_cat_custom_marker_pages');
					if(!empty($custom)){
						$color = $custom;
					}
					else {
						$color = get_option('woo_cat_colors_pages');
						if (empty($color)) {
							$color = 'red';
						}
					}			 	
			 	?>
			 		var color = '<?php echo $color; ?>';
			 		createMarker(map,point,root,the_link,the_title,color);
			 	<?php } else { ?>
			 		var color = '<?php echo get_option('woo_cat_colors_pages'); ?>';
	  				createMarker(map,point,root,the_link,the_title,color);
				<?php 
				}
					if(isset($_POST['woo_maps_directions_search'])){ ?>
					
					directionsPanel = document.getElementById("featured-route");
 					directions = new GDirections(map, directionsPanel);
  					directions.load("from: <?php echo htmlspecialchars($_POST['woo_maps_directions_search']); ?> to: <?php echo $address; ?>" <?php if($walking == 'on'){ echo $extra_params;} ?>);
  					
  					
  					
					directionsDisplay = new google.maps.DirectionsRenderer();
					directionsDisplay.setMap(map);
    				directionsDisplay.setPanel(document.getElementById("featured-route"));
					
					<?php if($walking == 'on'){ ?>
					var travelmodesetting = google.maps.DirectionsTravelMode.WALKING;
					<?php } else { ?>
					var travelmodesetting = google.maps.DirectionsTravelMode.DRIVING;
					<?php } ?>
					var start = '<?php echo htmlspecialchars($_POST['woo_maps_directions_search']); ?>';
					var end = '<?php echo $address; ?>';
					var request = {
       					origin:start, 
        				destination:end,
        				travelMode: travelmodesetting
    				};
    				directionsService.route(request, function(response, status) {
      					if (status == google.maps.DirectionsStatus.OK) {
        					directionsDisplay.setDirections(response);
      					}
      				});	
      				
  					<?php } ?>			
				<?php } ?>
			<?php } ?>
			

			  }
			  function handleNoFlash(errorCode) {
				  if (errorCode == FLASH_UNAVAILABLE) {
					alert("Error: Flash doesn't appear to be supported by your browser");
					return;
				  }
				 }

			
		
		initialize();
			
		});
	jQuery(window).load(function(){
			
		var newHeight = jQuery('#featured-content').height();
		newHeight = newHeight - 5;
		if(newHeight > 300){
			jQuery('#single_map_canvas').height(newHeight);
		}
		
	});

	</script>

<?php
}


/*-----------------------------------------------------------------------------------*/
/* WooCommerce compatibility */
/*-----------------------------------------------------------------------------------*/

if ( class_exists('woocommerce') ) {

	// Remove existing WC wrappers
	remove_action( 'woocommerce_before_main_content', 'woocommerce_output_content_wrapper', 10);
	remove_action( 'woocommerce_after_main_content', 'woocommerce_output_content_wrapper_end', 10);
	remove_action( 'woocommerce_sidebar', 'woocommerce_get_sidebar', 10);
	
	// Add content container
	add_action('woocommerce_before_main_content', create_function('', 'echo "<div id=\"content\" class=\"page col-full\">";'), 10);
	
	// Add main section 
	add_action('woocommerce_before_main_content', create_function('', 'echo "<section id=\"main\" class=\"col-left\">";'), 10);
	add_action('woocommerce_after_main_content', create_function('', 'echo "</section>";'), 10);
	
	// Add sidebar 
	add_action( 'woocommerce_after_main_content', 'woocommerce_get_sidebar', 10);
	
	// Add closing content container
	add_action('woocommerce_after_main_content', create_function('', 'echo "</div>";'), 10);

}

/*-----------------------------------------------------------------------------------*/
/* Load the Column Generator */
/*-----------------------------------------------------------------------------------*/

if ( true == apply_filters( 'woo_column_generator_load', true ) ) {
	locate_template( 'includes/woo-column-generator/woo-column-generator.php', true, true );
	if ( class_exists( 'WooThemes_Column_Generator' ) ) {
		global $woothemes_column_generator;
		$woothemes_column_generator = new WooThemes_Column_Generator();

		// Make sure to load the appropriate columns template, if required.
		add_action( 'template_redirect', 'woo_columns_template_redirect' );
	}
}

/*-----------------------------------------------------------------------------------*/
/* Use single-columns.php if a non-standard column layout option is selected */
/*-----------------------------------------------------------------------------------*/

function woo_columns_template_redirect () {
	
	global $post;
	
	if ( ! is_home() && is_singular() && isset( $post->ID ) ) {
	
		$layout = 'layout-std';
		
		$custom_meta = get_post_custom( $post->ID );

		if ( array_key_exists( '_column_layout', (array) $custom_meta ) ) {
			$layout = $custom_meta['_column_layout'][0];
		}
		
		if ( $layout != 'layout-std' && $layout != '' ) {
			locate_template( array( 'single-columns.php', 'single.php', 'index.php' ), true );
			
			exit;
		}
	
	}
	
} // End woo_columns_template_redirect()

/*-----------------------------------------------------------------------------------*/
/* END */
/*-----------------------------------------------------------------------------------*/
?>