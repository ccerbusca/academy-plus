<?php
function	failure()
{
	echo "ERROR\n";
	exit ;
}
$ok=0;
if ($_POST['submit'] !== "OK" || $_POST['login'] === "" || $_POST['oldpw'] ===""
	|| $_POST['newpw'] == "")
	failure();
else $ok=1;
$aux = file_get_contents("../private/passwd");
$tab = unserialize($aux);
$ok1 = 0;
for($i = 0; $tab[$i]; $i++)
{
	if ($tab[$i]['login'] === $_POST['login'])
	{
		$ok1 = 1;
		break ;
	}
	$i++;
}
if ($ok1 == 0)
	failure();
if ($tab[$i]['passwd'] !== hash("whirlpool", $_POST['oldpw']))
	failure();
$parola = hash("whirlpool", $_POST['newpw']);
$tab[$i] = array("login" => $_POST['login'], "passwd" => $parola);
$ser = serialize($tab);
file_put_contents("../private/passwd", $ser);
if ($ok == 1)
	echo "OK\n";
?>
