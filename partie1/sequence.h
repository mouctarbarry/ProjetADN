#define T_MAX 25
typedef struct sequence SEQUENCE;
struct sequence 
{
	char *lettre;
	int taille;
};

SEQUENCE lire_sequence (SEQUENCE S, char *fichier);