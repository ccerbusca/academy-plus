#!/usr/bin/php
<?php

if ($argc == 1)
	return ;

$k = 0;

foreach ($argv as $elem)
{
    $aux[$k] = preg_split("/\s+/", $elem);
    $k++;
}

$j = 0;
for($i = 1; $i < $k; $i++)
    foreach ($aux[$i] as $elem)
    {
        $tab[$j] = $elem;
        $j++;
    }

sort($tab);
foreach ($tab as $elem)
    echo "$elem\n";
?>
