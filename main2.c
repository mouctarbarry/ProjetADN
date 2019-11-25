#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main (int argc, char **argv){
	printf ("Bonjour\n");	
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	distanceAll (TAB);
	printf ("%.2f\n\n", distanceMin (TAB));
	affiche_seq (sequenceMoy(TAB));
}
