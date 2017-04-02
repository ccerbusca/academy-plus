#!/usr/bin/php
<?php

if ($argc == 1)
    return ;

$tab = preg_split("/\s+/", $argv[1]);
for($i = 1; $tab[$i]; $i++)
    echo "$tab[$i] ";
echo "$tab[0]\n";
?>