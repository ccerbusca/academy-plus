<?php

Class Vertex {
    private $_x;
    private $_y;
    private $_z;
    private $_w;
    private $_color;
    public static $verbose = FALSE;
    function __construct(array $kwargs)
    {
        if (!array_key_exists('x', $kwargs) || !array_key_exists('y', $kwargs)
            || !array_key_exists('z', $kwargs))
            return;
        $this->_x = $kwargs['x'];
        $this->_y = $kwargs['y'];
        $this->_z = $kwargs['z'];
        if (array_key_exists('color', $kwargs))
            $this->_color = $kwargs['color'];
        else
            $this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
        if (array_key_exists('w', $kwargs))
            $this->_w = $kwargs['w'];
        else
            $this->_w = 1.0;
        if (self::$verbose == TRUE) {
            echo sprintf("Vertex( x: %.2f, y: %.2f, z: %.2f, w: %.2f", $this->_x, $this->_y,
                $this->_z, $this->_w);
            if (self::$verbose == TRUE)
                echo sprintf(', %s', $this->_color);
            echo ' ) constructed' . PHP_EOL;
        }
    }
    function __destruct()
    {
        echo sprintf("Vertex( x: %.2f, y: %.2f, z: %.2f, w: %.2f", $this->_x, $this->_y,
            $this->_z, $this->_w);
        if (self::$verbose == TRUE)
            echo sprintf(', %s', $this->_color);
        echo ' ) destructed' . PHP_EOL;
    }
    static function doc()
    {
        echo file_get_contents("Vertex.doc.txt");
    }
    function __toString()
    {
        $str = sprintf("Vertex( x: %.2f, y: %.2f, z: %.2f, w: %.2f", $this->_x, $this->_y,
            $this->_z, $this->_w);
        if (self::$verbose == TRUE)
            $str .= sprintf(', %s', $this->_color);
        $str .= ' )';
        return $str;
    }
    public function setX($x)
    {
        $this->_x = $x;
    }
    public function getX()
    {
        return $this->_x;
    }
    public function setY($y)
    {
        $this->_y = $y;
    }
    public function getY()
    {
        return $this->_y;
    }
    public function setZ($z)
    {
        $this->_z = $z;
    }
    public function getZ()
    {
        return $this->_z;
    }
    public function setW($w)
    {
        $this->_w = $w;
    }
    public function getW()
    {
        return $this->_w;
    }
    public function setColor(Color $col)
    {
        $this->_color = $col;
    }
    public function getColor()
    {
        return $this->_color;
    }
}
?>