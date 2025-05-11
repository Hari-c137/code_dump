<html>
<body>

<h2 align=center> factorial </h2>
<form action="" method="post">
enter the number: <input type="text" name="num"></br>
<button type="submit"> Calcuate </button>
</form>


<?php

if($_POST) {
  $number = $_POST['num'];
  $fac = 1;

  while($number > 1) {
    $fac *= $number;
    $number--;
  }

  echo "factorial is : $fac";
}

?>


</body>
</html>
