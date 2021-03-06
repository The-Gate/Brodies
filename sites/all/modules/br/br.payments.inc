<?php

function br_payments($stage = '', $id = '', $key = '') {
  
  switch ($stage) {
    default:
      $out = '<div class="payment-intro"><h2>Please select what type of invoice you would like to pay</h2><a class="option first" href="/payments/invoice">PAY A BRODIES INVOICE</a><a class="option" href="/payments/dart">DART ONLINE PAYMENT<br />(DEBT & ASSET RECOVERY TEAM)</a><div class="ff"></div>
      <p>The transfer of the payment details from the Brodies web site to WorldPay are encapsulated using their own encrypted and digitally-signed protocol. This ensures that the information passed is both secure and tamper-proof.<br /><br />A 2% surcharge for payments made by credit card is applied at the payment confirmation page. There will be no charge for debit card transactions.</p></div><div id="cards"></div>';
      break;
    case 'invoice':
    case 'dart':
      $out = '<div class="payment-form">'. drupal_get_form('br_payment_form', $stage) .'</div>';
      break;
    case 'card-type':    
      $out = '<div class="payment-form">'. drupal_get_form('br_payment_card_form', $stage) .'</div>';
      break;  	  
    case 'payment':
      $node = node_load($id);
      if ($node->type == 'payment') {
        if (md5($node->title) == $key) {                    
          return drupal_get_form('br_worldpay_payment_form', $node);          
        }
      }
      drupal_set_message('Wrong payment URL', 'error');
      drupal_access_denied();      
      break;
       
    case 'response':
      return br_worldpay_response();
      break;       
  }
  return $out .'<script type="text/javascript" src="https://sealserver.trustwave.com/seal.js?code=3236d3088f5746ea8c7de2d8bf7af319"></script>';   
}

function br_payment_form($form_init, $stage) {
  $form = array();
  
  $result = db_query("SELECT i.field_name, label, required FROM content_node_field_instance i left join content_node_field f on f.field_name = i.field_name where i.type_name = 'payment' order by i.weight");
  
  $count = 0;
  while ($data = db_fetch_object($result)) {       
    if (array_search($data->field_name, array('field_pay_status', 'field_pay_data', 'field_pay_card')) !== FALSE) {
      continue;
    }
    
    $form[$data->field_name] = array(
      '#type' => 'textfield',
      '#title' => $data->label,
      '#required' => $data->required,   
      '#prefix' => '<div class="'. ($count % 2 == 1?'odd':'even') .'">',
      '#suffix' => '</div>',   
    );
    if ($data->field_name == 'field_pay_type') {
      $form[$data->field_name]['#value'] = $stage == 'invoice'?1:2;      
      $form[$data->field_name]['#type'] = 'value';
      continue;
    }
    
    if ($data->field_name == 'field_pay_comments') {
      $form[$data->field_name]['#type'] = 'textarea';
      $form[$data->field_name]['#resizable'] = FALSE;
    }
    
    if ($data->field_name == 'field_pay_reference') {
      $form[$data->field_name]['#description'] = 'Can be found on our correspondence';
      $form[$data->field_name]['#title'] = $stage == 'invoice'?'Brodies Invoice Reference number':'DART Reference number';
      if ($stage != 'invoice') {
        //$form[$data->field_name]['#description'] = 'Can be found on our correspondence';
      }
    }    
    if ($data->field_name == 'field_pay_amount') {
      $form[$data->field_name]['#description'] = '- 2% surcharge for payments made by credit card, there will be no charge for debit card transactions.';
    }
    
    if ($data->field_name == 'field_pay_email') {
      $count++;
      $form[$data->field_name.'_check'] = array(
        '#type' => 'textfield',
        '#title' => 'Email address verification',
        '#required' => TRUE,   
        '#prefix' => '<div class="'. ($count % 2 == 1?'odd':'even') .'">',
        '#suffix' => '</div>',           
      );      
    }
    
    $count ++;
  }

  $form['terms'] = array(
    '#type' => 'checkbox',
    '#title' => 'I accept the <a href="/legal-statement" target="_blank">(online payment terms and conditions)</a>',    
  );
  
  $form['suffix'] = array('#value' => '<div class="ff"></div><div class="label"><span title="This field is required." class="form-required">*</span> Denotes mandatory fields</div>');
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $stage == 'invoice'?'PAY INVOICE':'Make payment',
  );
  
  return $form;
}

