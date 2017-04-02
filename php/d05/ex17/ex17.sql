SELECT COUNT(*) as 'nb_abo',FLOOR(AVG(prix)) as 'moy_abo', MOD(SUM(duree_abo), 42) as 'ft' FROM abonnement;
