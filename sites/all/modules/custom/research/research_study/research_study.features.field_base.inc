<?php
/**
 * @file
 * research_study.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function research_study_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_instructions_text'.
  $field_bases['field_instructions_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_instructions_text',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
