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
// crée une nouvelle liste chainée unilataire vide et renvoie un pointeur sur cette liste
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
// crée un nouveau maillon qui contient l'élément de bateau passée en paramètre
SingleLinkedListElem  *NewLinkedListElement(ShipElt ShipElt) {
	SingleLinkedListElem *tmp;
	tmp = (SingleLinkedListElem *)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {	
	tmp->ShipElt = ShipElt;
	tmp->next = NULL;
	}
	return(tmp);
}


// ajout d'un maillon à la fin d'une Single list 
// renvoie 1 si le maillon a été ajouté, 0 sinon
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElem* elem) {
	if (list == NULL || elem == NULL || elem->next != NULL) return 0;
	// si la liste est vide
	if (list->tail == NULL) {
		list->tail = elem;
		list->head = elem;
		list->size = 1;
	}
	else {
		// on ajoute l'élément en fin
		list->tail->next = elem;
		list->tail = elem;
		list->size += 1;
	}
	return 1;
}

// renvoie un pointeur sur l'élément suivant dans la liste par rapport au dernier élément lu
// renvoie NULL si plus d'élement suivant
// renvoie tete de liste si pas encore utilisé
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
	
	// pas d'élément dans la liste ou elem invalide
	if ((list->size == 0) || (elem == NULL)) return(0); 

	// initialisation d'un pointeur sur l'élément courant
	SingleLinkedListElem *tmp = list->head;
	// previous désigne l'élément qui précède l'élément courant
	SingleLinkedListElem *previous = NULL;

	// l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste
	if ((elem == list->head) && (elem == list->tail)) {
		
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}

	// il est en tête, on supprime la tête

	if (elem == list->head)  {
		
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}

	// Recherche du maillon dans le reste de la liste chaînée
	
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
	// s'il est au milieu, on supprime l'élément
	if ((previous !=NULL) && (tmp == elem) && (tmp->next!=NULL)) {
		
		previous->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// l'élément recherché n'a pas été trouvé
	return(0);  
}

void RewindLinkedList(LinkedList* list)
{
	if (list == NULL) return;
	// on parque le curseur sur une adresse de parking
	// le prochain GetNext va placer le current sur la tête de liste
	list->current = (SingleLinkedListElem *) &(list->current_parking);
}

