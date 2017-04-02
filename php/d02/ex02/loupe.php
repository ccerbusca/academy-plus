#!/usr/bin/php
<?php

$line = file_get_contents("$argv[1]");

$j = 0;
$ok = 0;
$ok2 = 0;
while ($line[$j])
{
    if (substr($line, $j, 8) == "<a href=")
    {$ok = 1;}
    else if (substr($line, $j, 4) == "</a>")
    {$ok = 0;$ok2 = 0;}
    if (substr($line, $j, 6) == "title=" && $ok == 1)
    {$ok2 = 1;$j+=7;}
    if ($line[$j] == '"')
        $ok2 = 0;
    if ($line[$j] == '>' && $ok == 1)
        $ok2 = 1;
    if ($line[$j] == '<')
        $ok2 = 0;
    if ($ok2 == 1)
        $line[$j] = ucfirst($line[$j]);
    $j++;
}

echo "$line";

?>