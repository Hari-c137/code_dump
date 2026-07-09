<html>
<body>

<form method="post">
enter number: <input type="text" name="num"> <br>
<button type="submit"> Check </button>
</form>

<?php
if ($_POST) {
  $rev = strrev($_POST['num']);
  if($rev == $_POST['num']) 
    echo "its mea.. palindromo";
  else 
    echo "u an imposter.. get out";
}?>

</body>
</html>
