#include <stdio.h>
#include <stdlib.h>
#include "alignement.h"


int main(int argc, char const *argv[])
{
	printf("\nBonjour \n3eme partie \n\nListe des familles, leur allignement et leur sequence concensus\n\n");
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	
	ajout_sequence_all(TAB);

//	FAMILLE F = creer_familleS(TAB);
//	S_concensus (F);

	return 0;
}
