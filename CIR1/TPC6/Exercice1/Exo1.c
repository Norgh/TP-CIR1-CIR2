#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#define NbChiffresMax 30

// taille max pour representer un grand entier
typedef int GrandEntier[NbChiffresMax];
/* representation des grands entiers à l'aide d'un tableau */
/* les positions qui ne contiennent pas de chiffre significatif */
/* sont initialisées à zero */
/* *********************************************************** */
/* Procedure d'initialisation d'un grand entier a zero */
/* *********************************************************** */
void Initialise(GrandEntier Nombre)
{
	for (int i = 0; i < NbChiffresMax; i++) 
	{
		Nombre[i] = 0;
	}
}
/* *********************************************************** */
/* Procedure d'affichage d'un grand entier à l'ecran */
/* *********************************************************** */
void Affiche(GrandEntier Nombre)
{
	/* affichage d'espace à la place des zéros à gauche
	Sauf s'il s'agit du digit de droite, au cas ou GrandEntier vaut 0,
	il faut afficher 0 */
	int i = 0;
	while (Nombre[i] == 0 && i < NbChiffresMax - 1)
	{
		i++;
		printf(" ");
	}
	printf("\n");
	for (int x = 0; x < NbChiffresMax; x++) 
	{
		if (x % 3 == 0) 
		{ 
			printf(" "); 
		}
		printf("%d", Nombre[x]);
	} 

	
}
/* ***************************************************************/
/* Procedure d'ajout d'un chiffre à droite dans un grand entier */
/* ***************************************************************/
int AjouteADroite(GrandEntier Nb, int Chiffre)
{
	//décalage à gauche des chiffres 
	//écriture du nouveau chiffre dans la case de droite ainsi libérée
	int retour = 0;

	if (Nb[0] != 0)
	{
		retour=666;
	}

	for (int i = 1; i < NbChiffresMax-1; i++) 
	{
		Nb[i] = Nb[i+1];
	}
	Nb[NbChiffresMax-1] = Chiffre;

	if (retour != 0)
	{
		return -1;
	}

	return 0;
}
/* *********************************************************** */
/* Procedure de saisie d'un grand entier au clavier */
/* *********************************************************** */
/* FONCTION COMPLETE : NE DOIT PAS ETRE MODIFIEE */
int EntreeClavier(GrandEntier Nombre)
{
	int NbChiffresLus = 0;
	wchar_t car; // touche frappée en entrée
	wchar_t chiffre[2]; // variable type chaine de caractère Wide pour conversion
	// de car en entier avec _wtoi
	bool EstUnChiffre = false;
	Initialise(Nombre); // Nombre prend la valeur zero
	do
	{
		while ((car = _getwch()) == 0) {
			car = _getwch(); // touche de fonction ou direction enfoncée
		}; // lire la touche frappee au clavier
		if (EstUnChiffre = (bool)isdigit(car)) // s'il s'agit bien d'un chiffre
		{
			wprintf(L"%c", car); // echo ecran du chiffre valide
			chiffre[0] = car; // conversion du caractere en chaine null terminated pour _wtoi()
			chiffre[1] = 0;
			AjouteADroite(Nombre, _wtoi(chiffre)); // conversion du caractere en valeur numerique et
			NbChiffresLus++; // affectation dans le tableau qui contient le grand entier
		}
		else { // s'il s'agit d'un caractère de controle CLEAR (touche 'C' )
			if ((car == 'C') || (car == 'c')) {
				Initialise(Nombre); // effacement des caractères saisies
				printf("\nClear\n");
				EstUnChiffre = true; // pour continuer la saisie de ce nombre
			}
		}
	} while (EstUnChiffre && (NbChiffresLus < NbChiffresMax));
	printf("\n");
	if ((car == 'X') || (car == 'x')) return -1;
	return 0;
}
/* *********************************************************** */
/* Procedure de calcul de la somme de deux grands entiers */
/* *********************************************************** */
int Addition(GrandEntier Nb1, GrandEntier Nb2, GrandEntier Result)
{
	int retenue = 0;
	for (int i = NbChiffresMax-1; i >= 0; i--)
	{
		Result[i] = (Nb1[i] + Nb2[i] + retenue);
		if (Result[i]>9)
		{
			if (i == 0) {
				Result[i] -= 10;
				return -1;
			}
			retenue = 1;
			Result[i] = Result[i]-10;
		}
		else 
		{ 
			retenue = 0;
		}
	}
	return 0;
}


/* *********************************************************** */
/* Programme principal: COMPLET : rien à modifier */
/* *********************************************************** */
int main()
{
	GrandEntier Nb1, Nb2, Nb3;
	int i;
	int Fin = false;
	int Code; // valeur de retour de la fonction EntreeClavier
	while (!Fin)
	{
		if ((Code = EntreeClavier(Nb1)) < 0) Fin = true;
		if (!Fin && (Code = EntreeClavier(Nb2) < 0)) Fin = true;
		if (!Fin)
		{
			
			Affiche(Nb1);
			printf("\n");
			printf("+");
			Affiche(Nb2);
			printf("\n");
			for (i = 0; i < NbChiffresMax; i++)
			{
				if ((NbChiffresMax - i) % 3 == 0) printf("-");
				printf("-");
			}
			printf("\n=");
			Addition(Nb1, Nb2, Nb3);
			Affiche(Nb3);
			printf("\n");
		}
		else
		{
			printf("\n Welcome to The Hell !\n");
		}
	}
	return (EXIT_SUCCESS);
}