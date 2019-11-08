#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char const *argv[])
{
	printf("\n\nBonjour,\ndébut du projet \n\n\n");
	SEQUENCE S;
	S = lire_sequence (S, "seq01.txt");
	affiche_seq (S);
	return 0;
}