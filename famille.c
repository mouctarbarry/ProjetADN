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
			if (min > dis.d && TAB_SEQ[i].status ==0 && TAB_SEQ[j].status == 0){
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
			if (dis.d == Dmin && TAB_SEQ[i].status ==0 && TAB_SEQ[j].status == 0) {
				tab [i]++; tab[j]++;
			} 
		}
	}
		indice = max_indice (tab);
		printf("Séquence S principale est S%d: ", TAB_SEQ[indice].num);
		return TAB_SEQ[indice];
			
}

// fonction pourcréer la première famille avec la séquence s 
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ], SEQUENCE S){
	DISTANCE dis;
	FAMILLE f;
	f.groupe = malloc(N_SEQ *sizeof(SEQUENCE));
	int n =1;
	int i=0;
	S = sequence_s (TAB_SEQ);
	f.groupe[0]= S; S.status=1;
	while(i<N_SEQ){
		if (S.num != TAB_SEQ[i].num){
			dis = calcul_Distance1(S, TAB_SEQ[i]);
			if(dis.d == distanceMin(TAB_SEQ)){
				if (TAB_SEQ [i].status == 0){
				f.groupe[n] = TAB_SEQ[i];
				TAB_SEQ[i].status =1;
				n++;
				}
			}
		 }
		 i++;	
	} 
	f.dMin = distanceMin(TAB_SEQ);
	f.nb_famille = n;
	return f;
}

// fonction regrouper toutes les sequences qui n'ont pas été assigées à une famille

void regrouperFamille (SEQUENCE TAB_SEQ [N_SEQ]){
	int i = 0;
	TAB_FAMI T;
	T.f = malloc (N_SEQ*sizeof (FAMILLE));
	T.nb_f =0;
	SEQUENCE S = sequence_s (TAB_SEQ);
	while (i<N_SEQ){
		if (TAB_SEQ [i].status == 0) {
		T.f[i] = creer_familleS(TAB_SEQ, S);
		T.nb_f +=1;
		}
		affiche_famille (T.f[i]);
		i++;
	}
}






// Fonction qui retourne l'indice du plus gand element contenu dans un tableau de 20 elements
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
	for( int i = 0; i<F.nb_famille; i++){
		printf ("S%d ",F.groupe[i].num);
		affiche_seq (F.groupe[i]);
	} printf ("Membres de famille: %d\n", F.nb_famille);
	printf ("DIstance avec la sequence concensus: %.2f\n\n\n",F.dMin);
}












