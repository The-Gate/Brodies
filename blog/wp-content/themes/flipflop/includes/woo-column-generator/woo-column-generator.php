<?php
/**
 * WooThemes Column Generator.
 *
 * Split page/post content into columns.
 *
 * @package WordPress
 * @subpackage WooFramework
 * @category Component
 * @author Matty
 * @since 1.0.0
 *
 * TABLE OF CONTENTS
 *
 * - var $template_url
 * - var $column_counter
 * - var $count_column
 * - var $total_columns
 * - var $used_numbers
 * - var $current_column
 *
 * - function __construct()
 * - function init()
 * - function filter_mce_buttons()
 * - function filter_mce_external_plugins()
 * - function create_columns()
 * - function create_columns_callback()
 * - function tag_unautop()
 * - function remove_empty_p()
 * - function toggle_filters()
 * - function add_body_class()
 * - function get_layout_by_id()
 * - function get_supported_layouts()
 */

class WooThemes_Column_Generator {
	var $template_url;
	var $column_counter;
	var $count_column;
	var $total_columns;
	var $used_numbers;
	var $current_column;

	/**
	 * Constructor.
	 * @since   1.0.0
	 * @return  void
	 */
	public function __construct () {
		$this->template_url = get_template_directory_uri();
		$this->column_counter = 2;
		$this->count_column = true;
		$this->total_columns = 1;
		$this->current_column = 2;
		$this->used_numbers = array();
	
		// Register the necessary actions on `admin_init`.
		if ( is_admin() ) {
			add_action( 'admin_init', array( &$this, 'init' ) );
		} else {
			add_filter( 'body_class', array( &$this, 'add_body_class' ) );
			$this->toggle_filters();
		}
	} // End __construct()

	/**
	 * Initialize the column generator administration.
	 * @since  1.0.0
	 * @return void
	 */
	public function init() {
		if ( ( current_user_can( 'edit_posts' ) || current_user_can( 'edit_pages' ) ) && get_user_option( 'rich_editing') == 'true' )  {
		  	// Add the tinyMCE buttons and plugins.
			add_filter( 'mce_buttons', array( &$this, 'filter_mce_buttons' ) );
			add_filter( 'mce_external_plugins', array( &$this, 'filter_mce_external_plugins' ) );
		}
	} // End init()

	/**
	 * Add our new button to the tinyMCE editor.
	 * @since  1.0.0
	 * @param  array $buttons The existing array of buttons.
	 * @return array          The modified array of buttons.
	 */
	public function filter_mce_buttons( $buttons ) {
		array_push( $buttons, '|', 'WooThemesColumnGenerator' );
		
		return $buttons;
	} // End filter_mce_buttons()

	/**
	 * Add functionality to the tinyMCE editor as an external plugin.
	 * @since  1.0.0
	 * @param  array $plugins Array of tinyMCE plugins.
	 * @return array          Modified array of tinyMCE plugins.
	 */
	public function filter_mce_external_plugins( $plugins ) {
        $plugins['WooThemesColumnGenerator'] = $this->template_url . '/includes/woo-column-generator/js/editor_plugin.js';
        
        return $plugins;
	} // End filter_mce_external_plugins()
	
	/**
	 * Creates columns in the content by replacing <!--column--> tags.
	 * @since  1.0.0
	 * @param  string $content The existing content.
	 * @return string          The content, with columns parsed.
	 */	
	public function create_columns ( $content ) {	
		// if ( in_the_loop() ) {
		
			global $post;
		
			$custom_meta = get_post_custom( $post->ID );
		
			$columns_in_layout = 2;
			
			if ( ( array_key_exists( '_column_layout', (array) $custom_meta ) ) && 
				 ( $custom_meta['_column_layout'][0] == 'layout-3col' ) ) {
				$columns_in_layout = 3;
			}
			
			$this->columns_in_layout = $columns_in_layout;
		
			$pattern = '/<!--column(.*?)?-->/';
			
			preg_match_all( $pattern, $content, $matches );
			
			if ( is_array( $matches ) && is_array( $matches[0] ) ) {
				$this->total_columns = count( $matches[0] );
			}
			
			if ( preg_match( $pattern, $content, $matches ) ) {
				$content = preg_replace_callback( $pattern, array( &$this, 'create_columns_callback' ), $content );
			}
		
		// }
		
		return $content;
	} // End create_columns()
	
