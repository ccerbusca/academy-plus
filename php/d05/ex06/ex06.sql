SELECT titre, resum FROM film WHERE LCASE(resum) LIKE '%vincent%' ORDER BY id_film;
