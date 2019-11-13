#include "distance.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

DISTANCE calcul_Distance1(SEQUENCE S1, SEQUENCE S2){
	float dis = 0;
	DISTANCE D; 
	D.S1 = S1;
	D.S2 = S2;
	float decalage = abs(S1.taille - S2.taille)*1.5;
	int taille_min = S1.taille;
	if (S1.taille > S2.taille) taille_min = S2.taille;
	int i=0;
	while (i<taille_min){
		dis += dictanceNucleos (D.S1.lettre[i], D.S2.lettre[i]);
		i++;
	}
	dis += decalage;
	D.d = dis;
	return D;
}
float calcul_Distance2(SEQUENCE S1, SEQUENCE S2){
	return 0;
}
int dictanceNucleos(char n1, char n2){
	//  en se basant sur le tableau, la fonction return 0, 1 ou 2
	if (n1==n2)
		return 0;
	if ( (n1=='A' && n2 =='G') || (n1=='G' && n2 == 'A') || (n1=='C' && n2=='T') || (n1=='T' && n2=='C') ) 
		return 1;
	return 2;
}
void affiche_distance (DISTANCE D){
	printf("sequence: "); affiche_seq (D.S1);
	printf("sequence: "); affiche_seq (D.S2);
	printf("Distance: %f\n", D.d);
}