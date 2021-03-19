#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct node
{
	int data;
	struct node* leftChild;
	struct node* rightChild;
}node;

typedef node* tree;

/*typedef struct tree 
{
	node* root;
	int nbElem;
}tree; */

void displayTree(tree n, int depth)
{

	printf("%d ", n->data);
	if (n->leftChild != NULL)
	{
		displayTree(n->leftChild, depth+1);
	}
	if (n->rightChild != NULL)
	{
		displayTree(n->rightChild, depth+1);
	}
}

int main(){
	setlocale(LC_ALL, "fr-FR");

	node n1 = { 10,NULL,NULL };
	node n2 = { 15,NULL,NULL };
	node n3 = { 18,NULL,NULL };
	node n4 = { 25,NULL,NULL };
	node n5 = { 22,NULL,NULL };
	n1.leftChild = &n2;
	n2.leftChild = &n4;
	n1.rightChild = &n3;
	n2.rightChild = &n5;
	tree t = &n1;
	int d = 4;
	displayTree(t, d);
}