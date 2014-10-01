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
      '#collapsed' => TRUE,
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

    $title = field_get_items('bean', $bean, 'title_field');
    $title = field_view_value('bean', $bean, 'title_field', $title[0], array());
    $title = render($title);

    $link = field_get_items('bean', $bean, 'field_bean_highlight_link');
    $link = field_view_value('bean', $bean, 'field_bean_highlight_link', $link[0], array());
    $linktitle = $link['#element']['title'];
    $linkurl = $link['#element']['display_url'];

    $image = field_get_items('bean', $bean, 'field_bean_highlight_image');
    $image = field_view_value('bean', $bean, 'field_bean_highlight_image', $image[0], array());
    $image = render($image);

    $linktext = field_get_items('bean', $bean, 'field_bean_highlight_link_text');
    $linktext = field_view_value('bean', $bean, 'field_bean_highlight_link_text', $linktext[0], array());
    $linktext = render($linktext);

    $content = array();

    $markup = '<a href="' . $linkurl . '" class="sect-lnks thumbnail" rel="external" title="' . $linktitle . '">
                <figure>'
                  . $image .
                  '<figcaption>' . $linktext . '</figcaption>' .
                '</figure>
              </a>';
    $content['highlight']['#markup'] = $markup;

    return $content;
  }
}
