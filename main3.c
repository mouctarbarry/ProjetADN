#include <stdio.h>
#include <stdlib.h>
#include "alignement.h"


int main(int argc, char const *argv[])
{
	printf("Bonjour 3eme partier \n\n");
	SEQUENCE TAB[N_SEQ];
	initialisation (argv[1], TAB);
	
	ajout_sequence_all(TAB);

//	FAMILLE F = creer_familleS(TAB);
//	S_concensus (F);

	return 0;
}
