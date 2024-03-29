<?php
/*
    Plugin Name: ThinkTwit
    Plugin URI: http://www.thepicketts.org/thinktwit/
    Description: Outputs tweets from any Twitter users, hashtag or keyword through the Widget interface. Can be called via shortcode or PHP function call. If you like ThinkTwit please rate it at <a href="http://wordpress.org/extend/plugins/thinktwit/" title="ThinkTwit on Wordpress.org">http://wordpress.org/extend/plugins/thinktwit/</a> and of course any blog articles on ThinkTwit or recommendations greatly appreciated!
    Version: 1.5.3
    Author: Stephen Pickett
    Author URI: http://www.thepicketts.org/
	Text Domain: thinktwit

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

	define("THINKTWIT_VERSION",				"1.5.3");
	define("THINKTWIT_USERNAMES", 			"stephenpickett");
	define("THINKTWIT_HASHTAGS", 			"");
	define("THINKTWIT_USERNAME_SUFFIX", 	" said: ");
	define("THINKTWIT_LIMIT", 				5);
	define("THINKTWIT_MAX_DAYS", 			7);
	define("THINKTWIT_UPDATE_FREQUENCY", 	0);
	define("THINKTWIT_SHOW_USERNAME", 		"name");
	define("THINKTWIT_SHOW_AVATAR", 		1);
	define("THINKTWIT_SHOW_PUBLISHED", 		1);
	define("THINKTWIT_SHOW_FOLLOW",    		1);
	define("THINKTWIT_LINKS_NEW_WINDOW", 	1);
	define("THINKTWIT_NO_CACHE", 			0);
	define("THINKTWIT_USE_CURL", 			0);
	define("THINKTWIT_DEBUG", 				0);
	define("THINKTWIT_TIME_THIS_HAPPENED",	"This happened ");
	define("THINKTWIT_TIME_LESS_MIN",      	"less than a minute ago");
	define("THINKTWIT_TIME_MIN",           	"about a minute ago");
	define("THINKTWIT_TIME_MORE_MINS",     	" minutes ago");
	define("THINKTWIT_TIME_1_HOUR",        	"about an hour ago");
	define("THINKTWIT_TIME_2_HOURS",       	"a couple of hours ago");
	define("THINKTWIT_TIME_PRECISE_HOURS", 	"about =x= hours ago");
	define("THINKTWIT_TIME_1_DAY",         	"yesterday");
	define("THINKTWIT_TIME_2_DAYS",        	"almost 2 days ago");
	define("THINKTWIT_TIME_MANY_DAYS",     	" days ago");
	define("THINKTWIT_TIME_NO_RECENT",     	"There have been no recent tweets");

	// Register the widget to be initiated
	add_action("widgets_init", create_function("", "return register_widget(\"ThinkTwit\");"));
	
	// Load the translated strings
	load_plugin_textdomain('thinktwit', false, dirname(plugin_basename(__FILE__)) . '/languages/');

	class ThinkTwit extends WP_Widget {	
		// Returns the current ThinkTwit version
		public static function get_version() {
			return THINKTWIT_VERSION;
		}
		
		// Constructor
		public function __construct() {			
			// Set the description of the widget
			$widget_ops = array("description" => __("Outputs tweets from one or more Twitter users through the Widget interface, filtered on a particular #hashtag(s)"), 'thinktwit');

			// Load jQuery
			wp_enqueue_script("jquery");
			
			// Get our widget settings
			$settings = get_option("widget_thinktwit_settings");
			
			// If settings isn't an array
			if (!is_array($settings)) {
				// Use the default style
				$use_default_style = 1;
			} else {
				// Otherwise get the admin's selected option
				$use_default_style = isset($settings["use_default_style"]) ? $settings["use_default_style"] : 1;
			}
			
			// Load stylesheet
			$thinktwit_style_url = plugins_url("thinktwit.css", __FILE__); // Respects SSL, stylesheet is relative to the current file
			$thinktwit_style_file = WP_PLUGIN_DIR . "/thinktwit/thinktwit.css";

			// Check that the user wants to use the default style and then if the file exists
			if ($use_default_style && file_exists($thinktwit_style_file)) {
				// If so register the style and enqueue it
				wp_register_style("thinktwit", $thinktwit_style_url);
				wp_enqueue_style("thinktwit");
			}
			
			// Add shortcode
			add_shortcode("thinktwit", "ThinkTwit::shortcode_handler");

			// Add the handler to init()
			add_action("init", "ThinkTwit::ajax_request_handler");
			
			// If the user is an admin add the plugin settings menu option
			if (is_admin()) {
				// Add the menu option
				add_action('admin_menu', 'ThinkTwit::admin_menu');
				add_action('admin_init', 'ThinkTwit::admin_page_init');
			}
			
			// Override the default constructor, passing the name and description
			parent::WP_Widget("thinkTwit", $name = "ThinkTwit", $widget_ops);
		}
		
		// Display the widget
		public function widget($args, $instance) {
			extract($args);

			// Get the div id of the widget
			$widget_id        = $args["widget_id"];

			// Store the widget values in variables
			$title            = apply_filters("widget_title", $instance["title"]);
			$usernames        = !isset($instance["usernames"])			? THINKTWIT_USERNAMES : $instance["usernames"];
			$hashtags  	      = !isset($instance["hashtags"])			? THINKTWIT_HASHTAGS : $instance["hashtags"];
			$username_suffix  = !isset($instance["username_suffix"])	? THINKTWIT_USERNAME_SUFFIX : $instance["username_suffix"];
			$limit            = !isset($instance["limit"])				? THINKTWIT_LIMIT : $instance["limit"];
			$max_days         = !isset($instance["max_days"])			? THINKTWIT_MAX_DAYS : $instance["max_days"];
			$update_frequency = !isset($instance["update_frequency"])	? THINKTWIT_UPDATE_FREQUENCY : $instance["update_frequency"];
			$show_username    = !isset($instance["show_username"])		? THINKTWIT_SHOW_USERNAME : $instance["show_username"];
			$show_avatar      = !isset($instance["show_avatar"])		? THINKTWIT_SHOW_AVATAR : $instance["show_avatar"];
			$show_published   = !isset($instance["show_published"])		? THINKTWIT_SHOW_PUBLISHED : $instance["show_published"];
			$show_follow      = !isset($instance["show_follow"])		? THINKTWIT_SHOW_FOLLOW : $instance["show_follow"];
			$links_new_window = !isset($instance["links_new_window"])	? THINKTWIT_LINKS_NEW_WINDOW : $instance["links_new_window"];
			$no_cache         = !isset($instance["no_cache"])			? THINKTWIT_NO_CACHE : $instance["no_cache"];
			$use_curl         = !isset($instance["use_curl"])			? THINKTWIT_USE_CURL : $instance["use_curl"];
			$debug            = !isset($instance["debug"])				? THINKTWIT_DEBUG : $instance["debug"];
			
			// Times
			$time_settings = array(11);
			$time_settings[0] = !isset($instance["time_this_happened"])	? THINKTWIT_TIME_THIS_HAPPENED : $instance["time_this_happened"];
			$time_settings[1] = !isset($instance["time_less_min"])		? THINKTWIT_TIME_LESS_MIN : $instance["time_less_min"];
			$time_settings[2] = !isset($instance["time_min"])			? THINKTWIT_TIME_MIN : $instance["time_min"];
			$time_settings[3] = !isset($instance["time_more_mins"])		? THINKTWIT_TIME_MORE_MINS : $instance["time_more_mins"];
			$time_settings[4] = !isset($instance["time_1_hour"])		? THINKTWIT_TIME_1_HOUR : $instance["time_1_hour"];
			$time_settings[5] = !isset($instance["time_2_hours"])		? THINKTWIT_TIME_2_HOURS : $instance["time_2_hours"];
			$time_settings[6] = !isset($instance["time_precise_hours"])	? THINKTWIT_TIME_PRECISE_HOURS : $instance["time_precise_hours"];
			$time_settings[7] = !isset($instance["time_1_day"])			? THINKTWIT_TIME_1_DAY : $instance["time_1_day"];
			$time_settings[8] = !isset($instance["time_2_days"])		? THINKTWIT_TIME_2_DAYS : $instance["time_2_days"];
			$time_settings[9] = !isset($instance["time_many_days"])		? THINKTWIT_TIME_MANY_DAYS : $instance["time_many_days"];
			$time_settings[10]= !isset($instance["time_no_recent"])		? THINKTWIT_TIME_NO_RECENT : $instance["time_no_recent"];
			
			// Output code that should appear before the widget
			echo $before_widget;

			// If there is a title output it with before and after code
			if ($title)
				echo $before_title . $title . $after_title;

			// If the user selected to not cache the widget then output AJAX method
			if ($no_cache) { 
				echo ThinkTwit::output_ajax($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings);
			// Otherwise output HTML method
			} else {
				echo ThinkTwit::parse_feed($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings);
			}
			
			// Output code that should appear after the widget
			echo $after_widget;
		}

		// Update the widget when editing through admin user interface
		public function update($new_instance, $old_instance) {
			$instance = $old_instance;

			// Strip tags and update the widget settings
			$instance["title"]              = strip_tags($new_instance["title"]);
			$instance["usernames"]          = strip_tags($new_instance["usernames"]);
			$instance["hashtags"]           = strip_tags($new_instance["hashtags"]);
			$instance["username_suffix"]    = strip_tags($new_instance["username_suffix"]);
			$instance["limit"]              = strip_tags($new_instance["limit"]);
			$instance["max_days"]           = strip_tags($new_instance["max_days"]);
			$instance["update_frequency"]   = strip_tags($new_instance["update_frequency"]);
			$instance["show_username"]      = strip_tags($new_instance["show_username"]);
			$instance["show_avatar"]        = (strip_tags($new_instance["show_avatar"]) == "Yes" ? 1 : 0);
			$instance["show_published"]     = (strip_tags($new_instance["show_published"]) == "Yes" ? 1 : 0);
			$instance["show_follow"]        = (strip_tags($new_instance["show_follow"]) == "Yes" ? 1 : 0);
			$instance["links_new_window"]   = (strip_tags($new_instance["links_new_window"]) == "Yes" ? 1 : 0);
			$instance["no_cache"]           = (strip_tags($new_instance["no_cache"]) == "Yes" ? 1 : 0);
			$instance["use_curl"]           = (strip_tags($new_instance["use_curl"]) == "Yes" ? 1 : 0);
			$instance["debug"]              = (strip_tags($new_instance["debug"]) == "Yes" ? 1 : 0);
			$instance["time_this_happened"] = strip_tags($new_instance["time_this_happened"]);
			$instance["time_less_min"]      = strip_tags($new_instance["time_less_min"]);
			$instance["time_min"]           = strip_tags($new_instance["time_min"]);
			$instance["time_more_mins"]     = strip_tags($new_instance["time_more_mins"]);
			$instance["time_1_hour"]        = strip_tags($new_instance["time_1_hour"]);
			$instance["time_2_hours"]       = strip_tags($new_instance["time_2_hours"]);
			$instance["time_precise_hours"] = strip_tags($new_instance["time_precise_hours"]);
			$instance["time_1_day"]         = strip_tags($new_instance["time_1_day"]);
			$instance["time_2_days"]        = strip_tags($new_instance["time_2_days"]);
			$instance["time_many_days"]     = strip_tags($new_instance["time_many_days"]);
			$instance["time_no_recent"]     = strip_tags($new_instance["time_no_recent"]);

			return $instance;
		}

		// Output admin form for updating the widget
		public function form($instance) {
			// Set up some default widget settings
			$defaults = array("title"              => "My Tweets",
							  "usernames"          => THINKTWIT_USERNAMES,
							  "hashtags"           => THINKTWIT_HASHTAGS,
							  "username_suffix"    => THINKTWIT_USERNAME_SUFFIX,
							  "limit"              => THINKTWIT_LIMIT,
							  "max_days"           => THINKTWIT_MAX_DAYS,
							  "update_frequency"   => THINKTWIT_UPDATE_FREQUENCY,
							  "show_username"      => THINKTWIT_SHOW_USERNAME,
							  "show_avatar"        => THINKTWIT_SHOW_AVATAR,
							  "show_published"     => THINKTWIT_SHOW_PUBLISHED,
							  "show_follow"        => THINKTWIT_SHOW_FOLLOW,
							  "links_new_window"   => THINKTWIT_LINKS_NEW_WINDOW,
							  "no_cache"           => THINKTWIT_NO_CACHE,
							  "use_curl"           => THINKTWIT_USE_CURL,
							  "debug"              => THINKTWIT_DEBUG,
							  "time_this_happened" => THINKTWIT_TIME_THIS_HAPPENED,
							  "time_less_min"      => THINKTWIT_TIME_LESS_MIN,
							  "time_min"           => THINKTWIT_TIME_MIN,
							  "time_more_mins"     => THINKTWIT_TIME_MORE_MINS,
							  "time_1_hour"        => THINKTWIT_TIME_1_HOUR,
							  "time_2_hours"       => THINKTWIT_TIME_2_HOURS,
							  "time_precise_hours" => THINKTWIT_TIME_PRECISE_HOURS,
							  "time_1_day"         => THINKTWIT_TIME_1_DAY,
							  "time_2_days"        => THINKTWIT_TIME_2_DAYS,
							  "time_many_days"     => THINKTWIT_TIME_MANY_DAYS,
							  "time_no_recent"     => THINKTWIT_TIME_NO_RECENT
							 );
							 
			$instance = wp_parse_args((array) $instance, $defaults);

		?>
			<div class="accordion">
				<h3 class="head" style="background: #F1F1F1 url(images/arrows.png) no-repeat right 4px; padding: 4px; border: 1px solid #DFDFDF;"><?php _e("General Settings", 'thinktwit'); ?></h3>
				<div>
					<p><label for="<?php echo $this->get_field_id("title"); ?>"><?php _e("Title:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("title"); ?>" name="<?php echo $this->get_field_name("title"); ?>" type="text" value="<?php echo $instance["title"]; ?>" /></label></p>

					<p><label for="<?php echo $this->get_field_id("usernames"); ?>"><?php _e("Twitter usernames (optional) separated by spaces:", 'thinktwit'); ?> <textarea rows="4" cols="40" class="widefat" id="<?php echo $this->get_field_id("usernames"); ?>" name="<?php echo $this->get_field_name("usernames"); ?>"><?php echo $instance["usernames"]; ?></textarea></label></p>

					<p><label for="<?php echo $this->get_field_id("hashtags"); ?>"><?php _e("Twitter hashtags/keywords (optional) separated by spaces:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("hashtags"); ?>" name="<?php echo $this->get_field_name("hashtags"); ?>"  type="text" value="<?php echo $instance["hashtags"]; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("username_suffix"); ?>"><?php _e("Username suffix (e.g. \" said \"):", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("username_suffix"); ?>" name="<?php echo $this->get_field_name("username_suffix"); ?>" type="text" value="<?php echo $instance["username_suffix"]; ?>" /></label></p>

					<p><label for="<?php echo $this->get_field_id("limit"); ?>"><?php _e("Max tweets to display:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("limit"); ?>" name="<?php echo $this->get_field_name("limit"); ?>" type="text" value="<?php echo $instance["limit"]; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("max_days"); ?>"><?php _e("Max days to display:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("max_days"); ?>" name="<?php echo $this->get_field_name("max_days"); ?>" type="text" value="<?php echo $instance["max_days"]; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("update_frequency"); ?>"><?php _e("Update frequency:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("update_frequency"); ?>" name="<?php echo $this->get_field_name("update_frequency"); ?>" class="widefat">
						<option value="-1" <?php if (strcmp($instance["update_frequency"], -1) == 0) echo " selected=\"selected\""; ?>><?php _e("Live (uncached)", 'thinktwit'); ?></option>
						<option value="0" <?php if (strcmp($instance["update_frequency"], 0) == 0) echo " selected=\"selected\""; ?>><?php _e("Live (cached)", 'thinktwit'); ?></option>
						<option value="1" <?php if (strcmp($instance["update_frequency"], 1) == 0) echo " selected=\"selected\""; ?>><?php _e("Hourly", 'thinktwit'); ?></option>
						<option value="2" <?php if (strcmp($instance["update_frequency"], 2) == 0) echo " selected=\"selected\""; ?>><?php _e("Every 2 hours", 'thinktwit'); ?></option>
						<option value="4" <?php if (strcmp($instance["update_frequency"], 4) == 0) echo " selected=\"selected\""; ?>><?php _e("Every 4 hours", 'thinktwit'); ?></option>
						<option value="12" <?php if (strcmp($instance["update_frequency"], 12) == 0) echo " selected=\"selected\""; ?>><?php _e("Every 12 hours", 'thinktwit'); ?></option>
						<option value="24" <?php if (strcmp($instance["update_frequency"], 24) == 0) echo " selected=\"selected\""; ?>><?php _e("Every day", 'thinktwit'); ?></option>
						<option value="48" <?php if (strcmp($instance["update_frequency"], 48) == 0) echo " selected=\"selected\""; ?>><?php _e("Every 2 days", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("show_username"); ?>"><?php _e("Show username:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("show_username"); ?>" name="<?php echo $this->get_field_name("show_username"); ?>" class="widefat">
						<option value="none" <?php if (strcmp($instance["show_username"], "none") == 0) echo " selected=\"selected\""; ?>><?php _e("None", 'thinktwit'); ?></option>
						<option value="name" <?php if (strcmp($instance["show_username"], "name") == 0) echo " selected=\"selected\""; ?>><?php _e("Name", 'thinktwit'); ?></option>
						<option value="username" <?php if (strcmp($instance["show_username"], "username") == 0) echo " selected=\"selected\""; ?>><?php _e("Username", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("show_avatar"); ?>"><?php _e("Show username's avatar:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("show_avatar"); ?>" name="<?php echo $this->get_field_name("show_avatar"); ?>" class="widefat">
						<option <?php if ($instance["show_avatar"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["show_avatar"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("show_published"); ?>"><?php _e("Show when published:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("show_published"); ?>" name="<?php echo $this->get_field_name("show_published"); ?>" class="widefat">
						<option <?php if ($instance["show_published"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["show_published"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("show_follow"); ?>"><?php _e("Show 'Follow @username' links:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("show_follow"); ?>" name="<?php echo $this->get_field_name("show_follow"); ?>" class="widefat">
						<option <?php if ($instance["show_follow"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["show_follow"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("links_new_window"); ?>"><?php _e("Open links in new window:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("links_new_window"); ?>" name="<?php echo $this->get_field_name("links_new_window"); ?>" class="widefat">
						<option <?php if ($instance["links_new_window"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["links_new_window"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("no_cache"); ?>"><?php _e("Prevent caching e.g. by WP Super Cache:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("no_cache"); ?>" name="<?php echo $this->get_field_name("no_cache"); ?>" class="widefat">
						<option <?php if ($instance["no_cache"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["no_cache"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("use_curl"); ?>"><?php _e("Use CURL for accessing Twitter API (set yes if getting `URL file-access` errors):", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("use_curl"); ?>" name="<?php echo $this->get_field_name("use_curl"); ?>" class="widefat">
						<option <?php if ($instance["use_curl"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["use_curl"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>

					<p><label for="<?php echo $this->get_field_id("debug"); ?>"><?php _e("Output debug messages:", 'thinktwit'); ?> <select id="<?php echo $this->get_field_id("debug"); ?>" name="<?php echo $this->get_field_name("debug"); ?>" class="widefat">
						<option <?php if ($instance["debug"] == 1) echo "selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
						<option <?php if ($instance["debug"] == 0) echo "selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
					</select></label></p>
				</div>
			</div>
			
			<div class="accordion">
				<h3 class="head" style="background: #F1F1F1 url(images/arrows.png) no-repeat right 4px; padding: 4px; border: 1px solid #DFDFDF;"><?php _e("Time Messages", 'thinktwit'); ?></h3>
				<div>
					<p><?php _e("NOTE: The editing of these messages is optional.", 'thinktwit'); ?></p>
					
					<p><label for="<?php echo $this->get_field_id("time_this_happened"); ?>"><?php _e("Time prefix:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_this_happened"); ?>" name="<?php echo $this->get_field_name("time_this_happened"); ?>" type="text" value="<?php echo $instance['time_this_happened']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_less_min"); ?>"><?php _e("Less than 59 seconds ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_less_min"); ?>" name="<?php echo $this->get_field_name("time_less_min"); ?>" type="text" value="<?php echo $instance['time_less_min']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_min"); ?>"><?php _e("Less than 1 minute 59 seconds ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_min"); ?>" name="<?php echo $this->get_field_name("time_min"); ?>" type="text" value="<?php echo $instance['time_min']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_more_mins"); ?>"><?php _e("Less than 50 minutes ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_more_mins"); ?>" name="<?php echo $this->get_field_name("time_more_mins"); ?>" type="text" value="<?php echo $instance['time_more_mins']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_1_hour"); ?>"><?php _e("Less than 89 minutes ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_1_hour"); ?>" name="<?php echo $this->get_field_name("time_1_hour"); ?>" type="text" value="<?php echo $instance['time_1_hour']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_2_hours"); ?>"><?php _e("Less than 150 minutes ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_2_hours"); ?>" name="<?php echo $this->get_field_name("time_2_hours"); ?>" type="text" value="<?php echo $instance['time_2_hours']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_precise_hours"); ?>"><?php _e("Less than 23 hours ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_precise_hours"); ?>" name="<?php echo $this->get_field_name("time_precise_hours"); ?>" type="text" value="<?php echo $instance['time_precise_hours']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_1_day"); ?>"><?php _e("Less than 36 hours:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_1_day"); ?>" name="<?php echo $this->get_field_name("time_1_day"); ?>" type="text" value="<?php echo $instance['time_1_day']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_2_days"); ?>"><?php _e("Less than 48 hours ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_2_days"); ?>" name="<?php echo $this->get_field_name("time_2_days"); ?>" type="text" value="<?php echo $instance['time_2_days']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_many_days"); ?>"><?php _e("More than 48 hours ago:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_many_days"); ?>" name="<?php echo $this->get_field_name("time_many_days"); ?>" type="text" value="<?php echo $instance['time_many_days']; ?>" /></label></p>
					
					<p><label for="<?php echo $this->get_field_id("time_no_recent"); ?>"><?php _e("No recent tweets:", 'thinktwit'); ?> <input class="widefat" id="<?php echo $this->get_field_id("time_no_recent"); ?>" name="<?php echo $this->get_field_name("time_no_recent"); ?>" type="text" value="<?php echo $instance['time_no_recent']; ?>" /></label></p>
				</div>
			</div>
			
			<h3><?php _e("Support Development", 'thinktwit'); ?></h3>
			
			<p><?php _e("If you would like to support development of ThinkTwit donations are gratefully accepted:", 'thinktwit'); ?></p>
			<p style="text-align:center"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=B693F67QHAT8E" target="_blank"><img src="https://www.paypalobjects.com/en_US/GB/i/btn/btn_donateCC_LG.gif" alt="<?php _e("PayPal - The safer, easier way to pay online.", 'thinktwit'); ?>" /></a><img src="https://www.paypalobjects.com/en_GB/i/scr/pixel.gif" alt="" width="1" height="1" border="0" /></p>
			<p><a id="widget-thinktwit-<?php $id = explode("-", $this->get_field_id("widget_id")); echo $id[2]; ?>-reset_settings" href="#"><?php _e("Reset Settings", 'thinktwit'); ?></a></p>
				
			<script type="text/javascript">
				jQuery(document).ready(function($) {
					// Add accordion functionality
					$('div[id$="thinktwit-<?php echo $id[2]; ?>"] .accordion .head').click(function() {
						$(this).next().toggle('slow');
						return false;
					}).next().hide();
					
					// When reset_settings loads add the onclick function
					$("#widget-thinktwit-<?php echo $id[2]; ?>-reset_settings").live("click", function() {					  
						// Reset all of the values to their default
						$("#widget-thinktwit-<?php echo $id[2]; ?>-usernames").val("<?php echo THINKTWIT_USERNAMES; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-hashtags").val("<?php echo THINKTWIT_HASHTAGS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-username_suffix").val("<?php echo THINKTWIT_USERNAME_SUFFIX; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-limit").val("<?php echo THINKTWIT_LIMIT; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-max_days").val("<?php echo THINKTWIT_MAX_DAYS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-update_frequency").val("<?php echo THINKTWIT_UPDATE_FREQUENCY; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-show_username").val("<?php echo THINKTWIT_SHOW_USERNAME; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-show_avatar").val("<?php echo (THINKTWIT_SHOW_AVATAR ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-show_published").val("<?php echo (THINKTWIT_SHOW_PUBLISHED ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-show_follow").val("<?php echo (THINKTWIT_SHOW_FOLLOW ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-links_new_window").val("<?php echo (THINKTWIT_LINKS_NEW_WINDOW ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-no_cache").val("<?php echo (THINKTWIT_NO_CACHE ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-use_curl").val("<?php echo (THINKTWIT_USE_CURL ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-debug").val("<?php echo (THINKTWIT_DEBUG ? "Yes" : "No"); ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_this_happened").val("<?php echo THINKTWIT_TIME_THIS_HAPPENED; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_less_min").val("<?php echo THINKTWIT_TIME_LESS_MIN; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_min").val("<?php echo THINKTWIT_TIME_MIN; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_more_mins").val("<?php echo THINKTWIT_TIME_MORE_MINS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_1_hour").val("<?php echo THINKTWIT_TIME_1_HOUR; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_2_hours").val("<?php echo THINKTWIT_TIME_2_HOURS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_precise_hours").val("<?php echo THINKTWIT_TIME_PRECISE_HOURS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_1_day").val("<?php echo THINKTWIT_TIME_1_DAY; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_2_days").val("<?php echo THINKTWIT_TIME_2_DAYS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_many_days").val("<?php echo THINKTWIT_TIME_MANY_DAYS; ?>");
						$("#widget-thinktwit-<?php echo $id[2]; ?>-time_no_recent").val("<?php echo THINKTWIT_TIME_NO_RECENT; ?>");
						
						// Focus on the usernames
						$("#widget-thinktwit-<?php echo $id[2]; ?>-usernames").focus();
					
						// Return false so that the standard click function doesn't occur (i.e. navigating to #)
						return false;
					});
				});
			</script>
		<?php
		}
		
		// Displays the main admin options
		public static function admin_page() {
?>
			<div class="wrap">
				<?php screen_icon(); ?>
				<h2><?php _e("ThinkTwit Settings", 'thinktwit'); ?></h2>
				<form method="post" action="options.php">
					<?php settings_fields("thinktwit_options"); ?>
					<?php do_settings_sections("thinktwit"); ?>
					<?php submit_button(); ?>
				</form>
			</div>
<?php
		}
		
		// Initialise the admin page
		public static function admin_page_init() {
			// Add settings that we are going to store (these are strictly used other than to pass info as we save in options during sanitisation)
			register_setting('thinktwit_options', 'twitter_api_settings', 'ThinkTwit::check_admin_settings');
			
			// Add sections to the page
			add_settings_section(
				"general_settings",
				__("General Settings", 'thinktwit'),
				"ThinkTwit::admin_page_general_section_info",
				"thinktwit"
			);
			
			add_settings_field(
				"cleanup_period", 
				__("Cleanup period", 'thinktwit'), 
				"ThinkTwit::create_admin_page_cleanup_field", 
				"thinktwit",
				"general_settings"			
			);
			
			add_settings_field(
				"use_default_style", 
				__("Use default stylesheet", 'thinktwit'), 
				"ThinkTwit::create_admin_page_use_default_style_field", 
				"thinktwit",
				"general_settings"			
			);
			
			add_settings_section(
				"twitter_api_settings",
				__("Twitter API Settings", 'thinktwit'),
				"ThinkTwit::admin_page_twitter_section_info",
				"thinktwit"
			);

			// Add settings to the section
			add_settings_field(
				"consumer_key", 
				__("Consumer key", 'thinktwit'), 
				"ThinkTwit::create_admin_page_key_field", 
				"thinktwit",
				"twitter_api_settings"			
			);
			
			add_settings_field(
				"consumer_secret", 
				__("Consumer secret", 'thinktwit'), 
				"ThinkTwit::create_admin_page_secret_field", 
				"thinktwit",
				"twitter_api_settings"			
			);
		}
		
		// General section message for the admin page
		public static function admin_page_general_section_info() {
			// Get our widget settings
			$settings = get_option("widget_thinktwit_settings");
			
			// If settings isn't an array
			if (!is_array($settings)) {
				$version = ThinkTwit::get_version();
				$cache_names = __("none", 'thinktwit');
				$updated = __("never", 'thinktwit');
				$last_cleanup = __("never", 'thinktwit');
			} else { // Otherwise get the stored values after checking they are set
				// If the version is set then get it
				if (isset($settings["version"])) {
					$version = $settings["version"];
				} else {
					// Otherwise get the default value
					$version = ThinkTwit::get_version();
				}
				
				// If the cached names are available then get them
				if (isset($settings["cache_names"])) {
					$cache_names = implode("<br />", $settings["cache_names"]);
				} else {
					// Otherwise set to none
					$cache_names = __("none", 'thinktwit');
				}
				
				// If the last cleanup date is not never then format it appropriately
				if (isset($settings["last_cleanup"]) && (strcmp($settings["last_cleanup"], __("never", 'thinktwit')) != 0)) {
					// Format the timestamps correctly
					$last_cleanup = date('D F jS, Y H:i:s', $settings["last_cleanup"]);
				} else {
					// Otherwise set to never
					$last_cleanup = __("never", 'thinktwit');
				}
				
				// If the last updated date is not never then format it appropriately
				if (isset($settings["updated"]) && (strcmp($settings["updated"], __("never", 'thinktwit')) != 0)) {
					// Separate the Unix timestamp for easier disection
					list($microSec, $timeStamp) = explode(" ", $settings["updated"]);
				
					// Format the timestamps correctly
					$updated = date('D F jS, Y H:i:', $timeStamp) . (date('s', $timeStamp) + $microSec);
				} else {
					// Otherwise set to never
					$updated = __("never", 'thinktwit');
				}
			}
			
			echo "<p>" . __("The following static values are for information only:", 'thinktwit') . "</p>";
			echo "<table class=\"form-table\"><tbody><tr valign=\"top\"><th scope=\"row\">" . __("Version", 'thinktwit') . "</th><td>$version</td></tr>";
			echo "<tr valign=\"top\"><th scope=\"row\">" . __("Cache names", 'thinktwit') . "</th><td>$cache_names</td></tr>";
			echo "<tr valign=\"top\"><th scope=\"row\">" . __("Last updated", 'thinktwit') . "</th><td>$updated</td></tr>";
			echo "<tr valign=\"top\"><th scope=\"row\">" . __("Last cleanup", 'thinktwit') . "</th><td>$last_cleanup</td></tr>";
			echo "</tbody></table>";
		}
		
		// Twitter section message for the admin page
		public static function admin_page_twitter_section_info() {
			echo "<p>" . __("Enter your Twitter Application authentication settings below:", 'thinktwit') . "</p>";
		}
		
		// Checks the settings that are returned and stores the values in our options rather than using Settings API as intended
		public static function check_admin_settings($input) {
			// Get our widget settings
			$settings = get_option("widget_thinktwit_settings");
			$val = "";
			
			// If settings isn't an array
			if (!is_array($settings)) {
				// Create an array
				$settings = array();
				
				$settings["version"] = ThinkTwit::get_version();
				$settings["cache_names"] = array();
				$settings["updated"] = __("never", 'thinktwit');
				$settings["last_cleanup"] = __("never", 'thinktwit');
				
				// Create the array with the minimum required values including the consumer key
				if ($input["consumer_key"] != "") {
					$val = $input["consumer_key"];
					$settings["consumer_key"] = $input["consumer_key"];
				} else {
					$val = "";
					$settings["consumer_key"] = "";
				}
				
				// Create the array with the minimum required values including the consumer secret
				if ($input["consumer_secret"] != "") {
					$val = $input["consumer_secret"];
					$settings["consumer_secret"] = $input["consumer_secret"];
				} else {
					$val = "";
					$settings["consumer_secret"] = "";
				}
				
				// Create the array with the minimum required values including the cleanup period
				if ($input["cleanup_period"] != "") {
					$val = $input["cleanup_period"];
					$settings["cleanup_period"] = $input["cleanup_period"];
				} else {
					$val = "30";
					$settings["cleanup_period"] = "30";
				}
				
				// Create the array with the minimum required values including whether to use the default stylesheet
				if ($input["use_default_style"] != "") {
					$val = $input["use_default_style"];
					$settings["use_default_style"] = $input["use_default_style"];
				} else {
					$val = "1";
					$settings["use_default_style"] = "1";
				}
			} else {
				// Add the consumer key
				if ($input["consumer_key"] != "") {
					$val = $input["consumer_key"];
					$settings["consumer_key"] = $input["consumer_key"];
				}
				
				// Add the consumer secret
				if ($input["consumer_secret"] != "") {
					$val = $input["consumer_secret"];
					$settings["consumer_secret"] = $input["consumer_secret"];
				}
				
				// Add the cleanup period
				if ($input["cleanup_period"] != "") {
					$val = $input["cleanup_period"];
					$settings["cleanup_period"] = $input["cleanup_period"];
				}
				
				// Add the selected default style option
				if ($input["use_default_style"] != "") {
					$val = $input["use_default_style"];
					$settings["use_default_style"] = $input["use_default_style"];
				}
			}
				
			// Store our options
			update_option("widget_thinktwit_settings", $settings);
			
			// Return the value that was used
			return $val;
		}
		
		// Creates the consumer key field
		public static function create_admin_page_key_field() {
			// Get our options
			$settings = get_option("widget_thinktwit_settings");
			$consumer_key = "";
			
			// If settings isn't an array
			if (is_array($settings) && isset($settings["consumer_key"])) {
				$consumer_key = $settings["consumer_key"];
			}
?>
			<input type="text" id="consumer_key" name="twitter_api_settings[consumer_key]" value="<?= $consumer_key; ?>" size="30" />
<?php
		}
		
		// Creates the consumer secret field
		public static function create_admin_page_secret_field() {
			// Get our options
			$settings = get_option("widget_thinktwit_settings");
			$consumer_secret = "";
			
			// If settings isn't an array
			if (is_array($settings) && isset($settings["consumer_secret"])) {
				$consumer_secret = $settings["consumer_secret"];
			}
		?>
			<input type="text" id="consumer_secret" name="twitter_api_settings[consumer_secret]" value="<?= $consumer_secret; ?>" size="60" />
<?php
		}
		
		// Creates the cleanup field
		public static function create_admin_page_cleanup_field() {
			// Get our options
			$settings = get_option("widget_thinktwit_settings");
			$cleanup_period = "";
			
			// If settings isn't an array
			if (is_array($settings) && isset($settings["cleanup_period"])) {
				$cleanup_period = $settings["cleanup_period"];
			}
		?>
			<select id="cleanup_period" name="twitter_api_settings[cleanup_period]">
				<option value="1" <?php if (strcmp($cleanup_period, 1) == 0)     echo " selected=\"selected\""; ?>><?php _e("Daily", 'thinktwit'); ?></option>
				<option value="7" <?php if (strcmp($cleanup_period, 7) == 0)     echo " selected=\"selected\""; ?>><?php _e("Weekly", 'thinktwit'); ?></option>
				<option value="14" <?php if (strcmp($cleanup_period, 14) == 0)   echo " selected=\"selected\""; ?>><?php _e("Fortnightly", 'thinktwit'); ?></option>
				<option value="30" <?php if (strcmp($cleanup_period, 30) == 0 || 
				                             empty($cleanup_period))             echo " selected=\"selected\""; ?>><?php _e("Monthly", 'thinktwit'); ?></option>
				<option value="91" <?php if (strcmp($cleanup_period, 91) == 0)   echo " selected=\"selected\""; ?>><?php _e("Quarterly", 'thinktwit'); ?></option>
				<option value="182" <?php if (strcmp($cleanup_period, 182) == 0) echo " selected=\"selected\""; ?>><?php _e("Bi-annually", 'thinktwit'); ?></option>
				<option value="365" <?php if (strcmp($cleanup_period, 365) == 0) echo " selected=\"selected\""; ?>><?php _e("Annually", 'thinktwit'); ?></option>
			</select>
<?php
		}
		
		// Creates the use default style field
		public static function create_admin_page_use_default_style_field() {
			// Get our options
			$settings = get_option("widget_thinktwit_settings");
			$use_default_style = "";
			
			// If settings isn't an array
			if (is_array($settings) && isset($settings["use_default_style"])) {
				$use_default_style = $settings["use_default_style"];
			}
		?>
			<select id="use_default_style" name="twitter_api_settings[use_default_style]">
				<option value="1" <?php if (strcmp($use_default_style, 1) == 0) echo " selected=\"selected\""; ?>><?php _e("Yes", 'thinktwit'); ?></option>
				<option value="0" <?php if (strcmp($use_default_style, 0) == 0) echo " selected=\"selected\""; ?>><?php _e("No", 'thinktwit'); ?></option>
			</select>
<?php
		}

		// Function that will add a menu option for admin users
		public static function admin_menu() {
			// Add main menu option after Dashboard
			add_options_page('ThinkTwit', 'ThinkTwit', 'administrator', 'thinktwit', 'ThinkTwit::admin_page');
		}
					
		// Function for handling AJAX requests
		public static function ajax_request_handler() {
			// Check that all parameters have been passed
			if ((isset($_GET["thinktwit_request"]) && ($_GET["thinktwit_request"] == "parse_feed")) && isset($_GET["thinktwit_widget_id"]) && 
			  isset($_GET["thinktwit_usernames"]) && isset($_GET["thinktwit_hashtags"]) && isset($_GET["thinktwit_username_suffix"]) && 
			  isset($_GET["thinktwit_limit"]) && isset($_GET["thinktwit_max_days"]) && isset($_GET["thinktwit_update_frequency"]) && 
			  isset($_GET["thinktwit_show_username"]) && isset($_GET["thinktwit_show_published"]) && isset($_GET["thinktwit_show_follow"]) && 
			  isset($_GET["thinktwit_links_new_window"]) && isset($_GET["thinktwit_no_cache"]) && isset($_GET["thinktwit_use_curl"]) && 
			  isset($_GET["thinktwit_debug"]) && isset($_GET["thinktwit_time_this_happened"]) && isset($_GET["thinktwit_time_less_min"]) && 
			  isset($_GET["thinktwit_time_min"]) && isset($_GET["thinktwit_time_more_mins"]) && isset($_GET["thinktwit_time_1_hour"]) && 
			  isset($_GET["thinktwit_time_2_hours"]) && isset($_GET["thinktwit_time_precise_hours"]) && isset($_GET["thinktwit_time_1_day"]) && 
			  isset($_GET["thinktwit_time_2_days"]) && isset($_GET["thinktwit_time_many_days"]) && isset($_GET["thinktwit_time_no_recent"])) {
			  
				// Create an array to contain the time settings
				$time_settings = array(11);

				$time_settings[0] = strip_tags($_GET["thinktwit_time_this_happened"]);
				$time_settings[1] = strip_tags($_GET["thinktwit_time_less_min"]);
				$time_settings[2] = strip_tags($_GET["thinktwit_time_min"]);
				$time_settings[3] = strip_tags($_GET["thinktwit_time_more_mins"]);
				$time_settings[4] = strip_tags($_GET["thinktwit_time_1_hour"]);
				$time_settings[5] = strip_tags($_GET["thinktwit_time_2_hours"]);
				$time_settings[6] = strip_tags($_GET["thinktwit_time_precise_hours"]);
				$time_settings[7] = strip_tags($_GET["thinktwit_time_1_day"]);
				$time_settings[8] = strip_tags($_GET["thinktwit_time_2_days"]);
				$time_settings[9] = strip_tags($_GET["thinktwit_time_many_days"]);
				$time_settings[10] = strip_tags($_GET["thinktwit_time_no_recent"]);
	
			  
				// Output the feed and exit the call
				echo ThinkTwit::parse_feed(strip_tags($_GET["thinktwit_widget_id"]), strip_tags($_GET["thinktwit_usernames"]), strip_tags($_GET["thinktwit_hashtags"]), 
				  strip_tags($_GET["thinktwit_username_suffix"]), strip_tags($_GET["thinktwit_limit"]), strip_tags($_GET["thinktwit_max_days"]), 
				  strip_tags($_GET["thinktwit_update_frequency"]), strip_tags($_GET["thinktwit_show_username"]), strip_tags($_GET["thinktwit_show_avatar"]), 
				  strip_tags($_GET["thinktwit_show_published"]), strip_tags($_GET["thinktwit_show_follow"]), strip_tags($_GET["thinktwit_links_new_window"]), 
				  strip_tags($_GET["thinktwit_no_cache"]), strip_tags($_GET["thinktwit_use_curl"]), strip_tags($_GET["thinktwit_debug"]), $time_settings);

				exit();
			} elseif (isset($_GET["thinktwit_request"]) && ($_GET["thinktwit_request"] == "parse_feed")) {
				// Otherwise display an error and exit the call
				echo "<p class=\"thinkTwitError\">" . _e("Error: Unable to display tweets.", 'thinktwit') . "</p>";
				
				exit();
			}
		}
		
		// Looks in the downloaded file for a Twitter message that says the request was redirected, if found returns the URL to use instead
		private static function check_avatar_for_redirect($location) {
			// Get the file
			$file = file_get_contents($location);
			
			// First of all look for the redirect
			if (strpos($file, "redirected")) {
				// We have found a redirect, so next look for the URL between double quotes
				if (preg_match('/"([^"]+)"/', $str, $m)) {
					// If we find a match (we should) then return the URL
					return $m[1]; 
				}
			}
			
			return false;
		}
		
		// Converts Twitter content to links e.g. @username, #hashtag, http://url
		// TODO remove colon from @names, don't turn links containing "..." in to actual links, if a tweet does contain "..." then use 
		// statuses/show/:id to get it (https://dev.twitter.com/docs/api/1.1/get/statuses/show/%3Aid) and if # contains anything other 
		// than \w+ then exclude
		private static function convert_twitter_content_to_links($string) {
			// Separate all "words" in to an array so that we can process each individually
			$content_array = explode(" ", $string);
			$output = "";
			
			// Loop through the array of "words"
			foreach($content_array as $content) {
				// If we find http
				if(substr($content, 0, 7) == "http://") {
					$content = "<a href=\"" . $content . "\">" . $content . "</a>";
				}
				
				// If we find https
				if(substr($content, 0, 8) == "https://") {
					$content = "<a href=\"" . $content . "\">" . $content . "</a>";
				}

				// If we find www
				if(substr($content, 0, 4) == "www.") {
					$content = "<a href=\"http://" . $content . "\">" . $content . "</a>";
				}
				
				// If we find @username
				if(substr($content, 0, 1) == "@") {
					$content = "<a href=\"http://twitter.com/" . $content . "\">" . $content . "</a>";
				}
				
				// If we find #hashtag
				if(substr($content, 0, 1) == "#") {
					$content = "<a href=\"http://twitter.com/search/?src=hash&q=%23" . substr($content, 1) . "\">" . $content . "</a>";
				}
				
				// Reinsert spaces that have been removed
				$output .= " " . $content;
			}

			// Trim the output so that we don't have unnecessary spaces
			$output = trim($output);
			
			return $output;
		}
		
		// Deletes all unused avatars from tweets that are no longer valid (due to age or no longer located within a search)
		private static function delete_unused_avatars($allowed_usernames) {			
			// Get the directory where the images are stored
			$dir = plugin_dir_path( __FILE__ ) . 'images/';
			
			// NOTE: This code doesn't work if the owner of the file is different to the user of the running process
			// Get a listing of the images directory
			if ($handle = opendir($dir)) {
				// Iterate through the listing
				while (false !== ($entry = readdir($handle))) {
					// Ignore . and .., and make sure that we are dealing with a png, jpg or gif
					if ($entry != "." && $entry != ".." && (strpos($entry, ".png") || strpos($entry, ".jpg") || strpos($entry, ".gif"))) {
						// Look for the last fullstop in the filename so that we can get the username
						$fullstop = strrpos($entry, ".");

						// If there is no fullstop then we don't want to process any further (this shouldn't ever happen)
						if ($fullstop !== FALSE) {
							// Get filename but ignore the extension
							$username = substr($entry, 0, $fullstop);

							// If the filename is not in $allowed_usernames
							if (!in_array($username, $allowed_usernames)) {
								// If the file exists
								if (file_exists($dir . $entry)) {
									// First of all make it fully writeable to ensure we can delete it
									@chmod($dir . $entry, 0755);
									
									// Then delete it
									@unlink($dir . $entry);
								}
							}
						}
					}
				}
				
				// Close the directory stream
				closedir($handle);
			}
		}
		
		// Downloads the avatar for the given username, using CURL if specified
		private static function download_avatar($use_curl, $username, $image_url) {	
			// Get image MIME type
			$mime = ThinkTwit::get_image_mime_type($image_url);
			
			// Store the filename
			$filename = $username . $mime;
			$dir = plugin_dir_path(__FILE__) . 'images/';
			
			// First of all check if the folder exists
			if (!file_exists($dir)) {
				// If it doesn't then create it with write permissions
				mkdir($dir, 0755);
			} else {
				// And if it exists then check it is writeable
				if (!is_writable($dir)) {
					// If it isn't writeable then make it writeable
					@chmod($dir, 0755);
				}
			}
			
			while ($image_url) {
				// If file doesn't exist or file is older than 24 hours
				if (!file_exists($dir . $filename) || time() - filemtime(realpath($dir . $filename)) >= (60 * 60 * 24)) {
					// Download and save the image using CURL or file_put_contents
					if ($use_curl) {
						// Initiate a CURL object and open the image URL
						$ch = curl_init($image_url);
						
						// Open file location to save in using write binary mode
						$fp = fopen($dir . $filename, 'wb');
						
						// Set to return a file, to write in to fp
						curl_setopt($ch, CURLOPT_FILE, $fp);
						
						// Set to not include the header in the output
						curl_setopt($ch, CURLOPT_HEADER, 0);
						
						// Execute the call
						curl_exec($ch);
						
						// Close the CURL object
						curl_close($ch);
						
						// Close the file object
						fclose($fp);
					} else {
						// Download the file without CURL
						file_put_contents($dir . $filename, file_get_contents(htmlspecialchars($image_url)));
					}
					
					// Change the ownership of the file so it can be later deleted
					@chmod($dir . $filename, 0755);
				}
				
				// Check the contents for a redirect (this should return false and break the loop once it has a working file)
				$image_url = ThinkTwit::check_avatar_for_redirect($dir . $filename);
			}
			
			return $filename;
		}
		
		// Searches all of the caches for allowed usersnames and returns them
		private static function get_allowed_usernames() {
			$allowed_usernames = array();
			
			// Get our widget settings
			$settings = get_option("widget_thinktwit_settings");
			
			// Get the caches
			$cache_names = $settings["cache_names"];
			
			// Iterate each cache
			foreach($cache_names as $cache_name) {
				// Explode the cache name to get the id
				$cache_name_parts = explode("_", $cache_name);
				
				// Get the tweets from the current cache (the second part of the cache name is the widget id)
				$returned_tweets = ThinkTwit::get_tweets_from_cache($cache_name_parts[1]);
				
				// Ensure the database contained tweets
				if ($returned_tweets != FALSE) {
					// Get the tweets from the last update
					$tweets = $returned_tweets[0];
					
					// Iterate each tweet
					foreach($tweets as $tweet) {
						// Check that the tweet has a username
						if ($tweet->getUsername()) {
							// Add the tweet's username to the usernames array
							$allowed_usernames[] = $tweet->getUsername();
						}
					}
				}
			}
			
			// Remove duplicates
			$allowed_usernames = array_unique($allowed_usernames);
					
			return $allowed_usernames;
		}
		
		// Returns the MIME type (jpeg, png or gif - only allowed by Twitter) of the image at the given URL
		private static function get_image_mime_type($url) {
			// Use getimagesize to get the MIME type
			$size = @getimagesize($url);
			
			// Return the corresponding file extension
			switch ($size['mime']) {
				case 'image/gif':
					return ".gif";
					
					break;
				case 'image/jpeg':
					return ".jpg";
					
					break;
				case 'image/png':
					return ".png";
					
					break;
				default:
					return ".jpg";
					
					break;
			}
		}

		// Returns an array of Tweets from the cache or from Twitter depending on state of cache
		private static function get_tweets($update_frequency, $url, $use_curl, $widget_id, $limit, $max_days, $usernames, $hashtags) {
			$tweets;

			// First check that if the user wants live updates
			if ($update_frequency == -1) {				
				// Empty the cache so that next time caching is turned on it gets them fresh
				$tweets = array();
				
				// Store updated array in cache
				ThinkTwit::update_cache($tweets, $widget_id);
				
				// If so then just get the tweets live from Twitter
				$tweets = ThinkTwit::get_tweets_from_twitter($url, $use_curl);
				
				// If necessary, shrink the array (limit minus 1 as we start array from zero)
				if (count($tweets) > $limit) {
					$tweets = ThinkTwit::trim_array($tweets, $limit);
				}
			} else {
				// Otherwise, get values from cache
				$last_update = ThinkTwit::get_tweets_from_cache($widget_id);
				
				// Ensure the database contained tweets
				if ($last_update != FALSE) {
					// Get the tweets from the last update
					$tweets = $last_update[0];
					
					// Get the time when the last update was cached
					$cachedTime = $last_update[1];
				} else {
					// If it didn't then create an empty array
					$tweets = array();
					
					// And store the time as zero (so it always updates)
					$cachedTime = 0;
				}
				
				// Get the difference between now and when the cache was last updated
				$diff = time() - $cachedTime;
		
				// If update is required (the number of hours since last update,
				// calculated by dividing by 60 to get mins and 60 again to get hours)
				if (($diff / 3600) > $update_frequency) {
					// Get tweets fresh from Twitter
					$fresh_tweets = ThinkTwit::get_tweets_from_twitter($url, $use_curl);
					
					// Merge all the tweets together
					$tweets = ThinkTwit::merge_tweets($tweets, $fresh_tweets);
					
					// Remove empty tweets
					$tweets = ThinkTwit::remove_empty_tweets($tweets);
					
					// Sort array by date
					ThinkTwit::sort_tweets($tweets);
					
					// Remove any tweets that are duplicates
					$tweets = ThinkTwit::remove_duplicates($tweets);
					
					// Remove any tweets that don't contain the selected usernames or hashtags
					$tweets = ThinkTwit::remove_incorrect_usernames_and_hashtags($tweets, $usernames, $hashtags);
					
					// If necessary, shrink the array (limit minus 1 as we start array from zero)
					if (count($tweets) > $limit) {
						$tweets = ThinkTwit::trim_array($tweets, $limit);
					}
					
					// Store updated array in cache
					ThinkTwit::update_cache($tweets, $widget_id);
				}
			}
			
			// Remove any tweets that are older than max days
			$tweets = ThinkTwit::remove_old_tweets($tweets, $max_days);
			
			return $tweets;
		}
		
		// Returns an array of Tweets from the cache, along with the time of the last update
		private static function get_tweets_from_cache($widget_id) {
			// Get the option from the cache
			$tweets = get_option("widget_" . $widget_id . "_cache");
			
			return $tweets;
		}

		// Returns an array of Tweets when given the URL to access and a boolean indicating whether to use CURL
		private static function get_tweets_from_twitter($url, $use_curl) {
			// Get our options
			$settings = get_option("widget_thinktwit_settings");
			$consumer_key = "";
			$consumer_secret = "";
			
			// If settings isn't an array and the consumer values are set then get them
			if (is_array($settings) && isset($settings['consumer_key']) && isset($settings['consumer_secret'])) {
				$consumer_key = $settings['consumer_key'];
				$consumer_secret = $settings['consumer_secret'];
			}
		
			// Get the Twitter access token
			$access_token = ThinkTwit::get_twitter_access_token($consumer_key, $consumer_secret, $use_curl);
			
			// If user wishes to use CURL
			if ($use_curl) {			
				// Set up the headers that will be used to make a call to the URL including the app name and the access token
				$headers = array( 
					"GET /oauth2/token HTTP/1.1", 
					"Host: api.twitter.com", 
					"User-Agent: ThinkTwit Twitter App v" . ThinkTwit::get_version(),
					"Authorization: Bearer " . $access_token,
					"Content-Type: application/x-www-form-urlencoded;charset=UTF-8", 
				); 
			
				// Initiate a CURL object
				$ch = curl_init();

				// Set the URL
				curl_setopt($ch, CURLOPT_URL, $url);
				
				// Set the headers we created
				curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
				
				// Set option to not receive the headers
				$header = curl_setopt($ch, CURLOPT_HEADER, 0);

				// Set to return a string
				curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

				// Set the timeout
				curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);

				// Execute the API call
				$feed = curl_exec($ch);

				// Close the CURL object
				curl_close($ch);
			} else {				
				// Create an options context that contains the headers used to make a call to the URL including the app name and the access token
				$context = stream_context_create(array('http' => array('header' => 'Authorization: Bearer ' . $access_token)));
			
				// Execute the API call using the created headers
				$feed = @file_get_contents($url, false, $context);
			}
			
			// Decode the JSON feed
			$json = json_decode($feed, true);
			
			// Create an array to store the tweets
			$tweets = array();

			// Get the tweets from the JSON feed (if any exist)
			if (isset($json["statuses"])) {
				$json_tweets = $json["statuses"];
				
				// Check that values were returned
				if (is_array($json_tweets)) {
					// Loop through the tweets
					foreach($json_tweets as $tweet) {
						// Get the content of the tweet
						$content = $tweet["text"];
						
						// Get the user details
						$user = $tweet["user"];
						
						// Make the content links clickable
						$content = ThinkTwit::convert_twitter_content_to_links($content);
						
						// Download the avatar and get the local filename
						$filename = ThinkTwit::download_avatar($use_curl, $user["screen_name"], $user["profile_image_url"]);
						
						// Create a tweet and add it to the array
						$tweets[] = new Tweet("http://twitter.com/" . $user["screen_name"], $filename, $user["profile_image_url"], $user["name"], $user["screen_name"], $content, strtotime($tweet["created_at"]));
					}
				}
			}
			
			return $tweets;
		}
		
		// Returns the access token, created from the given consumer key and consumer secret, that is required to 
		// make authenticated requests to API v1.1 (see https://dev.twitter.com/docs/api/1.1/post/oauth2/token)
		private static function get_twitter_access_token($consumer_key, $consumer_secret, $use_curl) {
			// Url encode the consumer_key and consumer_secret in accordance with RFC 1738
			$encoded_consumer_key = urlencode($consumer_key);
			$encoded_consumer_secret = urlencode($consumer_secret);
			
			// Concatenate encoded consumer, a colon character and the encoded consumer secret
			$bearer_token = $encoded_consumer_key . ':' . $encoded_consumer_secret;
			
			// Base64-encode bearer token
			$base64_encoded_bearer_token = base64_encode($bearer_token);
			
			// Twitter URL that authenticates bearer tokens
			$url = "https://api.twitter.com/oauth2/token/";
			
			if ($use_curl) {
				// Set up the headers that will be used to make a call to the URL including the app name and the encoded bearer token
				$headers = array( 
					"POST /oauth2/token HTTP/1.1", 
					"Host: api.twitter.com", 
					"User-Agent: ThinkTwit Twitter App v" . ThinkTwit::get_version(),
					"Authorization: Basic " . $base64_encoded_bearer_token,
					"Content-Type: application/x-www-form-urlencoded;charset=UTF-8", 
					"Content-Length: 29"
				);

				// Setup curl
				$ch = curl_init();
				
				// Set the URL
				curl_setopt($ch, CURLOPT_URL, $url); 
				
				// Set the headers we created
				curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
				
				// Set option to not receive the headers
				$header = curl_setopt($ch, CURLOPT_HEADER, 0);
				
				// Set to use a POST call
				curl_setopt($ch, CURLOPT_POST, 1);
				
				// Set the parameter to be sent (see 
				curl_setopt($ch, CURLOPT_POSTFIELDS, "grant_type=client_credentials");
				
				// Set to return a string
				curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
				
				// Execute the call
				$response = curl_exec($ch);
				
				// Close curl
				curl_close($ch);
			} else {				
				// Create an options context that contains the headers used to make a call to the URL including the app name and the access token
				$context = stream_context_create(array("http" => array("method" => "POST",
																	   "header" => "POST /oauth2/token HTTP/1.1\r\n" .
																				   "Host: api.twitter.com\r\n" .
																				   "User-Agent: ThinkTwit Twitter App v" . ThinkTwit::get_version() . "\r\n" .
																				   "Authorization: Basic " . $base64_encoded_bearer_token . "\r\n" .
																				   "Content-Type: application/x-www-form-urlencoded;charset=UTF-8\r\n" .
																				   "Content-Length: 29\r\n",
																	   "content" => "grant_type=client_credentials")));
			
				// Execute the API call using the created headers
				$response = @file_get_contents($url, false, $context);
			}

			// Decode the returned JSON response
			$json = json_decode($response, true);
									
			// Verify that the token is a bearer (by checking for errors first and then checking that the type is bearer)
			if (!isset($json["errors"]) && $json["token_type"] == 'bearer') {
				// If so then return the access token
				return $json["access_token"];
			} else {
				// Otherwise if there were errors or the token was of the wrong type return null
				return null;
			}
		}
		
		// Inserts the tweets in array1 and array2 to a new array
		private static function merge_tweets($array1, $array2) {
			$new_array = array();
			
			// Loop through array1
			for ($i = 0; $i < count($array1); $i++) {
				// Add each item in the array in to the new array
				$new_array[] = $array1[$i];
			}
			
			// Loop through array2
			for ($i = 0; $i < count($array2); $i++) {
				// Add each item in the array in to the new array
				$new_array[] = $array2[$i];
			}
			
			return $new_array;
		}
		
		// Outputs the AJAX code to handle no-caching
		public static function output_ajax($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings) {
			return 
				"<script type=\"text/javascript\">
					jQuery(document).ready(function($) {
						$.ajax({
							type : \"GET\",
							url : \"index.php\",
							data : { 
								thinktwit_request             : \"parse_feed\",
								thinktwit_widget_id           : \"" . $widget_id . "\",
								thinktwit_usernames           : \"" . $usernames . "\",
								thinktwit_hashtags            : \"" . $hashtags . "\",
								thinktwit_username_suffix     : \"" . $username_suffix . "\",
								thinktwit_limit               : \"" . $limit . "\",
								thinktwit_max_days            : \"" . $max_days . "\",
								thinktwit_update_frequency    : \"" . $update_frequency . "\",
								thinktwit_show_username       : \"" . $show_username . "\",
								thinktwit_show_avatar         : \"" . $show_avatar . "\",
								thinktwit_show_published      : \"" . $show_published . "\",
								thinktwit_show_follow         : \"" . $show_follow . "\",
								thinktwit_links_new_window    : \"" . $links_new_window . "\",
								thinktwit_no_cache            : \"" . $no_cache . "\",
								thinktwit_use_curl            : \"" . $use_curl . "\",
								thinktwit_debug               : \"" . $debug . "\",
								thinktwit_time_this_happened  : \"" . $time_settings[0] . "\",
								thinktwit_time_less_min       : \"" . $time_settings[1] . "\",
								thinktwit_time_min            : \"" . $time_settings[2] . "\",
								thinktwit_time_more_mins      : \"" . $time_settings[3] . "\",
								thinktwit_time_1_hour         : \"" . $time_settings[4] . "\",
								thinktwit_time_2_hours        : \"" . $time_settings[5] . "\",
								thinktwit_time_precise_hours  : \"" . $time_settings[6] . "\",
								thinktwit_time_1_day          : \"" . $time_settings[7] . "\",
								thinktwit_time_2_days         : \"" . $time_settings[8] . "\",
								thinktwit_time_many_days      : \"" . $time_settings[9] . "\",
								thinktwit_time_no_recent      : \"" . $time_settings[10] . "\"
							},
							success : function(response) {
								" . __("// The server has finished executing PHP and has returned something, so display it!", 'thinktwit') . "
								$(\"#" . $widget_id . "\").append(response);
							}
						});
					});
				</script>";
		}
		
		// Public accessor to output parse_feed
		public static function output_anywhere($args) {
			// Ensure each argument has a value
			if (isset($args["widget_id"])) {
				$args["widget_id"] = "thinktwit-oa-" . $args["widget_id"];
			} else {
				$args["widget_id"] = "thinktwit-oa-0";
			}
				
			if (!isset($args["usernames"]))
				$args["usernames"] = THINKTWIT_USERNAMES;
			
			if (!isset($args["hashtags"]))
				$args["hashtags"] = THINKTWIT_HASHTAGS;
				
			if (!isset($args["username_suffix"]))
				$args["username_suffix"] = THINKTWIT_USERNAME_SUFFIX;
				
			if (!isset($args["limit"]))
				$args["limit"] = THINKTWIT_LIMIT;
				
			if (!isset($args["max_days"]))
				$args["max_days"] = THINKTWIT_MAX_DAYS;
			
			if (!isset($args["update_frequency"]))
				$args["update_frequency"] = THINKTWIT_UPDATE_FREQUENCY;
			
			if (!isset($args["show_username"]))
				$args["show_username"] = THINKTWIT_SHOW_USERNAME;
			
			if (!isset($args["show_avatar"]))
				$args["show_avatar"] = THINKTWIT_SHOW_AVATAR;
			
			if (!isset($args["show_published"]))
				$args["show_published"] = THINKTWIT_SHOW_PUBLISHED;
			
			if (!isset($args["show_follow"]))
				$args["show_follow"] = THINKTWIT_SHOW_FOLLOW;
			
			if (!isset($args["links_new_window"]))
				$args["links_new_window"] = THINKTWIT_LINKS_NEW_WINDOW;
			
			if (!isset($args["no_cache"]))
				$args["no_cache"] = THINKTWIT_NO_CACHE;
			
			if (!isset($args["use_curl"]))
				$args["use_curl"] = THINKTWIT_USE_CURL;
			
			if (!isset($args["debug"]))
				$args["debug"] = THINKTWIT_DEBUG;
			
			if (!isset($args["time_this_happened"]))
				$args["time_this_happened"] = THINKTWIT_TIME_THIS_HAPPENED;
			
			if (!isset($args["time_less_min"]))
				$args["time_less_min"] = THINKTWIT_TIME_LESS_MIN;
			
			if (!isset($args["time_min"]))
				$args["time_min"] = THINKTWIT_TIME_MIN;
			
			if (!isset($args["time_more_mins"]))
				$args["time_more_mins"] = THINKTWIT_TIME_MORE_MINS;
			
			if (!isset($args["time_1_hour"]))
				$args["time_1_hour"] = THINKTWIT_TIME_1_HOUR;
			
			if (!isset($args["time_2_hours"]))
				$args["time_2_hours"] = THINKTWIT_TIME_2_HOURS;
			
			if (!isset($args["time_precise_hours"]))
				$args["time_precise_hours"] = THINKTWIT_TIME_PRECISE_HOURS;
			
			if (!isset($args["time_1_day"]))
				$args["time_1_day"] = THINKTWIT_TIME_1_DAY;
			
			if (!isset($args["time_2_days"]))
				$args["time_2_days"] = THINKTWIT_TIME_2_DAYS;
			
			if (!isset($args["time_many_days"]))
				$args["time_many_days"] = THINKTWIT_TIME_MANY_DAYS;
			
			if (!isset($args["time_no_recent"]))
				$args["time_no_recent"] = THINKTWIT_TIME_NO_RECENT;
					  		  										 
			// Create an array to contain the time settings
			$time_settings = array(11);
			
			$time_settings[0] = $args["time_this_happened"];
			$time_settings[1] = $args["time_less_min"];
			$time_settings[2] = $args["time_min"];
			$time_settings[3] = $args["time_more_mins"];
			$time_settings[4] = $args["time_1_hour"];
			$time_settings[5] = $args["time_2_hours"];
			$time_settings[6] = $args["time_precise_hours"];
			$time_settings[7] = $args["time_1_day"];
			$time_settings[8] = $args["time_2_days"];
			$time_settings[9] = $args["time_many_days"];
			$time_settings[10] = $args["time_no_recent"];
			
			// If the user selected to use no-caching output AJAX code
			if ($args["no_cache"]) { 
				return "<div id=\"" . $args["widget_id"] . "\">" . ThinkTwit::output_ajax($args["widget_id"], $args["usernames"], $args["hashtags"], $args["username_suffix"], $args["limit"], $args["max_days"], $args["update_frequency"], $args["show_username"], $args["show_avatar"], $args["show_published"], $args["show_follow"], $args["links_new_window"], $args["no_cache"], $args["use_curl"], $args["debug"], $time_settings) . "</div>";
			// Otherwise output HTML method
			} else {
				return ThinkTwit::parse_feed($args["widget_id"], $args["usernames"], $args["hashtags"], $args["username_suffix"], $args["limit"], $args["max_days"], $args["update_frequency"], $args["show_username"], $args["show_avatar"], $args["show_published"], $args["show_follow"], $args["links_new_window"], $args["no_cache"], $args["use_curl"], $args["debug"], $time_settings);
			}
		}
		
		// Returns the tweets, subject to the given parameters
		private static function parse_feed($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, 
		  $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings) {
			
			// Create the Twitter Search API URL, ready for construction
			$url = "https://api.twitter.com/1.1/search/tweets.json?q=";
			
			// Check user supplied usernames
			if (!empty($usernames)) {
				// Construct a string of usernames to search for
				$username_string = str_replace(" ", "+OR+from%3A", $usernames);
				
				// Add the usernames to the URL, prefixed with "from:" for the first username
				$url .= "from%3A" . $username_string;
			}
			
			// Check user supplied hashtags
			if (!empty($hashtags)) {
				// Replace hashes in hashtags with code for URL
				$hashtag_string = str_replace("#", "%23", $hashtags);
				
				// Replace spaces in hashtags with plus signs
				$hashtag_string = str_replace(" ", "+OR+", $hashtag_string);
				
				// If there were usernames then append a separator to the URL
				if (!empty($usernames)) {
					$url .= "+OR+";
				}
				
				// Add the hashtags to the URL
				$url .= $hashtag_string;
			}

			// Finally add the limit
			$url .= "&rpp=" . $limit;
			
			$output = "";

			// If user wishes to output debug info then do so
			if ($debug) {		
				$output .= "<p><b>" . __("Current date/time" . ":", 'thinktwit') . "</b> " . date('Y/m/d H:i:s e (P)', time()) . "</p>";
				$output .= "<p><b>" . __("Widget ID" . ":", 'thinktwit') . "</b> " . $widget_id . "</p>";
				$output .= "<p><b>" . __("Twitter usernames (optional) separated by spaces" . ":", 'thinktwit') . "</b> " . $usernames . "</p>";
				$output .= "<p><b>" . __("Twitter hashtags/keywords (optional) separated by spaces:", 'thinktwit') . "</b> " . $hashtags . "</p>";
				$output .= "<p><b>" . __("Username suffix (e.g. \" said \"):", 'thinktwit') . "</b> " . $username_suffix . "</p>";
				$output .= "<p><b>" . __("Max tweets to display:", 'thinktwit') . "</b> " . $limit . "</p>";
				$output .= "<p><b>" . __("Max days to display:", 'thinktwit') . "</b> " . $max_days . "</p>";
				$output .= "<p><b>" . __("Show username:", 'thinktwit') . "</b> ";

				switch ($update_frequency) {
					case -1:
						$output .= "Live (uncached)";
						break;
					case 0:
						$output .= "Live (cached)";
						break;
					case 1:
						$output .= "Hourly";
						break;
					case 2:
						$output .= "Every 2 hours";
						break;
					case 4:
						$output .= "Every 4 hours";
						break;
					case 12:
						$output .= "Every 12 hours";
						break;
					case 24:
						$output .= "Every day";
						break;
					case 48:
						$output .= "Every 2 days";
						break;
				}
				
				$output .= "</p>";
				$output .= "<p><b>" . __("Show username:", 'thinktwit') . "</b> ";

				switch ($show_username) {
					case "none":
						$output .= "None";
						break;
					case "name":
						$output .= "Name";
						break;
					case "username":
						$output .= "Username";
						break;
				}
				
				$output .= "</p>";
				$output .= "<p><b>" . __("Show username's avatar:", 'thinktwit') . "</b> " . ($show_avatar ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Show when published:", 'thinktwit') . "</b> " . ($show_published ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Show 'Follow @username' links:", 'thinktwit') . "</b> " . ($show_follow ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Open links in new window:", 'thinktwit') . "</b> " . ($links_new_window ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Prevent caching e.g. by WP Super Cache:", 'thinktwit') . "</b> " . ($no_cache ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Use CURL for accessing Twitter API (set yes if getting `URL file-access` errors):", 'thinktwit') . "</b> " . ($use_curl ? "Yes" : "No") . "</p>";
				$output .= "<p><b>" . __("Output debug messages:", 'thinktwit') . "</b> " . ($debug ? "Yes" : "No") . "</p>";		
				$output .= "<p><b>" . __("URL:", 'thinktwit') . "</b> " . $url . "</p>";			
				$output .= "<p><b>" . __("Time prefix:", 'thinktwit') . "</b> " . $time_settings[0] . "</p>";
				$output .= "<p><b>" . __("Less than 59 seconds ago:", 'thinktwit') . "</b> " . $time_settings[1] . "</p>";
				$output .= "<p><b>" . __("Less than 1 minute 59 seconds ago:", 'thinktwit') . "</b> " . $time_settings[2] . "</p>";
				$output .= "<p><b>" . __("Less than 50 minutes ago:", 'thinktwit') . "</b> " . $time_settings[3] . "</p>";
				$output .= "<p><b>" . __("Less than 89 minutes ago:", 'thinktwit') . "</b> " . $time_settings[4] . "</p>";
				$output .= "<p><b>" . __("Less than 150 minutes ago:", 'thinktwit') . "</b> " . $time_settings[5] . "</p>";
				$output .= "<p><b>" . __("Less than 23 hours ago:", 'thinktwit') . "</b> " . $time_settings[6] . "</p>";
				$output .= "<p><b>" . __("Less than 36 hours:", 'thinktwit') . "</b> " . $time_settings[7] . "</p>";
				$output .= "<p><b>" . __("Less than 48 hours ago:", 'thinktwit') . "</b> " . $time_settings[8] . "</p>";
				$output .= "<p><b>" . __("More than 48 hours ago:", 'thinktwit') . "</b> " . $time_settings[9] . "</p>";
				$output .= "<p><b>" . __("No recent tweets:", 'thinktwit') . "</b> " . $time_settings[10] . "</p>";
			}

			// Get the tweets
			$tweets = ThinkTwit::get_tweets($update_frequency, $url, $use_curl, $widget_id, $limit, $max_days, $usernames, $hashtags);

			// Create an ordered list
			$output .= "<ol class=\"thinkTwitTweets\">";

			// Find out if there are any tweets, if so output them
			if (count($tweets) > 0) {
				// Loop through each tweet
				for ($i = 0; $i < count($tweets); $i++) {
					// Get the current tweet
					$tweet = $tweets[$i];

					// Output the list item
					$output .= "<li id=\"tweet-" . ($i + 1) . "\" class=\"thinkTwitTweet " . (($i + 1) % 2 ? "thinkTwitOdd" : "thinkTwitEven") . "\">";

					$name = "";
					// If the user wants to output the name or username then store it
					if (strcmp($show_username, "name") == 0) {
						$name = $tweet->getName();
					} elseif (strcmp($show_username, "username") == 0) {
						$name = $tweet->getUsername();
					}

					// Output the link to the poster's profile
					$output .= "<a href=\"" . $tweet->getUrl() . "\"" . ($links_new_window ? " target=\"blank\"" : "") . " title=\"" . $name . "\" class=\"thinkTwitUsername\" rel=\"nofollow\">";
										
					// If the avatar is empty (this should only happen after an upgrade)
					if (!$tweet->getAvatar()) {
						// Download the avatar (we need the filename but we should make sure that the file is there anyway)
						$filename = ThinkTwit::download_avatar($use_curl, $tweet->getUsername(), $tweet->getAvatarUrl());
						
						// Store the filename in the tweet
						$tweet->setAvatar($filename);
						
						// Store the tweet in the array of tweets
						$tweets[$i] = $tweet;
						
						// Update the cache with the updated tweets array
						ThinkTwit::update_cache($tweets, $widget_id);
					} else {
						// But if it does exist then get the full file path
						$file = plugin_dir_path( __FILE__ ) . 'images/' . $tweet->getAvatar();
						
						// And if the file doesn't exist
						if (!file_exists($file)) {
							// Then download it
							$filename = ThinkTwit::download_avatar($use_curl, $tweet->getUsername(), $tweet->getAvatarUrl());
						}
					}
					
					// Get the URL of the poster's avatar
					$url = plugins_url( 'images/' . $tweet->getAvatar() , __FILE__ );

					// Check if the user wants to display the poster's avatar and that we can actually find one
					if ($show_avatar && $url != false) {
						$output .= "<img src=\"" . $url . "\" alt=\"" . $name . "\" />";
					}
					
					// Check if the user wants to output the name, username or nothing at all
					if (strcmp($show_username, "none") != 0) {
						$output .= $name;
					}
					
					// Close the link and output the suffix
					$output .= "</a><span class=\"thinkTwitSuffix\">" . $username_suffix . "</span>";

					// Surround the tweet in a span to allow targeting of the tweet
					$output .= "<span class=\"thinkTwitContent\">";
					
					// Check if the user wants URL's to open in a new window
					if ($links_new_window) {
						// Find the URL's in the content
						$url_strings = explode("href=\"", $tweet->getContent());

						// Append the first part of the content to output
						$output .= $url_strings[0];

						// Loop through each URL
						for ($j = 1; $j <= (count($url_strings) - 1); $j++) {
							// Find the position of the closing quotation mark within the current string
							$pos = strpos($url_strings[$j], "\"");

							// Append everything up to the quotation marks
							$output .=  "href=\"" . substr($url_strings[$j], 0, $pos + 1);

							// Then add the code to open a new window
							$output .= " target=\"_blank\" rel=\"nofollow\"";

							// Then add everything after
							$output .= substr($url_strings[$j], $pos + 1);
						}
					} else {
						// Otherwise simply append the content unedited
						$output .= $tweet->getContent();
					}

					// Close the span
					$output .= "</span>";

					// Check if the user wants to show the published date
					if ($show_published) {
						$output .= "<span class=\"thinkTwitPublished\">" . $time_settings[0] . ThinkTwit::relative_created_at($tweet->getTimestamp(), $time_settings) . "</span>";
					}

					// Close the list item
					$output .= "</li>";
				}
			} else {
				// If no tweets were found output the message to say so
				$output .= "<li class=\"thinkTwitNoTweets\">" . $time_settings[10] . ".</li>";
			}

			$output .= "</ol>";
			
			// Check if the user wants to show the "Follow @username" links
			if ($show_follow && !empty($usernames)) {
				// If so then output one for each username
				foreach(explode(" ", $usernames) as $username) {
					$output .= "<p class=\"thinkTwitFollow\"><a href=\"https://twitter.com/" . $username . "\" class=\"twitter-follow-button\" data-show-count=\"false\" data-dnt=\"true\">" . __("Follow", 'thinktwit') . " @" . $username . "</a></p>";
				}
				
				// Output the script that adds the link functionality
				$output .= "<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>";
			}
			
			// Finally, perform any required cleanup operations
			ThinkTwit::perform_cleanup();
			
			return apply_filters("think_twit", $output);
		}
		
		// Performs cleanup operations
		private static function perform_cleanup() {
			$settings = get_option("widget_thinktwit_settings");
			
			// Check that settings is an array
			if (!is_array($settings)) {
				// The settings don't exist so create some
				$settings = array();
				
				// Set to 1 month and current datetime
				$settings["cleanup_period"] = 30;
				$settings["last_cleanup"] = time();
			} else {
				// If the cleanup period isn't set
				if (!isset($settings['cleanup_period'])) {
					// Set to 1 month
					$settings["cleanup_period"] = 30;
				}
				
				// If last cleanup isn't set
				if (!isset($settings['last_cleanup'])) {
					// Set to now
					$settings["last_cleanup"] = time();
				}
			}
			
			// Get the cleanup period
			$cleanup_period = $settings['cleanup_period'];
			
			// Get the datetime of the last cleanup
			$last_cleanup = $settings['last_cleanup'];
			
			// If the last cleanup was beyond the required period (86400 seconds is 1 day, so multiply by the period to get the total
			// maximum number of seconds)
			if ((time() - $last_cleanup) > ($cleanup_period * 86400)) {
				// Get allowed usernames
				$allowed_usernames = ThinkTwit::get_allowed_usernames();
				
				// Delete old avatars
				ThinkTwit::delete_unused_avatars($allowed_usernames);
				
				// Set the last cleanup period to now
				$settings["last_cleanup"] = time();
				
				// Store the updated cleanup time in our settings
				update_option("widget_thinktwit_settings", $settings);
			}
		}

		// Given a PHP time this returns how long ago that time was, in easy to understand English
		private static function relative_created_at($time_to_compare, $time_settings) {
			// Get the difference between the current time and the time we wish to compare against
			$time_difference = time() - $time_to_compare;

			if ($time_difference < 59) {            // Less than 59 seconds ago
				return $time_settings[1];
			} else if ($time_difference < 119) {    // Less than 1 minute 59 seconds ago
				return $time_settings[2];
			} else if ($time_difference < 3000) {   // Less than 50 minutes ago
				return round($time_difference / 60) . $time_settings[3];
			} else if ($time_difference < 5340) {   // Less than 89 minutes ago
				return $time_settings[4];
			} else if ($time_difference < 9000) {   // Less than 150 minutes ago
				return $time_settings[5];
			} else if ($time_difference < 82800) {  // Less than 23 hours ago
				return str_replace("=x=", round($time_difference / 3600), $time_settings[6]);
			} else if ($time_difference < 129600) { // Less than 36 hours
				return $time_settings[7];
			} else if ($time_difference < 172800) { // Less than 48 hours ago
				return $time_settings[8];
			} else {                                // More than 48 hours ago
				return round($time_difference / 86400) . $time_settings[9];
			}
		}
		
		// Returns an array with duplicate tweets removed (based on timestamp)
		private static function remove_duplicates($array) {
			$new_array = array();
			
			// Iterate through item
			for($i = 0; $i < count($array); $i++) {
				// If it's the first item, or if the current item's timestamp is not equal to the previous
				if (($i == 0) || ($i > 0 && $array[$i]->getTimestamp() != $array[$i - 1]->getTimestamp())) {
					// Add it to the new array
					$new_array[] = $array[$i];
				}
			}
			
			return $new_array;
		}
		
		// Removes empty tweets (based on content)
		private static function remove_empty_tweets($array) {
			$new_array = array();
			
			// Iterate through item
			foreach($array as $tweet) {
				// If the current item does have content
				if (is_object($tweet) && $tweet->getContent() != NULL && $tweet->getContent() != "") {
					// Add it to the new array
					$new_array[] = $tweet;
				}
			}
			
			return $new_array;
		}
		
		// Returns an array of Tweets with only the requested usernames and hashtags
		private static function remove_incorrect_usernames_and_hashtags($array, $usernames, $hashtags) {
			$new_array = array();
			
			// Iterate through item
			foreach($array as $tweet) {
				// If the current item has a valid username
				if (($tweet->getUsername()) && (stristr($usernames, $tweet->getUsername()))) {
					// Add it to the new array
					$new_array[] = $tweet;
				}
				
				// Separate hashtags into an array
				$hashtag_array = explode(" ", $hashtags);
				
				// Iterate through each hashtag
				foreach($hashtag_array as $hashtag => $search_needle) { 
					// If the current hashtag exists within the content of the current tweet
					if(($search_needle) && (stristr($tweet->getContent(), $search_needle) != FALSE)) {
						// Add it to the new array
						$new_array[] = $tweet;
					}
				}
			}
			
			return $new_array;
		}
		
		// Returns an array with tweets older than max days removed
		private static function remove_old_tweets($array, $max_days) {
			$new_array = array();
			
			// Iterate through item
			foreach($array as $tweet) {
				// Get the oldest date the tweet can be (max days in seconds)
				$oldest_date = time() - ($max_days * 24 * 60 * 60);

				// If the current item is younger than the oldest date				
				if ($tweet->getTimestamp() > $oldest_date) {
					// Add it to the new array
					$new_array[] = $tweet;
				}
			}
			
			return $new_array;
		}
		
		// Function to handle shortcode
		public static function shortcode_handler($atts) {
			extract(shortcode_atts(array(
				"widget_id"          => 0,
				"usernames"          => THINKTWIT_USERNAMES,
				"hashtags"           => THINKTWIT_HASHTAGS,
				"username_suffix"    => THINKTWIT_USERNAME_SUFFIX,
				"limit"              => THINKTWIT_LIMIT,
				"max_days"           => THINKTWIT_MAX_DAYS,
				"update_frequency"   => THINKTWIT_UPDATE_FREQUENCY,
				"show_username"      => THINKTWIT_SHOW_USERNAME,
				"show_avatar"        => THINKTWIT_SHOW_AVATAR,
				"show_published"     => THINKTWIT_SHOW_PUBLISHED,
				"show_follow"        => THINKTWIT_SHOW_FOLLOW,
				"links_new_window"   => THINKTWIT_LINKS_NEW_WINDOW,
				"no_cache"           => THINKTWIT_NO_CACHE,
				"use_curl"           => THINKTWIT_USE_CURL,
				"debug"              => THINKTWIT_DEBUG,
				"time_this_happened" => THINKTWIT_TIME_THIS_HAPPENED,
				"time_less_min"      => THINKTWIT_TIME_LESS_MIN,
				"time_min"           => THINKTWIT_TIME_MIN,
				"time_more_mins"     => THINKTWIT_TIME_MORE_MINS,
				"time_1_hour"        => THINKTWIT_TIME_1_HOUR,
				"time_2_hours"       => THINKTWIT_TIME_2_HOURS,
				"time_precise_hours" => THINKTWIT_TIME_PRECISE_HOURS,
				"time_1_day"         => THINKTWIT_TIME_1_DAY,
				"time_2_days"        => THINKTWIT_TIME_2_DAYS,
				"time_many_days"     => THINKTWIT_TIME_MANY_DAYS,
				"time_no_recent"     => THINKTWIT_TIME_NO_RECENT
			), $atts));
			
			// Modify unique id to lock it to shortcodes
			$widget_id = "thinktwit-sc-" . $widget_id;
						 
			// Create an array to contain the time settings
			$time_settings = array(11);

			$time_settings[0] = $time_this_happened;
			$time_settings[1] = $time_less_min;
			$time_settings[2] = $time_min;
			$time_settings[3] = $time_more_mins;
			$time_settings[4] = $time_1_hour;
			$time_settings[5] = $time_2_hours;
			$time_settings[6] = $time_precise_hours;
			$time_settings[7] = $time_1_day;
			$time_settings[8] = $time_2_days;
			$time_settings[9] = $time_many_days;
			$time_settings[10] = $time_no_recent;

			// If user selected to use no-caching output AJAX code
			if ($no_cache) {
				return "<div id=\"" . $widget_id . "\">" . ThinkTwit::output_ajax($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings) . "</div>";
			// Otherwise output HTML method
			} else {
				return ThinkTwit::parse_feed($widget_id, $usernames, $hashtags, $username_suffix, $limit, $max_days, $update_frequency, $show_username, $show_avatar, $show_published, $show_follow, $links_new_window, $no_cache, $use_curl, $debug, $time_settings);
			}
		}
		
		// Bubble sorts the tweets in array upon the timestamp
		private static function sort_tweets(&$array) {
			// Loop down through the array
			for ($i = count($array) - 1; $i >= 0; $i--) {
				// Record whether there was a swap
				$swapped = false;
				
				// Loop through un-checked array items
				for ($j = 0; $j < $i; $j++) {
					// Compare the values
					if ($array[$j]->getTimestamp() < $array[$j + 1]->getTimestamp()) {
						// Swap the values
						$tmp = $array[$j];
						$array[$j] = $array[$j + 1];        
						$array[$j + 1] = $tmp;
						$swapped = true;
					}
				}
			  
			  if (!$swapped) return;
			}
			
			return $array;
		}
		
		// Returns the given array but trimmed to the size of n
		private static function trim_array($array, $n) {
			$new_array = array();
			
			// Loop through the array until n
			for($i = 0; $i < $n; $i++) {
				array_push($new_array, $array[$i]);
			}
			
			return $new_array;
		}
				
		// Updates the cache with the given Tweets and stores the time of the update
		private static function update_cache($tweets, $widget_id, $timestamp = -1) {
			// If timestamp is -1 (default) then get the current time
			if ($timestamp == -1) $timestamp = time();
			
			// Store the tweets in the database with the given timestamp
			update_option("widget_" . $widget_id . "_cache", array($tweets, $timestamp));
			
			do {
				// Get our widget settings
				$settings = get_option("widget_thinktwit_settings");
							
				// If settings isn't an array
				if (!is_array($settings)) {
					// Store updated timestamp
					$current_updated = microtime(); // TODO For some reason some values are coming up identical between shortcode and widget when you have multiple widgets - how??
					
					// Create the array with the minimum required values
					$settings = array("version" => ThinkTwit::get_version(), "cache_names" => array("widget_" . $widget_id . "_cache"), "updated" => $current_updated);
				} else {
					// Otherwise, add the widget cache name to the array
					array_push($settings["cache_names"], "widget_" . $widget_id . "_cache");
					
					// Return a unique copy of the array to ensure we don't have duplicates
					$settings["cache_names"] = array_unique($settings["cache_names"]);
					
					// Store the current updated timestamp
					$current_updated = $settings["updated"];
					
					// Update the updated timestamp
					$settings["updated"] = microtime();
				}
				
				// Check if the stored version is the same as the current version
				if ($settings["version"] != ThinkTwit::get_version()) {
					// If not then update it
					$settings["version"] = ThinkTwit::get_version();
				}
				
				// Get a fresh copy of the settings so we can compare the timestamp with our settings timestamp
				// (if there is a difference then settings have been updated since we started, so repeat process)
				$fresh_settings = get_option("widget_thinktwit_settings");
				
				// Check that the fresh settings exist or else we will be stuck in a loop
				if (!is_array($fresh_settings)) {
					// If they don't lets just take a copy of our settings
					$fresh_settings = $settings;
				}
			} while($current_updated != $fresh_settings["updated"]);
			
			// Store the name of the cache in our settings
			update_option("widget_thinktwit_settings", $settings);
		}
	}
	
	// Class for storing a tweet
	class Tweet {
		protected $url;
		protected $avatar;
		protected $avatar_url;
		protected $name;
		protected $username;
		protected $content;
		protected $timestamp;

		// Constructor
		public function __construct($url, $avatar, $avatar_url, $name, $username, $content, $timestamp) {
			$this->url = trim($url);
			$this->avatar = trim($avatar);
			$this->avatar_url = trim($avatar_url);
			$this->name = trim($name);
			$this->username = trim($username);
			$this->content = trim($content);
			$this->timestamp = trim($timestamp);
		}

		// toString method outputs the contents of the Tweet
		public function __toString() {
			return "[url=$this->url, avatar=$this->avatar, avatar_url=$this->avatar_url, name=$this->name, username=$this->username, content='$this->content', timestamp=$this->timestamp]";
		}

		// Returns the tweet's URL
		public function getUrl() {
			return $this->url;
		}

		// Sets the tweet's URL
		public function setUrl($url) {
			$this->url = trim($url);
		}

		// Returns the tweet's avatar filename
		public function getAvatar() {
			return $this->avatar;
		}

		// Sets the tweet's avatar filename
		public function setAvatar($avatar) {
			$this->avatar = trim($avatar);
		}

		// Returns the tweet's avatar URL
		public function getAvatarUrl() {
			return $this->avatar_url;
		}

		// Sets the tweet's avatar URL
		public function setAvatarUrl($avatar_url) {
			$this->avatar_url = trim($avatar_url);
		}

		// Returns the tweet's Twitter name
		public function getName() {
			return $this->name;
		}

		// Sets the tweet's Twitter name
		public function setName($name) {
			$this->name = trim($name);
		}

		// Returns the tweet's username
		public function getUsername() {
			return $this->username;
		}

		// Sets the tweet's username
		public function setUsername($username) {
			$this->username = trim($username);
		}

		// Returns the tweet's content
		public function getContent() {
			return $this->content;
		}

		// Sets the tweet's content
		public function setContent($content) {
			$this->content = trim($content);
		}

		// Returns the tweet's timestamp
		public function getTimestamp() {
			return $this->timestamp;
		}

		// Sets the tweet's content
		public function setTimestamp($timestamp) {
			$this->timestamp = $timestamp;
		}
	}
?>