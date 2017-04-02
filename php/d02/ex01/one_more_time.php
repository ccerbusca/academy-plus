#!/usr/bin/php
<?php
function    get_month($str)
{
    $str = strtolower($str);
    if ($str === "janvier")
        return (1);
    else if ($str === "fevrier")
        return (2);
    else if ($str === "mars")
        return (3);
    else if ($str === "avril")
        return (4);
    else if ($str === "mai")
        return (5);
    else if ($str === "juin")
        return (6);
    else if ($str === "juillet")
        return (7);
    else if ($str === "aout")
        return (8);
    else if ($str === "septembre")
        return (9);
    else if ($str === "octobre")
        return (10);
    else if ($str === "novembre")
        return (11);
    else if ($str === "decembre")
        return (12);
}

$pattern = "/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)[\s]([0-9]{1,2})[\s]([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre)[\s]([0-9]{4})[\s]([0-9]{2})[:]([0-9]{2})[:]([0-9]{2})/";

if (!preg_match($pattern, $argv[1], $dat))
{
    echo "Wrong Format\n";
    exit(0);
}

date_default_timezone_set("Europe/Paris");

$mon = get_month($dat[3]);

echo mktime($dat[5], $dat[6], $dat[7], $mon, $dat[2], $dat[4])."\n";

?>