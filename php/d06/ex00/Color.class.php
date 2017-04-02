<?php
Class Color {
    public $red;
    public $green;
    public $blue;
    public static $verbose = FALSE;
    function __construct(array $kwargs)
    {
        if (array_key_exists('rgb', $kwargs))
        {
            $this->blue = intval($kwargs['rgb']) % 256;
            $kwargs['rgb'] = intval($kwargs['rgb']) / 256;
            $this->green = intval($kwargs['rgb']) % 256;
            $kwargs['rgb'] = intval($kwargs['rgb']) / 256;
            $this->red = intval($kwargs['rgb']);
        }
        else 
        {
            if (array_key_exists('red', $kwargs))
                $this->red = intval($kwargs['red']);
            if (array_key_exists('green', $kwargs))
                $this->green = intval($kwargs['green']);
            if (array_key_exists('blue', $kwargs))
                $this->blue = intval($kwargs['blue']);
        }
        if (self::$verbose == TRUE)
            echo 'Color( red: '. str_pad($this->red, 3, " ", STR_PAD_LEFT)
                . ', green: ' . str_pad($this->green, 3, " ", STR_PAD_LEFT)
                . ', blue: ' . str_pad($this->blue, 3, " ", STR_PAD_LEFT)
                . ' ) constructed.' . PHP_EOL;
    }
    function __destruct()
    {
        if (self::$verbose == TRUE)
            echo 'Color( red: '. str_pad($this->red, 3, " ", STR_PAD_LEFT)
                . ', green: ' . str_pad($this->green, 3, " ", STR_PAD_LEFT)
                . ', blue: ' . str_pad($this->blue, 3, " ", STR_PAD_LEFT)
                . ' ) destructed.' . PHP_EOL;
    }

    function    __toString()
    {
        return 'Color( red: '. str_pad($this->red, 3, " ", STR_PAD_LEFT)
                . ', green: ' . str_pad($this->green, 3, " ", STR_PAD_LEFT)
                . ', blue: ' . str_pad($this->blue, 3, " ", STR_PAD_LEFT) . ' )';
    }
    function    add(Color $aux)
    {
        $new = new Color(array(
            'red' => ($this->red + $aux->red),
            'green' => ($this->green + $aux->green),
            'blue' => ($this->blue + $aux->blue)));
        return ($new);
    }
    function    sub(Color $aux)
    {
        $new = new Color(array(
            'red' => ($this->red - $aux->red),
            'green' => ($this->green - $aux->green),
            'blue' => ($this->blue - $aux->blue)));
        return ($new);
    }
    function    mult($f)
    {
        $new = new Color(array(
            'red' => ($this->red * $f),
            'green' => ($this->green * $f),
            'blue' => ($this->blue * $f)));
        return ($new);
    }
    static function doc()
    {
        echo file_get_contents("Color.doc.txt");
    }
}
?>