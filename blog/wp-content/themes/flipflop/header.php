<?php
/**
 * Header Template
 *
 * Here we setup all logic and XHTML that is required for the header section of all screens.
 *
 * @package WooFramework
 * @subpackage Template
 */
 
 global $woo_options;
 
?><!DOCTYPE html>
<html <?php language_attributes(); ?>>
<head>

<meta charset="<?php bloginfo( 'charset' ); ?>" />

<title><?php woo_title(''); ?></title>
<?php woo_meta(); ?>

<?php if ( isset($woo_options['woo_alt_stylesheet']) && ( $woo_options['woo_alt_stylesheet'] == 'default.css' || $woo_options['woo_alt_stylesheet'] == '' ) ) { ?><link rel="stylesheet" type="text/css" href="<?php bloginfo( 'stylesheet_url' ); ?>" media="screen" /><?php } ?>
<link rel="pingback" href="<?php bloginfo( 'pingback_url' ); ?>" />
<meta content="initial-scale=1.0; maximum-scale=1.0; user-scalable=no" name="viewport"/>
<?php
	wp_head();
	woo_head();
?>
<script src="http://brodies.com/blog/js/respond.src.js"></script>

</head>

<body <?php body_class(); ?>>
<?php woo_top(); ?>
<div id="wrapper">
	<div id="header-wrap" class="parent">
	
	<?php if ( function_exists( 'has_nav_menu' ) && has_nav_menu( 'top-menu' ) ) { ?>

	<div id="top">
		<nav class="col-full" role="navigation">
			<?php wp_nav_menu( array( 'depth' => 6, 'sort_column' => 'menu_order', 'container' => 'ul', 'menu_id' => 'top-nav', 'menu_class' => 'nav fl', 'theme_location' => 'top-menu' ) ); ?>
		</nav>
	</div><!-- /#top -->

    <?php } ?>
    
    <?php woo_header_before(); ?>
		
		<header id="header" class="col-full parent">
        <div id="main-site-link"><a href="http://www.brodies.com/" target="_blank"><img src="http://brodies.com/blog/wp-content/themes/flipflop/images/brodies_main_site_btn.png"/></a></div>
        <object class="svg-logo" data="http://brodies.com/blog/images/blog-logo-3.svg" type="image/svg+xml"></object>
		<img src="http://brodies.com/blog/wp-content/themes/flipflop/images/Brodies_Lock_Up_no_line.png" class="ie-logo"/>
		<?php /*?><?php
		    $logo = get_template_directory_uri() . '/images/logo.png';
		    if ( isset( $woo_options['woo_logo'] ) && $woo_options['woo_logo'] != '' ) { $logo = $woo_options['woo_logo']; }
		?>
		<?php if ( ! isset( $woo_options['woo_texttitle'] ) || $woo_options['woo_texttitle'] != 'true' ) { ?>
		    <a id="logo" href="<?php bloginfo( 'url' ); ?>" title="<?php bloginfo( 'description' ); ?>">
		    	<img src="<?php echo $logo; ?>" alt="<?php bloginfo( 'name' ); ?>" />
		    </a>
	    <?php } ?><?php */?>
	    
	    <hgroup>
	        
			<h1 class="site-title"><a href="<?php bloginfo( 'url' ); ?>"><?php bloginfo( 'name' ); ?></a></h1>
			<h2 class="site-description"><?php bloginfo( 'description' ); ?></h2>
		      	
		</hgroup>

		<?php if ( isset( $woo_options['woo_ad_top'] ) && $woo_options['woo_ad_top'] == 'true' ) { ?>
        <div id="topad">
			<?php
				if ( isset( $woo_options['woo_ad_top_adsense'] ) && $woo_options['woo_ad_top_adsense'] != '' ) {
					echo stripslashes( $woo_options['woo_ad_top_adsense'] );
				} else {
					if ( isset( $woo_options['woo_ad_top_url'] ) && isset( $woo_options['woo_ad_top_image'] ) )
			?>
				<a href="<?php echo $woo_options['woo_ad_top_url']; ?>"><img src="<?php echo $woo_options['woo_ad_top_image']; ?>" width="468" height="60" alt="advert" /></a>
			<?php } ?>
		</div><!-- /#topad -->
        <?php } ?>
        
			<?php if ( isset( $woo_options['woo_header_navigation'] ) && $woo_options['woo_header_navigation'] == 'true' ) { ?>
			<h3 class="nav-toggle"><a href="#navigation"><?php _e('✚ Menu', 'woothemes'); ?></a></h3>
			<?php } ?>
        
        <div class="floater">
        
        <?php if ( isset( $woo_options['woo_header_search'] ) && $woo_options['woo_header_search'] == 'true' ) { ?>
		<div class="search_main">
		    <form method="get" class="searchform" action="<?php echo home_url( '/' ); ?>" >
		        <input type="text" class="field s" name="s" value="<?php esc_attr_e( '', 'woothemes' ); ?>" onfocus="if ( this.value == '<?php esc_attr_e( 'Search…', 'woothemes' ); ?>' ) { this.value = ''; }" onblur="if ( this.value == '' ) { this.value = '<?php esc_attr_e( 'Search…', 'woothemes' ); ?>'; }" />
		        <input type="image" src="<?php echo get_template_directory_uri(); ?>/images/ico-search.png" class="search-submit" name="submit" alt="Submit" />
		    </form>    
		</div><!--/.search_main-->
		<?php } ?>
        
        <?php woo_nav_before(); ?>
        
		<?php if ( isset( $woo_options['woo_header_navigation'] ) && $woo_options['woo_header_navigation'] == 'true' ) { ?>
		<nav id="navigation" class="fix" role="navigation">
			
			<?php
			if ( function_exists( 'has_nav_menu' ) && has_nav_menu( 'primary-menu' ) ) {
				wp_nav_menu( array( 'depth' => 6, 'sort_column' => 'menu_order', 'container' => 'ul', 'menu_id' => 'main-nav', 'menu_class' => 'nav fl', 'theme_location' => 'primary-menu' ) );
			} else {
			?>
	        <ul id="main-nav" class="nav fl">
				<?php if ( is_page() ) $highlight = 'page_item'; else $highlight = 'page_item current_page_item'; ?>
				<li class="<?php echo $highlight; ?>"><a href="<?php echo home_url( '/' ); ?>"><?php _e( 'Home', 'woothemes' ); ?></a></li>
				<?php wp_list_pages( 'sort_column=menu_order&depth=6&title_li=&exclude=' ); ?>
			</ul><!-- /#nav -->
	        <?php } ?>
	        <ul class="nav rss fr">
	            <?php
	            	$email = '';
	            	$rss = get_bloginfo_rss( 'rss2_url' );
	            	
	            	if ( isset( $woo_options['woo_subscribe_email'] ) && ( $woo_options['woo_subscribe_email'] != '' ) ) {
	            		$email = $woo_options['woo_subscribe_email'];
	            	}
	            	
	            	if ( isset( $woo_options['woo_feed_url'] ) && ( $woo_options['woo_feed_url'] != '' ) ) {
	            		$rss = $woo_options['woo_feed_url'];
	            	}
	            	
	            	if ( $email != '' ) {
	            ?>
	            <li class="sub-email"><a href="<?php echo esc_url( $email ); ?>" target="_blank"><?php _e( 'Email', 'woothemes' ); ?></a> |</li>
	            <?php } ?>
	            <li class="sub-rss"><a href="<?php echo $rss; ?>"><?php _e( 'RSS', 'woothemes' ); ?></a></li>
	        </ul>
	
		</nav><!-- /#navigation -->
		<?php } ?>
		
		<?php woo_nav_after(); ?>
				
		</div><!-- /.fr -->
		
		</header><!-- /#header -->
				
	</div><!-- /#header-wrap -->
	
	<div id="categoryWrap">
		<div id="categoryInner" class="col-full parent">
			<h2 id="catH2">Blog Categories</h2>
			<div id="catList">
			<a href="<?php echo home_url(); ?>/category/bclaims">Bclaims</a>
			<a href="<?php echo home_url(); ?>/category/corporate">Corporate</a>
			<a href="<?php echo home_url(); ?>/category/employment">Employment</a>
			<a href="<?php echo home_url(); ?>/category/family-law">Family Law</a>
			<a href="<?php echo home_url(); ?>/category/health-and-safety">Health & Safety</a>
			<a href="<?php echo home_url(); ?>/category/planning">Planning</a>
			<a href="<?php echo home_url(); ?>/category/public-law">Public Law</a>
			<a href="<?php echo home_url(); ?>/category/renewables">Renewables</a>
			<a href="<?php echo home_url(); ?>/category/technology">Technology</a>
			<a href="<?php echo home_url(); ?>/category/btrainees">BTrainees</a>
			<!-- <a href="<?php echo home_url(); ?>/category/scottish-tax">Scottish Tax</a> -->
			</div>
			<div class="catListBack">
    		<a href="<?php echo home_url(); ?>/category/bclaims" class="claims">< Back</a>
			<a href="<?php echo home_url(); ?>/category/corporate" class="corporate">< Back</a>
			<a href="<?php echo home_url(); ?>/category/employment" class="employment">< Back</a>
			<a href="<?php echo home_url(); ?>/category/family-law" class="family">< Back</a>
			<a href="<?php echo home_url(); ?>/category/health-and-safety" class="health">< Back</a>
			<a href="<?php echo home_url(); ?>/category/planning" class="planning">< Back</a>
			<a href="<?php echo home_url(); ?>/category/public-law" class="public-law">< Back</a>
			<a href="<?php echo home_url(); ?>/category/renewables" class="renew">< Back</a>
			<a href="<?php echo home_url(); ?>/category/technology" class="tech">< Back</a>
			<a href="<?php echo home_url(); ?>/category/scottish-tax" class="scotlaw">< Back</a>
            <a href="<?php echo home_url(); ?>/" class="home">< Back</a>
            </div>
			<div id="socLinks">
				        	<?php if ( is_active_sidebar( 'headersocial' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'headersocial' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>  
			</div>
			
		</div>
		
	</div>
			
	<?php woo_content_before(); ?>