function br_payment_form_validate($form_state, $form_values) {
  $vals = $form_values['values'];
  if (!is_numeric($vals['field_pay_amount'])) {
    form_set_error("field_pay_amount", "Please enter numeric value with dot as decimal point");
  }

  if (!$vals['terms']) {
    form_set_error("terms", "You must accept terms and conditions.");
  }
  
  if (!valid_email_address($vals['field_pay_email'])) {
    form_set_error("field_pay_email", "Please enter valid email address");
  }
  else {
    if ($vals['field_pay_email'] != $vals['field_pay_email_check']) {
      form_set_error("field_pay_email_check", "Please enter correct email address");
    }
  }
  
  if ($vals['field_pay_type'] == 2) {
    if (!preg_match("/[A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9].[0-9][0-9][0-9][0-9][0-9]/", $vals['field_pay_reference'])) {
      form_set_error("field_pay_reference", "Please enter the reference in correct format :  AAA0000.00000");  
    }
  }
  
  if ($vals['field_pay_type'] == 1) {
    if (!preg_match("/[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]/", $vals['field_pay_reference'])) {
      form_set_error("field_pay_reference", "Please enter the reference in correct format :  123456789 (9 digits)");  
    }
  }
  
  if ($vals['field_pay_type'] == 2) {
    if ($vals['field_pay_amount'] < 5) {
      form_set_error("field_pay_amount", "Minimum amount you can  pay is &pound;5");
    }
    
    if ($vals['field_pay_amount'] > 5000) {
      form_set_error("field_pay_amount", "Maximum amount you can pay is &pound;5000");
    }
  }
}

function br_payment_form_submit($form_state, $form_values) {
  $vals = $form_values['values'];  
  
  foreach ($vals as $key => $value) {
    if (strpos($key, 'field_') !== FALSE) {
      $_SESSION['payment'][$key] = $value;
    }
  }
  drupal_goto('payments/card-type');
}

function br_payment_card_form($form_state, $form_values) {
  $form['card-type'] = array(
    '#type' => 'select',
    '#title' => 'Payment method',
    '#options' => array('' => 'Please select', '1' => 'Visa/Mastercard (2% charge)', '2' => 'Visa Debit/Electron/Maestro/Solo'),
	'#required' => TRUE
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $_SESSION['payment']['field_pay_type'] == 1?'PAY INVOICE':'Make payment',
    '#attributes' => array('style' => 'position:relative;top:0px;float:right;'),
    '#prefix' => '<div class="ff"></div>'
  );
  
  return $form;
}

function br_payment_card_form_submit($form_state, $form_values) {
  $vals = $_SESSION['payment'];
  $vals['field_pay_card'] = $form_values['values']['card-type'];
  $new_node = (object) NULL;
  $new_node->type = 'payment';
  $new_node->title = 'Payment - '. ($vals['field_pay_type'] == 1?'Invoice':'Dart') .' - '. $vals['field_pay_reference'];
  $new_node->uid = 1; //saved as superadmin
  $new_node->created = time();
  $new_node->changed = time();
  $new_node->status = 0;
  $new_node->comment = 0;
  $new_node->promote = 0;
  $new_node->moderate = 0;
  $new_node->sticky = 0;    
  $new_node->body = '';       
    
  $new_node->field_l_left[0]['value'] = $row->strDisplayName;
  foreach ($vals as $key => $value) {
    if (strpos($key, 'field_') === 0) {
      $new_node->{$key}[0]['value'] = $value;
    }
  }
  $new_node->{'field_pay_status'}[0]['value'] = 1;
  node_save($new_node);         
  
  drupal_goto(br_payment_url($new_node));
}

function br_payment_url($node) {
  $key = md5($node->title);
  return 'payments/payment/'. $node->nid .'/'. $key;
}

