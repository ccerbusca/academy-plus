<?php
function auth($login, $passwd)
{
	$aux = file_get_contents("../private/passwd");
	$tab = unserialize($aux);
	foreach($tab as $elem)
	{
		if ($elem['login'] == $login)
		{
			if ($elem['passwd'] == hash("whirlpool", $passwd))
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (FALSE);
}
?>
