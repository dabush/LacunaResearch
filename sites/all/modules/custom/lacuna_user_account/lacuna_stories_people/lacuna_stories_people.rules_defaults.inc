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
      "REQUIRES" : [ "webform_rules", "rules", "php" ],
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
        { "drupal_message" : { "message" : "Welcome to Lacuna Stories. Please tell us about yourself by completing your profile." } },
        { "php_eval" : { "code" : "course_get_selected_course();" } }
      ]
    }
  }');
  $items['lacuna_stories_people_send_user_to_instructions'] = entity_import('rules_config', '{ "lacuna_stories_people_send_user_to_instructions" : {
      "LABEL" : "Send User to Instructions",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "php", "rules", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "demographic_survey_flag",
            "node" : [ "node" ],
            "flagging_user" : [ "user" ]
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "course_get_selected_course();" } },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } },
        { "drupal_message" : { "message" : "Thank you for completing the survey. You may now proceed to the study by clicking on the appropriate icon below." } }
      ]
    }
  }');
  return $items;
}
