SELECT titre, resum
FROM film 
HAVING titre LIKE '%42%' OR resum LIKE '%42%'
ORDER BY duree_min;
