<?php
/**
 * Categories Grid Template Part
 *
 * Here we setup all logic and XHTML that is required for the categories grid template part, used on the homepage.
 *
 * @package WooFramework
 * @subpackage Template
 */

	$html = '<section id="categories" class="section_categories col-full">' . "\n";
	$html .= '<h3 class="section-title">' . __( 'Categories', 'woothemes' ) . '</h3>' . "\n";
	$html .= '<ul class="section-body">' . "\n";
	$cat_args = array( 'title_li' => '', 'echo' => false, 'hierarchical' => 1, 'depth' => 1 );
	$html .= wp_list_categories( apply_filters( 'widget_categories_args', $cat_args ) );
	$html .= '</ul>' . "\n";

	echo $html;
?>