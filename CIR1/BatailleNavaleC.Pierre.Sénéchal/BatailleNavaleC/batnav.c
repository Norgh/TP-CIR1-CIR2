#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <Windows.h>
#include "ConsoleTools.h"
#include "liste.h"

#define NBBATEAUX 5
#define SEASIZEX 20
#define SEASIZEY 20

// Epreuve du 7 avril 2020
// 
// Nom : Sénéchal
// Prénom : Pierre
//



typedef struct BOAT {
	LinkedList *eltsBateau;
	size_t taille;
	Cap cap;

} BOAT;

typedef struct FLOTTE {
	size_t nbBateaux;
	BOAT *bateau;
} FLOTTE;

// protypes de fonctions

// création d'un jeu d'essais pour la flotte de 5 bateaux
// un bateau a reçu un tir
// le reste des bateaux n'a pas été touché 
int InitFlotte(FLOTTE *flotte); // rien à faire

// Affichage d'un bâteau
int AfficherBateau(BOAT bateau);

// Affichage de toute la flotte de bateaux à l'écran
int AfficherFlotte(FLOTTE flotte);

// programme principal - rien à faire
int main() {
	setlocale(LC_ALL, "fr-FR");
	system("CLS");
	openConsole();
	int err = EXIT_SUCCESS;
	// déclaration de la flotte de bateaux
	FLOTTE maFlotte;

	// création de la flotte
	if (InitFlotte(&maFlotte) == 0) err= EXIT_FAILURE;
	// affichage des bateaux
	if (AfficherFlotte(maFlotte) == 0) err= EXIT_FAILURE;
	
	printf("\n\nBye !");
	closeConsole();
	return err;
}

// code d'implémentation des fonctions
////////////////////////////////////////////////////////////////////////
// PAS DE CODE A AJOUTER AVANT



// Affichage d'un bateau
int AfficherBateau(BOAT bateau) {

	// bateau est une structure BOAT qui contient les éléments de bateau (champ ShipElt) dans une liste chainée nommée eltsBateau
	// chaque ShipElts contient un champ pos qui represente les coordonnées X et Y 
	// des différents points composant le bateau ainsi que l'état (touche ou ok) de chaque point.
	// la fonction GetNextElement() permet d'obtenir, un par un, tous les maillons d'une chaine contenant les shipelts d'un bateau.

	// Fonctions utilisables pour les listes chainées :
	// RewindLinkedList( nom_d_une_liste )  // Permet de relire une liste chainée à partir du début
	// maillon = GetNextElement( nom_d_une_liste ) // Permet d'obtenir le maillon suivant ou NULL si pas de suivant

	SingleLinkedListElem* maillon;

	// Compléter ICI = 2 lignes de code !!
	// ...
	maillon = bateau.eltsBateau;
	while (maillon != NULL) 
	{
		
		// déplace le curseur au point d'affichage
		moveCursor(maillon->ShipElt.pos.X, maillon->ShipElt.pos.Y);
		// affiche O ou X selon l'état de l'élément de bateau
		if (maillon->ShipElt.state == touche) {
			plotChar('X');
		}
		else {
			plotChar('O');
		}
		// Compléter ICI = 1 ligne  !!
		maillon = GetNextElement(bateau.eltsBateau);
	}
	//...
	return 0;
}



