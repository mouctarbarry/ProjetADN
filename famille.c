#include "famille.h"
#include <stdio.h>
#include <stdlib.h>
int indice; 

// cette fonction calcule les distances entre toutes les sequences  2 à 2 
void distanceAll(SEQUENCE TAB_SEQ[N_SEQ]){
	int i, j;
	i=0;
	DISTANCE  disAll;
	FILE *f;
	f = fopen ("distances.txt", "w");
	for (; i<N_SEQ; i++){
		for (j=i+1; j<N_SEQ; j++){
			disAll = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			fprintf (f, "S%d S%d:   %.2f\n", i+1, j+1, disAll.d);
			}
		}	
		fclose (f);
}

// 2e partie question b
// rechercher la distance d’édition minimum Dmin entre toutes les distances d’édition
float distanceMin (SEQUENCE TAB_SEQ[N_SEQ]){
	int i,j;
	i=0; j=1;
	DISTANCE dis;
	dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
	float min = dis.d;
	for (; i<N_SEQ; i++){
		for (j=i+1; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			if (min > dis.d && dis.d > 1){
				 min = dis.d;
				 }
			}
		} 
	return min;	
}

// Trouver la sequence pour la quelle le nombre d'autres sequences ayant
// la meme distance dmin avec elle est le plus grand 
SEQUENCE sequence_s (SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	float Dmin = distanceMin (TAB_SEQ);
	int *tab  = calloc (20, sizeof(int)); 
	for (int i=0; i<N_SEQ; i++){
		for (int j=i+1; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			if (dis.d == Dmin) {
				tab [i]++; tab[j]++;
			} 
		}
	}
		indice = max_indice (tab);
		printf("La séquence s qu'on recherche est S%d: ", TAB_SEQ[indice].num);
		return TAB_SEQ[indice];
			
}

// fonction pourcréer la première famille avec la séquence s 
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	FAMILLE f;
	f.groupe = malloc(N_SEQ *sizeof(SEQUENCE));
	int n =1;
	int i=0;
	f.groupe[i]= TAB_SEQ[indice];
	while(i<N_SEQ){
		if (i != indice) {
				dis = calcul_Distance1(TAB_SEQ[indice], TAB_SEQ[i]);
				if(dis.d == distanceMin (TAB_SEQ) ){
				f.groupe[n] = TAB_SEQ[i];
				n++;
			}
		 }
		 i++;	
	} 
	f.dMin = distanceMin(TAB_SEQ);
	f.nb_famille = n;
	return f;
}


// Fonction qui retourne l'indice du plus gand element contenu dans un tableau
int max_indice (int tab[20]){
	indice = 0;
	int i=0;
	int max = tab[0];
	for (i =1; i <20; i++){
		if (max < tab[i])
		{
			indice = i;
			max = tab[i];
		}
	}
	return indice;
}


void affiche_famille (FAMILLE F){
	printf("Famille de s : \n");
	for( int i = 0; i<F.nb_famille; i++){
		printf ("S%d ",F.groupe[i].num);
		affiche_seq (F.groupe[i]);
	} printf ("Membres de famille: %d\n", F.nb_famille);
}














