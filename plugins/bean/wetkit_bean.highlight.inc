<?php
/**
 * @file
 * Listing bean plugin.
 */

class WetKitHighlightBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'wetkit_bean_highlight_title_settings' => array(
        'classes' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['wetkit_bean_highlight_title_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Title Field'),
      '#tree' => TRUE,
      '#weight' => 1,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['wetkit_bean_highlight_title_settings']['classes'] = array(
      '#description' => t('CSS classes to be added to the title field.'),
      '#type' => 'textfield',
      '#title' => t('CSS'),
      '#default_value' => isset($bean->wetkit_bean_highlight_title_settings['classes']) ? $bean->wetkit_bean_highlight_title_settings['classes'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // Settings.
    $classes = isset($bean->wetkit_bean_highlight_title_settings['classes']) ? $bean->wetkit_bean_highlight_title_settings['classes'] : '';

    // Tile Field.
    $title = field_get_items('bean', $bean, 'title_field');
    $title = field_view_value('bean', $bean, 'title_field', $title[0], array());
    $title = render($title);

    // Link Field.
    $link = field_get_items('bean', $bean, 'field_bean_highlight_link');
    $link = field_view_value('bean', $bean, 'field_bean_highlight_link', $link[0], array());
    $linktitle = $link['#element']['title'];
    $linkurl = $link['#element']['display_url'];

    // Image Field.
    $image = field_get_items('bean', $bean, 'field_bean_highlight_image');
    $image = field_view_value('bean', $bean, 'field_bean_highlight_image', $image[0], array('settings' => array('image_style' => 'activities')));
    $image = render($image);

    // Body Field.
    $body = field_get_items('bean', $bean, 'field_bean_highlight_description');
    $body = field_view_value('bean', $bean, 'field_bean_highlight_description', $body[0], array());
    $body = render($body);

    // Reset content.
    $content = array();

    // Rendered markup.
    $markup = '<section class="col-lg-4 col-md-6"><a href="' . $linkurl . '" rel="external" title="' . $linktitle . '">';
    $markup .= '<h3>' . $title . '</h3>';
    $markup .= $image;
    $markup .= '</a>';
    $markup .= $body . '</section>';

    $content['highlight']['#markup'] = $markup;

    return $content;
  }
}
