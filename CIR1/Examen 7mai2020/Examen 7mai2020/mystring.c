#include <stdlib.h>
#include "mystring.h"
#include <string.h>


// **************************************************************************************** //
//
// NOM : S�n�chal
// PRENOM : Pierre
//
// *****************************************************************************************//

// La fonction myStrTrimStart supprime les caract�res espaces en d�but de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS "
// "HI GUYS " renvoie "HI GUYS "
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entr�e doit �tre termin�e correctement pas un caract�re fin de chaine
// La chaine en sortie est �galement termin�e par un caract�re de fin de chaine
// La chaine en entr�e est modifi�e (trim) et est renvoy�e par le return
// Si la chaine en entr�e est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h

char* myStrTrimStart(char* chaine) {
	
	if (chaine == NULL) return NULL; // Si la chaine d'entr�e est nulle on renvoie NULL (cf consigne exercice)
	while(chaine[0]==" ") // Tant que la chaine commence par un espace
	{
		for (int i = 0; chaine[i] != '\0'; i++) // Du d�but jusqu'� la fin de la chaine
		{
			chaine[i-1] = chaine[i]; // On d�cale d'un � gauche
		}
	}
	return chaine; // Et on renvoie la chaine 
}
// La fonction myStrTrimEnd supprime les caract�res espaces en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "  HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entr�e doit �tre termin�e correctement pas un caract�re fin de chaine
// La chaine en sortie est �galement termin�e par un caract�re de fin de chaine
// La chaine en entr�e est modifi�e (trim) et est renvoy�e par le return
// Si la chaine en entr�e est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h
char* myStrTrimEnd(char* chaine) {
	if (chaine == NULL) return NULL;
	int compteur = 0; // On cr�e un compteur pour connaitre la longueur de la chaine
	for (int i=0; chaine[i] != '\0'; i++) // Tant qu'on n'a pas atteint la fin de la chaine
	{
		compteur++; // On incr�mente le compteur
	}
	for (int a = (compteur - 1); a > 0; a--) // On se place � la fin de la chaine
	{
		chaine[a+1] = chaine[a]; // On d�cale d'un � droite
	}
	return chaine; // On retourne la chaine
}



// La fonction myStrTrim supprime les caract�res espaces en d�but et en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entr�e doit �tre termin�e correctement pas un caract�re fin de chaine
// La chaine en sortie est �galement termin�e par un caract�re de fin de chaine
// La chaine en entr�e est modifi�e (trim) et est renvoy�e par le return
// Si la chaine en entr�e est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h

char* myStrTrim(char* chaine) {
	if (chaine != NULL) {
		myStrTrimStart(chaine); // On appelle la fonction qui supprime les espaces en d�but de chaine
		myStrTrimEnd(chaine); // On appelle la fonction qui supprime les espaces en fin de chaine
	} 
	else {return NULL;}
	return chaine;
}