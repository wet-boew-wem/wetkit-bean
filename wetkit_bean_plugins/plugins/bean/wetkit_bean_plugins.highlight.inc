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
      'image_settings' => array(
        'image_style' => 'medium',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['image_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Image Style'),
      '#tree' => TRUE,
      '#weight' => 0,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['image_settings']['image_style'] = array(
      '#type' => 'select',
      '#title' => t('Image style'),
      '#options' => array('<none>' => t('None')) + drupal_map_assoc(array_keys(image_styles())),
      '#default_value' => isset($bean->image_settings['image_style']) ? $bean->image_settings['image_style'] : '',
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // Link Field
    $link_path = field_get_items('bean', $bean, 'field_bean_highlight_link');
    if (isset($link_path[0])) {
      $link_url = $link_path[0]['display_url'];
    }

    // Content Fields
    foreach($content['bean'] as &$child) {
      if (isset($link_url)) {
        $child['field_bean_highlight_image'][0]['file']['#prefix'] = '<a href="' . $link_url . '">';
        $child['field_bean_highlight_image'][0]['file']['#suffix'] = '</a>';
      }
    }
    return $content;
  }
}
