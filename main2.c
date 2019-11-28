#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main (int argc, char **argv){
	printf ("Bonjour\n");	
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	distanceAll (TAB);
	printf ("Distance minimum entre toutes les D.editions: %.2f\n\n", distanceMin (TAB));
	affiche_seq (sequence_s(TAB));
	FAMILLE f1 = creer_familleS(TAB);
	affiche_famille(f1);
}
