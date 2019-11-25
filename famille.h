#include "sequence.h"
#include "distance.h"


typedef struct famille FAMILLE;
struct famille {
	SEQUENCE *groupe;
	float distanceMax;
	float distanceMin;
};
void affiche_famille (FAMILLE F);
FAMILLE regrouperFamille (FAMILLE f);
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]);
float distanceMin (SEQUENCE TAB_SEQ[N_SEQ]);
SEQUENCE sequenceMoy (SEQUENCE TAB_SEQ [N_SEQ]);
