<?php
/**
 * Search Form Template
 *
 * This template is a customised search form.
 *
 * @package WooFramework
 * @subpackage Template
 */
?>
<div class="search_main fix">
    <form method="get" class="searchform" action="<?php echo esc_url( home_url( '/' ) ); ?>" >
        <input type="text" class="field s" name="s" />
        <input type="image" src="<?php echo get_template_directory_uri(); ?>/images/ico-search.png" class="search-submit" name="submit" alt="<?php esc_attr_e( 'Submit', 'woothemes' ); ?>" />
    </form>    
</div><!--/.search_main-->