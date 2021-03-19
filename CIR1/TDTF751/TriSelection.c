#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

#define TailleTabMax 100

int TriSelection(int* tab, int tabsize)
{
	int vMinPos = NULL;
	int vMin, swap;
	for (int i = 0; i < tabsize; i++)
	{
		vMin = *(tab + i);
		for (int y = i; y < tabsize; y++)
		{
			if (*(tab + y) < vMin)
			{
				vMin = *(tab + y);
				vMinPos = y;
			}
		}
		if (vMinPos != NULL)
		{
			swap = *(tab + vMinPos);
			*(tab + vMinPos) = *(tab + i);
			*(tab + i) = swap;
			vMinPos = NULL;
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
	TriSelection(tableau, TailleTabMax);
	printf("\n");
	for (int i = 0; i < TailleTabMax; i++)
	{
		printf("%d ", tableau[i]);
	}
}