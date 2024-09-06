#define NUM_EOLIENNES 10
#define JOURS_ANNEE 365

// Structure pour représenter une éolienne
typedef struct {
    bool en_panne; // Indique si l'éolienne est en panne
    int jours_restants_maintenance; // Nombre de jours restants pour la maintenance
} Eolienne;

bool estEnPanne(int vent); // Fonction pour déterminer si l'éolienne est en panne
int vent_dem(int *jour_vent); // Fonction pour simuler la transition du vent
float production_eolienne(int vent); // Fonction pour calculer la production d'une éolienne
void maintenance(int *cout, int *cout_maintenance, int jour_vent, Eolienne *eolienne); // Fonction pour effectuer la maintenance sur une éolienne
void simuler_1_jour(int k, Eolienne *parc_eolien, int *jour_vent, float *production_par_jour, int *cout, int *cout_maintenance);// Fonction pour simuler une journée du parc éolien
