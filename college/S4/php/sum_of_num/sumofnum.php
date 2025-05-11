<html>
<body>

<h2 align=center>SUM of Digits </h2>
<form method="post">
enter the number: <input type="text" name="num"><br>
<button type="submit">Caculate</button>
</form>

<?php

if($_POST) {
  $num = abs($_POST['num']);
  $sum = 0;

  while ($num > 0) {
    $sum = $sum + $num % 10;
    $num = (int)($num / 10);
  }

  echo "sum of digit is $sum"; 
}

?>



</body>
</html>
