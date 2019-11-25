#ifndef __SEQUENCE_
#define __SEQUENCE_
#define T_MAX 25
#define N_SEQ 20 //taille du tableau qui va contenir les 20 sequences du projet 
typedef struct sequence SEQUENCE;
struct sequence 
{
	char *lettre;
	int taille;
};

SEQUENCE lire_sequence (SEQUENCE S, char *fichier);
void initialisation (char * nomRep, SEQUENCE TAB_SEQ [N_SEQ]);
void affiche_seq (SEQUENCE S);
#endif
