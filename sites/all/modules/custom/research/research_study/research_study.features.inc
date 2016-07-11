<?php
/**
 * @file
 * research_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function research_study_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function research_study_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function research_study_flag_default_flags() {
  $flags = array();
  // Exported flag: "Demographic Survey Flag".
  $flags['demographic_survey_flag'] = array(
    'entity_type' => 'node',
    'title' => 'Demographic Survey Flag',
    'global' => 1,
    'types' => array(
      0 => 'webform',
    ),
    'flag_short' => 'Make this item the initial survey for this cohort',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item - remove it as the demographic survey',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'workflow_tab' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'research_study',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Post-reading Survey".
  $flags['post_reading_survey'] = array(
    'entity_type' => 'node',
    'title' => 'Post-reading Survey',
    'global' => 1,
    'types' => array(
      0 => 'webform',
    ),
    'flag_short' => 'Make this item the post-reading survey for the given cohort',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item - remove it as the post-reading survey',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'workflow_tab' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'research_study',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
