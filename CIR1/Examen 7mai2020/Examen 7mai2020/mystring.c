#include <stdlib.h>
#include "mystring.h"
#include <string.h>


// **************************************************************************************** //
//
// NOM : Sénéchal
// PRENOM : Pierre
//
// *****************************************************************************************//

// La fonction myStrTrimStart supprime les caractères espaces en début de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS "
// "HI GUYS " renvoie "HI GUYS "
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h

char* myStrTrimStart(char* chaine) {
	
	if (chaine == NULL) return NULL; // Si la chaine d'entrée est nulle on renvoie NULL (cf consigne exercice)
	while(chaine[0]==" ") // Tant que la chaine commence par un espace
	{
		for (int i = 0; chaine[i] != '\0'; i++) // Du début jusqu'à la fin de la chaine
		{
			chaine[i-1] = chaine[i]; // On décale d'un à gauche
		}
	}
	return chaine; // Et on renvoie la chaine 
}
// La fonction myStrTrimEnd supprime les caractères espaces en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "  HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h
char* myStrTrimEnd(char* chaine) {
	if (chaine == NULL) return NULL;
	int compteur = 0; // On crée un compteur pour connaitre la longueur de la chaine
	for (int i=0; chaine[i] != '\0'; i++) // Tant qu'on n'a pas atteint la fin de la chaine
	{
		compteur++; // On incrémente le compteur
	}
	for (int a = (compteur - 1); a > 0; a--) // On se place à la fin de la chaine
	{
		chaine[a+1] = chaine[a]; // On décale d'un à droite
	}
	return chaine; // On retourne la chaine
}



// La fonction myStrTrim supprime les caractères espaces en début et en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h

char* myStrTrim(char* chaine) {
	if (chaine != NULL) {
		myStrTrimStart(chaine); // On appelle la fonction qui supprime les espaces en début de chaine
		myStrTrimEnd(chaine); // On appelle la fonction qui supprime les espaces en fin de chaine
	} 
	else {return NULL;}
	return chaine;
}