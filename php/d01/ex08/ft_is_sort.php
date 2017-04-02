<?php

function    ft_is_sort($tab)
{
    $aux = $tab;
    sort($aux);
    $i = 0;
    foreach($aux as $elem)
    {
        if ($tab[$i] != $elem)
            return (FALSE);
        $i++;
    }
    return (TRUE);
}

?>