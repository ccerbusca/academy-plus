<?php
if ($_SERVER['PHP_AUTH_USER'] === 0)
{
	header('WWW-Authenticate: Basic realm=\"Private Area\"');
	header('HTTP/1.0 401 Unathorized');
	echo "Bye bye motherfucker\n";
	return ;
}
else
{
	if (($_SERVER['PHP_AUTH_USER'] == 'zaz') && ($_SERVER['PHP_AUTH_PW'] == 'jaimelespetitsponeys'))
		;
	else
	{
		header("WWW-Authenticate: Basic realm=\"Private Area\"");
		header("HTTP/1.0 401 Unauthorized");
		echo "Bye bye motherfucker\n";
		return ;
	}

}
$file = "../img/42.png";
?>
<html><body>
Bonjour Zaz<br />
<?php echo "<img src='data:image/png;base64,";
echo base64_encode(file_get_contents($file))."'>";
header("Content-Type: text/plane");
echo "\n";
?>
</body></html>
