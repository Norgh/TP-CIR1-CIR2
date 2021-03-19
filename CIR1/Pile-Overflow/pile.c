#include "pilestab.h"
#define STACKOVERFLOW -1

// cr�ation d'une pile
// stack : nom de la pile
// initialStackSize : taille de la pile en nombre de valeurs empilables
void NewStack(Stack** stack, int initialStackSize) {
	// allocation de la structure pile
	*stack = (Stack*)malloc(sizeof(Stack));
	if (*stack != NULL) {
		// allocation du tableau de donn�es
		(*stack)->tab = (int*)malloc(sizeof(int) * initialStackSize);
		if (((*stack)->tab) != NULL) {
			// initialisation des param�tres de la pile
			(*stack)->stackMaxSize = initialStackSize;
			(*stack)->stackNbElemts = 0;
		}
		else {
			// la pile n'a pas pu �tre cr��e, stack vaut NULL
			free(*stack);
			*stack = NULL;
		}
	}
}
// teste si la pile est pleine
bool isStackFull(Stack* stack) {
	return((stack->stackNbElemts >= stack->stackMaxSize));
};
// teste si la pile est vide
bool isStackEmpty(Stack* stack) {
	return(stack->stackNbElemts == 0);
}
// pousse une valeur sur la pile
int push(Stack* stack, int value) {
	if (!isStackFull(stack)) {
		stack->tab[stack->stackNbElemts] = value;
		stack->stackNbElemts++;
		return(0);
	}
	else {
		return(STACKOVERFLOW);
	}
}
// r�cup�re la valeur au sommet de la pile
int pull(Stack* stack, int* value) {
	if (!isStackEmpty(stack)) {






		return(EXIT_SUCCESS);
	}
	return(EXIT_FAILURE);
}
int peek(Stack* stack, int* value) {
	if (!isStackEmpty(stack)) {






		return(EXIT_SUCCESS);
	}
	return(EXIT_FAILURE);
}