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
// des sequences qui n'ont éventuellement pas encore été assignées à une famille
float dis_d_ed_Min(SEQUENCE TAB_SEQ[N_SEQ]){
	DISTANCE dis;
	float min = 1000;
	for (int i=0; i<N_SEQ-1; i++){
		for (int j=i+1; j<N_SEQ; j++){
			if (TAB_SEQ[i].status ==0 && TAB_SEQ[j].status == 0){
					dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
					if (min > dis.d){
				 	  min = dis.d;
				 	}
			} 

		}
			
	}
	return min;
		
}
// question C
// Trouver la sequence pour la quelle le nombre d'autres sequences ayant
// la meme distance dmin avec elle est le plus grand 
// Pour celà on va utiliser la fonction (dis_d_ed_Min) 
SEQUENCE recheche_S_Dmin (SEQUENCE TAB_SEQ [N_SEQ]){
	DISTANCE dis;
	float Dmin = dis_d_ed_Min (TAB_SEQ);
	TPS tps;
	int n =0;
	tps.tabS = malloc (380* sizeof (SEQUENCE));
	tps.nb_s=0;
	for (int i=0; i<N_SEQ; i++){
		for (int j=i+1; j<N_SEQ; j++){
			dis = calcul_Distance1 (TAB_SEQ[i], TAB_SEQ[j]);
			if (dis.d == Dmin) {
				tps.tabS[n] = TAB_SEQ[i]; n++;
				tps.tabS[n] = TAB_SEQ[j]; n++;
			} 
		}
	}	
		tps.nb_s = n;
		int indice = seq_frequent (tps);
		return TAB_SEQ[indice-1];		
}
// retourne la sequence la sequence la plus fréquente dans T
int seq_frequent (TPS T){
	int i, j;
    //Valeur la plus présente 
    SEQUENCE Smax;
    Smax.num = T.tabS[0].num;
    // Nombre d'occurrences de la sequence la plus présente 
    int max = 0;
    for(i = 0; i < T.nb_s - 1; ++i)
    {
        int cpt = 1;
        for(j = i + 1; j < T.nb_s ; ++j)
        {
            if(T.tabS[i].num == T.tabS[j].num)
                cpt++;
        }
        if(cpt > max)
        {
            max =  cpt;
            Smax.num = T.tabS[i].num;
        }
    }
 
    return Smax.num;
}

// fonction pourcréer la première famille avec la séquence S trouvée dans question précedente
FAMILLE creer_familleS(SEQUENCE TAB_SEQ [N_SEQ]){
	SEQUENCE S;
	DISTANCE dis;
	FAMILLE f;
	f.groupe = malloc(N_SEQ *sizeof(SEQUENCE));
	int n =0;
	int i=0;
	float Dmin = dis_d_ed_Min(TAB_SEQ);
	S = recheche_S_Dmin (TAB_SEQ);
	TAB_SEQ [S.num -1].status =1; 
	f.groupe[n]= S; n++;
	while(i<N_SEQ){
		if (S.num != TAB_SEQ[i].num){
			dis = calcul_Distance1(S, TAB_SEQ[i]);
			if(dis.d == Dmin){
				TAB_SEQ[i].status =1;
				f.groupe[n] = TAB_SEQ[i];
				n++;
			}
		 }
		 i++;	
	}
	f.dMin = Dmin;
	f.nb_famille = n;
	return f;
}

void affiche_famille (FAMILLE F){
	for( int i = 0; i<F.nb_famille; i++){
		printf ("S%d ",F.groupe[i].num);
		affiche_seq (F.groupe[i]);
	} printf ("Membres de famille: %d\n", F.nb_famille);
	printf ("Distance avec la sequence principale: %.2f\n\n\n", F.dMin);
}



