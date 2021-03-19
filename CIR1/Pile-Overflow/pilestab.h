#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
// d�finition du symbole de d�passement de pile
#define STACKOVERFLOW -1
// d�finition d'une pile � l'aide d'une structure
typedef struct Stack {
	int* tab; // le tableau de donn�es qu'il faut allouer
	int stackMaxSize; // taille max
	int stackNbElemts; // nb d'�l�ments actuellement dans la pile
} Stack;
// impl�mentation des piles avec des tableaux dynamiques
// cr�ation d'une pile
void NewStack(Stack** stack, int initialStackSize);
bool isStackFull(Stack* stack);
bool isStackEmpty(Stack* stack);
int push(Stack* stack, int value);
int pull(Stack* stack, int* value);
int peek(Stack* stack, int* value);