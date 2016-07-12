<?php
/**
 * @file
 * research_study.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function research_study_default_rules_configuration() {
  $items = array();
  $items['lacuna_stories_irb_form_send_user_to_study'] = entity_import('rules_config', '{ "lacuna_stories_irb_form_send_user_to_study" : {
      "LABEL" : "Send User to Study",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : {
            "text" : [ "site:current-page:path" ],
            "match" : "^user\\/reset\\/",
            "operation" : "regex"
          }
        },
        { "flag_flagged_user" : {
            "flag" : "irb_form_completed",
            "user" : [ "account" ],
            "flagging_user" : [ "account" ]
          }
        },
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } }
      ],
      "DO" : [
        { "redirect" : { "url" : "study-readings" } },
        { "drupal_message" : { "message" : "Thanks for resuming the study. You can continue where you left off with the reading below." } }
      ]
    }
  }');
  $items['rules_flag_user_after_post_reading_survey'] = entity_import('rules_config', '{ "rules_flag_user_after_post_reading_survey" : {
      "LABEL" : "Flag User After Post-reading Survey",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "post_reading_survey",
            "node" : [ "node" ],
            "flagging_user" : [ "user" ]
          }
        }
      ],
      "DO" : [
        { "flag_flaguser" : {
            "flag" : "user_has_completed_post_reading_",
            "user" : [ "user" ],
            "flagging_user" : [ "user" ],
            "permission_check" : "1"
          }
        }
      ]
    }
  }');
  return $items;
}
