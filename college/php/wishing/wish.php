<html>
<body>
<?php

$wish = date("H");
echo "$wish <br>";

  if ($wish < 12) {
    echo "good morning";
  }
  else if ($wish >= 12 && $wish < 18) {
    echo "good afternoon";
  }
  else {
    echo "good morning";
  }

?>
</body>
</html>
