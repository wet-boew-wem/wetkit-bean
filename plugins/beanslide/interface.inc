<?php
/**
 * @file
 * Interface for Bean Slide plugins.
 */

interface WetKitBeanSlidePluginInterface {

  /**
   *
   */
  public function attachments();

  /**
   *
   */
  public function form($settings);

  /**
   *
   */
  public function values();

  /**
   *
   */
  public function submit(&$settings);
}

class WetKitBeanSlideNullPlugin {

  /**
   * Implements WetKitBeanSlidePluginInterface::attachments().
   */
  public function attachments() {}

  /**
   * Implements WetKitBeanSlidePluginInterface::form().
   */
  public function form($settings) {
    return array();
  }

  /**
   * Implements WetKitBeanSlidePluginInterface::values().
   */
  public function values() {
    return array();
  }
}
