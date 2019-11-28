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
typedef struct tab_p_s TPS;
struct tab_p_s {
	SEQUENCE * tabS;
	int nb_s;
};

void affiche_famille (FAMILLE F);
void regrouperFamille (SEQUENCE TAB_SEQ [N_SEQ]);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float dis_d_ed_Min (SEQUENCE TAB_SEQ[N_SEQ]);
SEQUENCE recheche_S_Dmin (SEQUENCE TAB_SEQ [N_SEQ]);
int max_indice (int tab[20]);
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ], SEQUENCE S);
void recherche_sequence_seul(SEQUENCE TAB_SEQ [N_SEQ]);
