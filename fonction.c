#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "fonction.h"

// Matrice de transition de la force du vent
double matrice_transition[3][3] = {
    {0.2, 0.73, 0.07},
    {0.11, 0.74, 0.15},
    {0.04, 0.61, 0.35}
};

bool estEnPanne(int vent) { // Fonction pour déterminer si l'éolienne va tomber en panne
    float probabilitePanne = 0.15;
    if (vent == 2) {
        double randomValue = (double)rand() / RAND_MAX;
        return randomValue < probabilitePanne;
    }
    return false;
}

int vent_dem(int *jour_vent) { // Fonction pour simuler la transition du vent
    double proba = (double)rand() / RAND_MAX;
    double p = 0;
    int vent = *jour_vent;  // Initialisation du vent avec la valeur actuelle

    for (int i = 0; i < 3; i++) {
        if (p > proba) {
            *jour_vent = i;
            return i;
        } else {
            p += matrice_transition[vent][i];  // Utilisation de la valeur actuelle du vent
        }
    }
}

float production_eolienne(int vent) { // Fonction pour calculer la production d'une éolienne
    switch (vent) {
        case 0:
            return 0.0;
        case 1:
            return 0.4;
        case 2:
            return 0.65;
    }
}

void maintenance(int *cout, int *cout_maintenance, int jour_vent, Eolienne *eolienne) { // Fonction pour effectuer la maintenance sur une éolienne
    if (estEnPanne(jour_vent) && eolienne->jours_restants_maintenance == 0) {
        *cout += *cout_maintenance;
        eolienne->jours_restants_maintenance += 3;
    } else if (estEnPanne(jour_vent) && eolienne->jours_restants_maintenance != 0) {
        eolienne->jours_restants_maintenance -= 1;
    }
}

void simuler_1_jour(int k, Eolienne *parc_eolien, int *jour_vent, float *production_par_jour, int *cout, int *cout_maintenance) { // Fonction pour simuler une journée du parc éolien
    double production_eol = 0;
    int panne = 0;
    float prod_1_eol;
    if (k == 0){
        *jour_vent = 0;
    }
    else {
        vent_dem(jour_vent);   
    }

    for (int i = 0; i < NUM_EOLIENNES; i++) {
        parc_eolien[i].en_panne = estEnPanne(*jour_vent);
        maintenance(cout, cout_maintenance, *jour_vent, &parc_eolien[i]);

        if (parc_eolien[i].en_panne == true) {
                        panne += 1;
        }
    }
    prod_1_eol = production_eolienne(*jour_vent);
    production_eol = (NUM_EOLIENNES - panne) * prod_1_eol;
    production_par_jour[k] = production_eol;
}
