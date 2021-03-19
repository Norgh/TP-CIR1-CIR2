#include "files.h"

void NewQueue(Queue * *queue, int initialQueueSize) {
	*queue = (Queue*)malloc(sizeof(Queue));
	if (*queue != NULL) {
		(*queue)->tab = (int*)malloc(sizeof(int) * initialQueueSize);
		if (((*queue)->tab) != NULL) {
			for (int i = 0; i < initialQueueSize; i++) (*queue)->tab[i] = 0;
				(*queue)->first = -1;
				(*queue)->last = -1;
				(*queue)->queueNbElemt = 0;
				(*queue)->queueMaxSize = initialQueueSize;
		}
		else {
			free(*queue);
			*queue = NULL;
		}
	}
}
bool isQueueEmpty(Queue* queue) {
	return(queue->queueNbElemt == 0);
}
bool isQueueFull(Queue* queue) {
	return(queue->queueNbElemt == queue->queueMaxSize);
}
// Ajout d'un �l�ment dans la file
int queue(Queue* queue, int value) { // gestion de la file en tableau circulaire
// si la file est pleine, on ne fait rien
	if (isQueueFull(queue)) return(EXIT_FAILURE);
	// si la file est vide
	// �criture du premier �l�ment dans la file
	if (isQueueEmpty(queue)) {
		queue->first = 0;
		queue->last = 0;
		queue->queueNbElemt = 1;
		queue->tab[queue->last] = value;
	}
	else {
		// �criture d'un �l�ment dans la file
		queue->queueNbElemt += 1;
		queue->tab[queue->last] = value;
		// calculer la position du prochain �l�ment et le stocker
	};;
	return(EXIT_SUCCESS);
}
// Sortie d'un �l�ment de la file
int deQueue(Queue* queue, int* value) {
	


	return(EXIT_SUCCESS);
}