// Affichage de toute la flotte de bateaux à l'écran
int AfficherFlotte(FLOTTE flotte) {
	// Compléter ICI : 3 lignes de code
	for (int i = 0; i < flotte.nbBateaux; i++) {
		AfficherBateau(flotte.bateau[i]);
	}

	//....
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////
//  PAS DE CODE A AJOUTER AU-DELA
int InitFlotte(FLOTTE *flotte) {
	if (flotte == NULL) return 0;
	bool err = false;
	flotte->nbBateaux = NBBATEAUX;

	if ((flotte->bateau = (BOAT*)malloc(sizeof(BOAT) * NBBATEAUX)) == NULL) {
		err = true;
	}
	// jeu d'essai en dur
	COORD positionBateau[NBBATEAUX] = { {10,10}, {5,2}, {10,15},{15,3}, {20,18} };
	size_t tailleBateau[NBBATEAUX] = { 5, 4, 3, 3, 2 };
	size_t orientation[NBBATEAUX] = { Est, Nord, Ouest, Sud, Est };
	// Création des bateaux et ajout du premier element de bateau (proue)
	size_t i = 0;
	while (!err  && i < flotte->nbBateaux  )
	{
		ShipElt tmpElt;
		SingleLinkedListElem *tmpMaillon;

		// fixe la taille du bateau
		flotte->bateau[i].taille = tailleBateau[i];
		// fixe l'orientation
		//Cap cap = alea(0, 4);
		Cap cap = orientation[i];
		flotte->bateau[i].cap = cap;

		// création d'une liste chainée pour chacun des bateaux
		if ((flotte->bateau[i].eltsBateau = NewLinkedList()) == NULL) {
			err = true;
		}

		// Ajout 1er maillon qui contient le 1er element de bateau
		if (!err) {
			tmpElt.pos = positionBateau[i];
			tmpElt.state = ok;
		
			// création du maillon
			tmpMaillon = NewLinkedListElement(tmpElt);
			err = (tmpMaillon == NULL);	
			// ajout dans la liste chainée correspondant au bateau en cours de création
			if (!err) AddNewElemToSingleLinkedList(flotte->bateau[i].eltsBateau, tmpMaillon);
		}

		// calcul des coordonnées de chaque élément de bateau en fonction de la position de la proue
			// et de l'orientation (cap) du bateau calculée aléatoirement.
		int incX = 0;
		int incY = 0;
		
		switch (cap)
		{
		case Nord:
			incY = +1;
			break;
		case Est:
			incX = -1;
			break;
		case Sud:
			incY = -1;
			break;
		case Ouest:
			incX = +1;
			break;
		default:
			break;
		}

		size_t idxElt = 1;
		// creation de tous les maillons qui consistuent le reste du bateau
		// on part de la position du premier élément pour calculer les suivants en fonction de l'orientation du bateau
		COORD tmp;
		tmp.X = positionBateau[i].X;
		tmp.Y = positionBateau[i].Y;

		// tant qu'on a pas ajouté tous les éléments du bateau
		while (!err && idxElt < flotte->bateau[i].taille)
		{
			
			tmpElt.state = ok;
			// calcul position élément suivant
			tmp.X += incX;
			tmp.Y += incY;
			// si ca dépasse de la zone d'affichage on âffiche à l'autre bout
			if (tmp.X < 0) tmp.X = SEASIZEX - tmp.X;
			if (tmp.X > SEASIZEX - 1) tmp.X -= SEASIZEX;
			if (tmp.Y < 0) tmp.Y = SEASIZEY - tmp.Y;
			if (tmp.X > SEASIZEY - 1) tmp.Y -= SEASIZEY;
			// mise à jour de la structure élement de bateau
			tmpElt.pos = tmp;

			if (i == 1 && idxElt == 1) {
				// simulation d'un impact sur le deuxieme élément du deuxième bateau
				tmpElt.state = touche;
			}
			else {
				tmpElt.state = ok;
			}

			// ajout dans la liste chaine du maillon avec les informations concernant cet élément de bateau
			// création du maillon
			tmpMaillon = NewLinkedListElement(tmpElt);
			err = (tmpMaillon == NULL);
			// ajout dans la liste chainée correspondant au bateau en cours de création
			if (!err) AddNewElemToSingleLinkedList(flotte->bateau[i].eltsBateau, tmpMaillon);
			
			// on passe à l'élément de bateau suivant
	
			idxElt++;
		
		}
		// on passe au bateau suivant
		i++;
	}
	// retour du dernier code d'erreur
	if (err) return 0;
	
	return 1;
}