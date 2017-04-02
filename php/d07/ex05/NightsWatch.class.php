<?php
class NightsWatch
{
    public static $fighters;
    public static $index = 0;

    public function recruit($c)
    {
        if ($c instanceof IFighter)
        {
            self::$fighters[self::$index] = $c;
            self::$index++;
        }
    }
    public function fight()
    {
        foreach (self::$fighters as $elem)
            $elem->fight();
    }
}
?>