	/**
	 * Creates columns in the content by replacing <!--column--> tags.
	 * @since  1.0.0
	 * @param  array $matches  An array of matching column tags.
	 * @return strong          The modified content.
	 */
	public function create_columns_callback ( $matches ) {
		$column_number = $this->current_column;
		
		if ( $column_number < 10 ) { $column_number = '0' . $column_number; }
		
		$fix = '';
		$css_class = '';
		
		if ( ( ( $this->current_column - 1 ) % $this->columns_in_layout == 0 ) && ( $this->current_column > 1 ) ) {
			$fix = '<div class="fix column-clear"></div><!--/.fix column-clear-->' . "\n";
		}
		
		if ( ( ( $this->current_column ) % $this->columns_in_layout == 0 ) && ( $this->current_column > 1 ) ) {
			$css_class = ' last';
		}
		
		$pattern = '/<!--column(.*?)?-->/';
		$replacement = '</div>';
		
		$replacement .= $fix;
		
		$replacement .= '<div class="column column-' . $column_number . $css_class . '">';

		$content = $replacement;
		
		$this->current_column++;
		
		return $content;
	} // End create_columns_callback()

	/**
	 * Don't auto-p wrap shortcodes that stand alone. Attempts to prevent <p><!--column--></p>.
	 * Ensures that shortcodes are not wrapped in <<p>>...<</p>>.
	 * @since 2.9.0
	 * @param string $pee The content.
	 * @return string The filtered content.
	 */
	public function tag_unautop ( $content ) {
		global $shortcode_tags;
	
		if ( !empty($shortcode_tags) && is_array($shortcode_tags) ) {
			$tagnames = array_keys($shortcode_tags);
			$tagregexp = join( '|', array_map('preg_quote', $tagnames) );
			$content = preg_replace('/<p>\\s*?(<!--column-->)\\s*<\\/p>/s', '$1', $content );
		}
	
		return $content;	
	} // End tag_unautop()
	
	/**
	 * Attempts to remove empty <p></p> tags.
	 * @since  1.0.0
	 * @param  string $content The content.
	 * @return string          The filtered content.
	 */
	public function remove_empty_p ( $content ) {
		$content = str_replace( '<p></p>', '', $content );
	
		return $content;
	} // End remove_empty_p()

	/**
	 * Toggles our content filters.
	 * @since  1.0.0
	 * @param  boolean $off Whether to turn the filters on or off.
	 * @return void
	 */
	public function toggle_filters ( $off = false ) {
		if ( $off == true ) {
			// Create columns in the content.
			remove_filter( 'the_content', array( &$this, 'tag_unautop' ), 10 );
			remove_filter( 'the_content', array( &$this, 'create_columns' ), 11 );
			remove_filter( 'the_content', array( &$this, 'remove_empty_p' ), 12 );
		} else {
			// Create columns in the content.
			add_filter( 'the_content', array( &$this, 'tag_unautop' ), 10 );
			add_filter( 'the_content', array( &$this, 'create_columns' ), 11 );
			add_filter( 'the_content', array( &$this, 'remove_empty_p' ), 12 );
		}
	} // End toggle_filters()

	/**
	 * Add the appropriate layout type as a CSS class on the "body" tag.
	 * @since  1.0.0
	 * @param  array $classes Existing classes.
	 * @return array Modified array of classes.
	 */
	public function add_body_class ( $classes ) {
		if ( is_singular() ) {
			$classes[] = $this->get_layout_by_id( get_the_ID() );
		}

		return $classes;
	} // End add_body_class()

	/**
	 * Get the selected layout for a specified post ID.
	 * @since  1.0.0
	 * @param  int 	  $id Post ID.
	 * @return string     Selected layout class.
	 */
	public function get_layout_by_id ( $id ) {
		$response = 'column-layout-std';
		$column_layout = get_post_meta( intval( $id ), '_column_layout', true );
		if ( $column_layout != '' && in_array( $column_layout, $this->get_supported_layouts() ) ) {
			$response = 'column-' . $column_layout;
		}

		return $response;
	} // End get_layout_by_id()

	/**
	 * Return an array of the various layout options.
	 * @since  1.0.0
	 * @return array Supported layout options.
	 */
	private function get_supported_layouts () {
		return array( 'layout-std-full', 'layout-std', 'layout-3col', 'layout-2colA', 'layout-2colB', 'layout-2colC' );
	} // End get_supported_layouts()
} // End Class
?>