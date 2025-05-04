<html>
<body>
<?php

$web = array("arch"=>"cachyos.org", "rpm"=>"fedora.org", "deb"=>"unbuntu.org");

echo "<table border=2 align=center>";
echo "<h2 align=center> major distrutions </h2>";
echo "<br>";
echo "<tr>";
echo "<th> Names of Distro </th>";
echo "<th> links </th>";
echo "</tr>";


foreach ($web as $x=>$y) {
  echo "<tr>";
  echo "<td> $x </td>";
  echo "<td> $y </td>";
  echo "</tr>";
}

echo "</table>";


?>
</body>
</html>
