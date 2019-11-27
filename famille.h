#include "sequence.h"
#include "distance.h"


typedef struct famille FAMILLE;
struct famille {
	SEQUENCE * groupe;
	float dMin;
	int nb_famille;
};
void affiche_famille (FAMILLE F);
FAMILLE regrouperFamille (FAMILLE f);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float distanceMin (SEQUENCE TAB_SEQ[N_SEQ]);
SEQUENCE sequence_s (SEQUENCE TAB_SEQ [N_SEQ]);
int max_indice (int tab[20]);
FAMILLE creer_famille(float dmin,SEQUENCE TAB_SEQ [N_SEQ]);
FAMILLE creer_familleS18(float dmin, SEQUENCE TAB_SEQ [N_SEQ]);