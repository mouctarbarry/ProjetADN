#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char const *argv[])
{
	printf("\n\t\tBONJOUR :)\n \tPartie 1: \n\n\t\tListe de toutes les sequences\n");
	SEQUENCE TAB_SEQ [N_SEQ];
	char *nomfichier = malloc (sizeof (char)*40);
	FILE *f = NULL;
	for (int i = 0; i < N_SEQ; ++i)
	{
		if (i<9)
		{
			sprintf (nomfichier, "%s/seq0%d.txt", argv[1], i+1);
		} else sprintf (nomfichier, "%s/seq%d.txt", argv[1], i+1);
		f = fopen (nomfichier, "r");
		if (f==NULL) 
		{
			printf("ouverture fichier impossible !\n"); exit (1);
		}
		TAB_SEQ[i] = lire_sequence (TAB_SEQ[i], nomfichier);
		affiche_seq (TAB_SEQ[i]);
	}
	DISTANCE D = calcul_Distance1 (TAB_SEQ[2], TAB_SEQ [1]);
	affiche_distance (D);
	return 0;
}
