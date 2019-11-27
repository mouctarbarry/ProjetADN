#include "famille.h"
#include <stdio.h>
#include <stdlib.h>
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
	i=0;
	DISTANCE dis;
	dis = calcul_Distance1 (TAB_SEQ[0], TAB_SEQ[1]);
	float min = dis.d;
	for (; i<N_SEQ; i++){
		for (j=i+1; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			if (min > dis.d) min = dis.d;
			}
		} return min;	
}

SEQUENCE sequence_s (SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	float Dmin =1; int tab [20] = {00000000000000000000}; 
	for (int i=0; i<N_SEQ; i++){
		for (int j=0; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			if (dis.d == Dmin) {
				tab [i]++; tab[j]++;
			} 
		}
	} 
		int indice = max_indice (tab);
		printf("La séquence s est S%d : ", indice+1);
		return TAB_SEQ[indice];
			
}

int max_indice (int tab[20]){
	int indice = 0;
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

// fonction pourcréer la première famille avec la séquence s

FAMILLE creer_familleS18(float dmin, SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	FAMILLE f;
	f.groupe = malloc(N_SEQ *sizeof(SEQUENCE));
	int n =1;
	f.groupe[0]= TAB_SEQ[17];

	for(int i=1; i<N_SEQ && i!= 17; i++){
		dis = calcul_Distance1(TAB_SEQ[17], TAB_SEQ[i]);
		if(dis.d == dmin){
			f.groupe[n] = TAB_SEQ[i]; 
			n++;
		}
		f.dMin =dmin;
		f.nb_famille = n;
	}
	return f;
}


void affiche_famille (FAMILLE F){

	printf("Famille de s : \n");
	for( int i = 0; i<F.nb_famille;i++){
		affiche_seq (F.groupe[i]);
	}
}

FAMILLE creer_famille(float dmin,SEQUENCE TAB_SEQ [N_SEQ]){
	
}














