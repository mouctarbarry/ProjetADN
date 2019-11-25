#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char const *argv[])
{
	printf("\n\t\tBONJOUR :)\n \tPartie 1: \n\n\t\tListe de toutes les sequences\n");
	SEQUENCE TAB_SEQ [N_SEQ];
	initialisation (argv[1], TAB_SEQ);
	
	for (int i=0; i<N_SEQ; i++){
			affiche_seq (TAB_SEQ[i]);
		}
	DISTANCE D = calcul_Distance1 (TAB_SEQ[2], TAB_SEQ [1]);
	affiche_distance (D);
	return 0;
}
