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
	Liste* ListeChain�e = malloc(sizeof(Liste));
	if (ListeChain�e == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ListeChain�e->head = NULL;
	ListeChain�e->tail = NULL;
	return ListeChain�e;
}

void InitMaillon()
{
	Maillon* MaillonChain� = malloc(sizeof(Maillon));
	if (MaillonChain� == NULL)
	{
		exit(EXIT_FAILURE);
	}
	MaillonChain�->prcdnt = NULL;
	MaillonChain�->svnt = NULL;
	return MaillonChain�;
}
void Ajouter(Liste* ListeChain�e, Maillon* MaillonChain�)
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