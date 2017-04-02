#!/usr/bin/php
<?php
date_default_timezone_set("Europe/Paris");
$fd = fopen("/var/run/utmpx", "r");

fread($fd, 1256);
$i = 0;
while ($tab[$i] = fread($fd, 628))
    $i++;
$i = 0;
while ($tab[$i])
{
    $data[$i] = unpack("a256user/a4id/a32line/ipid/itype/i2time/a256host/@", $tab[$i]);
    if ($data[$i][type] == 7) {
        echo trim($data[$i][user])." ";
        echo trim($data[$i][line])."  ";
		echo strftime("%b %e %H:%M %n", $data[$i]["time1"]);
    }
    $i++;
}

?>
