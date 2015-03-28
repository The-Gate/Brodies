<?php

/**
 * @file
 * Google geocoder.
 */

/**
 * Return the list of ISO3166 codes supported by this geocoder.
 *
 * Google now supports geocoding for all countries:
 * https://developers.google.com/maps/coverage
 */
function google_geocode_country_list() {
  $countries = location_get_iso3166_list();
  return array_keys($countries);
}

/**
 * Return general information about this geocoder.
 */
function google_geocode_info() {
  return array(
    'name' => 'Google Maps',
    'url' => 'http://maps.google.com',
    'tos' => 'http://www.google.com/help/terms_local.html',
    'general' => TRUE,
  );
}

/**
 * Perform a geocode on a location array.
 * @param $location
 *   The location array to process.
 * @return
 *   an associative array with keys 'lat' and 'lon' containing the coordinates.
 */
function google_geocode_location($location = array()) {

  $query = array(
    'region' => $location['country'],
    'address' => _google_geocode_flatten($location),
    'components' => _google_geocode_get_components($location),
    'sensor' => 'false', // Required by TOS.
  );

  $url = url('http://maps.googleapis.com/maps/api/geocode/json', array(
    'query' => $query,
    'external' => TRUE,
  ));

  $http_reply = drupal_http_request($url);
  $data = json_decode($http_reply->data);

  $status_code = $data->status;
  if ($status_code != 'OK') {
    watchdog('location', 'Google geocoding returned status code: %status_code for the query url: %url', array('%status_code' => $data->status, '%url' => $url));
    return NULL;
  }
  $location = $data->results[0]->geometry->location;

  return array('lat' => $location->lat, 'lon' => $location->lng);
}

/**
 * General settings for this geocoder.
 */
function google_geocode_settings() {
  $form = array();
  $key = '';
  if (function_exists('gmap_get_key')) {
    $key = gmap_get_key();
  }

  if (!empty($key)) {
    $form['location_geocode_google_apikey'] = array(
      '#type' => 'item',
      '#title' => t('Google Maps API Key'),
      '#value' => $key,
      '#description' => t('The key in use was automatically provided by GMap.'),
    );
  }
  else {
    $form['location_geocode_google_apikey'] = array(
      '#type' => 'textfield',
      '#title' => t('Google Maps API Key'),
      '#size' => 64,
      '#maxlength' => 128,
      '#default_value' => variable_get('location_geocode_google_apikey', ''),
      '#description' => t('In order to use the Google Maps API geocoding web-service, you will need a Google Maps API Key.  You can obtain one at the !sign_up_link for the !google_maps_api.  PLEASE NOTE: You will <em>not</em> have to re-enter your API key for each country for which you have selected Google Maps for geocoding.  This setting is global.', array('!sign_up_link' => '<a href="http://www.google.com/apis/maps/signup.html">sign-up page</a>', '!google_maps_api' => '<a href="http://www.google.com/apis/maps/">Google Maps API</a>'))
    );
  }

  $country = arg(4);
  if ($country) {
    $form['location_geocode_' . $country . '_google_accuracy_code'] = array(
      '#type' => 'select',
      '#title' => t('Google Maps Geocoding Accuracy for %country', array('%country' => $country ) ),
      '#default_value' => variable_get('location_geocode_' . $country . '_google_accuracy_code', variable_get('location_geocode_google_minimum_accuracy', '3')),
      '#options' => location_google_geocode_accuracy_codes(),
      '#description' => t('The minimum required accuracy for the geolocation data to be saved.'),
    );
  }
  return $form;
}

function _google_geocode_flatten($location = array()) {
  // Check if its a valid address
  if (empty($location)) {
    return '';
  }

  $address = '';
  if (!empty($location['street'])) {
    $address .= $location['street'];
  }

  if (!empty($location['city'])) {
    if (!empty($address)) {
      $address .= ', ';
    }

    $address .= $location['city'];
  }

  if (!empty($location['province'])) {
    if (!empty($address)) {
      $address .= ', ';
    }

    // @@@ Fix this!
    if (substr($location['province'], 0, 3) == $location['country'] . '-') {
      $address .= substr($location['province'], 3);
      watchdog('Location', 'BUG: Country found in province attribute.');
    }
    else {
      $address .= $location['province'];
    }
  }

  if (!empty($location['postal_code'])) {
    if (!empty($address)) {
      $address .= ', ';
    }
    $address .= $location['postal_code'];
  }

  if (!empty($location['country'])) {
    if (!empty($address)) {
      $address .= ', ';
    }
    $address .= $location['country'];
  }

  return $address;
}

/**
 * Gets a components string to pass to the google geocode API.
 *
 * This is required to get more accurate results because sometimes when passing
 * in a small piece of information, like a country code only, it could also
 * match a different part of an address for another country as the highest
 * match.
 *
 * See https://developers.google.com/maps/documentation/geocoding/#ComponentFiltering
 * for details.
 *
 * @param array $location
 *   A location array.
 *
 * @return string
 *   A components string formatted as per the docs page linked to above.
 */
function _google_geocode_get_components($location = array()) {
  // Check if its a valid address
  if (empty($location)) {
    return '';
  }

  $components = array();
  if (!empty($location['city'])) {
    $components[] = 'locality:' . $location['city'];
  }
  if (!empty($location['province'])) {
    // @@@ Fix this!
    if (!empty($location['country']) && substr($location['province'], 0, 3) == $location['country'] . '-') {
      $components[] = 'administrative_area:' . substr($location['province'], 3);
    }
    else {
      $components[] = 'administrative_area:' . $location['province'];
    }
  }
  if (!empty($location['postal_code'])) {
    $components[] = 'postal_code:' . $location['postal_code'];
  }
  if (!empty($location['country'])) {
    $components[] = 'country:' . $location['country'];
  }

  return implode('|', $components);
}