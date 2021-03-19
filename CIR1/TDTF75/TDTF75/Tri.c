#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

#define TailleTabMax 1000

void tri_naif(int tab[TailleTabMax]) {
	for (int i = 0; i < TailleTabMax; i++)
	{
		for (int i = 0; i < TailleTabMax - 1; i++)
		{
			if (tab[i] > tab[i + 1]) {
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "fr-FR");

	srand(time(NULL));

	int tab[TailleTabMax];

	for (int i = 0; i < TailleTabMax; i++)
	{
		tab[i] = rand() % 1000;
	}

	tri_naif(tab);

	for (int i = 0; i < TailleTabMax; i++)
	{
		printf("%d ", tab[i]);
	}
}
