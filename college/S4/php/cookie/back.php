<?php
$visits = isset($_COOKIE['visits']) ? (int)$_COOKIE['visits'] : 0;
$visits++;
setcookie('visits', $visits, time() + (365 * 24 * 60 * 60));
?>

<html>
<body>

<div align=center>
    <h1>Cookies</h1>

        <?php if ($visits > 1): ?>
            <p>visit number <?= htmlspecialchars($visits) ?></p>
        <?php endif; ?>
            <a href="">HIT</a>
</div>
</body>
</html>
