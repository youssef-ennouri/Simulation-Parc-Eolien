#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "fonction.h"


int main() {
    srand(time(NULL));

    int cout_maintenance = 150000;
    int cout_total = 0;
    int jour_vent = 0;

    float *production_par_jour;
    production_par_jour = (float *)malloc(JOURS_ANNEE * sizeof(float));

    float production_annuelle = 0;
    float maxi = 0;
    float mini = 1 * NUM_EOLIENNES;

    Eolienne *parc_eolien;
    parc_eolien = (Eolienne *)malloc(NUM_EOLIENNES * sizeof(Eolienne));

    // Initialisation des éoliennes
    for (int i = 0; i < NUM_EOLIENNES; i++) {
        parc_eolien[i].en_panne = false;
        parc_eolien[i].jours_restants_maintenance = 0;
    }

    for (int k = 0; k < JOURS_ANNEE; k++) {
        simuler_1_jour(k, parc_eolien, &jour_vent, production_par_jour, &cout_total, &cout_maintenance);
    }

    // Calcul annuel
    for (int i = 0; i < JOURS_ANNEE; i++) {
        production_annuelle += production_par_jour[i];

        if (production_par_jour[i] >= maxi) {
            maxi = production_par_jour[i];
        }

        if (production_par_jour[i] <= mini) {
            mini = production_par_jour[i];
        }
    }
    float nbr_panne = cout_total/cout_maintenance;
    float nbr_ferme = 3*nbr_panne/NUM_EOLIENNES;
    float moyenne_panne = nbr_panne/JOURS_ANNEE;
    float rendement = 100*(production_annuelle/(0.65*NUM_EOLIENNES*JOURS_ANNEE));
    printf("#######################################################################################\n");
    printf("Pour un parc éolien de %d éoliennes sur %d jours :\n", NUM_EOLIENNES, JOURS_ANNEE);
    printf("La production annuelle du parc est de : %f MW\n", production_annuelle);
    printf("La production journalière maximale du parc est de : %f MW\n", maxi);
    printf("La production journalière minimale du parc est de : %f MW\n", mini);
    printf("Le parc a atteint : %f %% de son rendement maximal\n", rendement);
    printf("Le coût de maintenance total du parc est de : %d euros\n", cout_total);
    printf("Le nombre total de pannes du parc est de : %f pannes\n", nbr_panne);
    printf("C'est comme si le parc avait été fermé pendant : %f jours\n", nbr_ferme);
    printf("Le nombre moyen de pannes d'éoliennes par jour est de : %f pannes par jour\n", moyenne_panne);
    printf("#######################################################################################\n");

    free(parc_eolien);
    free(production_par_jour);

    return 0;
}
