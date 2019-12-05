#include "sequence.h"
#include "distance.h"

// structure pour stocker un ensemble 
// de sequences appartenant à la même famille, 
typedef struct famille FAMILLE;
struct famille {
	SEQUENCE * groupe;
	float dMin;
	int nb_famille; // nombre de membres de la famille
};
//sturcture pour stocker toutes les differentes familles
typedef struct ensemble_famille TAB_FAMI;
struct ensemble_famille{
	FAMILLE * f;
	int nb_f; // nombre de familles differentes
};
// structure pour stoker un nombre inconnu de sequences
typedef struct tab_p_s TPS;
struct tab_p_s {
	SEQUENCE * tabS;
	int nb_s;
};

void affiche_famille (FAMILLE F);
void regrouperFamilles (SEQUENCE TAB_SEQ [N_SEQ]);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float dis_d_ed_Min (SEQUENCE TAB_SEQ[N_SEQ]); // distance d'edition entre tout le monde 2 à 2
SEQUENCE recheche_S_Dmin (SEQUENCE TAB_SEQ [N_SEQ]); // voir defintion dans le .c
int seq_frequent (TPS T); // Elle retourne le numero de la sequence la plus fréquente dans T 
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ]);
