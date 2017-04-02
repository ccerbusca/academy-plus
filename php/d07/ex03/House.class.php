<?php

abstract class House
{
    abstract function getHouseName();
    abstract function getHouseMotto();
    abstract function getHouseSeat();
    public function introduce()
    {
        echo 'House ' . static::getHouseName() . ' of ' . static::getHouseSeat()
            . ' : "' . static::getHouseMotto() . '"' . PHP_EOL;
    }
}

?>