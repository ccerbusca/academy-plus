<?php
function	failure()
{
	echo "ERROR\n";
	exit ;
}
$ok=0;
if ($_POST['submit'] !== "OK" || $_POST['login'] === "" || $_POST['passwd'] ==="")
	failure();
else $ok=1;

if (!file_exists("../private"))
	mkdir("../private");
$aux = file_get_contents("../private/passwd");
$tab = unserialize($aux);
$i = 0;
foreach($tab as $elem)
{
	if ($elem['login'] === $_POST['login'])
		failure();
	$i++;
}
$parola = hash("whirlpool", $_POST['passwd']);
$tab[$i] = array("login" => $_POST['login'], "passwd" => $parola);
$ser = serialize($tab);
file_put_contents("../private/passwd", $ser);
if ($ok == 1)
	echo "OK\n";
?>
