#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "sequence.h"
#include "distance.h"

// cette fonction va lire dans le fichier pointé par fic, 
// et stocker la sequence dans S:
// chaque lettre est stockée dans S.lettre et la taille de la sequence dans taille
SEQUENCE lire_sequence (SEQUENCE S, char *fichier){
	S.lettre = malloc (sizeof(char)*T_MAX);
	int i= 0;
	FILE *f=NULL;
	f= fopen (fichier, "r");
	while ( (S.lettre[i] = fgetc(f)) != EOF ){
		i++;
	}
	S.taille = i;
	return S;
}
void affiche_seq (SEQUENCE S){
	for (int i = 0; i < S.taille; ++i)
	{
		printf("%c", S.lettre[i]);
	} printf("\n");
}



void initialisation (const char * nomRep, SEQUENCE TAB_SEQ [N_SEQ]){
	char *nomfichier = malloc (sizeof (char)*40);
	FILE *f = NULL;
	for (int i = 0; i < N_SEQ; ++i)
	{
		if (i<9)
		{
			sprintf (nomfichier, "%s/seq0%d.txt", nomRep, i+1);
		} else sprintf (nomfichier, "%s/seq%d.txt", nomRep, i+1);
		f = fopen (nomfichier, "r");
		if (f==NULL) 
		{
			printf("ouverture fichier impossible !\n"); exit (1);
		}
		TAB_SEQ[i] = lire_sequence (TAB_SEQ[i], nomfichier);
		TAB_SEQ[i].num = i+1;
		TAB_SEQ[i].status=0;
	}
}

