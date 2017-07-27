<?php
/**
 * @file
 * image_settings.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function image_settings_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 12';
  $picture_mapping->machine_name = 'col_12';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-lg--full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_12'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 3';
  $picture_mapping->machine_name = 'col_3';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-3--lg',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_3'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 3 Fixed';
  $picture_mapping->machine_name = 'col_3_fixed';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-3--lg--fixed',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_3_fixed'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 3 Thumb';
  $picture_mapping->machine_name = 'col_3_thumb';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-3--lg--thumb-fixed',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_3_thumb'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 4';
  $picture_mapping->machine_name = 'col_4';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-4--lg',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_4'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 6';
  $picture_mapping->machine_name = 'col_6';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-6--lg',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_6'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 8';
  $picture_mapping->machine_name = 'col_8';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-8--lg',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_8'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 9';
  $picture_mapping->machine_name = 'col_9';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-9--lg',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_9'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Col 9 Max H300';
  $picture_mapping->machine_name = 'col_9_max_h300';
  $picture_mapping->breakpoint_group = 'bootstrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap.screen-xs-max' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-12-sm-full',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-min' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col-9--lg-max-h300',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-sm-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-md-max' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.bootstrap.screen-lg-min' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '1.5x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['col_9_max_h300'] = $picture_mapping;

  return $export;
}
