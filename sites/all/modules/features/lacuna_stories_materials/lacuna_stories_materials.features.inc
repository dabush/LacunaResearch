<?php
/**
 * @file
 * lacuna_stories_materials.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lacuna_stories_materials_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function lacuna_stories_materials_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function lacuna_stories_materials_flag_default_flags() {
  $flags = array();
  // Exported flag: "Primary Reading".
  $flags['primary_reading'] = array(
    'entity_type' => 'node',
    'title' => 'Primary Reading',
    'global' => 1,
    'types' => array(
      0 => 'document',
    ),
    'flag_short' => 'This item is the primary reading for this study',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'This item is not the primary reading for this study',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'workflow_tab' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'lacuna_stories_materials',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function lacuna_stories_materials_image_default_styles() {
  $styles = array();

  // Exported image style: thumbnails_for_browsing.
  $styles['thumbnails_for_browsing'] = array(
    'label' => 'Thumbnails for Browsing',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 220,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function lacuna_stories_materials_node_info() {
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('Any primary or secondary documents.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
