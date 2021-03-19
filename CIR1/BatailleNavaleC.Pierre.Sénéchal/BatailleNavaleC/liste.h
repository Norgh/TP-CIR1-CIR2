#pragma once
#include <Windows.h>

#define UP 0
#define DOWN 1




// Etats possibles d'un �l�ment de bateau
typedef enum EltState
{
	ok = 0,
	touche = 1
} EltState;
// directions possibles pour un bateau
typedef enum Cap
{
	Nord,
	Est,
	Sud,
	Ouest
} Cap;

// Structure Element de bateau 
// Un �l�ment comporte ses coordonn�es et son �tat : touch� ou ok
// un bateau est form� d'une liste d'�l�ments de bateau
typedef struct ShipElt {
	// Etat de cet �l�ment de bateau, touch� ou non
	EltState state;
	// position de cet �l�ment de bateau sur la mer
	COORD pos;
}ShipElt;

// maillon qui contient un �l�ment de bateau
typedef struct SingleLinkedListElem {
	ShipElt ShipElt;
	struct SingleLinkedListElem *next;
} SingleLinkedListElem;

// Liste chain�e unilat�re d'�l�ments de bateau
typedef struct LinkedList {
	SingleLinkedListElem *head;
	int size;
	SingleLinkedListElem *tail;
	// impl�mentation d'un selecteur d'�l�ment courant
	SingleLinkedListElem* current;
	// sert � parquer le current ailleurs que sur head pour que le premier getNext fonctionne
	int current_parking;
} LinkedList;
// Cr�e une liste cha�n�e unilat�re vide et renvoie un pointeur sur celle-ci
LinkedList *NewLinkedList();

// Cr�e un nouveau maillon qui contient un nouvel element de bateau et renvoie un pointeur sur ce maillon
SingleLinkedListElem  *NewLinkedListElement(ShipElt ShipElt);
// Ajout d'un maillon en fin de liste
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElem* elem);



// Suppression et destruction d'un �l�ment de liste chain�e
int DeleteLinkedListElem(LinkedList *list, SingleLinkedListElem *Elem);
// rembobine la liste 
// en d�placant le curseur courant vers une position d'attente
// le premier appel � GetNext() place le curseur sur la tete de liste
// l'appel suivant � GetNext() place le curseur sur l'element qui suit et le renvoie, etc..

void RewindLinkedList(LinkedList* list);

SingleLinkedListElem* GetNextElement(LinkedList* Liste);

int alea(int min, int max);