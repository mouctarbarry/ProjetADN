#include "alignement.h"

/*ALIGNEMENT init_alignement(FAMILLE F){
	ALIGNEMENT A;
	
	2;
	return A;
}*/

void afficher_alignement(ALIGNEMENT A){
	for(int i =0; i<A.nb_sequences; i++){
		if (A.T_alignement[i].num < 10){
			printf("S%d  ", A.T_alignement[i].num);
		} else printf("S%d ", A.T_alignement[i].num);
		
		affiche_seq(A.T_alignement[i]);
	}
	printf("\n");
	printf("    ");
	affiche_seq (A.s_consensus);
	printf("Sequence CONSENSUS de l'alignement \n");
	
	
}



ALIGNEMENT aligner (FAMILLE F){
	SEQUENCE Smin;
	ALIGNEMENT A;
	int nombreElement = F.nb_famille;
	A.T_alignement = malloc (nombreElement*sizeof (SEQUENCE));
	A.T_alignement[0] = F.groupe[0];
	A.T_alignement[1] = F.groupe[1];
	A.nb_sequences = F.nb_famille;
	int compteur;
	int indice;
	if (F.nb_famille > 2){

		for (int i = 2; i < F.nb_famille ; ++i){
			Smin = F.groupe[i];
			DISTANCE dis; 
			float min;
            dis = calcul_Distance1(A.T_alignement[i-1], Smin);
            min = dis.d;
			compteur = i+1;
			indice = compteur;
			while (compteur < F.nb_famille){
				dis = calcul_Distance1 (F.groupe[compteur], F.groupe[i-1]);
				if (min  > dis.d)
				{
					min = dis.d;
					indice = compteur;
					Smin = F.groupe[compteur];
				}
				compteur++;
			}
			if (Smin.num != F.groupe[i].num)
			{	
				SEQUENCE Stmp = F.groupe[i];
            	F.groupe[i] = Smin;
            	F.groupe[indice] = Stmp;
			}
            
		}
		for (int i = 2; i < F.nb_famille; ++i)
		{
			A.T_alignement[i] = F.groupe[i];
		}
	}

	return A;
}


void ajout_sequence_all (SEQUENCE TAB_SEQ[N_SEQ]){
	ALIGNEMENT *A;
	A = malloc (N_SEQ * sizeof (ALIGNEMENT));
	int i = 0; 
	int cpt  = 0;
	while (cpt<N_SEQ){
		FAMILLE F =  creer_familleS (TAB_SEQ);
		affiche_famille (F);
		printf("--------------------------------------\n");
		A[i] = aligner (F);
		A[i].s_consensus.lettre = malloc (T_MAX* sizeof(char));
		A[i].s_consensus = S_concensus (F);
		afficher_alignement (A[i]);
		printf ("#######################################################\n\n");
		cpt += F.nb_famille;
		i++;
	}
  }


SEQUENCE S_concensus (FAMILLE F){
	SEQUENCE S_cons; 
	S_cons.lettre = malloc (T_MAX*sizeof (char));
	S_cons.taille = 0;
	int tab[5];
	int max_t = max_seq (F); 
	for (int i = 0; i<max_t; i++){
		for (int i = 0; i < 5; i++) {tab [i] = 0;}
		for (int j = 0; j<F.nb_famille; j++){
			if (i<F.groupe[j].taille)
			{
				if (F.groupe[j].lettre[i] == 'A')
				{
					tab[0]+=1;
				}
				if (F.groupe[j].lettre[i] == 'C')
				{
					tab[1]+=1;
				}
				if (F.groupe[j].lettre[i] == 'G')
				{
					tab[2]+=1;
				}
				if (F.groupe[j].lettre[i] == 'T')
				{
					tab[3]+=1;
				}

			}
			else tab [4]+=1;
		} 
		S_cons.lettre[i] = max_nucleo (tab);
	    S_cons.taille++;
	}
	return S_cons;
}

char max_nucleo (int tab[]){
	char c;
	if (deux_max(tab)){
        c = '.';
    }else{
    	int max = tab[4];
		for (int i = 0; i < 5; i++)
		{

        	if(max < tab[i]){
            	 if(i == 0)
             		c = 'A';
	             if(i == 1)
	             	c = 'C';
	              if(i == 2)
	             	c = 'G';
	             if(i == 3)
	             	c = 'T';	
	             if (i==4)
	             	c= '.';
	            max = tab[i];
        	}
        
		}
    }
	
	return c;
}

int max_seq (FAMILLE F){
	int max = F.groupe[0].taille;
	for (int i = 1; i < F.nb_famille; i++)
	{
		if (max < F.groupe[i].taille)
		{
			max = F.groupe[i].taille;
		}
	}
	return max;
}

int deux_max (int tab[]){
	int max = tab [0];
	int indiceMax = 0;
	int val = 0;
	for (int i = 1; i < 5; i++)
	{
		if (tab[i] > max )
		{
			max = tab[i];
			indiceMax = i;
		}
	}
	for (int i = 0; i < 5 ; i++)
	{
		if (max == tab[i]  &&  indiceMax != i){
			val = 1;
		}

	}
	return val;
}
/*
void allSeq_cons (SEQUENCE TAB[N_SEQ]){
	FAMILLE F;
	ALIGNEMENT *A;
	A = malloc (N_SEQ*sizeof(ALIGNEMENT));

	int cpt = 0;
	int i = 0;
	while(cpt<N_SEQ){
		F = creer_familleS(TAB);

	}
}


*/