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

SEQUENCE sequenceMoy (SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	float somDis=0;
	float tabMoy [N_SEQ];
	for (int i=0; i<N_SEQ; i++){
		for (int j=0; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			somDis += dis.d;
		  }
		tabMoy [i] = somDis/N_SEQ;
	  }
	float min = tabMoy[0];
	int cpt=0;
	for (int i=1; i<N_SEQ; i++){
		if (min > tabMoy[i]) {
		min = tabMoy [i];
		cpt = i;
		}
	} printf ("%.2f\n", min);
	return TAB_SEQ [cpt];
}























