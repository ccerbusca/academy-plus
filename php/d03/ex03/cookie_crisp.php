<?php
$action = $_GET['action'];
if ($action == "set")
	setcookie($_GET['name'], $_GET['value'], time() + (86400 * 30));
if ($action == "get")
	if ($_COOKIE[$_GET['name']])
		echo $_COOKIE[$_GET['name']]."\n";
if ($action == "del")
	setcookie($_GET['name'], "", 0);
?>
