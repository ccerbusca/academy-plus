#!/usr/bin/php
<?php

echo "Entrez un nombre : ";
while ($aux = fgets(STDIN))
{
	$nr = trim($aux);
	if (!is_numeric($nr))
		echo "'$nr' n'est pas un chiffre\n";
	else
	{
		if ($nr % 2 == 0)
		{
			echo "Le chifre $nr est Pair\n";
		}
		else
		{
			echo "Le chifre $nr est Impair\n";
		}
	}
	echo "Entrez un nombre : ";
}
echo "^D\n";
?>
