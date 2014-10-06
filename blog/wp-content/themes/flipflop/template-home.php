<?php
/**
 * Template Name: Home (RecentNews)
 *
 * The Home page template displays the "blog-style" template but shows recent posts from all categoires (controlled by a widget area)
 *
 * @package WooFramework
 * @subpackage Template
 */

 global $woo_options;
 get_header();
 
/**
 * The Variables
 *
 * Setup default variables, overriding them if the "Theme Options" have been saved.
 */
	
	$settings = array(
					'thumb_w' => 100, 
					'thumb_h' => 100, 
					'thumb_align' => 'alignleft'
					);
					
	$settings = woo_get_dynamic_values( $settings );
?>
    <!-- #content Starts -->
    <div id="content">
    <div class="col-full">
    
        <?php woo_main_before(); ?>
        
        <section id="main" class="col-left">   
        	
        <h1>Recent News</h1> 
        
        <div class="homeRec">	
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/bclaims/feed">RSS Feed Bclaims</a>
        	</div> 					
		<?php if ( is_active_sidebar( 'homerecentbclaims' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentbclaims' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>  
		</div>
		
		<div class="homeRec">	
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/btrainees/feed">RSS Feed BTrainees</a>
        	</div> 					
		<?php if ( is_active_sidebar( 'homerecentbtrainees' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentbtrainees' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>  
		</div>
		
		<div class="homeRec">  	
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/corporate-law/feed">RSS Feed Corporate Law</a> 
        	</div> 					
		<?php if ( is_active_sidebar( 'homerecentcorporate' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentcorporate' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>   
		</div>
		
        
        <div class="homeRec">
        	<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/employment-law/feed">RSS Feed Employment Law</a>
        	</div>  
        
        	<?php if ( is_active_sidebar( 'homerecentemployment' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentemployment' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>   
		</div>
		
		<div class="homeRec">  	
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/family-law/feed">RSS Feed Family Law</a> 
        	</div> 					
		<?php if ( is_active_sidebar( 'homerecentfamily' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentfamily' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>   
		</div>
		
		
	
		
		<div class="homeRec">  
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/health-and-safety/feed">RSS Feed Health & Safety</a>
        	</div> 						
		<?php if ( is_active_sidebar( 'homerecenthealth' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecenthealth' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>     
		</div>
		
		<div class="homeRec"> 
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/planning/feed">RSS Feed Planning</a>
        	</div>  						
		<?php if ( is_active_sidebar( 'homerecentplanning' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentplanning' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>  
		</div>
		
		
			<div class="homeRec"> 
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/public-law/feed">RSS Feed Public Law</a>
        	</div>  
		<?php if ( is_active_sidebar( 'homerecentpublic' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentpublic' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>   
		</div>
		
		
		<div class="homeRec"> 
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/renewables/feed">RSS Feed Renewables</a>
        	</div>  						
		<?php if ( is_active_sidebar( 'homerecentrenewables' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecentrenewables' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>
		</div>
		
	
		
		
		
		
			<div class="homeRec">  
			<div class="homeRecRSS">
        	<a href="<?php echo home_url(); ?>/category/tech/feed">RSS Feed Tech</a>
        	</div> 
		<?php if ( is_active_sidebar( 'homerecenttech' ) ) : ?>								
								<?php if ( !dynamic_sidebar( 'homerecenttech' ) ) : ?>
								<?php endif; ?>
								<?php endif; ?>  
		</div>
								
		
			
			
			
			
			
			
			 

        </section><!-- /#main -->
        
        <?php woo_main_after(); ?>
            
		<?php get_sidebar(); ?>

	</div><!-- /.col-full -->
    </div><!-- /#content -->		
		
<?php get_footer(); ?>