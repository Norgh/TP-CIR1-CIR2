#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"




int alea(int min, int max) {
	// Generate random numbers in the half-closed interval
	// [range_min, range_max). In other words,
	// range_min <= random number < range_max

	int u = (int)((double)rand() / ((long long )RAND_MAX + 1) * ((long long)max - (long long)min)) + min;
	return(u);

}
// cr�e une nouvelle liste chain�e unilataire vide et renvoie un pointeur sur cette liste
LinkedList *NewLinkedList() {
	LinkedList *tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
		// parking du current, permet de se placer sur head au premier getNext
		tmp->current = (SingleLinkedListElem*) &(tmp->current_parking);
	}
	return tmp;
}
// cr�e un nouveau maillon qui contient l'�l�ment de bateau pass�e en param�tre
SingleLinkedListElem  *NewLinkedListElement(ShipElt ShipElt) {
	SingleLinkedListElem *tmp;
	tmp = (SingleLinkedListElem *)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {	
	tmp->ShipElt = ShipElt;
	tmp->next = NULL;
	}
	return(tmp);
}


// ajout d'un maillon � la fin d'une Single list 
// renvoie 1 si le maillon a �t� ajout�, 0 sinon
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElem* elem) {
	if (list == NULL || elem == NULL || elem->next != NULL) return 0;
	// si la liste est vide
	if (list->tail == NULL) {
		list->tail = elem;
		list->head = elem;
		list->size = 1;
	}
	else {
		// on ajoute l'�l�ment en fin
		list->tail->next = elem;
		list->tail = elem;
		list->size += 1;
	}
	return 1;
}

// renvoie un pointeur sur l'�l�ment suivant dans la liste par rapport au dernier �l�ment lu
// renvoie NULL si plus d'�lement suivant
// renvoie tete de liste si pas encore utilis�
SingleLinkedListElem* GetNextElement(LinkedList* list) {
	int CurrentIndex = 0;
	SingleLinkedListElem* Element = NULL;
	if (list == NULL) return(NULL);

	if (list->current == (SingleLinkedListElem*)&(list->current_parking)) {
		list->current = list->head;
		Element = list->current;
	}
	else {
		if (list->current != NULL && list->current->next != NULL) {
			Element = list->current->next;
			list->current = Element;
		}
	}
	return(Element);
}

int DeleteLinkedListElem(LinkedList * list, SingleLinkedListElem * elem) {

	// on peut traiter un certain nombre de cas d'erreur
	
	// La liste n'existe pas
	if (list == NULL) return(0); 
	
	// liste vide ou anomalie
	if ((list->head == NULL) || (list->tail == NULL)) return(0); 
	
	// anomalie sur la taille
	if ((list->head == list->tail) && (list->size != 1)) return(0); 
	
	// pas d'�l�ment dans la liste ou elem invalide
	if ((list->size == 0) || (elem == NULL)) return(0); 

	// initialisation d'un pointeur sur l'�l�ment courant
	SingleLinkedListElem *tmp = list->head;
	// previous d�signe l'�l�ment qui pr�c�de l'�l�ment courant
	SingleLinkedListElem *previous = NULL;

	// l'�l�ment est en t�te et en queue, il y a donc 1 seul �l�ment dans la liste
	if ((elem == list->head) && (elem == list->tail)) {
		
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}

	// il est en t�te, on supprime la t�te

	if (elem == list->head)  {
		
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}

	// Recherche du maillon dans le reste de la liste cha�n�e
	
	while ((tmp != NULL) && (tmp != elem)) {
		previous = tmp;
		tmp = tmp->next;
	}

	// s'il est en queue, on supprime la queue
	if ((previous != NULL) && (tmp == elem) && (tmp->next==NULL)) {
			
			list->tail = previous;
			previous->next = NULL;
			list->size--;
			free(elem);
			return(1);
		}
	// s'il est au milieu, on supprime l'�l�ment
	if ((previous !=NULL) && (tmp == elem) && (tmp->next!=NULL)) {
		
		previous->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// l'�l�ment recherch� n'a pas �t� trouv�
	return(0);  
}

void RewindLinkedList(LinkedList* list)
{
	if (list == NULL) return;
	// on parque le curseur sur une adresse de parking
	// le prochain GetNext va placer le current sur la t�te de liste
	list->current = (SingleLinkedListElem *) &(list->current_parking);
}

