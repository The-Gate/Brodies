<?php
/**
 * @file
 * image_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function image_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function image_settings_image_default_styles() {
  $styles = array();

  // Exported image style: CTA_Large.
  $styles['CTA_Large'] = array(
    'label' => 'CTA_Large',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 240,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: CTA_small.
  $styles['CTA_small'] = array(
    'label' => 'CTA_small',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 115,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: News-featured.
  $styles['News-featured'] = array(
    'label' => 'News-featured',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 192,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: banner_image.
  $styles['banner_image'] = array(
    'label' => 'Banner Image',
    'effects' => array(
      46 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      47 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1920,
          'height' => 262,
          'anchor' => 'center-center',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: case-study-listing.
  $styles['case-study-listing'] = array(
    'label' => 'case-study-listing',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 212,
          'height' => 92,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: col-12-lg--full.
  $styles['col-12-lg--full'] = array(
    'label' => 'col-12-lg--FULL',
    'effects' => array(
      40 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-12-sm-full.
  $styles['col-12-sm-full'] = array(
    'label' => 'col-12-sm-FULL',
    'effects' => array(
      32 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-3--lg.
  $styles['col-3--lg'] = array(
    'label' => 'col-3--lg',
    'effects' => array(
      31 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-3--lg--fixed.
  $styles['col-3--lg--fixed'] = array(
    'label' => 'col-3--lg--fixed',
    'effects' => array(
      33 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      34 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 290,
          'height' => 190,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: col-3--lg--thumb-fixed.
  $styles['col-3--lg--thumb-fixed'] = array(
    'label' => 'col-3--lg--thumb-fixed',
    'effects' => array(
      35 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      36 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 290,
          'height' => 120,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: col-4--lg.
  $styles['col-4--lg'] = array(
    'label' => 'col-4--lg',
    'effects' => array(
      37 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 390,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-6--lg.
  $styles['col-6--lg'] = array(
    'label' => 'col-6--lg',
    'effects' => array(
      38 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 590,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-8--lg.
  $styles['col-8--lg'] = array(
    'label' => 'col-8--lg',
    'effects' => array(
      42 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-9--lg.
  $styles['col-9--lg'] = array(
    'label' => 'col-9--lg',
    'effects' => array(
      39 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 880,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col-9--lg-max-h300.
  $styles['col-9--lg-max-h300'] = array(
    'label' => 'col-9--lg-MAX-H300',
    'effects' => array(
      43 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 770,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      44 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 770,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: cs-list-thumb.
  $styles['cs-list-thumb'] = array(
    'label' => 'cs-list-thumb',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 65,
          'height' => 54,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: inline-videos-thumb.
  $styles['inline-videos-thumb'] = array(
    'label' => 'inline-videos-thumb',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 102,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 102,
          'height' => 56,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: inline-videos-thumb-mobile.
  $styles['inline-videos-thumb-mobile'] = array(
    'label' => 'inline-videos-thumb-mobile',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 320,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      8 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 320,
          'height' => 176,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: news-display-main.
  $styles['news-display-main'] = array(
    'label' => 'news-display-main',
    'effects' => array(
      10 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 457,
          'height' => 300,
          'xoffset' => 'center',
          'yoffset' => 'top',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: news-display-other.
  $styles['news-display-other'] = array(
    'label' => 'news-display-other',
    'effects' => array(
      12 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 157,
          'height' => 120,
          'xoffset' => 'center',
          'yoffset' => 'top',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: news-list-full.
  $styles['news-list-full'] = array(
    'label' => 'news-list-full',
    'effects' => array(
      15 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 519,
          'height' => 150,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: news-list-half.
  $styles['news-list-half'] = array(
    'label' => 'news-list-half',
    'effects' => array(
      17 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 226,
          'height' => 50,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: page-full-width.
  $styles['page-full-width'] = array(
    'label' => 'page-full-width',
    'effects' => array(
      19 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 519,
          'height' => 150,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: people-list-thumb.
  $styles['people-list-thumb'] = array(
    'label' => 'people-list-thumb',
    'effects' => array(
      20 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 65,
          'height' => 54,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: people-page-photo.
  $styles['people-page-photo'] = array(
    'label' => 'people-page-photo',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 162,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: related-cs-thumb.
  $styles['related-cs-thumb'] = array(
    'label' => 'related-cs-thumb',
    'effects' => array(
      24 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 160,
          'height' => 95,
          'xoffset' => 'center',
          'yoffset' => 'center',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: related-people-thumb.
  $styles['related-people-thumb'] = array(
    'label' => 'related-people-thumb',
    'effects' => array(
      25 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 323,
          'height' => 83,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      26 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 135,
          'height' => 83,
          'xoffset' => 'left',
          'yoffset' => 'center',
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: scroller-display-list.
  $styles['scroller-display-list'] = array(
    'label' => 'scroller-display-list',
    'effects' => array(
      41 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 160,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      28 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 160,
          'height' => 76,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: video-list.
  $styles['video-list'] = array(
    'label' => 'video-list',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 135,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: video-thumb.
  $styles['video-thumb'] = array(
    'label' => 'video-thumb',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 65,
          'height' => 54,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}
