<doctype>
<html>
<body>
</body>
<ul>
<?php $files = scandir('./');
sort($files); // this does the sorting
$files = array_diff(($files), array('.', '..'));
foreach($files as $file){
   echo'<li><a href="'.$file.'" target="_blank">'.$file.'</a></li>';
}
?>
</ul>
</html>