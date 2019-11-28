#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main (int argc, char **argv){
	printf ("Bonjour\n");	
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	distanceAll (TAB);
	printf ("Distance minimum entre toutes les D.editions: %.2f\n\n", dis_d_ed_Min (TAB));
	
	affiche_seq (recheche_S_Dmin(TAB));
	//regrouperFamille(TAB);
}
