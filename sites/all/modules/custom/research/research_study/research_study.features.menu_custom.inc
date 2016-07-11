<?php
/**
 * @file
 * research_study.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function research_study_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: devel.
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Development',
    'description' => 'Development link',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Development');
  t('Development link');

  return $menus;
}
