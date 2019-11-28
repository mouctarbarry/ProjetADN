#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char const *argv[])
{
	printf("\n\t\tBONJOUR :)\n \tPartie 1: \n\n\t\tListe de toutes les sequences\n");
	SEQUENCE TAB_SEQ [N_SEQ];
	initialisation (argv[1], TAB_SEQ);
	// afficher toutes les sequences du repertoire
	for (int i=0; i<N_SEQ; i++){
			printf ("S%d ",TAB_SEQ[i].num);
			affiche_seq (TAB_SEQ[i]);
		}
	//caluler la distance de 2 sequences données
	DISTANCE D = calcul_Distance1 (TAB_SEQ[19], TAB_SEQ [9]);
	affiche_distance (D);
	return 0;
}
