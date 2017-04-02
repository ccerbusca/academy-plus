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
for($i = 1;$i < $k;$i++)
    foreach ($aux[$i] as $elem)
    {
        $tab[$j] = $elem;
        $j++;
    }

$alp = 0;
$cif = 0;
$oth = 0;

for($i = 0; $tab[$i]; $i++)
{
    if (ctype_alpha($tab[$i]))
    {
        $alpha[$alp] = $tab[$i];
        $alp++;
    }
    else if (is_numeric($tab[$i]))
    {
        $numeric[$cif] = $tab[$i];
        $cif++;
    }
    else
    {
        $other[$oth] = $tab[$i];
        $oth++;
    }
}

natcasesort($alpha);
sort($numeric, SORT_STRING);
natcasesort($other);
foreach ($alpha as $elem)
    echo "$elem\n";
foreach ($numeric as $elem)
    echo "$elem\n";
foreach ($other as $elem)
    echo "$elem\n";
?>
