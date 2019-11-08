#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sequence.h"
#include "distance.h"

// cette fonction va lire dans le fichier pointé par fic, 
// et stocker la sequence dans S:
// chaque lettre est stockée dans S->lettre et la suivante dans S->next->lettre
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