function br_admin_payments_list() {
  $order = $out = $joins = $thumb = $filters = $filter_text = '';  
  $filter_names = $args = array();
  $rpp = 20;  
  
  switch ($type) {                   
     default:
        $sql = "SELECT n.changed, n.nid, n.title, p.* FROM {node} n LEFT join content_type_payment p on p.vid = n.vid WHERE type='payment' ORDER BY n.changed DESC";
        break;            
  }
      
  $result = pager_query($sql, $rpp, 0, NULL, $args);    
  
  $count = 0;   
  
  while ($data = db_fetch_object($result)) {
    $count++;      
    
    $temp = array();
    $contact = array('Name' => $data->field_pay_name_value, 'Landline' => $data->field_pay_phone_value, 'Mobile' => $data->field_pay_number_value, 'Address 1' => $data->field_pay_address1_value, 'Address 2' => $data->field_pay_address2_value, 'City' => $data->field_pay_city_value, 'Postcode' => $data->field_pay_postcode_value, 'Email' => $data->field_pay_email_value);
    
    foreach ($contact as $key => $value) {
      if ($value) {
        $temp[] = '<i>'. $key .':</i> '. $value;
      }
    }
    $contact = $temp;
    $statuses = array(1 => 'Started', 2 => 'Completed', 3 => 'Cancelled', 4 => 'Pending');
    $rows[] = array(
      date('h:i:s d/m/Y', $data->changed),
      ($data->field_pay_type_value == 1?'Invoice':'DART'),
      array('data' => $data->field_pay_reference_value),
      $data->field_pay_company_value,
      implode('<br />', $contact),
      $data->field_pay_comments_value,
      $data->field_pay_amount_value,      
      '<b>'. $statuses[$data->field_pay_status_value] .'</b>',
      array('data' => l('Pay', br_payment_url((object)array('title' => $data->title, 'nid' => $data->nid))), 'style' => 'text-align:center')
    );
  }      
  
  if ($count) {    
    $out = theme('pager', NULL, $rpp, 0) . theme('table', array('time', 'type', 'reference', 'company', 'contact', 'comments', 'amount', 'status', 'payment page'), $rows);  
  }
  else {
    $out = '<div class="message">'. t('No payments created') .'</div>';
  }

  return '
    <style>
      .listing.payments {
        /*width:120%;
        margin-left:-10%*/
      }
      
      .listing.payments table td{
        padding:10px;
      }
    </style>
<div class="listing payments">'. $filter_text . $out .'<div class="ff"></div></div>';
}

function br_admin_payments_settings_form() {
  $form['payment_worldpay_test'] = array(
    '#type' => 'checkbox',
    '#title' => t('Worldpay test mode'),
    '#default_value' => variable_get('payment_worldpay_test', FALSE),
  );
  
  $form['payment_worldpay_test_result'] = array(
    '#type' => 'select',
    '#title' => t('Test mode result'),
    '#description' => t('Specify the required transaction result when working in test mode.'),
    '#default_value' => variable_get('payment_worldpay_test_result', 'AUTHORISED'),
    '#options' => array('AUTHORISED' => 'Authorised', 'REFUSED' => 'Refused', 'ERROR' => 'Error', 'CAPTURED' => 'Captured'),
    '#disabled' => (!variable_get('uc_worldpay_test', TRUE)) ? TRUE : FALSE,
  );
  
  $form['payment_worldpay_desc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Submit the cart contents as the order description'),
    '#description' => t('Setting this option to true will display the cart contents on the payment page. This could help to reassure customers of exactly what they are paying for.'),
    '#default_value' => variable_get('payment_worldpay_desc', FALSE),
  );
  
  $form['uc_worldpay_md5'] = array(
    '#type' => 'textfield',
    '#title' => t('MD5 secret word'),
    '#description' => t('Secure your WorldPay account so only your server can send transactions to WorldPay. N.B. This needs to be configured on your WorldPay account first.'),
    '#size' => 20,
    '#maxlength' => 255,
    '#default_value' => variable_get('uc_worldpay_md5', ''),
  );  

  $form['uc_worldpay_edit_contact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable editing of contact details on the payment page.'),
    '#default_value' => variable_get('uc_worldpay_edit_contact', TRUE),
  );
  
  $form['uc_worldpay_show_contact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the contact details on the payment page.'),
    '#default_value' => variable_get('uc_worldpay_show_contact', TRUE),
    '#disabled' => variable_get('uc_worldpay_show_contact', TRUE),
  );

  $form['uc_worldpay_debug'] = array(
    '#type' => 'select',
    '#title' => t('Debug mode'),
    '#multiple' => FALSE,
    '#options' => array('log' => t('Log'), 'screen' => t('Screen'), 'both' => t('Both'), 'none' => t('None')),
    '#default_value' => variable_get('uc_worldpay_debug', 'log'),
  );
        
  return system_settings_form($form);
}

