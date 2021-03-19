#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


#define TAILLEMOT 30

void bye() { char saisie = ' '; do { saisie = (char)_getch(); } while (saisie != 'q'&&saisie != 'Q'); }

void saisir(char *tab, int taille)
{
	int position = 0;
	do
	{
		tab[position] = (char)_getch();
		printf("%c", tab[position]);
		position++;
		if (tab[position - 1] == '\b')
		{
			tab[position-2] = '\0';
			position -= 2;
		}
	} while (tab[position - 1] != '\r' && position < taille);
	tab[position - 1] = '\0';

	return tab;
}


int main()
{
	setlocale(LC_ALL, "fr-FR"); //pour ne pas avoir a trier les accents 
	char mot[TAILLEMOT], *espace = NULL;
	int palinlin = 1, longueurMot, position =0;

	//Saisie du mot
	printf_s("saisissez un mot : ");
	saisir(mot, TAILLEMOT);

	longueurMot = strlen(mot);
	printf("\nle mot est : %s \n", mot);

	//minusculisation et retrait des espaces
	for (int i = 0; i < longueurMot; i++)
	{
		mot[i] = tolower(mot[i]);
	}
	printf("\nsans Majuscule : %s \n", mot);

	espace = mot;
	if(strchr(mot, ' ') != NULL)
	{
		espace = strchr(mot, ' ');
		for (char *j = espace; *j != '\0'; j++)
		{
			if (*j != ' ')	*(espace++) = *j;
			else longueurMot--;
		}
		mot[longueurMot] = '\0';
	}
	printf("\nsans espaces : %s \n", mot);


	//verification
	for (int i = 0; i < longueurMot / 2; i++)
	{
			if (mot[i] != mot[longueurMot - 1 - i])
			{
				palinlin = 0;
			}
	}

	//affichage
	if (palinlin) { printf_s("PINLINLIN"); }
	else { printf_s("pas un palindrome :("); }

	bye();
}