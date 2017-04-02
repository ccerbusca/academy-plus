<?php

class UnholyFactory
{
    public static $fighter = Array();

    public function absorb($c)
    {
        if ($c instanceof Fighter)
        {
            foreach (self::$fighter as $elem)
                if ($elem == $c)
                {
                    echo '(Factory already absorbed a fighter of type ';
                    $c->__construct;
                    echo $c->getK();
                    echo ')' . PHP_EOL;
                    return ;
                }
            array_push(self::$fighter, $c);
            echo '(Factory absorbed a fighter of type ';
            $c->__construct;
            echo $c->getK();
            echo ')' . PHP_EOL;
        }
        else echo "(Factory can't absorb this, it's not a fighter)\n";
    }
    public function fabricate($str)
    {
        foreach (self::$fighter as $elem)
        {
            $elem->__construct;
            if ($elem->getK() == $str) {
                echo '(Factory fabricates a fighter of type '
                    . $str . ')' . PHP_EOL;
                return ($elem);
            }
        }
        echo '(Factory hasn\'t absorbed any fighter of type '
            . $str . ')' . PHP_EOL;
        return null;
    }
}

?>