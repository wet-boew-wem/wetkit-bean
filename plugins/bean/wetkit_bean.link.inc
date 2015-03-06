<?php
/**
 * @file
 * A bean link plugin.
 */

class WetKitLinkBean extends BeanPlugin {

  /**
   * Implements BeanPlugin::values().
   */
  public function values() {
    return array();
  }

  /**
   * Implements BeanPlugin::form().
   */
  public function form($bean, $form, &$form_state) {

    return $form;
  }

  /**
   * Implements BeanPlugin::view().
   */
  public function view($bean, $content, $view_mode = 'full', $langcode = NULL) {

    // Tile Field.
    $title = field_get_items('bean', $bean, 'title_field');
    $title = field_view_value('bean', $bean, 'title_field', $title[0], array());
    $title = render($title);

    // Links Field.
    $links_markup = '';
    $links = field_get_items('bean', $bean, 'field_bean_link');
    foreach ($links as $key => $val) {
      $links_tmp = field_view_value('bean', $bean, 'field_bean_link', $links[$key], array());
      $links_markup = '<li>' . render($links_tmp) . '</li>';
    }

    // Reset content.
    $content = array();

    // Rendered markup.
    $markup = '<section class="pillars mrgn-tp-md mrgn-bttm-md">';
    $markup .= '<h2>' . $title . '</h2>';
    $markup .= '<ul>' . $links_markup . '</ul>';
    $markup .= '</section>';

    $content['links']['#markup'] = $markup;

    return $content;
  }

  /**
   * Implements BeanPlugin::submit().
   */
  public function submit(Bean $bean) {
    return parent::submit($bean);
  }
}
