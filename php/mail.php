<?php 
$to = "admin@rccoder.net";
$subject = "TEST";
$message = "Hello";
$from = "ysbinang@qq.com";
$headers = "From:hah";
mail($to, $subject, $message, $from, $headers);
echo "Mail sent Already!";
 ?>