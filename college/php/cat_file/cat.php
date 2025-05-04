<html>

<h3> contents of the file </h3>
<?php

$myfile = fopen("file.txt", "r") or die("failed"); // fopen(filename, operation[read,write]); 
echo fgets($myfile);
fclose($myfile);

?>

</html>