function br_admin_payments_settings() {
  return drupal_get_form('br_admin_payments_settings_form');
}

function br_worldpay_payment_form($form_state, $payment_node) {

  $data = array();
  if (variable_get('payment_worldpay_test', TRUE)) { //test mode
    $worldpay_name = variable_get('payment_worldpay_test_result', 'AUTHORISED');; 
    $data = array(
      'testMode' => '100',
    );
  }
  else {
    $worldpay_name = $payment_node->field_pay_name[0]['value'];
  }      
    
  $amount = $payment_node->field_pay_amount[0]['value'];  
  $amount = $payment_node->field_pay_card[0]['value'] == 1?$amount * 1.02:$amount;	
	
  $data += array(
    'instId' => $payment_node->field_pay_type[0]['value'] == 1 ? 233770 : 298854,
    'amount' => $amount,
    'cartId' => $payment_node->nid,
    'currency' => 'GBP',
    'name' =>  $worldpay_name, //cardholder name
    'address' => ($payment_node->field_pay_address1[0]['value'] ? $payment_node->field_pay_address1[0]['value'] .',' : "\n")
               . ($payment_node->field_pay_address2[0]['value'] ? $payment_node->field_pay_address2[0]['value'] .',' : "\n")
               . ($payment_node->field_pay_city[0]['value'] ? $payment_node->field_pay_city[0]['value'] .'' : "\n")
               ,
    'state' => '', //uc_get_zone_code($order->billing_zone),
    'postcode' => $payment_node->field_pay_postcode[0]['value'], 
    'country' => 'GB', 
    'email' => $payment_node->field_pay_email[0]['value'],
    'tel' => $payment_node->field_pay_phone[0]['value'], 
    'M_uc_cart_id' => $payment_node->nid,
    'lang' => variable_get('payment_worldpay_lang', 'en-GB'),
    'M_http_host' => $_SERVER['HTTP_HOST'],
  );

  $uc_worldpay_md5 = variable_get('uc_worldpay_md5', '');
  if (!empty($uc_worldpay_md5)) {
    $data += array('signatureFields' => 'currency:cartId:amount');
    $data += array('signature' => md5($uc_worldpay_md5 . ':GBP:'. $payment_node->nid .':' . $amount));
  }
  
  if (variable_get('payment_worldpay_desc', FALSE)) {
    $data += array(
      'desc' => ($payment_node->field_pay_type[0]['value'] == 1 ?'Invoice Payment':'DART Payment') .' : reference - '. $payment_node->field_pay_reference[0]['value']
    );
  }
   
  if (!variable_get('uc_worldpay_edit_contact', TRUE)) {
    $data += array(
      'fixContact' => '',
    );
  }

  
  if (!variable_get('uc_worldpay_show_contact', TRUE)) {
    $data += array(
      'hideContact' => '',
    );
  } 

  foreach ($data as $name => $value) {
    $form[$name] = array(
      '#type' => 'hidden',
      '#value' => $value,      
    );
  }

  $test_server = 'https://select-test.worldpay.com/wcc/purchase';
  $live_server = 'https://select.worldpay.com/wcc/purchase';
  $form['#action'] = variable_get('payment_worldpay_test', TRUE) ? $test_server : $live_server;    
    
  $form['submit'] = array(    
    '#type'   => 'submit',
    '#name'   => '',        
    '#value'  => t('Proceed with payment'),    
    '#suffix' => '<script>document.forms["br-worldpay-payment-form"].submit();</script>'
  );      
  
  return $form;
}

