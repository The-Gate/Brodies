<?php
/**
 * @file
 * user_roles_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_roles_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Careers-Section.
  $roles['Careers-Section'] = array(
    'name' => 'Careers-Section',
    'weight' => 0,
  );

  // Exported role: Emergency-Page-Login.
  $roles['Emergency-Page-Login'] = array(
    'name' => 'Emergency-Page-Login',
    'weight' => 0,
  );

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 0,
  );

  return $roles;
}
