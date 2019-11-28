#include "sequence.h"
#include "distance.h"


typedef struct famille FAMILLE;
struct famille {
	SEQUENCE * groupe;
	float dMin;
	int nb_famille;
};
typedef struct ensemble_famille TAB_FAMI;
struct ensemble_famille{
	FAMILLE * f;
	int nb_f;
};

void affiche_famille (FAMILLE F);
void regrouperFamille (SEQUENCE TAB_SEQ [N_SEQ]);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float distanceMin (SEQUENCE TAB_SEQ[N_SEQ]);
SEQUENCE sequence_s (SEQUENCE TAB_SEQ [N_SEQ]);
int max_indice (int tab[20]);
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ], SEQUENCE S);
void recherche_sequence_seul(SEQUENCE TAB_SEQ [N_SEQ]);
