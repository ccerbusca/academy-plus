<?php

$vars = $_SERVER['QUERY_STRING'];
$i = 0;
$k = 0;
while($vars[$i])
{
	if ($vars[$i] == '=')
	{
		$i++;
		echo ": ";
	}
	if ($vars[$i] == '&')
	{
		$i++;
		echo "\n";
	}
	echo($vars[$i]);
	$k++;
	$i++;
}
if ($vars != "")
	echo "\n";

?>
