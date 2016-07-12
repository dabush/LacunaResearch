<?php
/**
 * @file
 * research_study.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function research_study_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_manage-surveys:manage-surveys.
  $menu_links['main-menu_manage-surveys:manage-surveys'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'manage-surveys',
    'router_path' => 'manage-surveys',
    'link_title' => 'Manage Surveys',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_manage-surveys:manage-surveys',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 15,
    'customized' => 1,
    'parent_identifier' => 'main-menu_manage:<nolink>/node/add/course',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Manage Surveys');

  return $menu_links;
}
