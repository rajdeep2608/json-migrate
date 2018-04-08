<?php

/**
 * @file
 * File contains migrate APIs.
 */

/*
 * Implements hook_migrate_api()
 */

function qed_city_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'city' => array(
        'title' => t('QED city - 1'),
      ),
    ),
  );
  return $api;
}
