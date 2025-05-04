<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: index.php");
    exit();
}
?>
<html>
<body>
    <h2>Welcome, <?= htmlspecialchars($_SESSION['username']) ?>!</h2>
    <p>This is the dashboard.</p>
    <a href="logout.php">Logout</a>
</body>
</html>

