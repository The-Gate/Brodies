<?php
if ( ! is_admin() ) { add_action( 'wp_enqueue_scripts', 'woothemes_add_javascript' ); }

if ( ! function_exists( 'woothemes_add_javascript' ) ) {
	function woothemes_add_javascript() {
		global $woo_options;
		
		wp_register_script( 'prettyPhoto', get_template_directory_uri() . '/includes/js/jquery.prettyPhoto.js', array( 'jquery' ) );
		wp_register_script( 'enable-lightbox', get_template_directory_uri() . '/includes/js/enable-lightbox.js', array( 'jquery', 'prettyPhoto' ) );

		wp_register_script( 'flexslider', get_template_directory_uri() . '/includes/js/jquery.flexslider-min.js', array( 'jquery' ) );

		wp_register_script( 'third-party', get_template_directory_uri() . '/includes/js/third-party.js', array( 'jquery' ) );
		wp_register_script( 'general', get_template_directory_uri() . '/includes/js/general.js', array( 'jquery' ) );
		
		wp_register_script( 'columnizer', get_template_directory_uri() . '/includes/js/jquery.columnizer.min.js', array( 'jquery' ) );
		
		if ( ( is_home() || is_front_page() ) && isset( $woo_options['woo_featured'] ) && ( $woo_options['woo_featured'] == 'true' ) ) {
			wp_enqueue_script( 'flexslider' );
		}

		wp_enqueue_script( 'third-party' );
		wp_enqueue_script( 'general' );
		
		/*wp_enqueue_script( 'columnizer' ); */
		

		do_action( 'woothemes_add_javascript' );
	} // End woothemes_add_javascript()
}

if ( ! is_admin() ) { add_action( 'wp_print_styles', 'woothemes_add_css' ); }

if ( ! function_exists( 'woothemes_add_css' ) ) {
	function woothemes_add_css () {
		wp_register_style( 'prettyPhoto', get_template_directory_uri() . '/includes/css/prettyPhoto.css' );
	
		do_action( 'woothemes_add_css' );
	} // End woothemes_add_css()
}

//Add an HTML5 Shim
add_action( 'wp_head', 'html5_shim' );

if ( ! function_exists( 'html5_shim' ) ) {
	function html5_shim() {
		?>
		<!--[if lt IE 9]>
			<script src="https://html5shim.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		<?php
	} // End html5_shim()
}
?>