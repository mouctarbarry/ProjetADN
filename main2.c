#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main (int argc, char **argv){
	printf ("Bonjour\n");	
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	//distanceAll (TAB);
	printf ("\n\n\tDistance minimum entre toutes les D.editions: %.2f\n\n", dis_d_ed_Min (TAB));
	FAMILLE f1, f2, f3, f4;
	f1 = creer_familleS (TAB);
	affiche_famille (f1);
	
	f2 = creer_familleS (TAB);
	affiche_famille (f2);
	
	f3 = creer_familleS (TAB);
	affiche_famille (f3);
	printf ("%d#\n",TAB[5].status);
}
