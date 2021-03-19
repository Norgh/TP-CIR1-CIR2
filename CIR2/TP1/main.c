#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>
#include<string.h>
#include<ctype.h>

char* minuscule(char Upper[20])
{
	for (unsigned int i = 0; i < strlen(Upper); i++)
	{
		Upper[i] = tolower(Upper[i]);
	}
	printf("Chaine en minuscule : %s\n", Upper);
	return Upper;
}

char* minuscule2(char Upper[20])
{
	for (unsigned int i = 0; i < strlen(Upper); i++)
	{
		Upper[i] = tolower(Upper[i]);
	}
	return Upper;
}
int AvecFor(int n)
{
	int factorielle = 1;
	for (int i = 2; i <= n; i++)
	{
		factorielle = factorielle*i;
	}
	return factorielle;
}

int AvecWhile(int n)
{
	int factorielle = 1;
	int compteur = 1;
	while (compteur < n)
	{
		compteur++;
		factorielle = factorielle * compteur;
	}
	return factorielle;
}

int Récursif(int n, int factorielle)
{
	if (n == 1)
	{
		return factorielle;
	}
	else 
	{
		factorielle = factorielle * n;
		
		return Récursif(n - 1, factorielle);
	}
}

void tri(int tab[10]) 
{
	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10 - 1; i++)
		{
			if (tab[i] > tab[i + 1]) {
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}
int main()
{	
	setlocale(LC_ALL, "fr-FR");
	//EXERCICE 1
	
	printf("Hello World\n");
	system("PAUSE");
	system("CLS");

	//EXERCICE 2

	float a, b, c;
	printf("Veuillez entrer les inconnues de l'équation du type ax^2+bx+c : \n");
	scanf_s("%f", &a);
	printf("%.2fx^2+",a);
	scanf_s("%f", &b);
	printf("%.2fx^2+(%.2fx)+",a, b);
	scanf_s("%f", &c);
	printf("Vous avez entré l'équation : %.2fx^2+(%.2fx)+(%.2f) \n", a, b, c);
	float delta;
	delta = b * b - (4 * a * c);
	float r1, r2;
	if (delta == 0)
	{
		r1 = (-b) / 2 * a;
		printf("Il y a une unique solution r=%.2f\n", r1);
	}
	if (delta > 0)
	{
		r1 = (b - (float)sqrt(delta)) / 2 * a;
		r2 = (b + (float)sqrt(delta)) / 2 * a;
		printf("r1=%.2f   |   r2=%.2f\n", r1, r2);
	}
	if (delta < 0)
	{
		printf("Pas de solution dans les Réels\n");
	}

	system("PAUSE");
	system("CLS");
	
	// EXERCICE 3

	char Upper[20] = { 0 };
	printf("Veuillez entrer votre chaine de caractères EN MAJUSCULE ci-dessous : \n");
	scanf_s("%s", Upper, 19);
	minuscule(Upper);

	system("PAUSE");
	system("CLS");
	
	// EXERCICE 4

	int n = 0;
	printf("Entrez la valeur de n dont vous voulez calculer la factorielle\n");
	scanf_s("%d", &n);
	printf("%d\n",AvecFor(n));
	printf("%d\n", AvecWhile(n));
	printf("%d\n", Récursif(n, 1));
	system("PAUSE");
	system("CLS");
	
	// Exercice 5
	
	int Tableau[10] = { 0 };
	int val = 0;
	printf("Entrez les valeurs du tableau à trier\n");
	for (int i = 1;i <= 10; i++)
	{
		printf("Veuillez entrer la valeur numéro %d\n", i);
		scanf_s("%d", &val);
		Tableau[i - 1] = val;
		system("CLS");
	}

	tri(Tableau);

	for (int i = 0;i < 10; i++)
	{
		printf("%d ", Tableau[i]);
	}

	system("PAUSE");
	system("CLS");
	
	// EXERCICE 6

	char Mot[100];
	char Hidden[100];
	printf("Veuillez entrer le mot à deviner : \n");
	scanf_s("%100s", Mot, 100);
	if (strlen(Mot) < 3)
	{
		printf("Veuillez choisir un mot de plus de 2 lettres, Merci!\n");
		scanf_s("%100s", Mot, 100);
	}
	system("CLS");
	minuscule2(Mot);
	strcpy_s(Hidden, 100, Mot);
	int size = strlen(Hidden);
	for (int i = 1;i < size-1; i++)
	{
		Hidden[i] = '_';
	}
	int fin = 10;
	int end = 0;
	int try = 0;
	int verif = 0;
	char Lettre[2];
	while (fin > 0 && end == 0)
	{
		printf("Il vous reste : %d tentatives\n", fin);
		printf("%s\n", Hidden);
		printf("Entrez un caractère : ");
		scanf_s("%1s", Lettre, 2);
		minuscule2(Lettre);
		for (int i = 1;i < size - 1; i++)
		{
			if (Lettre[0] == Mot[i])
			{
				Hidden[i] = Lettre[0];
				try++;
			}
		}
		if (try != 0)
		{
			fin++;
		}
		try = 0;
		fin--;
		verif = 0;
		for (int i = 0;i < size; i++)
		{
			if (Hidden[i] == Mot[i])
			{
				verif++;
			}
		}
		if (verif == size)
		{
			end = 1;
		}
	}
	if (end == 1)
	{
		printf("Vous avez trouvé le mot %s. Bravo, vous avez gagné!\n", Hidden);
	}
	else
	{
		printf("Vous avez perdu, le mot était : %s\n", Mot);
	}
}