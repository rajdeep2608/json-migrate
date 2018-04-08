<?php
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


class JSONMigration extends MigrateListJSON {


  /**
   * Return the fields (this is cleaner than passing in the array in the MigrateSourceList class above)
   * @return array
   */
  function fields() {
    return array(
      'title' => 'The title of the content',
      'content' => 'The body of the content',
      'date' => 'Date associated with the content',
      'url' => 'Source url associated with the content',
      'image' => 'Image Source url associated with the content',
      'id' => 'Source ID associated with the content',
    );
  }

  /**
   * Remap fields as needed
   * @param type $row
   */
  function prepareRow($row) {
    //rewrite the date as a timestamp
    list($year, $month, $day) = explode('-', $row->date);
    $row->date = mktime(0, 0, 0, $month, $day, $year);
  }

}
