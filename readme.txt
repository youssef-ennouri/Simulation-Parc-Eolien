SIMULATION D'UN PARC EOLIEN

#################################################################################################################################

   - Le code est divisé en trois fichiers : "projet.c", "fonction.c", et "fonction.h".
   - "projet.c" est le fichier principal contenant la fonction "main" qui orchestre la simulation du parc éolien sur une année.
   - "fonction.c" regroupe les fonctions spécifiques à la simulation du parc éolien, et "fonction.h" définit les prototypes de ces fonctions ainsi que les structures de données nécessaires.
- Les fonctions ont été regroupées selon leur fonctionnalité dans le fichier "fonction.c". Chaque fonction réalise une tâche spécifique, comme simuler une journée, déterminer si une éolienne est en panne, effectuer la maintenance, etc.
   - Cela permet une approche modulaire et facilite la compréhension, le débogage, et la maintenance du code. Chaque fonction peut être testée indépendamment.

##################################################################################################################################

   - La structure "Eolienne" a été définie pour représenter une éolienne dans le parc. Elle contient deux attributs : "en_panne" pour indiquer si l'éolienne est en panne, et "jours_restants_maintenance" pour suivre le nombre de jours restants pour la maintenance.
   - Les constantes "NUM_EOLIENNES" et "JOURS_ANNEE" sont définies dans le fichier d'en-tête "fonction.h" pour permettre une configuration facile du nombre d'éoliennes dans le parc et de la durée de la simulation.


##################################################################################################################################

   - La simulation de la transition du vent est effectuée par la fonction `vent_dem`. Elle utilise une matrice de transition pour déterminer le nouveau niveau de vent en fonction du niveau actuel. La probabilité de chaque transition est calculée de manière aléatoire.

   - La fonction "maintenance" gère la maintenance des éoliennes en fonction de la probabilité de panne et de la durée de l'intervention. Si une éolienne est en panne, le coût de maintenance est ajouté, et la période de maintenance est mise à jour.

   - La fonction "simuler_1_jour" coordonne la simulation d'une journée pour l'ensemble du parc. Elle utilise les fonctions précédentes pour mettre à jour l'état des éoliennes, calculer la production journalière, et maintenir les coûts à jour.

   - Dans le main, une simulation annuelle est effectué en faisant une boucle sur la fonction "simuler_1_jour" et permet de déterminer les différentes caractéristiques du parc sur cette année (la production totale, la production maximale et minimale journalière, ainsi que le coût total de maintenance.)

##################################################################################################################################

- La simulation de l'état du parc éolien est effectuée en utilisant une liste de structures pour représenter chaque éolienne sur une journée donnée. Le tableau de structures, "parc_eolien," stocke l'état de chaque éolienne, y compris si elle est en panne et le nombre de jours restants pour la maintenance.

- En utilisant cette liste de structures, nous sommes en mesure de suivre l'évolution quotidienne de chaque éolienne et d'extraire des statistiques clés pour l'ensemble du parc. Par exemple, la production journalière, les pannes, et la maintenance sont enregistrées et utilisées pour calculer des métriques telles que la production annuelle, le rendement, le coût total de maintenance, etc.

- L'approche de la liste de structures offre une flexibilité et une facilité de gestion des données, permettant une analyse approfondie de la performance du parc éolien sur l'ensemble de la simulation annuelle. Chaque éolienne est traitée individuellement, ce qui simplifie la logique du programme et facilite l'ajout de fonctionnalités ou l'analyse spécifique à une éolienne.

- La structure "Eolienne" définie dans "fonction.h" contient les attributs nécessaires pour suivre l'état de chaque éolienne, contribuant ainsi à une représentation claire et modulaire de l'ensemble du parc éolien.

- Les variables calculées à partir de la liste de structures, telles que la production annuelle, la production maximale et minimale journalière, le coût total de maintenance, le nombre total de pannes, le nombre moyen de pannes par jour, et le nombre de jours comme si le parc était fermé, sont ensuite affichées dans le rapport final généré par le programme principal ("projet.c").

##################################################################################################################################
