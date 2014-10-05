<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

ini_set('SMTP', 'smtp-auth.lumison.net'); 

$to      = 'chris.bobin@gmail.com';
$subject = 'the subject';
$message = 'hello';
$headers = 'From: contact@brodies.com' . "\r\n" .
    'Reply-To: contact@brodies.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();

print(mail($to, $subject, $message, $headers) ? 'ok':'nie');