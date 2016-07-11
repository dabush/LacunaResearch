<?php
/**
 * @file
 * research_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function research_study_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
