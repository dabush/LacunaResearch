<?php
/**
 * @file
 * lacuna_stories_people.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function lacuna_stories_people_default_rules_configuration() {
  $items = array();
  $items['lacuna_stories_irb_form_send_user_to_appropriate_survey'] = entity_import('rules_config', '{ "lacuna_stories_irb_form_send_user_to_appropriate_survey" : {
      "LABEL" : "Send User to Appropriate Survey",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "webform_rules", "rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "webform_has_id" : {
            "form_id" : [ "form_id" ],
            "selected_webform" : { "value" : { "webform-client-form-1" : "webform-client-form-1" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "demographic-survey" } },
        { "drupal_message" : { "message" : "Welcome to Lacuna Stories. Please tell us about yourself by completing your profile." } }
      ]
    }
  }');
  $items['lacuna_stories_people_send_user_to_instructions'] = entity_import('rules_config', '{ "lacuna_stories_people_send_user_to_instructions" : {
      "LABEL" : "Send User to Instructions",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [ { "text_matches" : { "text" : [ "node:title" ], "match" : "Survey" } } ],
      "DO" : [
        { "php_eval" : { "code" : "course_get_selected_course();" } },
        { "redirect" : { "url" : "lacuna-instructions" } },
        { "drupal_message" : { "message" : "Welcome to Lacuna Stories. Please tell us about yourself by completing your profile." } }
      ]
    }
  }');
  return $items;
}
