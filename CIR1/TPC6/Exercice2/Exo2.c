#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

static int produit=0; /* la valeur du dernier factoriel calculé.*/
static int N=1; /* la valeur de n pour laquelle on a calculé ce factoriel */

unsigned long long factorielle(unsigned int n)
{
	unsigned int NbBoucles = 0;
	if (produit == n)
	{
		printf("Nombre de boucles :%d", NbBoucles);
		return N;
	}
	else if (produit < n)
	{
		for (unsigned int i = n; i > produit; i--)
		{
			N = N*i;
			NbBoucles++;
		}
		produit = n;
		printf("Nombre de boucles :%d", NbBoucles);
		return N;
	}
	else
	{
		n = 1;
		for (unsigned int i = 1; i <= n; i++)
		{
			N = N*i;
			NbBoucles++;
		}
		produit = n;
		printf("Nombre de boucles :%d", NbBoucles);
		return N;
	}
}


int main() {
	setlocale(LC_ALL,"fr-FR");
	int n;
	unsigned long long fctrl = 0;
	char fin='A';
	while (fin != 'X')
	{
		printf("Entrer une valeur de n: ");
		scanf_s("%u", &n);
		system("CLS");
		fctrl = factorielle(n);
		printf("\nLa valeur du factoriel de %u est:%llu", n, fctrl);
		printf("\n \n \n \nPour arrêter le programme, appuyer sur 'X'\nSinon, appuyer sur n'importe quelle autre touche\n");
		fin = (char) getch();
	}
}