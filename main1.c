#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char const *argv[])
{
	printf("Bonjour,\ndébut du projet \n\n");
	SEQUENCE TAB_SEQ [N_SEQ];
	char *nomfichier = malloc (sizeof (char)*40);
	FILE *f = NULL;
	for (int i = 0; i < N_SEQ; ++i)
	{
		if (i<9)
		{
			sprintf (nomfichier, "sequences_ADN/seq0%d.txt", i+1);
		} else sprintf (nomfichier, "sequences_ADN/seq%d.txt", i+1);
		f = fopen (nomfichier, "r"); 
		if (f==NULL) 
		{
			printf("ouverture fichier impossible !\n"); exit (1);
		}
		TAB_SEQ[i] = lire_sequence (TAB_SEQ[i], nomfichier);
		affiche_seq (TAB_SEQ[i]);
	}
	return 0;
}