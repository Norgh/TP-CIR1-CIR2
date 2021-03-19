#pragma once
#include <Windows.h>

#define UP 0
#define DOWN 1




// Etats possibles d'un élément de bateau
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
// Un élément comporte ses coordonnées et son état : touché ou ok
// un bateau est formé d'une liste d'éléments de bateau
typedef struct ShipElt {
	// Etat de cet élément de bateau, touché ou non
	EltState state;
	// position de cet élément de bateau sur la mer
	COORD pos;
}ShipElt;

// maillon qui contient un élément de bateau
typedef struct SingleLinkedListElem {
	ShipElt ShipElt;
	struct SingleLinkedListElem *next;
} SingleLinkedListElem;

// Liste chainée unilatère d'éléments de bateau
typedef struct LinkedList {
	SingleLinkedListElem *head;
	int size;
	SingleLinkedListElem *tail;
	// implémentation d'un selecteur d'élément courant
	SingleLinkedListElem* current;
	// sert à parquer le current ailleurs que sur head pour que le premier getNext fonctionne
	int current_parking;
} LinkedList;
// Crée une liste chaînée unilatère vide et renvoie un pointeur sur celle-ci
LinkedList *NewLinkedList();

// Crée un nouveau maillon qui contient un nouvel element de bateau et renvoie un pointeur sur ce maillon
SingleLinkedListElem  *NewLinkedListElement(ShipElt ShipElt);
// Ajout d'un maillon en fin de liste
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElem* elem);



// Suppression et destruction d'un élément de liste chainée
int DeleteLinkedListElem(LinkedList *list, SingleLinkedListElem *Elem);
// rembobine la liste 
// en déplacant le curseur courant vers une position d'attente
// le premier appel à GetNext() place le curseur sur la tete de liste
// l'appel suivant à GetNext() place le curseur sur l'element qui suit et le renvoie, etc..

void RewindLinkedList(LinkedList* list);

SingleLinkedListElem* GetNextElement(LinkedList* Liste);

int alea(int min, int max);