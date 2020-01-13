#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main (int argc, char **argv){
	printf ("\n Bonjour\n\nPartie 2 :\n\n");	
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	distanceAll(TAB);
	printf("Distance minimum entre toutes les distances d'editions: %.2f\n\n", dis_d_ed_Min (TAB));
	printf("Liste de toutes les familles\n");
	regrouperFamilles(TAB);
}
