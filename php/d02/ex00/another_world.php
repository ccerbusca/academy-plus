#!/usr/bin/php
<?php

trim($argv[1]);
$tab = preg_split("/\s+/", $argv[1]);
for($i = 1; $tab[$i + 1]; $i++)
    echo "$tab[$i] ";
echo "$tab[$i]\n";
?>