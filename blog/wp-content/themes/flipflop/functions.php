<?php

/*-----------------------------------------------------------------------------------*/
/* Start WooThemes Functions - Please refrain from editing this section */
/*-----------------------------------------------------------------------------------*/

// Define the theme-specific key to be sent to PressTrends.
define( 'WOO_PRESSTRENDS_THEMEKEY', 'uuuc9a7z1gttqfhp4e6g8jhz9f9iutkhd' );

// WooFramework init
require_once ( get_template_directory() . '/functions/admin-init.php' );	

/*-----------------------------------------------------------------------------------*/
/* Load the theme-specific files, with support for overriding via a child theme.
/*-----------------------------------------------------------------------------------*/

$includes = array(
				'includes/theme-options.php', 			// Options panel settings and custom settings
				'includes/theme-functions.php', 		// Custom theme functions
				'includes/theme-actions.php', 			// Theme actions & user defined hooks
				'includes/theme-comments.php', 			// Custom comments/pingback loop
				'includes/theme-js.php', 				// Load JavaScript via wp_enqueue_script
				'includes/sidebar-init.php', 			// Initialize widgetized areas
				'includes/theme-widgets.php'			// Theme widgets
				);

// Allow child themes/plugins to add widgets to be loaded.
$includes = apply_filters( 'woo_includes', $includes );
				
foreach ( $includes as $i ) {
	locate_template( $i, true );
}

/*-----------------------------------------------------------------------------------*/
/* You can add custom functions below */
/*-----------------------------------------------------------------------------------*/



// remove excerpt [.. ] 

function new_excerpt_more( $more ) {
	return '...';
}
add_filter('excerpt_more', 'new_excerpt_more');

// Sidebars & Widgetizes Areas
if (function_exists('register_sidebar')) {
    register_sidebar(array(
    	'id' => 'homerecenttech',
    	'name' => 'home Recent Tech',
    	'description' => 'Recent tech posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentemployment',
    	'name' => 'home Recent Employment',
    	'description' => 'Recent Employment posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentbclaims',
    	'name' => 'home Recent Bclaims',
    	'description' => 'Recent Bclaims posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecenthealth',
    	'name' => 'home Recent Health',
    	'description' => 'Recent health&safety posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentplanning',
    	'name' => 'home Recent Planning',
    	'description' => 'Recent planning posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentrenewables',
    	'name' => 'home Recent Renewables',
    	'description' => 'Recent renewables posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentpublic',
    	'name' => 'home Recent Public Law',
    	'description' => 'Recent public law posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentcorporate',
    	'name' => 'home Recent Corporate',
    	'description' => 'Recent Corporate posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
	register_sidebar(array(
    	'id' => 'homerecentfamily',
    	'name' => 'home Recent Family',
    	'description' => 'Recent Family posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	register_sidebar(array(
    	'id' => 'homerecentbtrainees',
    	'name' => 'home Recent BTrainees',
    	'description' => 'Recent BTrainees posts on homepage',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	register_sidebar(array(
    	'id' => 'headersocial',
    	'name' => 'Header Social Links',
    	'description' => 'Widget area for social links',
    	'before_widget' => '<div id="%1$s" class="widget %2$s">',
    	'after_widget' => '</div>',
    	'before_title' => '<h3 class="widgettitle">',
    	'after_title' => '</h3>',
    ));
	
/*end of widgets - dont remove the below bracket! */	
}

add_filter('upload_mimes', 'custom_upload_mimes');

function custom_upload_mimes ( $existing_mimes=array() ) {

	// add the file extension to the array

	$existing_mimes['svg'] = 'mime/type';

        // call the modified list of extensions

	return $existing_mimes;

}


/**
  * Add HTML to Login page
*/
function junk_email_warning() {
     
	 echo '<p>A password will be emailled to you.</p><p>Please check your junk folder for this email.</p>';
	 
}
add_action( 'register_form', 'junk_email_warning');






/*-----------------------------------------------------------------------------------*/
/* Don't add any code below here or the sky will fall down */
/*-----------------------------------------------------------------------------------*/
?>