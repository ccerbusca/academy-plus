<?php
session_start();
if ($_GET['submit'])
	$_SESSION['submit'] = $_GET['submit'];
if (!$_SESSION['login'])
	$_SESSION['login'] = $_GET['login'];
if (!$_SESSION['passwd'])
	$_SESSION['passwd'] = $_GET['passwd'];
?>
<html><body>
<form method="get">
	Identifiant: <input type="text" name="login" value="<?php
session_start();
if ($_SESSION['submit'] === "OK")
	echo $_SESSION['login'];
?>">
	<br>
	Mot de passe: <input type="password" name="passwd" value="<?php
session_start();
if ($_SESSION['submit'] === "OK")
	echo $_SESSION['passwd'];
?>">
	<input type="submit" name="submit" value="OK">
</form>
</body></html>
