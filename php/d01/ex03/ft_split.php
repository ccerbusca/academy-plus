<?php
function ft_split($k)
{
	$tab = preg_split("/\s+/", $k);
	sort($tab);
	return ($tab);
}
?>
