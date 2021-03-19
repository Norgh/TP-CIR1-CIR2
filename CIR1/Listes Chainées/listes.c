#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


typedef struct Element 
{
	int data;
	Element* suivant;
} Element;

//La structure de contrôle de la file
typedef struct SLLFile 
{        //SLLFile <---> PILE
	Element* head;        //head
	Element* tail;        //tail
	int size;            //taille
	int maxsize;
} SLLFile;


// Check if file is full
int SLLisFileFull(SLLFile* file) 
{
	if (file->size == file->maxsize)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}


// Check if file is empty
int SLLisFileEmpty(SLLFile* file) 
{
	if (file->size == 0)
	{
		return(1);
	}
	else {
		return(0);
	}
}


//Empile le nombre value au début de la file 
int enfiler(SLLFile* file, int value)
{
	Element* nouveau = malloc(sizeof(nouveau));
	if (file == NULL || nouveau == NULL)
	{
		return(-1);
	}
	nouveau->data = value;
	nouveau->suivant = NULL;
	//Soit la file est vide, dans ce cas on crée la file en faisant 
	//pointer head et tail vers nouvellement,incrementer size
	if (SLLisFileEmpty(file))
	{
		//initialiser la file;
		file->head = nouveau;
		file->tail = nouveau;
		file->size++;

	}
	else    //La file n'est pas vide, dans ce cas, on rajoute le nouvel element
		//après le dernier element 
	{
		file->tail->suivant = nouveau;
		file->tail = nouveau;
	}
	file->size++;
	return file->size;
}


//Défiler
int SLLpull(SLLFile* file, int* value) 
{
	int nombredepilé = 0;
	if (file == NULL)
	{
		return(-1);
	}
	if (!SLLisFileEmpty(file))        //si la file n'es pas vide ...
	{
		Element* elementDepile = file->head;
		nombredepilé = elementDepile->data;
		file->head = elementDepile->suivant;
		free(elementDepile);
		file->size--;
		return nombredepilé;
	}
}











int main() {
	setlocale(LC_ALL, "fr-FR");
}