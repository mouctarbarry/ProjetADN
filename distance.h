#ifndef __DISTANCE_H
#define __DISTANCE_H

#include "sequence.h"

struct Distance 
{
	SEQUENCE S1;
	SEQUENCE S2;
	float d;
};
typedef struct Distance DISTANCE;
DISTANCE calcul_Distance1(SEQUENCE S1, SEQUENCE S2); 
float calcul_Distance2 (SEQUENCE S1, SEQUENCE S2);
void affiche_distance (DISTANCE D);
int dictanceNucleos(char n1, char n2); //fonction qui retourne la distance entre 2 lettres (nucléotides)

#endif