#ifndef __SEQUENCE_
#define __SEQUENCE_
#define T_MAX 25 //Taille max des nucléotides
#define N_SEQ 20 //taille du tableau qui va contenir les 20 sequences du projet 
typedef struct sequence SEQUENCE;
struct sequence 
{
	char *lettre; // tableaux de lettres formant la sequence
	int taille;	  // nombre de lettres formant la sequence
	int num;	  // numéro unique (identifiant) de la sequence 
	int status;	  // status de la sequence: 1 si assignée à une famille, et 0 sinon 
};

SEQUENCE lire_sequence (SEQUENCE S, char *fichier);
void initialisation (const char * nomRep, SEQUENCE TAB_SEQ [N_SEQ]);
void affiche_seq (SEQUENCE S);
#endif