function br_worldpay_response($cart_id = 0) {
  $cart_id = $_POST['cartId'];
  $amount = $_POST['amount'];
  $trans_status = $_POST['transStatus'];
  $card_type = $_POST['cardType'];
  $uc_cart_id = $_POST['M_uc_cart_id'];
  global $base_url;
  drupal_set_html_head("<base href=\"$base_url/\" />\n");

  // Stop orders being processed for orders from different hosts.
  if ($_SERVER['HTTP_HOST'] != $_POST['M_http_host']) {
    print theme('page', t('There was an error with the transaction. The host did not match.'));
    return;
  }

  // Log a new order notification to watchdog.
  $log_entry = t('New order notification for order !order_id.', array('!order_id' => $cart_id));
  $message = t('Returned parameters: <pre>!post</pre>', array('!post' => print_r($_POST, TRUE)));

  // If debug mode is set appropriately, append the returned parameters to the
  // log entry.
  $debug = variable_get('uc_worldpay_debug', 'log');
  if ($debug == 'log' || $debug == 'both') {
    $log_entry .= '<br/>' . $message;
  }
  watchdog('uc_worldpay', $log_entry);

  // If debug mode is set appropriately, print the returned parameters to the
  // screen.
  if ($debug == 'screen' || $debug == 'both') {
    $output .= $message;
  }
    
  // If the order could not be loaded print an error message and exit.
  if (!$order = node_load($cart_id)) {
    
    drupal_set_message(t('The order could not be found and this transaction cannot continue.'), 'error');
  
    return;
  }

  // If the status of the order is not 'in_checkout' print an error and exit.
  if ($order->field_pay_status[0]['value'] == 2 || $order->field_pay_status[0]['value'] == 4) {
    $page_title = t('Payment already completed');
    $title = t('This payment was already completed, please add another payment.');    
  }
  else {
    $order->field_pay_data[0]['value'] = serialize($_POST);
  
    if (is_numeric($amount)) {
      switch ($trans_status) {
        case 'Y':
          $page_title = t('Payment Complete');
          $title = t('Your payment is complete and confirmed.');        
          $order->field_pay_status[0]['value'] = 2;
          break;
  
        case 'C':
          $page_title = t('Payment Cancelled');
          $title = t('Your payment has been cancelled.');
          drupal_set_message(t('Your order has been cancelled.'));
          $order->field_pay_status[0]['value'] = 3;                
          break;
  
        default:
          $page_title = t('Payment Pending');
          $title = t('Your order is pending.');
          $order->field_pay_status[0]['value'] = 4;        
          break;
      }
    }
  
    node_save($order);
    $admin_email = 'cashroom@brodies.com';
    $params['payment_details'] = br_payment_details_content($order);
    $params['stage'] = $order->field_pay_type[0]['value'];
    if ($order->field_pay_status[0]['value'] == 2) {
      drupal_mail('br', 'payment-complete', $admin_email, language_default(), $params);
    }
    
    if ($order->field_pay_status[0]['value'] == 4) {
      drupal_mail('br', 'payment-pending', $admin_email, language_default(), $params);
    }
  }
  
  print '<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />        
    <title>'. $page_title .' - Payments | Brodies LLP</title>    
  </head><body><div style="text-align:center;margin-bottom:20px;"><a href="http://brodies2.gate-demo.co.uk"><img src="https://secure-test.worldpay.com/i/233770/header.png" alt="Payment gateway" /></a></div><div style="width:400px;margin:30px auto;"><h1 style="font-family:arial;color: #00245D;font-size: 1.4em;">'. $title .'</h1><WPDISPLAY ITEM=banner></div></body></html>';
  exit();
}

function br_payment_details_content($order) {
  $out = '';
  
  $form = br_payment_form('', $order->field_pay_type[0]['value'] == 1?'invoice':'dart');
  foreach ($form as $fname => $data) {
    if (array_search($fname, array('suffix', 'submit')) !== FALSE) continue;
    $val = $order->{$fname}[0]['value'];
    $label = $data['#title'];
    if ($fname == 'field_pay_type') {
      $val = $order->field_pay_type[0]['value'] == 1?'invoice':'dart';
      $label = 'Payment type';
    }
    
    $out .= '<div><b>'. $label .'</b>: '. $val .'</div>';
    if ($fname == 'field_pay_type') {
      $out .= '<div><b>Payment time</b>: '. date('H:i:s d/m/Y', $order->changed) .'</div><br />';
    }
    
    if ($fname == 'field_pay_email') {
      $out .= '<br />';
    }
    
    if ($fname == 'field_pay_amount') {
      $out .= '<br />';
    }
  }

    

  return $out;
}
