<?php
/**
 * Plugin Name: WM Simple Captcha
 * Plugin URI: http://plugins.web-mumbai.com/
 * Description: WM Simple Captcha for registration page, customize captcha image according to your theme.
 * Version: 1.1.1
 * Author: WebMumbai
 * Author URI: http://plugins.web-mumbai.com/
 * License: GPL version 2 or later - http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 */ 
if (!defined('ABSPATH')) exit; // Exit if accessed directly
	
require_once('classes/wm_simple_captcha_front.php');
global $wmsimplecaptchafront;
$wmsimplecaptchafront = new WM_Simple_Captcha_Front(__FILE__);