<?php
/**
 * @file
 * lacuna_stories_menus.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function lacuna_stories_menus_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course_context_part';
  $context->description = 'Course Context for Participants';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'Participant' => 'Participant',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-3' => array(
          'module' => 'superfish',
          'delta' => '3',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
    'region' => array(
      'lacuna_stories' => array(
        'disable' => array(
          'header' => 'header',
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Course Context for Participants');
  $export['course_context_part'] = $context;

  return $export;
}
