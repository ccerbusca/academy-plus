<?php

abstract class Fighter
{
    private $keepo;
    function __construct($fighter)
    {
        $this->keepo = $fighter;
    }
    abstract function fight($target);
    public function getK()
    {
        return $this->keepo;
    }
}

?>