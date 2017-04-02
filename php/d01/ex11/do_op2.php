#!/usr/bin/php
<?php

if ($argc != 2)
{
    echo "Incorrect Parameters\n";
    return ;
}

if (!preg_match("/^[\s]*([\+\-]?[0-9]+)[\s]*([\+\-\/\*\%])[\s]*([\+\-]?[0-9]+)+[\s]*/", $argv[1], $ops))
{
    echo "Syntax Error\n";
    return ;
}

if ($ops[2] == "+")
    echo $ops[1] + $ops[3]."\n";
if ($ops[2] == "*")
    echo $ops[1] * $ops[3]."\n";
if ($ops[2] == "-")
    echo $ops[1] - $ops[3]."\n";
if ($ops[2] == "%")
    echo $ops[1] % $ops[3]."\n";
if ($ops[2] == "/")
    echo $ops[1] / $ops[3]."\n";
?>