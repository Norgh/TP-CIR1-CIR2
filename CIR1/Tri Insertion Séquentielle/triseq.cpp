#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

#define TailleTabMax 100

int TriInsertionSequentielle(int* tab, int tabsize)
{
	for (int i = 0; i < tabsize; i++)
	{
		for (int y = 0; y < tabsize; y++)
		{

		}

	}





}

int main() {
	setlocale(LC_ALL, "fr-FR");
	srand(time(NULL));

	int tableau[TailleTabMax];
	for (int i = 0; i < TailleTabMax; i++)
	{
		tableau[i] = rand() % 1000;
		printf("%d ", tableau[i]);
	}
	printf("\n");
	TriInsertionSequentielle(tableau, TailleTabMax);
	printf("\n");
	for (int i = 0; i < TailleTabMax; i++)
	{
		printf("%d ", tableau[i]);
	}
}