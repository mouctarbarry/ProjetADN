#include "sequence.h"
#include "distance.h"
#include "famille.h"
#define L_NUCLEO 4

typedef struct alignement ALIGNEMENT;
struct alignement 
{
	SEQUENCE * T_alignement;
	SEQUENCE s_consensus;
	int nb_sequences;
};


typedef struct nucletid T_NUCLEO;
struct nucletid{
	char nucleo;
	int nb_nucleo;
};

ALIGNEMENT init_alignement (FAMILLE F);
void ajout_sequence_all (SEQUENCE TAB[N_SEQ]);
ALIGNEMENT aligner (FAMILLE F);
void afficher_alignement(ALIGNEMENT A);
int max_seq(FAMILLE F);
char max_nucleo (int tab[]);
SEQUENCE S_concensus (FAMILLE F);
int deux_max (int tab[]);
void allSeq_cons (SEQUENCE TAB[N_SEQ]);

//void calucl_s_consensus (SEQUENCE S);
//SEQUENCE S_concensus (FAMILLE F);
//void init_valnucleo (T_NUCLEO t[4]);









