<?php
if (!function_exists( 'woo_options')) {
function woo_options() {

// THEME VARIABLES
$themename = "FlipFlop";
$themeslug = "flipflop";

// STANDARD VARIABLES. DO NOT TOUCH!
$shortname = "woo";
$manualurl = 'http://www.woothemes.com/support/theme-documentation/'.$themeslug.'/';

//Access the WordPress Categories via an Array
$woo_categories = array();
$woo_categories_obj = get_categories( 'hide_empty=0' );
foreach ($woo_categories_obj as $woo_cat) {
    $woo_categories[$woo_cat->cat_ID] = $woo_cat->cat_name;}
$categories_tmp = array_unshift($woo_categories, "Select a category:" );

//Access the WordPress Pages via an Array
$woo_pages = array();
$woo_pages_obj = get_pages( 'sort_column=post_parent,menu_order' );
foreach ($woo_pages_obj as $woo_page) {
    $woo_pages[$woo_page->ID] = $woo_page->post_name; }
$woo_pages_tmp = array_unshift($woo_pages, "Select a page:" );

//Stylesheets Reader
$alt_stylesheet_path = get_template_directory() . '/styles/';
$alt_stylesheets = array();
if ( is_dir($alt_stylesheet_path) ) {
    if ($alt_stylesheet_dir = opendir($alt_stylesheet_path) ) {
        while ( ($alt_stylesheet_file = readdir($alt_stylesheet_dir)) !== false ) {
            if(stristr($alt_stylesheet_file, ".css") !== false) {
                $alt_stylesheets[] = $alt_stylesheet_file;
            }
        }
    }
}

//More Options
$other_entries = array( "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19" );

// Setup an array of categories for a dropdown.
$args = array( 'echo' => 0, 'hierarchical' => 1 );
$cats_dropdown = wp_dropdown_categories( $args );
$cats = array();

// Quick string hack to make sure we get the pages with the indents.
$cats_dropdown = str_replace( "<select name='cat' id='cat' class='postform' >", '', $cats_dropdown );
$cats_dropdown = str_replace( '</select>', '', $cats_dropdown );
$cats_split = explode( '</option>', $cats_dropdown );

$cats[] = __( 'Select a Category:', 'woothemes' );

foreach ( $cats_split as $k => $v ) {	
	$id = '';	
	// Get the ID value.
	preg_match( '/value="(.*?)"/i', $v, $matches );
	
	if ( isset( $matches[1] ) ) {	
		$id = $matches[1];
		$cats[$id] = trim( strip_tags( $v ) );
	}
}

$woo_categories = $cats;

// Setup an array of tags for a dropdown.
$args = array( 'echo' => 0, 'hierarchical' => 1, 'taxonomy' => 'post_tag' );
$tags_dropdown = wp_dropdown_categories( $args );
$tags = array();

// Quick string hack to make sure we get the tags with the indents.
$tags_dropdown = str_replace( "<select name='cat' id='cat' class='postform' >", '', $tags_dropdown );
$tags_dropdown = str_replace( '</select>', '', $tags_dropdown );
$tags_split = explode( '</option>', $tags_dropdown );

$tags[] = __( 'Select a Tag:', 'woothemes' );

foreach ( $tags_split as $k => $v ) {
	$id = '';
	// Get the ID value.
	preg_match( '/value="(.*?)"/i', $v, $matches );
	
	if ( isset( $matches[1] ) ) {
		$id = $matches[1];
		$tags[$id] = trim( strip_tags( $v ) );
	}
}

$woo_tags = $tags;

// Setup an array of pages for a dropdown.
$args = array( 'echo' => 0 );
$pages_dropdown = wp_dropdown_pages( $args );
$pages = array();

// Quick string hack to make sure we get the pages with the indents.
$pages_dropdown = str_replace( '<select name="page_id" id="page_id">', '', $pages_dropdown );
$pages_dropdown = str_replace( '</select>', '', $pages_dropdown );
$pages_split = explode( '</option>', $pages_dropdown );

$pages[] = __( 'Select a Page:', 'woothemes' );

foreach ( $pages_split as $k => $v ) {
	$id = '';
	// Get the ID value.
	preg_match( '/value="(.*?)"/i', $v, $matches );
	
	if ( isset( $matches[1] ) ) {
		$id = $matches[1];
		$pages[$id] = trim( strip_tags( $v ) );
	}
}

$woo_pages = $pages;

// Setup an array of numbers.
$woo_numbers = array();
for ( $i = 1; $i <= 20; $i++ ) {
	$woo_numbers[$i] = $i;
}

// THIS IS THE DIFFERENT FIELDS
$options = array();

// General

		$options[] = array( 'name' => __( 'General Settings', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'general' );

		$options[] = array( 'name' => __( 'Quick Start', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Theme Stylesheet', 'woothemes' ),
			'desc' => __( 'Select your themes alternative color scheme.', 'woothemes' ),
			'id' => $shortname . '_alt_stylesheet',
			'std' => 'default.css',
			'type' => 'select',
			'options' => $alt_stylesheets );

		$options[] = array( 'name' => __( 'Custom Logo', 'woothemes' ),
			'desc' => __( 'Upload a logo for your theme, or specify an image URL directly.', 'woothemes' ),
			'id' => $shortname . '_logo',
			'std' => '',
			'type' => 'upload' );

		$options[] = array( 'name' => __( 'Text Title', 'woothemes' ),
			'desc' => sprintf( __( 'Enable text-based Site Title and Tagline. Setup title & tagline in %1$s.', 'woothemes' ), '<a href="' . home_url() . '/wp-admin/options-general.php">' . __( 'General Settings', 'woothemes' ) . '</a>' ),
			'id' => $shortname . '_texttitle',
			'std' => 'false',
			'class' => 'collapsed',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Site Title', 'woothemes' ),
			'desc' => __( 'Change the site title typography.', 'woothemes' ),
			'id' => $shortname . '_font_site_title',
			'std' => array( 'size' => '36', 'unit' => 'px', 'face' => 'Droid Serif', 'style' => '', 'color' => '#333333' ),
			'class' => 'hidden',
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Site Description', 'woothemes' ),
			'desc' => __( 'Enable the site description/tagline under site title.', 'woothemes' ),
			'id' => $shortname . '_tagline',
			'class' => 'hidden',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Site Description', 'woothemes' ),
			'desc' => __( 'Change the site description typography.', 'woothemes' ),
			'id' => $shortname . '_font_tagline',
			'std' => array( 'size' => '12', 'unit' => 'px', 'face' => 'Droid Sans', 'style' => '', 'color' => '#999999' ),
			'class' => 'hidden last',
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Custom Favicon', 'woothemes' ),
			'desc' => __( 'Upload a 16px x 16px <a href="http://www.faviconr.com/">ico image</a> that will represent your website\'s favicon.', 'woothemes' ),
			'id' => $shortname . '_custom_favicon',
			'std' => '',
			'type' => 'upload' );

		$options[] = array( 'name' => __( 'Tracking Code', 'woothemes' ),
			'desc' => __( 'Paste your Google Analytics (or other) tracking code here. This will be added into the footer template of your theme.', 'woothemes' ),
			'id' => $shortname . '_google_analytics',
			'std' => '',
			'type' => 'textarea' );

		$options[] = array( 'name' => __( 'Subscription Settings', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'RSS URL', 'woothemes' ),
			'desc' => __( 'Enter your preferred RSS URL. (Feedburner or other)', 'woothemes' ),
			'id' => $shortname . '_feed_url',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'E-Mail Subscription URL', 'woothemes' ),
			'desc' => __( 'Enter your preferred E-mail subscription URL. (Feedburner or other)', 'woothemes' ),
			'id' => $shortname . '_subscribe_email',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Contact Form E-Mail', 'woothemes' ),
			'desc' => __( 'Enter your E-mail address to use on the Contact Form Page Template. Add the contact form by adding a new page and selecting "Contact Form" as page template.', 'woothemes' ),
			'id' => $shortname . '_contactform_email',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Display Options', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Custom CSS', 'woothemes' ),
			'desc' => __( 'Quickly add some CSS to your theme by adding it to this block.', 'woothemes' ),
			'id' => $shortname . '_custom_css',
			'std' => '',
			'type' => 'textarea' );

		$options[] = array( 'name' => __( 'Post/Page Comments', 'woothemes' ),
			'desc' => __( 'Select if you want to enable/disable comments on posts and/or pages.', 'woothemes' ),
			'id' => $shortname . '_comments',
			'std' => 'both',
			'type' => 'select2',
			'options' => array( "post" => __( 'Posts Only', 'woothemes' ), "page" => __( 'Pages Only', 'woothemes' ), "both" => __( 'Pages / Posts', 'woothemes' ), "none" => __( 'None', 'woothemes' ) ) );

		$options[] = array( 'name' => __( 'Post Content', 'woothemes' ),
			'desc' => __( 'Select if you want to show the full content or the excerpt on posts.', 'woothemes' ),
			'id' => $shortname . '_post_content',
			'type' => 'select2',
			'options' => array( "excerpt" => __( 'The Excerpt', 'woothemes' ), "content" => __( 'Full Content', 'woothemes' ) ) );

		$options[] = array( 'name' => __( 'Post Author Box', 'woothemes' ),
			'desc' => sprintf( __( 'This will enable the post author box on the single posts page. Edit description in %1$s.', 'woothemes' ), '<a href="' . home_url() . '/wp-admin/profile.php">' . __( 'Profile', 'woothemes' ) . '</a>' ),
			'id' => $shortname . '_post_author',
			'std' => 'true',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Display Breadcrumbs', 'woothemes' ),
			'desc' => __( 'Display dynamic breadcrumbs on each page of your website.', 'woothemes' ),
			'id' => $shortname . '_breadcrumbs_show',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Display Pagination', 'woothemes' ),
			'desc' => __( 'Display pagination on the blog.', 'woothemes' ),
			'id' => $shortname . '_pagenav_show',
			'std' => 'true',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Pagination Style', 'woothemes' ),
			'desc' => __( 'Select the style of pagination you would like to use on the blog.', 'woothemes' ),
			'id' => $shortname . '_pagination_type',
			'type' => 'select2',
			'options' => array( "paginated_links" => __( 'Numbers', 'woothemes' ), "simple" => __( 'Next/Previous', 'woothemes' ) ) );

		// Styling
		$options[] = array( 'name' => __( 'Styling', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'styling' );

		$options[] = array( 'name' => __( 'Background', 'woothemes' ),
			'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Body Background Color', 'woothemes' ),
			'desc' => __( 'Pick a custom color for background color of the theme e.g. #697e09', 'woothemes' ),
			'id' => $shortname . '_body_color',
			'std' => '',
			'type' => 'color' );

		$options[] = array( 'name' => __( 'Body background image', 'woothemes' ),
			'desc' => __( 'Upload an image for the theme\'s background', 'woothemes' ),
			'id' => $shortname . '_body_img',
			'std' => '',
			'type' => 'upload' );

		$options[] = array( 'name' => __( 'Background image repeat', 'woothemes' ),
			'desc' => __( 'Select how you would like to repeat the background-image', 'woothemes' ),
			'id' => $shortname . '_body_repeat',
			'std' => 'no-repeat',
			'type' => 'select',
			'options' => array( "no-repeat", "repeat-x", "repeat-y", "repeat" ) );

		$options[] = array( 'name' => __( 'Background image position', 'woothemes' ),
			'desc' => __( 'Select how you would like to position the background', 'woothemes' ),
			'id' => $shortname . '_body_pos',
			'std' => "top",
			'type' => 'select',
			'options' => array( "top left", "top center", "top right", "center left", "center center", "center right", "bottom left", "bottom center", "bottom right" ) );
			
		$options[] = array( 'name' => "Background Attachment",
            'desc' => "Select whether the background should be fixed or move when the user scrolls",
            'id' => $shortname."_body_attachment",
            'std' => "scroll",
            'type' => "select",
            'options' => array( "scroll","fixed"));

		$options[] = array( 'name' => __( 'Links', 'woothemes' ),
			'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Link Color', 'woothemes' ),
			'desc' => __( 'Pick a custom color for links or add a hex color code e.g. #697e09', 'woothemes' ),
			'id' => $shortname . '_link_color',
			'std' => '',
			'type' => 'color' );

		$options[] = array( 'name' =>  __( 'Link Hover Color', 'woothemes' ),
			'desc' => __( 'Pick a custom color for links hover or add a hex color code e.g. #697e09', 'woothemes' ),
			'id' => $shortname . '_link_hover_color',
			'std' => '',
			'type' => 'color' );

		$options[] = array( 'name' =>  __( 'Button Color', 'woothemes' ),
			'desc' => __( 'Pick a custom color for buttons or add a hex color code e.g. #697e09', 'woothemes' ),
			'id' => $shortname . '_button_color',
			'std' => '',
			'type' => 'color' );

		/* Typography */

		$options[] = array( 'name' => __( 'Typography', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'typography' );

		$options[] = array( 'name' => __( 'Enable Custom Typography', 'woothemes' ) ,
			'desc' => __( 'Enable the use of custom typography for your site. Custom styling will be output in your sites HEAD.', 'woothemes' ) ,
			'id' => $shortname . '_typography',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'General Typography', 'woothemes' ) ,
			'desc' => __( 'Change the general font.', 'woothemes' ) ,
			'id' => $shortname . '_font_body',
			'std' => array( 'size' => '1.5', 'unit' => 'em', 'face' => 'Andada', 'style' => '', 'color' => '#333333' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Navigation', 'woothemes' ) ,
			'desc' => __( 'Change the navigation font.', 'woothemes' ),
			'id' => $shortname . '_font_nav',
			'std' => array( 'size' => '0.9', 'unit' => 'em', 'face' => 'Droid Serif', 'style' => 'bold', 'color' => '#333333' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Page Title', 'woothemes' ) ,
			'desc' => __( 'Change the page title.', 'woothemes' ) ,
			'id' => $shortname . '_font_page_title',
			'std' => array( 'size' => '3.5', 'unit' => 'em', 'face' => 'Droid Serif', 'style' => 'bold', 'color' => '#333333' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Post Title', 'woothemes' ) ,
			'desc' => __( 'Change the post title.', 'woothemes' ) ,
			'id' => $shortname . '_font_post_title',
			'std' => array( 'size' => '3.5', 'unit' => 'em', 'face' => 'Droid Serif', 'style' => 'bold', 'color' => '#333333' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Post Meta', 'woothemes' ),
			'desc' => __( 'Change the post meta.', 'woothemes' ) ,
			'id' => $shortname . '_font_post_meta',
			'std' => array( 'size' => '0.8', 'unit' => 'em', 'face' => 'Andada', 'style' => '', 'color' => '#AAAAAA' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Post Entry', 'woothemes' ) ,
			'desc' => __( 'Change the post entry.', 'woothemes' ) ,
			'id' => $shortname . '_font_post_entry',
			'std' => array( 'size' => '1', 'unit' => 'em', 'face' => 'Droid Serif', 'style' => '', 'color' => '#333333' ),
			'type' => 'typography' );

		$options[] = array( 'name' => __( 'Widget Titles', 'woothemes' ) ,
			'desc' => __( 'Change the widget titles.', 'woothemes' ) ,
			'id' => $shortname . '_font_widget_titles',
			'std' => array( 'size' => '0.7', 'unit' => 'em', 'face' => 'Droid Serif', 'style' => 'bold', 'color' => '#333333' ),
			'type' => 'typography' );

		/* Layout */

		$options[] = array( 'name' => __( 'Layout', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'layout' );

		$url =  get_template_directory_uri() . '/functions/images/';
		$options[] = array( 'name' => __( 'Main Layout', 'woothemes' ),
			'desc' => __( 'Select which layout you want for your site.', 'woothemes' ),
			'id' => $shortname . '_site_layout',
			'std' => "layout-left-content",
			'type' => 'images',
			'options' => array(
				'layout-left-content' => $url . '2cl.png',
				'layout-right-content' => $url . '2cr.png' )
		);

		$options[] = array( 'name' => __( 'Category Exclude - Homepage', 'woothemes' ),
			'desc' => __( 'Specify a comma seperated list of category IDs or slugs that you\'d like to exclude from your homepage (eg: uncategorized).', 'woothemes' ),
			'id' => $shortname . '_exclude_cats_home',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Category Exclude - Blog Page Template', 'woothemes' ),
			'desc' => __( 'Specify a comma seperated list of category IDs or slugs that you\'d like to exclude from your \'Blog\' page template (eg: uncategorized).', 'woothemes' ),
			'id' => $shortname . '_exclude_cats_blog',
			'std' => '',
			'type' => 'text' );
			
		$options[] = array( 'name' => __( 'Header - Search Field', 'woothemes' ),
            'desc' => __( 'Enable the search field in the header area.', 'woothemes' ),
            'id' => $shortname.'_header_search',
            'std' => 'true',
            'type' => 'checkbox');
            
		$options[] = array( 'name' => __( 'Header - Navigation', 'woothemes' ),
            'desc' => __( 'Enable the navigation in the header area.', 'woothemes' ),
            'id' => $shortname.'_header_navigation',
            'std' => 'true',
            'type' => 'checkbox');

		$options[] = array( 'name' => __( 'Display Post Meta Below Title', 'woothemes' ),
            'desc' => __( 'Display the post meta below the post title, instead of to the left side.', 'woothemes' ),
            'id' => $shortname.'_postmeta_below_title',
            'std' => 'false',
            'type' => 'checkbox');
         
        /* Homepage */
        $options[] = array( 'name' => __( 'Homepage', 'woothemes' ),
							'type' => 'heading',
							'icon' => 'homepage' );   

        /* Homepage Setup */
		$options[] = array( 'name' => __( 'Homepage Setup', 'woothemes' ),
							'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Custom Homepage Layout', 'woothemes' ),
							'desc' => '',
							'id' => $shortname . '_home_layout_notice',
							'std' => sprintf( __( 'It\'s possible to fully override and customise the layout of the homepage, by adding widgets to the "Homepage" widget area on the "%sWidgets%s" screen.%sWe\'ve also provided the "Woo - Component" widget to add the default homepage sections to your custom layout.%s', 'woothemes' ), '<a href="' . esc_url( admin_url( 'widgets.php' ) ) . '" target="_blank">', '</a>', '<br /><br /><small>', '</small>' ),
							'type' => 'info' );

		$options[] = array( 'name' => __( 'Enable Featured Slider', 'woothemes' ),
		                    'desc' => __( 'Enable the featured post slider on the homepage.', 'woothemes' ),
		                    'id' => $shortname . '_featured',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Enable "Recent Entries"', 'woothemes' ),
		                    'desc' => __( 'Enable the "Recent Entries" section on the default homepage.', 'woothemes' ),
		                    'id' => $shortname . '_recent_entries_enable',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Enable "Specific Entries"', 'woothemes' ),
		                    'desc' => __( 'Enable the "Specific Entries" section on the default homepage.', 'woothemes' ),
		                    'id' => $shortname . '_specific_entries_enable',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Enable the Categories Grid', 'woothemes' ),
		                    'desc' => __( 'Enable the "Categories Grid" section on the default homepage.', 'woothemes' ),
		                    'id' => $shortname . '_categories_grid_enable',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		/* Featured Slider */
		$options[] = array( 'name' => __( 'Featured Slider', 'woothemes' ),
			'type' => 'subheading' );
		                    
		$options[] = array( 'name' => __( 'Slider Entries', 'woothemes' ),
		                    'desc' => __( 'Select the number of entries that should appear in the home page slider.', 'woothemes' ),
		                    'id' => $shortname . '_featured_entries',
		                    'std' => '3',
		                    'type' => 'select',
		                    'options' => $other_entries);

		$options[] = array( 'name' => __( 'Filter By Category', 'woothemes' ),
							'desc' => __( 'Optionally select a category from which to display entries.', 'woothemes' ),
							'id' => $shortname . '_featured_category',
							'std' => '',
							'type' => 'select2', 
							'options' => $woo_categories );

		$options[] = array( 'name' => __( 'Filter By Tag', 'woothemes' ),
							'desc' => __( 'Optionally select a tag from which to display entries.', 'woothemes' ),
							'id' => $shortname . '_featured_tag',
							'std' => '',
							'type' => 'select2', 
							'options' => $woo_tags );

		$options[] = array( 'name' => __( 'Slider Post Order', 'woothemes' ),
		                    'desc' => __( 'Select which way you wish to order your slider posts.', 'woothemes' ),
		                    'id' => $shortname . '_featured_order',
		                    'std' => 'DESC',
							'type' => 'select2',
							'options' => array( 'desc' => __( 'Newest to oldest', 'woothemes' ), 'ASC' => __( 'Oldest to newest', 'woothemes' ), 'rand' => __( 'Random order', 'woothemes' ) ) );   
		
		$options[] = array( 'name' => __( 'Slider Post Content', 'woothemes' ),
							'desc' => __( 'Select if you want to show the full content or the excerpt on posts.', 'woothemes' ),
							'id' => $shortname . '_featured_post_content',
							'type' => 'select2',
							'std' => 'content', 
							'options' => array( 'excerpt' => __( 'The Excerpt', 'woothemes' ), 'content' => __( 'Full Content', 'woothemes' ) ) );

		$options[] = array( 'name' => __( 'Slider Next/Prev Navigation', 'woothemes' ),
		                    'desc' => __( 'Select to enable next/prev slider for the featured slider.', 'woothemes' ),
		                    'id' => $shortname . '_featured_nextprev',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Slider Pagination', 'woothemes' ),
		                    'desc' => __( 'Select to enable pagination for the featured slider.', 'woothemes' ),
		                    'id' => $shortname . '_featured_pagination',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Slider Hover Pause', 'woothemes' ),
		                    'desc' => __( 'Hovering over featured slider will pause it.', 'woothemes' ),
		                    'id' => $shortname . '_featured_hover',
		                    'std' => 'true',
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Auto Slide Interval', 'woothemes' ),
		                    'desc' => __( 'The time in <b>seconds</b> each slide pauses for, before transitioning to the next.', 'woothemes' ),
		                    'id' => $shortname . '_featured_speed',
		                    'std' => '7',
							'type' => 'select',
							'options' => array( __( 'Off', 'woothemes' ), '1', '2', '3', '4', '5', '6', '7', '8', '9', '10' ) );
		                    
		$options[] = array( 'name' => __( 'Slider Animation Speed', 'woothemes' ),
		                    'desc' => __( 'The time in <b>seconds</b> the animation between slides will take.', 'woothemes' ),
		                    'id' => $shortname . '_featured_animation_speed',
		                    'std' => '0.6',
							'type' => 'select',
							'options' => array( '0.0', '0.1', '0.2', '0.3', '0.4', '0.5', '0.6', '0.7', '0.8', '0.9', '1.0', '1.1', '1.2', '1.3', '1.4', '1.5', '1.6', '1.7', '1.8', '1.9', '2.0' ) );

		/* Recent Entries */
		$options[] = array( 'name' => __( 'Recent Entries', 'woothemes' ),
			'type' => 'subheading' );

		$token = '_recent_entries';

		$options[] = array( 'name' => __( 'Title', 'woothemes' ),
			'desc' => __( 'Enter a title for the "Recent Entries" section.', 'woothemes' ),
			'id' => $shortname . $token . '_title',
			'std' => __( 'Recent Entries', 'woothemes' ),
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Exclude Featured Slider Posts', 'woothemes' ),
		                    'desc' => __( 'Optionally exclude featured slider posts from displaying in the "Recent Entries" section.', 'woothemes' ),
		                    'id' => $shortname . $token . '_exclude_featured',
		                    'std' => 'true', 
		                    'type' => 'checkbox' );


		$options[] = array( 'name' => __( 'Display Thumbnail Images', 'woothemes' ),
		                    'desc' => __( 'Display thumbnail images, if available, next to each of the featured entries.', 'woothemes' ),
		                    'id' => $shortname . $token . '_image_enable',
		                    'std' => 'true', 
		                    'class' => 'collapsed', 
		                    'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Featured Image Dimensions', 'woothemes' ),
							'desc' => __( 'Enter integer values (eg: 130 and 85) for the desired size of the "Recent Entries" images.', 'woothemes' ),
							'id' => $shortname . $token . '_image_dimensions',
							'std' => '', 
							'class' => 'hidden', 
							'type' => array(
								array(  'id' => $shortname . $token . '_image_width',
									'type' => 'text',
									'std' => 130,
									'meta' => __( 'Width', 'woothemes' ) ),
								array(  'id' => $shortname . $token . '_image_height',
									'type' => 'text',
									'std' => 85,
									'meta' => __( 'Height', 'woothemes' ) )
							) );

		$options[] = array( 'name' => __( 'Image Alignment', 'woothemes' ),
			'desc' => __( 'Select the position of the image in relation to an entry\'s text.', 'woothemes' ),
			'id' => $shortname . $token . '_image_align',
			'std' => 'left',
			'type' => 'select2', 
			'class' => 'hidden last', 
			'options' => array( 'left' => __( 'Left', 'woothemes' ), 'right' => __( 'Right', 'woothemes' ) ) );

		$options[] = array( 'name' => __( 'Total Entries To Display', 'woothemes' ),
			'desc' => __( 'Select the number of recent entries to display.', 'woothemes' ),
			'id' => $shortname . $token . '_limit',
			'std' => 6,
			'type' => 'select2', 
			'options' => $woo_numbers );
		
		$options[] = array( 'name' => __( 'Number of Entries to Feature', 'woothemes' ),
			'desc' => __( 'Out of the entries displayed, how many should display in the "featured" style?', 'woothemes' ),
			'id' => $shortname . $token . '_featured',
			'std' => 2,
			'type' => 'select2', 
			'options' => $woo_numbers );

		$options[] = array( 'name' => __( 'Button Text', 'woothemes' ),
			'desc' => __( 'Enter text for the button to be displayed after the recent entries (leave empty to disable button).', 'woothemes' ),
			'id' => $shortname . $token . '_button_title',
			'std' => __( 'All Articles', 'woothemes' ),
			'type' => 'text' );
	
		$options[] = array( 'name' => __( 'Button Link', 'woothemes' ),
			'desc' => __( 'Select a page to which the button is to link.', 'woothemes' ),
			'id' => $shortname . $token . '_button_page_id',
			'std' => '',
			'type' => 'select2', 
			'options' => $woo_pages );

		/* Specific Entries */
		$options[] = array( 'name' => __( 'Specific Entries', 'woothemes' ),
			'type' => 'subheading' );

		$token = '_specific_entries';

		$options[] = array( 'name' => __( 'Title', 'woothemes' ),
			'desc' => __( 'Enter a title for the "Specific Entries" section.', 'woothemes' ),
			'id' => $shortname . $token . '_title',
			'std' => __( 'News in Pictures', 'woothemes' ),
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Featured Image Dimensions', 'woothemes' ),
			'desc' => __( 'Enter integer values (eg: 365 and 270) for the desired size of the "Specific Entries" images.', 'woothemes' ),
			'id' => $shortname . $token . '_image_dimensions',
			'std' => '', 
			'type' => array(
				array(  'id' => $shortname . $token . '_image_width',
					'type' => 'text',
					'std' => 365,
					'meta' => __( 'Width', 'woothemes' ) ),
				array(  'id' => $shortname . $token . '_image_height',
					'type' => 'text',
					'std' => 270,
					'meta' => __( 'Height', 'woothemes' ) )
			) );

		$options[] = array( 'name' => __( 'Thumbnail Image Dimensions', 'woothemes' ),
			'desc' => __( 'Enter integer values (eg: 130 and 80) for the desired size of the "Specific Entries" thumbnail images.', 'woothemes' ),
			'id' => $shortname . $token . '_thumb_dimensions',
			'std' => '', 
			'type' => array(
				array(  'id' => $shortname . $token . '_thumb_width',
					'type' => 'text',
					'std' => 130,
					'meta' => __( 'Width', 'woothemes' ) ),
				array(  'id' => $shortname . $token . '_thumb_height',
					'type' => 'text',
					'std' => 80,
					'meta' => __( 'Height', 'woothemes' ) )
			) );

		$options[] = array( 'name' => __( 'Total Entries To Display', 'woothemes' ),
			'desc' => __( 'Select the number of specific entries to display.', 'woothemes' ),
			'id' => $shortname . $token . '_limit',
			'std' => 6,
			'type' => 'select2', 
			'options' => $woo_numbers );
		
		$options[] = array( 'name' => __( 'Number of Entries to Feature', 'woothemes' ),
			'desc' => __( 'Out of the entries displayed, how many should display in the "featured" style?', 'woothemes' ),
			'id' => $shortname . $token . '_featured',
			'std' => 2,
			'type' => 'select2', 
			'options' => $woo_numbers );

		$options[] = array( 'name' => __( 'Filter By Category', 'woothemes' ),
			'desc' => __( 'Optionally select a category from which to display entries.', 'woothemes' ),
			'id' => $shortname . $token . '_category',
			'std' => '',
			'type' => 'select2', 
			'options' => $woo_categories );

		$options[] = array( 'name' => __( 'Filter By Tag', 'woothemes' ),
			'desc' => __( 'Optionally select a tag from which to display entries.', 'woothemes' ),
			'id' => $shortname . $token . '_tag',
			'std' => '',
			'type' => 'select2', 
			'options' => $woo_tags );

		$options[] = array( 'name' => __( 'Button Text', 'woothemes' ),
			'desc' => __( 'Enter text for the button to be displayed after the specific entries (leave empty to disable button).', 'woothemes' ),
			'id' => $shortname . $token . '_button_title',
			'std' => __( 'All Photos', 'woothemes' ),
			'type' => 'text' );
	
		$options[] = array( 'name' => __( 'Button Link', 'woothemes' ),
			'desc' => __( 'Select a page to which the button is to link.', 'woothemes' ),
			'id' => $shortname . $token . '_button_page_id',
			'std' => '',
			'type' => 'select2', 
			'options' => $woo_pages );

		/* Dynamic Images */
		$options[] = array( 'name' => __( 'Dynamic Images', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'image' );

		$options[] = array( 'name' => __( 'Resizer Settings', 'woothemes' ),
			'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Dynamic Image Resizing', 'woothemes' ),
			'desc' => '',
			'id' => $shortname . '_wpthumb_notice',
			'std' => __( 'There are two alternative methods of dynamically resizing the thumbnails in the theme, <strong>WP Post Thumbnail</strong> or <strong>TimThumb - Custom Settings panel</strong>. We recommend using WP Post Thumbnail option.', 'woothemes' ),
			'type' => "info" );

		$options[] = array( 'name' => __( 'WP Post Thumbnail', 'woothemes' ),
			'desc' => __( 'Use WordPress post thumbnail to assign a post thumbnail. Will enable the <strong>Featured Image panel</strong> in your post sidebar where you can assign a post thumbnail.', 'woothemes' ),
			'id' => $shortname . '_post_image_support',
			'std' => 'true',
			'class' => "collapsed",
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'WP Post Thumbnail - Dynamic Image Resizing', 'woothemes' ),
			'desc' => __( 'The post thumbnail will be dynamically resized using native WP resize functionality. <em>(Requires PHP 5.2+)</em>', 'woothemes' ),
			'id' => $shortname . '_pis_resize',
			'std' => 'true',
			'class' => "hidden",
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'WP Post Thumbnail - Hard Crop', 'woothemes' ),
			'desc' => __( 'The post thumbnail will be cropped to match the target aspect ratio (only used if "Dynamic Image Resizing" is enabled).', 'woothemes' ),
			'id' => $shortname . '_pis_hard_crop',
			'std' => 'true',
			'class' => "hidden last",
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'TimThumb - Custom Settings Panel', 'woothemes' ),
			'desc' => sprintf( __( 'This will enable the %1$s (thumb.php) script which dynamically resizes images added through the <strong>custom settings panel below the post</strong>. Make sure your themes <em>cache</em> folder is writable. %2$s', 'woothemes' ), '<a href="http://code.google.com/p/timthumb/">TimThumb</a>', '<a href="http://www.woothemes.com/2008/10/troubleshooting-image-resizer-thumbphp/">Need help?</a>' ),
			'id' => $shortname . '_resize',
			'std' => 'true',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Automatic Image Thumbnail', 'woothemes' ),
			'desc' => __( 'If no thumbnail is specifified then the first uploaded image in the post is used.', 'woothemes' ),
			'id' => $shortname . '_auto_img',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Thumbnail Settings', 'woothemes' ),
			'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Thumbnail Image Dimensions', 'woothemes' ),
			'desc' => __( 'Enter an integer value i.e. 250 for the desired size which will be used when dynamically creating the images.', 'woothemes' ),
			'id' => $shortname . '_image_dimensions',
			'std' => '',
			'type' => array(
				array(  'id' => $shortname . '_thumb_w',
					'type' => 'text',
					'std' => 100,
					'meta' => __( 'Width', 'woothemes' ) ),
				array(  'id' => $shortname . '_thumb_h',
					'type' => 'text',
					'std' => 100,
					'meta' => __( 'Height', 'woothemes' ) )
			) );

		$options[] = array( 'name' => __( 'Thumbnail Alignment', 'woothemes' ),
			'desc' => __( 'Select how to align your thumbnails with posts.', 'woothemes' ),
			'id' => $shortname . '_thumb_align',
			'std' => 'alignleft',
			'type' => 'select2',
			'options' => array( 'alignleft' => __( 'Left', 'woothemes' ), 'alignright' => __( 'Right', 'woothemes' ), 'aligncenter' => __( 'Center', 'woothemes' ) ) );

		$options[] = array( 'name' => 'Single Post - Show Thumbnail',
			'desc' => __( 'Show the thumbnail in the single post page.', 'woothemes' ),
			'id' => $shortname . '_thumb_single',
			'class' => 'collapsed',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Single Post - Thumbnail Dimensions', 'woothemes' ),
			'desc' => __( 'Enter an integer value i.e. 250 for the image size. Max width is 576.', 'woothemes' ),
			'id' => $shortname . '_image_dimensions',
			'std' => '',
			'class' => 'hidden last',
			'type' => array(
				array(  'id' => $shortname . '_single_w',
					'type' => 'text',
					'std' => 200,
					'meta' => __( 'Width', 'woothemes' ) ),
				array(  'id' => $shortname . '_single_h',
					'type' => 'text',
					'std' => 200,
					'meta' => __( 'Height', 'woothemes' ) )
			) );

		$options[] = array( 'name' => __( 'Single Post - Thumbnail Alignment', 'woothemes' ),
			'desc' => __( 'Select how to align your thumbnail with single posts.', 'woothemes' ),
			'id' => $shortname . '_thumb_single_align',
			'std' => 'alignright',
			'type' => 'select2',
			'class' => 'hidden',
			'options' => array( 'alignleft' => __( 'Left', 'woothemes' ), 'alignright' => __( 'Right', 'woothemes' ), 'aligncenter' => __( 'Center', 'woothemes' ) ) );

		$options[] = array( 'name' => __( 'Add thumbnail to RSS feed', 'woothemes' ),
			'desc' => __( 'Add the the image uploaded via your Custom Settings panel to your RSS feed', 'woothemes' ),
			'id' => $shortname . '_rss_thumb',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Enable Lightbox', 'woothemes' ),
					'desc' => __( 'Enable the PrettyPhoto lighbox script on images within your website\'s content.', 'woothemes' ),
					'id' => $shortname . '_enable_lightbox',
					'std' => 'false',
					'type' => 'checkbox' );

		/* Footer */
		$options[] = array( 'name' => __( 'Footer Customization', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'footer' );

		$url =  get_template_directory_uri() . '/functions/images/';
		$options[] = array( 'name' => __( 'Footer Widget Areas', 'woothemes' ),
			'desc' => __( 'Select how many footer widget areas you want to display.', 'woothemes' ),
			'id' => $shortname . '_footer_sidebars',
			'std' => "4",
			'type' => 'images',
			'options' => array(
				'0' => $url . 'layout-off.png',
				'1' => $url . 'footer-widgets-1.png',
				'2' => $url . 'footer-widgets-2.png',
				'3' => $url . 'footer-widgets-3.png',
				'4' => $url . 'footer-widgets-4.png' )
		);

		$options[] = array( 'name' => __( 'Custom Affiliate Link', 'woothemes' ),
			'desc' => __( 'Add an affiliate link to the WooThemes logo in the footer of the theme.', 'woothemes' ),
			'id' => $shortname . '_footer_aff_link',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Enable Custom Footer (Left)', 'woothemes' ),
			'desc' => __( 'Activate to add the custom text below to the theme footer.', 'woothemes' ),
			'id' => $shortname . '_footer_left',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Custom Text (Left)', 'woothemes' ),
			'desc' => __( 'Custom HTML and Text that will appear in the footer of your theme.', 'woothemes' ),
			'id' => $shortname . '_footer_left_text',
			'std' => '',
			'type' => 'textarea' );

		$options[] = array( 'name' => __( 'Enable Custom Footer (Right)', 'woothemes' ),
			'desc' => __( 'Activate to add the custom text below to the theme footer.', 'woothemes' ),
			'id' => $shortname . '_footer_right',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Custom Text (Right)', 'woothemes' ),
			'desc' => __( 'Custom HTML and Text that will appear in the footer of your theme.', 'woothemes' ),
			'id' => $shortname . '_footer_right_text',
			'std' => '',
			'type' => 'textarea' );

		/* Subscribe & Connect */
		$options[] = array( 'name' => __( 'Subscribe & Connect', 'woothemes' ),
			'type' => 'heading',
			'icon' => 'connect' );

		$options[] = array( 'name' => __( 'Setup', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Enable Subscribe & Connect - Single Post', 'woothemes' ),
			'desc' => sprintf( __( 'Enable the subscribe & connect area on single posts. You can also add this as a %1$s in your sidebar.', 'woothemes' ), '<a href="' . home_url() . '/wp-admin/widgets.php">widget</a>' ),
			'id' => $shortname . '_connect',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Subscribe Title', 'woothemes' ),
			'desc' => __( 'Enter the title to show in your subscribe & connect area.', 'woothemes' ),
			'id' => $shortname . '_connect_title',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Text', 'woothemes' ),
			'desc' => __( 'Change the default text in this area.', 'woothemes' ),
			'id' => $shortname . '_connect_content',
			'std' => '',
			'type' => 'textarea' );

		$options[] = array( 'name' => __( 'Enable Related Posts', 'woothemes' ),
			'desc' => __( 'Enable related posts in the subscribe area. Uses posts with the same <strong>tags</strong> to find related posts. Note: Will not show in the Subscribe widget.', 'woothemes' ),
			'id' => $shortname . '_connect_related',
			'std' => 'true',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Subscribe Settings', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Subscribe By E-mail ID (Feedburner)', 'woothemes' ),
			'desc' => __( 'Enter your <a href="http://www.woothemes.com/tutorials/how-to-find-your-feedburner-id-for-email-subscription/">Feedburner ID</a> for the e-mail subscription form.', 'woothemes' ),
			'id' => $shortname . '_connect_newsletter_id',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Subscribe By E-mail to MailChimp', 'woothemes', 'woothemes' ),
			'desc' => __( 'If you have a MailChimp account you can enter the <a href="http://woochimp.heroku.com" target="_blank">MailChimp List Subscribe URL</a> to allow your users to subscribe to a MailChimp List.', 'woothemes' ),
			'id' => $shortname . '_connect_mailchimp_list_url',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Connect Settings', 'woothemes' ),
					'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Enable RSS', 'woothemes' ),
			'desc' => __( 'Enable the subscribe and RSS icon.', 'woothemes' ),
			'id' => $shortname . '_connect_rss',
			'std' => 'true',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Twitter URL', 'woothemes' ),
			'desc' => __( 'Enter your  <a href="http://www.twitter.com/">Twitter</a> URL e.g. http://www.twitter.com/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_twitter',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Facebook URL', 'woothemes' ),
			'desc' => __( 'Enter your  <a href="http://www.facebook.com/">Facebook</a> URL e.g. http://www.facebook.com/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_facebook',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'YouTube URL', 'woothemes' ),
			'desc' => __( 'Enter your  <a href="http://www.youtube.com/">YouTube</a> URL e.g. http://www.youtube.com/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_youtube',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Flickr URL', 'woothemes' ),
			'desc' => __( 'Enter your  <a href="http://www.flickr.com/">Flickr</a> URL e.g. http://www.flickr.com/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_flickr',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'LinkedIn URL', 'woothemes' ),
			'desc' => __( 'Enter your  <a href="http://www.www.linkedin.com.com/">LinkedIn</a> URL e.g. http://www.linkedin.com/in/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_linkedin',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Delicious URL', 'woothemes' ),
			'desc' => __( 'Enter your <a href="http://www.delicious.com/">Delicious</a> URL e.g. http://www.delicious.com/woothemes', 'woothemes' ),
			'id' => $shortname . '_connect_delicious',
			'std' => '',
			'type' => 'text' );

		$options[] = array( 'name' => __( 'Google+ URL', 'woothemes' ),
			'desc' => __( 'Enter your <a href="http://plus.google.com/">Google+</a> URL e.g. https://plus.google.com/104560124403688998123/', 'woothemes' ),
			'id' => $shortname . '_connect_googleplus',
			'std' => '',
			'type' => 'text' );

		/* Advertising */
		$options[] = array( 'name' => __( 'Advertising', 'woothemes' ),
			'type' => 'heading',
			'icon' => "ads" );

		$options[] = array( 'name' => __( 'Top Ad (468x60px)', 'woothemes' ),
			'type' => 'subheading' );

		$options[] = array( 'name' => __( 'Enable Ad', 'woothemes' ),
			'desc' => __( 'Enable the ad space', 'woothemes' ),
			'id' => $shortname . '_ad_top',
			'std' => 'false',
			'type' => 'checkbox' );

		$options[] = array( 'name' => __( 'Adsense code', 'woothemes' ),
			'desc' => __( 'Enter your adsense code (or other ad network code) here.', 'woothemes' ),
			'id' => $shortname . '_ad_top_adsense',
			'std' => '',
			'type' => 'textarea' );

		$options[] = array( 'name' => __( 'Image Location', 'woothemes' ),
			'desc' => __( 'Enter the URL to the banner ad image location.', 'woothemes' ),
			'id' => $shortname . '_ad_top_image',
			'std' => "http://www.woothemes.com/ads/468x60b.jpg",
			'type' => 'upload' );

		$options[] = array( 'name' => __( 'Destination URL', 'woothemes' ),
			'desc' => __( 'Enter the URL where this banner ad points to.', 'woothemes' ),
			'id' => $shortname . '_ad_top_url',
			'std' => "http://www.woothemes.com",
			'type' => 'text' );
									
/* Contact Template Settings */

$options[] = array( 'name' => __( 'Contact Page', 'woothemes' ),
					'icon' => 'maps',
				    'type' => 'heading');    

$options[] = array( 'name' => __( 'Contact Information', 'woothemes' ),
					'type' => 'subheading');

$options[] = array( 'name' => __( 'Your Twitter username', 'woothemes' ),
					'desc' => __( 'Enter your Twitter username. Example: woothemes', 'woothemes' ),
					'id' => $shortname . '_contact_twitter',
					'std' => '',
					'type' => 'text' );
				    
$options[] = array( 'name' => __( 'Location Name', 'woothemes' ),
					'desc' => __( 'Enter the location name. Example: London Office', 'woothemes' ),
					'id' => $shortname . '_contact_title',
					'std' => '',
					'type' => 'text' );

$options[] = array( 'name' => __( 'Location Address', 'woothemes' ),
					'desc' => __( 'Enter your company\'s address', 'woothemes' ),
					'id' => $shortname . '_contact_address',
					'std' => '',
					'type' => 'textarea' );

$options[] = array( 'name' => __( 'Telephone', 'woothemes' ),
					'desc' => __( 'Enter your telephone number', 'woothemes' ),
					'id' => $shortname . '_contact_number',
					'std' => '',
					'type' => 'text' );

$options[] = array( 'name' => __( 'Fax', 'woothemes' ),
					'desc' => __( 'Enter your fax number', 'woothemes' ),
					'id' => $shortname . '_contact_fax',
					'std' => '',
					'type' => 'text' );

$options[] = array( 'name' => __( 'Email Address', 'woothemes' ),
					'desc' => __( 'Enter your email address', 'woothemes' ),
					'id' => $shortname . '_contact_email',
					'std' => '',
					'type' => 'text' );

$options[] = array( 'name' => __( 'Maps', 'woothemes' ),
					'type' => 'subheading');
					
$options[] = array( 'name' => __( 'Contact Form Google Maps Coordinates', 'woothemes' ),
					'desc' => sprintf( __( 'Enter your Google Map coordinates to display a map on the Contact Form page template and a link to it on the Contact Us widget. You can get these details from %sGoogle Maps%s', 'woothemes' ), '<a href="' . esc_url( 'http://www.getlatlon.com/' ) . '" target="_blank">', '</a>' ),
					'id' => $shortname . '_contactform_map_coords',
					'std' => '',
					'type' => 'text' );
					
$options[] = array( 'name' => __( 'Disable Mousescroll', 'woothemes' ),
					'desc' => __( 'Turn off the mouse scroll action for all the Google Maps on the site. This could improve usability on your site.', 'woothemes' ),
					'id' => $shortname . '_maps_scroll',
					'std' => '',
					'type' => 'checkbox');

$options[] = array( 'name' => __( 'Map Height', 'woothemes' ),
					'desc' => __( 'Height in pixels for the maps displayed on Single.php pages.', 'woothemes' ),
					'id' => $shortname . '_maps_single_height',
					'std' => '250',
					'type' => 'text');
					
$options[] = array( 'name' => __( 'Default Map Zoom Level', 'woothemes' ),
					'desc' => __( 'Set this to adjust the default in the post & page edit backend.', 'woothemes' ),
					'id' => $shortname . '_maps_default_mapzoom',
					'std' => '9',
					'type' => 'select2',
					'options' => $other_entries);

$options[] = array( 'name' => __( 'Default Map Type', 'woothemes' ),
					'desc' => __( 'Set this to the default rendered in the post backend.', 'woothemes' ),
					'id' => $shortname . '_maps_default_maptype',
					'std' => 'G_NORMAL_MAP',
					'type' => 'select2',
					'options' => array( 'G_NORMAL_MAP' => __( 'Normal', 'woothemes' ), 'G_SATELLITE_MAP' => __( 'Satellite', 'woothemes' ), 'G_HYBRID_MAP' => __( 'Hybrid', 'woothemes' ), 'G_PHYSICAL_MAP' => __( 'Terrain', 'woothemes' ) ) );

// Add extra options through function
if ( function_exists( 'woo_options_add' ) )
	$options = woo_options_add( $options );

if ( get_option( 'woo_template' ) != $options) update_option( 'woo_template', $options );
if ( get_option( 'woo_themename' ) != $themename) update_option( 'woo_themename', $themename );
if ( get_option( 'woo_shortname' ) != $shortname) update_option( 'woo_shortname', $shortname );
if ( get_option( 'woo_manual' ) != $manualurl) update_option( 'woo_manual', $manualurl );

// Woo Metabox Options
// Start name with underscore to hide custom key from the user
global $post;
$woo_metaboxes = array();

// Shown on both posts and pages


// Show only on specific post types or page

if ( ( get_post_type() == 'post' ) || ( ! get_post_type() ) ) {

	// TimThumb is enabled in options
	if ( get_option( 'woo_resize' ) == 'true' ) {
	
		$woo_metaboxes[] = array (	'name' => 'image',
									'label' => __( 'Image', 'woothemes' ),
									'type' => 'upload',
									'desc' => __( 'Upload an image or enter an URL.', 'woothemes' ) );

		$woo_metaboxes[] = array (	'name' => '_image_alignment',
									'std' => 'c',
									'label' => __( 'Image Crop Alignment', 'woothemes' ),
									'type' => 'select2',
									'desc' => __( 'Select crop alignment for resized image', 'woothemes' ),
									'options' => array(	'c' => __( 'Center', 'woothemes' ),
														't' => __( 'Top', 'woothemes' ),
														'b' => __( 'Bottom', 'woothemes' ),
														'l' => __( 'Left', 'woothemes' ),
														'r' => __( 'Right', 'woothemes' ) ) );
	// TimThumb disabled in the options
	} else {
	
		$woo_metaboxes[] = array (	'name' => '_timthumb-info',
									'label' => __( 'Image', 'woothemes' ),
									'type' => 'info',
									'desc' => sprintf( __( '%1$sTimThumb%2$s is disabled. Use the %1$sFeatured Image%2$s panel in the sidebar instead, or enable TimThumb in the options panel.', 'woothemes' ), '<strong>', '</strong>' ) );

	}

	$woo_metaboxes[] = array (  'name'  => 'embed',
					            'std'  => '',
					            'label' => __( 'Embed Code', 'woothemes' ),
					            'type' => 'textarea',
					            'desc' => __( 'Enter the video embed code for your video (YouTube, Vimeo or similar)', 'woothemes' ) );

} // End post

if ( ( get_post_type() == 'post' ) || ( get_post_type() == 'page' ) || ( !get_post_type() ) ) {
	$template_url = get_template_directory_uri();
$woo_metaboxes[] = array (	'name' => '_column_layout',
							'std' => 'layout-std',
							'label' => __( 'Column Layout Style', 'woothemes' ),
							'type' => 'images',
							'class' => 'collapse',
							'desc' => __( 'Select the post content column layout style you want on this specific post/page.', 'woothemes' ),
							'options' => array(
										'layout-std' => esc_url( $template_url . '/images/' . 'ico-layout-std.png' ),
										'layout-3col' => esc_url( $template_url . '/images/' . 'ico-layout-3col.png' ), 
										'layout-2colA' => esc_url( $template_url . '/images/' . 'ico-layout-2colA.png' ),
										'layout-2colB' => esc_url( $template_url . '/images/' . 'ico-layout-2colB.png' ),
										'layout-2colC' => esc_url( $template_url . '/images/' . 'ico-layout-2colC.png' )
										));

$woo_metaboxes[] = array( 'label' => __( 'A Note on Column Layout Selection', 'woothemes' ),
					'type' => 'info',
					'class' => 'collapse last',
					'desc' => sprintf( __( 'When selecting a column layout option, please be sure to add only the appropriate number of column breaks into the content editor above.%1$sFor example, if you have selected a two-column layout, only a single column break is required to produce two columns.%1$sIf you have chosen a three-column layout, two column breaks are required.', 'woothemes' ), '<br />' ) );

}

$woo_metaboxes[] = array (	'name' => '_layout',
							'std' => 'layout-default',
							'label' => __( 'Layout', 'woothemes' ), 
							'type' => 'images',
							'desc' => __( 'Select the layout you want on this specific post/page.', 'woothemes' ),
							'options' => array(
										'layout-default' => esc_url( $template_url . '/functions/images/' . 'layout-off.png' ),
										'layout-full' => esc_url( $template_url . '/functions/images/' . '1c.png' ),
										'layout-left-content' => esc_url( $template_url . '/functions/images/' . '2cl.png' ),
										'layout-right-content' => esc_url( $template_url . '/functions/images/' . '2cr.png' ) ) );

// Add extra metaboxes through function
if ( function_exists( 'woo_metaboxes_add' ) )
	$woo_metaboxes = woo_metaboxes_add($woo_metaboxes);

if ( get_option( 'woo_custom_template' ) != $woo_metaboxes) update_option( 'woo_custom_template', $woo_metaboxes );

} // END woo_options()
} // END function_exists()

// Add options to admin_head
add_action( 'admin_head','woo_options' );

//Enable WooSEO on these Post types
$seo_post_types = array( 'post', 'page' );
define( 'SEOPOSTTYPES', serialize( $seo_post_types ) );

//Global options setup
add_action( 'init','woo_global_options' );
function woo_global_options(){
	// Populate WooThemes option in array for use in theme
	global $woo_options;
	$woo_options = get_option( 'woo_options' );
}
?>