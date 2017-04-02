SELECT titre as 'Titre', resum as 'Resume', annee_prod FROM film
INNER JOIN genre on film.id_genre = genre.id_genre WHERE genre.nom = 'erotic'
ORDER BY annee_prod DESC;
