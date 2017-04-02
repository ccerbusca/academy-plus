<?php

class Lannister
{
    public function yes()
    {
        return 3;
    }
    public function sleepWith($c)
    {
        if (method_exists($c, 'yes')) 
        {
            if ($c->yes() == 1 || $c->yes() == 2)
                echo "Not even if I'm drunk !\n";
            else
                if (static::yes() == 1)
                    echo "With pleasure, but only in a tower in Winterfell, then.\n";
                else echo "Not even if I'm drunk !\n";
        }
        else echo "Let's do this.\n";
    }
}

?>