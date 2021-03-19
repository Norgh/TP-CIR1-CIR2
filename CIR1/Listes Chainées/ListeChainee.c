/*#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct Maillon
{
	int valeur;
	struct Maillon* svnt;
	struct Maillon* prcdnt;
}Maillon;

typedef struct Liste
{
	Maillon* head;
	Maillon* tail;
	int NbrElmnts;
}Liste;

void InitListe()
{
	Liste* ListeChainée = malloc(sizeof(Liste));
	if (ListeChainée == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ListeChainée->head = NULL;
	ListeChainée->tail = NULL;
	return ListeChainée;
}

void InitMaillon()
{
	Maillon* MaillonChainé = malloc(sizeof(Maillon));
	if (MaillonChainé == NULL)
	{
		exit(EXIT_FAILURE);
	}
	MaillonChainé->prcdnt = NULL;
	MaillonChainé->svnt = NULL;
	return MaillonChainé;
}
void Ajouter(Liste* ListeChainée, Maillon* MaillonChainé)
{




}

 int main() {
	setlocale(LC_ALL, "fr-FR");
	InitListe();
	char tmp[20];
	char chaine[20]="Vive la france";
	printf("%s\n", chaine);
	for (int i = 0; i < 19; i++) 
	{
		tmp[i] = toupper(chaine[i]);
	}
	printf("%s", tmp);



} */