// Generated by CoffeeScript 1.8.0
var $,
  __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; },
  __hasProp = {}.hasOwnProperty,
  __extends = function(child, parent) { for (var key in parent) { if (__hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor(); child.__super__ = parent.prototype; return child; };

$ = jQuery;

Annotator.Plugin.CommentCount = (function(_super) {
  __extends(CommentCount, _super);

  function CommentCount() {
    this.updateViewer = __bind(this.updateViewer, this);
    return CommentCount.__super__.constructor.apply(this, arguments);
  }

  CommentCount.prototype.options = {
    commentClass: "annotator-comment-count",
    base_url: "drupal7.dev"
  };

  CommentCount.prototype.pluginInit = function() {
    if (!Annotator.supported()) {
      return;
    }
    return this.annotator.viewer.addField({
      load: this.updateViewer
    });
  };

  CommentCount.prototype.updateViewer = function(field, annotation) {
    var link;
    field = $(field);
    field.addClass(this.options.commentClass);
    link = this.options.base_url + annotation.links[0].href;
    if (annotation.comment_count !== "0") {
      return field.html('<a href="' + link + '#comments">' + annotation.comment_count + ' Comments</a><a href="' + link + '#comment-form" class="annotator-new-comment-count-button" title="New Comment">&nbsp;&nbsp;&nbsp;&nbsp;</a>');
    } else {
      return field.html(annotation.comment_count + ' Comments<a href="' + link + '#comment-form" class="annotator-new-comment-count-button" title="New Comment">&nbsp;&nbsp;&nbsp;&nbsp;</a>');
    }
  };

  return CommentCount;

})(Annotator.Plugin);
