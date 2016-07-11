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
          'region' => 'header',
          'weight' => '-10',
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
