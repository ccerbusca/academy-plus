#!/usr/bin/php
<?php

$tab = preg_replace("/\s+/", " ", $argv[1]);

if ($argc == 1)
	return ;
$tab = trim($tab);
echo "$tab\n";

?>
