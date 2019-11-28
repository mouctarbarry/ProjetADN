#include "sequence.h"
#include "distance.h"


typedef struct famille FAMILLE;
struct famille {
	SEQUENCE * groupe;
	float dMin;
	int nb_famille;
};
// cette structure va permettre de stocker à chaque fois les sequences non encore assignées à une famille
typedef struct seq_restant S_REST;
struct seq_restant{
	SEQUENCE * liste_res;
	int nb_seq_res;
};

void affiche_famille (FAMILLE F);
FAMILLE regrouperFamille (FAMILLE f);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float distanceMin (SEQUENCE TAB_SEQ[N_SEQ]);
SEQUENCE sequence_s (SEQUENCE TAB_SEQ [N_SEQ]);
int max_indice (int tab[20]);
FAMILLE creer_famille(float dmin,SEQUENCE TAB_SEQ [N_SEQ]);
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ]);
