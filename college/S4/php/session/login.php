<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $user = $_POST['username'];
    $pass = $_POST['password'];

    if ($user === 'x137' && $pass === 'voldemort') {
        $_SESSION['username'] = $user;
        header("Location: dashboard.php");
        exit();
    } else {
        echo "<body><p>Invalid username or password.</p><a href='index.php'>Try again</a></body>";
    }
}
?>

